#include <stdio.h>

double calc_hours(int hours[], int weekTotal, char output);

int main(void) {
  int numWeek;

  // Prompt the user for the number of weeks and read it
  printf("Number of weeks taking CS50: ");
  scanf("%d", &numWeek);

  // Create the hours array with the specified size
  int hours[numWeek];

  // Read the hours for each week
  for (int i = 0; i < numWeek; i++) {
    int num = 0;
    printf("Week %d HW Hours: ",
           i + 1); // Changed to i + 1 for user-friendly display
    scanf("%d", &num);
    hours[i] = num;
  }

  // Clear the newline character from the input buffer
  while (getchar() != '\n')
    ;

  char option;
  printf("Enter T for total hours, A for average hours per week: ");
  scanf("%c", &option);

  double result = calc_hours(hours, numWeek, option);

  printf("%f hours\n", result); // Added newline for better output formatting
}

double calc_hours(int hours[], int weekTotal, char output) {
  double total = 0;

  // Calculate the total hours
  for (int i = 0; i < weekTotal; i++) {
    total += hours[i];
  }

  // Return either total or average based on user choice
  if (output == 'T') {
    return total;
  } else if (output == 'A') {
    return total / weekTotal;
  }

  return 0; // Changed from 1 to 0 for clarity in return value
}
