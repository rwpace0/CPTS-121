/*
Name: Reid Pace
Class: 121 PA3
Date: September 14, 2024
Lab Section: 15
Description: header file for function declarations.
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*************************************************************
* Function:	read_double
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function scans the floating-point values in the input file.
* Input parameters: All floating point values into the input.dat folder.
* Returns: The scans for floating point values in the input folder.
* Preconditions: The floating point values and the input folder must be accessible
* Postconditions: This function reads input.dat for floating point values
*************************************************************/
double read_double(FILE* infile);

/*************************************************************
* Function:	read_integer
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function scans the integer values in the input file.
* Input parameters: All integer values into the input.dat folder.
* Returns: This scans for integers in the input folder.
* The integers and the input folder must be accessible
* Postconditions: This function reads input.dat for integers
*************************************************************/
int read_integer(FILE* infile);

/*************************************************************
* Function: calculate_sum
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function calcuates the sum of the numbers for gpa, student, and age.
* Input parameters: Number 1 - Number 5
* Returns: The sum of the numbers as a floating point value
* Preconditions: The number variables must be accessible
* Postconditions: The function displays the sum of the numbers to the ouput.dat
*************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

/*************************************************************
* Function:	calculate_mean
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function calculates the mean of the numbers by sum/number. if statement for a divide by 0 error if number = 0.
* Input parameters: Sum of numbers and amount of numbers.
* Returns: The mean as a floating point value
* Preconditions: The sum and number must be accessible.
* Postconditions: The function displays the mean o the output
*************************************************************/
double calculate_mean(double sum, int number);

/*************************************************************
* Function:	calculate_deviation
* Date Created:  9/14/24
* Date Last Modified:  9/14/24
* Description: This function calculates the deviation from numbers - mean.
* Input parameters: The amount of numbers and the mean of them
* Returns: The deviation as a floating point value
* Preconditions: The amount of numbers and mean must be accessible
* Postconditions: This displays the deviation to the output
*************************************************************/
double calculate_deviation(double number, double mean);

/*************************************************************
* Function:	calculate_variance
* Date Created:  9/14/24
* Date Last Modified:  9/14/24
* Description: This function calculates the variance from ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 + (deviation4)^2 + (deviation5)^2) / number. if statement for a divide by 0 error if number = 0.
* Input parameters: Each deviation from the numbers
* Returns: The variance in floating point value
* Preconditions: The deviations must be accessible
* Postconditions: This funtion displays variance to the ouptut
*************************************************************/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

/*************************************************************
* Function: calculate_standard_deviation
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function calculates the standard deviation from sqrt(variance)
* Input parameters: Variance
* Returns: Standard deviation in floating point value
* Preconditions: The variance and input folder must be accessible
* Postconditions: The function will display the standard deviation to the output
*************************************************************/
double calculate_standard_deviation(double variance);

/*************************************************************
* Function:	find_max
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function calculates the max of the numbers. It uses > and if statements to determine what number is greatest.
* Input parameters: The numbers of each value
* Returns: The max of the numbers as a floating point value
* Preconditions: The numbers must be accessible
* Postconditions: This displays the max to the output
*************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5);

/*************************************************************
* Function:	find_min
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function calculates the min of the numbers. It uses < and if statements to determine what number is least.
* Input parameters: The numbers of each value
* Returns: The min of the numbers as a floating point value
* Preconditions: The numbers must be accessible
* Postconditions: This displays the minimum to the output
*************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5);

/*************************************************************
* Function: print_double
* Date Created: 9/14/24
* Date Last Modified: 9/14/24
* Description: This function scans values to the output.dat
* Input parameters: All values
* Returns: None due to void
* Preconditions: Numbers from input.dat must be accessible
* Postconditions: This scans the output
*************************************************************/
void print_double(FILE* outfile, double number);



//end functions.h
#endif