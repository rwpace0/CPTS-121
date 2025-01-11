/*
Name: Reid Pace
Class: 121 PA2
Date: September 6, 2024
Lab Section: 15
Description: header file containing all function declarations and donstant definitions.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define G 6.67e-11 //G in scientific notation in problem 4

#define PI 3.14159 //pi as constant in problem 2

//	1. 
/*
Function: calculate_newtons_2nd_law
Date Created: 9/10/24
Date Last Modified: 9/10/24
Description: This function calculates the force from F=M*A
Input Parameters: The mass and acceleration.
Returns: The force from Newtons 2nd law as a floating point value.
Preconditions: The mass and acceleration must be accessible.
Postconiditions: This function displays the force from Newton's 2nd law.
*/
double calculate_newtons_2nd_law(double mass, double acceleration);

//	2. 
/*
Function: calculate_volume_cylinder
Date Created: 9/10/24
Date Last Modified: 9/10/24
Description: This function calculates the volume of a cylinder from V=PI * R^2 * height;
Input Parameters: The radius and height
Returns: The volume of a cylinder in floating point value.
Preconditions: The radius, height, and PI must be accessible.
Postconiditions: This function displays the volume using the equation.
*/
double calculate_volume_cylinder(double radius, double height); 

//	3.
/*
Function: perform_character_encoding
Date Created : 9/10/24
Date Last Modified : 9/ 10/24
Description : This function displays an ecoded character from return offset + (plaintext_character - 'a') + 'A'
Input Parameters : lowercase letter, offset number.
Returns : The encoded character.
Preconditions : The plain text character, and offset number must be accessible.
Postconiditions : This function displays the encoded charcter.
*/
char perform_character_encoding(char plaintext_character, int offset);

//	4. 
/*
Function: calculate_gravity
Date Created: 9/10/24
Date Last Modified: 9/10/24
Description: This function calculates the force of gravity from force = G * m1 * m2 / D^2
Input Parameters: Mass 1, Mass 2, and Distance.
Returns: The force of gravity in floating-point value.
Preconditions: The gravity constant, mass 1, mass 2, and distance must be accessible.
Postconiditions: This function displays the force of gravity using the equation.
*/
double calculate_gravity(double mass1, double mass2, double distance);

//	5.
/*
Function: calculate_celsius
Date Created: 9/10/24
Date Last Modified: 9/10/24
Description: This function calculates the converstion of degrees fahrenheit to degrees celsius using: Celsius = (fahrenheit - 32) / 9 / 5);
Input Parameters: Degrees in fahrenheit.
Returns: The degrees in celsius in floating point value.
Preconditions: Fahrenheit must be accessible.
Postconiditions: This function displays the degrees in celsius using the equation.
*/
double calculate_celsius(double fahrenheit);

//	6. 
/*
Function: calculate_distance
Date Created: 9/10/24
Date Last Modified: 9/10/24
Description: This function calculates the distance between two points from distance = sqrt((x1 - x2)^2 + (y1 - y2)^2;
Input Parameters: The two coordinate pairs of (x1 y1) and (x2 y2).
Returns: The distance between the two points in floating-point value.
Preconditions: x1, y1, x2, y2 must be accessible.
Postconiditions: This function displays the distance between the two points using the equation.
*/
double calculate_distance(double x1, double y1, double x2, double y2);

//	7.
/*
Function: calculate_y
Date Created: 9/10/24
Date Last Modified: 9/10/24
Description: This function calculates y from y = 89 / 27 - z * x + a / (a % 2)
Input Parameters: z, x, and a.
Returns: y in floating-point value.
Preconditions: z, x and a must be accessible.
Postconiditions: This function displays y using the equation.
*/
double calculate_y(double z, double x, int a);