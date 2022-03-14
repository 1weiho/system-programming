#include <stdio.h>

int main() {
  int i, j;
  int output;
  int next;
  int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // First row
  printf("    ");
  for (i = 0; i < 9; i++) {
    printf("%d", num[i]);
    if (i < 8) {
      printf("   ");
    } else {
      printf("\n");
    }
  }

  // table
  for (i = 0; i < 9; i++) {
    printf("%d   ", num[i]);
    for (j = 0; j < 9; j++) {
      output = num[i] * num[j];
      printf("%d", output);
      if (j < 8) {
        next = num[i] * num[j + 1];
        if (next / 10 > 0) {
          printf("  ");
        } else {
          printf("   ");
        }
      } else {
        printf("\n");
      }
    }
  }
}