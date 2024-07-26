#include <stdio.h>

int add(int x, int y) { return x + y; }

int main(void) {
  int x;
  int y;

  printf("x: ");
  scanf("%d", &x);

  printf("y: ");
  scanf("%d", &y);

  printf("%i\n", add(x, y));
}
