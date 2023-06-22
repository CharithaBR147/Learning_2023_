#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(const struct Student *students, int numStudents, const char *name) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");

            found = 1;
        }
    }

    if (!found) {
        printf("Student Not Found\n");
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

    const char *searchName = "Chris";

    searchByName(students, numStudents, searchName);

    return 0;
}