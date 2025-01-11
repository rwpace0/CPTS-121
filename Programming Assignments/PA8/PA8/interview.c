/*
Name: Reid Pace
Class: 121 PA8
Date: November 27, 2024
Lab Section: 15
Description: source file for function definition.
*/
#include "interview.h"

/*************************************************************
* Function:	my_str_n_cat
* Date Created: 11/27/24
* Date Last Modified: 11/28/24
* Description: Appends one string to the end of the other without string.h
* Input parameters: source array, array destination, number of characters
* Returns: the destination array
* Preconditions: Arrays must be initialized
* Postconditions: Appends strings
*************************************************************/
char* my_str_n_cat(const char* source, char *dest, int n) {

	//copy to end of dest
	while (*dest != '\0') {
		dest++;
	}
	for (int i = 0; i < n; i++) {
		//end of source
		if (*source == '\0') {
			break;
		}
		//add source to end of dest
		else {
			*dest = *source;
			dest++;
			source++;
		}
	}
	return dest;

}

/*************************************************************
* Function:	my_str_n_cat
* Date Created: 11/27/24
* Date Last Modified: 11/27/24
* Description: Finds specific integer's index position out of an array of assorted integers
* Input parameters: integer array, size of array, desired number
* Returns: the target index number
* Preconditions: The array must be initialized and there must be a target number
* Postconditions: Finds the target number's index
*************************************************************/
int binary_search(int list[], int n, int target) {
	
	
	int left = 1, right = n;
	int found = 0, mid = 0;
	int targetindex = -1;


	while (!found && left <= right) {

		mid = (left + right) / 2;
		
		if (target == list[mid] ) {
			found = 1;
			targetindex = mid;
		}
		if (target < list[mid]) {

			right = mid - 1;

		}
		if (target > list[mid]) {

			left = mid + 1;

		}

		
	}

	return targetindex;

}

/*************************************************************
* Function:	bubble_sort
* Date Created: 11/27/24
* Date Last Modified: 11/27/24
* Description: Sorts an array of strings
* Input parameters: array to be sorted, number of strings within the array
* Returns: none
* Preconditions: thge array must have strings indexed inside
* Postconditions: Fsorts the strings inside the array
*************************************************************/
void bubble_sort(char* arr[], int strings) {
	//marker u = string
	int u = strings, c = 0; 

	for (int i = 0; i < u; i++) {
		while (u > 1) {

			c = 1;

			while (c < u) {

				if (*arr[c] < *arr[c - 1]) {
					//reversing array
					char* temp = arr[c - 1];
					arr[c - 1] = arr[c];
					arr[c] = temp;

				}
				//marker c goes forward
				c++;
			}
			//u goes backward
			u--;
		}

	}

}

/*************************************************************
* Function:	is_palindrome
* Date Created: 11/29/24
* Date Last Modified: 11/29/24
* Description: Recursively determines if a string of characters is a palindrome
* Input parameters: the string of characters and the length of the string
* Returns: returns itself to determine if the string is a palindrome
* Preconditions: The string must be accessible and length must be known
* Postconditions: Determines if string is a palindrome or not
*************************************************************/
int is_palindrome(char* string, int length) {

	//base case
	if (length <= 1) {
		return 1;
	}

	//remove whitespace
	if (*string == ' ') {
		return is_palindrome(string + 1, length - 1);
	}
	//remove whitespace
	if (string[length - 1] == ' ') {
		return is_palindrome(string, length - 1);
	}

	//if first index of the sring doesnt equal the last then it wont be a palindrome
	if (string[0] != string[length - 1]) {
		return 0;
	}

	//recursive
	return is_palindrome(string + 1, length - 2);
}

