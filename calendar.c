#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils/string_utils.h"
#include "datetime/date.h"

void print_month_name(int month);
void print_month_calendar(int year, int month);

const int FIRST_AD_DAY = 6; // saturday

int main()
{
    int month;

    time_t current_time;
    current_time = time(NULL);
    struct tm c_localtime = *localtime(&current_time);

    print_month_calendar(c_localtime.tm_year + 1900, c_localtime.tm_mon + 1);

    return 0;
}

void print_month_calendar(int year, int month)
{
    print_month_name(month);

    printf("\nMon  Tue  Wed  Thr  Fri  Sat  Sun\n");
    printf("---  ---  ---  ---  ---  ---  ---\n");

    int january_first_day = FIRST_AD_DAY;

    // first day for the selected year
    for (int k = 1; k < year; k++) {
        january_first_day = (january_first_day + days_for_year(k) ) % 7;
    }

    for (int date = 1; date <= 5 * january_first_day - 5; date++) {
        printf(" ");
    }

    int _days_per_month = days_per_month(month);

    for (int date = 1; date <= _days_per_month; date++) {
        int day_block_lenght = 3;
        char day_text[3];
        sprintf(day_text, "%d", date);
        str_pad(day_text, day_block_lenght, " ", STR_PAD_LEFT);
        printf("%s", day_text);

        if ( (date + january_first_day - 1) % 7 > 0 )
            printf("%2s", " ");
        else
            printf("\n");
    }

    january_first_day = (january_first_day + _days_per_month) % 7;

    printf("\n");
}

void print_month_name(int month)
{
    switch (month)
    {
        case JANUARY:
            printf("\nJanuary\n");
            break;
        case FEBRUARY:
            printf("\nFebruary\n");
            break;
        case MARCH:
            printf("\nMarch\n");
            break;
        case APRIL:
            printf("\nApril\n");
            break;
        case MAY:
            printf("\nMay\n");
            break;
        case JUNE:
            printf("\nJune\n");
            break;
        case JULY:
            printf("\nJuly\n");
            break;
        case AUGUST:
            printf("\nAugust\n");
            break;
        case SEPTEMBER:
            printf("\nSeptember\n");
            break;
        case OCTOBER:
            printf("\nOctober\n");
            break;
        case NOVEMBER:
            printf("\nNovember\n");
            break;
        case DECEMBER:
            printf("\nDecember\n");
            break;
    }
}
