#include "ListTemplate.h"

int main() {
	List<double> log(5);
	
	log.push(1);
	log.push(2);
	log.insert(3);
	
	
	
	log.display();
	
	log.remove(3);
	log.remove(2);
	log.remove(1);
	
	cout << "----\n";
	log.display();
	
	return 0;
}
