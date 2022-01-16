/**
*	Patrick Aliberti
*	0-4_VertexArrays_SFML.cpp
*	01/16/2022
* 
*	This program creates a square and a line using sf::VertexArray
*/
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Test");

	// Square
	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(5, 5);
	quad[1].position = sf::Vector2f(200, 5);
	quad[2].position = sf::Vector2f(200, 200);
	quad[3].position = sf::Vector2f(5, 200);

	sf::Texture texture;

	if (!texture.loadFromFile("TestImages/index.jpeg")) {
		std::cout << "ERROR" << std::endl;
	}

	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(50, 0);
	quad[2].texCoords = sf::Vector2f(50, 100);
	quad[3].texCoords = sf::Vector2f(0, 100);

	// Line
	sf::VertexArray line(sf::Lines, 2);

	line[0].position = sf::Vector2f(5, 205);
	line[1].position = sf::Vector2f(205, 205);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(quad, &texture);
		window.draw(line);
		window.display();
	}

	return 0;
}
