#include <stdio.h>
#include <stdlib.h>
#include "ekspresi.h"

char Input[MAX];
char Ekspresi[MAX];
char CS[MAX];
int Indeks;
listoflist ListEkspresi;
int IdxEval;

boolean IsEkspresiEnd()
{
	int i;

	i = 0;
	while (Input[i] != EOE)
	{
		i++;
	}

	return Input[i] == EOE;
}

void InputEkspresi()
{
	int i;

	i = 0;
	gets(Input);

	do
	{
		Ekspresi[Indeks++] = Input[i++];
	} while (Input[i] != EOE);

	if (!IsEkspresiEnd())
	{
		Ekspresi[Indeks++] = BLANK;
		InputEkspresi();
	}
}

void PrintEkspresi()
{
	int i;

	i = 0;
	do
	{
		printf("%c", Ekspresi[i++]);
	} while (Ekspresi[i] != EOE);
}

void IgnoreBlank()
{
	while (Ekspresi[Indeks] == BLANK && Ekspresi[Indeks] != '(')
	{
		Indeks++;
	}
}

void Advance()
{
	int i;

	i = 0;

	IgnoreBlank();
	while (Ekspresi[Indeks] != BLANK && Ekspresi[Indeks] != LB && Ekspresi[Indeks] != RB && Ekspresi[Indeks] != MARK)
	{
		CS[i++] = Ekspresi[Indeks++];
	}
	CS[i] = EOE;
}

listoflist ParsingEkspresi()
{
	listoflist Ltemp;
	infotype Inf;

	CreateList(&Ltemp);
	IgnoreBlank();
	if (Ekspresi[Indeks] == '(')
	{
		Indeks++;
		while (Ekspresi[Indeks] != ')')
		{
			Advance();
			if (Ekspresi[Indeks] == '(')
			{
				List(Inf) = ParsingEkspresi();
				TipeInfo(Inf) = LIST;
				Indeks++;
			}
			else
			{
				KonsdEkspresi(&Inf);
			}
			Ltemp = Konsd(Ltemp, Inf);
		}
	}
	else
	{
		Advance();
		KonsdEkspresi(&Inf);
		Ltemp = Konsd(Ltemp, Inf);
	}
	return Ltemp;
}

void KonsdEkspresi(infotype *Inf)
{
	int Idx;
	bilangan_type Bil;
	Idx = 0;
	if (TipeEkspresi() == KATA)
	{
		if (CS[Idx] == 'T')
		{
			Bool(*Inf) = true;
			TipeInfo(*Inf) = BOOL;
		}
		else if (CS[Idx] == 'F')
		{
			Bool(*Inf) = false;
			TipeInfo(*Inf) = BOOL;
		}
		else if (IsFUNGSI(CS))
		{
			do
			{
				(Fungsi(*Inf))[Idx] = CS[Idx];
			} while (CS[Idx] != EOE && CS[Idx++] != MARK);
			TipeInfo(*Inf) = FUNGSI;
		}
		else
		{
			do
			{
				(Peubah(*Inf))[Idx] = CS[Idx];
			} while (CS[Idx] != EOE && CS[Idx++] != MARK);
			TipeInfo(*Inf) = PEUBAH;
		}
	}
	else if (TipeEkspresi() == ANGKA)
	{
		KonvertToInteger(&Bil);
		Bilangan(*Inf) = Bil;
		TipeInfo(*Inf) = BILANGAN;
	}
}

int TipeEkspresi()
{
	int i;

	i = 0;
	if ((48 <= CS[i] && CS[i] <= 57) || (CS[i] == 45 && 48 <= CS[i + 1] && CS[i + 1] <= 57))
	{
		return ANGKA;
	}
	else if ((33 <= CS[i] && CS[i] <= 47) || (58 <= CS[i] && CS[i] <= 126))
	{
		return KATA;
	}
}

