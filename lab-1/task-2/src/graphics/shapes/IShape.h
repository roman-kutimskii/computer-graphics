#ifndef ISHAPE_H
#define ISHAPE_H

#include <SFML/Graphics.hpp>

class IShape {
public:
    virtual ~IShape() = default;

    virtual void draw(sf::RenderWindow &window) const = 0;

    virtual void move(const sf::Vector2f &delta) const = 0;

    [[nodiscard]] virtual sf::FloatRect getBounds() const = 0;

    virtual void ensureInsideWindow(const sf::RenderWindow &window) const = 0;
};

#endif //ISHAPE_H
