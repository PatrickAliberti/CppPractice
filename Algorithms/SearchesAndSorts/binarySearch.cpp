#include <iostream>
using namespace std;

const int SIZE = 20;

// function prototype
int binarySearch(const int [], int size, int value);

int main()
{
	// Array with employees IDs sorted in ascending order
	int idNums[SIZE] = {101, 142, 147, 189, 199, 207, 222,
						234, 289, 296, 310, 319, 388, 394,
						417, 429, 447, 521, 536, 600};
	int results;	// To holdthe search results
	int empID;		// To hold an employees ID
	
	// Get an emplyee ID to search for
	cout << "Enter the employee ID you wish to search for: ";
	cin >> empID;
	
	// Search for the ID
	results = binarySearch(idNums, SIZE, empID);
	
	// If results contain -1, the value was not found
	if (results == 1)
	{
		cout << "That number does not exist in the array.\n";
	}
	// Otherwise results contains the subscript of 
	// the specified employee ID in the array
	else
	{
		cout << "The ID is found at element " << results;
		cout << " in the array.\n";
	}
	return 0;
}
///////////////////////////////////////////////////////////////
int binarySearch(const int array [], int size, int value)
{
	int first = 0,
		last = size -1,
		middle,
		position = -1;
	bool found = false;
	
	while (!found && first <= last)
	{
		middle = (first + last) / 2;	// Calculate midway point
		if (array[middle] == value)		// If the value if found
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)// If value is in lower half
		{
			last = middle -1;
		}
		else						   //If value is in upper half
		{
			first = middle +1;
		}
	}
	return position;
}
