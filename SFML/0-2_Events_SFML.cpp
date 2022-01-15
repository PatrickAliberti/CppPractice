#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Test");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			// if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				// window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		window.clear();
		window.display();
	}

	return 0;
}
