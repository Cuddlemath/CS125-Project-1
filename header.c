#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dispstats(int ml_num, int words) {
  printf("You have filled out %d Mad Libs!\n", ml_num);
  printf("You have used %d words!\n", words);
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void getMadLib(char *curr_mad_lib[MAXWORDS], int *ml_num) {
  FILE *mad_lib_text = fopen("empty_mad_libs.txt", "r");
  char line[100];
  int i = 0;

  while (curr_mad_lib[i][0] != '|' && fscanf(mad_lib_text, "%99s", line) == 1) {
    curr_mad_lib[i] = malloc(MAXWORDLENGTH);
    strcpy(curr_mad_lib[i], line);
    i++;
 	}
  
  curr_mad_lib[i] = NULL;
  fclose(mad_lib_text);
}

void fillMadLib(char *curr_mad_lib[], int *words_num) {
  int i, j;
  int end_of_sentence = 0;
  char word[MAXWORDLENGTH];
  
  clearInputBuffer();
  
  for(i = 0; curr_mad_lib[i] != NULL; i++) {
    if (curr_mad_lib[i][0] == '[') {
      for (j = 0; j < strlen(curr_mad_lib[i]); j++) {
        if (curr_mad_lib[i][j] == '.') {
          end_of_sentence = 1;
        }
      }
      
      printf("Please enter a %s: ", curr_mad_lib[i]);
      if (fgets(word, MAXWORDLENGTH, stdin) != NULL) {
        word[strcspn(word, "\n")] = '\0';
      }
      if (end_of_sentence == 1) {
        strcat(word, ".");
      }
      free(curr_mad_lib[i]);
      curr_mad_lib[i] = malloc(MAXWORDLENGTH);      
      strcpy(curr_mad_lib[i], word);
      (*words_num)++;
    }
    end_of_sentence = 0;    
  }
}