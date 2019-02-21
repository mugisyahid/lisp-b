#include <stdio.h>
#include "bilangan.h"

void TulisBilangan(bilangan_type Bil)
{
	switch (TipeBilangan(Bil))
	{
	case BULAT:
		printf("%d", Bil.bulat);
		break;
	case PECAHAN:
		printf("%d", Bil.pecahan.pembilang);
		printf("/%d", Bil.pecahan.penyebut);
		break;
	case RIIL:
		printf("%f", Bil.riil);
		break;
	}
}

void Konvert(bilangan_type *Bil, int T)
{
	if (TipeBilangan(*Bil) == BULAT && T == PECAHAN)
	{
		Pembilang(*Bil) = Bulat(*Bil);
		Penyebut(*Bil) = 1;
		TipeBilangan(*Bil) = PECAHAN;
	}
	else if (TipeBilangan(*Bil) == BULAT && T == RIIL)
	{
		Riil(*Bil) = (riil_type)Bulat(*Bil);
		TipeBilangan(*Bil) = RIIL;
	}
	else if (TipeBilangan(*Bil) == PECAHAN && T == RIIL)
	{
		Riil(*Bil) = (riil_type)(Pembilang(*Bil)) / (Penyebut(*Bil));
		TipeBilangan(*Bil) = RIIL;
	}
}

pecahan_type MakePecahan(bulat_type Bul1, bulat_type Bul2)
{
	pecahan_type PecHasil;

	PecHasil.pembilang = Bul1;
	PecHasil.penyebut = Bul2;
	SederhanaPecahan(&PecHasil);
	return PecHasil;
}

bilangan_type Tambah(bilangan_type Bil1, bilangan_type Bil2)
{
	bilangan_type BilHasil;

	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		Riil(BilHasil) = Riil(Bil1) + Riil(Bil2);
		TipeBilangan(BilHasil) = RIIL;
		return BilHasil;
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		Pembilang(BilHasil) = (Pembilang(Bil1) * Penyebut(Bil2)) + (Pembilang(Bil2) * Penyebut(Bil1));
		Penyebut(BilHasil) = Penyebut(Bil1) * Penyebut(Bil2);
		SederhanaPecahan(&Pecahan(BilHasil));
		TipeBilangan(BilHasil) = PECAHAN;
		return BilHasil;
	}
	else
	{
		Bulat(BilHasil) = Bulat(Bil1) + Bulat(Bil2);
		TipeBilangan(BilHasil) = BULAT;
		return BilHasil;
	}
}

bilangan_type Kurang(bilangan_type Bil1, bilangan_type Bil2)
{
	bilangan_type BilHasil;

	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		Riil(BilHasil) = Riil(Bil1) - Riil(Bil2);
		TipeBilangan(BilHasil) = RIIL;
		return BilHasil;
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		Pembilang(BilHasil) = (Pembilang(Bil1) * Penyebut(Bil2)) - (Pembilang(Bil2) * Penyebut(Bil1));
		Penyebut(BilHasil) = Penyebut(Bil1) * Penyebut(Bil2);
		SederhanaPecahan(&Pecahan(BilHasil));
		TipeBilangan(BilHasil) = PECAHAN;
		return BilHasil;
	}
	else
	{
		Bulat(BilHasil) = Bulat(Bil1) - Bulat(Bil2);
		TipeBilangan(BilHasil) = BULAT;
		return BilHasil;
	}
}

bilangan_type Kali(bilangan_type Bil1, bilangan_type Bil2)
{
	bilangan_type BilHasil;

	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		Riil(BilHasil) = Riil(Bil1) * Riil(Bil2);
		TipeBilangan(BilHasil) = RIIL;
		return BilHasil;
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		Pembilang(BilHasil) = Pembilang(Bil1) * Pembilang(Bil2);
		Penyebut(BilHasil) = Penyebut(Bil1) * Penyebut(Bil2);
		SederhanaPecahan(&Pecahan(BilHasil));
		TipeBilangan(BilHasil) = PECAHAN;
		return BilHasil;
	}
	else
	{
		Bulat(BilHasil) = Bulat(Bil1) * Bulat(Bil2);
		TipeBilangan(BilHasil) = BULAT;
		return BilHasil;
	}
}

