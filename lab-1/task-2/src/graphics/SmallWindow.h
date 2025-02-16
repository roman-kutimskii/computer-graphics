#ifndef SMALLWINDOW_H
#define SMALLWINDOW_H

#include "CircleShape.h"
#include "CompositeShape.h"

class SmallWindow final : public CompositeShape {
public:
    explicit SmallWindow(const sf::Vector2f &position) {
        add(std::make_unique<CircleShape>(position, 30, sf::Color(106, 130, 194)));
    }
};

#endif //SMALLWINDOW_H
