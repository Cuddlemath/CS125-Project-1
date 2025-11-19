/*
Names: Ronald Keyes and Kylee Walker
Due Date: 11/23/25
Description: Defines values and functions used in main.c and header.c
References: Looked at lecture on headers.
*/

#ifndef HEADER_H

#define MAXWORDS 200
#define MAXWORDLENGTH 100
#define MAXLINE 256

void getMadLib(char *curr_mad_lib[MAXWORDS], int *ml_num, int gamemode);
void dispstats(int ml_num, int Il_num, int words);
void fillMadLib(char *curr_mad_lib[], int *words_num);
void clearInputBuffer();


#endif