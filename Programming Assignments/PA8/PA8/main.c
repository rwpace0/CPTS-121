/*
Name: Reid Pace
Class: 121 PA8
Date: November 27, 2024
Lab Section: 15
Description: main file for program execution.
*/
#include "interview.h"

int main() {

	//(1) string
	int n = 5;
	char dest[100] = "hello";
	const char source[100] = "world";

	my_str_n_cat(source, dest, n);

	printf("%s\n\n", dest);

	//(2) binary search 
	int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("Index of 5: %d\n\n", binary_search(list, 9, 5));
	
	//(3) bubble sort 
	char* bubble[] = { "three", "two", "one" };

	printf("Before sorting:\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", bubble[i]);
	}
	bubble_sort(bubble, 3);
	printf("\nAfter sorting:\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", bubble[i]);
	}

	//(4) palindrome 
	char string[] = { "race car" };
	printf("\n");

	if (is_palindrome(string, 8)) {
		printf("%s is a palindrome", &string);
	}
	if (!is_palindrome(string, 8)) {
		printf("%s is not a palindrome", &string);
	}

	//(5) prime number 
	int prime = 17;
	printf("\n\nPrime number: %d. Sum of prime from 2: %d", prime, sum_primes(prime));
	
	//(6) maximum occurrences 
	Occurrences arr[128];
	int* i_max = 0;
	char* c_max = 0;

	maximum_occurrences("hello world", arr, &i_max, &c_max);

	
	printf("\n\n%c had the most uses with %d",c_max, i_max);

	//(7) max consecutive integers
	int data[4][5] = {
		{-5, 6, 0, 2, 2},
		{1, 2, 2, 2, 9},
		{3, 2, 3, 3, 2},
		{1, -8, 3, 7, -2}
	};
	int* start = NULL;
	int max_length = 0;

	max_consecutive_integers(data, 4, 5, &start, &max_length);

	printf("\n\nStart address: %p\nMax consecutive integer length: %d\n", start, max_length);

	return 0;
}