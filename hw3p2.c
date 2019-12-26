#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
 Author: John Cody
 Date created: 02/04/2018
 Brief description of the program: This program takes 6 coefficients and uses them along with some initial guess values to find the roots. 
input(s): the 6 coefficients
output(s): the equation, the roots, and how many iterations it took to find the roots 
brief description or relationship between inputs and outputs: the roots are calculated using the Newton-Rapson method. It is basically a loop that 
works to get the x value closer to the root by subtracting y / dy. So the process is set x equal to one of the initial values, then evaluate y, if 
it is close enought to zero then stop and output that x is a root, otherwise evaluate dy using x, and subtract y/dy from x, then start over and 
evaluate y again. 
*/

int main(void) {

	double c5 = 0.0, c4 = 0.0, c3 = 0.0, c2 = 0.0, c1 = 0.0, c0 = 0.0;     // Initialize the coefficients
	double x = 0.0, y = 0.0, dy = 0.0;                                     // Initialize the important variables
	int i = 0, counter = 0;  // Initialize the loop variables
	int j = 0;
	
	printf("This program is to find one root of 5th - order polynomial using Newton - Rhapson method.\n"); 
	printf("\tc5x ^ 5 + c4x ^ 4 + c3x ^ 3 + c2x ^ 2 + c1x + c0\n");               // Describing the program to the user 
	printf("Enter polynomial coefficients : c5 c4 c3 c2 c1 c0 in this order : ");
	scanf("%lf%lf%lf%lf%lf%lf", &c5, &c4, &c3, &c2, &c1, &c0);                // Getting the coefficients from the user

	printf("\nYour polynomial is ");
	if (c5 != 0) {                         // This part looks really complex, but it isn't. 
		printf("%.1fx ^ 5", c5);}          // It just tests to make sure that the variable is not equal to zero. 
	if ((c5 != 0) && ((c4 != 0) || (c3 != 0) || (c2 != 0) || (c1 != 0) || (c0 != 0))) {  // If it is, then it doesn't get added to the equation. 
		printf(" + ");}                   //Also, if the variable isn't added, then the " + " isn't added either. 
	if (c4 != 0) {
		printf("%.1fx ^ 4", c4);}
	if ((c4 != 0) && ((c3 != 0) || (c2 != 0) || (c1 != 0) || (c0 != 0))) {
		printf(" + ");}
	if (c3 != 0) {
		printf("%.1fx ^ 3", c3);}
	if ((c3 != 0) && ((c2 != 0) || (c1 != 0) || (c0 != 0))) {
		printf(" + ");}
	if (c2 != 0) {
		printf("%.1fx ^ 2", c2);}
	if ((c2 != 0) && ((c1 != 0) || (c0 != 0))) {
		printf(" + ");}
	if (c1 != 0) {
		printf("%.1fx", c1);}
	if ((c1 != 0) && (c0 != 0)) {
		printf(" + ");}
	if (c0 != 0) {
		printf("%.1f ", c0);}
	printf("\n");

	
	double initialVal[7] = { -10000, -1000, -100, 0, 100, 1000, 10000};      // Setting up the initial variable array that the loop will cycle through. 

	for (i = 0; i < 7; i++) {      // The outer for loop
		x = initialVal[i];         // Sets x equal to one of the initial values, depending on how many iterations the for loop has gone through
		y = 100.0;                 // Sets y equal to any number that is not within .00001 of zero            

		j = 0;
		while (j < 500) {
			j++;
			y = c5*pow(x, 5.0) + c4*pow(x, 4.0) + c3*pow(x, 3.0) + c2*pow(x, 2.0) + c1*x + c0;  // Calculates y(x)
			dy = 5.0 * c5*pow(x, 4.0) + 4.0 * c4*pow(x, 3.0) + 3.0 * c3*pow(x, 2.0) + 2.0 * c2*x + c1; 
			
			if (fabs(y) < 0.00001) {
				break;   
			}
			x = x - y / dy;
		
		}
		if (fabs(y) < 0.00001) {
			printf("\nOne of the roots of this polynomial is %.5lf\n", x);       // Outputs the root that was found
			printf("Starting from an initial guess of x = %.1f, this answer was obtained in %d iterations.\n", initialVal[i], j-1);
		}                                   // Outputs additional information
		else {
			printf("\nThe initial guess of x = %.1lf failed to converge to a solution; roots may be complex\n", initialVal[i]);
		}        // When the counter passes 499, the loop gives up as it cannot determine a solution

	}
	
	return 0;    // Fin
}