#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStructArray(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 10;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    int numStudents = 3; // Number of structures in the array
    struct Student students[numStudents];

    initializeStructArray(students, numStudents);

    // Printing the initialized structures
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}