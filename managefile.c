#include <stdio.h>
#include <stdlib.h>
#include "managefile.h"

FILE *f, *temp, *pftujuan;

void LoadFile(listoflist L)
{
	int Idx1, Idx2;
	infotype firstElmt;

	firstElmt = FirstElmt(Next(L));
	BacaFile(Peubah(firstElmt));
	while (fgets(Input, sizeof(Input), f) != NULL)
	{
		Idx1 = 0;
		do
		{
			Idx2 = 0;
			do
			{
				Ekspresi[Idx1++] = Input[Idx2++];
			} while (Input[Idx2] != MARK && Input[Idx2] != '\n');
			if (!IsEkspresiEnd())
			{
				Ekspresi[Idx1++] = BLANK;
			}
			else
			{
				break;
			}
		} while (fgets(Input, sizeof(Input), f) != NULL);
		Indeks = 0;
		ListEkspresi = ParsingEkspresi();
		ListEkspresi = EvaluasiEkspresi(ListEkspresi);
		PrintList(ListEkspresi);
		printf("\n");
	}

	fclose(f);
}

void BacaFile(char *filesumber)
{
	f = fopen(filesumber, "r");
	if (f == NULL)
	{
		puts("File tidak ada!");
	}
}

void SaveFile(listoflist L)
{
	char *S;
	int i;
	infotype firstElmt;

	firstElmt = FirstElmt(Next(L));
	fclose(temp);
	temp = fopen("_temp.txt", "a+");
	S = (char *)malloc(sizeof(char));
	pftujuan = fopen(Peubah(firstElmt), "w+");
	while (fgets(S, sizeof(S), temp) != NULL)
	{
		fputs(S, pftujuan);
	}
	fclose(pftujuan);
}