void KonvertToInteger(bilangan_type *Bil)
{
	int i, Idx, Angka, Angka1, counter;
	float Desimal;
	boolean Negatif;

	Idx = 0;
	Angka = 0;
	Angka1 = 0;
	Desimal = 0;
	counter = 0;
	Negatif = false;

	if (CS[Idx] == MINUS)
	{
		Negatif = true;
		Idx++;
	}

	while (CS[Idx] != EOE && CS[Idx] != DOT && CS[Idx] != SLASH)
	{
		Angka = CS[Idx++] - 48 + 10 * Angka;
	}
	if (CS[Idx] == DOT)
	{
		Idx++;
		Desimal = (riil_type)Angka;
		while (CS[Idx] != EOE)
		{
			Desimal = CS[Idx++] - 48 + 10 * Desimal;
			counter++;
		}
		for (i = 1; i <= counter; i++)
		{
			Desimal = Desimal / 10;
		}
		if (Negatif)
		{
			Desimal = Desimal * (-1);
		}
		Riil(*Bil) = Desimal;
		TipeInfo(*Bil) = RIIL;
	}
	else if (CS[Idx] == SLASH)
	{
		Idx++;
		while (CS[Idx] != EOE)
		{
			Angka1 = CS[Idx++] - 48 + 10 * Angka1;
		}
		if (Negatif)
		{
			Angka = Angka * (-1);
		}
		Pecahan(*Bil) = MakePecahan(Angka, Angka1);
		TipeInfo(*Bil) = PECAHAN;
	}
	else
	{
		if (Negatif)
		{
			Angka = Angka * (-1);
		}
		Bulat(*Bil) = Angka;
		TipeInfo(*Bil) = BULAT;
	}
}

///////////////////////////////////////////////////////////////////////////////

listoflist EvaluasiEkspresi(listoflist L)
{
	listoflist LHasil;
	int Fun;
	infotype Inf, firstElmt;

	if (IdxEval > 0)
	{
		printf("%d=> ", IdxEval);
		PrintList(L);
		printf("\n");
		IdxEval++;
	}

	if (TipeInfo(FirstElmt(L)) == LIST)
	{
		LHasil = EvaluasiEkspresi(List(FirstElmt(L)));
	}
	else if (TipeInfo(FirstElmt(L)) == PEUBAH)
	{
		LHasil = EvaluasiPeubah(L);
	}
	else if (TipeInfo(FirstElmt(L)) != FUNGSI)
	{
		LHasil = L;
	}
	else if (TipeInfo(FirstElmt(L)) == FUNGSI)
	{
		firstElmt = FirstElmt(L);
		Fun = IsFUNGSI(Fungsi(firstElmt));
		if (1 <= Fun && Fun <= 7)
		{
			LHasil = EvaluasiAritmetika(L);
		}
		else if (8 <= Fun && Fun <= 18)
		{
			LHasil = EvaluasiBoolean(L);
		}
		else if (Fun == 19)
		{
			LHasil = EvaluasiIf(L);
		}
		else if (Fun == 20)
		{
			LHasil = EvaluasiCond(L);
		}
		else if (21 <= Fun && Fun <= 30)
		{
			LHasil = EvaluasiList(L);
		}
		else if (31 <= Fun && Fun <= 35)
		{
			LHasil = EvaluasiLain(L);
		}
	}

	if (IdxEval > 0)
	{
		printf("%d=> ", IdxEval);
		PrintList(LHasil);
		printf("\n");
		IdxEval--;
	}
	return LHasil;
}

listoflist EvaluasiPeubah(listoflist L)
{
	listoflist LHasil;
	infotype Inf, firstElmt;
	int i;

	i = 0;
	CreateList(&LHasil);
	firstElmt = FirstElmt(L);
	while (i < IdxVar && !IsNamaSama(Nama(ListVar[i]), Peubah(firstElmt)))
	{
		i++;
	}
	if (IsNamaSama(Nama(ListVar[i]), Peubah(firstElmt)))
	{
		Inf = InfoPeubah(ListVar[i]);
		LHasil = Konso(Inf, LHasil);
	}
	return LHasil;
}

listoflist EvaluasiLain(listoflist L)
{
	int Fun;
	infotype firstElmt;

	firstElmt = FirstElmt(L);
	Fun = IsFUNGSI(Fungsi(firstElmt));
	if (Fun == 31)
	{
		LoadFile(L);
	}
	else if (Fun == 32)
	{
		SaveFile(L);
	}
	else if (Fun == 33)
	{
		fclose(f);
		fclose(temp);
		remove("_temp.txt");
		printf("Bye!");
		exit(EXIT_SUCCESS);
	}
	else if (Fun == 34)
	{
		return Setq(L);
	}
	else if (Fun == 35)
	{
		IdxEval = 1;
		return EvaluasiEkspresi(Next(L));
	}
}

