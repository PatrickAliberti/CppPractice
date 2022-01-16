/**
*	C++ Primer (5th Edition)
* 
*	2.5.2 - The auto Specifier
* 
*	p. 68 - "It is not uncommon to want to store the value of an expression in a variable. To declare the variable, we have to know the type of that
*			expression. When we write a program, it can be suprisingly difficult-and sometimes even impossible-to determine the type of an expression. Under
*			the new standard, we can let the compiler figure out the type for us by using the auto type specifier. Unlike type specifiers, such as double,
*			that name a specific type, auto tells the compiler to deduce the type from the initializer. By implication, a variable that uses auto as its type
*			specifier must also have an initializer"
*/
int main() {
	double val1 = 2, val2 = 3;
	auto item = val1 + val2;			// item initialized to the result of val1 and val2

	int i = 0, &r = i;
	auto a = r;							// a is an int (r is an alias for i, which has type int)

	return 0;
}