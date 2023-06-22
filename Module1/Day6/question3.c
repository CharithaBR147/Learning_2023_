#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStructArray(const struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents = 3; // Number of structures in the array
    struct Student students[numStudents];

    // Initialize the structures (for demonstration)
    students[0].rollno = 1001;
    strcpy(students[0].name, "Aron");
    students[0].marks = 100.00;

    students[1].rollno = 1002;
    strcpy(students[1].name, "Bella");
    students[1].marks = 90.50;

    students[2].rollno = 1003;
    strcpy(students[2].name, "Chris");
    students[2].marks = 85.25;

    displayStructArray(students, numStudents);

    return 0;
}