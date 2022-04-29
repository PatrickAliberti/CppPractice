/**
	Patrick Aliberti
	my_stack.h
	02/25/2022
	
	This file contains contains the node definition, the stack object
	definition, and the member function definitions for the stack object.
*/
struct stackNode {
	int val;
	stackNode *next;
};

class My_stack {
private:
	int max;
	int qty;
	stackNode *top;

public:
	My_stack();
	My_stack(int);
	~My_stack();
	
	int size();
	int capacity();
	bool isFull();
	bool isEmpty();
	bool push(int);
	bool pop();
	int getTop();
	bool clear();
};

// Constuctors
My_stack::My_stack(int m) {
	qty = 0;
	top = nullptr;
	
	if (m < 0)
		max = 0;
	else
		max = m;
}

// Destructor
My_stack::~My_stack() {
	clear();
}

// Accessors
int My_stack::capacity() { return max; }
int My_stack::size() { return qty; }

/**
	Task:		Determines whether stack is full or not
	
	Parameters:	None
	
	Returns:	True if full, false if not full
*/
bool My_stack::isFull() {
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
bool My_stack::isEmpty() {
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
bool My_stack::push(int num) {
	if (isFull())
		return false;
		
	stackNode *temp = new stackNode;
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
bool My_stack::pop() {
	if (isEmpty())
		return false;
		
	stackNode* temp = top;
	top = top->next; 	// or temp->next
	
	delete temp;
	qty--;
	return true;
}

/**
	Task:		Get the top value
	
	Parameters:	None
	
	Returns:	The top value
*/
int My_stack::getTop() {
	if (isEmpty())
		return 0;
	
	return top->val;
}

/**
	Task:		Clears stack
	
	Parameters:	None
	
	Returns:	True
*/
bool My_stack::clear() {
	for (stackNode* temp = top; temp != nullptr; temp = top) {
		top = top->next;
		delete temp;
	}
	
	qty = 0;
	return true;
}
