/**
*	Patrick Aliberti
*	testVect.cpp
*	04/12/2021
* 
*	This program tests out the Vect class
*/
#include <iostream>
#include "vect.h"
using namespace std;

int main()
{
	// Test default constructor
	Vect vect1;
	vect1.displayData();
	
	// Test second constructor
	Vect vect2(3, 4, 'r');
	vect2.displayData();
	
	// Test setMode and setRect
	vect2.setRect(3, 4);
	vect2.setMode('p');
	vect2.displayData();
	
	// Test set
	vect2.set(5, .927295, 'p');
	vect2.displayData();
	
	// Test accessors
	cout << "\nRectangle values:\n";
	cout << vect2.getX() << "\n";
	cout << vect2.getY() << "\n\n";
	cout << "Polar values:\n";
	cout << vect2.getMag() << "\n";
	cout << vect2.getAng() << "\n\n";
	
	Vect vect3(10, 20, 'r');
	
	// Test overloaded + operator
	cout << "The sum of vect 2 and 3 is:\n";
	Vect sum = vect2 + vect3;
	sum.displayData();
	
	// Test - operator (unary)
	cout << "\nVect 3 negated is:\n";
	Vect neg = -vect3;
	neg.displayData();
	
	// Test - operator (binary)
	cout << "\nThe difference of vect 3 and 2 is:\n";
	Vect diff = vect3 - vect2;
	diff.displayData();

	// Test == operator
	Vect vect4(10, 20, 'r');
	bool eq = vect3 == vect4;
	if (eq == 1)
		cout << "\nVectors 3 and 4 are equal.\n";
		
	// Test * operator
	cout << "\nThe product of vect 3 and the number 2 is:\n";
	Vect prod = vect3 * 2;
	prod.displayData();
	
	// Test * friend operator
	cout << "\nThe product of the number 2 and vect 3 is:\n";
	Vect prod2 = 2 * vect3;
	prod2.displayData();
	
	// Test << friend operator
	cout << "\nVect 1:\n" << vect1; 
	cout << "\nVect 2:\n" << vect2;
	cout << "\nVect 3:\n" << vect3;
	cout << "\nVect 4:\n" << vect4;
	
	return 0;
}
