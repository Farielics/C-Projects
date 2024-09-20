/*
 * Faryal Alizai G01364057
 * CS 262, Lab Section 202
 * Lab2
*/

#include <stdio.h>
#include <math.h>

#define BSA1 0.007184
#define BSA2 0.425
#define BSA3 0.725

int main() {
	char buffer[10];

	float h;
	printf("Please enter the height\n");
	fgets(buffer, 10, stdin);
	sscanf(buffer, "%f", &h);

	float w;
	printf("Please enter the weight\n");
	fgets(buffer, 10, stdin);
	sscanf(buffer, "%f", &w);

	double BSA = BSA1 * pow(w, BSA2) * pow(h, BSA3);

	printf("The Height is: %.1f cms\n", h);
	printf("The Weight is: %1.f kgs\n", w);
	printf("BSA: %.4f meter square\n", BSA);
}
