/*
Name: Reid Pace
Class: 121 PA5
Date: October 19, 2024
Lab Section: 15
Description: source file for equations and function definition.
*/

#include "yahtzee.h"

/*************************************************************
* Function:	print_game_menu
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function prints the starting game menu
* Input parameters: User inputs 1-3 what they want to select
* Returns: The choice of the user
* Preconditions: The user input must be accessible
* Postconditions: Continues to do what the player wants. 1 for rules. 2 to play. 3 to exit.
*************************************************************/
int print_game_menu() {
	int game_state = 0;
	printf("Welcome to Yahtzee!\n1. Print game rules\n2. Start a game of Yahtzee\n3. Exit\n"); scanf("%d", &game_state);

	return game_state;


}

/*************************************************************
* Function:	print_rules
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function prints rules
* Input parameters: None
* Returns: None
* Preconditions: The user must have pressed 2 at the menu
* Postconditions: Prints rules of yahtzee
*************************************************************/
void print_rules() {

	printf("\nRules:\n\nYahtzee is a turn-based game where players aim to score the most points by rolling five dice to achieve specific combinations over 13 rounds. On each turn, a player can roll the dice up to three times, choosing to re-roll any number of dice after the first roll. At the end of their turn, the player selects one of 13 scorecard categories to score based on their dice roll. The scorecard is divided into an Upper Section, where points are earned by totaling specific numbers (e.g., Ones, Twos, etc.), and a Lower Section, which includes combinations like Three of a Kind, Four of a Kind, Full House (25 points), Small Straight (30 points), Large Straight (40 points), Yahtzee (50 points), and Chance. If a player's total in the Upper Section reaches 63 or more points, they receive a 35-point bonus. Multiple Yahtzees after the first score an additional 100 points if the Yahtzee category has already been filled. The game ends after all 13 categories are filled, and the player with the highest total score wins.\n\n");
	
}

/*************************************************************
* Function:	roll_1die
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function rolls a random number between 1-6
* Input parameters: None
* Returns: Random number between 1-6
* Preconditions: The game must be started
* Postconditions: Rolls die by selecting number between 1-6
*************************************************************/
int roll_1die() {
	return  (rand() % 6) + 1;
	}
	
/*************************************************************
* Function:	roll_dice
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function rolls 5 dice from the single dice roll function
* Input parameters: None
* Returns: None
* Preconditions: The game must be started and the roll_1die function must be accessible
* Postconditions: Randomly rolls 5 different die
*************************************************************/
void roll_dice(int dice[5]) {
	for (int i = 0; i < 5; i++) {
		dice[i] = roll_1die();
	}
}

/*************************************************************
* Function:	display_dice
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function displays the results of the five dice rolls
* Input parameters: None
* Returns: None
* Preconditions: All of the roll dice functions must be accessible
* Postconditions: Displays the values of the 5 dice rolls
*************************************************************/
void display_dice(int dice[], int num_dice) {
	printf("\nRolls:\n");
	for (int i = 0; i < num_dice; i++) {
		printf("%d \n", dice[i]); 
		}
	
}

