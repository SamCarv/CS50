#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

bool vote(int voter, int rank, char *name);
void tabulate();
int find_min();
bool is_tie(int min);
void eliminate(int min);

typedef struct {
  char *name;
  int votes;
  bool eliminated;
} candidate;

int voter_count = 0;
int candidate_count = 0;

candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];

int main(int argc, char *argv[]) {

  if (argc <= 1) {
    printf("Usage: runoff [candidate ...]\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    candidates[i - 1].name = argv[i];
    candidates[i - 1].votes = 0;
    candidates[i - 1].eliminated = false;
  }

  candidate_count = argc - 1;

  printf("Number of voters: ");
  scanf("%i", &voter_count);

  char cand_name[20];

  for (int i = 0; i < voter_count; i++) {
    int vote_points = 3;
    for (int j = 0; j < candidate_count; j++) {
      vote_points--;
      printf("Rank %i: ", (j + 1));
      scanf("%19s", cand_name);
      if (!vote(i, vote_points, cand_name)) {
        printf("Invalid vote.");
      }
    }
    printf("\n");
  }

  tabulate();
  printf("Min: %i\n", find_min());

  for (int i = 0; i < candidate_count; i++) {
    printf("%s\n", candidates[i].name);
    printf("%i\n", candidates[i].votes);
    printf("%i\n", candidates[i].eliminated);
  }
}

bool vote(int voter, int rank, char *name) {
  for (int i = 0; i < candidate_count; i++) {
    if (strcmp(name, candidates[i].name) == 0) {
      preferences[voter][rank] = i;
      return true;
    }
  }
  return false;
}

void tabulate() {
  for (int i = 0; i < candidate_count; i++) {
    for (int j = 0; j < candidate_count; j++) {
      candidates[i].votes += preferences[j][i];
    }
  }
}

int find_min() {
  int min = 0;

  for (int i = 0; i < candidate_count; i++) {
    if (candidates[i].eliminated == 0) {
      if (min < candidates[i].votes) {
        min = candidates[i].votes;
      }
    }
  }
  return min;
}

bool is_tie(int min) {
  int total_tie = 0;
  int candidates_rem = 0;
  for (int i = 0; i < candidate_count; i++) {
    if (candidates[i].eliminated == false) {
      candidates_rem++;
      if (candidates[i].votes == min) {
        total_tie++;
      }
    }
  }

  if (total_tie == candidates_rem) {
    return true;
  } else {
    return false;
  }
}

void eliminate(int min) {
  for (int i = 0; i < candidate_count; i++) {
    if (candidates[i].votes == min) {
      candidates[i].eliminated = true;
    }
  }
}

void print_winner() {
  float half_votes = voter_count * voter_count / 2.0;
  for (int i = 0; i < candidate_count; i++) {
    if (candidates[i].eliminated == false) {
      if (candidates[i].votes > half_votes) {
        printf("%s", candidates[i].name);
      }
    }
  }
}
