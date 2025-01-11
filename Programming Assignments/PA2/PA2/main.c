/*
Name: Reid Pace
Class: 121 PA2
Date: September 6, 2024
Lab Section: 15
Description: A modular equation evaluator.
*/

#include "equations.h"


//	1.  Newton’s Second Law of Motion
int main() {

	{
		double mass=0.0, acceleration=0.0, force=0.0;

		//prompt showing equation for better visual
		printf("Newton's Second Law: F=M*A\n");

		//prompt mass and acceleration, get mass and acceleration from  user
		printf("Enter mass and acceleration: ");
		scanf("%lf%lf", &mass, &acceleration);

		//force function
		force = calculate_newtons_2nd_law(mass, acceleration); 

		//output result
		printf("The force is: %.2lf\n", force);
	}

	//	2. Volume of a cylinder

	{
		double radius=0.0, height=0.0, volume_cylinder=0.0;

		//prompt showing equation for better visual \n for spacing
		printf("\nVolume of a cylinder: V = PI * R^2 * H\n");

		//prompt radius and height, get radius and height from  user from scanf
		printf("Enter radius and height of cylinder: ");
		scanf("%lf%lf", &radius, &height);

		//cylinder volume function
		volume_cylinder = calculate_volume_cylinder(radius, height);

		//output result
		printf("The volume of the cylinder is: %.2lf\n", volume_cylinder);
	}

	//	3. Character encoding

	{
		char plaintext_character=0.0, encoded_character=0.0;

		int offset=0;

		//prompt showing equation for better visual
		printf("\nCharacter encoding: encoded_character = offset + plaintext_character\n");

		//prompt user for lowercase letter, get letter from user
		printf("Enter lowercase letter and offset number: ");
		scanf(" %c %d", &plaintext_character, &offset);

		//encoded character function
		encoded_character = perform_character_encoding(plaintext_character, offset);

		//output result
		printf("Encoded character: %c\n", encoded_character);
	}
		
	//4. Gravity

	{
		double mass1=0.0, mass2=0.0, distance=0.0, force=0.0;

		//prompt showing equation for better visual
		printf("\nGravity: F=G*M*m/D^2\n");

		//prompts mass1, mass2, distance. gets mass1, mass2, distance from user
		printf("Enter the first mass, second mass, and distance: ");
		scanf("%lf%lf%lf", &mass1, &mass2, &distance);

		//force of gravity function
		force = calculate_gravity(mass1, mass2, distance);

		//output result, %e allows very small numbers and %lf does not work with such small numbers
		printf("The force is: %.13e\n", force);

	}

	//5. Fahrenheit to Celsius conversion

	{

		double fahrenheit=0.0, celsius=0.0;

		//prompt showing equation for better visual
		printf("\nFahrenheit to Celsius: C = (F - 32) / (9 / 5)\n");

		//prompts fahrenheit, gets fahrenheit from user
		printf("Enter temperature in fahrenheit: ");
		scanf("%lf", &fahrenheit);

		//celsius function 
		celsius = calculate_celsius(fahrenheit);

		//output result
		printf("The temperature in Celsius is: %.2lf\n", celsius);

	}

	//6. Distance between two points

	{

		double distance=0.0, x1=0.0, x2=0.0, y1=0.0, y2=0.0;

		//prompt showing equation for better visual
		printf("\nThe distance between two points: DD=sqrt(x1-x2)^2 + (y1-y2)^2\n");

		//prompt coordinates for x1 and y1, gets x1 and y1 from user
		printf("Enter the coordinates of (x1 y1): ");
		scanf("%lf %lf", &x1, &y1);

		//prompt coordinates for x2 and y2, gets x2 and y2 from user
		printf("Enter the coordinates of (x2 y2): ");
		scanf("%lf %lf", &x2, &y2);

		//dsitance function
		distance = calculate_distance(x1, y1, x2, y2);

		//output result
		printf("The distance between the two point is: %.2lf\n", distance);

		//The coridinates must be in form of: x x and not x, x.

	}

	//7. General equation:

	{

		double y=0.0, z=0.0, x=0.0;
		int a=0;

		//prompt showing equation for better visual
		printf("\ny = (89 / 27) - z * x + a / (a % 2)\n");

		//prompt user for x, z, a gets x,z a from user
		printf("Enter X, Z, A: ");
		scanf("%lf%lf%d", &x, &z, &a);

		//y function
		y = calculate_y(z, x, a);

		//output result
		printf("y is: %.2lf\n", y);

		return 0;
	}
}