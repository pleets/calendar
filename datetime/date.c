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
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 31;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return is_leap_year(month) ? 28 : 29;
    }
}