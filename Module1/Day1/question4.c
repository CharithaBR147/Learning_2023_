#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    // Read operand 1
    printf("Enter Number 1: ");
    scanf("%f", &num1);

    // Read operator
    printf("Enter the operator: ");
    scanf(" %c", &operator);

    // Read operand 2
    printf("Enter Number 2: ");
    scanf("%f", &num2);

    // Perform calculations based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    return 0;
}