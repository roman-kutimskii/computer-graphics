#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "IShape.h"

class CircleShape final : public IShape {
public:
    CircleShape(const sf::Vector2f &position, const float radius, const sf::Color &color) {
        m_circle = std::make_unique<sf::CircleShape>(radius);
        m_circle->setPosition(position);
        m_circle->setFillColor(color);
    }

    void draw(sf::RenderWindow &window) const override {
        window.draw(*m_circle);
    }

    void move(const sf::Vector2f &delta) const override {
        m_circle->move(delta);
    }

private:
    std::unique_ptr<sf::CircleShape> m_circle;
};

#endif //CIRCLESHAPE_H
