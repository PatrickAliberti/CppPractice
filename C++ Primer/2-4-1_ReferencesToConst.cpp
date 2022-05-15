/**
*	C++ Primer (5th Edition)
* 
*	2.4.1 - References to const
* 
*	p. 61 - "As with any other object, we can bind a reference to an object of a const type. To do so we use a reference to const, which is a reference that refers
*			to const type. Unlike an ordinary reference, a reference to a const cannot be used to change the object to which the reference is bound."
*/
#include <iostream>

int main() {
	const int ci = 1024;
	const int &ri = ci;			// ok: both reference and underlying object are const
	// r1 = 42;					// error: r1 is a reference to a const
	// int &r2 = ci;			// error: nonconst reference to a const object.

	std::cout << ri << std::endl;

	/**
	*	p. 61 - "In 2.3.1 (p. 51) we noted that there are two exceptions to the rule that the type of a reference must match the type of the object to which it
	*	refers. The first exceptions is that we can initialize a reference to const from any expression that can be converted (2.1.2, p.35) to the type of the
	*	reference. In particular, we can bind a reference to const to a nonconst object, a literal, or a more general expression"
	*/

	int i = 42;
	const int &r1 = i;				// we can bind a const int& to a plain int object
	const int &r2 = 42;				// ok: r2 is a reference to a const
	const int &r3 = r1 * 2;			// ok: r3 is a reference to a const
	// int &r4 = r1 * 2;			// error: r4 is a plain, nonconst reference

	/**
	*	p. 61 - "Here ri refers to an int. Operations on ri will be integer operations, but dval is a floating point number, not an integer. To ensure that the
	*			object to which ri is bound to is an int, the compiler transforms this code into something like
	*			
	*			const int temp = dval;			// create a temporary const int from the double
	*			const int &ri = temp;			// bind ri to that temporary"
	* 
	*		  -	"Binding a reference to const to a nonconst int is legal. However, we cannot use the reference to const to change i. Even so, the value in i can
	*			change
	*/
	double dval = 3.14;
	const int &rj = dval;			// If this was not const, assigning would change the object to which ri is bound, which is a temporary, not dval.

	return 0;
}