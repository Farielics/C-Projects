/* Faryal Alizai G01364057
 *
 * CS 262, Section 202
 * Lab 7
 */

#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 100
//defines the max legnth for a line in the input file
#define NAME_LENGTH 50
//defines the max length for a name
#define COURSE_LENGTH 10
//defines the max length for a course title

int main(int argc, char *argv[]) {
//main function
    if (argc != 3) {
	//checks how many arguments are provided and if they're correct
        printf("Error: Use: %s <input_file> <output_file>\n", argv[0]);
        //prints an error message if arguments are not correct
		return 1;
		//returns 1 to show error
    }

    FILE *input_file = fopen(argv[1], "r");
	//open file for reading
    if (input_file == NULL) {
	//looks to see if the file doesnt open
        printf("Error: Input file not opening.\n");
		//prints an error message
        return 1;
		//returns 1 to show error
    }

    FILE *output_file = fopen(argv[2], "w");
	//open the output file to write
    if (output_file == NULL) {
	//checks to see if the output file opens
        printf("Error: Output file not opening.\n");
		//prints an error message if output file doesn't open
        fclose(input_file);
		//closes the input file
        return 1;
		//returns 1 to show error
    }

    int rows;
    if (fscanf(input_file, "%d", &rows) != 1) {
	//reads the numver of rows
        printf("Error: can't read number of rows.\n");
		//prints error if reading fails
        fclose(input_file);
		//closes the input file
        fclose(output_file);
		//closes the outpuft fiel
        return 1;
		//returns 1 to show error
    }

    char line[LINE_LENGTH];
    fgets(line, sizeof(line), input_file); 
	//ingores the rest of first line within the input file

    fprintf(output_file, "name                     Gnum       grade   course      credits semester\n");
	//writes out the categories
	
    int Gnum, semester, credits;
    char name[NAME_LENGTH], course[COURSE_LENGTH];
    float grade;
	//decares variables to store data

    for (int i = 0; i < rows; i++) {
	//loops through each row
        if (fgets(line, sizeof(line), input_file) == NULL) {
		//reads one line at a time
            printf("Error: Input file not readable.\n");
			//shows error message if reading fails
            fclose(input_file);
			//closes the input file
            fclose(output_file);
			//closes the output file
            return 1;
			//returns 1 to show error
        }

        if (sscanf(line, "%d %49[^,], %d %s %d %f", &Gnum, name, &semester, course, &credits, &grade) != 6) {
        //parses using sscanf
			printf("Error: Input file not parsing.\n");
			//shows error message if parsing fails
            fclose(input_file);
			//close input file
            fclose(output_file);
			//close output file
            return 1;
			//return 1 to show error
        }

        fprintf(output_file, "%-25s %-10d %-8.2f %-10s %-3d %3d\n", name, Gnum, grade, course, credits, semester);
		//formats the output file
    }

    fclose(input_file);
	//closes the input file
    fclose(output_file);
	//closes the output file

    printf("Congrats, proccesing data has been completed.\n");
	//shows a message to show that procces was successful

    return 0;
	//returns 0 when theres no errors
}
