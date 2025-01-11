/*
Name: Reid Pace
Class: 121 PA6
Date: October 24, 2024
Lab Section: 15
Description: source file for function definition.
*/

#include "battleship.h"

//10-24
void welcome_screen() {
	
	printf("Welcome to Battleship!\n\n");
	
	printf("Press Enter for Rules:");
	//waits for enter
	while (getchar() != '\n');
	//clear screen
	system("cls");

	printf("1. This is a two-player game of Battleship.\n");
	printf("   - Player 1: You, the human player.\n");
	printf("   - Player 2: The computer.\n\n");

	printf("2. Each player has a 10x10 game board and five ships:\n");
	printf("   - Carrier (5 spaces)\n");
	printf("   - Battleship (4 spaces)\n");
	printf("   - Cruiser (3 spaces)\n");
	printf("   - Submarine (3 spaces)\n");
	printf("   - Destroyer (2 spaces)\n\n");

	printf("3. The goal of the game is to sink all of your opponent's ships before they sink yours.\n\n");

	printf("4. At the start of the game:\n");
	printf("   - You can choose to place your ships manually or randomly.\n");
	printf("   - The computer places its ships randomly.\n\n");

	printf("5. Players take turns firing at the opponent's board by selecting a grid coordinate.\n");
	printf("   - If the chosen coordinate contains part of an enemy ship, it's a hit.\n");
	printf("   - If the chosen coordinate is empty, it’s a miss.\n\n");

	printf("6. When all parts of a ship are hit, that ship is considered sunk.\n\n");

	printf("7. The game continues until one player has sunk all of the opponent's ships.\n\n");

	printf("8. The game keeps track of the moves in a log file for review at the end.\n\n");

	printf("Good luck!\n\n");

	printf("Press Enter to Continue:");
	//waits for enter
	while (getchar() != '\n');
	//clear screen
	system("cls");
}
//10-24
void initialize_game_board(char board[10][10]) {
	//generate board


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = '~';
		}

	}
}
	

//10-24
int select_who_starts_first() {

	printf("\nStarting player will be chosen at random.\n\n");
	//player 1 or 2
	return (rand() % 2)+1;


}
//10-24
int ship_positions() {
	int option = 0;
	printf("1. Enter position of ships manually.\n2. Allow the program to randomly select positions of ships\n"); scanf("%d", &option);
	system("cls");
	return option;
	
}

//10-25
void display_board(char board[10][10]) {
	//top
	printf("  0 1 2 3 4 5 6 7 8 9\n");

	//show rows
	for (int i = 0; i < 10; i++) {
		printf("%d ", i); //row number
		for (int j = 0; j < 10; j++) {
			printf("%c ", board[i][j]); //grid
		}
		printf("\n"); //next row
	}
}
//10-26
//10-27
int valid_position(char board[10][10], int row, int col, int ship_length, int direction) {
	for (int i = 0; i < ship_length; i++) {
		int check_row = 0, check_col = 0;
		check_row = row;
		check_col = col;

		if (direction == 0) {  //0 = horizontal
			check_col += i;
		}
		else {  //1 = vertical
			check_row += i; 
		}
		//off grid or ship already there
		if (check_row >= 10 || check_col >= 10 || board[check_row][check_col] != '~') {
			return 0; //invalid
		}
	}
	return 1; //valid
}

//10-25
//10-27
void manually_place_ships_on_board(char board[10][10]) {
	int row = 0, col = 0, ship_xy[10];
	int ship_lengths[5] = { 5, 4, 3, 3, 2};
	const char* ship_names[5] = { "Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer" };
	char ship_char[5] = { 'C', 'B', 'R', 'S', 'D' };

	//loop one ship at a time start at 'c'
	for (int i = 0; i < 5; i++) {
		int finished = 0;
		//finsihed to tell when each ship is placed
		while (!finished) {
			printf("\nEnter positions for %s (%d spaces):\n", ship_names[i], ship_lengths[i]);
			//double length for enought space
			 ship_xy[ship_lengths[i] * 2];
			 //loop asks for positions until ship length ends
			for (int j = 0; j < ship_lengths[i] * 2; j += 2) {
				printf("\nRow (Left): "); scanf("%d", &row);
				printf("\nColumn (Top): "); scanf("%d", &col);
				
				ship_xy[j] = row;
				//column offset
				ship_xy[j + 1] = col;
			}
			//
			if (valid_position(board, ship_xy[0], ship_xy[1], ship_lengths[i], 0)==1) {
				for (int j = 0; j < ship_lengths[i] * 2; j += 2) {
					//ship placed when valid
					board[ship_xy[j]][ship_xy[j + 1]] = ship_char[i];
				}
				
				finished = 1;//move to next ship
			}
			else {
				printf("Invalid position. Enter valid position.\n");
			}
		}
		display_board(board);
	}
	
}
//10-27
//10-29
void randomly_place_ships_on_board(char board[10][10]) {

	
	int shipsize[5] = { 5, 4, 3, 3, 2 }, shipchar[5] = { 'C', 'B', 'R', 'S', 'D' };


	//need to make the direction for every ship 
	for (int i = 0; i < 5; i++) {
		int finished = 0;
		int direction = 0, row = 0, col = 0;
		while (!finished) {
			direction = rand() % 2;

			//0=horizontal
			if (direction == 0) {

				row = rand() % 10;
				col = rand() % (10 - shipsize[i] + 1); //i is ship size

			}
			//1=vertical
			else {
				
				row = rand() % (10 - shipsize[i] + 1);
				col = rand() % 10;
			}

			int is_valid = valid_position(board, row, col, shipsize[i], direction);


			if (is_valid == 0) {
				continue;
			}
			//fix
			if (is_valid == 1) {
				
					// Place the ship on the board
					for (int j = 0; j < shipsize[i]; j++) {
						int place_row = row;
						int place_col = col;

						if (direction == 0) {  // Horizontal
							place_col = col + j;
						}
						else {// Vertical
							place_row = row + j;
						}
						//place char at board place
						board[place_row][place_col] = shipchar[i];
					}
				

				finished = 1;
			}
		}

	}

}

