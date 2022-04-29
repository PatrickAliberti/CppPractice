#include "LinkedList.h"
#include <iostream>
using namespace std;

struct node1 {
	int val;
	node1* next;
};

int main() {
	My_list list1(5);
	
	//cout << list1.size() << "\n";
	node1* test;
	list1.add(3, nullptr);
	
	list1.find(3);
	
//	cout << list1.size() << "\n";
	
	
	return 0;
}
