#include <iostream>

#include "SFML/Graphics.hpp"

#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
	text.setString(t);
	button.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(bgColor);
}

void Button::setFont(sf::Font& font) {
	text.setFont(font);
}

void Button::setBackColor(sf::Color color) {
	button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);

	float xPos = (pos.x + button.getLocalBounds().width / 3) - (text.getLocalBounds().width);
	float yPos = (pos.y + button.getLocalBounds().height / 3) - (text.getLocalBounds().height);
	text.setPosition({ xPos, yPos });
}

void Button::drawTo(sf::RenderWindow& window) {
	window.draw(button);
	window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;

	float btnPosXWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnPosYHeight = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < btnPosXWidth && mouseX > btnPosX && mouseY < btnPosYHeight && mouseY > btnPosY) {
		return true;
	}
	else
		return false;
}