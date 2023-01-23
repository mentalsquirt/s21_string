#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "check.h"
#include "s21_string.h"
#include <check.h>
#include <time.h>

#define NMAX 1024
#define AMOUNT 10

char *get_random_str() {
  srand(time(NULL));
  int len = rand() % (NMAX - 1) + 1;
  char *str = (char*)malloc(len + 1);
  for (int i = 0; i < len; i++) {
    str[i] = (char)(rand() % ('z' - 'a' + 1) + 'a');
  }
  str[len] = '\0';
  return str;
}

START_TEST (test_memchr) {
  char *str = get_random_str();
  int len = strlen(str);
  char target = (char) (rand() % ('z' - 'a' + 1) + 'a');
  ck_assert_ptr_eq(memchr(str, target, len), s21_memchr(str, target, len));
  free(str);
}
END_TEST

START_TEST (test_memcpy) {
  char *src = get_random_str();
  int len = strlen(src);
  char *dst = (char*)malloc(len + 1);
  char *expected_dst = (char*)malloc(len + 1);
  memcpy(expected_dst, src, len);
  s21_memcpy(dst, src, len);
  ck_assert_str_eq(dst, expected_dst);
  free(src);
  free(dst);
  free(expected_dst);
}
END_TEST

START_TEST (test_memcmp) {
  char *s1 = get_random_str();
  char *s2 = get_random_str();
  int len = rand() % (NMAX - 1) + 1;
  ck_assert_int_eq(memcmp(s1, s2, len), s21_memcmp(s1, s2, len));
  free(s1);
  free(s2);
}
END_TEST

START_TEST(test_strtok) {
  char input[] = "This is a test string";
  char *result;
  char *delimiter = " ";
  result = strtok(input, delimiter);
  ck_assert_str_eq(result, "This");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "is");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "a");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "test");
  result = strtok(NULL, delimiter);
  ck_assert_str_eq(result, "string");
  result = strtok(NULL, delimiter);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST (test_strstr) {
  char *haystack = get_random_str();
  char *needle = get_random_str();
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
  free(haystack);
  free(needle);
}
END_TEST

START_TEST (test_strcpy) {
  char *src = get_random_str();
  char *dst = (char*) malloc(strlen(src) + 1);
  strcpy(dst, src);
  s21_strcpy(dst, src);
  ck_assert_str_eq(dst, src);
  free(src);
  free(dst);
}
END_TEST

START_TEST (test_strcmp) {
  char *s1 = get_random_str();
  char *s2 = get_random_str();
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
  free(s1);
  free(s2);
}
END_TEST

START_TEST (test_strlen) {
  char *str = get_random_str();
  ck_assert_int_eq(strlen(str), s21_strlen(str));
  free(str);
}
END_TEST

START_TEST (test_strchr) {
  char *str = get_random_str();
  char *target = str + (rand() % strlen(str));
  ck_assert_ptr_eq(strchr(str, *target), s21_strchr(str, *target));
  free(str);
}
END_TEST

START_TEST (test_strcat) {
  char *s1 = get_random_str();
  char *s2 = get_random_str();
  char *expected_str = (char*) malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(expected_str, s1);
  strcat(expected_str, s2);
  char *my_str = (char*) malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(my_str, s1);
  s21_strcat(my_str, s2);
  ck_assert_str_eq(my_str, expected_str);
  free(s1);
  free(s2);
  free(expected_str);
  free(my_str);
}
END_TEST

START_TEST (test_memmove) {
  char *s1 = get_random_str();
  int len = strlen(s1);
  int offset = rand() % len;
  char *expected_s1 = (char*)malloc(len + 1);
  memcpy(expected_s1, s1, len);
  s21_memmove(s1 + offset, s1, len - offset);
  memmove(expected_s1 + offset, expected_s1, len - offset);
  ck_assert_str_eq(s1, expected_s1);
  free(s1);
  free(expected_s1);
}
END_TEST

START_TEST (test_memset) {
  char *s1 = get_random_str();
  int len = strlen(s1);
  char target = (char)(rand() % ('z' - 'a' + 1) + 'a');
  char *s2 = (char*)malloc(len + 1);
  memcpy(s2, s1, len);
  s21_memset(s1, target, len);
  memset(s2, target, len);
  ck_assert_str_eq(s1, s2);
  free(s1);
  free(s2);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Test suite");

  TCase *tc_memchr = tcase_create("memchr");
  TCase *tc_memcmp = tcase_create("memcmp");
  TCase *tc_memcpy = tcase_create("memcpy");
  TCase *tc_memmove = tcase_create("memmove");
  TCase *tc_memset = tcase_create("memset");
  TCase *tc_strcat = tcase_create("strcat");
  TCase *tc_strlen = tcase_create("strlen");
  TCase *tc_strcmp = tcase_create("strcmp");
  TCase *tc_strcpy = tcase_create("strcpy");
  TCase *tc_strchr = tcase_create("strchr");
  TCase *tc_strstr = tcase_create("strstr");
  TCase *tc_strtok = tcase_create("strtok");

  tcase_add_test(tc_memchr, test_memchr);
  tcase_add_test(tc_memcmp, test_memcmp);
  tcase_add_test(tc_memcpy, test_memcpy);
  tcase_add_test(tc_memmove, test_memmove);
  tcase_add_test(tc_memset, test_memset);
  tcase_add_test(tc_strcat, test_strcat);
  tcase_add_test(tc_strlen, test_strlen);
  tcase_add_test(tc_strcmp, test_strcmp);
  tcase_add_test(tc_strcpy, test_strcpy);
  tcase_add_test(tc_strchr, test_strchr);
  tcase_add_test(tc_strstr, test_strstr);
  tcase_add_test(tc_strtok, test_strtok);

  suite_add_tcase(s, tc_memchr);
  suite_add_tcase(s, tc_memcmp);
  suite_add_tcase(s, tc_memcpy);
  suite_add_tcase(s, tc_memmove);
  suite_add_tcase(s, tc_memset);
  suite_add_tcase(s, tc_strcat);
  suite_add_tcase(s, tc_strlen);
  suite_add_tcase(s, tc_strcmp);
  suite_add_tcase(s, tc_strcpy);
  suite_add_tcase(s, tc_strchr);
  suite_add_tcase(s, tc_strstr);
  suite_add_tcase(s, tc_strtok);

  SRunner *sr = srunner_create(s);

  for (int repeats = 0; repeats < 100; repeats++) srunner_run_all(sr, CK_NORMAL);

  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
