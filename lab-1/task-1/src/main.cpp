#include <SFML/Graphics.hpp>

void drawLetterP(sf::RenderWindow &window, const sf::Vector2f &position) {
    sf::RectangleShape verticalLine({30, 90});
    verticalLine.setPosition(position);
    verticalLine.setFillColor(sf::Color::Green);
    window.draw(verticalLine);

    sf::CircleShape circle(30);
    circle.setPosition({position.x + 15, position.y});
    circle.setFillColor(sf::Color::Green);
    window.draw(circle);

    sf::CircleShape removeCircle(20);
    removeCircle.setPosition({position.x + 25, position.y + 10});
    removeCircle.setFillColor(sf::Color::White);
    window.draw(removeCircle);
}

void drawLetterB(sf::RenderWindow &window, const sf::Vector2f &position) {
    sf::RectangleShape verticalLine({30, 90});
    verticalLine.setPosition(position);
    verticalLine.setFillColor(sf::Color::Green);
    window.draw(verticalLine);

    sf::CircleShape topCircle(25);
    topCircle.setPosition({position.x + 15, position.y});
    topCircle.setFillColor(sf::Color::Green);
    window.draw(topCircle);

    sf::CircleShape topRemoveCircle(15);
    topRemoveCircle.setPosition({position.x + 25, position.y + 10});
    topRemoveCircle.setFillColor(sf::Color::White);
    window.draw(topRemoveCircle);

    sf::CircleShape bottomCircle(30);
    bottomCircle.setPosition({position.x + 15, position.y + 30});
    bottomCircle.setFillColor(sf::Color::Green);
    window.draw(bottomCircle);

    sf::CircleShape bottomRemoveCircle(20);
    bottomRemoveCircle.setPosition({position.x + 25, position.y + 40});
    bottomRemoveCircle.setFillColor(sf::Color::White);
    window.draw(bottomRemoveCircle);
}

void drawLetterK(sf::RenderWindow &window, const sf::Vector2f &position) {
    sf::ConvexShape topTriangle(3);
    topTriangle.setFillColor(sf::Color::Green);
    topTriangle.setPoint(0, position);
    topTriangle.setPoint(1, {position.x + 80, position.y});
    topTriangle.setPoint(2, {position.x, position.y + 90});
    window.draw(topTriangle);

    sf::ConvexShape bottomTriangle(3);
    bottomTriangle.setFillColor(sf::Color::Green);
    bottomTriangle.setPoint(0, position);
    bottomTriangle.setPoint(1, {position.x + 80, position.y + 90});
    bottomTriangle.setPoint(2, {position.x, position.y + 90});
    window.draw(bottomTriangle);

    sf::ConvexShape topRemoveTriangle(3);
    topRemoveTriangle.setFillColor(sf::Color::White);
    topRemoveTriangle.setPoint(0, {position.x + 20, position.y});
    topRemoveTriangle.setPoint(1, {position.x + 60, position.y});
    topRemoveTriangle.setPoint(2, {position.x + 20, position.y + 40});
    window.draw(topRemoveTriangle);

    sf::ConvexShape bottomRemoveTriangle(3);
    bottomRemoveTriangle.setFillColor(sf::Color::White);
    bottomRemoveTriangle.setPoint(0, {position.x + 20, position.y + 50});
    bottomRemoveTriangle.setPoint(1, {position.x + 60, position.y + 90});
    bottomRemoveTriangle.setPoint(2, {position.x + 20, position.y + 90});
    window.draw(bottomRemoveTriangle);
}

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        drawLetterP(window, {50, 50});
        drawLetterB(window, {150, 50});
        drawLetterK(window, {250, 50});

        window.display();
    }
}
