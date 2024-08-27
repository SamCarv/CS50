#include <stdbool.h>
#include <stdio.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

typedef struct {
  char *name;
  int votes;
  bool eliminated;
} candidate;

int main(void) { candidate candidates[MAX_CANDIDATES]; }
