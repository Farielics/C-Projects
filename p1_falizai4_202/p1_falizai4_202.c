/* Faryal Alizai G01264057
 * CS 262, Lab Section 202
 * P1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYERNAMELENGTH 25
#define SOUPLENGTH 10


int menu();
int is_valid_option(int options);
void score_status(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC);
void mixed_soup(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC);
void alphabet_soup(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC);
void number_soup(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC);
//declares the functions

int main() {
    srand(time(NULL));
	//creates random nums

    printf("**********************************\n");
    printf("* Welcome to Character Soup *\n");
    printf("**********************************\n");
	//prints the welcome message

    char pName[PLAYERNAMELENGTH];
    printf("Player's name: ");
    fgets(pName, sizeof(pName), stdin);
    pName[strcspn(pName, "\n")] = '\0';
	//prompts the user to input players name/name

    int matchPointsP = 0;
    int roundPointsP = 0;
    int matchPointsC = 0;
    int roundPointsC = 0;
	//initializes variables for the points of player and computer

    int options;
    do {
        options = menu();
		//shows menu

        if (is_valid_option(options)) {
		//sees if input is valid
            switch (options) {
                case 1:
                    mixed_soup(pName, matchPointsP, roundPointsP, matchPointsC, roundPointsC);
                    break;
                case 2:
                    alphabet_soup(pName, matchPointsP, roundPointsP, matchPointsC, roundPointsC);
                    break;
                case 3:
                    number_soup(pName, matchPointsP, roundPointsP, matchPointsC, roundPointsC);
                    break;
                case 4:
                    printf("Thank you for playing! Hope to see you again!\n");
                    break;
				//executables that match with the game modes
            }
        } else {
            printf("Option %d is not valid!\n", options);
			//if not any of those then prints that its invalid
        }

    } while (options != 4);

    return 0;
}
//Main game loop

int menu() {
    int options;
    printf("1. Mixed soup\n");
    printf("2. Alphabet soup\n");
    printf("3. Number soup\n");
    printf("4. Quit\n");
    printf("Select an option: ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &options);

    return options;
}
//Function to show the menu

int is_valid_option(int options) {
    return (options >= 1 && options <= 4);
//function thats used to check if the input entered if valid or not
}

void score_status(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC) {
    printf("%s, match points: %d round points: %d\n", pName, matchPointsP, roundPointsP);
    printf("Computer, match points: %d round points: %d\n", matchPointsC, roundPointsC);
//function used to show the score status
}

void mixed_soup(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC) {
//function of mixed soup game
	printf("****************************\n");
    printf("* Mixed soup *\n");
    printf("****************************\n");
	//prints the title of the game mode

    int playedrounds;
    for (playedrounds = 1; playedrounds <= 10; ++playedrounds) {
	//loops for 10 rounds
        char pSoup[SOUPLENGTH + 1];
        char cSoup[SOUPLENGTH + 1];
		//creates random soups for the computer and player

        for (int i = 0; i < SOUPLENGTH; ++i) {
            pSoup[i] = rand() % (126 - 33 + 1) + 33;
            cSoup[i] = rand() % (126 - 33 + 1) + 33;
			//gives a random ASCII character
        }

        pSoup[SOUPLENGTH] = '\0';
        cSoup[SOUPLENGTH] = '\0';
		//keeps them as vvalid strings

        printf("Round: %d/10\n", playedrounds);
        printf("Soup: \"%s\"\n", pSoup);
        printf("************************************\n");

        printf("%s's soup: \"%s\"\n", pName, pSoup);
        printf("Computer's soup: \"%s\"\n", cSoup);
		//shows the round info

        int countsmatch = 0;
        for (int i = 0; i < SOUPLENGTH; ++i) {
            if (pSoup[i] == cSoup[i]) {
                countsmatch++;
		//updates the points by checking matches
            }
        }

        roundPointsP = countsmatch;
        roundPointsC = countsmatch;
        matchPointsP += roundPointsP;
        matchPointsC += roundPointsC;
		//updates the points

        score_status(pName, matchPointsP, roundPointsP, matchPointsC, roundPointsC);
		//shows the updated score status

        if (playedrounds < 10) {
            printf("[Continue]\n");
            getchar();
		//waits for user to put in an input
        }
    }

    printf("Game Over\n");
    printf("%s, score: %d\nmatch points: %d round points: %d\n", pName,
           matchPointsP, matchPointsP, roundPointsP);
    printf("Computer, score: %d\nmatch points: %d round points: %d\n", matchPointsC,
           matchPointsC, roundPointsC);
	//prints game over info

    if (matchPointsP > matchPointsC) {
        printf("%s won this game.\n", pName);
    } else if (matchPointsP < matchPointsC) {
        printf("Computer won this game.\n");
    } else {
        printf("The game ended in a tie.\n");
	//determines if theres a winner/ if theres a tie
    }

    printf("[Return to menu]\n");
	//waits for user to got back to menu
}

void alphabet_soup(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC) {
    printf("******************************\n");
    printf("* Alphabet soup *\n");
    printf("******************************\n");
	//shows title for the Alphabet soup game mode

    int playedrounds;
    for (playedrounds = 1; playedrounds <= 10; ++playedrounds) {
	//loops through 10 times
        char pSoup[SOUPLENGTH + 1];
        char cSoup[SOUPLENGTH + 1];

        for (int i = 0; i < SOUPLENGTH; ++i) {
            pSoup[i] = rand() % 26 + 'a';
            cSoup[i] = rand() % 26 + 'a';
		//creates random soup for the player n computer
        }

        pSoup[SOUPLENGTH] = '\0';
        cSoup[SOUPLENGTH] = '\0';

        printf("Round: %d/10\n", playedrounds);
        printf("Soup: \"%s\"\n", pSoup);
        printf("************************************\n");
        printf("%s's soup: \"%s\"\n", pName, pSoup);
        printf("Computer's soup: \"%s\"\n", cSoup);
		//shows the round info

        int countsmatch = 0;
        for (int i = 0; i < SOUPLENGTH; ++i) {
            if (pSoup[i] == cSoup[i]) {
                countsmatch++;
		//checks the matches and updates points
            }
        }

        roundPointsP = countsmatch;
        roundPointsC = countsmatch;
        matchPointsP += countsmatch;
        matchPointsC += countsmatch;
		//updates the points

        score_status(pName, matchPointsP, roundPointsP, matchPointsC, roundPointsC);
		//shows updated score status

        if (playedrounds < 10) {
            printf("[Continue]\n");
            getchar();
		//shows message for each round until all 10 are over
        }
    }

    printf("Game Over\n");
    printf("%s, score: %d\nmatch points: %d round points: %d\n", pName,
           matchPointsP, matchPointsP, roundPointsP);
    printf("Computer, score: %d\nmatch points: %d round points: %d\n", matchPointsC,
           matchPointsC, roundPointsC);
	//Shows the game over info

    if (matchPointsP > matchPointsC) {
        printf("%s won this game.\n", pName);
    } else if (matchPointsP < matchPointsC) {
        printf("Computer won this game.\n");
    } else {
        printf("The game ended in a tie.\n");
	//sees if theres a winner or if its a tie
    }

    printf("[Return to menu]\n");
}

void number_soup(char pName[PLAYERNAMELENGTH], int matchPointsP, int roundPointsP, int matchPointsC, int roundPointsC) {
    printf("******************************\n");
    printf("* Number soup *\n");
    printf("******************************\n");
	//shows the title for Number SOup game

    int playedrounds;
    for (playedrounds = 1; playedrounds <= 10; ++playedrounds) {
	//loops 10 times
        char pSoup[SOUPLENGTH + 1];
        char cSoup[SOUPLENGTH + 1];

        for (int i = 0; i < SOUPLENGTH; ++i) {
            pSoup[i] = rand() % 10 + '0';
            cSoup[i] = rand() % 10 + '0';
		//creates random soups for the comp and player
        }

        pSoup[SOUPLENGTH] = '\0';
        cSoup[SOUPLENGTH] = '\0';

        printf("Round: %d/10\n", playedrounds);
        printf("Soup: \"%s\"\n", pSoup);
        printf("************************************\n");
        printf("%s's soup: \"%s\"\n", pName, pSoup);
        printf("Computer's soup: \"%s\"\n", cSoup);
		//shows the rounds info

        int countsmatch = 0;
        for (int i = 0; i < SOUPLENGTH; ++i) {
            if (pSoup[i] == cSoup[i]) {
                countsmatch++;
		//checks for any updates on the match and then updates points
            }
        }

        roundPointsP = countsmatch;
        roundPointsC = countsmatch;
        matchPointsP += countsmatch;
        matchPointsC += countsmatch;
		//updates points

        score_status(pName, matchPointsP, roundPointsP, matchPointsC, roundPointsC);
		//shows the new score status

        if (playedrounds < 10) {
            printf("[Continue]\n");
            getchar();
		//shows until the last round
        }
    }

    printf("Game Over\n");
    printf("%s, score: %d\nmatch points: %d round points: %d\n", pName,
           matchPointsP, matchPointsP, roundPointsP);
    printf("Computer, score: %d\nmatch points: %d round points: %d\n", matchPointsC,
           matchPointsC, roundPointsC);
	//prints game over info

    if (matchPointsP > matchPointsC) {
        printf("%s won this game.\n", pName);
    } else if (matchPointsP < matchPointsC) {
        printf("Computer won this game.\n");
    } else {
        printf("The game ended in a tie.\n");
	//checks to see if theres a winner or if it s a tie
    }

    printf("[Return to menu]\n");
	//shows menu message
}
