#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct HandNode{
string val;
HandNode *next;
};

class hand{
	private: 
	int qty;
	int max;
	HandNode *start;
	
	
	public:
		hand(int);
		~hand();
		bool add(string);
		bool remove(string);
		bool isfull();
		void display();
		int getSize();
		bool isEmpty();
		int getTotal();
		bool convertFace();
		bool makeEmpty();
		bool checkBust(int);
		bool find(string);
		string getStart();
		bool winStatus(int, int);
		void helpAce();
		
};

hand::hand(int m){
	max =m;
	start = NULL;
	qty = 0;
}
hand::~hand(){
	makeEmpty();
}

bool hand::isEmpty(){
	if(qty ==0){
		return true;
	}
	return false;
}
bool hand::isfull(){
	if(qty == max){
		cout << "full";
		return true;
	}
	return false;
}
bool hand::makeEmpty(){
	HandNode *temp = start;
	while(start!=NULL){
	start=start->next;
	delete temp;
	temp=start;	
	}
	qty=0;
	return true;
}
bool hand::add(string v){
	if(isfull())
		return false;
	
	HandNode *temp = new HandNode;
	temp->val = v;
	temp->next=start;
	start = temp;
	qty++;
	return true;
}

void hand::display(){
	HandNode *s = start;
	while(s!=NULL){
		cout << s->val << " " ;
		s=s->next;
	}
}
int hand::getTotal(){
	HandNode *s = start;
	int num =0;
	int total =0;
	int aceNum =0;
	while(s!=NULL){
		
				
		if(s->val=="K"|| s->val == "Q"|| s->val == "J"|| s->val=="T")	{//fixed T for ten that didnt work i think keep eye on
			total += 10;
			
		}
		if(s->val== "A"){
			aceNum++;
			total +=11;///////////////////////////////handle Ace scenario when checking if bust then sub 10 if bust and have ace from find fucntion in list class
			
		}
		if(aceNum >= 2){
			total -=10;
		}
		else{
		
			stringstream obj;
			obj <<s->val;
			obj>> num;
			total += num;
		}
		s=s->next;
	
	}//while
	return total;
}
bool hand::checkBust(int num){
	
	if(num > 21){
		
		return true;
	}//if Bust statement
	if(num<21){
	
		return false;
	}
	else{
	
		return false;
	}
}
bool hand::find(string v){
	for(HandNode *scan =start; scan!=NULL;scan=scan->next){
		if(scan->val==v){
			return true;
		}
		return false;
	}//for
	
}//find
string hand::getStart(){
	
	string str = start->val;
		
	return str;
}
bool hand::winStatus(int playerNum, int deal){
	
	if(playerNum > deal && playerNum <= 21){//winning condition    && playerNum <= 21
	
		return true;}
	
	if(playerNum< deal && deal <=21){
		return false ;
	}
	else {
		if(playerNum == deal){
		
			cout << "Tied"<<endl;
		}
	}
	
}//winStatus
