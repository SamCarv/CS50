#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check(char *password);

int main(void) {
  char *password;

  while (true) {
    printf("Enter your password: ");
    scanf("%s", password);

    if (check(password)) {
      printf("Your password is valid!\n");
      break;
    } else {
      printf("Your password need at least one upper...\n");
    }
  }
}

bool check(char *password) {
  bool lowerAlpha = false;
  bool upperAlpha = false;
  bool hasNum = false;
  bool hasSymbol = false;

  for (int i = 0; i < strlen(password); i++) {

    if (isalpha(password[i])) {
      if (islower(password[i])) {
        lowerAlpha = true;
      } else {
        upperAlpha = true;
      }
    }

    if (isdigit(password[i])) {
      hasNum = true;
    }

    if (ispunct(password[i])) {
      hasSymbol = true;
    }
  }

  if (lowerAlpha && upperAlpha && hasNum && hasSymbol) {
    return true;
  } else {
    return false;
  }
}
