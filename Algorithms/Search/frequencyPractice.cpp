/**
*	Patrick Aliberti
*	frequencyPractice.cpp
*	12/11/2020
* 
*	This program randomly fills an array, sorts it in descending order then displays a chart showing the frequency for each number
*/
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

const int SIZE = 50;

void load_array(int list[]);
void sort_array(int list[]);
void display_array(const int list[]);
void display_frequency(const int list[]);

int main()
{
	int number_list[SIZE] = {0};
	
	load_array(number_list);
	display_array(number_list);
	sort_array(number_list);
	display_array(number_list);
	display_frequency(number_list);
	
	return 0;
}

/**
*	task:		Randomly fill array
* 
*	parameters: an integer array
* 
*	returns:	nothing
*/
void load_array(int list[])
{
	srand(time(0));
	for (int x=0; x < SIZE; x++)
		list[x] = rand()%20 + 1;
}

/**
*	task:		Sort array
*
*	parameters: an integer array
*
*	returns:	nothing
*/
void sort_array(int list[])
{
	int large, index, temp;
	
	for (int start=0; start < SIZE-1; start++)
	{
		index = start;
		large = list[start];
		for (int scan=start+1; scan < SIZE; scan++)
		{
			if (list[scan] > large)
			{
				large = list[scan];
				index = scan;
			}
		}
		temp = list[index];
		list[index] = list[start];
		list[start] = temp;
		
		display_array(list);
	}
}

/**
*	task:		display array
*
*	parameters: a const integer array
*
*	returns:	nothing
*/
void display_array(const int list[])
{
	cout << endl;
	
	for (int x=0; x < SIZE; x++)
		cout << list[x] << ", ";
}

/**
*	task:		display frequency of each number
*
*	parameters: a const integer array
*
*	returns:	nothing
*/
void display_frequency(const int list[])
{
	int current=list[0], count = 0;
	cout << endl << setw(3) << "N" << setw(6) << "Count";
	
	for (int x=0; x < SIZE; x++)
	{
		if (list[x] == current)
			count++;
		else
		{
			cout << endl << setw(3) << current << setw(3) << count;
			
			current = list[x];
			count = 1;
		}
	}
	cout << endl << setw(3) << current << setw(6) << count;
}
