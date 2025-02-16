#ifndef HOUSE_H
#define HOUSE_H

#include "../shapes/CompositeShape.h"
#include "Roof.h"
#include "Wall.h"

class House final: public CompositeShape {
    public:
    explicit House(const sf::Vector2f& position) {
        add(std::make_unique<Wall>(position + sf::Vector2f(24, 123)));
        add(std::make_unique<Roof>(position));
    }
};

#endif //HOUSE_H
