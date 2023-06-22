#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringToStructArray(const char *inputString, int numStudents, struct Student *students) {
    const char *delimiter = " ";
    char *token;
    char *inputCopy = strdup(inputString); // Create a copy of the input string

    token = strtok(inputCopy, delimiter);

    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        strcpy(students[i].name, token);

        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        token = strtok(NULL, delimiter);
    }

    free(inputCopy); // Free the dynamically allocated memory
}

int main() {
    const char *inputString = "1001 Aron 100.00";
    int numStudents = 1; // Number of structures to initialize
    struct Student *students = malloc(numStudents * sizeof(struct Student));

    parseStringToStructArray(inputString, numStudents, students);

    // Printing the initialized structures
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students); // Free the dynamically allocated memory

    return 0;
}