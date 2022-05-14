#include <iostream>
#include <time.h>
using namespace std;

struct card {
	char suit;
	char face;
	card* next;
};

class deckOfCards {
private:
	card* topCard;
	int numOfDecks;
	
	void loadDeck();
	void deleteDeck();
	
public:
	deckOfCards(int);
	~deckOfCards();
	string takeCard();
	bool shuffleDeck();
	void displayDeck();		// function only used for testing purposes
};

// Constructor
deckOfCards::deckOfCards(int num_of_decks) {
	topCard = nullptr;	
	if (num_of_decks <= 0)
		numOfDecks = 1;
			
	else
		numOfDecks = num_of_decks;
		
	loadDeck();
}

// Destructor
deckOfCards::~deckOfCards() { deleteDeck(); }

void deckOfCards::loadDeck() {
	char s, c;
	card* temp;
	for (int deck = 0; deck < numOfDecks; deck++) {
		for (int suits = 0; suits < 4; suits++) {
			for (int cards = 1; cards < 14; cards++) {
				temp = new card;
				switch (suits) {
					case 0:	s = 'D';
							break;
					
					case 1:	s = 'H';
							break;
							
					case 2:	s = 'S';
							break;
							
					case 3:	s = 'C';
							break;
				}
				temp->suit = s;
				
				switch (cards) {
					case 1:  c = 'A';
							 break;
							
					case 11: c = 'J';
							 break;
							 
					case 12: c = 'Q';
							 break;
							 
					case 13: c = 'K';
							 break;
					
					default: c = cards + 48;
				}
				temp->face = c;
				temp->next = topCard;
				topCard = temp;
			}
		}
	}
}

void deckOfCards::deleteDeck() {
	for (card* temp = topCard; topCard != nullptr; temp = topCard) {
		topCard = temp->next;
		delete temp;
	}
}

bool deckOfCards::shuffleDeck() {
	deleteDeck();		// Ensures there is enough cards
	loadDeck();
	
	srand(time(0));
	int numOfCards = numOfDecks * 52;
	int cardToFind;
	card *scan, *back, *tempTopCard = nullptr;
	for (int times = rand() % 10 + 1; times > 0; times--) {
		while (topCard != nullptr) {
			cardToFind = rand() % numOfCards + 1;
			numOfCards--;
			for (card *scan = topCard; cardToFind != 1; cardToFind--) {
				back = scan;
				scan = scan->next;
			}
			
			if (scan == topCard)
				topCard = scan->next;
				
			else
				back->next = scan->next;
				
			scan->next = tempTopCard;
			return true;
		}
		topCard = tempTopCard;
		return true;	
	}
}

string deckOfCards::takeCard() {
	string str = "   ";
	card *temp;
	if (topCard == nullptr)
		str = "";
	
	str[0] = topCard->face;
	str[1] = topCard->suit;
	str[2] = '\n';
	
	temp = topCard;
	topCard = temp->next;
	delete temp;
	return str;
}

void deckOfCards::displayDeck() {
	for (card *scan = topCard; scan != nullptr; scan = scan->next)
		cout << scan->face << " " << scan->suit << endl;
		
	cout << endl;
}