listoflist Setq(listoflist L)
{
	listoflist L1;
	peubah_type Var;
	int Idx;
	infotype firstElmt;

	firstElmt = FirstElmt(Next(L));
	Idx = 0;
	L1 = EvaluasiEkspresi(Next(Next(L)));
	Nama(Var) = (char *)malloc(sizeof(Peubah(firstElmt)));
	CopyNama(&(Nama(Var)), Peubah(firstElmt));
	InfoPeubah(Var) = FirstElmt(L1);
	if (IdxVar == 0)
	{
		ListVar[Idx] = Var;
		IdxVar++;
	}
	else
	{
		while (Idx < IdxVar && !IsNamaSama(Nama(ListVar[Idx]), Nama(Var)))
		{
			Idx++;
		}
		ListVar[Idx] = Var;
		if (Idx == IdxVar)
		{
			IdxVar++;
		}
	}
	return L1;
}

listoflist EvaluasiList(listoflist L)
{
	int Fun;
	infotype firstElmt;

	firstElmt = FirstElmt(L);
	Fun = IsFUNGSI(Fungsi(firstElmt));
	if (Fun == 21)
	{
		return CarZ(L);
	}
	else if (Fun == 22)
	{
		return CdrZ(L);
	}
	else if (Fun == 23)
	{
		return ConsZ(L);
	}
	else if (Fun == 24)
	{
		return ListZ(L);
	}
	else if (Fun == 25)
	{
		return AppendZ(L);
	}
	else if (Fun == 26)
	{
		return ReverseZ(L);
	}
	else if (Fun == 27)
	{
		return AtomZ(L);
	}
	else if (Fun == 28)
	{
		return ListpZ(L);
	}
	else if (Fun == 29)
	{
		return NullZ(L);
	}
	else if (Fun == 30)
	{
		return EqualZ(L);
	}
}

listoflist CarZ(listoflist L)
{
	listoflist L1;
	address P;

	L1 = EvaluasiEkspresi(Next(L));
	P = Alokasi(FirstElmt(List(FirstElmt(L1))));
	return P;
}

listoflist CdrZ(listoflist L)
{
	listoflist L1, LHasil;
	infotype Inf;
	address P;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	P = Next(List(FirstElmt(L1)));
	List(Inf) = P;
	TipeInfo(Inf) = LIST;
	return Konso(Inf, LHasil);
}

listoflist ConsZ(listoflist L)
{
	listoflist L1, L2, LHasil;
	infotype Inf;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	L2 = EvaluasiEkspresi(Next(Next(L)));
	List(Inf) = Konso(FirstElmt(L1), List(FirstElmt(L2)));
	TipeInfo(Inf) = LIST;
	return Konso(Inf, LHasil);
}

listoflist ListZ(listoflist L)
{
	listoflist L1, LHasil;
	address P, P1;
	infotype Inf;

	CreateList(&LHasil);
	CreateList(&(List(Inf)));
	P = Next(L);
	if (P == nil)
	{
		List(Inf) = P;
	}
	else
	{
		while (P != nil)
		{
			CreateList(&L1);
			P1 = Alokasi(Info(P));
			L1 = EvaluasiEkspresi(P1);
			List(Inf) = Concat(List(Inf), L1);
			P = Next(P);
		}
	}
	TipeInfo(Inf) = LIST;
	LHasil = Konso(Inf, LHasil);
	return LHasil;
}

listoflist AppendZ(listoflist L)
{
	listoflist L1, L2, LHasil;
	infotype Inf;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	L2 = EvaluasiEkspresi(Next(Next(L)));
	List(Inf) = Concat(List(FirstElmt(L1)), List(FirstElmt(L2)));
	TipeInfo(Inf) = LIST;
	return Konso(Inf, LHasil);
}

listoflist ReverseZ(listoflist L)
{
	listoflist L1, LHasil;
	infotype Inf;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	List(Inf) = InversList(List(FirstElmt(L1)));
	TipeInfo(Inf) = LIST;
	return Konso(Inf, LHasil);
}