/*************************************************************
* Function:	calculate_combo
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function calculates the 13 different combinations the user can choose by using a switch loop
* Input parameters: User selects what combo they want to use from the dice rolls
* Returns: The score of the user
* Preconditions: The roll dice functions and players input must be accessible
* Postconditions: Calculates combination and adds it to the  player's score
*************************************************************/
int calculate_combo(int dice[5], int choice) {
	int score = 0;
	int count[6] = { 0 };
	
	for (int i = 0; i < 5; i++) {
		count[dice[i] - 1]++;
	}
	//for the sum of options the sum of the numbers are added to the player score
	switch (choice) {
	case 1: case 2: case 3: case 4: case 5: case 6:
		for (int i = 0; i < 5; i++) {
			if (dice[i] == choice) {
				score += dice[i];
			}

		}
		break;
		//checks the numbers for three of a kind and adds to score
	case 7:
		for (int i = 0; i < 6; i++) {
			if (count[i] >= 3) {
				for (int j = 0; j < 5; j++) {
					score += dice[j];
				}
				return score;

			}

		}
		break;
		//checks numbers for four of a kind and adds to score
	case 8:
		for (int i = 0; i < 6; i++) {
			if (count[i] >= 4) {
				for (int j = 0; j < 5; j++) {
					score += dice[j];
				}
				return score;

			}

		}
		break;
		//checks numbers for all the same numbers and adds 25 to score 
	case 9:
	{
		int three = 0, two = 0;
		for (int i = 0; i < 6; i++) {
			if (count[i] == 3) three = 1;
			if (count[i] == 2) two = 1;
		}
		if (three && two) return 25;
	}
	break;
	//checks for three numbers in a row and adds 30 to score
	case 10:
		if ((count[0] && count[1] && count[2] && count[3]) ||
			(count[1] && count[2] && count[3] && count[4]) ||
			(count[2] && count[3] && count[4] && count[5])) {
			return 30;
		}
		break;
		//checks for five numbers in a row and adds 40 to score.
	case 11:
		if ((count[0] && count[1] && count[2] && count[3] && count[4]) || (count[1] && count[2] && count[3] && count[4] && count[5])) {
			return 40;

		}
		break;
		//checks for yahtzee adds 50 to score
	case 12:
		for (int i = 0; i < 6; i++) {
			if (count[i] == 5) {
				return 50;
			}
		}
		break;
		//adds sum of same dice to score
	case 13:
		for (int i = 0; i < 5; i++) {
			score += dice[i];
		}
		break;
	}
	return score;
}

/*************************************************************
* Function:	display_combo_menu
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function prints the combination menu
* Input parameters: The user must have chosen to select a combination
* Returns: None
* Preconditions: The users selection must be available
* Postconditions: Will proceed to the calculation function after selection
*************************************************************/
void display_combo_menu(int used[13]) {
	printf("\nChoose an option:\n");
	if (used[0] != -1) printf("1. Sum of 1's\n");
	if (used[1] != -1) printf("2. Sum of 2's\n");
	if (used[2] != -1) printf("3. Sum of 3's\n");
	if (used[3] != -1) printf("4. Sum of 4's\n");
	if (used[4] != -1) printf("5. Sum of 5's\n");
	if (used[5] != -1) printf("6. Sum of 6's\n");
	if (used[6] != -1) printf("7. Three-of-a-kind\n");
	if (used[7] != -1) printf("8. Four-of-a-kind\n");
	if (used[8] != -1) printf("9. Full house\n");
	if (used[9] != -1) printf("10. Small straight\n");
	if (used[10] != -1) printf("11. Large straight\n");
	if (used[11] != -1) printf("12. Yahtzee\n");
	if (used[12] != -1) printf("13. Chance\n");
}

/*************************************************************
* Function:	option_used
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function determines if the user has already chosen a function.
* Input parameters: The choice of the user at the combination menu
* Returns: 1 if the combo has been selected to restart combination menu. 0 to continue program when a valid selection was chosen
* Preconditions: The choice of the user at the combo menu
* Postconditions: Continues program if valid combo and restarts menu if chosen an already used combo.
*************************************************************/
int option_used(int used[13], int choice) {

	if (used[choice - 1] == -1) {
		printf("\nOption %d has already been used. Please select another option.\n", choice);
		return 1;
	}
	return 0; 
}

/*************************************************************
* Function:	reroll_dice
* Date Created: 9/19/24
* Date Last Modified: 9/19/24
* Description: This function rerolls dice if the user choses not to use the last roll for a combination. User choses the dice position to reroll and types 0 after all positions are chosen.
* Input parameters: The positions of the dice
* Returns: None
* Preconditions: The user must have chosen to reroll dice
* Postconditions: Rerolls dice positions based on input
*************************************************************/
void reroll_dice(int dice[5]) {
	int reroll[5] = { 0 };
	int die_num = 0;

	printf("\nEnter which dice position you want to reroll(1-5). Enter 0 when you want to stop: ");
	
	while (1) {
		scanf("%d", &die_num);
		if (die_num == 0) {
			break;
		}
		if (die_num >= 1 && die_num <= 5) {
			reroll[die_num - 1] = 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (reroll[i] == 1) {
			dice[i] = roll_1die();
		}
	}
}