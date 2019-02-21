#include <stdio.h>
#include "ekspresi.h"

int main(){
	listoflist ListHasil;
	
	IdxVar = 0;
	Indeks = 0;
	
	CreateList(&ListEkspresi);
	CreateList(&ListHasil);
	
	InputEkspresi();
	
	Indeks = 0;
	
	ListEkspresi = ParsingEkspresi();
	
	//PrintList(ListEkspresi);
	
	ListHasil = EvaluasiEkspresi(ListEkspresi);
	
	PrintList(ListHasil);
	
	
	////////////////////////////////////////////////////////////////
	Indeks = 0;
	
	CreateList(&ListEkspresi);
	CreateList(&ListHasil);
	
	InputEkspresi();
	
	Indeks = 0;
	
	ListEkspresi = ParsingEkspresi();
	
	//PrintList(ListEkspresi);
	
	ListHasil = EvaluasiEkspresi(ListEkspresi);
	
	PrintList(ListHasil);
	
	return 0;
}