/**
	Patrick Aliberti
	DoublyLinkedList.h
	5/14/2022
	
	This file contains the implementation for the doubly linked list data structure
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
	bool pop_front();
	bool pop_back();
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
	while (pop_front());	
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
	
	if (!tail)
		head = tail = temp;
		
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	qty++;
	return true;
}

bool DLList::pop_front() {
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

bool DLList::pop_back() {
	if (isEmpty())
		return false;
		
	Node *cur;		
	if(head == tail) {
        cur = head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        cur = tail;
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete cur;
    qty--;
    return true;
}

bool DLList::remove(const int v) {
	Node *temp;
    temp = head;
    if (head == tail) {
        if(head->val != v)
            return false;

        head = nullptr;
        tail = nullptr;
        delete temp;
        return true;
    }
    
    if(head->val == v) {
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return true;
    }
    else if (tail->val == v) {
        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return true;
    }
    
    while (temp->val != v) {
        temp = temp->next;
        if (temp == nullptr)
            return true;
    }
    
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    
    delete temp;
    return true;
}

void DLList::display() const {
	if (isEmpty())
		return;
		
	for (Node* scan = head; scan != nullptr; scan = scan->next)
		cout << "\n" << scan->val;	

	cout << endl;
	return;
}


#endif
