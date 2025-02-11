#ifndef LETTERP_H
#define LETTERP_H

#include "ILetter.h"
#include <vector>
#include <memory>

class LetterP final : public ILetter {
public:
    explicit LetterP(const sf::Vector2f &position) {
        auto verticalLine = std::make_unique<sf::RectangleShape>(sf::Vector2f(30, 90));
        verticalLine->setPosition(position);
        verticalLine->setFillColor(sf::Color::Green);
        m_shapes.push_back(std::move(verticalLine));

        auto circle = std::make_unique<sf::CircleShape>(30);
        circle->setPosition({position.x + 15, position.y});
        circle->setFillColor(sf::Color::Green);
        m_shapes.push_back(std::move(circle));

        auto removeCircle = std::make_unique<sf::CircleShape>(20);
        removeCircle->setPosition({position.x + 25, position.y + 10});
        removeCircle->setFillColor(sf::Color::White);
        m_shapes.push_back(std::move(removeCircle));
    }

    void draw(sf::RenderWindow &window) override {
        for (const auto &shape: m_shapes) {
            window.draw(*shape);
        }
    }

    void move(const sf::Vector2f &delta) override {
        for (const auto &shape: m_shapes) {
            shape->move(delta);
        }
    }

private:
    std::vector<std::unique_ptr<sf::Shape>> m_shapes;
};

#endif //LETTERP_H