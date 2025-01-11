/*
Name: Reid Pace
Class: 121 PA6
Date: October 24, 2024
Lab Section: 15
Description: header file for function declaration.
*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#define _CRT_SECURE_NO_WARNINGS

#define CARRIER_LENGTH 5
#define BATTLESHIP_LENGTH 4
#define CRUISER_LENGTH 3
#define SUBMARINE_LENGTH 3
#define DESTROYER_LENGTH 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//11-3
//struct used to keep track of the player stats to print to the output file. 
typedef struct {

	int num_hits, num_miss, total;

} Stats;


/*************************************************************
* Function:	welcome_screen
* Date Created: 10/24/24
* Date Last Modified: 10/24/24
* Description: This function prints the game menu and waits for user to press enter to continue the program. 
* Input parameters: None
* Returns: None
* Preconditions: Noe
* Postconditions: Continues the game after enter.
*************************************************************/
void welcome_screen();

/*************************************************************
* Function: initialize_game_board
* Date Created: 10/24/24
* Date Last Modified: 10/24/24
* Description: Populates a 10x10 grid with '~'.  
* Input parameters: board
* Returns:None
* Preconditions: None
* Postconditions: None
*************************************************************/
void initialize_game_board(char board[10][10]);

/*************************************************************
* Function:	select_who_starts_first
* Date Created: 10/24/24
* Date Last Modified: 10/24/24
* Description: This function randomly chooses player 1 or 2 to start.
* Input parameters: None
* Returns: Rand() function that can output either 1 or 2.
* Preconditions: None
* Postconditions: Selects who starts first
*************************************************************/
int select_who_starts_first();


/*************************************************************
* Function:	ship_position
* Date Created: 10/24/24
* Date Last Modified: 10/24/24
* Description: Gives user the choice between randomly placing ships on the board or manually placing them.
* Input parameters: none
* Returns: The player's choice
* Preconditions: The player choice must be accessible. 
* Postconditions: The board will continue on to manually place or random place functions
*************************************************************/
int ship_positions();

/*************************************************************
* Function:	display_board
* Date Created: 10/25/24
* Date Last Modified: 10/25/24
* Description: Displays and numbers each position on the board. 
* Input parameters: board
* Returns: None
* Preconditions: The intialize board must be accessible
* Postconditions: Displays the 10x10 board to the screen
*************************************************************/
void display_board(char board[10][10]);

/*************************************************************
* Function:	valid_position
* Date Created: 10/26/24
* Date Last Modified: 10/27/24
* Description: This function determines if the position of the ship overlaps another.
* Input parameters: Board, row, column, the ship's length, and the direction it's placed
* Returns: 1 if there is no ship where a new ship is trying to be placed. 2 if the position isn't empty
* Preconditions: The board must be accessible
* Postconditions: Continues when position is valid
*************************************************************/
int valid_position(char board[10][10], int row, int col, int ship_length, int direction);

/*************************************************************
* Function:	manually_place_ships_on_board
* Date Created: 10/25/24
* Date Last Modified: 10/27/24
* Description: Allows the user to choose the position of each ship and saves it.
* Input parameters: Board
* Returns: None
* Preconditions: The board must be accessible and the valid_position function must determine if the player can place ships there or not.
* Postconditions: Continues the game with the player's chosen positions
*************************************************************/
void manually_place_ships_on_board(char board[10][10]);

/*************************************************************
* Function:	randomly_place_ships_on_board
* Date Created: 10/27/24
* Date Last Modified: 10/29/24
* Description: Randomly places every ship on the board. Used if the player selects random placement and for the computer's board
* Input parameters: Board
* Returns: None
* Preconditions: The board must be accessible and the valid_position function must determine if ships can be there or not.
* Postconditions: Continues the game with the randomly places board
*************************************************************/
void randomly_place_ships_on_board(char board[10][10]);

/*************************************************************
* Function:	check_shot
* Date Created: 11/2/24
* Date Last Modified: 11/2/24
* Description: Determines if the shot hit a ship or missed. Re-asks for input if spot already chosen before
* Input parameters: Board, row, and column of the shot
* Returns: 1 if the shot hit a ship and 0 if it missed. 2 if the shot was already used.
* Preconditions: The board must be populated with ships.
* Postconditions: Determines hit or miss.
*************************************************************/
int check_shot(char board[10][10], int row, int col);

/*************************************************************
* Function:	update_board
* Date Created: 11/2/24
* Date Last Modified: 11/2/24
* Description: Updated the position of the last shot with 'M' for miss and '*' for a hit.
* Input parameters: Board, with the row and column of the character. Hit_miss variable for checking the shot.
* Returns: None
* Preconditions: The board must be accessible and the valid_position function must determine if ships can be there or not.
* Postconditions: Continues the game with the randomly places board
*************************************************************/
void update_board(char board[10][10], int row, int col, int hit_miss);

/*************************************************************
* Function:	check_sunk
* Date Created: 11/2/24
* Date Last Modified: 11/2/24
* Description: Checks to see if a ship got sunk so the program can display to the user what ship was sunk.
* Input parameters: Board and the character of the ship that was hit
* Returns: 1 if a ship was sunk and 0 if the ship still is alive
* Preconditions: The last shot that landed must be accessible.
* Postconditions: Main writes a message saying what ship was sunk if the function returns 1.
*************************************************************/
int check_sunk(char board[10][10], char ship_char);

/*************************************************************
* Function:	computer_shot
* Date Created: 11/3/24
* Date Last Modified: 11/3/24
* Description: Randomly chooses a postion on the board to shoot for the computer.
* Input parameters: row and column of the shot
* Returns: None
* Preconditions: It must be the computers turn to shoot and all of the previous functions must be accessible
* Postconditions: Determines a random column and row to fire 
*************************************************************/
void computer_shot(int *row, int *col);

/*************************************************************
* Function:	is_winner
* Date Created: 11/3/24
* Date Last Modified: 11/3/24
* Description: Determines if there are any ships left on the board. If not then the opposite board is the winner
* Input parameters: board and the characters of the ships
* Returns: 1 if a player wins and 0 if there are still ships on the board
* Preconditions: Both updated boards must be accessible
* Postconditions: Displays winning message if there is a winner
*************************************************************/
int is_winner(char board[10][10], char* ship_chars);

/*************************************************************
* Function:	output_current_move
* Date Created: 11/3/24
* Date Last Modified: 11/3/24
* Description: Outputs each shot and miss by the specific player to the output file
* Input parameters:output file, row, column, hit or miss shot, sunk ship, current player's turn, ship characters, names of the ships, ship characters.
* Returns: None
* Preconditions: Player must have made a move
* Postconditions: Outputs move to output file
*************************************************************/
void output_current_move(FILE* outfile, int row, int col, int hit_miss, int sunk, int current_player, char ship_char, char* ship_names[], char ship_chars[]);

/*************************************************************
* Function:	output_stats
* Date Created: 11/3/24
* Date Last Modified: 11/3/24
* Description: Prints the player stats to the output file
* Input parameters: Output file, player 1 and player 2 variables from struct. Keeps tracked of hits, misses, and total shots for each player
* Returns: None
* Preconditions: Player must have hit or miss ship
* Postconditions: Prints stats to output file
*************************************************************/
void output_stats(FILE* outfile, Stats p1, Stats p2);

#endif