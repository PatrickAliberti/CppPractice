/**
	Patrick Aliberti
	my_queue_test.cpp
	02/09/2022

	This file contains the main function in which the queue is tested and the buy
	and sell actions are performed
*/
#include <iostream>
#include "My_queue.h"
using namespace std;

int main() {
	My_queue queue1(2);
	queue1.buy(10, 1.50);
	queue1.buy(100, 2.00);
	
	cout << "Total selling price: $" << queue1.sell(10) << endl;
	cout << "Queue size after sell: " << queue1.size() << endl;
	
	queue1.display();
	
	return 0;
}
