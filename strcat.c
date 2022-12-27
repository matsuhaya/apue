/*
 * Author: Hiroyuki Chishiro
 * License: 2-Clause BSD
 */
#include <stdio.h>

#define BUFSIZE 16

char *mystrcat(char *dest, const char *src) {
  char *tmp = dest;

  while (*dest) {
    dest++;
  }

  while ((*dest++ = *src++)) {
  }

  return tmp;
}

int main(void) {
  char dest[BUFSIZE], src[BUFSIZE];

  printf("Please input a string: ");
  scanf("%s", dest);
  printf("Please input a string: ");
  scanf("%s", src);

  mystrcat(dest, src);

  printf("src  = %s\n", src);
  printf("dest = %s\n", dest);

  return 0;
}