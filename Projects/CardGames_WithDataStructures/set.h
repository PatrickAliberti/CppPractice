/**
	Patrick Aliberti
	set.h
	05/04/2022
	
	This file contains defines the set data structure definition
*/
#include <iostream>
using namespace std;

struct setNode {
	char face;
	char suit;
	setNode *next;
};

class set {
private:
	int max;
	int qty;
	setNode *top;

public:
	set();
	set(int);
	~set();
	
	int size();
	int capacity();
	bool isFull();
	bool isEmpty();
	bool push(string);
	bool pop();
	string getTop();
	bool find(string);
	bool erase(string);
	bool clear();
	
	void display();		// for testing purposes
};

// Constuctors
set::set(int m) {
	qty = 0;
	top = nullptr;
	
	if (m < 0)
		max = 0;
	else
		max = m;
}

// Destructor
set::~set() { clear(); }

// Accessors
int set::capacity() { return max; }
int set::size() { return qty; }

/**
	Task:		Determines whether stack is full or not
	Parameters:	None
	Returns:	True if full, false if not full
*/
bool set::isFull() {
	if (qty == max)
		return true;

	return false;
}

/**
	Task:		Determines whether stack is empty or not
	Parameters:	None
	Returns:	True if empty, false if not empty
*/
bool set::isEmpty() {
	if (qty == 0)
		return true;

	return false;
}

/**
	Task:		Pushes a value onto the stack if there is room
	Parameters:	An string holding face and suit of a card
	Returns:	False if the stack is full, true if not and if the value was
				pushed
*/
bool set::push(string card) {
	if (isFull())
		return false;
		
	setNode* temp = new setNode;
	temp->face = card[0];
	temp->suit = card[1];
	temp->next = top;
	
	top = temp;
	qty++;
	
	return true;
}

/**
	Task:		Pops a value from the stack if one exists
	Parameters:	None
	Returns:	False if the stack is empty, true if not and if the value was
				popped
*/
bool set::pop() {
	if (isEmpty())
		return false;
		
	setNode* temp = top;
	top = top->next; 	// or temp->next
	
	qty--;
	delete temp;
	return true;
}

/**
	Task:		Get the top value
	Parameters:	None
	Returns:	The top card
*/
string set::getTop() {
	if (isEmpty())
		return 0;
		
	string card = "   ";
	card[0] = top->face;
	card[1] = top->suit;
	card[2] = '\n';
	
	return card;
}

bool set::find(string val) {
	if (isEmpty())
		return false;
		
	for (setNode* scan = top; scan != nullptr; scan = scan->next) {
		if (val[0] == scan->face && val[1] == scan->suit)
			return true;
	}
}

bool set::erase(string val) {
	if (!find(val))
		return false;
	
	setNode* scan = top;
	if (scan->face == val[0] && scan->suit == val[1]) {
		top = scan->next;
		delete scan;
		qty--;
		return true;
	}
	
	while (scan->next != nullptr) {
		if (scan->next->face == val[0] && scan->next->suit == val[1]) {
			setNode* temp = scan->next;
			scan->next = temp->next;
			delete temp;
			qty--;
			return true;
		}
		scan = scan->next;
	}
	return true;
}

/**
	Task:		Clears stack
	Parameters:	None
	Returns:	True
*/
bool set::clear() {
	for (setNode* temp = top; temp != nullptr; temp = top) {
		top = top->next;
		delete temp;
	}
	
	qty = 0;
	return true;
}

void set::display() {
	for (setNode* scan = top; scan != nullptr; scan = scan->next)
		cout << scan->face << scan->suit << "\n";
}
