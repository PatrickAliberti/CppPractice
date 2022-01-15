/******************************************************************************
Patrick Aliberti

testVect.cpp

This program tests out the Vect class

04/16/2021
******************************************************************************/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "vect.h"
using namespace std;

int numOfSteps = 0;
float aveStep;

Vect generateStep(const float, float);

int main()
{
	// Get the size of the field
	float sizeOfField;
	cout << "What is the size (in cm) of the field?\n";
	cin >> sizeOfField;
	
	// Get the size of dizzyKid's gate
	float sizeOfGate;
	cout << "What is the size (in cm) of dizzyKid's gate?\n";
	cin >> sizeOfGate;
	
	// Generate random vector. Add that vector to accumulation vector until the
	// magnitude is greater than the size of the field
	Vect lastStep = generateStep(sizeOfField, sizeOfGate);
	cout << "\n" << lastStep;
	
	// Report the number of steps and average outward distance of each step
	cout << "\ndizzyKid stepped " << numOfSteps << " times,\n"
		 << "with an average distance of " << aveStep << " per step.";
	
	return 0;
}

Vect generateStep(const float fs,float gs)
{
	Vect vectAccum;
	unsigned seed = time(0);
	srand(seed);
	float a, m;
	int g = static_cast<int>(gs);
	
	// Generate a random vector until out of bounds
	while (vectAccum.getMag() <= fs)
	{
		Vect dizzyStep((rand() % (359) + 1), (rand() % (g) + 1), 'p');
		vectAccum = vectAccum + dizzyStep;
		// cout << vectAccum;
		
		numOfSteps++;
	}
	aveStep = vectAccum.getMag() / numOfSteps;
	return vectAccum;
}
