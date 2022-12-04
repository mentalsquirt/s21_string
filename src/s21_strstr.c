#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') return (char*)haystack;

  s21_size_t j = 0;
  for (s21_size_t i = 0; haystack[i] != '\0'; i++) {
    j = 0;
    while ((haystack[i + j] != '\0') && (haystack[i + j] != needle[j])) {
      if (needle[j + 1] == '\0') {
        return (char*)(haystack + i);
      }
    }
  }
  return NULL;
}
