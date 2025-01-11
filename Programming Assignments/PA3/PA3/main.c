/*
Name: Reid Pace
Class: 121 PA3
Date: September 14, 2024
Lab Section: 15
Description: main folder for a program that processes numbers, corresponding to student records read in
from a file, and writes the required results to an output file
*/

#include "functions.h"

int main() {

	//Pointer for input and output files. 
	FILE* infile = NULL, * outfile = NULL;

	//declaring all variables as ints and doubles respectively
	int student1 = 0, student2 = 0, student3 = 0, student4 = 0, student5 = 0;
	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0, gpa_sum = 0.0, gpa_mean = 0.0;
	int class_standing1 = 0, class_standing2 = 0, class_standing3 = 0, class_standing4 = 0, class_standing5 = 0, class_sum= 0;
	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0, age_sum = 0.0;
	double deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0, stddev = 0.0, variance =0.0;

	//open input.dat for reading and output.dat for writing
	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "w");
	
	//if input is not found or output cannot be written program displays error message. Else when the program works.
	if ((infile == NULL) || (outfile == NULL))
	{
		printf("Either could not open %s for reading or %s for writing!\n", "input.dat", "output.dat");
		printf("Exiting program!\n");
	}
	else {

		//Sucessfully executed statement
		printf("Executed sucessfully. Check output.dat for result.\n");
		
		//using read_integer and read_double to read all student, gpa, and class standing values from the input
		student1 = read_integer(infile); gpa1 = read_double(infile); class_standing1 = read_integer(infile); age1 = read_double(infile);
		student2 = read_integer(infile); gpa2 = read_double(infile); class_standing2 = read_integer(infile); age2 = read_double(infile);
		student3 = read_integer(infile); gpa3 = read_double(infile); class_standing3 = read_integer(infile); age3 = read_double(infile);
		student4 = read_integer(infile); gpa4 = read_double(infile); class_standing4 = read_integer(infile); age4 = read_double(infile);
		student5 = read_integer(infile); gpa5 = read_double(infile); class_standing5 = read_integer(infile); age5 = read_double(infile);

		//using calculate_sum to find the sum for gpa, class standing, and age
		gpa_sum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
		class_sum = calculate_sum(class_standing1, class_standing2, class_standing3, class_standing4, class_standing5);
		age_sum = calculate_sum(age1, age2, age3, age4, age5);

		//printing the mean of gpa, class standing, and age to the output.dat by using print_double
		print_double(outfile, calculate_mean(gpa_sum, 5));
		print_double(outfile, calculate_mean(class_sum, 5));
		print_double(outfile, calculate_mean(age_sum, 5));

		//declares gpa mean using calculate_mean for next statements
		gpa_mean = calculate_mean(gpa_sum, 5);
		// using calculate)_devation to find the deviation of the gpa. uses gpa mean from above.
		deviation1 = calculate_deviation(gpa1, gpa_mean);
		deviation2 = calculate_deviation(gpa2, gpa_mean);
		deviation3 = calculate_deviation(gpa3, gpa_mean);
		deviation4 = calculate_deviation(gpa4, gpa_mean);
		deviation5 = calculate_deviation(gpa5, gpa_mean);

		//using calculate_variance to find the variance from the deviation of the gpas
		variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);
		
		//using calculate_standard_deviation to find standard deviation of the gpas then prints it to the output.dat
		stddev = calculate_standard_deviation(variance);
		print_double(outfile, stddev);

		//prints the minumum and maximum gpas to the output file from the calculatioon find_min and find_max
		print_double(outfile, find_min(gpa1, gpa2, gpa3, gpa4, gpa5));
		print_double(outfile, find_max(gpa1, gpa2, gpa3, gpa4, gpa5));

		//closes the input.dat and output.dat folders
		fclose(infile);
		fclose(outfile);

		return 0;

	}
}

