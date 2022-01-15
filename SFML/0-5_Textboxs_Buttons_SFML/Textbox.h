#pragma once

#include <iostream>
#include <sstream>

#include "SFML/Graphics.hpp"

class Textbox {
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int);
	void deleteLastChar();

public:
	Textbox(int, sf::Color, bool);

	std::string getText();

	void setFont(sf::Font&);
	void setPosition(sf::Vector2f);
	void setLimit(bool);
	void setLimit(bool, int);
	void setSelected(bool);

	void drawTo(sf::RenderWindow&);
	void typedOn(sf::Event);
};