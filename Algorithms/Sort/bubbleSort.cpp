/**
*	Patrick Aliberti
*	bubbleSort.cpp
*	12/6/2020
*
*	This program demonstrates the bubble sort algorithm
*/
#include <iostream>
using namespace std;

void bubbleSort(int[], int);
void swap(int &, int &);

int main()
{
	const int SIZE = 6;
	
	// Array of unsorted values
	int values[SIZE] = {6, 1, 5, 2, 4, 3};
	
	// Display the unsorted array
	cout << "The unsorted values:\n";
	for (int index = 0; index < SIZE; index++)
	{
		cout << values[index];
	}
	cout << endl;
	
	// Sort the array
	bubbleSort(values, SIZE);
	
	// Display the sorted array
	cout << "The sorted values:\n";
		for (int index = 0; index < SIZE; index++)
	{
		cout << values[index];
	}
	cout << endl;
	
	return 0;
}

/**
*	task:		perform the bubble sort
* 
*	parameters:	an integer array and the size of the array
* 
*	returns:	nothing
*/
void bubbleSort(int array[], int size)
{
	int maxElement;
	int index;
	
	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}
		}
	}
}

/**
*	task:		swap two variables
*
*	parameters:	integer references to each variable
*
*	returns:	nothing
*/
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
