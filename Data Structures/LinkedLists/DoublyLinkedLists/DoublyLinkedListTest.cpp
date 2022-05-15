#include "DoublyLinkedList.h"

#include <iostream>
using namespace std;

int main() {
	DLList log(5);
	
	log.push_back(1);
	log.push_back(2);
	log.push_back(3);
	
	log.delete_front();
	log.delete_back();
	log.remove(2);
	
	cout << log.peekTail();
	
	log.display();
	
	return 0;
}
