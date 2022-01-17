/**
*	C++ Primer (5th Edition)
* 
*	2.4.4 - constexpr and Constant Expressions
* 
*	p. 65 - "A constant expression is an expression whose value cannot change and that can be evaluated at any time. A literal is a constant expression. A const
*			object that is initialized from a constant expression is also a constant expression."
* 
*	p. 66 - "Under the new standard, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration.
*			Variables that are declared as constexpr are implicitly const and must be initialized by constant expressions"
*
*			"Generally, it is a good idea to use constexpr for variables that you intend to use as constant expressions"
*/
int main() {
	const int max_files = 20;					// max_files is a constant expression
	const int limit = max_files + 1;			// limit is a constant expression
	int staff_size = 27;						// staff_size is not a constant expression
	// const int sz = get_size();				// sz is not a constant expression because the intitializer is not known until runtime

	// constexpr Variables
	constexpr int mf = 20;				// 20 is a constant expression
	constexpr int limit = mf + 1;		// mf + 1 is a constant expression
	// constexpr int sz = size();		// ok only if: size is a constexpr function

	// Pointers and constexpr
	const int *p = nullptr;				// p is a pointer to a const int
	constexpr int *q = nullptr;			// q is a const pointer to int

	// a constexpr pointer may point to a const or nonconst type
	constexpr int *np = nullptr;		// np is a constant pointer to int that is null
	int j = 0;
	constexpr int i = 42;
	
	// constexpr const int *p = &i;		// p is a constant pointer to the const int i
	// constexpr int *p1 = &j;			// p1 is a constant pointer to the int j


	return 0;
}