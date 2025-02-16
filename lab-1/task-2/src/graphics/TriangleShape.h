#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include "IShape.h"

class TriangleShape : public IShape {
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

private:
    std::unique_ptr<sf::ConvexShape> m_triangle;
};

#endif //TRIANGLESHAPE_H
