#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *name;
  float price;
} food;

food add_items(char *name, float price);
float get_cost(food menu[], int menu_length);

int main(void) {
  food f = add_items("Burger", 9.50);

  food menu[4];

  menu[0] = add_items("Burger", 9.50);
  menu[1] = add_items("Hot Dog", 11.0);
  menu[2] = add_items("Fries", 5.0);
  menu[3] = add_items("Soda", 2.0);

  printf("Welcome to Beach Burger Shack!\n");
  printf("Choose from the following menu to order. Press enter when done.\n");
  printf("\n");

  for (int i = 0; i < 4; i++) {
    printf("%s: $%.2f\n", menu[i].name, menu[i].price);
  }

  float total_food = get_cost(menu, 4);

  printf("Your total cost is: %.2f\n", total_food);
}

food add_items(char *name, float price) {
  food f;

  f.name = name;
  f.price = price;

  return f;
}

float get_cost(food menu[], int menu_length) {
  float total_price = 0;

  while (true) {
    char food_name[40];
    printf("Enter a food item: ");
    scanf("%s", food_name);

    if (strcmp(food_name, "0") == 0) {
      break;
    }

    for (int i = 0; i < menu_length; i++) {
      if (strcmp(food_name, menu[i].name) == 0) {
        total_price += menu[i].price;
        break;
      }
    }
  }

  return total_price;
}
