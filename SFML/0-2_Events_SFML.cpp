/**
*	Patrick Aliberti
*	0-2_Events_SFML.cpp
*	01/16/2022
* 
*	This program demonstrates a simple event handle
*/
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
			
			if (event.type == sf::Event::MouseWheelMoved) {
				std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
				std::cout << "mouse x: " << event.mouseWheel.x << std::endl;
				std::cout << "mouse y: " << event.mouseWheel.y << std::endl;
			}
		}
		window.clear();
		window.display();
	}

	return 0;
}
