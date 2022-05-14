/**
	Patrick Aliberti
	ListTemplate.h
	5/14/2022
	
	This file contains a linked list template so that it can accept any data type.
*/
#ifndef LISTTEMPLATE_H
#define LISTTEMPLATE_H

#include <iostream>
using namespace std;

template <class T>
class List {
private:
	struct node {
		T val;
		node *next;
	};
	
	node *head;
	int qty, max;
	
public:
	List();
	List(int);
	~List();
	
	int size() const;
	int capacity() const;
	int peek() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	bool push(T);
	bool insert(T);
	bool remove(T);
	void display() const;
};

template <class T>
List<T>::List(int m) {
	if (m < 0);
		max = 0;
		
	else
		max = m;
		
	qty = 0;
	head = nullptr;
}

template <class T>
List<T>::~List() { clear(); }

template <class T>
int List<T>::size() const { return qty; }

template <class T>
int List<T>::capacity() const { return max; }

template <class T>
int List<T>::peek() const {
	if (!head)
		return -1;
		
	return head->val;
}

template <class T>
bool List<T>::isEmpty() const {
	if (qty == 0)
		return true;
		
	return false;
}

template <class T>
bool List<T>::isFull() const {
	if (qty == max)
		return true;
		
	return false;
}

template <class T>
void List<T>::clear() {
	while (remove(peek()));
	return;
}

template <class T>
bool List<T>::push(T v) {
	if (isFull())
		return false;
		
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

template <class T>
bool List<T>::insert(T v) {
	if (isFull())
		return false;
	
	node *newNode;
	node *nodePtr;
	node *previousNode = nullptr;
	
	newNode = new node;
	newNode->val = v;
	
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

template <class T>
bool List<T>::remove(T v) {
	if (isEmpty())
		return false;
	
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
			previousNode->next =  nodePtr->next;
			delete nodePtr;
		}
	}
	
	qty--;
	return false;
}

template <class T>
void List<T>::display() const {
	node *nodePtr;
	nodePtr = head;
	while (nodePtr) {
		cout << nodePtr->val << endl;
		nodePtr = nodePtr->next;
	}
}

#endif
