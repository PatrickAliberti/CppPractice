#include <iostream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Button.h"
#include "Textbox.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Test");

	sf::Font timesRoman;
	timesRoman.loadFromFile("Times-Roman.ttf");

	Textbox textbox(15, sf::Color::White, false);
	textbox.setFont(timesRoman);
	textbox.setPosition(sf::Vector2f(100, 100));
	textbox.setLimit(true, 10);

	Button btn("Click Me!", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
	btn.setPosition({ 100, 300 });
	btn.setFont(timesRoman);

	while (window.isOpen()) {
		sf::Event event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			textbox.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			textbox.setSelected(false);
		}

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered)
				textbox.typedOn(event);
			if (event.type == sf::Event::MouseMoved)
				if (btn.isMouseOver(window))
					btn.setBackColor(sf::Color::White);
				else
					btn.setBackColor(sf::Color::Green);
			if (event.type == sf::Event::MouseButtonPressed)
				std::cout << "You clicked the button!" << std::endl;
		}

		window.clear();
		textbox.drawTo(window);
		btn.drawTo(window);
		window.display();
	}

	return 0;
}
