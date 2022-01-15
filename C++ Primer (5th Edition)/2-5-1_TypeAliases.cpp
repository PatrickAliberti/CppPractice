/**
*	C++ Primer (5th Edition)
* 
*	2.5.1 - Type Aliases
* 
*	p. 67 - "A type alias is a name that is a synonm for another type. Type aliases let us simplify complicated type definitions, making those types easire to use.
			Type aliases also let us emphasize the purpose for which a type is used."
*/
int main() {
	// Define a type alias using typedef
	typedef double wages;					// wages is a synonym for double
	typedef wages base, *p;					// base is a synonym for double, p for double*

	// Define a type alias using an alias declaration
	using SI = int;							// SI is a synonym for int

	wages hourly, weekly;					// same as double hourly, weekly;
	SI item;								// same as int item;

	return 0;
}