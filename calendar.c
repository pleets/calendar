#include <stdio.h>
#include <string.h>
#include "utils/string_utils.h"
#include "datetime/date.h"

void print_month_name(int month);

int main()
{
    const int FIRST_AD_DAY = 6; // saturday

    int january_first_day, _days_per_month, month, date, year;

    printf("Type a year: ");
    scanf("%d", &year);

    january_first_day = FIRST_AD_DAY;

    // first day for the selected year
    for (int k = 1; k < year; k++) {
        january_first_day = (january_first_day + days_for_year(k) ) % 7;
    }

    for (month = JANUARY; month <= DECEMBER; month++)
    {
        print_month_name(month);
        _days_per_month = days_per_month(month);

        printf("\nMon  Tue  Wed  Thr  Fri  Sat  Sun\n");
        printf("---  ---  ---  ---  ---  ---  ---\n");

        for (date = 1; date <= 5 * january_first_day - 5; date++) {
            printf(" ");
        }

        for (date = 1; date <= _days_per_month; date++) {
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
    }

    printf("\n");

    return 0;
}

void print_month_name(int month)
{
    switch (month)
    {
        case JANUARY:
            printf("\nJanuary\n");
            break;
        case FEBRUARY:
            printf("\n\n\nFebruary\n");
            break;
        case MARCH:
            printf("\n\n\nMarch\n");
            break;
        case APRIL:
            printf("\n\n\nApril\n");
            break;
        case MAY:
            printf("\n\n\nMay\n");
            break;
        case JUNE:
            printf("\n\n\nJune\n");
            break;
        case JULY:
            printf("\n\n\nJuly\n");
            break;
        case AUGUST:
            printf("\n\n\nAugust\n");
            break;
        case SEPTEMBER:
            printf("\n\n\nSeptember\n");
            break;
        case OCTOBER:
            printf("\n\n\nOctober\n");
            break;
        case NOVEMBER:
            printf("\n\n\nNovember\n");
            break;
        case DECEMBER:
            printf("\n\n\nDecember\n");
            break;
    }
}
