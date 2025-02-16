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

    [[nodiscard]] sf::FloatRect getBounds() const override {
        return m_circle->getGlobalBounds();
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
    std::unique_ptr<sf::CircleShape> m_circle;
};

#endif //CIRCLESHAPE_H
