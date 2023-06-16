#include <stdio.h>

void main() {
    int score;
    char grade;

    printf("Enter the score: ");
    scanf("%d", &score);

    if (score >= 90 && score <= 100) {
        grade = 'A';
    } else if (score >= 75 && score <= 89) {
        grade = 'B';
    } else if (score >= 60 && score <= 74) {
        grade = 'C';
    } else if (score >= 50 && score <= 59) {
        grade = 'D';
    } else if (score >= 0 && score <= 49) {
        grade = 'F';
    } else {
        printf("Invalid score entered.\n");
        return 0;
    }

    printf("The grade is: %c\n", grade);

    return 0;
}