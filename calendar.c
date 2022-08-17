#include <stdio.h>
#include <string.h>
#include "utils/string_utils.h"

#define SPACE_BETWEEN 2

int is_leap_year(int year);
int get_days_for_year(int year);
void xprint(char* x, int times);

int main()
{
    const int PRIMER_DIA_DC = 6; // saturday

    int january_first_day, days_per_month, month, date, year;

    printf("Type a year: ");
    scanf("%d", &year);

    january_first_day = PRIMER_DIA_DC;

    // first day for the selected year
    for (int k = 1; k < year; k++) {
        january_first_day = (january_first_day + get_days_for_year(k) ) % 7;
    }

    for (month = 1; month <= 12; month++)
    {
        switch (month)
        {
            case 1:
                printf("\nJanuary\n");
                days_per_month = 31;
                break;
            case 2:
                printf("\n\n\nFebruary\n");
                days_per_month = month % 4 == 0 && month % 100 != 0 ? 28 : 29;
                break;
            case 3:
                printf("\n\n\nMarch\n");
                days_per_month = 31;
                break;
            case 4:
                printf("\n\n\nApril\n");
                days_per_month = 30;
                break;
            case 5:
                printf("\n\n\nMay\n");
                days_per_month = 31;
                break;
            case 6:
                printf("\n\n\nJune\n");
                days_per_month = 30;
                break;
            case 7:
                printf("\n\n\nJuly\n");
                days_per_month = 31;
                break;
            case 8:
                printf("\n\n\nAugust\n");
                days_per_month = 31;
                break;
            case 9:
                printf("\n\n\nSeptember\n");
                days_per_month = 30;
                break;
            case 10:
                printf("\n\n\nOctober\n");
                days_per_month = 31;
                break;
            case 11:
                printf("\n\n\nNovember\n");
                days_per_month = 30;
                break;
            case 12:
                printf("\n\n\nDecember\n");
                days_per_month = 31;
                break;
        }

        printf("\nMon  Tue  Wed  Thr  Fri  Sat  Sun\n");
        printf("---  ---  ---  ---  ---  ---  ---\n");

        for (date = 1; date <= 5 * january_first_day - 5; date++) {
            printf(" ");
        }

        for (date = 1; date <= days_per_month; date++) {
            int day_block_lenght = 3;
            char day_text[3];
            sprintf(day_text, "%d", date);
            str_pad(day_text, day_block_lenght, " ", STR_PAD_LEFT);
            printf("%s", day_text);

            if ( (date + january_first_day - 1) % 7 > 0 )
                xprint(" ", SPACE_BETWEEN);
            else
                printf("\n");
        }

        january_first_day = (january_first_day + days_per_month) % 7;
    }

    printf("\n");

    return 0;
}

int is_leap_year(int year)
{
    return year % 4 == 0 && year % 100 != 0;
}

int get_days_for_year(int year)
{
    return is_leap_year(year) ? 366 : 365;
}

void xprint(char* x, int times)
{
    for (int i = 0; i < times; i++) {
        printf("%s", x);
    }
}
