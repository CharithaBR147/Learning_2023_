#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

int getMonthDays(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month];
}

int countDays(char* date) {
    int day1, month1, year1, day2, month2, year2;
    sscanf(date, "%d/%d/%d", &day1, &month1, &year1);
    sscanf(date + 10, "%d/%d/%d", &day2, &month2, &year2);

    int totalDays = 0;

    // Count days for the first year
    for (int i = month1 + 1; i <= 12; i++)
        totalDays += getMonthDays(i, year1);
    totalDays += getMonthDays(month1, year1) - day1;

    // Count days for the years in between
    for (int year = year1 + 1; year < year2; year++) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }

    // Count days for the last year
    for (int i = 1; i < month2; i++)
        totalDays += getMonthDays(i, year2);
    totalDays += day2;

    return totalDays;
}

int main() {
    char dateString[] = "10/04/201510/04/2016";
    int daysElapsed = countDays(dateString);

    printf("No. of days elapsed: %d\n", daysElapsed);

    return 0;
}