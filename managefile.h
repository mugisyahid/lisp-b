#ifndef MANAGEFILE_H
#define MANAGEFILE_H

#include "ekspresi.h"
#include "boolean.h"

#define MAXLINE 1200
extern char line[MAXLINE];
extern FILE *f, *temp, *pftujuan;

void LoadFile(listoflist L);

void SaveFile(listoflist L);

void BacaFile(char *filesumber);

#endif