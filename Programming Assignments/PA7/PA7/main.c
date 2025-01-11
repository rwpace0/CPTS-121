/*
Name: Reid Pace
Class: 121 PA7
Date: November 14, 2024
Lab Section: 15
Description: main file for program execution.
*/

#include "poker.h"


int main(void)
{
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	//1 for start. 2 for rules. 3 for exit
	int menu_option = 0;
	
	//user selects to play again
	char play_again;

	//player and dealer score
	int p_score = 0, d_score = 0;
	//y or n for player to redraw cards
	char redraw_input;

	//player hand and dealer hand variables
	Hand player_hand;
	Hand dealer_hand;

	srand((unsigned)time(NULL)); /* seed random-number generator */

	while (play_again=1) {

		menu_option = print_menu();
		switch (menu_option) {
		case 1:
			break;
		case 2:
			//rules
			system("cls");
			printf("1. You and the dealer are both dealt five cards. The dealers hand is hidden.\n\n2. You may choose to redraw up to three cards. The dealer will do the same\n\n3.After redrawing or not redrawing, both hands will be compared. The hand with the best combination wins.\n\n4. The combinations (from lowest to highest rank):\n\n(1) Pair\n\n(2) Two Pairs\n\n(3) Three of a Kind\n\n(4) Straight\n\n(5) Full House\n\n(6) Flush\n\n(7) Four of a Kind\n\n");
			system("pause");
			system("cls");
			break;
		case 3:
			//exit
			printf("Goodbye\n");
			return 0;
		}
		//player
		shuffle(deck);
		deal(deck, face, suit, &player_hand);

		//dealer
		shuffle(deck);
		deal(deck, face, suit, &dealer_hand);


		printf("Player Hand:\n\n");
		print_hand(face, suit, &player_hand);
		printf("\nYou may redraw up to three cards. Would you like to redraw any cards? (Y/N): "); scanf(" %c", &redraw_input);
		//player chooses to redraw
		if (redraw_input == 'Y' || redraw_input == 'y') {
			player_redraw_cards(deck, face, suit, &player_hand);
		}
		printf("\n");
		system("pause");
		system("cls");
		//dealer redraws
		dealer_redraw_cards(deck, face, suit, &dealer_hand);
		//player and dealer scores
		p_score = hand_score(&player_hand);
		d_score = hand_score(&dealer_hand);
		
		printf("Both hands have been finalized.\n\n");
		system("pause");
		system("cls");

		//end of game showing both hands
		printf("Your Hand:\n\n");
		print_hand(face, suit, &player_hand);
		printf("\nDealer Hand:\n\n");
		print_hand(face, suit, &dealer_hand);

		//determining who wins
		if (p_score > d_score) {

			printf("\nYou won!\n\nWould you like to play again? (Y/N): "); scanf(" %c", &play_again);

		}
		if (p_score < d_score) {

			printf("\nThe dealer won!\n\nWould you like to play again? (Y/N): "); scanf(" %c", &play_again);

		}
		if (p_score == d_score) {
		
			printf("\nIt was a tie!\n\nWould you like to play again? (Y/N): "); scanf(" %c", &play_again);

		}
		//game restarts when user choses to play again
		if (play_again == 'Y' || play_again == 'y') {
			
			system("cls");
			play_again = 1;
		}
		//player chose not to play again
		else {
			system("cls");
			printf("Goodbye\n");
			return 0;
		}

	}
	return 0;
}