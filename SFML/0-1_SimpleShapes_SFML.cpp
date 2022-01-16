/**
*	Patrick Aliberti
*	0-1_SimpleShapes_SFML.cpp
*	01/16/2022
* 
*	This program is an introduction to SFML and demonstrates simple window creation, setting a
*	framerate limit, creating a triangle, square, line, and a convex shape. 
* 
*	Another options to draw simple shapes is using sf::VertexArray
*/
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main() {
	RenderWindow window(sf::VideoMode(1200, 500), "'Agent Cat' Development");
	window.setFramerateLimit(60);

	// Triangle
	CircleShape triangle;
	triangle.setRadius(50.f);
	triangle.setPointCount(3);

	triangle.setFillColor(Color::Red);
	triangle.setOutlineThickness(5.f);
	triangle.setOutlineColor(Color::Blue);

	// Square
	CircleShape square;
	square.setPosition(Vector2f(800.f, 100.f));
	square.setRadius(100.f);
	square.setPointCount(4);

	// Line
	Vertex line[] = { Vertex(Vector2f(100.f, 400.f)), Vertex(Vector2f(50.f, 100.f)) };

	// Convex shape
	ConvexShape convex;
	convex.setPosition(Vector2f(400.f, 50.f));

	convex.setPointCount(5);

	convex.setPoint(0, Vector2f(0, 0));
	convex.setPoint(1, Vector2f(150, 10));
	convex.setPoint(2, Vector2f(120, 90));
	convex.setPoint(3, Vector2f(30, 100));
	convex.setPoint(4, Vector2f(0, 50));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(triangle);
		window.draw(square);
		window.draw(line, 2, Lines);
		window.draw(convex);

		window.display();
	}

	return 0;
}