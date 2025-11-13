
#ifndef HEADER_H
#define HEADER_H

#define MAXWORDS 200
#define MAXWORDLENGTH 100
#define MAXLINE 256

void getMadLib(char *curr_mad_lib[MAXWORDS], int ml_num, int *nouns, int *verbs, int *adjs);
void dispstats(int ml_num, int words, int nouns, int verbs, int adjs);
void fillMadLib(char *curr_mad_lib[]);


#endif