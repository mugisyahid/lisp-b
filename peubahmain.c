#include <stdio.h>
#include "listoflist.h"
#include "peubah.h"

int main(){
	bilangan_type Bil;
	peubah_type Var;
	infotype Inf;
	
	Bulat(Bil) = 10;
	TipeBilangan(Bil) = BULAT;
	Bilangan(Inf) = Bil;
	TipeInfo(Inf) = BILANGAN;
	InfoPeubah(Var) = Inf;
	CopyNama(&(Nama(Var)),"test");
	
	printf("%s %d", Nama(Var), IsNamaSama(Nama(Var), "test"));

	ListVar[0] = Var;
	
	return 0;
}