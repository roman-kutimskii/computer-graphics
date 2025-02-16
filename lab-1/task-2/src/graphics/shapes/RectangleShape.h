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
    std::unique_ptr<sf::RectangleShape> m_rect;
};

#endif //RECTANGLESHAPE_H
