#ifndef IMAGE_H
#define IMAGE_H

#include "background/Background.h"
#include "fence/Fence.h"
#include "house/House.h"
#include "shapes/CompositeShape.h"

class Image final : public CompositeShape {
public:
    // TODO использовать матрицу трансформации, или scale|translate, сделать так, чтобы домик был повёрнут на 49 градусов
    explicit Image(const sf::Vector2f &position) {
        add(std::make_unique<Background>(position));
        add(std::make_unique<House>(position + sf::Vector2f(10, 30)));
        add(std::make_unique<Fence>(position + sf::Vector2f(234, 198), 10));
    }
};

#endif //IMAGE_H
