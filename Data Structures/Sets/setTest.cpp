#include "my_set.h"

#include <iostream>
using namespace std;

int main() {
	My_set set1(5);
	set1.insert(1);
	
	set1.display();
	
	set1.erase(1);

	
	set1.display();
	
	return 0;
}
