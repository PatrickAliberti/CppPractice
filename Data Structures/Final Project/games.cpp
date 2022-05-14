/**
	Branden Favre
	Corey Scarfone
	Patrick Aliberti
	Trevor DeRis
	
	games.cpp
	05/04/2022
	
	This program utilizes set, stack, and queue data structures to create a
	menu of different games including blackjack, crazy eights, go boom, and war
*/
#include "deckOfCards.h"
#include "hand.h"
#include "set.h"
#include "deckQueue.h"

#include <iostream>
#include <cctype>
using namespace std;

// Blackjack
void blackJack();

// Crazy 8s
void crazy8s();
string discard(set&, deckOfCards&, string, char&);
bool checkHand(set&, string, char);
bool checkSuit(char, set&);
bool checkFace(char, set&);

// War
void warGame();
int getRank(char, char []);
void pushWarCards(deckQueue &, deckQueue &);

// Go Boom
void goBoom();
bool gbTurn(set &_p, string &_inPlay);
bool gbPlayable(const string _toPlay, const string _inPlay);

int main() {
	goBoom();
	
	return 0;
}

void blackJack(){
	cout << "Two player Black Jack game vs dealer"<<endl;
	deckOfCards deck(6);
	deck.shuffleDeck();
	deck.shuffleDeck();

	hand* player1 = new hand(5);
	hand* player2 = new hand(5);
	hand* dealer = new hand(5);

	dealer->add(deck.takeCard());
	cout << "Dealers hand: ";
	dealer->display();//display just one of dealers cards
	cout <<" ?"<<endl;

	dealer->add(deck.takeCard());
	cout << endl;

	bool player1Resolved = false;
	bool player2Resolved = false;

	player1->add(deck.takeCard());
	player1->add(deck.takeCard());
	player2->add(deck.takeCard());
	player2->add(deck.takeCard());

	cout << "Player One's hand:";
	player1->display();
	cout <<endl;
	
	cout << "Player Two's hand:";
	player2->display();
	cout << endl;
	cout <<endl;

	cout << "Player One's hand total:"<<player1->getTotal()<<endl;	
	if(	player1->checkBust(player1->getTotal()) ==false){

	do{
		cout << "Player one what would you like to do?" <<endl;
		cout << "1. Hit"<<endl;
		cout << "2. Stay"<<endl;
		
		int ch;
		cin >> ch;
		switch(ch){
			case 1:
				player1->add(deck.takeCard());
				cout<< "Player one Drew a " << player1->getStart()<< " "<<endl;
				cout << " Your total is now "<<player1->getTotal()<<endl;

				if(player1->checkBust(player1->getTotal())== true)
					player1Resolved = true;

				break;//hit

			case 2:
				cout << "stay";
				cout << " total is " << player1->getTotal() << endl;
				player1Resolved = true;
				break;//stay	
		}//switch
	}while(player1Resolved == false );
}//if


	/////////////////////////////////////////////////////Player 2

	cout << endl<< "Player twos total is: " <<player2->getTotal()<< " "<<endl;
	if(	player2->checkBust(player2->getTotal()) ==false){
	do{
		cout << "Player Two what would you like to do?" <<endl;
		cout << "1. Hit"<<endl;
		cout << "2. Stay"<<endl;

		int ch;
		cin >> ch;
		switch(ch){
			case 1:
				player2->add(deck.takeCard());
				
				cout<< "Player Two Drew a " << player2->getStart()<< " "<<endl;
				cout << "Your total is now "<<player2->getTotal()<<endl;

				if(player2->checkBust(player2->getTotal())== true)
					player2Resolved = true;
					
				break;//hit

			case 2:
				cout << "stay";
				cout << " total is " << player2->getTotal() << endl;

				player2Resolved = true;

				break;//stay
		}//switch
	}while(player2Resolved == false );
}//if

	
	//////////////////////////////Dealer hand

	while(dealer->getTotal()<16){
		dealer->add(deck.takeCard());
		cout << "Dealer Drew a : " << dealer->getStart() << endl;
	}
	cout << "dealer total:"<< dealer->getTotal()<<endl;


	///////////////////////////////// Comparison

	cout << endl <<"Player 1:";
	
	if(player1->checkBust(player1->getTotal())){
		cout << " Bust"<<endl;
	}//player 1 bust

	else{

	if(player1->winStatus(player1->getTotal(),dealer->getTotal())){
		cout << "Won "<<endl;
	}//player 1 win

	else{
		if(dealer->checkBust(dealer->getTotal())){
			cout <<"Won"<<endl;
		}

		else{
			if(player1->getTotal()!=dealer->getTotal())
				cout << "Lost "<<endl;
		}
	}
}//player 1 win or lose///////////////////////////////////////////

	cout << "Player 2:";

	if(player2->checkBust(player2->getTotal())){
		cout << " Bust"<<endl;
	}//player 1 bust

	else{

	if(player1->winStatus(player2->getTotal(),dealer->getTotal())){
		cout << "Won "<<endl;
	}//player 2 win

	else{
		if(dealer->checkBust(dealer->getTotal())){
			cout <<"Won"<<endl;
		}

		else{
				if(player2->getTotal() != dealer->getTotal())
				cout << "Lost"<<endl;
		}
	}
}//player 2 win or lose

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
	
	return;
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
			
		else
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
	for (int i = 2; i < 9; i++) {
		s = to_string(i);
		s.c_str();
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

void warGame()
{
	deckOfCards deck(1);
	deckQueue player1(52);
	deckQueue player2(52);
	deckQueue warCards(52);
	
	char ranks[13] = 
	{'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	
	int flag = 0;
	char c1, c2;
	int ic1, ic2;
	
	deck.shuffleDeck();
	
	for(int i = 0; i < 26; i++)
	{
		string card = deck.takeCard();
		player1.push(card[0]);
		card = deck.takeCard();
		player2.push(card[0]);
	}
	
	while(flag == 0)
	{		
		player1.pop(c1);
		ic1 = getRank(c1, ranks);
		player2.pop(c2);
		ic2 = getRank(c2, ranks);
		cout << "Player 1's card: " << c1
		     << "\nPlayer 2's card: " << c2 << endl;
		
		if(ic1 > ic2) //Player 1 wins
		{
			cout << "Player 1's card is higher!\n";
			player1.push(c1);
			player1.push(c2);
		}
		else if(ic2 > ic1) //Player 2 wins
		{
			cout << "Player 2's card is higher!\n";
			player2.push(c2);
			player2.push(c1);
		}
		else if(ic1 == ic2) //War starts
		{
			warCards.push(c1);
			warCards.push(c2);
			while(ic1 == ic2)
			{
				cout << "\nWAR!!!\n";
				for(int i = 0; i < 2; i++)
				{
					if(player1.isEmpty() && player2.isEmpty())
					{
						cout << "Both players ran out of cards during war.\n";
						flag = 3;
						break;
					}
					if(player1.isEmpty())
					{
						pushWarCards(player2, warCards);
						cout << "Player 1 ran out of cards during war.\n";
						flag = 2;
						break;
					}
					if(player2.isEmpty())
					{
						pushWarCards(player1, warCards);
						cout << "Player 2 ran out of cards during war.\n";
						flag = 1;
						break;
					}
					player1.pop(c1);
					player2.pop(c2);
					if(i == 0)
					{
						cout << "Player 1's facedown card: " << c1
						     << "\nPlayer 2's facedown card: " << c2 << endl;
					}
					else
					{
						cout << "Player 1's faceup card: " << c1 
						     << "\nPlayer 2's faceup card: " << c2 << endl;
					}
					
					warCards.push(c1);
					warCards.push(c2);
				}
				if(flag != 0)
					break;
				ic1 = getRank(c1, ranks);
				ic2 = getRank(c2, ranks);
				if(ic1 > ic2)
				{
					cout << "Player 1's card is higher!\n\n";
					pushWarCards(player1, warCards);
				}
				else if(ic2 > ic1)
				{
					cout << "Player 2's card is higher!\n\n";
					pushWarCards(player2, warCards);
				}	
			}
		}
		cout << "Player 1 Cards left: " << player1.size() << "\n";
		cout << "Player 2 Cards left: " << player2.size() << "\n";
		if(flag != 0)
			break;
		if(player1.isEmpty())
				flag = 2;
		if(player2.isEmpty())
				flag = 1;
	}
	
	if(flag == 1)
		cout << "\nPlayer 1 wins!";
	else if(flag == 2)
		cout << "\nPlayer 2 wins!";
	else if(flag == 3)
		cout << "\nIt's a tie!";
}

//Takes in char c and char array ranks. Figures out ranks of c passed in
//returns int i.
int getRank(char c, char ranks[])
{
	for(int i = 0; i < 13; i++)
		if(c == ranks[i])
			return i;
}

//Takes in deckQueue player and warCards both passed by reference. Pops value
//out of warCards and pushes into player as long as warCards isn't empty.
void pushWarCards(deckQueue &player, deckQueue &warCards)
{
	while(!warCards.isEmpty())
	{
		char x;					
		warCards.pop(x);
		player.push(x);
	}
}

void goBoom() {
	int players;
	int p_turn; // player taking their turn (array notation)
	int decks;
	int highestScore = 0;
	string card;
	
	
	// decide number of players/decks
	do{
		cout << "Go Boom:\n"
			 << "This game is scored by summing the value of all opponent's"
			 << "\ncards after a win. Play continues until a player reaches"
			 << "\n200 score.\n\n"
			 << "Card Ranking: A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3, 2\n\n"
			 << "Go Boom supports 2-8 players, 2-6 players use 1 deck,\n"
			 << "7-8 players use 2 decks\n"
			 << "Please enter number of players: ";
		cin >> players;
	}while(players < 2 || players > 8);
	
	if(players < 7)
		decks = 1;
	else
		decks = 2;
	
	
	// calculated maximum possible hand size
	int maxHand = (decks * 52) - ((players - 1) * 7);
	
	set hands[players] = set(maxHand);  // array containing player hands
	int scores[players]; // array containing player scores
	for(int i = 0; i < players; i++)
		scores[i] = 0;
	
	
	// loop until a player has scored 200 points
	do{
		// shuffle deck
		deckOfCards deck(decks);
		deck.shuffleDeck();
		deck.shuffleDeck();
		int drawn = 0; // number of cards drawn from deck
		
		// deal/initialize player hands
		while(hands[0].size() < 3){
			for(int i = 0; i < players; i++){
				
				// get from deck
				card = deck.takeCard();
				if(card == "")
					break;
				drawn++;
				
				// put in hand
				hands[i].push(card);
			}
		}
		
		
		// play game: first player to 0 cards wins
		// while conditional checks after each turn if the player won
	
		int turn = 1;
		bool draw;  // flag tracking if current player needs to draw
		string inPlay = "NULL"; // current card at top of discard pile
		
		do{
			p_turn = (turn - 1) % players; // array notation
			
			// say whose turn it is
			cout << "\n\nPlayer " << p_turn + 1 << "'s turn";
	
			
			if(gbTurn(hands[p_turn], inPlay))  // if true: go to next player
				turn++;
				
			else{ // try to draw or skip if deck is empty
				if(drawn < decks * 52){
					hands[p_turn].push(deck.takeCard());
					drawn++;
				}
				else
					turn++;
			}
			
		}while(!hands[p_turn].isEmpty()); // check if current player hand is empty
		
		// calculate winner's total score
		char chTemp;
		int gameScore = 0;
		
		for(int i = 0; i < players; i++){ // first player to winner sum
		cout << "popping cards, showing calculated vals";
		
			while(!hands[i].isEmpty()){ // sum all cards in a hand 
				chTemp = hands[i].getTop()[0];
				hands[i].pop();
				
				// decide value of card
				if(isdigit(chTemp))
					gameScore += chTemp - 48;
				else if(chTemp == 'A')
					gameScore += 1;
				else if(isalpha(chTemp))
					gameScore += 10;
					
				cout << " " << chTemp;
			} // end while hand[i] !empty
		} 
		
		scores[p_turn] += gameScore;
		cout << "\n\n******\n"
			 << "Player " << p_turn + 1 << " wins the round with " << gameScore
			 << " points."
			 << "\n******\n\n"
			 << "Player scores below:\n";
		for(int i = 1; i <= players; i++)
			cout << endl << i << " - " << scores[i];
			 
		
		// check if greater than highestScore
		if(scores[p_turn] >= highestScore)
			highestScore = scores[p_turn];
		
		// clear hands and deck
		for(int i = 0; i < players; i++)
			hands[i].clear();
			
	}while(highestScore < 200);
	
	cout << "Player " << p_turn + 1 << " wins with a score of:\n\n"
		 << "*********\n" 
		 << "***" << scores[p_turn] << "***\n"
		 << "*********\n\n"
		 << "Player scores below:\n";
	for(int i = 1; i <= players; i++)
		cout << endl << i << " - " << scores[i];
	
	return;
}

// figure out what action the player will take
// cards can be played but drawing happens in main
bool gbTurn(set &_p, string &_inPlay){
	
	string toPlay; // player input card selection
	
	// show player their hand
	cout << "\nHand:\n";
	_p.display();
	

	// if first turn, allow player 1 to play any card
	if(_inPlay == "NULL"){										// Favre's fix implemented
		cout << "\nFirst turn, play any card.\n";
		
		do{
			cout << "Please enter rank and suite to play: ";
			cin.ignore();
			getline(cin, toPlay);
			toPlay[0] = toupper(toPlay[0]);
			toPlay[1] = toupper(toPlay[1]);
		}while(!_p.find(toPlay)); 
	
		_p.erase(toPlay);
		_inPlay = toPlay;
		return true;
	} // end if first turn
	
	
	// show card in play
	cout << "\nCard in play: " << _inPlay << endl;
	
	// not first, play matching card or draw
	do{
		cout << "Please enter rank and suite to play, or nothing to draw: ";
		getline(cin, toPlay);
			
		// return false: tells main to draw from deck
		if(toPlay == ""){
			return false;
		}
		
		toPlay[0] = toupper(toPlay[0]);
		toPlay[1] = toupper(toPlay[1]);
		
		// check if given selection would be playable
	}while(!_p.find(toPlay) || !gbPlayable(toPlay, _inPlay));
	
	_p.erase(toPlay);
	_inPlay = toPlay;
	return true;
}


// check if a given card would be playable
bool gbPlayable(const string _toPlay, const string _inPlay){
	// if suite or value is matched, card is playable
	if((_toPlay[0] == _inPlay[0]) || (_toPlay[1] == _inPlay[1]))
		return true;
	
	else
		return false;
}
