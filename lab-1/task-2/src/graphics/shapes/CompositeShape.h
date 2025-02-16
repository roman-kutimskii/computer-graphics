#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H

#include "IShape.h"

class CompositeShape : public IShape {
public:
    void add(std::unique_ptr<IShape> shape) {
        m_shapes.push_back(std::move(shape));
    }

    void remove(IShape *shape) {
        std::erase_if(m_shapes, [shape](const std::unique_ptr<IShape> &s) {
            return s.get() == shape;
        });
    }

    void draw(sf::RenderWindow &window) const override {
        for (const auto &shape: m_shapes) {
            shape->draw(window);
        }
    }

    void move(const sf::Vector2f &delta) const override {
        for (const auto &shape: m_shapes) {
            shape->move(delta);
        }
    }

    [[nodiscard]] sf::FloatRect getBounds() const override {
        if (m_shapes.empty()) {
            return {};
        }

        auto bounds = m_shapes[0]->getBounds();

        for (size_t i = 1; i < m_shapes.size(); ++i) {
            const auto &shapeBounds = m_shapes[i]->getBounds();
            float left = std::min(bounds.position.x, shapeBounds.position.x);
            float top = std::min(bounds.position.y, shapeBounds.position.y);
            float width = std::max(bounds.position.x + bounds.size.x, shapeBounds.position.x + shapeBounds.size.x) -
                          left;
            float height = std::max(bounds.position.y + bounds.size.y, shapeBounds.position.y + shapeBounds.size.y) -
                           top;
            bounds = sf::FloatRect({left, top}, {width, height});
        }

        return bounds;
    }

    void ensureInsideWindow(const sf::RenderWindow &window) const override {
        const auto bounds = getBounds();
        const auto windowSize = sf::Vector2f(window.getSize());

        sf::Vector2f offset(0, 0);

        if (bounds.position.x < 0) {
            offset.x = -bounds.position.x;
        } else if (bounds.position.x + bounds.size.x > windowSize.x) {
            offset.x = windowSize.x - (bounds.position.x + bounds.size.x);
        }

        if (bounds.position.y < 0) {
            offset.y = -bounds.position.y;
        } else if (bounds.position.y + bounds.size.y > windowSize.y) {
            offset.y = windowSize.y - (bounds.position.y + bounds.size.y);
        }

        if (offset.x != 0 || offset.y != 0) {
            move(offset);
        }
    }

private:
    std::vector<std::unique_ptr<IShape> > m_shapes;
};

#endif //COMPOSITESHAPE_H
