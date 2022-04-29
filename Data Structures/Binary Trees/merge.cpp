/**
	Patrick Aliberti
	merge.cpp
	04/13/2022
	
	This is the driver for the binaryTree.h in which two files, data1.txt and
	data2.txt get merged to a binary tree and written to a new file. The
	duplicates get written to an error file and are not included in the merge
	file.
*/
#include "binaryTree.h"

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool merge(std::string, bt&);

int main() {
	bt mergeTree(1000);
	mergeTree.add(23);
	mergeTree.add(100);
	mergeTree.add(75);
	merge("data1.txt", mergeTree);
	//merge("data2.txt", mergeTree);
		
	return 0;
}

/**
	Task:	merges the files from a text file to a binary tree
	Param:	The name of the file and the binary tree to add too
	Return: True if merged
*/
bool merge(std::string fileName, bt& mTree) {
	ifstream inFile;
	ofstream errOutFile;
	ofstream mergeOutFile;
	inFile.open(fileName.c_str());
	if (!inFile) {
		cout << "Could not open the input file. Merge failed." << endl;
		return false;
	}
	
	static int mergeNum;
	mergeNum++;
	
	if (mergeNum > 2) {
		cout << "Can ony merge 2 files." << endl;
		return false;
	}
	
	// Vectors with file data
	int inTemp, numOfNodes = 0;
	vector<int> data, data2;
	while (inFile >> inTemp) {
		data.push_back(inTemp);
		numOfNodes++;
	}	
	inFile.close();
	if (mergeNum == 1) {
		inFile.open("data2.txt");
		while (inFile >> inTemp) {
			data2.push_back(inTemp);
		}
		inFile.close();
	}
	else {
		inFile.open("data1.txt");
		while (inFile >> inTemp) {
			data2.push_back(inTemp);
		}
		inFile.close();
	}
	
	if (numOfNodes < 50) {
		cout << "File is to small. Merge failed." << endl;
		return false;
	}
	
	// If it is the first merge, create new merged and error files, otherwise
	// append the existing files
	if (mergeNum > 1) {
		mergeOutFile.open("merged.txt", ios::app);
		errOutFile.open("error.txt", ios::app);
	}
	else {
		mergeOutFile.open("merged.txt");
		errOutFile.open("error.txt");
	}
	
	// If there are duplicates between the two files, delete them from the
	// vector and put them in the error file
	for (int i2 = 0; i2 < data.size(); i2++) {
		for (int j2 = 0; j2 < data2.size(); j2++) {
			if (data[i2] == data2[j2]) {
				errOutFile << data[i2] << "\n"; 
				data.erase(data.begin() + i2);
				i2--;
			}
		}
	}
	
	// Find the duplicates between a file and the tree, delete duplicates from
	// the tree and add non-duplicates to the tree and merged.txt
	bt copyTree(1000);
	mTree.copy(copyTree);
	int count;
	for (int i = 0; i < data.size(); i++) {
		count = 0;
		for (int j = 0; j < data.size(); j++) {
			if (data[i] == data[j]) {
				count++;
			}
		}
		
		if (mTree.find(data[i])) {
			count++;
			errOutFile << data[i] << "\n";
			mTree.remove(data[i]);
			copyTree.remove(data[i]);
		}
		if (count == 1) {
			if (mTree.isFull()) {
				cout << "The tree is full and has been partially merged." << endl;
				return true;
			}
			
			mergeOutFile << data[i] << "\n";
			mergeOutFile.close();
			mergeOutFile.open("merged.txt", ios::app);
			
			mTree.add(data[i]);
		}
		else {
			errOutFile << data[i] << "\n";
		}
	}
	mergeOutFile.close();
	errOutFile.close();
	
	// Put non-duplicate tree values into merged.txt
	if (mergeNum == 1)
		copyTree.treeToFile("merged.txt");
	
	cout << "Merge complete." << endl;
	return true;
}
