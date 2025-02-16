#include <SFML/Graphics.hpp>

#include "graphics/LetterB.h"
#include "graphics/LetterK.h"
#include "graphics/LetterP.h"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(60);

    LetterP letterP(sf::Vector2f(100, 50), sf::Color::Red);
    LetterB letterB(sf::Vector2f(200, 100), sf::Color::Green);
    LetterK letterK(sf::Vector2f(300, 150), sf::Color::Blue);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto *resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect visibleArea({0, 0}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear(sf::Color::White);

        letterP.update(window);
        letterP.draw(window);

        letterB.update(window);
        letterB.draw(window);

        letterK.update(window);
        letterK.draw(window);

        window.display();
    }
}
