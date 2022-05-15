/**
*	C++ Primer (5th Edition)
* 
*	2.5.3 - The decltype Type Specfier
* 
*	p. 70 - "Sometimes we want to define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the
*			variable. For such cases, the new standard introduced a second type specifier, decltype, which returns the type of its operand. The compiler analyzes the
*			expression to determine its type but does not evaluate the expression."
*/
#include <iostream>

int f();

int main() {
	double x = 5.5;
	decltype(f()) sum = x;			// sum has whatever type f returns (int)

	std::cout << sum << std::endl;

	// decltype of an expression can be a reference type
	int i = 42, * p = &i, &r = i;
	decltype(r + 0) b;				// ok: addition yields an int; b is an uninitialized int
	// decltype(*p) c;				// error: c in int& and must be initialized

	// decltype of a parenthesized variable is always a reference
	// decltype((i)) d;				// error: d is int& and must be initialized
	decltype(i) e;					// ok: e is an unitialized int

	return 0;
}

int f() {
	return 12;
}