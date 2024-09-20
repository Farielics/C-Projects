/* Faryal Alizai G01364057
 * CS 262 Lab Section 202
 * P2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTHOFSEQ 34
//legneth of each sequence
#define LENGTHOFHEADER 9
//legnth of the header
#define ROWSOFDATA 4
//length of rows
#define COLSOFDATA 5
//length of coloums
#define LENGTHOFCOLOR 10
//length of color names
//constants


int *create_sequence(FILE *input);
int *create_header(int *sequence);
int **create_data(int *sequence);
int validate_sequence(int *sequence, int **data);
int validate_header(int *header);
int validate_data(int **data);
int validate_row(int **data, int row);
int validate_column(int **data, int col);
int compute_id(int **data, int valid_sequence);
char *get_color(int id);
void output_sequence(FILE *output, int *sequence, int sequence_number);
void output_header(FILE *output, int *header);
void output_data(FILE *output, int **data);
void output_id(FILE *output, int id);
void output_color(FILE *output, char *color);
void free_arrays(int *sequence, int *header, int **data);
void free_data(int **data);
//function prototypes


int main(int argc, char *argv[]) {
//main function
    if (argc != 2) {
        printf("Error: You must put the input filename: ./p2_username_labsection <input_file>\n");
        return 1;
	//checks for the correct num of arguments
    }

    FILE *input = fopen(argv[1], "r");
	//opens the inputed file
    if (input == NULL) {
        printf("Error: Can't open %s.\n", argv[1]);
		//if null prints error message
        return 2;
    }

    char output_filename[256];
    strncpy(output_filename, argv[1], sizeof(output_filename) - 5);
    strncat(output_filename, ".out", 5);
	//creates the output files name
    FILE *output = fopen(output_filename, "w");
	//opens the output file
    if (output == NULL) {
        printf("Error: Can't open %s.\n", output_filename);
	//if null prints this error message
        fclose(input);
		//closes the file
        return 3;
    }

    int sequence_number = 0;
	int *sequence;
	//initalizes the seq nums
    while ((sequence = create_sequence(input)) != NULL) {
        sequence_number++;
		//loops the seqences in the input file
		
        output_sequence(output, sequence, sequence_number);
		//outputs the sequence information tot he output file

        int *header = create_header(sequence);
		//creates the arrays header
        output_header(output, header);
		//outputs the headers information to the output file

        int **data = create_data(sequence);
		//creates the arrays data
        output_data(output, data);
		//outputs data to the output file

        int valid_sequence = validate_sequence(sequence, data);
		//checks the seq and the data
        int id = compute_id(data, valid_sequence);
		//searches for the ID
        output_id(output, id);
		//outputs the ID

        char *color = get_color(id);
		//gets a color based on the ID
        output_color(output, color);
		//outputs the color into the output file
        free(color);
		//frees the memory for color
		
        free_arrays(sequence, header, data);
		//frees the memory for seq, header, and data
    }

    fclose(input);
	//closes the input file
    fclose(output);
	//closes the output file

    printf("Decoding Complete. Written to file %s.\n", output_filename);
	//prints this if everything works as needed
    return 0;
}

int *create_sequence(FILE *input) {
    int *sequence = malloc(LENGTHOFSEQ * sizeof(int));
	//this function is used to create seq array
    if (sequence == NULL) {
        printf("Error: No more memory.\n");
		//if null print this error message
        exit(4);
    }

    for (int i = 0; i < LENGTHOFSEQ; i++) {
        if (fscanf(input, "%d", &sequence[i]) != 1) {
            free(sequence);
            return NULL;
	//reads inteers from input file
        }
    }

    return sequence;
}

int *create_header(int *sequence) {
    int *header = malloc(LENGTHOFHEADER * sizeof(int));
	//function used to create the array header
    if (header == NULL) {
        printf("Error: No more memory.\n");
		//if null then pring this error
        exit(4);
    }

    for (int i = 0; i < LENGTHOFHEADER; i++) {
        header[i] = sequence[i];
		//copies the first 9 nums in the seq-header
    }
    return header;
}

int **create_data(int *sequence) {
    int **data = malloc(ROWSOFDATA * sizeof(int *));
	//function to create array data
    if (data == NULL) {
        printf("Error: No more memory.\n");
		//if null then print out this error
        exit(4);
    }

    for (int i = 0; i < ROWSOFDATA; i++) {
        data[i] = malloc(COLSOFDATA * sizeof(int));
		//initatlies the array data and copies the data from the seq
        if (data[i] == NULL) {
            printf("Error: No more memory.\n");
		//if null then print out this error
            exit(4);
        }
        for (int j = 0; j < COLSOFDATA; j++) {
            data[i][j] = sequence[LENGTHOFHEADER + i * COLSOFDATA + j];
        }
    }

    return data;
}

int validate_sequence(int *sequence, int **data) {
//function to check the seq 
    return validate_header(sequence) && validate_data(data);
}

int validate_header(int *header) {
    for (int i = 0; i < LENGTHOFHEADER; i++) {
        if (header[i] != 1) {
            return 0;
	//function to check the header
        }
    }
    return 1;
}

int validate_data(int **data) {
    for (int i = 0; i < ROWSOFDATA; i++) {
	//function to check data rows + coloums
        if (!validate_row(data, i)) {
            return 0;
        }
    }
    for (int j = 0; j < COLSOFDATA; j++) {
        if (!validate_column(data, j)) {
            return 0;
        }
    }
    return 1;
}

int validate_row(int **data, int row) {
    int sum = 0;
    for (int i = 0; i < COLSOFDATA; i++) {
        sum += data[row][i];
    }
    return (sum % 2 == 0);
	//function to check the rows
}

int validate_column(int **data, int col) {
    int sum = 0;
    for (int i = 0; i < ROWSOFDATA; i++) {
        sum += data[i][col];
    }
    return (sum % 2 == 0);
	//function to check the columns
}


int compute_id(int **data, int valid_sequence) {
    if (!valid_sequence) {
        return -1;
    }

    int id = 0;
    int position = 15;
    for (int i = 0; i < ROWSOFDATA; i++) {
		for (int j = 0; j < COLSOFDATA; j++) {
			if(!((i == 3) || (j == 4))) { 
				id += data[i][j] * (1 << position);
				position = position -1;
				//function to solve for the data 
			}
        }
    }
    return id;
}

char *get_color(int id) {
    char *color = malloc(LENGTHOFCOLOR * sizeof(char));
	//function to get color
    if (color == NULL) {
        printf("Error: No more memory.\n");
		//if null then print this error
        exit(4);
    }

    switch (id) {
        case 3072:
            strncpy(color, "White", LENGTHOFCOLOR);
            break;
        case 3076:
            strncpy(color, "Green", LENGTHOFCOLOR);
            break;
        case 3083:
            strncpy(color, "Yellow", LENGTHOFCOLOR);
            break;
        case 3085:
            strncpy(color, "Red", LENGTHOFCOLOR);
            break;
        case 3086:
            strncpy(color, "Blue", LENGTHOFCOLOR);
            break;
        case 3087:
            strncpy(color, "Purple", LENGTHOFCOLOR);
            break;
        case 3123:
            strncpy(color, "Black", LENGTHOFCOLOR);
            break;
        default:
            strncpy(color, "Invalid", LENGTHOFCOLOR);
		//picks color based on ID
    }

    return color;
	//returns a color based on id
}

void output_sequence(FILE *output, int *sequence, int sequence_number) {
    fprintf(output, "Sequence %d:", sequence_number);
    for (int i = 0; i < LENGTHOFSEQ; i++) {
        fprintf(output, " %d", sequence[i]);
    }
    fprintf(output, "\n");
	//function to output the details
}

void output_header(FILE *output, int *header) {
    fprintf(output, "Header:");
    for (int i = 0; i < LENGTHOFHEADER; i++) {
        fprintf(output, " %d", header[i]);
    }
    fprintf(output, "\n");
	//function to output the details of the header
}

void output_data(FILE *output, int **data) {
    fprintf(output, "Data:\n");
    for (int i = 0; i < ROWSOFDATA; i++) {
        for (int j = 0; j < COLSOFDATA; j++) {
            fprintf(output, "%d ", data[i][j]);
        }
        fprintf(output, "\n");
		//function to output the details of the data
    }
}

void output_id(FILE *output, int id) {
    fprintf(output, "Value: %d\n", id);
	//function to print the ID
}

void output_color(FILE *output, char *color) {
    fprintf(output, "Color: %s\n", color);
	//function to print the color
}

void free_arrays(int *sequence, int *header, int **data) {
    free(sequence);
    free(header);
    free_data(data);
	//function to free memory 
}

void free_data(int **data) {
    for (int i = 0; i < ROWSOFDATA; i++) {
        free(data[i]);
    }
    free(data);
	//function to free memory
}
