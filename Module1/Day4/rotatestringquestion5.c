#include <stdio.h>
#include <string.h>

void rotateStringLeft(char* str, int positions) {
    int len = strlen(str);
    positions = positions % len;

    char temp[positions + 1];
    strncpy(temp, str, positions);
    temp[positions] = '\0';

    memmove(str, str + positions, len - positions + 1);
    strcat(str, temp);
}

void rotateStringRight(char* str, int positions) {
    int len = strlen(str);
    positions = positions % len;

    char temp[positions + 1];
    strncpy(temp, str + len - positions, positions);
    temp[positions] = '\0';

    memmove(str + positions, str, len - positions + 1);
    strncpy(str, temp, positions);
}

int main() {
    char inputString[] = "abcdxyz";
    int positions = 2;

    printf("Input String: %s\n", inputString);
    printf("Positions: %d\n", positions);

    rotateStringLeft(inputString, positions);
    printf("Left Rotation: %s\n", inputString);

    rotateStringRight(inputString, positions);
    printf("Right Rotation: %s\n", inputString);

    return 0;
}