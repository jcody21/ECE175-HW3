#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
 Author: John Cody
 Date created: 02/03/2018
 Brief description of the program: This is an optimization program that asks how much gold a user wants to spend and then calculates how much armor
 and health the user should buy to maximize their effective health score. 
 input(s): the amount of gold that the user wishes to spend. 
 output(s): the amount of heath and armor that the user should buy and what effective health score that will give them. 
 brief description or relationship between inputs and outputs: The program takes the amount of gold, checks to ensure that it is positive, and then runs 
 amount of gold through a loop to check the effective health at every amount of armor. This every time the loop finds a score higher than the one that it 
 currently has, it updates all of the max values to these new values. 
*/

int main(void) {

	int gold = 0;
	int armor = 0;               // Just your average variables. 
	int health = 0; 
	double eHealth = 0.0;

	int maxArmor = 0;
	int maxHealth = 0;            // These are your max variables. These are what allow the loop to save the highest values. 
	double maxEHealth = 0.0; 


	printf("How much gold do you wish to spend ? ");     // Getting the user input. 
	scanf("%d", &gold);

	while(gold <= 0) {
		printf("\nYou have no gold to spend.\n");          // Checking to make sure that the number given is positive. 
		printf("Please enter in a valid amount of gold to spend.\n");   // If not the user is told that they need to try again. 
		
		printf("\nHow much gold do you wish to spend ? ");     // Getting the user input. 
		scanf("%d", &gold);
	}

	for (armor = 0; armor < (gold / 18); armor++) {         // Looping through the different amounts of armor that the user could buy. 
		health = (gold - 18 * armor) / 2;                   // Setting the amount of health based on the amount of gold and armor.
		eHealth = health*(100 + pow((armor*1.0), 2.0)) / 100;    // Calculating the amount of effective health based on the health and armor. 

		if (eHealth > maxEHealth) {       // Comparing the previous high effective health value and the new effective health value.
			maxArmor = armor;             // If the new value is larger than the old value, then all of the max values are updated. 
			maxHealth = health;           // This is the trick that lets the program save the highest values. 
			maxEHealth = eHealth;
		}
	}

	if (gold % 2 > 0) {     // These if else statements just determine wheather or not to include the "save gold" statement in the final output. 
		printf("\nFor %d gold you should buy %d Health, and %d Armor for an effective health score of %.3lf\n", gold - 1, maxHealth, maxArmor, maxEHealth);
		printf("You should save 1 gold for the next round\n");   // ^ This is where the max values are finally output. 
	}
	else {
		printf("\nFor %d gold you should buy %d Health, and %d Armor for an effective health score of %.3lf\n", gold, maxHealth, maxArmor, maxEHealth);
	}

	return 0;
}