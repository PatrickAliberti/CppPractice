/*
Program: deckQueue.h
Author: Branden Favre
Assignment: Final Project
Due Date: 5/4/22
*/
#include <cstddef>
#include <iostream>
using namespace std;

struct deckNode
{
	char face;
	deckNode * next;
};

class deckQueue
{
	private:
		deckNode * in;
		deckNode * out;
		int max;
		int qty;
	public:
		deckQueue();
		deckQueue(int);
		bool push(char);
		bool pop(char &);
		int size();
		bool isEmpty();
		bool isFull();
		bool clear();
		~deckQueue();
};
/******************************************************************************
Default constructor. Sets in and out to NULL.
******************************************************************************/
deckQueue::deckQueue()
{
	in = out = NULL;
}
/******************************************************************************
Overloaded constructor. Takes in int m. Sets in and out to NULL, qty to 0, 
and max to m unless max is less than 0, set to 0 in that case.
******************************************************************************/
deckQueue::deckQueue(int m)
{
	in = out = NULL;
	qty = 0;
	if(m < 0)
		max = 0;
	else
		max = m;
}
/******************************************************************************
push takes in char f. Checks if the deckQueue is full, returns false
if it is. Creates a pointer called temp that points to a new node. Sets temp
face to f and temp next to NULL. Checks if out is NULL and if it is sets in and
out to temp and return true. Else sets in next to temp and in to temp. 
Returns true.
******************************************************************************/
bool deckQueue::push(char f)
{
	if(isFull())
	{
		cout << "Error. deckQueue full.\n";
		return false;
	}
	deckNode * temp = new deckNode;
	temp -> face = f;
	temp -> next = NULL;
	qty++;
	if(out == NULL)
	{
		in = out = temp;
		return true;
	}
	in -> next = temp;
	in = temp;
	return true;
}
/******************************************************************************
pop takes in char f passed by reference. If out equals NULL, return false. 
Sets node temp to out and f to out face. If out equals in, in and out set to 
NULL, delete temp, and returns true. Else out equals out next, delete temp, 
and return true.
******************************************************************************/
bool deckQueue::pop(char &f)
{
	if(out==NULL)
		return false;
	deckNode * temp = out;
	f = out -> face;
	qty--;
	if(out==in)
	{
		in = out = NULL;
		delete temp;
		return true;
	}
	out = out -> next;
	delete temp;
	return true;
}
/******************************************************************************
size returns deckQueue qty
******************************************************************************/
int deckQueue::size()
{
	return qty;
}

/******************************************************************************
isEmpty checks if qty is equal to 0 or if in or out are equal to NULL.
If so, sets in and out to NULL, qty to 0, and returns true. Else, returns false
******************************************************************************/
bool deckQueue::isEmpty()
{
	if(qty == 0 || in == NULL || out == NULL)
	{
		in = out = NULL;
		qty = 0;
		return true;
	}
	return false;
}
/******************************************************************************
isFull checks if qty is equal to max. returns true if so, false if not.
******************************************************************************/
bool deckQueue::isFull()
{
	if(qty == max)
		return true;
	return false;
}
/******************************************************************************
clear creates variables x, calls the pop function in a while loop, 
essential clearing the deckQueue, returns true.
******************************************************************************/
bool deckQueue::clear()
{
	char x;
	while(pop(x));
	return true;
}
/******************************************************************************
Deconstructor calls clear()
******************************************************************************/
deckQueue::~deckQueue()
{
	clear();
}
