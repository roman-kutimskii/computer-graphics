#ifndef WALL_H
#define WALL_H

#include "BigWindow.h"
#include "CompositeShape.h"
#include "Door.h"
#include "RectangleShape.h"

class Wall final : public CompositeShape {
public:
    explicit Wall(const sf::Vector2f &position) {
        add(std::make_unique<RectangleShape>(position, sf::Vector2f(200, 110), sf::Color::White));
        add(std::make_unique<BigWindow>(position + sf::Vector2f(115, 20)));
        add(std::make_unique<Door>(position + sf::Vector2f(40, 35)));
    }
};

#endif //WALL_H
