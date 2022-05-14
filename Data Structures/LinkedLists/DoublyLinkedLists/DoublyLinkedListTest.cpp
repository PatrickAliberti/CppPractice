#include "DoublyLinkedList.h"

#include <iostream>
using namespace std;

int main() {
	DLList log(5);
	
	log.insert(1);
	log.insert(2);
	log.insert(3);
	
	log.delete_front();
	log.delete_back();
	
	cout << log.peekTail();
	
	log.display();
}
