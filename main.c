#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int menu = 0, ML_num = 0, Word_num = 0, Noun_num = 0, Verb_num = 0, Adj_num = 0, i = 0;
  char *current_mad_lib[MAXWORDS];
  FILE *mad_lib_save;
  
  printf("Welcome to the Mad Lib Generator!\n");
  while (menu != 5) {
    printf("Choose a menu option!\n");
    printf("[1] Fill out a mad lib.\n");
    printf("[2] Print out complete mad libs.\n");
    printf("[3] Display stats.\n");
    printf("[4] Exit program and display final stats.\n");
    scanf("%d", &menu);
    
    switch (menu) {
      case 1:
        getMadLib(current_mad_lib, ML_num, &Noun_num, &Verb_num, &Adj_num);
        ML_num++;
        
        fillMadLib(current_mad_lib);
        
        mad_lib_save = fopen("mad_libs.txt", "w");
        while (current_mad_lib[i] != NULL) {
          fputs(current_mad_lib[i], mad_lib_save);
          fputs(" ", mad_lib_save);
          if ((i+1)%10 == 0) {
            fputs("\n", mad_lib_save);
          }
          i++;
        }
        printf("Mad Lib saved to file.");
        fclose(mad_lib_save);
        break;
      case 2:
        mad_lib_save = fopen("mad_libs.txt", "w");
        for (i = 0; i < sizeof(current_mad_lib); i++) {
        		fprintf(mad_lib_save, "%s", current_mad_lib[i]); 
        }
				fclose(mad_lib_save);
        break;
      case 3:
        dispstats(ML_num, Word_num, Noun_num, Verb_num, Adj_num);
        break;
      case 4:
        printf("Thank you for using the Mad Lib Generator! Here are your final stats:");
        dispstats(ML_num, Word_num, Noun_num, Verb_num, Adj_num);
        return 0;
      default:
        printf("Invalid menu option. Try again.");
    }
  }
  return 0;
}

