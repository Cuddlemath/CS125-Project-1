/*
Names: Ronald Keyes and Kylee Walker
Due Date: 11/23/25
Description: All the functions that are called in main.c
References: Googled new functions, ChatGPT'd some errors, Looked at some lectures.
*/

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void dispstats(int ml_num, int Il_num, int words) {
  printf("You have filled out %d Libs!\n", (ml_num + Il_num));
  printf("Out of those, %d were Mad and %d were Insane!", ml_num, Il_num);
  printf("You have used %d words!\n", words);
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void getMadLib(char *curr_mad_lib[MAXWORDS], int *ml_num, int gamemode) {
  FILE *mad_lib_text;
  if (gamemode == 1) {
    mad_lib_text = fopen("empty_mad_libs.txt", "r");
  }
  else {
    mad_lib_text = fopen("empty_INSANE_libs.txt", "r");
  }
  
  char line[100];
  int i = 0;
  
  for (i = 1; i < *ml_num; i++) {
    while (fscanf(mad_lib_text, "%99s", line) == 1 && line[0] != '~');
    /* In the empty libs files, the ~ separates each lib. */
  }

  i = 0;
  while (fscanf(mad_lib_text, "%99s", line) == 1 && line[0] != '~') {
    curr_mad_lib[i] = malloc(MAXWORDLENGTH);
    strcpy(curr_mad_lib[i], line);
    i++;
 	}
  curr_mad_lib[i] = NULL;
  fclose(mad_lib_text);
}

void fillMadLib(char *curr_mad_lib[], int *words_num) {
  int i, j, end_period = 0, end_question = 0, end_exclamation = 0, end_comma = 0, try_again = 0;
  char word[MAXWORDLENGTH];
  
  /* To ensure replacing the words doesn't get rid of punctuation, we have to check for each and add them back at the end. */
  for(i = 0; curr_mad_lib[i] != NULL; i++) {
    if (curr_mad_lib[i][0] == '[') {
      for (j = 0; j < strlen(curr_mad_lib[i]); j++) {
        if (curr_mad_lib[i][j] == '.') {
          end_period = 1;
          curr_mad_lib[i][j] = '\0';
        }
        else if (curr_mad_lib[i][j] == '?') {
          end_question = 1;
          curr_mad_lib[i][j] = '\0';
        }
        else if (curr_mad_lib[i][j] == '!') {
          end_exclamation = 1;
          curr_mad_lib[i][j] = '\0';
        }
        else if (curr_mad_lib[i][j] == ',') {
          end_comma = 1;
          curr_mad_lib[i][j] = '\0';
        }
      }
      
      printf("Please enter a %s: ", curr_mad_lib[i]);
      if (fgets(word, MAXWORDLENGTH, stdin) != NULL) {
        if (strlen(word) > 0 && word[strlen(word) - 1] == '\n') {
          word[strlen(word) - 1] = '\0';
        } 
        else {
          clearInputBuffer();
          word[strlen(word) - 1] = '\0';
        }
        if (strlen(word) == 0) {
          try_again = 1;
        }
      }
      
      if (end_period == 1) {
        strcat(word, ".");
      }
      else if (end_question == 1) {
        strcat(word, "?");
      }
      else if (end_exclamation == 1) {
        strcat(word, "!");
      }
      else if (end_comma == 1) {
        strcat(word, ",");
      }
      if (try_again != 1) {
        free(curr_mad_lib[i]);
        curr_mad_lib[i] = malloc(MAXWORDLENGTH);      
        strcpy(curr_mad_lib[i], word);
        (*words_num)++;
      }
      else {
        printf("No input, try again!\n");
        i--;
      }
    }
    end_period = 0, end_question = 0, end_exclamation = 0, end_comma = 0, try_again = 0;
  }
}