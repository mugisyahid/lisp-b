#include <stdio.h>
#include "peubah.h"
#include "listoflist.h"

peubah_type ListVar[MAXHURUF];
int IdxVar;

void CopyNama(char *Nama[], const char* Input){
	int Idx;
	
	Idx = 0;
	do {
		(*Nama)[Idx] = Input[Idx];
	} while(Input[Idx++] != '\0');
	(*Nama)[Idx] = '\0';
}

boolean IsNamaSama(char* Nama1, const char* Nama2){
	int Idx;
	
	Idx = 0;
	
	while(Nama1[Idx] == Nama2[Idx] && Nama1[Idx] != '\0' && Nama2[Idx] != '\0'){
		Idx++;
	}
	
	return (Nama1[Idx] == '\0' && Nama2[Idx] == '\0');
}