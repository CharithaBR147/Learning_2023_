#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    int numBits = sizeof(num) * 8; // Assuming an unsigned int is 32 bits on your system

    for (i = numBits - 1; i >= 0; i--) {
        unsigned int mask = 1u << i;
        putchar((num & mask) ? '1' : '0');
    }

    printf("\n");
}

int main() {
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits representation: ");
    printBits(num);

    return 0;
}