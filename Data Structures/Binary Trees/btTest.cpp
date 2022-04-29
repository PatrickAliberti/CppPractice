#include "binaryTree.h"

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool merge(std::string, bt&);

int main() {
	bt mergeTree(100);
	merge("data1.txt", mergeTree);
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
	ifstream mergeInFile;
	inFile.open(fileName.c_str());
	if (!inFile) {
		cout << "Could not open the input file. Merge failed." << endl;
		return false;
	}
	
	int inTemp, inTemp2, count = 0;
	while (inFile >> inTemp)
		count++;
		
	inFile.close();
	if (count >= 50) {
		cout << "File is to big. Merge failed." << endl;
		return false;
	}
	
	mergeOutFile.open("merged.txt");
	mergeInFile.open("merged.txt");
	errOutFile.open("error.txt");
	inFile.open(fileName.c_str());
	
	while (inFile >> inTemp) {
		// If binary tree is full, merge as much as possible
		if (mTree.isFull()) {
			cout << "Binary tree is full. Partially merged." << endl;
			return true;
		}
		// If it is not a duplicate, add it to merge.txt
		else if (mTree.add(inTemp)) {
			mergeOutFile << inTemp << "\n";
			mergeOutFile.close();
			mergeOutFile.open("merged.txt", ios::app);
		}
			
		// If it is a duplicate, delete it from the tree and from merge.txt and
		// add it to error.txt
		else {
			// Remove duplicate from merge.txt contents by putting data in a
			// vector, deleting the value from the vector, then replacing the
			// data from merge.txt with the values from the vector
			/*
			vector<int> tempMerge;
			
			mergeInFile.close();
			mergeInFile.open("merged.txt");
		
			while (mergeInFile >> inTemp2) {
				tempMerge.push_back(inTemp2);
			}
			for(int i = 0; i < tempMerge.size(); i++) {
				if (tempMerge[i] == inTemp){
					tempMerge.erase(tempMerge.begin() + i);
				}
			}
			cout << "\n";
			for (int i = 0; i < tempMerge.size(); i++) {
				mergeOutFile << tempMerge[i] << "\n";
			}
			*/

			errOutFile << inTemp << "\n" << inTemp << "\n";
			mTree.remove(inTemp);
		}
	}
	inFile.close();
	mergeOutFile.close();
	mergeInFile.close();
	errOutFile.close();
	cout << "Merge complete." << endl;
	return true;
}
