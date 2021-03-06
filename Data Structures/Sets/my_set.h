/**
	Patrick Aliberti
	my_set.cpp
	02/25/2022
	
	This file contains contains the node definition, the set object
	definition, and the member function definitions for the set object.
*/
#include <iostream>
using namespace std;

struct node {
	node* prev;
	node* next;
	int val;
};

class My_set {
private:
	int qty;
	int max;
	node* it;
	node* end;
	
	int numOfFourOfAKinds;
	
public:
	My_set();
	My_set(int);
	
	int capacity();
	int size();
	int peek();
	int getNumOfFourOfAKinds();
	node* getEnd();
	bool isEmpty();
	bool clear();
	bool insert(int);
	node* find(int);
	bool erase(int);
	void removeFourOfAKind();
	void display();
};

// Constructor
My_set::My_set(int m) {
	max = m;
	qty = 0;
	numOfFourOfAKinds = 0;
	
	end = nullptr;
	it = nullptr;
}

// Accessors
int My_set::capacity() { return max; }
int My_set::size() { return qty; }
int My_set::getNumOfFourOfAKinds() { return numOfFourOfAKinds; }

int My_set::peek() {
	if (end == nullptr)
		return 0;
		
	else
		return end->val;
}

node* My_set::getEnd() { 
	it = end;
	return it;
}

/**
	Task:	Determine if the set is empty
	
	Param:	None
	
	Return:	True if empty, false otherwise
*/
bool My_set::isEmpty() {
	if (qty == 0)
		return true;
		
	return false;
}

/**
	Task:	Insert a value into the set
	
	Param:	The value to be inserted
	
	Return:	True if inserted, false if the set is full orif the value already
			exists
*/
bool My_set::insert(int v) {
	if (qty == max)
		return false;

	if (find(v) != nullptr) {
		return false;
	}
		
	node* temp = new node;
	temp->next = nullptr;
	temp->val = v;
	if (isEmpty()) {
		temp->prev = nullptr;
	}
	else {
		temp->prev = end;
		end->next = temp;
	}
	
	end = temp;
	qty++;
	return true;
}

/**
	Task:	Find if value exists in the set
	
	Param:	The value
	
	Return:	The value if it exists, null otherwise
*/
node* My_set::find(int v) {
	for (it = end; it != nullptr; it = it->prev) {
		if (it->val == v) {
			return it;
		}
	}
	return nullptr;
}

/**
	Task:	Erase a value from the set
	
	Param:	The value
		
	Return:	True if the value was erased, false if it didn't exist in the set
*/
bool My_set::erase(int v) {
	if (find(v) == nullptr)
		return false;
		
	if (it->next == it->prev) {
		end = nullptr;
	}
	else if (it->prev == nullptr) {
		it->next->prev = nullptr;
	}
	else if (it->next == nullptr) {
		it->prev->next = nullptr;
		end = it->prev;
	}
	else {
		it->prev->next = it->next;
		it->next->prev = it->prev;
	}
	
	qty--;
	delete it;
	it = end;
	return true;
}

bool My_set::clear() {
	while (erase(peek()));
	return true;
}

void My_set::removeFourOfAKind() {
	int ofAKind;
	for (it = end; it != nullptr; it = it->prev) {
		ofAKind = 1;
		for (node* it2 = end; it2 != nullptr; it2 = it2->prev) {
			if (it->val == it2->val)
				continue;
				
			if (it->val % 100 == it2->val % 100) {
				ofAKind++;
				if (ofAKind == 4) {
					numOfFourOfAKinds++;
					for (int i = 100; i < 401; i += 100) {
						erase((it->val % 100) + i);
					}
				}
			}
		}
	}
}

/**
	Task:	Display the values in the set
	
	Param:	None
	
	Return: None
*/
void My_set::display() {
	std::cout << "Your Hand" << "\n";
	for (it = end; it != nullptr; it = it->prev) {
		std::cout << it->val % 100 << "\t";
	}
	std::cout << "\n" << std::endl;
}
