#include <stdio.h>
#include "colors.h"

void printf_color(char *text, char *color)
{
    printf("%s%s%s", color, text, COLOR_NORMAL);
}

void printf_colors(char *text, char *color, char *background)
{
    printf("%s%s%s%s%s", color, background, text, COLOR_NORMAL, BG_COLOR_NORMAL);
}