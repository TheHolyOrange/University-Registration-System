#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

// Function to check if a year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a given month of a year
int days_in_month(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return is_leap_year(year) ? 29 : 28;
    }
    return 0; // Invalid month
}

// Function to convert date to the number of days since 01/01/0000
int date_to_days(int day, int month, int year) {
    int days = day;
    for (int y = 0; y < year; y++) {
        days += is_leap_year(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += days_in_month(m, year);
    }
    return days;
}

// Function to calculate the absolute value
int abs(int x) {
    return x < 0 ? -x : x;
}

// Function to check the difference between two dates
int checkDateDiff(char *date1, char *date2) {
    int day1, month1, year1;
    int day2, month2, year2;

    // Parse the dates
    sscanf(date1, "%d/%d/%d", &day1, &month1, &year1);
    sscanf(date2, "%d/%d/%d", &day2, &month2, &year2);

    // Convert dates to total days
    int days1 = date_to_days(day1, month1, year1);
    int days2 = date_to_days(day2, month2, year2);

    // Calculate the difference in days
    int diff_days = abs(days2 - days1);

    // Return 0 if the difference is more than 14 days, otherwise return 1
    return diff_days > 14 ? 0 : 1;
}