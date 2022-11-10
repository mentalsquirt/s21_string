#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *res = NULL;
    const unsigned char *str_p = (const unsigned char *)str;

    int i = 0;
    if (str && n != 0) {
        while (n--) {
            if (str_p[i] == c) {
                res = (void *)&str_p[i];
                break;
            }
        }
    }

    return res;
}
