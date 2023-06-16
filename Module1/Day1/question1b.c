#include <stdio.h>

void main() {
    int num1, num2, biggest;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    biggest = (num1 > num2) ? num1 : num2;

    printf("The biggest number is: %d\n", biggest);

    return 0;
}