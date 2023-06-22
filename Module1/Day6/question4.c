#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStructArrayDescending(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the structures
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStructArray(const struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents = 4; // Number of structures in the array
    struct Student students[numStudents];

    // Initialize the structures
    students[0].rollno = 1001;
    strcpy(students[0].name, "Aron");
    students[0].marks = 85.25;

    students[1].rollno = 1002;
    strcpy(students[1].name, "Bella");
    students[1].marks = 90.50;

    students[2].rollno = 1003;
    strcpy(students[2].name, "Chris");
    students[2].marks = 95.75;

    students[3].rollno = 1004;
    strcpy(students[3].name, "David");
    students[3].marks = 80.00;

    printf("Before sorting:\n");
    displayStructArray(students, numStudents);

    sortStructArrayDescending(students, numStudents);

    printf("After sorting in descending order based on marks:\n");
    displayStructArray(students, numStudents);

    return 0;
}