#ifndef IMAGE_H
#define IMAGE_H

#include "fence/Fence.h"
#include "house/House.h"
#include "shapes/CompositeShape.h"

class Image final : public CompositeShape {
public:
    explicit Image(const sf::Vector2f& position) {
        add(std::make_unique<House>(position));
        add(std::make_unique<Fence>(position + sf::Vector2f(224, 168), 8));
    }
};

#endif //IMAGE_H
