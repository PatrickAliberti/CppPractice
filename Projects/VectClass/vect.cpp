/**
*	Patrick Aliberti
*	Vect.cpp
*	04/12/2021
*
*	This program implements the Vect class
*/
#include <iostream>
#include <cmath>
#include "vect.h"
using namespace std;

const float RAD_TO_DEG = 57.2957795;
const float PI = 3.141592;

// Default constructor sets the values to 0 and mode to rect
Vect::Vect()
{
	x = 0;
	y = 0;
	
	ang = 0;
	mag = 0;
	
	mode = 'r';
}


// Second constructor sets the values and mode to arguments
// It takes in two floats and a char. The char determines the
// mode and the floats are set to either x and y or mag and 
// angle, depending on the mode.
Vect::Vect(float a, float b, char m)
{
	if (m == 'r')
	{
		mode = 'r';
		x = a;
		y = b;
		
		setPolar();
	}
	else if (m == 'p')
	{
		mode = 'p';
		ang = a;
		mag = b;
		
		setRect();
	}
	else
	{
		mode = 'r';
		x = a;
		y = b;
		
		setPolar();
	}
}

// Destructor (placeholder)
Vect::~Vect() {}

// setRect sets the values of rect so theres no stale data
void Vect::setRect()
{
	x = mag * cos((ang / 180 * PI) / RAD_TO_DEG);
	y = mag * sin(ang / RAD_TO_DEG);
}

// setPolar sets the values of polar so theres no stale data
void Vect::setPolar()
{
	ang = (atan2(y, x)) * 180 / PI;
	mag = sqrt((x * x) + (y * y));
}

// setMode sets the mode equal to the argument passed
void Vect::setMode(char m)
{
	if (m == 'r')
		mode = 'r';
	else if (m == 'p')
		mode = 'p';
	else
		cout << "Invalid mode given." << endl;
}

// setRect sets the rect values
void Vect::setRect(float a, float b)
{
	x = a;
	y = b;
	
	setPolar();
}

// set sets the values depending on the mode
void Vect::set(float a, float b, char m)
{
	if (m == 'r')
	{
		mode = 'r';
		x = a;
		y = b;
		
		setPolar();
	}
	if (m == 'p')
	{
		mode = 'p';
		mag = a;
		ang = b;
		
		setRect();
	}
	else
		cout << "Invalid mode given." << endl;
}

// getX returns x
float Vect::getX() const
{ return x; }

// getY returns y
float Vect::getY() const
{ return y; }

// getMag returns the magnitude
float Vect::getMag() const
{ return mag; }

// getAng returns the angle
float Vect::getAng() const
{ return ang; }

// displayData displays the data
void Vect::displayData() const
{
	if (mode == 'r')
		cout << "(" << x << ", " << y << ")\n";
	else if (mode == 'p')
		cout << "<" << mag << ", " << ang << ">\n";
}

// Overloaded + operator
// The object is the left operand, the parameter is the right operand
// Returns the sum of the two operands
Vect Vect::operator+(const Vect& add) const
{
	Vect result(x + add.x, y + add.y, 'r');
	return result;
}

// Overloaded - operator (unary)
// The object is the right operand
// Returns the negated object
Vect Vect::operator-() const
{
	Vect result(-x, -y, 'r');
	return result;
}

// Overloaded - operator (binary)
// The object is the left operand, the parameter is the right operand
// Returns the difference of the two operands
Vect Vect::operator-(const Vect& sub) const
{
	Vect result(x - sub.x, y - sub.y, 'r');
	return result;
}

// Overloaded == operator
// The object is the left operand, the parameter is the right operand
// Returns a true or false depending on if the two operators are equal 
bool Vect::operator==(const Vect& eq) const
{
	return x == eq.x && y == eq.y;
}

// Overloaded * operator
// The object is the left operand, the parameter is the right operand
// Returns the product of the two operators
Vect Vect::operator*(float m) const
{
	Vect result(x * m, y * m, 'r');
	return result;
}

// Friend * operator
// The first parameter is the left operand, the second parameter is the right operand
// Returns the product of the two operands
Vect operator*(float mult1, const Vect& mult2)
{
	Vect result(mult1 * mult2.x, mult1 * mult2.y, 'r');
	return result;
}

// Friend << operator
// The first parameter is the left operand, the second parameter is the right operand
// Returns the product of the two operands
ostream& operator<<(ostream& output, const Vect& obj)
{
	output << "(" << obj.x << ", " << obj.y << ")\n"
		   << "<" << obj.ang << ", " << obj.mag << ">" << endl;
	
	return output;
}
