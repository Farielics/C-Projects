/*#include "fork.h"


int main()
{
	printf("262$");
}
*/
/* Faryal Alizai G01364057
 * CS 262, Lab Section 202
 * P3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 10000
#define MAX_ARGS 128
#define MAX_HISTORY 100

char* history[MAX_HISTORY];
int history_count = 0;

void display_prompt() {
    printf("262$");
    fflush(stdout);
}

void add_history(const char* command) {
    if (history_count >= MAX_HISTORY) {
        free(history[0]);  // Free the oldest entry if history is full
        memmove(history, history + 1, sizeof(char*) * (MAX_HISTORY - 1));  // Shift all entries
        history_count--;
    }
    history[history_count++] = strdup(command);  // Duplicate and store the command
}

void show_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i, history[i]);
    }
}

void clear_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);  // Free each history entry
        history[i] = NULL;  // Nullify the pointer after freeing
    }
    history_count = 0;  // Reset history count
}

int parse_input(char* input, char** args) {
    int count = 0;
    char* token = strtok(input, " \t\n");
    while (token != NULL) {
        if (count >= MAX_ARGS) {
            fprintf(stderr, "error: too many arguments\n");
            return -1;
        }
        args[count++] = strdup(token);  // Duplicate and store the token
        token = strtok(NULL, " \t\n");
    }
    args[count] = NULL;
    return count;
}

void free_parsed_args(char** args) {
    int i = 0;
    while (args[i] != NULL) {
        free(args[i]);  // Free each argument
        i++;
    }
}

void execute_command(char** args) {
    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL || chdir(args[1]) != 0) {
            perror("cd error");
        }
    } else if (strcmp(args[0], "history") == 0) {
        if (args[1] != NULL && strcmp(args[1], "-c") == 0) {
            clear_history();
        } else {
            show_history();
        }
    } else {
        pid_t pid = fork();
        if (pid == 0) {  // Child process
            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "execvp error: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {  // Forking failed
            perror("fork error");
        } else {
            wait(NULL);  // Wait for child process to finish
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_ARGS + 1];

    while (1) {
        display_prompt();
        if (!fgets(input, sizeof(input), stdin)) {
            break;  // Exit on EOF
        }
        if (input[0] == '\n') {
            continue;  // Skip empty lines
        }
        if (parse_input(input, args) != -1) {
            execute_command(args);
            free_parsed_args(args);
        }
    }

    clear_history();  // Clear history on exit to free all remaining allocated memory
    return 0;
}
