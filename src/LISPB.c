#include <stdio.h>

#include "bilangan.h"
#include "listoflist.h"
#include "fungsi.h"
#include "peubah.h"
#include "ekspresi.h"
#include "managefile.h"
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