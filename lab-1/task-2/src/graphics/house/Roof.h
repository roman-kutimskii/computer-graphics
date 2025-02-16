#ifndef ROOF_H
#define ROOF_H

#include "../shapes/CompositeShape.h"
#include "Flue.h"
#include "Slope.h"
#include "SmallWindow.h"
#include "../shapes/TriangleShape.h"

class Roof final : public CompositeShape {
public:
    explicit Roof(const sf::Vector2f &position) {
        add(std::make_unique<Flue>(position + sf::Vector2f(160, 30)));
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(24, 123),
                position + sf::Vector2f(124, 23),
                position + sf::Vector2f(224, 123),
                sf::Color::White)
        );
        add(std::make_unique<Slope>(position));
        add(std::make_unique<SmallWindow>(position + sf::Vector2f(109, 88)));
    }
};

#endif //ROOF_H
