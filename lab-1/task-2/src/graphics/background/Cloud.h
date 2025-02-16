#ifndef CLOUD_H
#define CLOUD_H

#include "../shapes/CircleShape.h"
#include "../shapes/CompositeShape.h"
#include "../shapes/RectangleShape.h"

class Cloud final : public CompositeShape {
public:
    explicit Cloud(const sf::Vector2f &position) {
        add(std::make_unique<RectangleShape>(position + sf::Vector2f(12, 20), sf::Vector2f(75, 25), sf::Color::White));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(0, 25), 10, sf::Color::White));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(10, 10), 12, sf::Color::White));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(30, 1), 12, sf::Color::White));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(45, 0), 20, sf::Color::White));
        add(std::make_unique<CircleShape>(position + sf::Vector2f(70, 15), 15, sf::Color::White));
    }
};

#endif //CLOUD_H
