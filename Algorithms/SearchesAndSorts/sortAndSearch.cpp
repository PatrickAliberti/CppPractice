/**********************************************************************
program:	sortAndSearch.cpp
date:       12/14/2020
author:     G.Panczner
purpose:	This program loads an array with random numbers from 1-20,
			then displays the contents of the array. It then sorts the
			array and outputs and outputs 2 columns. 1) showing a list
			of the distinct array elements and 2) showing a count of
			the number of occurances of each element
**********************************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// Global constants
const int SIZE = 50;

// Function prototypes
void display_array(const int number_list[]);
void display_frequency(const int number_list[]);
void load_array(int number_list[]);
void sort_array(int number_list[]);
void swap(int &a, int &b);

int main()
{
	srand(time(0));
	int number_list[SIZE] = {0};

	// Load array with random values
	load_array(number_list);
	
	// Display array
	display_array(number_list);
	
	// Sort array using a descending order selection sort
	sort_array(number_list);
	
	// Display frequency
	display_frequency(number_list);
	
	
	return 0;
}
////////////////////////////////////////////////////////////////////
void display_array(const int number_list[])
{
	cout << "Number List:\n";
	for (int index = 0; index < SIZE; index++)
	{
		cout << number_list[index] << " ";
	}
	cout << "\n" << endl;
}
////////////////////////////////////////////////////////////////////
void display_frequency(const int number_list[])
{
	int count = 0;
	
	cout << "Number:   Frequency:\n";
	for (int i = 20; i > 0; i--)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == number_list[j])
			{
				count++;
			}
		}
		if (i < 10)
			cout << i << setw(10) << count << "\n";
		else
			cout << i << setw(9) << count << "\n";
			
		count = 0;
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////
void load_array(int number_list[])
{
	for (int index = 0; index < SIZE; index++)
	{
		number_list[index] = ((rand() % 20) + 1);
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////
void sort_array(int number_list[])
{
	int minIndex, minValue;
	
	cout << "Array contents after each pass of the sort:\n";
	for (int start = (SIZE - 1); start > 0; start--)
	{
		minIndex = start;
		minValue = number_list[start];
		for (int index = start + 1; index < SIZE; index++)
		{
			if (number_list[index] < minValue)
			{
				minValue = number_list[index];
				minIndex = index;
			}
		}
		swap(number_list[minIndex], number_list[start]);
		cout << number_list[minIndex] << " ";
	}
	cout << "\n" << endl;
}
////////////////////////////////////////////////////////////////////
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
