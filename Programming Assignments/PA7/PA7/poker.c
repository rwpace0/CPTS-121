/*
Name: Reid Pace
Class: 121 PA7
Date: November 14, 2024
Lab Section: 15
Description: source file for function definition.
*/
#include "poker.h"

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */


	//reset the deck so shuffle can be called multiple times
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			wDeck[i][j] = 0;
		}
	}

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand *player_hand)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int num_cards = 0;

	/* deal 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					/*player hand points to the hand.hand is the position of each card that is chosen. num_cards counts how many cards there are, up to 5.
					face of the card is found through column and suit is through row. */
					player_hand->hand[num_cards].face_index = column;
					player_hand->hand[num_cards].suit_index = row;
					num_cards++;
					if (num_cards == 5) {
						return;
					}
				}
			}
		}
	}
}

void print_hand(const char* wFace[], const char* wSuit[], Hand *player_hand) {
	for (int i = 0; i < 5; i++) {
		printf("%5s of %-8s%c", wFace[player_hand->hand[i].face_index], wSuit[player_hand->hand[i].suit_index], i % 2 == 0 ? '\n' : '\n');
	}

}

int print_menu() {
	int option = 0;

	printf("Welcome to 5-Card Draw!\n1. Start\n2. Rules\n3. Exit\n"); scanf("%d", &option);
		system("cls");
		return option;
		
}

//11/16/24
int contains_pair(Hand* player_hand) {

	int face_count[13] = { 0 };

	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face. when 2 of the same faces are found the next for loop will return 1
		face_count[player_hand->hand[i].face_index]++;
	}
		
	for (int i = 0; i < 13; i++) {
		if (face_count[i] == 2) {
			//pair found
			return 1; 
		}
	}
	//no pair
	return 0;

}

int contains_2pair(Hand* player_hand) {

	int face_count[13] = { 0 };
	int pairs = 0;

	
	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face.
		face_count[player_hand->hand[i].face_index]++;
	}

	for (int i = 0; i < 13; i++) {
		if (face_count[i] == 2) {
			//pair found
			pairs++;
		}
	}
	

	//if pairs = 2 it returns 1 if not it returns 0
	return (pairs == 2);
}

int contains_three(Hand* player_hand) {

	int face_count[13] = { 0 };

	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face.
		face_count[player_hand->hand[i].face_index]++;
	}

	for (int i = 0; i < 13; i++) {
		if (face_count[i] == 3) {
			//three of a kind found
			return 1;
		}
	}
	//no three of a kind
	return 0;

}

int contains_four(Hand* player_hand) {

	int face_count[13] = { 0 };

	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face.
		face_count[player_hand->hand[i].face_index]++;
	}

	for (int i = 0; i < 13; i++) {
		if (face_count[i] == 4) {
			//four of a kind found
			return 1;
		}
	}
	//no four of a kind
	return 0;

}

int contains_full_house(Hand* player_hand) {

	int face_count[13] = { 0 };
	int pair = 0;
	int three = 0;

	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face.
		face_count[player_hand->hand[i].face_index]++;
	}
	//finds pair and three of a kind
	for (int i = 0; i < 13; i++) {
		if (face_count[i] == 2) {
			pair++;
		}
		if (face_count[i] == 3) {
			three++;
		}
	}
	//returns 1 if there is a pair and a three of a kind. 0 otherwise.
	return (pair == 1 && three == 1);
}

int contains_flush(Hand* player_hand) {

	int suit_count[13] = { 0 };

	for (int i = 0; i < 5; i++) {
		//increments every time it notices a suit
		suit_count[player_hand->hand[i].suit_index]++;
	}

	for (int i = 0; i < 13; i++) {
		if (suit_count[i] == 5) {
			//flush found
			return 1;
		}
	}
	//no flush found
	return 0;

}

int contains_straight(Hand* player_hand) {

	int face_count[13] = { 0 };
	int count=0;


	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face.
		face_count[player_hand->hand[i].face_index]++;
	}
	//every individual card is stored as 1. if two of the same card is found it will return 0.
	for (int i = 0; i < 13; i++) {
		if (face_count[i] == 1) {
			count++;
			//count==5 returns 1 when there is no separation between cards.
			if (count == 5) {
				return 1;
			}
		}
		else {
			count = 0;
		}
	}
	
	//count never reached five. no straight
	return 0;

}

