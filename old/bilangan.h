#ifndef BILANGAN_H
#define BILANGAN_H

#include "boolean.h"

#define BULAT 1
#define PECAHAN 2
#define RIIL 3

typedef long long int bulat_type;
typedef struct
{
	bulat_type pembilang;
	bulat_type penyebut;
} pecahan_type;
typedef float riil_type;
typedef struct
{
	bulat_type bulat;
	pecahan_type pecahan;
	riil_type riil;
	int tipe;
} bilangan_type;

#define TipeBilangan(Bil) (Bil).tipe
#define Bulat(Bil) (Bil).bulat
#define Pecahan(Bil) (Bil).pecahan
#define Pembilang(Bil) (Bil).pecahan.pembilang
#define Penyebut(Bil) (Bil).pecahan.penyebut
#define Riil(Bil) (Bil).riil

void TulisBilangan(bilangan_type Bil);

void Konvert(bilangan_type *Bil, int T);

pecahan_type MakePecahan(bulat_type Bul1, bulat_type Bul2);

bilangan_type Tambah(bilangan_type Bil1, bilangan_type Bil2);

bilangan_type Kurang(bilangan_type Bil1, bilangan_type Bil2);

bilangan_type Kali(bilangan_type Bil1, bilangan_type Bil2);

bilangan_type Bagi(bilangan_type Bil1, bilangan_type Bil2);

boolean IsBesarDari(bilangan_type Bil1, bilangan_type Bil2);

boolean IsKurangDari(bilangan_type Bil1, bilangan_type Bil2);

boolean IsSama(bilangan_type Bil1, bilangan_type Bil2);

bulat_type ModBilangan(bulat_type Bul1, bulat_type Bul2);

bulat_type DivBilangan(bulat_type Bul1, bulat_type Bul2);

boolean IsRelatifPrima(bulat_type Bul1, bulat_type Bul2);

void SederhanaPecahan(pecahan_type *Pec);

#endif