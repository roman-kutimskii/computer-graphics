#ifndef TREE_H
#define TREE_H

#include "../shapes/CompositeShape.h"
#include "../shapes/TriangleShape.h"

class Tree final : public CompositeShape {
public:
    explicit Tree(const sf::Vector2f &position) {
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(20, 25),
                position + sf::Vector2f(40, 0),
                position + sf::Vector2f(60, 25),
                sf::Color(85, 217, 185))
        );
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(15, 45),
                position + sf::Vector2f(40, 10),
                position + sf::Vector2f(65, 45),
                sf::Color(85, 217, 185))
        );
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(10, 60),
                position + sf::Vector2f(40, 30),
                position + sf::Vector2f(70, 60),
                sf::Color(85, 217, 185))
        );
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(5, 75),
                position + sf::Vector2f(40, 45),
                position + sf::Vector2f(75, 75),
                sf::Color(85, 217, 185))
        );
        add(std::make_unique<TriangleShape>(
                position + sf::Vector2f(0, 100),
                position + sf::Vector2f(40, 45),
                position + sf::Vector2f(80, 100),
                sf::Color(85, 217, 185))
        );
    }
};

#endif //TREE_H