//11-2
int check_shot(char board[10][10], int row, int col) {//have to loop back to function in main when hit is achieved

	
	//find empty
	if (board[row][col] == '~') {
		printf("The shot at %d,%d missed!\n\n", row, col);
		return 0; //hit missed
	}
	if (board[row][col] == 'M' || board[row][col] == '*') {
	//returns 2 for when the player reuses coordinate. Can't return 1 or else update_board turns the M into a *
		printf("Coordinate already used. Please select new coordinates:\n\n");
		return 2;
	}
	else {
		printf("The shot at %d,%d landed!\n\n", row, col);
		return 1; //hit landed
	}
	
}

//11-2
void update_board(char board[10][10], int row, int col, int hit_miss) {
	//miss
	if (hit_miss == 0 || hit_miss == 2) {
		board[row][col] = 'M';
	}
	//hit
	else {
		board[row][col] = '*';
	}

}
//11-2
int check_sunk(char board[10][10], char ship_char) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (board[i][j] == ship_char) {//specific ship has chars left
				return 0;//ship found
			}

		}
		
	}
	return 1; //ship sunk
}

void computer_shot(int *row, int *col) {//computer chooses random coord

	*row = rand() % 10;

	*col = rand() % 10; 

	printf("\nPlayer 2 has fired at %d,%d!\n\n", *row, *col);
	
}

int is_winner(char board[10][10], char *ship_chars) {

	for (int i = 0; i < 10; i++) {//row
		for (int j = 0; j < 10; j++) {//col
			for (int k = 0; k < 5; k++) {//ship character
				if (board[i][j] == ship_chars[k]) {//if there is a ship char left the function ends
					return 0;//ship found, no win yet
				}
			}
		}

	}
	return 1;//no ships found. A player won
}

void output_current_move(FILE* outfile, int row, int col, int hit_miss, int sunk, int current_player, char ship_char, char* ship_names[], char ship_chars[]) {
	const char* ship_name = NULL;

	//find the ship name based on ship_char
	for (int i = 0; i < 5; i++) {
		if (ship_char == ship_chars[i]) {
			ship_name = ship_names[i];
			break;
		}
	}
	
	if (hit_miss) {
		fprintf(outfile, "Player %d hit the enemy %s at (%d, %d)\n", current_player, ship_name, row, col);

		
		if (sunk) {
			fprintf(outfile, "Player %d sunk the enemy %s at (%d, %d)\n", current_player, ship_name, row, col);
		}
	}
	else {
		fprintf(outfile, "Player %d missed at (%d, %d)\n", current_player, row, col);
	}
}

void output_stats(FILE* outfile, Stats p1, Stats p2) {

	fprintf(outfile, "\nPlayer 1 Statistics:\n\n");
	fprintf(outfile, "Player 1 Hits: %d\n", p1.num_hits);
	fprintf(outfile, "Player 1 Misses: %d\n", p1.num_miss);
	fprintf(outfile, "Player 1 Total Shots: %d\n\n", p1.total);

	fprintf(outfile, "Player 2 Statistics:\n\n");
	fprintf(outfile, "Player 2 Hits: %d\n", p2.num_hits);
	fprintf(outfile, "Player 2 Misses: %d\n", p2.num_miss);
	fprintf(outfile, "Player 2 Total Shots: %d\n\n", p2.total);
}