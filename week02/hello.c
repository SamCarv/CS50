#include <stdio.h>

int main(void) {
  char name[20];

  printf("What's your name?\n");
  scanf("%s", name);

  printf("hello, %s\n", name);
}
