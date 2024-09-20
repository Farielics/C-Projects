/* Faryal Alizai G01364057
 * CS 262, Section 202
 * Lab 9
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DOB {
    int day;
    int month;
    int year;
} DOB;

typedef struct Employee {
    int ID;
    char FirstName[50];
    char LastName[50];
    DOB birthDate;
    double Salary;
} Employee;

void insertData(Employee** database, int* size);
void updateData(Employee* database, int size);
void searchEmployee(Employee* database, int size);
void printDatabase(Employee* database, int size);
void freeDatabase(Employee* database, int size);

int main() {
    char choice_str[2];
    int size = 3;
    Employee* database = malloc(size * sizeof(Employee));
    
    if (database == NULL) {
        printf("Memory failed.\n");
        return 1;
    }

    char choice;
    
    do {
        printf("\nEnter your Choice:\n");
        printf("'i' - Insert data\n");
        printf("'u' - Update data\n");
        printf("'s' - Search employee\n");
        printf("'p' - Print the database\n");
        printf("'q' - Quit\n");
        
        fgets(choice_str, sizeof(choice_str), stdin);
        choice = choice_str[0];
        
        switch (choice) {
            case 'i':
                insertData(&database, &size);
                break;
            case 'u':
                updateData(database, size);
                break;
            case 's':
                searchEmployee(database, size);
                break;
            case 'p':
                printDatabase(database, size);
                break;
            case 'q':
                freeDatabase(database, size);
                printf("Quitting...\n");
                break;
            default:
                printf("%c is not a valid choice. Please try again.\n", choice);
        }
    } while (choice != 'q');
    
    return 0;
}

void insertData(Employee** database, int* size) {
    
}

void updateData(Employee* database, int size) {
    
}

void searchEmployee(Employee* database, int size) {

}

void printDatabase(Employee* database, int size) {

}

void freeDatabase(Employee* database, int size) {
    free(database);
}
