#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    char* token = strtok((char*)input, " ");
    for (int i = 0; i < size; i++) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name));
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        token = strtok(NULL, " ");
    }
}

void initializeStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        students[i].name[0] = '\0';
        students[i].marks = 0.0;
    }
}

void displayStudents(const struct Student* students, int size) {
    printf("Roll No\tName\tMarks\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

void sortStudentsDescending(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void searchStudentByName(const struct Student* students, int size, const char* name) {
    printf("Search results for '%s':\n", name);
    printf("Roll No\tName\tMarks\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("%d\t%s\t%.2f\n", students[i].rollno, students[i].name, students[i].marks);
        }
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    fflush(stdin); // Clear input buffer
    
    struct Student students[size];
    char input[100];

    printf("Enter student details (roll no, name, marks) in the format 'RollNo Name Marks':\n");
    for (int i = 0; i < size; i++) {
        fgets(input, sizeof(input), stdin);
        parseString(input, &students[i], 1);
    }

    printf("\nStudents:\n");
    displayStudents(students, size);

    sortStudentsDescending(students, size);

    printf("\nStudents (sorted in descending order of marks):\n");
    displayStudents(students, size);

    char searchName[20];
    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchStudentByName(students, size, searchName);

    return 0;
}