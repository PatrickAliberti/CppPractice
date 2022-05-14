/**
	Patrick Aliberti
	DoublyLinkedList.h
	5/14/2022
	
	This file contains the implementation for the doubly linked list data structure
	
	TO DO:  - Test/fix delete_back(), insert(), and remove()
			- change delete to pop
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
	int val;
	Node *next, *prev;
	Node(int);
};

Node::Node(int v) {
	val = v;
	next = prev = nullptr;
}

class DLList {
private:
	Node *head, *tail;
	int qty, max;
	
public:
	DLList();
	DLList(const int);
	~DLList();
	
	int capacity() const;
	int size() const;
	int peekHead() const;
	int peekTail() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	
	bool push_front(const int);
	bool push_back(const int);
	bool delete_front();
	bool delete_back();
	bool insert(const int);
	bool remove(const int);
	
	void display() const;
};

DLList::DLList(const int m) {
	if (m < 0)
		max = 0;
	
	else
		max = m;
		
	qty = 0;
	head = tail = nullptr;
}

DLList::~DLList() { clear(); }

int DLList::capacity() const { return max; }
int DLList::size() const { return qty; }

int DLList::peekHead() const {
	if (!head)
		return -1;
	
	return head->val;
}

int DLList::peekTail() const {
	if (!tail)
		return -1;
	
	return tail->val;
}

bool DLList::isEmpty() const {
	if (qty == 0)
		return true;
	
	return false;		
}

bool DLList::isFull() const {
	if (qty == max)
		return true;
	
	return false;
}

void DLList::clear() {
	while (delete_front());
	return;
}

bool DLList::push_front(const int v) {
	if (isFull())
		return false;
	
	Node * temp = new Node(v);
	
	if (!head)
		head = tail = temp;
		
	else {
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	qty++;
	return true;
}

bool DLList::push_back(const int v) {
	if (isFull())
		return false;
		
	Node *temp = new Node(v);
	
	if (!head)
		head = tail = temp;
		
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	qty++;
	return true;
}

bool DLList::delete_front() {
	if (isEmpty())
		return false;
		
	Node *temp = head;
	if (head == tail)
		tail = nullptr;
		
	head = head->next;
	delete temp;
	qty--;
	return true;
}

bool DLList::delete_back() {
	if (isEmpty())
		return false;
		
	Node *temp = tail;
	if (head == tail)
		head = nullptr;
		
	tail->next = nullptr;
	tail = tail->prev;
	
	delete temp;
	qty--;
	return true;
}

bool DLList::insert(const int v) {
	if (isFull())
		return false;
	
	Node *newNode;
	Node *nodePtr;
	Node *previousNode = nullptr;
	
	newNode = new Node(v);
	
	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}
	else {
		previousNode = nullptr;
		for (nodePtr = head; nodePtr != nullptr && nodePtr->val < v; nodePtr = nodePtr->next) {
			previousNode = nodePtr;
		}
					
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	qty++;
	return true;
}

bool DLList::remove(const int v) {
	Node *nodePtr;
	Node *previousNode;
	
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

void DLList::display() const {
	for (Node* scan = head; scan != nullptr; scan = scan->next) {
		cout << "yuh\n" << scan->val;	
	}
		
		
	cout << endl;
	return;
}


#endif
