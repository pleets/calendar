#include "date_constants.c"

int is_leap_year(int year)
{
    return year % 4 == 0 && year % 100 != 0;
}

int days_for_year(int year)
{
    return is_leap_year(year) ? 366 : 365;
}

int days_per_month(int month)
{
    switch (month)
    {
        case JANUARY:
            return 31;
        case FEBRUARY:
            return is_leap_year(month) ? 28 : 29;
        case MARCH:
            return 31;
        case APRIL:
            return 30;
        case MAY:
            return 31;
        case JUNE:
            return 30;
        case JULY:
            return 31;
        case AUGUST:
            return 31;
        case SEPTEMBER:
            return 30;
        case OCTOBER:
            return 31;
        case NOVEMBER:
            return 30;
        case DECEMBER:
            return 31;
    }
}