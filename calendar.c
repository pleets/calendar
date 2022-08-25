#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils/string_utils.h"
#include "datetime/date.h"
#include "terminal/print.h"

void parse_arguments(int argc, char *argv[]);

void print_month_name(int month);
void print_month_calendar(int year, int month, int day);

int is_last_weekend_day(int day, int first_month_day);

const int FIRST_AD_DAY = 6; // saturday

int colors = 0;
char base_text_color[10] = COLOR_NORMAL;
char base_bg_color[10] = BG_COLOR_NORMAL;

int main(int argc, char *argv[])
{
    if (argc > 1) {
        parse_arguments(argc, argv);
    }

    time_t current_time;
    current_time = time(NULL);
    struct tm c_localtime = *localtime(&current_time);

    print_month_calendar(c_localtime.tm_year + 1900, c_localtime.tm_mon + 1, c_localtime.tm_mday);

    return 0;
}

void parse_arguments(int argc, char *argv[])
{
    char _colors[] = "colors";

    for(int i = 1; i <= argc - 1; i++) {
        if (strcmp(_colors, argv[i])) {
            colors = 1;
            strcpy(base_text_color, COLOR_CYAN);
            strcpy(base_bg_color, BG_COLOR_MAGENTA);
        }
    }
}

void print_month_calendar(int year, int month, int day)
{
    print_month_name(month);

    printf_color("\nMon  Tue  Wed  Thr  Fri  Sat  Sun", base_bg_color);
    printf("\n---  ---  ---  ---  ---  ---  ---\n");

    int first_month_day = FIRST_AD_DAY;

    // first day for the selected year
    for (int k = 1; k < year; k++) {
        first_month_day = (first_month_day + days_for_year(k) ) % 7;
    }

    for (int date = 1; date <= 5 * first_month_day - 5; date++) {
        printf(" ");
    }

    int _days_per_month = days_per_month(month);

    for (int date = 1; date <= _days_per_month; date++) {
        int day_block_lenght = 3;
        char day_text[3];
        sprintf(day_text, "%d", date);
        str_pad(day_text, day_block_lenght, " ", STR_PAD_LEFT);

        int _is_last_weekend_day = is_last_weekend_day(date, first_month_day);

        if (day == date) {
            printf_colors(
                day_text,
                colors ? COLOR_NORMAL : COLOR_BLACK,
                colors ? base_bg_color : BG_COLOR_WHITE
            );
        } else {
            printf_color(day_text, _is_last_weekend_day ? COLOR_NORMAL : base_text_color);
        }

        if (_is_last_weekend_day)
            printf("%2s", " ");
        else
            printf("\n");
    }

    first_month_day = (first_month_day + _days_per_month) % 7;

    printf("\n");
}

int is_last_weekend_day(int day, int first_month_day)
{
    return (day + first_month_day - 1) % 7 > 0;
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
