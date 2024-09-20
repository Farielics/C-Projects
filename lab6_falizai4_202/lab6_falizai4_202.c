/* Faryal Alizai GG0136407
 * CS 262, Lab Section 202
 * Lab 6
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArray(int *numArray, int arrayLength);
void ShuffleArray(int *numArray, int arrayLength);
int compare(const void *a, const void *b);
int getMemory(int **numArray, int N);

int main(int argc, char *argv[]) {
    if (argc != 3) {

        printf(" %s Enter <seed> <arraySize>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    srand(seed);

    int N = atoi(argv[2]);

    if (N < 2 || N > 500) {
        printf("Error: Array size must be between 2-500\n");
        return 1;
    }

    int *numArray;
    if (!getMemory(&numArray, N)) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    printf("Generating lists of %d numbers\n", N);

    for (int i = 0; i < 10; i++) {
        InitArray(numArray, N);

        printf("Starting array: ");
        for (int j = 0; j < N; j++) printf("%d ", numArray[j]);
        printf("\n");

        ShuffleArray(numArray, N);

        printf("Mixed array: ");
        for (int j = 0; j < N; j++) printf("%d ", numArray[j]);
        printf("\n");

        qsort(numArray, N, sizeof(int), compare);

        printf("Sorted arrays in descending order: ");
        for (int j = 0; j < N; j++) printf("%d ", numArray[j]);
        printf("\n");
    }

    free(numArray);

    return 0;
}

int getMemory(int **numArray, int N) {
    *numArray = malloc(sizeof(int) * N);
    if (*numArray == NULL) {
        printf("Error allocating memory!\n");
        return 0;
    }
    return 1;
}

void InitArray(int *numArray, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) numArray[i] = i + 1;
}

void ShuffleArray(int *numArray, int arrayLength) {
    for (int i = arrayLength - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numArray[i];
        numArray[i] = numArray[j];
        numArray[j] = temp;
    }
}

int compare(const void *a, const void *b) {
    int numA = *((int*)a);
    int numB = *((int*)b);

    if (numA < numB) return 1;
    else if (numA > numB) return -1;
    else return 0;
}
