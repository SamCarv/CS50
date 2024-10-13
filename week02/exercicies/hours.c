#include <stdio.h>

double calc_hours(int hours[], int weekTotal, char output);

int main(void) {
  int numWeek;

  printf("Number of weeks taking CS50: ");
  scanf("%d", &numWeek);

  int hours[numWeek];

  for (int i = 0; i < numWeek; i++) {
    int num = 0;
    printf("Week %d HW Hours: ", i + 1);
    scanf("%d", &num);
    hours[i] = num;
  }

  while (getchar() != '\n')
    ;

  char option;
  printf("Enter T for total hours, A for average hours per week: ");
  scanf("%c", &option);

  double result = calc_hours(hours, numWeek, option);

  printf("%f hours\n", result);
}

double calc_hours(int hours[], int weekTotal, char output) {
  double total = 0;

  for (int i = 0; i < weekTotal; i++) {
    total += hours[i];
  }

  if (output == 'T') {
    return total;
  } else if (output == 'A') {
    return total / weekTotal;
  }

  return 0;
}
