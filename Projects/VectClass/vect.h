/**
*	Patrick Aliberti
*	vect.h
*	04/12/2021
*
*	This program specifies the Vect class
*/
#ifndef VECT_H
#define VECT_H

#include <iostream>
using namespace std;

class Vect {
	private:
		float x;
		float y;
		
		float mag;
		float ang;
		
		char mode;
		
		// Private member functions
		void setRect();
		void setPolar();
		
	public:
		// Constructors
		Vect();
		Vect(float a, float b, char m);
		
		~Vect();
		
		// Mutators
		void setMode(char m);
		void setRect(float x, float y);
		void set(float a, float b, char m);
		
		// Accessors
		float getX() const;
		float getY() const;
		float getMag() const;
		float getAng() const;
		void displayData() const;
		
		// Overloaded operators
		Vect operator+(const Vect &right) const;
		Vect operator-() const;
		Vect operator-(const Vect &right) const;
		bool operator==(const Vect &right) const;
		Vect operator*(float m) const;
		
		// Friends
		friend Vect operator*(float, const Vect &);
		friend ostream& operator<<(ostream&, const Vect &);
};

#endif
