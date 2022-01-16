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

	return 0;
}

int f() {
	return 12;
}