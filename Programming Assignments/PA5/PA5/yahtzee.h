/*
Name: Reid Pace
Class: 121 PA5
Date: October 19, 2024
Lab Section: 15
Description: header file for function declaration.
*/

#ifndef YAHTZEE_H
#define YAHTZEE_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



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
int print_game_menu();


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
void print_rules();


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
int roll_1die();


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
void roll_dice(int dice[5]);


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
void display_dice(int dice[], int num_dice);


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
int calculate_combo(int dice[5], int choice);


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
void display_combo_menu(int used[13]);


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
int option_used(int used[13], int choice);


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
void reroll_dice(int dice[5]);

#endif
