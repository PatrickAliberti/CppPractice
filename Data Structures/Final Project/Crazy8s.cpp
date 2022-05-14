/**
	Patrick Aliberti
	Crazy8s.cpp
	05/04/2022
	
	This program contains a game of crazy eights using set and stack data
	structures
*/
#include "deckOfCards.h"
#include "set.h"

#include <iostream>
using namespace std;

void crazy8s();
string discard(set&, deckOfCards&, string, char&);
bool checkHand(set&, string, char);
bool checkSuit(char, set&);
bool checkFace(char, set&);

int main () {
	crazy8s();
	
	return 0;
}

/**
	Task:	Create a game of crazy eights between two users
	Param:	None
	Return:	None
*/
void crazy8s() {
	cout << "Directions:\n"
		 << "This is a 2 player game of crazy eights. 7 cards are delt from "
		 << "the deck to each player. One card is taken from the deck and \n"
		 << "turned face up to start the discard pile. During a player's "
		 << "turn they must put a valid card on the dicard pile or draw \n"
		 << "from the deck. A valid card is one that has the same face or "
		 << "suit as the discard pile. Cards with a value of 8 can be \n"
		 << "played whenever and allow the user to nominate a suit for the "
		 << "next move." << endl;
		 
	
	set p1(26);
	set p2(26);
	deckOfCards deck(1);
	
	deck.shuffleDeck();
	
	string discardPile = deck.takeCard();
	char suit = discardPile[1];
	
	for (int i = 0; i < 7; i++) {
		p1.push(deck.takeCard());
		p2.push(deck.takeCard());
	}
	
	cout << endl << "Player 1's hand \n";
	p1.display();
	cout << endl << "Player 2's hand \n";
	p2.display();
	
	while (p1.size() > 0 && p2.size() > 0) {
		cout << endl << "\nDiscard pile: " << discardPile;
		
		cout << endl << "Player 1's turn";
		discardPile = discard(p1, deck, discardPile, suit);
		p1.display();
		
		cout << endl << "Discard pile: " << discardPile;
		
		if (p1.size() == 0) {
			cout << "\n\nPlayer 1 wins!";
			return;
		}
		
		cout << endl << "Player 2's turn";
		discardPile = discard(p2, deck, discardPile, suit);
		p2.display();
	}
		
	if (p2.size() == 0) {
		cout << "\n\nPlayer 2 wins!";
	}
}

/**
	Task:	Prompt user to discard a valid card. If the user has no valid cards,
			a card is drawn from the deck
			
	Param:	A reference to the players hand, a reference to the deck of cards,
			the discard pile value, and a reference to the suit nominated after
			the player plays an 8
	
	Return:	A string holding the discard pile value
*/
string discard(set& hand, deckOfCards& deck, string dPile, char& s) {
	if (!checkHand(hand, dPile, s)) {
		cout << "\nNo cards in your hand can be used. Drawing a card from the "
			 << "deck\n";
		hand.push(deck.takeCard());
		return dPile;
	}
	
	string dCard;
	cout << endl << "Enter the card you would like to discard: ";
	cin >> dCard;
		
	while (!hand.find(dCard)) {
		cout << endl << "Invalid card. Enter a card from your hand: ";
		cin >> dCard;
	}
	
	while (dPile[0] != '8' && dCard[0] != '8'
	&& (dCard[0] != dPile[0] && dCard[1] != dPile[1])) {
		cout << endl << "Invalid card. Enter a card with the same face or "
			 << "suit as the discard pile: ";
		cin >> dCard;
	}
	
	if (dCard[0] == '8') {
		hand.erase(dCard);
		dPile = dCard;
		
		cout << endl << "What suit would you like to nominate? ";
		cin >> s;
		
		while (s != 'C' && s != 'S' && s != 'H' && s != 'D') {
			cout << endl << "Invalid suit. Enter S (Spades), C (Clubs), D "
				 << "(Diamonds), or H (hearts): ";
			cin >> s;
		}
	}
	else if (dPile[0] != '8' && (dCard[0] == dPile[0] || dCard[1] == dPile[1])) {
		hand.erase(dCard);
		dPile = dCard;
	}
	else if (dPile[0] == '8') {
		while (dCard[1] != s) {
			cout << endl << "Wrong suit. Enter a card with suit " << s << ": ";
			cin >> dCard;
		}
		hand.erase(dCard);
		dPile = dCard;
	}
	cout << endl;
	return dPile;
}

/**
	Task:	Check a players hand to see if it has a valid card
	Param:	The player's hand, the discard pile value, and the nominated suit
	Return:	True if there is a valid card, false otherwise
*/
bool checkHand(set& hand, string dPile, char s) {
	if (dPile[0] == '8') {					// Check for the same nominated suit
		if (checkSuit(s, hand))		// if the discard pile is an 8
			return true;
			
		return false;
	}
	
	if (checkSuit(dPile[1], hand))	// Check for same discard pile suit
		return true;
		
	if (checkFace(dPile[0], hand))	// Check for same discard pile face
		return true;
					
	if (checkFace('8', hand))		// Check for 8s
		return true;
		
	return false;
}

/**
	Task:	Check a players hand to see if it has a card with the same suit as
			the arg that is passed through
			
	Param:	The suit and the players hand
	
	Return:	True if there is a card with the same suit, false otherwise
*/
bool checkSuit(char suit, set& hand) {
	string temp = "  ";
	temp[1] = suit;
		
	string s;
	for (int i = 2; i < 10; i++) {
		s = to_string(i);
		temp[0] = s[0];
		
		if (hand.find(temp))
			return true;
	}
	
	temp[0] = 'A';
	if (hand.find(temp))
		return true;
				
	temp[0] = 'T';
	if (hand.find(temp))
		return true;
				
	temp[0] = 'J';
	if (hand.find(temp))
		return true;
				
	temp[0] = 'Q';
	if (hand.find(temp))
		return true;
				
	temp[0] = 'K';
	if (hand.find(temp))
		return true;
		
	return false;
}

/**
	Task:	Check a players hand to see if it has a card with the same face as
			the arg that is passed through
			
	Param:	The face and the players hand
	
	Return:	True if there is a card with the same face, false otherwise
*/
bool checkFace(char face, set& hand) {
	string temp = "  ";
	temp[0] = face;
	temp[1] = 'S';
	
	if (hand.find(temp))
		return true;
					
	temp[1] = 'C';
	if (hand.find(temp))
		return true;
				
	temp[1] = 'D';
	if (hand.find(temp))
		return true;
				
	temp[1] = 'H';
	if (hand.find(temp))
		return true;
		
	return false;
}
