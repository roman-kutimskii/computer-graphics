#ifndef ILETTER_H
#define ILETTER_H

#include "SFML/Graphics.hpp"

class ILetter {
public:
    virtual ~ILetter() = default;

    virtual void draw(sf::RenderWindow &window) = 0;

    virtual void move(const sf::Vector2f &delta) = 0;
};

#endif //ILETTER_H
