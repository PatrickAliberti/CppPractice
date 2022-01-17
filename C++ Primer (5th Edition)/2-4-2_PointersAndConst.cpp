/**
*	C++ Primer (5th Edition)
* 
*	2.4.2 - Pointers and const
* 
*	p. 62 - "As with references, we can define pointers that point to either const or nonconst types. Like a reference to a const, a pointer to const may not be used
*			to change the object to which the pointer points. We may store the address of a const object only in a pointer to a const"
*/
int main() {
	const double pi = 3.14;				// pi is const
	// double *ptr = &pi;				// error: ptr is a plain pointer
	const double* cptr = &pi;			// ok: cptr may point to a double that is const
	// cptr = 42;						// error: cannot assign to *cptr

	/**
	*	pg. 62 - "In 2.3.2 (p. 52) we noted that there are two exceptions to the rule that the types of a pointer and the object to which it points must match. The
	*			 first exception is that we can use a pointer to const to point to a nonconst object"
	*/
	double dval = 3.14;			// dval is a double
	cptr = &dval;				// ok: but can't change dval through cptr

	/**
	*	const pointers
	*/
	int errNumb = 0;
	int* const curErr = &errNumb;		// currErr will always point to errNumb
	const double pi = 3.14159;
	const double* const pip = &pi;		// pip is a const pointer to a const object

	// We can use currErr to change the value of errNumb
	// *pip = 2.72;						// error: pip is a pointer to const
	if (*curErr) {
		*curErr = 0;					// ok: reset the value of the object to which curErr is bound
	}

	return 0;
}