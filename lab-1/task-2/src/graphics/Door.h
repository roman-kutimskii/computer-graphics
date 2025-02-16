#ifndef DOOR_H
#define DOOR_H

#include "CircleShape.h"
#include "CompositeShape.h"
#include "RectangleShape.h"

class Door final : public CompositeShape {
public:
    explicit Door(const sf::Vector2f &position) {
        add(std::make_unique<RectangleShape>(position, sf::Vector2f(40, 75), sf::Color(71, 71, 71)));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(10, 25), 5, sf::Color::White));
    }
};

#endif //DOOR_H
