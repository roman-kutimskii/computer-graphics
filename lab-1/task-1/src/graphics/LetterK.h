#ifndef LETTERK_H
#define LETTERK_H

#include "Letter.h"

class LetterK : public Letter {
public:
    LetterK(const sf::Vector2f &position, const sf::Color &color): Letter(position) {
        createShapes(position, color);
    }

private:
    void createShapes(const sf::Vector2f &position, const sf::Color &color) {
        auto triangle1 = std::make_unique<sf::ConvexShape>(3);
        triangle1->setFillColor(color);
        triangle1->setPoint(0, position);
        triangle1->setPoint(1, {position.x + 80, position.y});
        triangle1->setPoint(2, {position.x, position.y + 90});
        m_shapes.push_back(std::move(triangle1));

        auto triangle2 = std::make_unique<sf::ConvexShape>(3);
        triangle2->setFillColor(color);
        triangle2->setPoint(0, position);
        triangle2->setPoint(1, {position.x + 80, position.y + 90});
        triangle2->setPoint(2, {position.x, position.y + 90});
        m_shapes.push_back(std::move(triangle2));

        auto triangle3 = std::make_unique<sf::ConvexShape>(3);
        triangle3->setFillColor(sf::Color::White);
        triangle3->setPoint(0, {position.x + 20, position.y});
        triangle3->setPoint(1, {position.x + 60, position.y});
        triangle3->setPoint(2, {position.x + 20, position.y + 40});
        m_shapes.push_back(std::move(triangle3));

        auto triangle4 = std::make_unique<sf::ConvexShape>(3);
        triangle4->setFillColor(sf::Color::White);
        triangle4->setPoint(0, {position.x + 20, position.y + 50});
        triangle4->setPoint(1, {position.x + 60, position.y + 90});
        triangle4->setPoint(2, {position.x + 20, position.y + 90});
        m_shapes.push_back(std::move(triangle4));
    }
};

#endif //LETTERK_H
