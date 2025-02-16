#ifndef LETTERP_H
#define LETTERP_H

#include "Letter.h"

class LetterP : public Letter {
public:
    LetterP(const sf::Vector2f &position, const sf::Color &color): Letter(position) {
        createShapes(position, color);
    }

private:
    void createShapes(const sf::Vector2f &position, const sf::Color &color) {
        auto rect1 = std::make_unique<sf::RectangleShape>(sf::Vector2f(30, 90));
        rect1->setPosition(position);
        rect1->setFillColor(color);
        m_shapes.push_back(std::move(rect1));

        auto circle1 = std::make_unique<sf::CircleShape>(30);
        circle1->setPosition(position + sf::Vector2f(15, 0));
        circle1->setFillColor(color);
        m_shapes.push_back(std::move(circle1));

        auto circle2 = std::make_unique<sf::CircleShape>(20);
        circle2->setPosition(position + sf::Vector2f(25, 10));
        circle2->setFillColor(sf::Color::White);
        m_shapes.push_back(std::move(circle2));
    }
};

#endif //LETTERP_H
