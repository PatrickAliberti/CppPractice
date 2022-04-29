/**
	Patrick Aliberti
	LinkedList.h
	
*/
#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

class My_list {
private:
	int qty;
	int max;
	node* start;
	
	void display(node*);
	int getBig();	
	
public:
	My_list(int);

	int size();
	int capacity();

	bool isEmpty();
	bool isFull();
	bool clear();
	
	bool add(int, node* s);
	bool remove(int);
	bool find(int);
	bool insertionSort();
};

// Constructor
My_list::My_list(int m) {
	max = m;
	
	start = nullptr;	
}

// Accessors
int My_list::size() { return qty; }
int My_list::capacity() { return max; }

/**
	Task:	Determine if the list is empty
	
	Param:	None
	
	Return:	True if empty, false otherwise
*/
bool My_list::isEmpty() {
	if (qty == 0)
		return true;
		
	return false;
}

/**
	Task:	Determine if the list is full
	
	Param:	None
	
	Return:	True if full, false otherwise
*/
bool My_list::isFull() {
	if (qty == max)
		return true;
		
	return false;
}

/**
	Task:	Clear the list
	
	Param:	None
	
	Return:	True
*/
bool My_list::clear() {
	node* temp = start;
	while (start != nullptr) {
		start = start->next;
		delete temp;
		temp = start;
	}
	qty = 0;
	return true;
}

/**
	Task:	Insert new node before node s
	
	Param:	Value of node and the node it will be placed in front of
	
	Return:	False if the list is full, true if node is added
	
*/
bool My_list::add(int v, node* s) {
	if (isFull())
		return false;
	
	node* temp = new node;
	temp->val = v;
	temp->next = s;
	s = temp;
	qty++;
	
	return true;
}

/**
	Task:	Delete an element
	
	Param:	The value of the element
	
	Return:	False if linked list is empty, true otherwise
*/
bool My_list::remove(int v) {
	if (isEmpty())
		return false;
		
	node* scan = start;
	if (scan->val == v) {
		start = scan->next;
		delete scan;
		qty--;
		return true;
	}
	
	while (scan->next != nullptr) {
		if (scan->next->val == v) {
			node* temp = scan->next;
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
	Task:	Find element in the list
	
	Param:	the value of the element
	
	Return:	True if found, false otherwise
*/
bool My_list::find(int v) {
	node* scan;
	for (scan = start; scan != nullptr; scan = scan->next) {
		if (scan->val == v)
			return true;
	}
	return false;
}

int My_list::getBig() {
	if (isEmpty()) 
		return INT_MIN;
		
	int lg = start->val;
	for (node *scan = start->next; scan!= nullptr; scan = scan->next) {
		if (scan->val > lg)
			lg = scan->val;
	}
	return lg;
}

bool My_list::insertionSort() {
	node* list2 = nullptr;
	int lg, size = 0;
	while (start != nullptr) {
		lg = getBig();
		if (lg == INT_MIN)
			break;
		
		remove(lg);
		add(lg, list2);
		qty--;
		size++;
	}
	qty = size;
	start = list2;
	return true;
}
