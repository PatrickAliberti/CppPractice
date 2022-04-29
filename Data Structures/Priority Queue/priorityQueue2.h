#include <iostream>
#include <vector>
using namespace std;

struct data {
	string name;
};

struct node {
	int priority;
	int time;
	node* next;
	data d;
};

class pq {
private:
	node* in;
	node* out;
	int qty;
	int max;
	
public:
	pq();
	pq(int);
	~pq();
	
	int size();
	int capacity();
	bool add(int, int, data);
	bool pop(data&);
	bool clear();
	bool priority_update(int, int);
	bool del(string&);
	bool isFull();
	bool isEmpty();
	void display();
	void displayMedTriage();
};

pq::pq(int m) {
	qty = 0;
	max = m;
	in = out = nullptr;
}

pq::~pq() {
	clear();
}

int pq::size() { return qty; }
int pq::capacity() { return max; }

bool pq::add(int p, int t, data _d) {
	if (isFull())
		return false;
	
	node* q;
	node* temp = new node;
	temp->priority = p;
	temp->time = t;
	temp->d = _d;
	qty++;
	
	if (isEmpty()) {
		temp->next = nullptr;
		in = out = temp;
		return true;
	}
	
	if (out->priority < p) {
		in->next = temp;
		temp->next = nullptr;
		in = temp;
		
		// qty++;
		return true;
	}
	else {
		temp->next = out;
		out = temp;
		
		// qty++;
		return true;
	}
	
	
}

bool pq::pop(data& _d) {
	if (isEmpty())
		return false;
		
	node* temp = out;
	_d = out->d;
	out = out->next;
	delete temp;
	
	if (temp == in)		// out == nullptr
		in = out;
			
	qty--;
	return true;
}

bool pq::clear() {
	for (node* scan = out; scan != nullptr; scan = scan->next) {
		pop(scan->d);
	}
}

bool pq::priority_update(int now, int push_factor) {
	for (node* scan = out; scan != nullptr; scan = scan->next) {
		if (now - scan->time >= push_factor) {
			scan->priority++;
			scan->time += push_factor;
		}
	}
	
	return true;
}

bool pq::del(string& val) {
	for (node* scan = out; scan->next != nullptr; scan = scan->next) {
		if(scan->next->d.name == val) {
			node* temp = scan->next;
			scan->next = temp->next;
			qty--;
			if (scan->next == nullptr) {
				in = scan;
			}
			delete temp;
			return true;
		}
	}
	return false;
}

void pq::display() {
	for (node* scan = out; scan != nullptr; scan = scan->next) {
		cout << endl << scan->priority << "   "
					 << scan->time << "   "
					 << scan->d.name;
	}
}

void pq::displayMedTriage() {
	vector<string> critical;
	vector<string> serious;
	vector<string> moderate;
	vector<string> low;
	
	for (node* scan = out; scan != nullptr; scan = scan->next) {
		if (scan->priority == 1)
			critical.push_back(scan->d.name);
		else if (scan->priority == 2)
			serious.push_back(scan->d.name);
		else if (scan->priority == 3)
			moderate.push_back(scan->d.name);
		else
			low.push_back(scan->d.name);
	}
	
	cout << "\n\nCritical (Wait - 1 min)\n-------------------------\n";
	for (int i = 0; i < critical.size(); i++) {
		cout << critical[i] << "\n";
	}
	
	cout << "\n\nSerious (Wait - 8 min)\n-------------------------\n";
	for (int i = 0; i < serious.size(); i++) {
		cout << serious[i] << "\n";
	}
	
	cout << "\n\nModerate (Wait - 16 min)\n-------------------------\n";
	for (int i = 0; i < moderate.size(); i++) {
		cout << moderate[i] << "\n";
	}
	
	cout << "\n\nLow Priority (Wait - 32 min)\n-------------------------\n";
	for (int i = 0; i < low.size(); i++) {
		cout << low[i] << "\n";
	}
}

bool pq::isEmpty() {
	if (in == nullptr && out == nullptr)
		return true;
		
	return false;
}

bool pq::isFull() {
	if (qty == max)
		return true;
	
	return false;
}
