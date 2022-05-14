/*
Program: deckOfCards.h
Author: Branden Favre
Assignment: Final Project
Due Date: 5/4/22
*/

#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

struct card
{
	char suit;
	char face;
	card * next;
};

class deckOfCards
{
	private:
		card * topCard;
		int numOfDecks;
		void loadDeck();
		void deleteDeck();
	public:
		int size();
		int capacity();
		deckOfCards(int = 0);
		~deckOfCards() {deleteDeck();}
		string takeCard();
		bool shuffleDeck();
		void displayDeck(); //testing purposes
};

int deckOfCards::capacity() { return numOfDecks * 52; }

/******************************************************************************
Overloaded constructor takes in number_of_decks. Sets topCard to NULL, checks
if number_of_decks is less than or equal to 0, setting numOfDecks to 1, else
numOfDecks equals number_of_decks. Calls loadDeck()
******************************************************************************/
deckOfCards::deckOfCards(int number_of_decks)
{
	topCard = NULL;
	if(number_of_decks <= 0)
		numOfDecks = 1;
	else
		numOfDecks = number_of_decks;
	loadDeck();
}
/******************************************************************************
loadDeck loops through 52 times, loading the stack with cards representing one
of each suit. Suits represented with D, H, S and C. 1, 10, 11, 12, and 13 are
represented with A, T, J, Q, K respectively. 
******************************************************************************/
void deckOfCards::loadDeck()
{
	char s, c;
	int count = 0;
	card * temp;
	
	for(int decks = 0; decks < numOfDecks; decks++)
		for(int suits = 0; suits < 4; suits++)
			for(int cards = 1; cards < 14; cards++)
			{
				temp = new card;
				switch(suits)
				{
					case 0: s = 'D'; //Diamonds
							break;
					case 1: s = 'H'; //Hearts
							break;
					case 2: s = 'S'; //Spades
							break;
					case 3: s = 'C'; //Clubs
							break;
				}
				temp -> suit = s;
				switch(cards)
				{
					case 1: temp -> face = 'A'; //Ace
							break;
					case 10: temp -> face = 'T'; //Ten
							break;
					case 11: temp -> face = 'J'; //Jack
							break;
					case 12: temp -> face = 'Q'; //Queen
							break;
					case 13: temp -> face = 'K'; //King
							break;
					default: temp -> face = cards + 48;
				}
				temp -> next = topCard;
				topCard = temp;
			}
}
/******************************************************************************
deleteDeck goes through the stack and deletes the topCard.
******************************************************************************/
void deckOfCards::deleteDeck()
{
	for(card * temp = topCard; topCard != NULL; temp = topCard)
	{
		topCard = temp -> next;
		delete temp;
	}
}
/******************************************************************************
shuffleDeck uses srand to randomize the deck.
******************************************************************************/
bool deckOfCards::shuffleDeck()
{
	srand(time(0));
	int numOfCards = numOfDecks * 52;
	int cardToFind;
	card * scan;
	card * back = NULL;
	card * tempTopCard = NULL;
	
	for(int times = rand()%10+1; times > 0; times--)
		while(topCard != NULL)
		{
			cardToFind = rand()%numOfCards + 1;
			numOfCards--;
			for(scan = topCard; cardToFind != 1; cardToFind--)
			{
				back = scan;
				scan = scan -> next;
			}
			if(scan == topCard)
				topCard = scan -> next;
			else
				back -> next = scan -> next;
			scan -> next = tempTopCard;
			tempTopCard = scan;
		}
		
	topCard = tempTopCard;
	
	return true;
}
/******************************************************************************
takeCard puts the topCard into str and then removes topCard. Returns str.
******************************************************************************/
string deckOfCards::takeCard()
{
	if (topCard == NULL) 
		return "";
	
	string str = "   "; //size 3 string
	card * temp;
	
	if(topCard == NULL)
		str = "";
		
	str[0] = topCard -> face;
	str[1] = topCard -> suit;
	str[2] = '\n';
	
	temp = topCard;
	topCard = temp -> next;
	delete temp;
	
	return str;
}
/******************************************************************************
displayDeck loops through the stack and outputs the top card.
******************************************************************************/
void deckOfCards::displayDeck()
{
	card * temp = topCard;
	
	for(card * scan = temp; temp != NULL; scan = temp)
	{
		cout << scan -> face << scan -> suit << endl;
		temp = scan -> next;
	}
	
	delete temp;
}
