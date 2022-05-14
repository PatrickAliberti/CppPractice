/**
	Patrick Aliberti
	my_stack.h
	02/02/2022
	
	This file contains contains the node definition, the stack object
	definition, and the member function definitions for the stack object.
*/
#include <iostream>
using namespace std;
struct node {
	int val;
	node *next;
};

class stack {
private:
	int max;
	int qty;
	node *top;

public:
	stack();
	stack(int);
	~stack();
	
	int size();
	int capacity();
	bool isFull();
	bool isEmpty();
	bool push(int);
	bool pop();
	int getTop();
	bool clear();
	
	void display();		// for testing purposes
};

// Constuctors
stack::stack(int m) {
	qty = 0;
	top = nullptr;
	
	if (m < 0)
		max = 0;
	else
		max = m;
}

// Destructor
stack::~stack() {
	clear();
}

// Accessors
int stack::capacity() { return max; }
int stack::size() { return qty; }

/**
	Task:		Determines whether stack is full or not
	Parameters:	None
	Returns:	True if full, false if not full
*/
bool stack::isFull() {
	if (qty == max)
		return true;
	else
		return false;
}

/**
	Task:		Determines whether stack is empty or not
	Parameters:	None
	Returns:	True if empty, false if not empty
*/
bool stack::isEmpty() {
	if (qty == 0)
		return true;
	else
		return false;
}

/**
	Task:		Pushes a value onto the stack if there is room
	Parameters:	An integer
	Returns:	False if the stack is full, true if not and if the value was
				pushed
*/
bool stack::push(int num) {
	if (isFull())
		return false;
		
	node *temp = new node;
	temp->val = num;
	temp->next = top;
	
	top = temp;
	qty++;
	
	return true;
}

/**
	Task:		Pops a value from the stack if one exists
	Parameters:	An integer
	Returns:	False if the stack is empty, true if not and if the value was
				popped
*/
bool stack::pop() {
	if (isEmpty())
		return false;
		
	node* temp = top;
	top = top->next; 	// or temp->next
	
	qty--;
	delete temp;
	return true;
}

/**
	Task:		Get the top value
	Parameters:	None
	Returns:	The top value
*/
int stack::getTop() {
	if (isEmpty())
		return 0;
	
	return top->val;
}

/**
	Task:		Clears stack
	Parameters:	None
	Returns:	True
*/
bool stack::clear() {
	for (node* temp = top; temp != nullptr; temp = top) {
		top = top->next;
		delete temp;
	}
	
	qty = 0;
	return true;
}

void stack::display() {
	for (node* scan = top; scan != nullptr; scan = scan->next) {
		cout << scan->val << " ";
	}
}
