#include <stdio.h>

int countSetBits(int arr[], int size) {
    int totalSetBits = 0;

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int bitCount = 0;

        // Count set bits in the current element
        while (num > 0) {
            bitCount += num & 1;
            num >>= 1;
        }

        totalSetBits += bitCount;
    }

    return totalSetBits;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = countSetBits(arr, size);

    printf("Total number of set bits: %d\n", result);

    return 0;
}