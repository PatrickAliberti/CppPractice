#include "my_set.h"

#include <iostream>
using namespace std;

int main() {
	My_set set1(5);
	
	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	set1.insert(4);
	set1.insert(5);
	set1.insert(6);
	
	set1.display();
	
	set1.clear();

	
	set1.display();
	
	return 0;
}
