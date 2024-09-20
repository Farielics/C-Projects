/* Faryal Alizai G01364057
 * CS 262, Lab section 202
 * Lab 10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxName 50

typedef struct Node {
    char name[maxName];
    int dob;
    int mob;
    int yob;
    struct Node *next;
} Data;

int insertNode(Data **firstData, Data data);
Data *deleteNode(Data **firstData, Data data);
void printList(Data *firstData);
void sortList(Data **firstData);
int isValidDate(int day, int month, int year);

int main() {
    Data *head = NULL;
    int choice;
    int friendCount = 0;
    char input[100];

    do {
        printf("************ Friends birthday list ************\n");
        printf("Friends in the list: %d\n", friendCount);
        printf("(1) Insert data\n");
        printf("(2) Delete Data\n");
        printf("(3) Print list\n");
        printf("(4) Quit\n");
        printf("**********************************************\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid input. Enter a number between 1 and 4.\n");
            continue;
        }

        switch(choice) {
            case 1: {
                Data newData;
                printf("*** Insert data ***\n");
                printf("Name: ");
                fgets(newData.name, maxName, stdin);
                newData.name[strcspn(newData.name, "\n")] = '\0';
                printf("Month of birth: ");
                fgets(input, sizeof(input), stdin);
                if (sscanf(input, "%d", &newData.mob) != 1 || newData.mob < 1 || newData.mob > 12) {
                    printf("Invalid month. Enter a number between 1 and 12.\n");
                    continue;
                }
                printf("Day of birth: ");
                fgets(input, sizeof(input), stdin);
                if (sscanf(input, "%d", &newData.dob) != 1 || newData.dob < 1 || newData.dob > 31) {
                    printf("Invalid day. Enter a number between 1 and 31.\n");
                    continue;
                }
                printf("Year of birth: ");
                fgets(input, sizeof(input), stdin);
                if (sscanf(input, "%d", &newData.yob) != 1 || newData.yob < 1900 || newData.yob > 2024) {
                    printf("Invalid year. Enter a number between 1900 and 2024.\n");
                    continue;
                }
                if (!insertNode(&head, newData)) {
                    printf("Insertion failed.\n");
                } else {
                    friendCount++;
                }
                break;
            }
            case 2: {
                if (head == NULL) {
                    printf("Nothing to delete.\n");
                    break;
                }
                Data searchData;
                printf("*** Delete data ***\n");
                printf("Name: ");
                fgets(searchData.name, maxName, stdin);
                searchData.name[strcspn(searchData.name, "\n")] = '\0';
                printf("Month of birth: ");
                fgets(input, sizeof(input), stdin);
                if (sscanf(input, "%d", &searchData.mob) != 1 || searchData.mob < 1 || searchData.mob > 12) {
                    printf("Invalid month. Enter a number between 1 and 12.\n");
                    continue;
                }
                printf("Day of birth: ");
                fgets(input, sizeof(input), stdin);
                if (sscanf(input, "%d", &searchData.dob) != 1 || searchData.dob < 1 || searchData.dob > 31) {
                    printf("Invalid day. Enter a number between 1 and 31.\n");
                    continue;
                }
                printf("Year of birth: ");
                fgets(input, sizeof(input), stdin);
                if (sscanf(input, "%d", &searchData.yob) != 1 || searchData.yob < 1900 || searchData.yob > 2024) {
                    printf("Invalid year. Enter a number between 1900 and 2024.\n");
                    continue;
                }
                if (deleteNode(&head, searchData) != NULL) {
                    printf("Friend deleted successfully.\n");
                    friendCount--;
                } else {
                    printf("################ Data Does not exist ###############\n");
                }
                break;
            }
            case 3:
                printList(head);
                break;
            case 4:
                while (head != NULL) {
                    Data *temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Memory free successfully!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

int insertNode(Data **firstData, Data data) {
    Data *current = *firstData;
    Data *prev = NULL;

    while (current != NULL) {
        if (strncmp(current->name, data.name, maxName) == 0) {
            return 0;
        }
        prev = current;
        current = current->next;
    }

    Data *newNode = (Data *)malloc(sizeof(Data));
    if (newNode == NULL) {
        fprintf(stderr, "Memory failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, data.name, maxName - 1);
    newNode->name[maxName - 1] = '\0';
    newNode->dob = data.dob;
    newNode->mob = data.mob;
    newNode->yob = data.yob;
    newNode->next = NULL;

    if (prev == NULL) {
        *firstData = newNode;
    } else {
        prev->next = newNode;
    }

    return 1;
}

Data *deleteNode(Data **firstData, Data data) {
    Data *current = *firstData;
    Data *prev = NULL;

    while (current != NULL) {
        if (strncmp(current->name, data.name, maxName) == 0 && current->dob == data.dob &&
            current->mob == data.mob && current->yob == data.yob) {
            Data *deletedData = (Data *)malloc(sizeof(Data));
            if (deletedData == NULL) {
                fprintf(stderr, "Memory failed.\n");
                exit(EXIT_FAILURE);
            }
            strncpy(deletedData->name, current->name, maxName - 1);
            deletedData->name[maxName - 1] = '\0';
            deletedData->dob = current->dob;
            deletedData->mob = current->mob;
            deletedData->yob = current->yob;
            deletedData->next = NULL;

            if (prev == NULL) {
                *firstData = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return deletedData;
        }
        prev = current;
        current = current->next;
    }

    return NULL;
}

void sortList(Data **firstData) {
    if (*firstData == NULL || (*firstData)->next == NULL) {
        return;
    }

    Data *current;
    Data *nextNode;
    int swapped;

    do {
        swapped = 0;
        current = *firstData;

        while (current->next != NULL) {
            if (current->yob > current->next->yob ||
                (current->yob == current->next->yob && (current->mob > current->next->mob ||
                                                         (current->mob == current->next->mob && current->dob >
                                                                                                    current->next->dob)))) {
                Data *temp = current;
                nextNode = current->next;
                current->next = nextNode->next;
                nextNode->next = temp;

                if (temp == *firstData) {
                    *firstData = nextNode;
                } else {
                    Data *prev = *firstData;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = nextNode;
                }

                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while (swapped);
}

void printList(Data *firstData) {
    if (firstData == NULL) {
        printf("Empty list.\n");
        return;
    }

    sortList(&firstData);

    printf("************ List content ************\n");
    while (firstData != NULL) {
        printf("%02d/%02d/%04d %s\n", firstData->mob, firstData->dob, firstData->yob, firstData->name);
        firstData = firstData->next;
    }
    printf("****************************************\n");
}

int isValidDate(int day, int month, int year) {
    if (year < 1900 || year > 2024 || month < 1 || month > 12 || day < 1) {
        return 0;
    }

    int daysInMonth;
    switch(month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
    }

    if (day > daysInMonth) {
        return 0;
    }

    return 1;
}
