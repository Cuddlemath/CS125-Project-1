/*
Names: Ronald Keyes and Kylee Walker
Due Date: 11/23/25
Description: This program allows you to fill out mad libs, print out the ones you've completed, and it saves completed mad libs to a file. It loops through a menu until the user decides to end the program.
References: Googled new functions, ChatGPT'd some errors, Looked at some lectures.
*/

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int menu = 0, ML_num = 0, IL_num, ML_rand_num = 0, Word_num = 0, i, Gamemode = 0;
  /* Using a character pointer array was giving issues, so we allocate it like this so we can use a character double pointer like a character pointer array. */
  char **current_mad_lib = malloc(MAXWORDS * sizeof(char *)); 
  if (!current_mad_lib) {
    printf("Memory error!\n");
    return 1;
  }
  /* We want to make a new file every time the program runs, as it just add to the previous file. */
  char line[MAXLINE];
  char fileName[MAXLINE];
  char fileNameWithDirectory[MAXLINE] = "Mad_Libs/";
  FILE *mad_lib_save;
  srand(time(0));
  
  printf("\nWelcome to the Mad Lib Generator!\n");
  printf("We have a new gamemode!\n"); 
  printf("Instead of just words not making sense, the whole sentence makes no sense!\n");
  printf("It's called INSANE Libs. You can choose the gamemode in the menu.\n\n");
  printf("Before we start, \nPlease enter a file name for the text file where your filled out libs will be saved.\n");
  printf("Note, if you enter the name of an existing file the libs will be appended on the end: ");
  fgets(fileName, MAXLINE, stdin);
  fileName[strcspn(fileName, "\n")] = '\0';
  strcat(fileName, ".txt");
  strcat(fileNameWithDirectory, fileName);
  
  while (menu != 5) {
    menu = 0;
    printf("\n\nChoose a menu option!\n");
    printf("[1] Fill out a mad lib.\n");
    printf("[2] Fill out an INSANE lib.\n");
    printf("[3] Print out your text file.\n");
    printf("[4] Display stats.\n");
    printf("[5] Exit program and display final stats.\n");
    scanf("%d", &menu);
    clearInputBuffer();
    
    switch (menu) {
      case 1:
        for (i = 0; current_mad_lib[i] != NULL; i++) {
          free(current_mad_lib[i]);
        }
        current_mad_lib[0] = NULL;
        
        ML_rand_num = rand() % 150 + 1; /* We randomize every time so that running the program again rarely gives the same mad lib */
        printf("ML_rand_num\n");
        printf("%d\n", ML_rand_num);
        Gamemode = 1;
        getMadLib(current_mad_lib, &ML_rand_num, Gamemode);
        ML_num++;
        
        fillMadLib(current_mad_lib, &Word_num);
        
        mad_lib_save = fopen(fileNameWithDirectory, "a");
        i = 0;
        fprintf(mad_lib_save, "This is Lib number %d, Mad Lib number %d:\n", (ML_num + IL_num), ML_num);
        while (current_mad_lib[i] != NULL) {
          fprintf(mad_lib_save, "%s", current_mad_lib[i]);
          /* We want a space after every word and a new line after every 10 words for better formating */
          fputs(" ", mad_lib_save);
          if ((i+1)%10 == 0) {
            fputs("\n", mad_lib_save);
          }
          i++;
        }
        fputs("\n\n", mad_lib_save);
        printf("Mad Lib saved to %s", fileNameWithDirectory);
        fclose(mad_lib_save);
        break;
      case 2: /* Same as case 1 except for INSANE Libs */
        for (i = 0; current_mad_lib[i] != NULL; i++) {
          free(current_mad_lib[i]);
        }
        current_mad_lib[0] = NULL;
        
        ML_rand_num = rand() % 150 + 1;
        printf("ML_rand_num\n");
        printf("%d\n", ML_rand_num);
        Gamemode = 2;
        getMadLib(current_mad_lib, &ML_rand_num, Gamemode);
        IL_num++;
        
        fillMadLib(current_mad_lib, &Word_num);
        
        mad_lib_save = fopen(fileNameWithDirectory, "a");
        i = 0;
        fprintf(mad_lib_save, "This is Lib number %d, INSANE Lib number %d:\n", (ML_num + IL_num), IL_num);
        while (current_mad_lib[i] != NULL) {
          fprintf(mad_lib_save, "%s", current_mad_lib[i]);
          fputs(" ", mad_lib_save);
          if ((i+1)%10 == 0) {
            fputs("\n", mad_lib_save);
          }
          i++;
        }
        fputs("\n\n", mad_lib_save);
        printf("Mad Lib saved to %s", fileNameWithDirectory);
        fclose(mad_lib_save);
        break;
      case 3:
        printf("\n");
        mad_lib_save = fopen(fileNameWithDirectory, "r");
        while (fgets(line, MAXLINE, mad_lib_save) != NULL) {
    		  printf("%s", line);
        }
				fclose(mad_lib_save);
        printf("\n\n");
        break;
      case 4:
        dispstats(ML_num, IL_num, Word_num);
        break;
      case 5:
        printf("Thank you for using the Mad Lib Generator! \nHere are your final stats:\n");
        dispstats(ML_num, IL_num, Word_num);
        return 0;
      default:
        printf("Invalid menu option. Try again.");
    }
  }
  for (i = 0; current_mad_lib[i] != NULL; i++) {
    free(current_mad_lib[i]);
  }
  free(current_mad_lib);
  return 0;
}

