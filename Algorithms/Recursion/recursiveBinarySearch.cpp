/**
*	Patrick Aliberti
*	recursiveBinarySearch.cpp
*	12/30/2020
*
*	This  program demonstrates the recursive binary search function
*/
#include <iostream>
using namespace std;

int binarySearch(int [], int, int, int);

const int SIZE = 20;

int main()
{
	int tests[SIZE] = {100, 126, 147, 187, 198, 217, 240,
					   245, 257, 273, 286, 288, 299, 317,
					   326, 339, 367, 388, 391, 428};
					   
	int empId;
	int results;
	
	// Get employee ID number to search for
	cout << "Enter employee ID:";
	cin >> empId;
	
	// Search for the ID in the array
	results = binarySearch(tests, 0, SIZE - 1, empId);
	
	// Display the results to the screen
	if (results == -1)
		cout << "That number does not exist in the array.\n";
	else
	{
		cout << "That id is found at element " << results
			 << " in the array.\n";
	}
	return 0;
}

// binarySearch function definition
int binarySearch(int array[], int first, int last, int value)
{
	int middle;
	
	if (first > last)
		return -1;
	middle = (first + last)/2;
	if (array[middle] == value)
		return middle;
	if (array[middle] < value)
		return binarySearch(array, middle + 1, last, value);
	else
		return binarySearch(array, middle + 1, last, value);
}
