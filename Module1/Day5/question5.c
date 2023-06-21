#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void swapFields(struct Student *s1, struct Student *s2) {
    struct Student temp;

    // Swap name field
    strcpy(temp.name, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, temp.name);

    // Swap rollNumber field
    temp.rollNumber = s1->rollNumber;
    s1->rollNumber = s2->rollNumber;
    s2->rollNumber = temp.rollNumber;

    // Swap marks field
    temp.marks = s1->marks;
    s1->marks = s2->marks;
    s2->marks = temp.marks;
}

int main() {
    struct Student student1, student2;

    printf("Enter details for student 1:\n");
    printf("Enter name: ");
    scanf(" %[^\n]", student1.name);
    printf("Enter roll number: ");
    scanf("%d", &student1.rollNumber);
    printf("Enter marks: ");
    scanf("%f", &student1.marks);

    printf("\nEnter details for student 2:\n");
    printf("Enter name: ");
    scanf(" %[^\n]", student2.name);
    printf("Enter roll number: ");
    scanf("%d", &student2.rollNumber);
    printf("Enter marks: ");
    scanf("%f", &student2.marks);

    printf("\nBefore swapping:\n");
    printf("Student 1:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student2.name, student2.rollNumber, student2.marks);

    // Swap fields using function
    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student2.name, student2.rollNumber, student2.marks);

    return 0;
}