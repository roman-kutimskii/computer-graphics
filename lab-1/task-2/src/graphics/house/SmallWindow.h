#ifndef SMALLWINDOW_H
#define SMALLWINDOW_H

#include "../shapes/CircleShape.h"
#include "../shapes/CompositeShape.h"

class SmallWindow final : public CompositeShape {
public:
    explicit SmallWindow(const sf::Vector2f &position) {
        add(std::make_unique<CircleShape>(position, 15, sf::Color(106, 130, 194)));
    }
};

#endif //SMALLWINDOW_H
