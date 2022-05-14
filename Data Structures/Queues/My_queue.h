/**
	Patrick Aliberti
	my_queue.h
	02/09/2022
	
	This file contains the node definition, the queue object definition, and the
	member function definitions for the queue object.
*/
#include <iostream>
using namespace std;

struct node {
	int qty;
	double price;
	node* next;
};

class My_queue {
private:
	node* in;
	node* out;
	int max;
	int qty;
	
public:
	My_queue(int);
	~My_queue();
	
	int size();
	int capacity();
	bool pop(int&, double&);
	bool isEmpty();
	bool isFull();
	bool clear();
	
	double sell(int);
	bool buy(int, double);
	
	void display();
};

void My_queue::display() {
	for (node* scan = out; scan != nullptr; scan = scan->next) {
		cout << scan->price << "   ";
	}
}

// Constructors
My_queue::My_queue(int m) {
	in = out = nullptr;
	qty = 0;
	max = m;
}

// Destructor
My_queue::~My_queue() { clear(); }

// Accessors
int My_queue::size() { return qty; }
int My_queue::capacity() { return max; }

/**
	Task:		Pop value from the queue
	
	Parameters: Reference to an int for the quantity, and a reference to a
				double to set the price
				
	Returns:	False if queue is empty, true otherwise
*/
bool My_queue::pop(int& q, double& p) {
	if (isEmpty())
		return false;
		
	node* temp = out;
	q = out->qty;
	p = out->price;
	qty--;
	
	if (qty == 0) {
		in = out = nullptr;
		delete temp;
		return true;
	}
	out = out->next;
	delete temp;
	
	return true;
}

/**
	Task:		Check if queue is empty
	
	Parameters:	None
	
	Returns:	True if empty, false otherwise
*/
bool My_queue::isEmpty() {
	if (qty == 0)
		return true;
		
	return false;
}

/**
	Task:		Check if queue is full
	
	Parameters:	None
	
	Returns:	True if full, false otherwise
*/
bool My_queue::isFull() {
	if (qty == max)
		return true;
		
	return false;
}

/**
	Task:		Clear the queue
	
	Parameters:	None
	
	Returns: 	True
*/
bool My_queue::clear() {
	int x;
	double y;
	while (pop(x, y));
	
	return true;
}

/**
	Task:		Perform buy action by pushing a value to the queue
	
	Parameters:	An int to set the quantity, and a double to set the price
	
	Returns:		False if queue is full, otherwise true
*/
bool My_queue::buy(int q, double p) {
	if (isFull())
		return false;
	
	node* temp = new node;
	temp->qty = q;
	temp->price = p;
	temp->next = nullptr;
	
	if (isEmpty()) {
		in = out = temp;
		qty++;
		return true;
	}
	in->next = temp;
	in = temp;
	qty++;
	
	return true;
}

/**
	Task:		Perform sell action, if the sell quantity is larger than the
				stock quantity in the last node, remove the rest of the sell
				quantity from the next node
	
	Parameters:	The quanitity of stocks to be sold
	
	Returns:	The total selling price of the transaction
*/
double My_queue::sell(int qty_to_rm)  {
	double total_selling_price = 0;
	while (qty_to_rm > 0) {
		if (out->qty >= qty_to_rm) {
			total_selling_price += qty_to_rm * out->price;
			out->qty -= qty_to_rm;
			qty_to_rm = 0;
			
			if (out->qty == 0) {
				int x;
				double y;
				pop(x, y);
			}
		}
		else {
			total_selling_price += out->qty * out->price;
			qty_to_rm -= out->qty;
			
			int x;
			double y;
			pop(x, y);
		}
	}
	return total_selling_price;
}
