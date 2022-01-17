/**
*	C++ Primer (5th Edition)
* 
*	19.3 - Enumerations
* 
*	p. 832 - "Enumerations let us group together sets of integral constants. Like classes, each enumeration defines a new type."
*/
#include <iostream>

int main() {
	// Scoped enumeration
	// By default, enumerator values start at 0 and increase by 1, or they can be initialized
	enum class open_modes { input, output, append };

	// Unscoped enumeration
	enum color { red, yellow, green };
	enum { floatPrec = 6, doublePrec = 10, double_doublePrec = 10 };

	// Scope
	// enum stoplight { red, yellow, green };			// error: redefines enumerators
	enum class peppers { red, yellow, green };			// ok: enumerators are hidden
	color eyes = green;									// ok: enumerators are in scope for an unscoped enumeration
	// peppers p = green;								// error: enumerators from peppers are not in scope
	
	color hair = color::red;							// ok: we can explicitly access the numerators
	peppers p2 = peppers::red;							// ok: using red from peppers

	int i = color::red;									// ok: unscoped enumerator implicitly converted to an int
	// int j = peppers::red;							// error: scoped enumerations are not implicitly converted

	// Define constexpr variables of enumeration type
	enum class intTypes {
		charTyp = 8, shortTyp = 16, intTyp = 16,
		longTyp = 32, long_longTyp = 64
	};

	constexpr intTypes charBits = intTypes::charTyp;

	// Use an enum as the expression in a switch statement and use the value of its enumerators as the case labels
	switch (eyes) {
	case 0:
		std::cout << eyes;
		break;

	case 1:
		std::cout << eyes;
		break;

	case 2:
		std::cout << eyes;
		break;
	}

	/**
	*	p. 834 - "Although each enum defines a unique type, it is represented by one of the built-in integral types. Under the new standard, we can specify that type
	*				by following the enum name with a colon and the name of the type we want to use"
	* 
	*				"Being able to specify the underlying type of an enum lets us control the type used across different implementations. We can be confident that our program
					compiled under one implementation will generate the same code when we compile it on another."
	*/

	// Forward declarations
	enum intValues : unsigned long long;			// unscoped, must specify a type
	enum class random;								// scoped enums can use int by default

	enum intValues : unsigned long long {
		charTyp = 255, shortTyp = 65535, intTyp = 65535,
		longType = 4294967295UL,
		long_longTyp = 18446744073709551615ULL
	};

	return 0;
}