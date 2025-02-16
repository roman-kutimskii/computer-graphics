#ifndef FENCE_H
#define FENCE_H
#include "Board.h"
#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"

class Fence final : public CompositeShape {
public:
    explicit Fence(const sf::Vector2f &position, const int size) {
        add(std::make_unique<RectangleShape>(
                position + sf::Vector2f(5, 23),
                sf::Vector2f(static_cast<float>(size - 1) * 20, 10),
                sf::Color(205, 161, 35))
        );
        add(std::make_unique<RectangleShape>(
                position + sf::Vector2f(5, 47),
                sf::Vector2f(static_cast<float>(size - 1) * 20, 10),
                sf::Color(205, 161, 35))
        );
        for (int i = 0; i < size; ++i) {
            add(std::make_unique<Board>(position + sf::Vector2f(20 * static_cast<float>(i), 0)));
        }
    }
};

#endif //FENCE_H
