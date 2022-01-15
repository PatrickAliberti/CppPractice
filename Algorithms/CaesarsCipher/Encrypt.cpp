/***************************************************************************************************
Patrick Aliberti

Encrypt.cpp

This program reads data from a binary file into a dynamic array of structs. It then copys the
encrypted data into another dynamic array which then gets written into another binary file. 

04/17/2021
****************************************************************************************************/
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

string getInFileName();
int getNumOfRecords(const string);
Agent *readFileIntoArray(const string, const int);
void displayAgentArray(const Agent *, const int);
int getKey();
Agent *copyEncryptArray(Agent *, const int, const int);
string getEncryptFile();
void writeArrayIntoFile(Agent *, const int, const string);

int main()
{
	// Display a simple  welcome message.
	cout << "This program contains classified information. Follow the steps below to view and "
		 << "encrypt the data provided."
		 << endl << endl;
	
	// Get the spy data file name
	string fileName = getInFileName();

	// Get the number of records
	int numOfRecords = getNumOfRecords(fileName);
	
	// Read the data from the file into a dynamic array of structs
	Agent *agentArrayPtr = readFileIntoArray(fileName, numOfRecords);
	
	// Display the contents of the struct array
	displayAgentArray(agentArrayPtr, numOfRecords);
	
	// Get the key from the user
	int key = getKey();
	
	// Copy the encrypted contents of the origional dynamic array into anew dynamic array
	Agent *encryptArrayPtr = copyEncryptArray(agentArrayPtr, numOfRecords, key);
	
	// Diplay the contents of the encrypted dynamic array
	displayAgentArray(encryptArrayPtr, numOfRecords);
	
	// Ask the user if they want to create an encryption file. If yes get the file name and the 
	// encryption key.
	string encryptFileName = getEncryptFile();
	
	// Write the encrypted dynamic array to a file. Tell user if transfre was successful and the
	// name of the encrpted file
	writeArrayIntoFile(encryptArrayPtr, numOfRecords, encryptFileName);
	
	// Clean up allocated memory and pointers
	delete [] agentArrayPtr;
	delete [] encryptArrayPtr;
	agentArrayPtr = nullptr;
	encryptArrayPtr = nullptr;
	
	return 0;
}

/****************************************************************************************************
task:		Get the name of the input file

data in:	No paramters, has the user input the file name

data out:	Returns the valid file name that the user entered
****************************************************************************************************/
string getInFileName()
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

/****************************************************************************************************
task:		Get the number of records in the file

data in:	The name of the file

data out:	The number of records in the file
****************************************************************************************************/
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

/****************************************************************************************************
task:		Read the data from the file into an array of structs

data in:	The name of the file and the number of records

data out:	A pointer to the array of structs
****************************************************************************************************/
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

/****************************************************************************************************
task:		Displays the contents from the dynamic array of structures

data in:	The dynamic array of structs and the number of records

data out:	No return value, displays the contents of the array of structs
****************************************************************************************************/
void displayAgentArray(const Agent *agentArr, const int numOfAgents)
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

/****************************************************************************************************
task:		Gets the encryption key from the user

data in:	No parameters, asks the user for the encryption key

data out:	Returns the encryption key
****************************************************************************************************/
int getKey()
{
	int key;
	cout << "Enter the Encryption key:";
	cin >> key;
	
	return key;
}

/****************************************************************************************************
task:		Copys the encrypted contents of the origional dynamic array into a new dynamic array

data in:	The origional dynamic array, the number of records, and the key

data out:	The encrypted dynamic array
****************************************************************************************************/
Agent *copyEncryptArray(Agent *agentArr, const int numOfAgents, const int key)
{
	Agent *encryptArr = new Agent[numOfAgents];
	
	for (int i = 0; i < numOfAgents; i++)
	{
		// Copy
		encryptArr[i] = agentArr[i];
		
		// Encrypt the names
		for (int j = 0; j < strlen(encryptArr[i].name); j++)
		{
			encryptArr[i].name[j] += 14 + key;
		}
		
		// Encrypt the ID numbers
		encryptArr[i].idNum -= 1052 + key;
		
		// Encrypt the years of service
		encryptArr[i].years += ((key * -2.34) / 3.1415);
		
		// Encrypt the location
		for (int j = 0; j < strlen(encryptArr[i].location); j++)
		{
			encryptArr[i].location[j] += 14 + key;
		}
	}
	
	return encryptArr;
}

/****************************************************************************************************
task:		Gets the name of the encrytion file if the user want to create one

data in:	No parameters, asks the user if they want an encrytion file, and if yes, user enters the
			name of the file

data out:	Returns name of the encryption file
****************************************************************************************************/
string getEncryptFile()
{
	string encryptFileName;
	int key;
	char ask;
	cout << "Would you like to create an encryption file?[Y/n]";
	cin >> ask;
		
	bool asking = true;
	while (asking == true)
	{
		if (ask == 'y' || ask == 'Y')
		{
			cout << "Enter the name of the encryption file: ";
			cin >> encryptFileName;
			asking = false;
		}
		else if (ask == 'n' || ask == 'N')
		{
			cout << "Did not create an encryption file. Exiting." << endl;
			asking = false;
		}
		else
		{
			cout << "USAGE: Enter Y or N";
			cin >> ask;
		}
	}
	
	return encryptFileName;
}

/****************************************************************************************************
task:		Writes the contents of the encrypted dynamic array into a file. Tells user if transfer
			was successful and the name of the encryption file

data in:	The encrypted dynamic array and the size of the array

data out:	No return value, creates encrypted file and displays if transfer was successful and the 
			name of the encryption file
****************************************************************************************************/
void writeArrayIntoFile(Agent *encryptArr, const int numOfAgents, const string fileName)
{
	ofstream outFile(fileName, ios::out | ios::binary);
	Agent record;
	
	outFile.write(reinterpret_cast<char *>(&encryptArr[0]), sizeof(record));	
	if (outFile)
	{
		for (int i = 1; i < numOfAgents; i++)
		{		 
			outFile.write(reinterpret_cast<char *>(&encryptArr[i]), sizeof(record));	
		}
		cout << "Transfer was successful." << endl;
	}
	else
	{
		cout << "Transfer was not successful." << endl;
	}
	outFile.close();
}
