#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dispstats(int ml_num, int words, int nouns, int verbs, int adjs) {
  printf("You have filled out %d Mad Libs!\n", ml_num);
  printf("You have used %d words!\n", words);
  /*
  printf("You have used %d nouns!\n", nouns);
  printf("You have used %d verbs!\n", verbs);
  printf("You have used %d adjectives!\n", adjs);
  */
}

void getMadLib(char *curr_mad_lib[MAXWORDS], int ml_num, int *nouns, int *verbs, int *adjs) {
  FILE *mad_lib_text = fopen("empty_mad_libs.txt", "r");
  int i = 0;

  while (i < MAXWORDS && !feof(mad_lib_text)) {
    curr_mad_lib[i] = (char *)malloc(sizeof(char) * MAXWORDLENGTH);

	if (fscanf(mad_lib_text, "%99s", curr_mad_lib[i]) == 1) {
            i++;
        } else {
            free(curr_mad_lib[i]);
            break;
        }
  }
}

void fillMadLib(char *curr_mad_lib[]) {
  int i;
  char word[MAXWORDLENGTH];
  
  while (getchar() != '\n'){
    getchar();
  }
  
  for(i = 0; curr_mad_lib[i] != NULL; i++) {
    if (curr_mad_lib[i][0] == '(') {
      printf("Please enter a %s: ", curr_mad_lib[i]);
      if (fgets(word, MAXWORDLENGTH, stdin) != NULL) {
        word[strcspn(word, "\n")] = '\0';
      }
      strcpy(curr_mad_lib[i], word);
    }
  }
}