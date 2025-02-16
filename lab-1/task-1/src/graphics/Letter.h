#ifndef LETTER_H
#define LETTER_H

#include <cmath>
#include <SFML/Graphics.hpp>

class Letter {
public:
    explicit Letter(const sf::Vector2f &position) : m_position(position) {
    }

    void draw(sf::RenderWindow &window) const {
        for (const auto &shape: m_shapes) {
            window.draw(*shape);
        }
    }

    void update(const sf::RenderWindow &window) {
        m_velocityY = m_velocityY + m_accelerationY;
        for (const auto &shape: m_shapes) {
            shape->move(sf::Vector2f(0, m_velocityY));
        }

        const auto windowSize = sf::Vector2f(window.getSize());
        const auto letterBounds = getBounds();

        if (letterBounds.position.y + letterBounds.size.y > windowSize.y) {
            const auto delta = letterBounds.position.y + letterBounds.size.y - windowSize.y;
            for (const auto &shape: m_shapes) {
                shape->move(sf::Vector2f(0, -delta));
            }
            m_velocityY = -m_velocityY;
        }
    }

    [[nodiscard]] sf::FloatRect getBounds() const {
        if (m_shapes.empty()) {
            return {};
        }

        auto bounds = m_shapes[0]->getGlobalBounds();

        for (size_t i = 1; i < m_shapes.size(); ++i) {
            sf::FloatRect shapeBounds = m_shapes[i]->getGlobalBounds();
            sf::FloatRect newBounds;
            newBounds.position.x = std::min(bounds.position.x, shapeBounds.position.x);
            newBounds.position.y = std::min(bounds.position.y, shapeBounds.position.y);
            newBounds.size.x = std::max(bounds.position.x + bounds.size.x, shapeBounds.position.x + shapeBounds.size.x)
                               - newBounds.position.x;
            newBounds.size.y = std::max(bounds.position.y + bounds.size.y, shapeBounds.position.y + shapeBounds.size.y)
                               - newBounds.position.y;
            bounds = newBounds;
        }

        return bounds;
    }

protected:
    std::vector<std::unique_ptr<sf::Shape> > m_shapes;
    sf::Vector2f m_position;

private:
    float m_velocityY = 0;
    float m_accelerationY = 1;
};

#endif //LETTER_H
