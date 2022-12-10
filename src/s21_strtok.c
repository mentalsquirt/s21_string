#include "s21_string.h"
#include <string.h>
#include <stdio.h>

char *olds;

char *s21_strtok(char *str, const char *delim) {
  char *token;

  if (str == NULL)
    str = olds;

  /* Scan leading delimiters.  */
  str += s21_strspn (str, delim);
  if (*str == '\0')
    {
      olds = str;
      return NULL;
    }

  /* Find the end of the token.  */
  token = str;
  str = s21_strpbrk (token, delim);
  if (str == NULL)
    /* This token finishes the string.  */
    olds = memchr(token, '\0', 1024);
  else
    {
      /* Terminate the token and make OLDS point past it.  */
      *str = '\0';
      olds = str + 1;
    }
  return token;
}

size_t s21_strspn(const char *s, const char *accept) {
  const char *p;
  const char *a;
  size_t count = 0;

  for (p = s; *p != '\0'; ++p)
    {
      for (a = accept; *a != '\0'; ++a)
    if (*p == *a)
      break;
      if (*a == '\0')
    return count;
      else
    ++count;
    }

  return count;
}

char *s21_strpbrk(const char *s, const char *accept) {
  while (*s != '\0')
    {
      const char *a = accept;
      while (*a != '\0')
    if (*a++ == *s)
      return (char *) s;
      ++s;
    }

  return NULL;
}

