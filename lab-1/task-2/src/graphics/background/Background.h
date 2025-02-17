#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Cloud.h"
#include "Tree.h"
#include "../shapes/CircleShape.h"
#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"

class Background final : public CompositeShape {
public:
    explicit Background(const sf::Vector2f &position) {
        add(std::make_unique<CircleShape>(position + sf::Vector2f(20, 0), 200, sf::Color(139, 244, 255)));
        add(std::make_unique<RectangleShape>(
                position + sf::Vector2f(20, 275),
                sf::Vector2f(400, 125),
                sf::Color(60, 158, 109))
        );
        add(std::make_unique<RectangleShape>(
                position + sf::Vector2f(0, 255),
                sf::Vector2f(440, 55),
                sf::Color(57, 196, 120))
        );
        add(std::make_unique<Tree>(position + sf::Vector2f(300, 155)));
        add(std::make_unique<Cloud>(position + sf::Vector2f(250, 50)));
    }
};

#endif //BACKGROUND_H