listoflist AtomZ(listoflist L)
{
	listoflist L1, LHasil;
	infotype Inf;
	boolean B;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	B = TipeInfo(FirstElmt(L1)) != LIST;
	Bool(Inf) = B;
	TipeInfo(Inf) = BOOL;
	return Konso(Inf, LHasil);
}

listoflist ListpZ(listoflist L)
{
	listoflist L1, LHasil;
	infotype Inf;
	boolean B;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	B = TipeInfo(FirstElmt(L1)) == LIST;
	Bool(Inf) = B;
	TipeInfo(Inf) = BOOL;
	return Konso(Inf, LHasil);
}

listoflist NullZ(listoflist L)
{
	listoflist L1, LHasil;
	infotype Inf;
	boolean B;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	B = IsListEmpty(List(FirstElmt(L1)));
	Bool(Inf) = B;
	TipeInfo(Inf) = BOOL;
	return Konso(Inf, LHasil);
}

listoflist EqualZ(listoflist L)
{
	listoflist L1, L2, LHasil;
	infotype Inf;
	boolean B;

	CreateList(&LHasil);
	L1 = EvaluasiEkspresi(Next(L));
	L2 = EvaluasiEkspresi(Next(Next(L)));
	B = IsEqual(List(FirstElmt(L1)), List(FirstElmt(L2)));
	Bool(Inf) = B;
	TipeInfo(Inf) = BOOL;
	return Konso(Inf, LHasil);
}

listoflist EvaluasiCond(listoflist L)
{
	listoflist L1;
	boolean B1;
	address P;

	B1 = false;
	P = Next(L);

	while (P != nil && !B1)
	{
		L1 = EvaluasiEkspresi(List(FirstElmt(List(FirstElmt(P)))));
		B1 = Bool(FirstElmt(L1));
		if (B1)
		{
			return EvaluasiEkspresi(List(FirstElmt(Next(List(FirstElmt(P))))));
		}
		P = Next(P);
	}
}

listoflist EvaluasiIf(listoflist L)
{
	listoflist L1;
	boolean B1;

	if (TipeInfo(FirstElmt(Next(L))) == LIST)
	{
		L1 = EvaluasiEkspresi(List(FirstElmt(Next(L))));
		B1 = Bool(FirstElmt(L1));
		if (B1)
		{
			return EvaluasiEkspresi(List(FirstElmt(Next(Next(L)))));
		}
		else
		{
			return EvaluasiEkspresi(List(FirstElmt(Next(Next(Next(L))))));
		}
	}
}

listoflist EvaluasiBoolean(listoflist L)
{
	int Fun;
	infotype firstElmt;

	firstElmt = FirstElmt(L);
	Fun = IsFUNGSI(Fungsi(firstElmt));
	if (8 <= Fun && Fun <= 13)
	{
		return EvaluasiRelasional(L);
	}
	else if (14 <= Fun && Fun <= 16)
	{
		return EvaluasiLojik(L);
	}
}

listoflist EvaluasiLojik(listoflist L)
{
	listoflist L1, L2, LHasil;
	infotype Inf, Inf1, firstElmt;
	boolean B1, B2, BHasil;
	int Fun;

	CreateList(&LHasil);
	if (Next(L) != nil && Next(Next(L)) == nil)
	{
		Bool(Inf) = true;
		TipeInfo(Inf) = BOOL;
		L = Konsd(L, Inf);
	}
	firstElmt = FirstElmt(L);
	Fun = IsFUNGSI(Fungsi(firstElmt));
	L1 = EvaluasiEkspresi(Next(L));
	L2 = EvaluasiEkspresi(Next(Next(L)));
	B1 = Bool(FirstElmt(L1));
	B2 = Bool(FirstElmt(L2));
	if (Fun == 14)
	{
		BHasil = (B1 && B2);
	}
	else if (Fun == 15)
	{
		BHasil = (B1 || B2);
	}
	else if (Fun == 16)
	{
		BHasil = (!B1);
	}
	Bool(Inf1) = BHasil;
	TipeInfo(Inf1) = BOOL;
	LHasil = Konsd(LHasil, Inf1);

	return LHasil;
}

