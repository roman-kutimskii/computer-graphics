#include <SFML/Graphics.hpp>

#include "LetterB.h"
#include "LetterK.h"
#include "LetterP.h"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(60);
    LetterP letterP({50, 50});
    LetterB letterB({150, 50});
    LetterK letterK({250, 50});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                window.setView(sf::View(sf::FloatRect({0, 0}, sf::Vector2<float>(resized->size))));
            }
        }

        window.clear(sf::Color::White);

        letterP.draw(window);
        letterB.draw(window);
        letterK.draw(window);

        window.display();
    }
}
