#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  size_t len1 = s21_strlen(haystack), len2 = s21_strlen(needle);
  for (size_t i = 0; i <= len1 - len2; i++) {
    if (s21_strcmp(haystack + i, needle) == 0) {
      return (char *)haystack + i;
    }
  }
  return NULL;
}
