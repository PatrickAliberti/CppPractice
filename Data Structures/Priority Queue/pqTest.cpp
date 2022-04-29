/**
	Patrick Aliberti
	pqTest.cpp
	04/20/2022
	
	This program creates a medical triage where the user can enter new tasks
	with a priority and complete, or remove, tasks from the medical triage.
	
	The medical triage can also be automated to demonstrate how it works.
*/
#include "priorityQueue.h"

#include <iostream>
using namespace std;

void automate();

bool createTask(string, int, pq&);
bool completeTask(string, pq&);

int main() {
	char ask;
	cout << "Would you like to see an example of how a medical triage works?"
		 << " [Y/N]";
	cin >> ask;
	if (ask == 'Y' || ask == 'y') {
		automate();
		return 0;
	}
	
	data data1;
	
	pq medTriage(100);
	medTriage.add(0, 0, data1);
		
	char quit = 'x';
	while (quit != 'q' || quit != 'Q') {
		cout << "\nWould you like to add a task [enter A], remove a task"
			 << "[enter R], or quit [enter Q]?\n";
		cin >> quit;
		
		if (quit == 'q' || quit == 'Q')
			return 0;
			
		else if (quit == 'A' || quit == 'a') {
			string task;
			int priority;
			cout << "\nEnter the task: ";
			cin >> task;
			cout << "\nEnter the priority: ";
			cin >> priority;
			
			createTask(task, priority, medTriage);
		}
		else if (quit == 'R' || quit == 'r') {
			string task;
			cout << "\nEnter the task: ";
			cin >> task;
			
			completeTask(task, medTriage);
		}
		else
			cout << "\nNot a valid response.";
			
		if (medTriage.size() == medTriage.capacity()) {
			cout << "\nMax number of tasks reached.";
			return 0;
		}
	}
	
	return 0;
}

/**
	Task:	Add a new task to the medical triage
	Param:	a string describing the task, the priority number, and the pq object
	Return:	True if task was created, false otherwise
*/
bool createTask(string task, int p, pq& mTriage) {
	if (p > 4 || p < 1) {
		cout << "\nPriority number has to be between 1 and 5. Task cancelled.";
		return false;
	}
	
	data data1;
	data1.name = task;
	int time = p * p * p;
	
	mTriage.add(p, time, data1);
	mTriage.displayMedTriage();
	return true;
}

/**
	Task:	Remove a task to the medical triage
	Param:	the string describing the task and the pq object
	Return:	True if task was removed, false otherwise
*/
bool completeTask(string task, pq& mTriage) {
	if (mTriage.del(task)) {
		cout << "\n" << task << " completed.";
		mTriage.displayMedTriage();
		return true;
	}
	cout << "\nTask is not on list.";
	return false;
}

/**
	Task:	Demonstrate how a medical triage works
	Param:	None
	Return: None
*/
void automate() {
	data data0, data1, data2, data3, data4;
	data1.name = "Heart attack";
	data2.name = "Car accident";
	data3.name = "Infection";
	data4.name = "Small cut";
	
	pq medTriage(100);
	medTriage.add(0, 0, data0);
	medTriage.add(1, 1, data1);
	medTriage.add(1, 1, data2);
	medTriage.add(3, 27, data3);
	medTriage.add(4, 64, data4);
	
	medTriage.displayMedTriage();
	cout << endl;
	
	cout << "\nRemoving the task with the next highest priority: "
		 << data1.name << "\n";
	medTriage.del(data1.name);
	medTriage.displayMedTriage();
	
	cout << "\nRemoving the task with the next highest priority: "
		 << data2.name << "\n";
	medTriage.del(data2.name);
	medTriage.displayMedTriage();
	
	cout << "\nRemoving the task with the next highest priority: "
		 << data3.name << "\n";
	medTriage.del(data3.name);
	medTriage.displayMedTriage();
	
	cout << "\nRemoving the task with the next highest priority: "
		 << data4.name << "\n";
	medTriage.del(data4.name);
	medTriage.displayMedTriage();
		 
	return;
}
