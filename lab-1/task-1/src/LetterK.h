#ifndef LETTERK_H
#define LETTERK_H

#include "ILetter.h"

class LetterK final : public ILetter {
public:
    explicit LetterK(const sf::Vector2f &position) {
        auto topTriangle = std::make_unique<sf::ConvexShape>(3);
        topTriangle->setFillColor(sf::Color::Green);
        topTriangle->setPoint(0, position);
        topTriangle->setPoint(1, {position.x + 80, position.y});
        topTriangle->setPoint(2, {position.x, position.y + 90});
        m_shapes.push_back(std::move(topTriangle));

        auto bottomTriangle = std::make_unique<sf::ConvexShape>(3);
        bottomTriangle->setFillColor(sf::Color::Green);
        bottomTriangle->setPoint(0, position);
        bottomTriangle->setPoint(1, {position.x + 80, position.y + 90});
        bottomTriangle->setPoint(2, {position.x, position.y + 90});
        m_shapes.push_back(std::move(bottomTriangle));

        auto topRemoveTriangle = std::make_unique<sf::ConvexShape>(3);
        topRemoveTriangle->setFillColor(sf::Color::White);
        topRemoveTriangle->setPoint(0, {position.x + 20, position.y});
        topRemoveTriangle->setPoint(1, {position.x + 60, position.y});
        topRemoveTriangle->setPoint(2, {position.x + 20, position.y + 40});
        m_shapes.push_back(std::move(topRemoveTriangle));

        auto bottomRemoveTriangle = std::make_unique<sf::ConvexShape>(3);
        bottomRemoveTriangle->setFillColor(sf::Color::White);
        bottomRemoveTriangle->setPoint(0, {position.x + 20, position.y + 50});
        bottomRemoveTriangle->setPoint(1, {position.x + 60, position.y + 90});
        bottomRemoveTriangle->setPoint(2, {position.x + 20, position.y + 90});
        m_shapes.push_back(std::move(bottomRemoveTriangle));
    }

    void draw(sf::RenderWindow &window) override {
        for (const auto &shape: m_shapes) {
            window.draw(*shape);
        }
    }

    void move(const sf::Vector2f &delta) override {
        for (const auto &shape: m_shapes) {
            shape->move(delta);
        }
    }

private:
    std::vector<std::shared_ptr<sf::Shape> > m_shapes;
};

#endif //LETTERK_H
