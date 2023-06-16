 #include <stdio.h>

int findLargestNumber(int num) {
    int largestNum = 0;
    int temp = num;

    for (int i = 0; i < 4; i++) {
        int divisor = 1;
        int newNum = 0;

        for (int j = 0; j < 4; j++) {
            int digit = temp / divisor % 10;

            if (j != i) {
                newNum = newNum * 10 + digit;
            }

            divisor *= 10;
        }

        if (newNum > largestNum) {
            largestNum = newNum;
        }
    }

    return largestNum;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNum = findLargestNumber(num);
    printf("Largest number by deleting a single digit: %d\n", largestNum);

    return 0;
}