#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputString[] = "5,2,7,8";
    int integers[4];
    int i = 0;

    char *token = strtok(inputString, ",");
    while (token != NULL) {
        integers[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // Print the converted integers
    for (i = 0; i < 4; i++) {
        printf("Integer %d: %d\n", i+1, integers[i]);
    }

    return 0;
}