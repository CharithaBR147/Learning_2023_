#include <stdio.h>
#include <stdint.h>

void printExponent(double x) {
    // Get the bits of the double value
    uint64_t bits = *(uint64_t *)&x;

    // Extract the exponent bits (bits 52-62) and shift them to the rightmost position
    uint16_t exponent = (bits >> 52) & 0x7FF;

    // Convert the exponent to hexadecimal and binary format
    char hexString[5];
    sprintf(hexString, "0x%X", exponent);

    char binaryString[12];
    for (int i = 0; i < 11; i++) {
        binaryString[10 - i] = (exponent & (1 << i)) ? '1' : '0';
    }
    binaryString[11] = '\0';

    // Print the results
    printf("Exponent in hexadecimal: %s\n", hexString);
    printf("Exponent in binary: %s\n", binaryString);
}

int main() {
    double x = 0.7;
    printExponent(x);
    return 0;
}