#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "IShape.h"

class RectangleShape final : public IShape {
public:
    RectangleShape(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color) {
        m_rect = std::make_unique<sf::RectangleShape>(size);
        m_rect->setPosition(position);
        m_rect->setFillColor(color);
    }

    void draw(sf::RenderWindow &window) const override {
        window.draw(*m_rect);
    }

    void move(const sf::Vector2f &delta) const override {
        m_rect->move(delta);
    }

    void rotate(const float degrees) const {
        m_rect->rotate(sf::degrees(degrees));
    }

    [[nodiscard]] sf::FloatRect getBounds() const override {
        return m_rect->getGlobalBounds();
    }

private:
    std::unique_ptr<sf::RectangleShape> m_rect;
};

#endif //RECTANGLESHAPE_H
