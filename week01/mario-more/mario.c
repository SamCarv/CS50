#include <stdio.h>

void print_row(int bricks, int total_height);

int main(void) {
  int n;
  do {
    printf("Height: ");
    scanf("%d", &n);
  } while (n < 1);

  for (int i = 1; i <= n; i++) {
    print_row(i, n);
  }
}

void print_row(int bricks, int height) {
  for (int j = 0; j < height - bricks; j++) {
    printf(" ");
  }

  for (int j = 0; j < bricks; j++) {
    printf("#");
  }

  printf("  ");

  for (int i = 0; i < bricks; i++) {
    printf("#");
  }

  printf("\n");
}
