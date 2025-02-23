#include <SFML/Graphics.hpp>

#include "graphics/Image.h"


int main() {
    // TODO: сделать так, чтобы dnd не отрывался
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(60);

    const Image image(sf::Vector2f(200, 100));

    bool isDragging = false;
    sf::Vector2f mousePos;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto *resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect visibleArea({0, 0}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            } else if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                    mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                    if (image.getBounds().contains(mousePos)) {
                        isDragging = true;
                    }
                }
            } else if (const auto *mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left) {
                    isDragging = false;
                }
            } else if (event->is<sf::Event::MouseMoved>()) {
                if (isDragging && image.getBounds().contains(mousePos)) {
                    const auto newMousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                    image.move(newMousePos - mousePos);
                    mousePos = newMousePos;

                    image.ensureInsideWindow(window);
                }
            }
        }

        window.clear(sf::Color::Black);

        image.draw(window);

        window.display();
    }
}
