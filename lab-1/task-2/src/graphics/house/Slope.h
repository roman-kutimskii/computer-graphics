#ifndef SLOPE_H
#define SLOPE_H

#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"

class Slope final : public CompositeShape {
public:
    explicit Slope(const sf::Vector2f &position) {
        auto rect1 = std::make_unique<RectangleShape>(
            position + sf::Vector2f(124, 0),
            sf::Vector2f(175, 20),
            sf::Color(248, 139, 28)
        );
        rect1->rotate(45);
        auto rect2 = std::make_unique<RectangleShape>(
            position + sf::Vector2f(138, 14),
            sf::Vector2f(175, 20),
            sf::Color(248, 139, 28)
        );
        rect2->rotate(135);
        add(std::move(rect1));
        add(std::move(rect2));
    }
};

#endif //SLOPE_H
