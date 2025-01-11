/*
Name: Reid Pace
Class: 121 PA6
Date: November 14, 2024
Lab Section: 15
Description: header file for function declaration.
*/

#ifndef POKER_H
#define POKER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {

	int face_index, suit_index;

} Card;

typedef struct {

	Card hand[5];

} Hand;

/*************************************************************
* Function:	shuffle
* Date Created: Included
* Date Last Modified: Not modified
* Description: Shuffles deck so cards arent in the same order
* Input parameters: Deck
* Returns: None
* Preconditions: Deck must be accessible
* Postconditions: Shuffles deck when called
*************************************************************/
void shuffle(int wDeck[][13]);

/*************************************************************
* Function:	deal
* Date Created: included
* Date Last Modified: 11/17/24
* Description: Deals 5 random cards to the player or dealer hand
* Input parameters: Deck, face, suit, hand(player or dealer)
* Returns: None
* Preconditions: All input parameters must work
* Postconditions: Deals cards to hands
*************************************************************/
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* player_hand);

/*************************************************************
* Function:	print_menu
* Date Created: 11/16/24
* Date Last Modified: 11/16/24
* Description: This function prints the game menu and waits for user to choose to start, print rules, or exit.
* Input parameters: None
* Returns: Player selection
* Preconditions: None
* Postconditions: Continues based on input.
*************************************************************/
int print_menu();

/*************************************************************
* Function:	print_hand
* Date Created: 11/16/24
* Date Last Modified: 11/20/24
* Description: Prints the hand of either the dealer or the player
* Input parameters: Face, suit, player/dealer hand
* Returns: None
* Preconditions: There must be a hand available from the deal function
* Postconditions: Displays hand
*************************************************************/
void print_hand(const char* wFace[], const char* wSuit[], Hand* player_hand);

/*************************************************************
* Function:	contains_pair
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there is a pair in a deck
* Input parameters: player/dealer hand
* Returns: 1 for pair 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there is a pair
*************************************************************/
int contains_pair(Hand* player_hand);

/*************************************************************
* Function:	contains_2pair
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there are two pairs in a deck
* Input parameters: player/dealer hand
* Returns: 1 for 2 pairs 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there are 2 pairs
*************************************************************/
int contains_2pair(Hand* player_hand);

/*************************************************************
* Function:	contains_three
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there are 3 of the same faces in a deck
* Input parameters: player/dealer hand
* Returns: 1 for three of a kind 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there is three of a kind
*************************************************************/
int contains_three(Hand* player_hand);

/*************************************************************
* Function:	contains_four
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there is are four of a kind in a deck
* Input parameters: player/dealer hand
* Returns: 1 for four of a kind 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there is four of a kind
*************************************************************/
int contains_four(Hand* player_hand);

/*************************************************************
* Function:	contains_full_house
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there is a full house
* Input parameters: player/dealer hand
* Returns: 1 for full house 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there is a full house
*************************************************************/
int contains_full_house(Hand* player_hand);

/*************************************************************
* Function:	contains_flush
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there is a a flush in a hand
* Input parameters: player/dealer hand
* Returns: 1 for flush 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there is a flush
*************************************************************/
int contains_flush(Hand* player_hand);

/*************************************************************
* Function:	contains_straight
* Date Created: 11/18/24
* Date Last Modified: 11/18/24
* Description: Determines if there is a straight in a deck
* Input parameters: player/dealer hand
* Returns: 1 for straight 0 for none
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines if there is a straight
*************************************************************/
int contains_straight(Hand* player_hand);

/*************************************************************
* Function:	hand_score
* Date Created: 11/18/24
* Date Last Modified: 11/21/24
* Description: Sets each hand combination to different point values. a pair is only worth one but a flush is worth 5
* Input parameters: player/dealer hand
* Returns: points from combos
* Preconditions: There must be a hand available from the deal function
* Postconditions: Determines a hand's vvalue
*************************************************************/
int hand_score(Hand* player_hand);

/*************************************************************
* Function:	player_redraw_cards
* Date Created: 11/19/24
* Date Last Modified: 11/21/24
* Description: Allows the player to redraw up to 3 cards and chooses three random unused cards
* Input parameters: Deck, face, suit, player hand
* Returns: None
* Preconditions: Player must have already gotten hand from deal function
* Postconditions: Updates hand based on the card redraw
*************************************************************/
void player_redraw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* player_hand);

/*************************************************************
* Function:	dealer_redraw_cards
* Date Created: 11/19/24
* Date Last Modified: 11/21/24
* Description: Redraws cards for the dealer. Recognizes when it has a combo and redraws other cards based on the combo
* Input parameters: Deck, face, suit, dealer hand
* Returns: None
* Preconditions: Dealer must have already gotten hand from deal function
* Postconditions: Updates hand based on the card redraw
*************************************************************/
void dealer_redraw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* dealer_hand);

/*************************************************************
* Function:	generate_card
* Date Created: 11/19/24
* Date Last Modified: 11/20/24
* Description: Finds a random card in the deck and makes sure it hasn't been used
* Input parameters: face, suit, hand
* Returns: None
* Preconditions: Used_cards must be accessible
* Postconditions: Generates a new card
*************************************************************/
void generate_card(int* face, int* suit, Hand* player_hand);

/*************************************************************
* Function:	used_cards
* Date Created: 11/19/24
* Date Last Modified: 11/20/24
* Description: Determines if the card is in the hand already
* Input parameters: face, suit, dealer hand
* Returns: 1 if card is in hand, 0 if not
* Preconditions: Hand must be accessible
* Postconditions: Determines if a card is in the deck
*************************************************************/
int used_cards(int face, int suit, Hand* player_hand);

#endif