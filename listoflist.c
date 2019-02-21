#include <stdio.h>
#include <stdlib.h>
#include "listoflist.h"

address Alokasi(infotype X)
{
	address P;

	P = (address)malloc(sizeof(elmtlist));
	if (P != nil)
	{
		Info(P) = X;
		Next(P) = nil;
	}
	return P;
}

void Dealokasi(address *P)
{
	free(*P);
}

void CreateList(listoflist *Lis)
{
	*Lis = nil;
}

infotype FirstElmt(listoflist L)
{
	return Info(L);
}

listoflist Tail(listoflist L)
{
	return Next(L);
}

listoflist Konso(infotype e, listoflist L)
{
	address P;

	P = Alokasi(e);
	if (P == nil)
	{
		return L;
	}
	else
	{
		Next(P) = L;
		return P;
	}
}

listoflist Konsd(listoflist L, infotype e)
{
	address P;
	address Last;

	P = Alokasi(e);
	if (P == nil)
	{
		return L;
	}
	else
	{
		if (IsListEmpty(L))
		{
			return P;
		}
		else
		{
			Last = L;
			while (Next(Last) != nil)
			{
				Last = Next(Last);
			}
			Next(Last) = P;
			return L;
		}
	}
}

void DeleteAfter(listoflist *L, address *Pdel, address Prec)
{
	address P;

	P = *L;
	while (P != Prec)
	{
		P = Next(P);
	}
	*Pdel = Next(Prec);
	Dealokasi(&(Next(Prec)));
	Next(Prec) = Next(Next(Prec));
}

listoflist InversList(listoflist L)
{
	if (!IsListEmpty(L))
	{
		return Konsd(InversList(Tail(L)), Info(L));
	}
}

listoflist Concat(listoflist L1, listoflist L2)
{
	if (IsListEmpty(L1))
	{
		return L2;
	}
	else
	{
		return Konso(Info(L1), Concat(Tail(L1), L2));
	}
}

listoflist CopyList(listoflist L)
{
	listoflist Ltemp;

	CreateList(&Ltemp);
	if (IsListEmpty(L))
	{
		return Ltemp;
	}
	else
	{
		return Konso(Info(L), CopyList(Tail(L)));
	}
}

boolean IsListEmpty(listoflist L)
{
	return L == nil;
}

boolean IsEqual(listoflist L1, listoflist L2)
{
	if (IsListEmpty(L1) && IsListEmpty(L2))
	{
		return true;
	}
	else if (!IsListEmpty(L1) && !IsListEmpty(L2))
	{
		if (TipeInfo(FirstElmt(L1)) == LIST && TipeInfo(FirstElmt(L2)) == LIST)
		{
			if (IsEqual(List(FirstElmt(L1)), List(FirstElmt(L2))))
			{
				return IsEqual(Next(L1), Next(L2));
			}
		}
		else if (TipeInfo(FirstElmt(L1)) != LIST && TipeInfo(FirstElmt(L2)) != LIST)
		{
			if (IsSama(Bilangan(FirstElmt(L1)), Bilangan(FirstElmt(L2))))
			{
				return IsEqual(Next(L1), Next(L2));
			}
		}
	}
	return false;
}

void PrintList(listoflist L)
{
	infotype Inf;

	if (!IsListEmpty(L))
	{
		Inf = Info(L);
		switch (TipeInfo(Inf))
		{
		case BILANGAN:
			TulisBilangan(Bilangan(Inf));
			break;
		case LIST:
			printf("(");
			PrintList(List(Inf));
			printf(")");
			break;
		case FUNGSI:
			printf("%s", Fungsi(Inf));
			break;
		case BOOL:
			if (Bool(Inf))
			{
				printf("T");
			}
			else
			{
				printf("F");
			}
		}
		printf(" ");
		PrintList(Tail(L));
	}
}