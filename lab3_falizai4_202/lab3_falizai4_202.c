/*
 Faryal Alizai G
 CS 262, Lab Section 202
 Lab 3
 */

#include <stdio.h>
#include <string.h>

char menuOption();
char getCharValue();
int getNumValue();
int checkNumValue(int userValue);
void printLine(int N, char C);
void printSquare(int N, char C);
void printRectangle(int N, char C);
void printTriangle(int N, char C);
void menu();

int main() {
	char option;
	char charValue = '\0';
	int numValue = 0;

	void printLine(int N, char C);
	void printSquare(int N, char C);
	void printRectangle(int N, char C);
	void printTriangle(int n, char C);

	do {
		menu();
		option = menuOption();
		
		switch(option) {
			
		case 'C':
		case 'c':
			printf("Enter/Change Character:\n ");
			charValue = getCharValue();
			break;
		
		case 'N':
		case 'n':
			printf("Enter/Change Number:\n ");
			numValue = getNumValue();
			printf("Enter a number between 1 and 15:\n ");
			numValue = checkNumValue(numValue);
			break;

		case 'L':
		case 'l':
			printLine(numValue, charValue);
			break;

		case 'S':
		case 's':
			printSquare(numValue, charValue);
			break;

		case 'R':
		case 'r':
			printRectangle(numValue, charValue);
			break;

		case 'T':
		case 't':
			printTriangle(numValue, charValue);
			break;

		case 'Q':
		case 'q':
			printf("Quitting the program\n");
			break;

		default:
		printf("Invalid Choice\n");
		}
	}
	while(option != 'Q' && option != 'q');
	return 0;
}

void menu() {

	printf("Menu\n");
	printf("C/c: Enter/Change Character\n");
	printf("N/n: Enter/Chance Number\n");
	printf("L/l: Print Line\n");
	printf("S/s: Print Square\n");
	printf("R/r: Print Rectangle\n");
	printf("T/t: Print Triangle\n");
	printf("Q/q: Quit Program\n");
	printf("Enter input:\n");
}
char menuOption() {
	char valueString[15];
	char option;

	do {
		fgets(valueString, sizeof(valueString), stdin);
		sscanf(valueString, "%c", &option);

		if ((option >= 'A' && option <= 'Z') || (option >= 'a' && option <= 'z')) {
			return option;
		} else {
			printf("Invalid choice\n");
		}
	} while(option != 'Q' && option != 'q');
	return option;
}

char getCharValue() {
	char character;
	char valueChar[15];

	fgets(valueChar, sizeof(valueChar), stdin);
	sscanf(valueChar, "%c", &character);

	return character;
}
int getNumValue() {
	int number;
	char valueChar[15];
	
	fgets(valueChar, sizeof(valueChar), stdin);
	sscanf(valueChar, "%d", &number);
	
	return number;
}
int checkNumValue(int userValue) {
	while(userValue <0 || userValue > 16){
		printf("Enter a number between 1 and 15:\n ");
		char valueChar[15];
		
		fgets(valueChar, sizeof(valueChar), stdin);
		sscanf(valueChar, "%d", &userValue);
	}
	return userValue;
}

void printLine(int N, char C) {
	for(int i = 0; i <N; ++i) {
		printf("%c\n", C);
	}
}

void printSquare(int N, char C) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j <N; ++j) {
			printf("%c", C);
		}
		printf("\n");
	}
}

void printRectangle(int N, char C) {
	int width = N + 5;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < width; ++j) {
			printf("%c", C);
		}
		printf("\n");
	}
}

void printTriangle(int N, char C) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j <= i; ++j) {
			printf("%c", C);
		}
		printf("\n");
	}
}

