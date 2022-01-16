/**
*	Patrick Aliberti
*
*	DeEncrypt.cpp
*
*	This program de-encrypts the encrypted file
*
*	04/17/2021
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

const int C_STRING_SIZE = 21;

struct Agent
{
	char name[C_STRING_SIZE];
	int idNum;
	double years;
	char location[C_STRING_SIZE];
};

string getFileName();
int getNumOfRecords(const string);
Agent *readFileIntoArray(const string, const int);
void displayArray(const Agent *, const int);
int getKey();
Agent *deEncryptArray(Agent *, const int, const int);

int main()
{
	// Display a simple welcome message
	cout << "This program contains classified information. Follow the steps below to view and "
		 << "de-encrypt the data."
		 << endl << endl;
	
	// Prompt user for encrypted file name
	string fileName = getFileName();
	
	// Display the encrypted information
	int numOfRecords = getNumOfRecords(fileName);
	Agent *encryptArrayPtr = readFileIntoArray(fileName, numOfRecords);
	displayArray(encryptArrayPtr, numOfRecords);
	
	// De-encrypt the information and display it
	int key = getKey();
	Agent *deEncryptArrayPtr = deEncryptArray(encryptArrayPtr, numOfRecords, key);
	displayArray(deEncryptArrayPtr, numOfRecords);
	
	// Clean up allocated memory and pointers
	delete [] encryptArrayPtr;
	delete [] deEncryptArrayPtr;
	encryptArrayPtr = nullptr;
	deEncryptArrayPtr = nullptr;
	
	return 0;
}

/**
*	task:		Get the name of the input file
*
*	data in:	No paramters, has the user input the file name
*
*	data out:	Returns the valid file name that the user entered
*/
string getFileName()
{
	string filename;
	char again;
	
	cout << "Enter the name of the data file:\n";
	cin >> filename;
	
	fstream dataFile(filename);
	
	while (dataFile.fail())
	{
		cout << "ERROR: File could not be opened.\n"
			 << "Would you like to try again?[Y/n]\n";
		cin >> again;
		
		if (again == 'y' || again == 'Y')
		{
			cout << "Enter the name of the data file:\n";
			cin >> filename;
			dataFile.open(filename);
		}
		else if (again == 'n' || again == 'N')
		{
			exit(0);
		}
		else
		{
			cout << "USAGE: Enter Y or N";
			cin >> again;
		}
	}
	
	if (dataFile)
	{
		dataFile.close();
		return filename;
	}
}

/**
*	task:		Get the number of records in the file
*
*	data in:	The name of the file
*
*	data out:	The number of records in the file
*/
int getNumOfRecords(const string fileName)
{
	ifstream inFile(fileName, ios::in | ios::binary);
	Agent record;
	int count = 0;
	
	inFile.read(reinterpret_cast<char *>(&record), sizeof(record));	

	while (!inFile.eof())
	{
		count++;

		inFile.read(reinterpret_cast<char *>(&record), sizeof(record));	
	} 
	inFile.close();
	
	return count;
}

/**
*	task:		Read the data from the file into an array of structs
*
*	data in:	The name of the file and the number of records
*
*	data out:	A pointer to the array of structs
*/
Agent *readFileIntoArray(const string fileName, const int numOfAgents)
{
	ifstream inFile(fileName, ios::in | ios::binary);
	Agent record;
	
	Agent *agentArray = new Agent[numOfAgents];
	
	inFile.read(reinterpret_cast<char *>(&agentArray[0]), sizeof(record));	
	if (inFile)
	{
		for (int i = 1; i < numOfAgents; i++)
		{		 
			inFile.read(reinterpret_cast<char *>(&agentArray[i]), sizeof(record));	
		}
	}
	else
	{
		cout << "Could not open the file." << endl;
	}
	inFile.close();
	
	return agentArray;
}

/**
*	task:		Displays the contents from the dynamic array of structures
*
*	data in:	The dynamic array of structs and the number of records
*
*	data out:	No return value, displays the contents of the array of structs
*/
void displayArray(const Agent *agentArr, const int numOfAgents)
{
	cout << "\n|==================================================================|";
	cout << "\n|Name" << setw(21)
		 << "ID Number" << setw(20)
		 << "Years of Service" << setw(22)
		 << "Location|";
	cout << "\n|==================================================================|\n";
	
	for (int i = 0; i < numOfAgents; i++)
	{
		int nameLen = strlen(agentArr[i].name);
		int setWidth = 24 - nameLen;
		
		cout << "|" << agentArr[i].name << setw(setWidth)
			 << agentArr[i].idNum << setw(21)
			 << agentArr[i].years << setw(21)
			 << agentArr[i].location << "|";
		cout << "\n";
	}
	cout << "|==================================================================|\n";
}

/**
*	task:		Gets the encryption key from the user
*
*	data in:	No parameters, asks the user for the encryption key
*
*	data out:	Returns the encryption key
*/
int getKey()
{
	int key;
	cout << "Enter the Encryption key:";
	cin >> key;
	
	return key;
}

/**
*	task:		De-encrypts the contents from the array
*
*	data in:	The number of records and the key
*
*	data out:	The encrypted dynamic array
*/
Agent *deEncryptArray(Agent *deEncryptArr, const int numOfAgents, const int key)
{
	
	for (int i = 0; i < numOfAgents; i++)
	{	
		// Encrypt the names
		for (int j = 0; j < strlen(deEncryptArr[i].name); j++)
		{
			deEncryptArr[i].name[j] -= 14 + key;
		}
		
		// Encrypt the ID numbers
		deEncryptArr[i].idNum += 1052 + key;
		
		// Encrypt the years of service
		deEncryptArr[i].years -= ((key * -2.34) / 3.1415);
		
		// Encrypt the location
		for (int j = 0; j < strlen(deEncryptArr[i].location); j++)
		{
			deEncryptArr[i].location[j] -= 14 + key;
		}
	}
	
	return deEncryptArr;
}
