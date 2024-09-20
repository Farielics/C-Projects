/* Faryal Alizai G01364057
 * CS 262, Lab Section 202
 * Lab 5
*/
#include <stdio.h>
#include <string.h>

#define SIZE 20
#define WSIZE 50

char toUpper(char alphabet) {
    if (alphabet >= 'a' && alphabet <= 'z') {
        return alphabet - ('a' - 'A');
    }
    return alphabet;
}

void getAdjective(char letter, char adjective[]) {
	letter = toUpper(letter);

	while (!(letter >= 'A' && letter <= 'Z')) {
        printf("Error! Please enter a valid input.\n");
        printf("Enter the first letter of your last name [A-Z]: ");

        char input[2];
        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c", &letter);

        letter = toUpper(letter);
    }

    if (letter >= 'A' && letter <= 'E') {
        strcat(adjective, "The Awesome");
    } else if (letter >= 'F' && letter <= 'J') {
        strcat(adjective, "The Funny");
    } else if (letter >= 'K' && letter <= 'O') {
        strcat(adjective, "The Dangerous");
    } else if (letter >= 'P' && letter <= 'T') {
        strcat(adjective, "The Lovely");
    } else if (letter >= 'U' && letter <= 'Z') {
        strcat(adjective, "The Electrifying");
    }
}

void getSubject(char month[], char subject[]) {
	int validMonth = 0;

    	while (!validMonth) {
		//printf("Enter your birth month [JAN|FEB|...|DEC]: ");
		char input[5];
		fgets(input, sizeof(input), stdin);
		sscanf(input, "%s", month);
		
		input[strcspn(input, "\n")] = '\0';

        	for (int i = 0; i < 3; i++) {
            		month[i] = toUpper(month[i]);
		}
		

        	/*if (strcmp(month, "JAN") >= 0 && strcmp(month, "MAR") <= 0) {
            		strcat(subject, "Biography");
            		validMonth = 1;
        	} else if (strcmp(month, "APR") >= 0 && strcmp(month, "JUN") <= 0) {
            		strcat(subject, "Revenge");
            		validMonth = 1;
		} else if (strcmp(month, "JUL") >= 0 && strcmp(month, "SEP") <= 0) {
            		strcat(subject, "Battle");
            		validMonth = 1;
        	} else if (strcmp(month, "OCT") >= 0 && strcmp(month, "DEC") <= 0) {
            		strcat(subject, "Fairy Tale");
            		validMonth = 1;
		}
		if (!validMonth) {
            		printf("Error! Please enter a valid input.\n");
			//char input[5];
			//fgets(input, sizeof(input), stdin);
			//sscanf(input, "%s", month); */
		if (strcmp(month, "JAN") == 0) {
            		strcat(subject, "Biography");
            		validMonth = 1;
        	} else if (strcmp(month, "FEB") == 0) {
            		strcat(subject, "Biography"); 
            		validMonth = 1;
        	} else if (strcmp(month, "MAR") == 0) {
            		strcat(subject, "Biography");
            		validMonth = 1;
        	} else if (strcmp(month, "APR") == 0) {
            		strcat(subject, "Revenge");
            		validMonth = 1;
        	} else if (strcmp(month, "MAY") == 0) {
            		strcat(subject, "Revenge"); 
            		validMonth = 1;
        	} else if (strcmp(month, "JUN") == 0) {
            		strcat(subject, "Revenge");
            		validMonth = 1;
        	} else if (strcmp(month, "JUL") == 0) {
            		strcat(subject, "Battle");
            		validMonth = 1;
        	} else if (strcmp(month, "AUG") == 0) {
            		strcat(subject, "Battle");
            		validMonth = 1;
        	} else if (strcmp(month, "SEP") == 0) {
            		strcat(subject, "Battle");
            		validMonth = 1;
        	} else if (strcmp(month, "OCT") == 0) {
            		strcat(subject, "Fairy Tale");
            		validMonth = 1;
        	} else if (strcmp(month, "NOV") == 0) {
            		strcat(subject, "Fairy Tale");
            		validMonth = 1;
        	} else if (strcmp(month, "DEC") == 0) {
            		strcat(subject, "Fairy Tale");
            		validMonth = 1;
        	} else {
            		printf("Error! Please enter a valid input.\n");
		}
	}
}

void getComplement(int digit, char complement[]) {
	int validDigit = 0;

    	while (!validDigit) {
		//printf("Enter the last digit of your cellphone [0-9]: ");
        	char input[5];

        	fgets(input, sizeof(input), stdin);
        	sscanf(input, "%d", &digit);

        	if (digit >= 0 && digit <= 9) {
            		validDigit = 1;
        	} else {
            		printf("Error! Please enter a valid input.\n");
		}
	}

    switch (digit) {
        case 0:
        case 1:
            strcat(complement, "of a Movie Star");
            break;
        case 2:
        case 3:
            strcat(complement, "of a Hero");
            break;
        case 4:
        case 5:
            strcat(complement, "of a Jedi");
            break;
        case 6:
        case 7:
            strcat(complement, "of an Ogre");
            break;
        case 8:
        case 9:
            strcat(complement, "of a Dreamer");
            break;
    }
}

int main() {
	char userAdjective[SIZE] = ""; 
	char userSubject[SIZE] = "";
	char userComplement[SIZE] = "";
    	char movieTitle[WSIZE] = "";

    	char lastNameLetter;
    	char birthMonth[4];
    	int cellphoneDigit;

    	printf("Welcome to the Title Movie creator program.\n");

    	printf("Enter the first letter of your last name [A-Z]: ");
    	char lastNameInput[2];
    	fgets(lastNameInput, sizeof(lastNameInput), stdin);
    	sscanf(lastNameInput, " %c", &lastNameLetter);
    	getAdjective(lastNameLetter, userAdjective);

	
    	printf("Enter your birth month [JAN|FEB|...|DEC]: ");
    	char monthInput[4];
    	fgets(monthInput, sizeof(monthInput), stdin);
    	sscanf(monthInput, "%s", birthMonth);
    	getSubject(birthMonth, userSubject);

    	printf("Enter the last digit of your cellphone [0-9]: ");
    	char digitInput[5];
    	fgets(digitInput, sizeof(digitInput), stdin);
    	sscanf(digitInput, "%d", &cellphoneDigit);
    	getComplement(cellphoneDigit, userComplement);

    	strcat(movieTitle, userAdjective);
    	strcat(movieTitle, " ");
    	strcat(movieTitle, userSubject);
    	strcat(movieTitle, " ");
    	strcat(movieTitle, userComplement);

    	printf("The Movie Title for your life is: %s\n", movieTitle);

    	char quitChoice;
    	printf("Do you want to quit [Y|y]? ");
    	char choiceInput[2];
    	fgets(choiceInput, sizeof(choiceInput), stdin);
    	sscanf(choiceInput, " %c", &quitChoice);

    	if (quitChoice == 'Y' || quitChoice == 'y') {
        	printf("Goodbye, thank you for creating a movie title. \n");
    	} else {
        	printf("Make another movie title\n");
		main();
	}

    	return 0;
}
