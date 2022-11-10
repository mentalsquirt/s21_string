#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define NULL (void*)0
typedef unsigned long s21_size_t;

#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);

#endif  // SRC_S21_STRING_H_