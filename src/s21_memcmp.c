#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int res = 0;

    const unsigned char *str1_p = (const unsigned char *)str1;
    const unsigned char *str2_p = (const unsigned char *)str2;

    if (str1_p && str2_p && (n != 0)) {
        for (int i = 0; i < n; i++) {
            if (str1_p[i] != str2_p[i]) {
                res = *str1_p - *str2_p;
                break;
            }
        }
    }

    return res;
}
