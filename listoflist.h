#ifndef LISTOFLIST_H
#define LISTOFLIST_H

#include "bilangan.h"
#include "boolean.h"

#define MAXNAMA 100
#define nil NULL
#define BILANGAN 1
#define LIST 2
#define PEUBAH 3
#define FUNGSI 4
#define BOOL 5

typedef struct telmtlist *address;
typedef address listoflist;
typedef struct
{
	bilangan_type bilangan;
	listoflist list;
	char peubah[MAXNAMA];
	char fungsi[MAXNAMA];
	int b;
	int tipe;
} infotype;
typedef struct telmtlist
{
	infotype info;
	address next;
} elmtlist;

#define First(L) (L)
#define Info(P) (P)->info
#define Bilangan(Inf) (Inf).bilangan
#define List(Inf) (Inf).list
#define Peubah(Inf) (Inf).peubah
#define Fungsi(Inf) (Inf).fungsi
#define Bool(Inf) (Inf).b
#define TipeInfo(Inf) (Inf).tipe
#define Next(P) (P)->next

address Alokasi(infotype X);

void Dealokasi(address *P);

void CreateList(listoflist *Lis);

infotype FirstElmt(listoflist L);

listoflist Tail(listoflist L);

listoflist Konso(infotype e, listoflist L);

listoflist Konsd(listoflist L, infotype e);

boolean IsListEmpty(listoflist L);

void DeleteAfter(listoflist *L, address *Pdel, address Prec);

listoflist InversList(listoflist L);

listoflist Concat(listoflist L1, listoflist L2);

listoflist CopyList(listoflist L);

void PrintList(listoflist L);

#endif