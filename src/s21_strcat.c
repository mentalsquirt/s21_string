#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = s21_strlen(dest);
  if (dest && src) {
    while (*src != '\0') {
      dest[i] = *src;
      src++;
      i++;
    }
  }
  return dest;
}


char *s21_strncat(char *dest, const char *src, size_t n) {
  s21_size_t count = 0;
  if (!dest || !src) {
    exit(1);
  }
  for (s21_size_t i = s21_strlen(dest); count < n;) {
    dest[i] = src[count];
    count++;
    i++;
  }
  return dest;
}
