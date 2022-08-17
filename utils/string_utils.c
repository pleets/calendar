#include <string.h>
#include "string_macros.c"

char* str_pad(char string[], int length, char pad_string[], int pad_type)
{
	int extra_chars;
	int string_length = strlen(string);
	char buffer[20];

	if (string_length > length) {
		return string;
	}

	extra_chars = length - string_length;

    switch (pad_type)
    {
        case STR_PAD_RIGHT:
            for (int i = 0; i < extra_chars; i++) {
                strcat(string, pad_string);
            }
            break;
        
        case STR_PAD_LEFT:
            strcpy(buffer, string);

            for (int i = 0; i < extra_chars; i++) {
                if (i == 0) {
                    strcpy(string, pad_string);
                } else {
                    strcat(string, pad_string);
                }
            }

            strcat(string, buffer);
            break;

        default:
            break;
    }

	return string;
}