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

private:
    std::vector<std::unique_ptr<IShape> > m_shapes;
};

#endif //COMPOSITESHAPE_H
