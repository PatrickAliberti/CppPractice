#include "List.h"

int main() {
	List log(5);
	
	log.push(1);
	log.push(1);
	log.push(2);
	
	log.remove(1);
	log.remove(1);
	log.remove(2);
		
	log.display();
			
	return 0;
}
