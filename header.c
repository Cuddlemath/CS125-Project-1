#include "header.h"
#include <stdio.h>
#include <stdlib.h>

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

void fillMadLib(char *curr_mad_lib[MAXWORDS]) {
  int i;
  char word[MAXWORDLENGTH];
  for (i = 0; i < sizeof(curr_mad_lib; i++)) {
    
  }
}