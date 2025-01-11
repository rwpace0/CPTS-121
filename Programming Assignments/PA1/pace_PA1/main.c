/*
Programmer: Reid Pace
Class: CptS 121, Fall 2024; Lab Section 15
Programming Assignment: PA1
Date: September 2, 2024
Description: The program prompts the user for inputs to the
equations and evaluate them based on the inputs.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 

#include <math.h>

#define G 6.67e-11 //G in scientific notation in problem 4

#define PI 3.14159 //pi as constant in problem 2


//	1.  Newton’s Second Law of Motion
int main() {

	{
		float mass, acceleration, force;

		//prompt showing equation for better visual
		printf("Newton's Second Law: F=M*A\n");

		//prompt mass, get mass from  user
		printf("Enter Mass for Newton's Second Law (floating-point): ");
		scanf("%f", &mass);

		//prompt acceleration, get acceleration from user
		printf("Enter acceleration (floating-point): ");
		scanf("%f", &acceleration);

		//Newton's equation to get force
		force = mass * acceleration;

		//output result
		printf("The force is: %f\n", force);
	}







//	2. Volume of a cylinder



	{
		float radius, height, volume_cylinder;

		//prompt showing equation for better visual \n for spacing
		printf("\nVolume of a cylinder: V = PI * R^2 * H\n");

		//prompt radius, get radius from  user from scanf
		printf("Enter radius of cylinder: ");
		scanf("%f", &radius);

		//prompt height, get height from  user
		printf("Enter height: ");
		scanf("%f", &height);

		//equation to get vol, with pow() to use the power of 2
		volume_cylinder = PI * pow(radius, 2) * height;

		//output result
		printf("The volume of the cylinder is: %f\n", volume_cylinder);
	}



	//	3. Character encoding


	{
		char plaintext_character, encoded_character;

		int offset;
		
		//prompt showing equation for better visual
		printf("\nCharacter encoding: encoded_character = offset + plaintext_character\n");

		//prompt user for lowercase letter, get letter from user
		printf("Enter lowercase letter: ");
		scanf(" %c", &plaintext_character);

		//prompt user for offset number, get number from user
		printf("Enter offset number: ");
		scanf("%d", &offset);

		//equation to get encoded character. 'a' and 'A' denotes as a character and not a string. 
		encoded_character = offset + (plaintext_character - 'a') +
			'A';

		//output result
		printf("Encoded character: %c\n", encoded_character);
	}
	

//4. Gravity

	{
		double mass1, mass2, distance, force;

		//prompt showing equation for better visual
		printf("\nGravity: F=G*M*m/D^2\n");

		//prompts mass1, gets mass1 from user
		printf("Enter the first mass: ");
		scanf("%lf", &mass1);

		//prompts masss2, getsmass 2 from user
		printf("Enter the second mass: ");
		scanf("%lf", &mass2);

		//prompts distance, gets distance from user
		printf("Enter the distance: ");
		scanf("%lf", &distance);

		//equation to get force
		force = G * mass1 * mass2 / pow(distance, 2);

		//output result, %e allows very small numbers and %lf does not work with such small numbers
		printf("The force is: %e\n", force);

	}


//5. Fahrenheit to Celsius conversion

	{

		double fahrenheit, celsius;

		//prompt showing equation for better visual
		printf("\nFahrenheit to Celsius: C = (F - 32) / (9 / 5)\n");

		//prompts fahrenheit, gets fahrenheit from user
		printf("Enter temperature in fahrenheit: ");
		scanf("%lf", &fahrenheit);

		//equation. (float) for integers to floating point for accuracy.
		celsius = (fahrenheit - 32) / ((float)9 / (float)5);

		//output result
		printf("The temperature in Celsius is: %lf\n", celsius);

	}



//6. Distance between two points



	{

		double distance, x1, x2, y1, y2;

		//prompt showing equation for better visual
		printf("\nThe distance between two points: DD=sqrt(x1-x2)^2 + (y1-y2)^2\n");

		//prompt coordinates for x1 and y1, gets x1 and y1 from user
		printf("Enter the coordinates of (x1 y1): ");
		scanf("%lf %lf", &x1, &y1);

		//prompt coordinates for x2 and y2, gets x2 and y2 from user
		printf("Enter the coordinates of (x2 y2): ");
		scanf("%lf %lf", &x2, &y2);

		//equation sqrt for square root  
		distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		//output result
		printf("The distance between the two point is: %f\n", distance);

		//The coridinates must be in form of: x x and not x, x.

	}

	//7. General equation:

	{

		double y, z, x;
		int a;

		//prompt showing equation for better visual
		printf("\ny = (89 / 27) - z * x + a / (a % 2)\n");

		//prompt user for x, gets x from user
		printf("Enter x: ");
		scanf("%lf", &x);

		//prompt user for z, gets z from user
		printf("Enter z: ");
		scanf("%lf", &z);

		//prompt user for a, gets a from user
		printf("Enter a (integer only): ");
		scanf("%d", &a);

		//equation (float) converts integer to floating-point
		y = ((float)89 / (float)27) - z * x + a / (a % 2);

		//output result
		printf("y is: %f\n", y);

		return 0;
	}
}