/**
	Patrick Aliberti
	binaryTree.h
	04/13/2022
	
	This file contains the binary search tree class and the node struct
*/
#include <fstream>
#include <iostream>
using namespace std;

struct node {
	node* left = nullptr;
	node* right = nullptr;
	int val;
};

class bt {
private:
	node* tt;
	int qty;
	int max;
	
	bool p_add(node*&, int&);
	bool p_remove(node*&, int&);
	bool p_clear(node*&);
	void p_displayLVR(node*);
	bool p_find(node*, int&);
	bool p_copy(bt&, node*);
	void p_treeToFile(node*, string);
	node* findMin(node*);
	
public:
	bt(); 
	bt(int);
	~bt();
	
	int size();
	int capacity();
	
	bool isEmpty();
	bool isFull();
	bool add(int);
	bool remove(int);
	bool clear();
	bool find(int);
	bool copy(bt&);
	void treeToFile(string);
	void displayLVR();
};
 
// Constructor
bt::bt(int m) {
	max = m;
	qty = 0;
	tt = nullptr;
}

// Destructor
bt::~bt() { clear(); }

// Accessors
int bt::size() { return qty; }
int bt::capacity() { return max; }

// Check if the binary tree is empty
bool bt::isEmpty() {
	if (qty == 0)
		return true;
	
	return false;
}

// Check if the binary tree is full
bool bt::isFull() {
	if (qty == max)
		return true;
		
	return false;
}

// Wrapper functions called by user
bool bt::add(int v) { return p_add(tt, v); }
bool bt::remove(int v) { return p_remove(tt, v); }
bool bt::clear() { return p_clear(tt); }
bool bt::find(int v) { return p_find(tt, v); }
bool bt::copy(bt& copyTree) { return p_copy(copyTree, tt); }
void bt::treeToFile(string fileName) { return p_treeToFile(tt, fileName); }
void bt::displayLVR() { return p_displayLVR(tt); }


// Private functions called by wrappers
/**
	Task:	Adds a node to the tree
	
	Param:	Takes in the "root" node and the value to add
	
	Return:	True if it is added, otherwise false. It does not get added if the
			tree is full or if it is a duplicate.
*/
bool bt::p_add(node*& curve, int& v) {
	if (isFull())
		return false;
		
	else if (curve == nullptr) {
		curve = new node;
		curve->val = v;
		qty++;
		return true;
	}
	else if (v < curve->val) {
		if (curve->left == nullptr) {
			curve->left = new node;
			curve->left->left = curve->left->right = nullptr;
			curve->left->val = v;
			qty++;
			return true;
		}
		else
			return p_add(curve->left, v);
	}
	else if (v > curve->val) {
		if (curve->right == nullptr) {
			curve->right = new node;
			curve->right->left = curve->right->right = nullptr;
			curve->right->val = v;
			qty++;
			return true;
		}
		else
			return p_add(curve->right, v);
	}
	else
		return false;
}

/**
	Task:	Remove a node from the tree
	
	Param:	The root node and the value to remove
		
	Return:	True if it is removed, false otherwise. 
*/
bool bt::p_remove(node*& curve, int& v) {
	if (curve == nullptr)
		return false;
		
	else if(v < curve->val)
		p_remove(curve->left, v);
		
	else if (v > curve->val)
		p_remove(curve->right, v);
		
	else {
		// Leaf node
		if (curve->left == nullptr && curve->right == nullptr) {
			delete curve;
			curve = nullptr;
			qty--;
			return true;
		}
		// Right child
		else if (curve->left == nullptr) {
			curve = curve->right;
			qty--;
			return true;
		}
		// Left child
		else if (curve->right == nullptr) {
			curve = curve->left;
			qty--;
			return true;
		}
		// Left and right children
		else {
			node* min = curve->right;
			curve->val = min->val;
			while (min->left != nullptr)
				min = min->left;
				
			p_remove(curve->right, min->val);
		}
	}
}

/**
	Task:	Clear the tree
	
	Param:	The root node
		
	Return:	True if it gets cleared, false otherwise
*/
bool bt::p_clear(node*& curve) {
	if (curve == nullptr)
		return true;
		
	p_clear(curve->left);
	p_clear(curve->right);
	
	delete curve;
	curve = nullptr;
	qty--;
	
	if (qty == 0)
		return true;
		
	else
		return false;
}

/**
	Task:	Check if a value is in the tree
	
	Param:	The root node and the value to check
		
	Return:	True if it is found, false otherwise
*/
bool bt::p_find(node* curve, int& v) {
	if (curve == nullptr)
		return false;
	
	else if (v == curve->val)
		return true;
		
	else if (v < curve->val)
		return p_find(curve->left, v);
		
	else if (v > curve->val)
		return p_find(curve->right, v);
}

/**
	Task:	Add the values from one tree to another
	
	Param:	The tree to add to anf the root node
		
	Return:	False if curve is null, otherwise it recurses to the nex node
*/
bool bt::p_copy(bt& copyTree, node* curve) {
	if (curve == nullptr)
		return false;
		
	p_copy(copyTree, curve->left);
	copyTree.add(curve->val);
	p_copy(copyTree, curve->right);
}

/**
	Task:	Writes the data from a tree to a file
	
	Param:	The root node and the name of the file.
		
	Return:	Nothing
*/
void bt::p_treeToFile(node* curve, string fileName) {
	if (curve == nullptr)
		return;
		
	ofstream outFile;
	outFile.open(fileName.c_str(), ios::app);
		
	p_treeToFile(curve->left, fileName);
	outFile << curve->val << "\n";
	p_treeToFile(curve->right, fileName);
}

/**
	Task:	Find the minimum node given the root node
	
	Param:	The root node
	
	Return:	The minimum node
*/
node* bt::findMin(node* curve) {
	while (curve->left != nullptr)
		curve = curve->left;
		
	return curve;
}

/**
	Task:	Displays the contents of the tree
	
	Param:	The root node
		
	Return:	Nothing
*/
void bt::p_displayLVR(node* curve) {
	if (curve == nullptr)
		return;
		
	p_displayLVR(curve->left);
	cout << curve->val << "   ";
	p_displayLVR(curve->right);
}
