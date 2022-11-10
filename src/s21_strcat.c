#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    s21_size_t i = s21_strlen(dest);

    if (dest && src) {
        while (*src != '\0') {
            dest[i] = *src;
            src++;
        }
    }

    return dest;
}
