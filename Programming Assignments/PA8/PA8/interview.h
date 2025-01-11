/*
Name: Reid Pace
Class: 121 PA8
Date: November 27, 2024
Lab Section: 15
Description: header file for function declaration.
*/

#ifndef INTERVIEW_H
#define INTERVIEW_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char* my_str_n_cat(const char* source, char* dest, int n);

int binary_search(int list[], int n, int target);

void bubble_sort(char* arr[], int strings);

int is_palindrome(char* string, int length);

typedef struct occurrences
{
	int num_occurrences;
	double frequency;

} Occurrences;

void maximum_occurrences(char* str, Occurrences arr[], int* i_max, char* c_max);

void max_consecutive_integers(int** array, int row, int col, int** start, int* max_length);

#endif