#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS  64

char input[MAX_INPUT];
char *args[MAX_ARGS];
int arg_count;

void print_prompt() {
    printf("myShell> ");
    fflush(stdout);
}

void read_input() {
    if (fgets(input, sizeof(input), stdin) == NULL) {
        // User pressed Ctrl+D
        printf("\n");
        exit(0);
    }
    // Remove newline from end of input
    input[strcspn(input, "\n")] = '\0';
}

void parse_input() {
    arg_count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL; // Required for exec
}

int main() {
    while (1) {
        print_prompt();
        read_input();

        // If user pressed Enter without typing anything
        if (input[0] == '\0') continue;

        parse_input();

        // Temporarily print args to verify parser works
        for (int i = 0; i < arg_count; i++) {
            printf("arg[%d] = %s\n", i, args[i]);
        }
    }
    return 0;
}
