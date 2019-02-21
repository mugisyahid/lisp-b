#ifndef EKSPRESI_H
#define EKSPRESI_H

#include "peubah.h"
#include "fungsi.h"
#include "listoflist.h"
#include "managefile.h"
#include "boolean.h"

#define MAX			10000
#define EOE			'\0'
#define BLANK		' '
#define MARK 		'#'
#define DOT			'.'
#define LB			'('
#define RB			')'
#define SLASH		'/'
#define MINUS		'-'
#define NL			'\n'
#define BILANGAN	1
#define LIST		2
#define PEUBAH		3
#define FUNGSI		4
#define ANGKA		5
#define KATA		6
#define NVALID		0

extern char Input[MAX];
extern char Ekspresi[MAX];
extern char CS[MAX];
extern int Indeks;
extern listoflist ListEkspresi;

void Advance();

boolean IsEkspresiEnd();

void InputEkspresi();

void PrintEkspresi();

void IgnoreBlank();

void KonvertToInteger(bilangan_type *Bil);

void Advance();

int TipeEkspresi();

void KonsdEkspresi(infotype *Inf);

listoflist ParsingEkspresi();

/////////////////////////////////////////////////////////////////////

listoflist EvaluasiEkspresi(listoflist L);

listoflist EvaluasiPeubah(listoflist L);

listoflist EvaluasiLain(listoflist L);

listoflist Setq(listoflist L);

listoflist EvaluasiList(listoflist L);

listoflist CarZ(listoflist L);

listoflist CdrZ(listoflist L);

listoflist ConsZ(listoflist L);

listoflist ListZ(listoflist L);

listoflist AppendZ(listoflist L);

listoflist ReverseZ(listoflist L);

listoflist AtomZ(listoflist L);

listoflist ListpZ(listoflist L);

listoflist NullZ(listoflist L);

listoflist EqualZ(listoflist L);

listoflist EvaluasiCond(listoflist L);

listoflist EvaluasiIf(listoflist L);

listoflist EvaluasiBoolean(listoflist L);

listoflist EvaluasiLojik(listoflist L);

listoflist EvaluasiRelasional(listoflist L);

listoflist EvaluasiAritmetika(listoflist L);

#endif