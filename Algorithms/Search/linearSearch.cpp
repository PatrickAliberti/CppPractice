/**
*	Patrick Aliberti
*	linearSearch.cpp
*	12/10/2020
*
*	This program demonstrates the linear search algorithm
*/
#include <iostream>
using namespace std;

int linearSearch(const int[], int, int);

int main()
{
	const int SIZE = 5;
	int tests[SIZE] = {87, 75, 98, 100, 82};
	int results;
	
	// Search the array for 100;
	results = linearSearch(tests, SIZE, 100);
	
	// If linerSearch returned -1, then 100 was not found
	if (results == -1)
	{
		cout << "You did not earn 100 points on any test\n";
	}
	// Otherwise results contains the subscripts of the first 100 in the array
	else
	{
		cout << "you earned 100 points on test: ";
		cout << (results + 1) << endl;
	}
	return 0;
}

/**
*	task:		perform the linear search
* 
*	parameters:	a const integer array, the size of the array, and the value being searched for
* 
*	returns:	nothing
*/
int linearSearch(const int arr[], int size, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;
	
	while (index < size && !found)
	{
		if (arr[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}
