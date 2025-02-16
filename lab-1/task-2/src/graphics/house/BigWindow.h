#ifndef BIGWINDOW_H
#define BIGWINDOW_H

#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"

class BigWindow final : public CompositeShape {
public:
    explicit BigWindow(const sf::Vector2f &position) {
        add(std::make_unique<RectangleShape>(position, sf::Vector2f(45, 45), sf::Color(193, 231, 245)));
    }
};

#endif //BIGWINDOW_H
