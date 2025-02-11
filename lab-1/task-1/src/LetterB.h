#ifndef LETTERB_H
#define LETTERB_H

#include "ILetter.h"

class LetterB final : public ILetter {
public:
    explicit LetterB(const sf::Vector2f &position) {
        auto verticalLine = std::make_shared<sf::RectangleShape>(sf::Vector2f({30, 90}));
        verticalLine->setPosition(position);
        verticalLine->setFillColor(sf::Color::Green);
        m_shapes.push_back(std::move(verticalLine));

        auto topCircle = std::make_shared<sf::CircleShape>(25);
        topCircle->setPosition({position.x + 15, position.y});
        topCircle->setFillColor(sf::Color::Green);
        m_shapes.push_back(std::move(topCircle));

        auto topRemoveCircle = std::make_unique<sf::CircleShape>(15);
        topRemoveCircle->setPosition({position.x + 25, position.y + 10});
        topRemoveCircle->setFillColor(sf::Color::White);
        m_shapes.push_back(std::move(topRemoveCircle));

        auto bottomCircle = std::make_unique<sf::CircleShape>(30);
        bottomCircle->setPosition({position.x + 15, position.y + 30});
        bottomCircle->setFillColor(sf::Color::Green);
        m_shapes.push_back(std::move(bottomCircle));

        auto bottomRemoveCircle = std::make_unique<sf::CircleShape>(20);
        bottomRemoveCircle->setPosition({position.x + 25, position.y + 40});
        bottomRemoveCircle->setFillColor(sf::Color::White);
        m_shapes.push_back(std::move(bottomRemoveCircle));
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

#endif //LETTERB_H
