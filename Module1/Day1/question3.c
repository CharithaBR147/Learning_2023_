#include <stdio.h>

// Function to calculate percentage
float calculate_percentage(float total_marks, int total_subjects) {
    return (total_marks / (total_subjects * 100)) * 100;
}

int main() {
    // Variables declaration
    int roll_no;
    char name[100];
    float marks_physics, marks_maths, marks_chemistry;
    float total_marks, percentage;

    // Read student details
    printf("Enter Roll No: ");
    scanf("%d", &roll_no);

    printf("Enter Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Physics Marks: ");
    scanf("%f", &marks_physics);

    printf("Enter Maths Marks: ");
    scanf("%f", &marks_maths);

    printf("Enter Chemistry Marks: ");
    scanf("%f", &marks_chemistry);

    // Calculate total marks
    total_marks = marks_physics + marks_maths + marks_chemistry;

    // Calculate percentage
    percentage = calculate_percentage(total_marks, 3);

    // Print summary
    printf("\n------ Student Summary ------\n");
    printf("Roll No: %d\n", roll_no);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", marks_physics);
    printf("Maths Marks: %.2f\n", marks_maths);
    printf("Chemistry Marks: %.2f\n", marks_chemistry);
    printf("Total Marks: %.2f\n", total_marks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}