int hand_score(Hand* player_hand) {
	int points = 0;

	//point system for the card combos rank
	if (contains_pair(player_hand)) {
		points++;
	}
	if (contains_2pair(player_hand)) {
		points += 2;
	}
	if (contains_three(player_hand)) {
		points += 3;
	}
	if (contains_straight(player_hand)) {
		points += 4;
	}
	if (contains_full_house(player_hand)) {
		points += 5;
	}
	if (contains_flush(player_hand)) {
		points += 6;
	}
	if (contains_four(player_hand)) {
		points += 7;
	}
	return points;
}

//prompts user once. uses string.h for handling
void player_redraw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* player_hand) {

	char input[100];
	int num_redraw=0, card_num = 0, suit=0, face=0;
	
	int redraw[5] = { 0 };
	//for making every number a different input instead of one
	char* separate;

	//clears previous input. fgets counts the previous input without this
	while (getchar() != '\n');

	printf("\nWhat cards you would like to redraw (1-5): "); 
	fgets(input, sizeof(input), stdin);

	

	//changes every space into null character to allow for multiple inputs
	separate = strtok(input, " ");
	
	while (separate != NULL) {
		//changes separate into an int
		card_num = atoi(separate);

		if (card_num > 5 || card_num < 1) {
			printf("\nInvalid card position. Enter new card position\n"); return;
		}
		if (redraw[card_num - 1]) {
			printf("\nDuplicate card position. Enter new card position\n"); return;
		}
		//mark for redraw
		redraw[card_num - 1] = 1;

		num_redraw++;

		if (num_redraw > 3) {
			printf("\nToo many cards selected. Don't enter more than three positions\n"); return;
		}
		//go to next number
		separate = strtok(NULL, " ");
	}
	for (int i = 0; i < 5; i++) {
		if (redraw[i]) {
			generate_card(&face, &suit, player_hand);
			player_hand->hand[i].face_index = face;
			player_hand->hand[i].suit_index = suit;
		}

	}

	system("cls");
	printf("Your new hand:\n\n");
	print_hand(wFace, wSuit, player_hand);

}
//find which cards are repeated using contains functions and mark those to not be redrawn. mark others for redraw.
void dealer_redraw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* dealer_hand) {

	int face_count[13] = { 0 };
	int redraw[5] = { 0 };
	int suit = 0, face = 0;

	//from the contains functions:
	for (int i = 0; i < 5; i++) {
		//increments every time it notices a face. when 2 of the same faces are found the next for loop will return 1
		face_count[dealer_hand->hand[i].face_index]++;
	}
	//marks all cards that are not part of pair for redraw
	if (contains_pair(dealer_hand) && !contains_2pair(dealer_hand)) {
		
		for (int i = 0; i < 13; i++) {
			if (face_count[i] == 2) {
				for (int j = 0; j < 5; j++) {
					if (dealer_hand->hand[j].face_index == i) {
						redraw[j] = 0;
					}
				}
				break; //stop after first pair is found
			}
		}

	}

	if (contains_2pair(dealer_hand)) {
		for (int i = 0; i < 13; i++) {
			if (face_count[i] == 2) {
				for (int j = 0; j < 5; j++) {
					if (dealer_hand->hand[j].face_index == i) {
						redraw[j] = 0;
					}
				}
			}
		}
	}
	
	if (contains_three(dealer_hand)) {
		for (int i = 0; i < 13; i++) {
			if (face_count[i] == 3) {
				for (int j = 0; j < 5; j++) {
					if (dealer_hand->hand[j].face_index == i) {
						redraw[j] = 0;
					}
				}
				break;
			}
		}
	}
	//hand good enough to not redraw
	if (contains_four(dealer_hand) || contains_full_house(dealer_hand) || contains_flush(dealer_hand) || contains_straight(dealer_hand)) {
		return; //no redraw
	}
	//nothing found redraw all cards
	else {
		for (int i = 0; i < 3; i++){
				redraw[i] = 1;
		}
	}

	//redraw marked cards
	for (int i = 0; i < 5; i++) {
		
			if (redraw[i]) {
				generate_card(&face, &suit, dealer_hand);
				dealer_hand->hand[i].face_index = face;
				dealer_hand->hand[i].suit_index = suit;
			

			}
	}


	
	
}

//generates a card for redraw functions as long as the cards haven't been used
void generate_card(int *face, int *suit, Hand *player_hand) {

	do {
		*suit = rand() % 4;//row
		*face = rand() % 13;//col
	} while (used_cards(*face, *suit, player_hand));

}

//just for functions
int used_cards(int face, int suit, Hand *player_hand) {

	for (int i = 0; i < 5; i++) {
		//card in hand return 1
		if (player_hand->hand[i].face_index == face && player_hand->hand[i].suit_index == suit) {
			return 1;
		}

	}
	return 0;
}