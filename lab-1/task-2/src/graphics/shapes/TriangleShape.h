#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include "IShape.h"

class TriangleShape final : public IShape {
public:
    TriangleShape(const sf::Vector2f &point1, const sf::Vector2f &point2, const sf::Vector2f &point3,
                  const sf::Color &color) {
        m_triangle = std::make_unique<sf::ConvexShape>(3);
        m_triangle->setPoint(0, point1);
        m_triangle->setPoint(1, point2);
        m_triangle->setPoint(2, point3);
        m_triangle->setFillColor(color);
    }

    void draw(sf::RenderWindow &window) const override {
        window.draw(*m_triangle);
    }

    void move(const sf::Vector2f &delta) const override {
        m_triangle->move(delta);
    }

    [[nodiscard]] sf::FloatRect getBounds() const override {
        return m_triangle->getLocalBounds();
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
    std::unique_ptr<sf::ConvexShape> m_triangle;
};

#endif //TRIANGLESHAPE_H
