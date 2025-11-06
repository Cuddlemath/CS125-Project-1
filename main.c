#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
  int menu = 0, ML_num = 0, Noun_num = 0, Verb_num = 0, Adj_num = 0, i = 0;
  char *current_mad_lib[MAXWORDS];
  FILE *mad_lib_text = fopen("empty_mad_libs.txt", "r");
  FILE *mad_lib_save;
  
  printf("Welcome to the Mad Lib Generator!\n");
  while (menu != 5) {
    printf("Choose a menu option!\n");
    printf("[1] Fill out a mad lib.\n");
    printf("[2] Print out complete mad libs.\n");
    printf("[3] Display stats.\n");
    printf("[4] Exit program and display final stats.\n");
    
    switch (menu) {
      case 1:
        getMadLib(current_mad_lib, ML_num, &Noun_num, &Verb_num, &Adj_num);
        ML_num++;
        
        mad_lib_save = fopen("mad_libs.txt", "w");
        while (current_mad_lib[i] != NULL) {
          fputs(current_mad_lib[i], mad_lib_save);
          if ((i+1)%10 == 0) {
            fputs("\n", mad_lib_save);
          }
          i++;
        }
        printf("Mad Lib saved to file.");
        fclose(mad_lib_save);
        break;
      case 2:
        mad_lib_save = fopen("mad_libs.txt", "r");
        fprintf(mad_lib_save); 
        fclose(mad_lib_save);
        break;
      case 3:
        dispstats(ML_num, Noun_num, Verb_num, Adj_num);
        break;
      case 4:
        printf("Thank you for using the Mad Lib Generator! Here are your final stats:")
        dispstats(ML_num, Noun_num, Verb_num, Adj_num);
        fclose(mad_lib_text);
        return 0;
      default:
        printf("Invalid menu option. Try again.");
    }
  }
  
}

void dispstats(int ml_num, int nouns, int verbs, int adjs) {
  printf("You have filled out %d Mad Libs!\n", ML_num);
  printf("You have used %d nouns!\n", Noun_num);
  printf("You have used %d verbs!\n", Verb_num);
  printf("You have used %d adjectives!\n", Adj_num);
}
        