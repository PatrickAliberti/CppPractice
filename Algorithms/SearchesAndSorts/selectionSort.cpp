// This program demonstrates the selection sort algorithm
#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(int[], int);
void swap (int &, int &);

int main()
{
	const int SIZE = 6;
	
	// Array ofunsorted values
	int values[SIZE] = {6, 1, 5, 2, 4, 3};
	
	// Display the unsorted array
	cout << "The unsorted values:\n";
	for (int index = 0; index < SIZE; index++)
	{
		cout << values[index] << " ";
	}
	cout << endl;
	
	// Sort the array
	selectionSort(values, SIZE);
	
	// Display the sorted array
	cout << "The sorted values:\n";
	for (int index = 0; index < SIZE; index++)
	{
		cout << values[index] << " ";
	}
	cout << endl;
}
////////////////////////////////////////////////////////////
void selectionSort(int array[], int size)
{
	int minIndex, minValue;
	
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}
////////////////////////////////////////////////////////////
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