listoflist EvaluasiRelasional(listoflist L)
{
	bilangan_type Bil1, Bil2;
	listoflist L1, L2, LHasil;
	infotype Inf, firstElmt;
	boolean B;
	int Fun;

	firstElmt = FirstElmt(L);
	CreateList(&LHasil);
	Fun = IsFUNGSI(Fungsi(firstElmt));
	L1 = EvaluasiEkspresi(Next(L));
	L2 = EvaluasiEkspresi(Next(Next(L)));
	Bil1 = Bilangan(FirstElmt(L1));
	Bil2 = Bilangan(FirstElmt(L2));
	if (Fun == 8)
	{
		B = (IsBesarDari(Bil1, Bil2) || IsSama(Bil1, Bil2));
	}
	else if (Fun == 9)
	{
		B = (IsBesarDari(Bil1, Bil2) && !IsSama(Bil1, Bil2));
	}
	else if (Fun == 10)
	{
		B = (IsKurangDari(Bil1, Bil2) || IsSama(Bil1, Bil2));
	}
	else if (Fun == 11)
	{
		B = (IsKurangDari(Bil1, Bil2) && !IsSama(Bil1, Bil2));
	}
	else if (Fun == 12)
	{
		B = IsSama(Bil1, Bil2);
	}
	else if (Fun == 13)
	{
		B = !IsSama(Bil1, Bil2);
	}
	if (B)
	{
		Bool(Inf) = true;
		TipeInfo(Inf) = BOOL;
	}
	else
	{
		Bool(Inf) = false;
		TipeInfo(Inf) = BOOL;
	}
	LHasil = Konsd(LHasil, Inf);

	return LHasil;
}

listoflist EvaluasiAritmetika(listoflist L)
{
	bilangan_type Bil, Bil1, Bil2;
	infotype Inf, Inf1, firstElmt;
	boolean unary, kosong;
	listoflist L1, L2, L3;
	int Fun;

	unary = false;
	kosong = false;
	CreateList(&L3);
	if (Next(L) == nil)
	{
		Bulat(Bilangan(Inf)) = 0;
		TipeBilangan(Bilangan(Inf)) = BULAT;
		TipeInfo(Inf) = BILANGAN;
		L = Konsd(L, Inf);
		L = Konsd(L, Inf);
		kosong = true;
	}
	else if (Next(Next(L)) == nil)
	{
		Bulat(Bilangan(Inf)) = 0;
		TipeBilangan(Bilangan(Inf)) = BULAT;
		TipeInfo(Inf) = BILANGAN;
		L = Konsd(L, Inf);
		unary = true;
	}
	firstElmt = FirstElmt(L);
	L1 = EvaluasiEkspresi(Next(L));
	L2 = EvaluasiEkspresi(Next(Next(L)));
	Bil1 = Bilangan(FirstElmt(L1));
	Bil2 = Bilangan(FirstElmt(L2));
	Fun = IsFUNGSI(Fungsi(firstElmt));
	if (Fun == 1)
	{
		Bil = Tambah(Bil1, Bil2);
	}
	else if (Fun == 2)
	{
		if (unary)
		{
			Bil = Kurang(Bil2, Bil1);
		}
		else
		{
			Bil = Kurang(Bil1, Bil2);
		}
	}
	else if (Fun == 3)
	{
		Bil = Kali(Bil1, Bil2);
	}
	else if (Fun == 4)
	{
		if (unary)
		{
			Bulat(Bil2) = 1;
			TipeBilangan(Bil2) = BULAT;
			Bil = Bagi(Bil2, Bil1);
		}
		else
		{
			Bil = Bagi(Bil1, Bil2);
		}
	}
	else if (Fun == 5)
	{
		Bulat(Bil) = ModBilangan(Bulat(Bil1), Bulat(Bil2));
		TipeInfo(Bil) = BULAT;
	}
	else if (Fun == 6)
	{
		Bulat(Bil) = DivBilangan(Bulat(Bil1), Bulat(Bil2));
		TipeInfo(Bil) = BULAT;
	}
	else if (Fun == 7)
	{
	}
	Bilangan(Inf1) = Bil;
	TipeInfo(Inf1) = BILANGAN;
	L3 = Konsd(L3, Inf1);

	return L3;
}
