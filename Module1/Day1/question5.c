#include <stdio.h>

int bit_operations(int num, int oper_type) {
    int result = num;

    switch (oper_type) {
        case 1: // Set 1st bit
            result = num | (1 << 0);
            break;
        case 2: // Clear 31st bit
            result = num & (~(1 << 31));
            break;
        case 3: // Toggle 16th bit
            result = num ^ (1 << 15);
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }

    return result;
}

int main() {
    int num, oper_type;

    // Read input values
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);

    // Perform bit operations
    int result = bit_operations(num, oper_type);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}