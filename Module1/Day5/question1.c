#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

double calculateSurfaceArea(struct Box *boxPtr) {
    double length = boxPtr->length;
    double width = boxPtr->width;
    double height = boxPtr->height;

    return 2 * (length * width + length * height + width * height);
}

int main() {
    struct Box myBox;
    struct Box *boxPtr = &myBox;

    // Accessing structure members with dot operator (.)
    myBox.length = 5.0;
    myBox.width = 3.0;
    myBox.height = 2.0;

    // Accessing structure members with indirection operator (*) and dot operator (.)
    printf("Volume: %.2f\n", calculateVolume(&myBox));
    printf("Surface Area: %.2f\n", calculateSurfaceArea(&myBox));

    // Accessing structure members with arrow operator (->)
    boxPtr->length = 7.0;
    boxPtr->width = 4.0;
    boxPtr->height = 3.0;

    // Accessing structure members with arrow operator (->)
    printf("Volume: %.2f\n", calculateVolume(boxPtr));
    printf("Surface Area: %.2f\n", calculateSurfaceArea(boxPtr));

    return 0;
}