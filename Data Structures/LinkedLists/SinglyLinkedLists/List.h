/**
	Patrick Aliberti
	List.h
	5/13/2022
	
	This file contains the imlpementation for the singly linked list data structure
*/
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

class List {
private:
	int qty, max;
	node* head;
	
public:
	List();
	List(int);
	~List();
	
	int capacity();
	int size();
	int peek();
	bool isEmpty();
	bool isFull();
	bool push(int);
	bool insert(int);
	bool remove(int);
	void clear();
	void display();
};

// Constructor
List::List(int m) {
	if (m < 0)
		max = 0;
		
	else
		max = m;

	qty = 0;
	head = nullptr;
}

// Destructor
List::~List() { clear(); }

// Accessors
int List::capacity() { return max; }
int List::size() { return qty; }

int List::peek() {
	if (!head)
		return -1;
		
	return head->val;
}

bool List::isEmpty() {
	if (qty == 0)
		return true;
		
	return false;
}

bool List::isFull() {
	if (qty == max)
		return true;
		
	return false;
}

bool List::push(int v) {
	node *newNode;
	node *nodePtr;
	
	newNode = new node;
	newNode->val = v;
	newNode->next = nullptr;
	
	if (!head)
		head = newNode;
		
	else {
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
			
		nodePtr->next = newNode;
	}
	qty++;
	return true;
}

bool List::remove(int v) {
	node *nodePtr;
	node *previousNode;
	
	if (!head)
		return false;
		
	if (head->val == v) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		for (nodePtr = head; nodePtr != nullptr && nodePtr->val != v; nodePtr = nodePtr->next)
			previousNode = nodePtr;	
			
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}	
	}
	qty--;
	return true;
}

void List::clear() {
	while (remove(peek()));
	return;
}

void List::display() {
	for (node* scan = head; scan != nullptr; scan = scan->next)
		cout << scan->val << "\n";
		
	cout << endl;
	return;
}

#endif
