
#ifndef HEADER_H
#define HEADER_H

#define MAXWORDS 200
#define MAXWORDLENGTH 100
#define MAXLINE 256

void getMadLib(char *curr_mad_lib[MAXWORDS], int *ml_num);
void dispstats(int ml_num, int words);
void fillMadLib(char *curr_mad_lib[], int *words_num);
void clearInputBuffer();


#endif