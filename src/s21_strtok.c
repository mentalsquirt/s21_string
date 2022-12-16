#include "s21_string.h"

char *olds;

char *s21_strtok(char *str, const char *delim) {
  char *token = NULL;

  if (str == NULL)
    str = olds;

  /* Scan leading delimiters.  */
  str += s21_strspn (str, delim);  // handles possible trailing delims
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
    olds = s21_memchr(token, '\0', 1024);
  else
    {
      /* Terminate the token and make OLDS point past it.  */
      *str = '\0';
      olds = str + 1;
    }
  return token;
}
