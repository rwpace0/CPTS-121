/*
Name: Reid Pace
Class: 121 PA3
Date: September 14, 2024
Lab Section: 15
Description: source folder for equations and function definition.
*/

#include "functions.h"

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
double read_double(FILE* infile) {

	double value = 0.0;

	fscanf(infile, "%lf", &value);

		return value;
}

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
int read_integer(FILE* infile) {

	int value = 0;

	fscanf(infile, "%d", &value);

		return value;

}

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
double calculate_sum(double number1, double number2, double number3, double number4, double number5) {

	return number1 + number2 + number3 + number4 + number5;

}

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
double calculate_mean(double sum, int number) {

	if (number == 0) {

		return -1.0;

	}

	return sum / number;

}

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
double calculate_deviation(double number, double mean) {

	return number - mean;

}

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
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {

	double variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number; 

	if (number == 0) {

		return -1.0;
}
	else {

		return variance;
	}
}

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
double calculate_standard_deviation(double variance) {

	return sqrt(variance);

}

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
double find_max(double number1, double number2, double number3, double number4, double number5) {

	double max = number1;

	if (number2 > max) max = number2;
	if (number3 > max) max = number3;
	if (number4 > max) max = number4;
	if (number5 > max) max = number5;

	return max;
}

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
double find_min(double number1, double number2, double number3, double number4, double number5) {

	double min = number1; 

	if (number2 < min) min = number2;
	if (number3 < min) min = number3;
	if (number4 < min) min = number4;
	if (number5 < min) min = number5;

	return min;
}

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
void print_double(FILE* outfile, double number) {

	fprintf(outfile, "%.2f\n", number); 

}