/*
Name: Reid Pace
Class: 121 PA5
Date: October 19, 2024
Lab Section: 15
Description: main file for executing program.
*/

#include "yahtzee.h"

int main() {
	//decs
	int dice[5], used[2][13] = {{ 0 }}, scores[2] = { 0, 0 }, upper_scores[2] = { 0, 0 };;
	int game_state = 0, num_dice = 5, round = 1, rolls = 0, choice = 0, sum = 0, player = 0, score = 0;
	char rand_key, y_or_n;
	//rand
	srand(time(NULL));

	//main menu
	game_state = print_game_menu();

	//rules
	if (game_state == 1) {

		print_rules();

		game_state = print_game_menu();
	}
	//exit
	if (game_state == 3) {
		printf("\nExiting Prgram.\n\nGoodbye!\n");
		return 0;
	}

	printf("\nStarting game...\n");
	//game starts at round one and stops at round 13
	if (game_state == 2) {
		for (round = 1; round <= 13; round++) {
			for (player = 0; player < 2; player++) {
				rolls = 0;
				//prints player and round
				printf("\nPlayer: %d\nRound: %d\n", player + 1, round);
				printf("\nEnter any key to roll the dice: "); scanf(" %c", &rand_key);
				//rolling dice and rolls increased
				roll_dice(dice);
				display_dice(dice, num_dice);
				rolls++;
				//rolls when the player can still use for combo
				while (rolls <= 2) {

					printf("\nWould you like to use these rolls for a combination (Y/N)? "); scanf(" %c", &y_or_n);
					//player choses to use rolls for combo
					if (y_or_n == 'y' || y_or_n == 'Y') {
						//displays the combo menu and check when used
						display_combo_menu(used[player]);
						scanf("%d", &choice);
						//if combo is used restarts combo menu
						while (option_used(used, choice)) {
							display_combo_menu(used); scanf("%d", &choice);
						}
						//calculate player score based on combo used
						score = calculate_combo(dice, choice);
						//counts combo as used
						used[player][choice - 1] = -1;
						//adds score to player score
						scores[player] += score;
						//calculates upper scores
						if (choice >= 1 && choice <= 6) {
							upper_scores[player] += score;
						//scored 63 points in one round and 35 points extra are added
						if (upper_scores[player] >= 63) {
							printf("\nPlayer %d reached 63 points! Bonus 35 points added!\n", player + 1);
							scores[player] += 35;
						
							upper_scores[player] = -63;
						}
					}
					printf("\nPlayer %d scored %d points!\n", player + 1, score);
					break;

				}
				//reroll dice if selected n
				if (y_or_n == 'n' || y_or_n == 'N') {
					roll_dice(dice);
					reroll_dice(dice);
					display_dice(dice, num_dice);
					rolls++;


				}
			}
				//when rolls = 3 player can not ask to reroll
			if (rolls == 3) {
				//displays the combo menu and check when used
				display_combo_menu(used);
				//if combo is used restarts combo menu
				scanf("%d", &choice);
				while (option_used(used, choice)) {
					display_combo_menu(used); scanf("%d", &choice);
				}
				//calculate player score based on combo used
				score = calculate_combo(dice, choice);
				//counts combo as used
				used[player][choice - 1] = -1;
				//adds score to player score
				scores[player] += score;

				//calculates upper scores
				if (choice >= 1 && choice <= 6) {
					upper_scores[player] += score;
					//scored 63 points in one round and 35 points extra are added
				if (upper_scores[player] >= 63) {
					printf("\nPlayer %d reached 63 points! Bonus 35 points added!\n", player + 1);
					scores[player] += 35;

					upper_scores[player] = -63;
				}
			}
			printf("\nPlayer %d scored %d points!\n", player + 1, score);
			break;
		}
			}
		}
		//game over screen
		printf("\nGame Over!\n");
		printf("Player 1 score: %d\n", scores[0]);
		printf("Player 2 score: %d\n", scores[1]);
		//determines who's score is higher and who wins or tie
		if (scores[0] > scores[1]) {
			printf("Player 1 wins!\n");
		}
		else if (scores[1] > scores[0]) {
			printf("Player 2 wins!\n");
		}
		else {
			printf("It's a tie!\n");
		}
	}

	


	return 0;
}