#ifndef FLUE_H
#define FLUE_H

#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"

class Flue final : public CompositeShape {
public:
    explicit Flue(const sf::Vector2f &position) {
        add(std::make_unique<RectangleShape>(position, sf::Vector2f(40, 60), sf::Color(242, 75, 50)));
    }
};

#endif //FLUE_H
