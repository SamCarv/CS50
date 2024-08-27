#include <stdbool.h>
#include <stdio.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

bool vote(char *voter, int rank, char *name);

typedef struct {
  char *name;
  int votes;
  bool eliminated;
} candidate;

int voter_count;
int candidate_count;

int main(void) {
  candidate candidates[MAX_CANDIDATES];
  int preferences[MAX_VOTERS][MAX_CANDIDATES];
}

bool vote(char *voter, int rank, char *name) { return true; }
