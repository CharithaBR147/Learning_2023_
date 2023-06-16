#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char *temp = (char *)malloc(size);

    // Copy contents of 'a' to 'temp'
    memcpy(temp, a, size);

    // Copy contents of 'b' to 'a'
    memcpy(a, b, size);

    // Copy contents of 'temp' to 'b'
    memcpy(b, temp, size);

    // Free the temporary memory
    free(temp);
}

int main() {
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y, sizeof(int));

    printf("After swap: x = %d, y = %d\n", x, y);

    double a = 3.14;
    double b = 2.71828;

    printf("Before swap: a = %lf, b = %lf\n", a, b);

    swap(&a, &b, sizeof(double));

    printf("After swap: a = %lf, b = %lf\n", a, b);

    return 0;
}