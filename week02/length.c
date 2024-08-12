#include <stdio.h>
#include <string.h>

int string_length(char string[]);

int main(void) {
  char name[20];

  printf("Name: ");
  scanf("%s", name);

  int length = string_length(name);

  printf("Length: %i\n", length);
  printf("Length: %lu\n", strlen(name));
}

int string_length(char string[]) {
  int n = 0;
  while (string[n] != '\0') {
    n++;
  }
  return n;
}
