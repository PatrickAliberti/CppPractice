/**
*	Patrick Aliberti
*	0-3_Sprites_SFML.cpp
*	01/16/2022
* 
*	This program loads a sprite and demonstrates simple movement over the elapsed time using sf::Clock
*/
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Scrappy The Junkyard Cat");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("TestImages/AgentCat.png"))
		return EXIT_FAILURE;

	sf::IntRect rectSourceSprite(230, 0, 230, 200);
	sf::Sprite sprite(texture, rectSourceSprite);

	// Load a clock to get elapsed time
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Use elapsed time to momve sprite
		if (clock.getElapsedTime().asSeconds() > 0.25f) {
			if (rectSourceSprite.left == 230)
				rectSourceSprite.left = 0;
			else
				rectSourceSprite.left += 230;

			sprite.setTextureRect(rectSourceSprite);
			clock.restart();
		}

		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}

	return 0;
}
