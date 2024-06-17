#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char input[1000];
    char *words[100];
    int count = 0;

    // Read the input
    printf("Enter a pipe-separated sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if it exists
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Tokenize the input string based on '|'
    char *token = strtok(input, "|");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, "|");
    }

    // Sort the words using qsort
    qsort(words, count, sizeof(char *), compare);

    // Print the sorted words
    for (int i = 0; i < count; i++) {
        printf("%s | ", words[i]);
    }

    return 0;
}

