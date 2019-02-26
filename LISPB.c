#include <stdio.h>

#include "bilangan.c"
#include "listoflist.c"
#include "fungsi.c"
#include "peubah.c"
#include "ekspresi.c"
#include "managefile.c"
#include "boolean.h"

int main()
{
	int baris;

	remove("_temp.txt");
	temp = fopen("_temp.txt", "a+");
	baris = 1;
	IdxVar = 0;

	printf("LISPB\n");
	for (;;)
	{
		Indeks = 0;
		CreateList(&ListEkspresi);
		printf("[%d]> ", baris);
		InputEkspresi();
		fputs(Ekspresi, temp);
		fputs("\n", temp);
		Indeks = 0;
		ListEkspresi = ParsingEkspresi();
		ListEkspresi = EvaluasiEkspresi(ListEkspresi);
		PrintList(ListEkspresi);
		baris++;
		printf("\n");
	}

	return 0;
}