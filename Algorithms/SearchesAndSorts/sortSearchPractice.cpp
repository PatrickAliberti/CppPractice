#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int linearSearch(int [], int, int);

int main()
{
	int val;
	const int SIZE = 5;
	int linear[SIZE] = {0};
	
	cout << "Choose the value you would like to find: ";
	cin >> val;
	
	linearSearch(linear, SIZE, val);
	cout << val << " was located at element " << linearSearch(linear, SIZE, val);
	
	return 0;
}
/////////////////////////////////////////////////////////////////////
int linearSearch(int arr[], int size, int value)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = (rand() % 5) + 1;
		cout << arr[i] << "\n";
	}
	
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
