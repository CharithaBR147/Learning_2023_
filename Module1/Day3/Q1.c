#include <stdio.h>

void print_numbers(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
    for (i = n; i >= 1; i--) {
        printf("%d", i);
    }
    printf("\n");
}

void print_spaces(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf(" ");
    }
    for (i = 1; i <= (n * 2) - 3; i++) {
        printf(" ");
    }
    for (i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("\n");
}

void print_pattern(int n) {
    int i;
    for (i = n; i >= 1; i--) {
        print_numbers(i);
        if (i > 1) {
            print_spaces(i - 1);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    print_pattern(n);
    return 0;
}