bilangan_type Bagi(bilangan_type Bil1, bilangan_type Bil2)
{
	bilangan_type BilHasil;

	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		Riil(BilHasil) = Riil(Bil1) / Riil(Bil2);
		TipeBilangan(BilHasil) = RIIL;
		return BilHasil;
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		Pembilang(BilHasil) = Pembilang(Bil1) * Penyebut(Bil2);
		Penyebut(BilHasil) = Penyebut(Bil1) * Pembilang(Bil2);
		SederhanaPecahan(&Pecahan(BilHasil));
		TipeBilangan(BilHasil) = PECAHAN;
		return BilHasil;
	}
	else
	{
		if (ModBilangan(Bulat(Bil1), Bulat(Bil2)) == 0)
		{
			Bulat(BilHasil) = Bulat(Bil1) / Bulat(Bil2);
			TipeBilangan(BilHasil) = BULAT;
		}
		else
		{
			Pembilang(BilHasil) = Bulat(Bil1);
			Penyebut(BilHasil) = Bulat(Bil2);
			SederhanaPecahan(&Pecahan(BilHasil));
			TipeBilangan(BilHasil) = PECAHAN;
		}
	}
	return BilHasil;
}
boolean IsBesarDari(bilangan_type Bil1, bilangan_type Bil2)
{
	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		return Riil(Bil1) > Riil(Bil2);
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		return Pembilang(Bil1) * Penyebut(Bil2) > Pembilang(Bil2) * Penyebut(Bil1);
	}
	else
	{
		return Bulat(Bil1) > Bulat(Bil2);
	}
}

boolean IsKurangDari(bilangan_type Bil1, bilangan_type Bil2)
{
	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		return Riil(Bil1) < Riil(Bil2);
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		return Pembilang(Bil1) * Penyebut(Bil2) < Pembilang(Bil2) * Penyebut(Bil1);
	}
	else
	{
		return Bulat(Bil1) < Bulat(Bil2);
	}
}

boolean IsSama(bilangan_type Bil1, bilangan_type Bil2)
{
	if (TipeBilangan(Bil1) == RIIL || TipeBilangan(Bil2) == RIIL)
	{
		if (TipeBilangan(Bil1) != RIIL)
		{
			Konvert(&Bil1, RIIL);
		}
		if (TipeBilangan(Bil2) != RIIL)
		{
			Konvert(&Bil2, RIIL);
		}
		return Riil(Bil1) == Riil(Bil2);
	}
	else if (TipeBilangan(Bil1) == PECAHAN || TipeBilangan(Bil2) == PECAHAN)
	{
		if (TipeBilangan(Bil1) != PECAHAN)
		{
			Konvert(&Bil1, PECAHAN);
		}
		if (TipeBilangan(Bil2) != PECAHAN)
		{
			Konvert(&Bil2, PECAHAN);
		}
		return Pembilang(Bil1) * Penyebut(Bil2) == Pembilang(Bil2) * Penyebut(Bil1);
	}
	else
	{
		return Bulat(Bil1) == Bulat(Bil2);
	}
}

bulat_type ModBilangan(bulat_type Bul1, bulat_type Bul2)
{
	return Bul1 % Bul2;
}

bulat_type DivBilangan(bulat_type Bul1, bulat_type Bul2)
{
	return (bulat_type)Bul1 / Bul2;
}

bulat_type FPB(bulat_type Bul1, bulat_type Bul2)
{
	bulat_type BulTemp;

	while (Bul2 != 0)
	{
		BulTemp = ModBilangan(Bul1, Bul2);
		Bul1 = Bul2;
		Bul2 = BulTemp;
	}
	return Bul1;
}

void SederhanaPecahan(pecahan_type *Pec)
{
	bulat_type GCD;

	GCD = FPB(Pec->pembilang, Pec->penyebut);
	Pec->pembilang = DivBilangan(Pec->pembilang, GCD);
	Pec->penyebut = DivBilangan(Pec->penyebut, GCD);

	if (Pec->penyebut < 0)
	{
		Pec->pembilang = Pec->pembilang * (-1);
		Pec->penyebut = Pec->penyebut * (-1);
	}
}