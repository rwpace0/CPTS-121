/*
Name: Reid Pace
Class: 121 PA6
Date: October 24, 2024
Lab Section: 15
Description: main file for program execution.
*/

#include "battleship.h"

int main() {
	//board used to test if the ships would land correctly and game would finish
	//printf("\nactual board for test\n\n"); display_board(player2_board);

	int game_state = 0, option = 0, row = 0, col = 0, hit_miss = 0, current_player, sunk=0, won_loss=0;
	char hidden_board[10][10], player1_board[10][10] = { {0} }, player2_board[10][10] = {{ 0 }};
	const char* ship_names[5] = { "Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer" };
	char ship_chars[5]={ 'C', 'B', 'R', 'S', 'D' };
	char ship_char;
	FILE* outfile = NULL;
	outfile = fopen("battleship.log", "w");
	Stats p1 = { 0,0,0 }, p2 = { 0,0,0 };

	srand(time(NULL));
	
	welcome_screen();

	option = ship_positions(); 
	
	initialize_game_board(player1_board);
	initialize_game_board(player2_board);
	initialize_game_board(hidden_board);

	if (option == 1) {
		//replace player 2 board
		display_board(player1_board);
		manually_place_ships_on_board(player1_board);
		
	}
	if (option == 2) {
		randomly_place_ships_on_board(player1_board);
	}
	//player 2 board
	randomly_place_ships_on_board(player2_board);
	printf("Player 2 (Computer's) board has been generated.\n");
	
	printf("\nYour Board:\n\n");
	display_board(player1_board);

	printf("\nPlayer 2's board:\n\n");
	display_board(hidden_board);

	
	
	//starting player
	current_player = select_who_starts_first();
	system("pause");
	system("cls");
		printf("Player %d has been selected to start first:\n\n", current_player);
		


		//use system("pause");

		//while is_winner
		while (won_loss==0) {
			switch (current_player) {
			case 1:
				//display the player two board to fire at
				printf("Player 2's board:\n\n");
				display_board(hidden_board);
				printf("\nEnter Target:\n");
				printf("\nRow (X): "); scanf("%d", &row);
				printf("\nColumn (Y): "); scanf("%d", &col);
				system("cls");
				//have to make it continue on hit and break on miss
				hit_miss = check_shot(player2_board, row, col);
				//ttotal shots to logfile
				p1.total++;
				//ship_char tracks what character was hit
				ship_char = player2_board[row][col];
				//hits updated for logfile
				p1.num_hits++;
				//change board based on current move
				update_board(player2_board, row, col, hit_miss);
				update_board(hidden_board, row, col, hit_miss);
				//check if sunk ship
				sunk = check_sunk(player2_board, ship_char);
				
				//sunk ship
				if (sunk) {
					// Find the ship name based on ship_char and display message
					for (int i = 0; i < 5; i++) {
						if (ship_char == ship_chars[i]) {
							printf("You sunk the %s!\n\n", ship_names[i]);
							break;
						}
					}
				}
				//output to logfile
				output_current_move(outfile, row, col, hit_miss, sunk, current_player, ship_char, ship_names, ship_chars);
				display_board(hidden_board);

				//check winner
				if (is_winner(player2_board, ship_chars)) {
					won_loss = 1;
					break;
				}
				//miss changes to player 2
				if (hit_miss == 0) {
					p1.num_miss++;
					current_player = 2;
				}
				//end of turn
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 2:
				printf("Player 2's Turn:\n");
				
				//computer chooses random shot
				computer_shot(&row, &col);
				hit_miss = check_shot(player1_board, row, col);
				ship_char = player1_board[row][col];
				sunk = check_sunk(player1_board, ship_char);
				//total shots to output
				p2.total++;
				//hits to output
				p2.num_hits++;

				update_board(player1_board, row, col, hit_miss);
				

				
				if (sunk) {
					// Find the ship name based on ship_char and display message
					for (int i = 0; i < 5; i++) {
						if (ship_char == ship_chars[i]) {
							printf("Player 2 sunk your %s!\n\n", ship_names[i]);
							break;
						}
					}
				}
				//logfile
				output_current_move(outfile, row, col, hit_miss, sunk, current_player, ship_char, ship_names, ship_chars);
				display_board(player1_board);
				if (is_winner(player1_board, ship_chars)) {
					won_loss = 1;
					break;
				}
				//miss to output file
				if (hit_miss == 0) {
					p2.num_miss++;
					//switch players on miss
					current_player = 1;
				}
				//end of turn
				printf("\n");
				system("pause");
				system("cls");
				break;
			}

		}
		//win screen
		if (won_loss) {
			printf("\nPlayer %d won!\n\nCheck battleship.log for game statistics.\n\n", current_player);
		}
		//output stats
		output_stats(outfile, p1, p2);
		fclose(outfile);
	return 0;
}

