/* Faryal Alizai G01364057
CS 262, Lab Section 202
Lab 4
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int angle;
	
	printf("Enter the angle:");
	scanf("%d", &angle);
	
	if(angle < 0 || angle > 180) {
		printf("Invalid input");
		return 1;
	}
	
	printf("Hours where the hands are %d degrees apart:\n", angle);
	
	for(int hour =0; hour < 12; hour++) {
		for(int min = 0; min < 60; min += 6) {

			int hourAngle = (hour * 60 + min) * 360 / (12 * 60);
			int minAngle = min * 360 / 60;

			int angleDifference = abs(hourAngle - minAngle);

			if(angleDifference > 180) {
				angleDifference = 360 - angleDifference;
			}

			if(angleDifference == angle && (min == 0 || min == 30)) {
				printf("%02d:00\n", hour);
			}
		}
	}
	if(angle % 90 != 0) {
		printf("There is no hour where the hands are %d degrees apart.\n", angle);
	}
	
	return 0;
}
