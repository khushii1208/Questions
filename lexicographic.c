#include <stdio.h>
#include <string.h>

void removeConsecutivePairs(char *str) {
    int len = strlen(str);
    int i, j;

    while (1) {
        int pairFound = 0;

        for (i = 0; i < len - 1; i++) {
            if (str[i] + 1 == str[i + 1]) {
                // Remove the consecutive pair by shifting the rest of the string
                for (j = i; j < len - 2; j++) {
                    str[j] = str[j + 2];
                }
                len -= 2;
                pairFound = 1;
                break;
            }
        }

        if (!pairFound) {
            break;
        }
    }

    str[len] = '\0'; // Null-terminate the string
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if it's read by fgets
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }

    removeConsecutivePairs(str);
    printf("Resultant string: %s\n", str);

    return 0;
}

