#ifndef BOARD_H
#define BOARD_H

#include "../shapes/CircleShape.h"
#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"
#include "../shapes/TriangleShape.h"

class Board final : public CompositeShape {
public:
    explicit Board(const sf::Vector2f &position) {
        add(std::make_unique<RectangleShape>(
                position + sf::Vector2f(0, 10),
                sf::Vector2f(10, 55),
                sf::Color(233, 197, 97))
        );
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(0, 10),
                position + sf::Vector2f(5, 0),
                position + sf::Vector2f(10, 10),
                sf::Color(233, 197, 97))
        );
        add(std::make_unique<CircleShape>(position + sf::Vector2f(3, 25), 2, sf::Color(183, 146, 31)));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(3, 50), 2, sf::Color(183, 146, 31)));
    }
};

#endif //BOARD_H
