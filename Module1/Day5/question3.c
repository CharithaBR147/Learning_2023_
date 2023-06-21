#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimeDifference(struct Time t1, struct Time t2, struct Time *diff) {
    int totalSeconds1, totalSeconds2, differenceSeconds;

    totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    differenceSeconds = totalSeconds2 - totalSeconds1;

    diff->hours = differenceSeconds / 3600;
    differenceSeconds %= 3600;
    diff->minutes = differenceSeconds / 60;
    diff->seconds = differenceSeconds % 60;
}

int main() {
    struct Time startTime, endTime, diffTime;

    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    getTimeDifference(startTime, endTime, &diffTime);

    printf("\nTime difference: %d hours %d minutes %d seconds\n", diffTime.hours, diffTime.minutes, diffTime.seconds);

    return 0;
}