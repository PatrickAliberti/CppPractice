/**
	Patrick Aliberti
	goFish.cpp
	02/25/2022
	
	This program contains a game of go fish implemented with sets and a stack
*/
#include <ctime>
#include <iostream>
#include <vector>

#include "my_set.h"
#include "my_stack.h"

int main() {
	srand(time(0));
	My_stack deckOfCards(52);
	std::vector<int> shuffle;
	
	// Create a stack for the deck of cards
	for (int i = 1; i <= deckOfCards.capacity() / 4; i++) {
		for (int i2 = 1; i2 <= 4; i2++) {
			shuffle.push_back(i + (100 * i2));
		}
	}

	// Shuffle the deck of cards
	for (int i = 0; i < deckOfCards.capacity(); i++) {
		int randomElement = rand() % 52;
				
		int temp = shuffle[i];
		shuffle[i] = shuffle[randomElement];
		shuffle[randomElement] = temp;
		
		deckOfCards.push(shuffle[i]);
	}
	
	// Deal out the hands	
	My_set userHand(52);
	My_set computerHand(52);
	while (userHand.size() < 7
	&& computerHand.size() < 7) {
		userHand.insert(deckOfCards.getTop());
		deckOfCards.pop();
		
		computerHand.insert(deckOfCards.getTop());
		computerHand.find(deckOfCards.getTop());
		deckOfCards.pop();
	}
	userHand.display();
	
	// While the game isn't over
	while (deckOfCards.size() != 0 || userHand.size() != 0
	|| computerHand.size() != 0) {
		userHand.removeFourOfAKind();
		computerHand.removeFourOfAKind();
		
		// Prompt user for card
		int card = -1;
		while(userHand.find(card + 100) == nullptr
		&& userHand.find(card + 200) == nullptr
		&& userHand.find(card + 300) == nullptr
		&& userHand.find(card + 400) == nullptr) {
			std::cout << "\n\n'Do you have any __'s?' [Enter card value here] ";
			std::cin >> card;
		}
		
		// If computer doesnt have card, go fish, otherwise give the cards to
		// the user
		if (computerHand.find(card + 100) == nullptr
		&& computerHand.find(card + 200) == nullptr
		&& computerHand.find(card + 300) == nullptr
		&& computerHand.find(card + 400) == nullptr) {
			std::cout << "\nGo fish!\n\n";
			userHand.insert(deckOfCards.getTop());
			deckOfCards.pop();
		}
		else {
			std::cout << "\nGood choice! Computer gives you their " << card
					  << "'s\n\n";
					  
			for (int i = 100; i <= 400; i += 100) {
				if (computerHand.erase(card + i))
					userHand.insert(card + i);
			}
		}
		userHand.removeFourOfAKind();
		userHand.display();
		
		// Computer's turn
		std::cout << "Computer's turn\n\n";
		
		int card2 = -1;
		while (computerHand.find(card2 + 100) == nullptr
		&& computerHand.find(card2 + 200) == nullptr
		&& computerHand.find(card2 + 300) == nullptr
		&& computerHand.find(card2 + 400) == nullptr) {
			card2 = (rand() % 13) + 1;
		}
		if (userHand.find(card2 + 100) == nullptr
		&& userHand.find(card2 + 200) == nullptr
		&& userHand.find(card2 + 300) == nullptr
		&& userHand.find(card2 + 400) == nullptr) {
			std::cout << "Computer goes fishing\n\n";
			computerHand.insert(deckOfCards.getTop());
			deckOfCards.pop();
		}
		else {
			std::cout << "Computer takes your " << card2 << "'s\n\n";
			for (int i = 100; i <= 400; i += 100) {
				if (userHand.erase(card2 + i)) 
					computerHand.insert(card2 + i);
			}
			userHand.display();
		}
		computerHand.removeFourOfAKind();
	}
	
	// Declare player with most four of a kinds as the winner
	if (userHand.getNumOfFourOfAKinds() > computerHand.getNumOfFourOfAKinds()) {
		std::cout << "You Win!";
	}
	else {
		std::cout << "Computer Wins!";
	}
	std::cout << std::endl;
	
	return 0;
}
