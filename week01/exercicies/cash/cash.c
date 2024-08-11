#include <stdio.h>

int calculate_coin(int cents, int coin) {
  int coins = 0;
  while (cents >= coin) {
    cents = cents - coin;
    coins++;
  }
  return coins;
}

int main(void) {
  int cents;

  do {
    printf("Change owed: ");
    scanf("%i", &cents);
  } while (cents < 0);

  int quarters = calculate_coin(cents, 25);
  cents = cents - (quarters * 25);

  int dimes = calculate_coin(cents, 10);
  cents = cents - (dimes * 10);

  int nickles = calculate_coin(cents, 5);
  cents = cents - (nickles * 5);

  int pennies = calculate_coin(cents, 1);
  cents = cents - (pennies * 1);

  int total = quarters + dimes + nickles + pennies;
  printf("%i\n", total);
}
