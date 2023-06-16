#include <stdio.h>

int main() {
    double a, b;

    printf("Enter the first number: ");
    scanf("%lf", &a);

    printf("Enter the second number: ");
    scanf("%lf", &b);

    if (a > b) {
        printf("The bigger number is: %.2lf\n", a);
    } else if (b > a) {
        printf("The bigger number is: %.2lf\n", b);
    } else {
        printf("Both numbers are equal.\n");
    }

    return 0;
}