#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_p = (unsigned char *)dest;
  const unsigned char *src_p = (const unsigned char *)src;

  if (n && (dest_p != src_p)) {
    // overlap where src is first
    if (dest_p > src_p && dest_p - src_p < (int)n) {
      for (int i = n - 1; i >= 0; i--) {
        dest_p[i] = src_p[i];
      }
    // overlap where dest is first
    } else if (dest_p < src_p && src_p - dest_p < (int)n) {
      for (int i = 0; i < n; i++) {
        dest_p[i] = src_p[i];
      }
    } else {
      s21_memcpy(dest, src, n);
    }
  }

  return dest;
}
