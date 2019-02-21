#ifndef PEUBAH_H
#define PEUBAH_H

#include "listoflist.h"
#include "boolean.h"

#define MAXHURUF				1000

typedef struct {
    char* nama;
	infotype info;
} peubah_type;

#define Nama(V)				(V).nama
#define InfoPeubah(V) 		(V).info

extern peubah_type ListVar[MAXHURUF];
extern int IdxVar;

void CopyNama(char *Nama[],const char* Input);

boolean IsNamaSama(char* Nama1,const char* Nama2);

#endif