/*************************************************************
* Function:	sum_primes
* Date Created: 11/29/24
* Date Last Modified: 11/29/24
* Description: Adds all of the prime numbers that come before a certain prime number
* Input parameters: The prime number
* Returns: returns itself to determine the sum of the numbers
* Preconditions: The prime number must be accessible
* Postconditions: Finds the sum of the prime numbers from 2 to n
*************************************************************/
int sum_primes(int n) {
	//n<2 not allowed
	if (n < 2) return 0;
	//determine if number is prime and return the sum
	if (is_prime(n, 2)) return n + sum_primes(n - 1); 
	//recursive
	return sum_primes(n - 1);
}

/*************************************************************
* Function:	is_prime
* Date Created: 11/29/24
* Date Last Modified: 11/29/24
* Description: Recursively determines if a number is prime
* Input parameters: The prime number and starting number (2)
* Returns: returns itself to determine if the number is prime
* Preconditions: The number must be accessible
* Postconditions: Determines if a number is a prime number
*************************************************************/
int is_prime(int n, int i) {
	//n<2 not allowed
	if (n < 2) return 0; 
	//number is prime
	if (i * i > n) return 1; 
	//not prime
	if (n % i == 0) return 0;
	//recursive
	return is_prime(n, i + 1);

}

/*************************************************************
* Function:	maximum_occurences
* Date Created: 11/29/24
* Date Last Modified: 11/29/24
* Description: Finds the number of times the most used character appears in a string
* Input parameters: the string of characters, struct array for determining the occurrences, pointer for determining the number of times the char appears,pointer for determining what char appeared the most
* Returns: none
* Preconditions: The string holding the chars must be accessible and the struct must be accessible
* Postconditions: Finds the most used char and how many times it was used
*************************************************************/
void maximum_occurrences(char * str, Occurrences arr[], int* i_max, char* c_max) {

	int num_chars = 0, char_i = 0;
	*i_max = 0, * c_max = '\0';
	//initialize array
	for (int i = 0; i < 128; i++) {//i<128, 128 max chars in ascci
		arr[i].num_occurrences = 0;
		arr[i].frequency = 0.0;
	}
	//finding number of specific chars
	for (int i = 0; str[i] != '\0'; i++) {
		char_i = (unsigned char)str[i];
		arr[char_i].num_occurrences++;
		num_chars++;
	}
	//freq
	for (int i = 0; i < 128; i++) {
		if (num_chars > 0) {
			arr[i].frequency = (double)arr[i].num_occurrences / num_chars;//freq calculation
		}
	}
	//max number and max char
	for (int i = 48; i< 128 ; i++) {//i=48, after 48 on ascii is chars

		if (arr[i].num_occurrences > *i_max) {
			
			*i_max = arr[i].num_occurrences;//number of times
			*c_max = (char)i;//char max

		}

	}
	

}
/*************************************************************
* Function:	max_consecutive_integers
* Date Created: 11/29/24
* Date Last Modified: 11/29/24
* Description: finds the longest sequence of ints and their address in a 2D array
* Input parameters: 2D array with ints, row, column, double pointer to the start of the array, pointer to the length of the longest sequence of the same number in the array
* Returns: none
* Preconditions: the array and size must be accessible
* Postconditions: Finds the address of and the number of the longest sequence in the array
*************************************************************/
void max_consecutive_integers(int array[][5], int row, int col, int** start, int* max_length) {
	//start to first index of array
	int *current_start = &array[0][0];
	int current_value = 0, current_length=1, next_row=0, next_col=0;
	*max_length = 0;
	*start = NULL;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//init rows and cols
			current_value = array[i][j];

			//if the col reaches the end go to col in next row
			next_row = (j + 1 == col) ? (i + 1) % row : i;
			next_col = (j + 1 == row) ? 0 : j + 1;

			//found match
			if (array[next_row][next_col] == current_value) {

				current_length++;
				//new match is longer than last one
				if (current_length > *max_length) {

					*max_length = current_length;
					*start = current_start;

				}
			}
			//no new max so restart
			else {
				current_length = 1;
				current_start = &array[next_row][next_col];
			}

		}
	}
}