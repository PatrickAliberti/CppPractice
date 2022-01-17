/**
*	C++ Primer (5th Edition)
* 
*	2.4.3 - Top-Level const
* 
*	p. 63 - "We use the term top-level const to indicate that the pointer itself is a const. When a pointer can point to a const object, we refer to that const as a
*			low-level const. More generally, top-level const indicates that an object itself is const. Top-level const can appear in any object type, i.e., one of the
*			built-in arithmetic types, a class type, or a pointer type. Low-level const appears in the base type of compound types such as pointer or references. Note
*			that pointer types, unlike most other types, can have both top-level and low-level const independently."
*/
int main() {
	int i = 0;
	int *const p1 = &i;			// we can't change the value of p1; const is top-level
	const int ci = 42;			// we cannot change the ci; const is top-level
	const int *p2 = &ci;		// we can change p2; const is low level
	const int *const p3 = p2;	// right-most const is top-level, left-most is not
	const int &r = ci;			// const in reference types is always low-level; reference types are not objects which can be const

	// When we copy an object, top-level consts are ignored
	i = ci;
	p2 = p3;

	// When we copy an object, low-level consts are not ignored
	// In general, we can convert a nonconst to a const but not the other way around
	// int *p = p3;			// error: p3 has a low-level const but p doesn't (const to nonconst)
	p2 = p3;				// ok: p2 has the same low-level const qualification as p3
	p2 = &i;				// ok: we can convert int* to const int* (nonconst to const)

	// int &r = ci			// error: can't bind an ordinary int& to a const int object
	const int& r2 = i;		// ok: can bind const int& to plain int

	return 0;
}