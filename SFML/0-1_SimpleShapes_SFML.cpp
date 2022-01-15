/**
* Patrick Aliberti
* SimpleShapes_SFML_0.0.cpp
* 12/31/2021
* 
* This program is an introduction to SFML and demonstrates simple window creation, setting a
* framerate limit, creating a triangle, square, line, and a convex shape. 
*/
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main() {
	// Make a window with a specific size and title
	RenderWindow window(sf::VideoMode(1200, 500), "'Agent Cat' Development");

	// Set frame rate limit
	window.setFramerateLimit(60);

	/**
	* TRIANGLE -
	* 
	* Use CircleShape with a point count of 3. A point count of 3 makes a tringle, 4 makes a
	* square, etc.
	*/
	CircleShape triangle;
	triangle.setRadius(50.f);
	triangle.setPointCount(3);

	// Messing around with setting colors and border of the triangle
	triangle.setFillColor(Color::Red);
	triangle.setOutlineThickness(5.f);
	triangle.setOutlineColor(Color::Blue);

	/**
	* SQUARE -
	*
	* Follow the triangle creation process
	*/
	CircleShape square;
	square.setPosition(Vector2f(800.f, 100.f));
	square.setRadius(100.f);
	square.setPointCount(4);

	/**
	* Line -
	*
	* Use verticies to create lines between points
	*/
	Vertex line[] = { Vertex(Vector2f(100.f, 400.f)), Vertex(Vector2f(50.f, 100.f)) };

	/**
	* Convex Shapes -
	*
	* Set the point count and the values of the points
	*/
	ConvexShape convex;
	convex.setPosition(Vector2f(400.f, 50.f));

	convex.setPointCount(5);

	convex.setPoint(0, Vector2f(0, 0));
	convex.setPoint(1, Vector2f(150, 10));
	convex.setPoint(2, Vector2f(120, 90));
	convex.setPoint(3, Vector2f(30, 100));
	convex.setPoint(4, Vector2f(0, 50));

	// Main loop while window is open
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear window for the new frame
		window.clear();

		// Print out all the stuff on the frame
		window.draw(triangle);
		window.draw(square);
		window.draw(line, 2, Lines);
		window.draw(convex);

		// Display the frame
		window.display();
	}

	return 0;
}