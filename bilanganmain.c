#include <stdio.h>
#include "bilangan.h"

int main(){
	bilangan_type Bil;
	bilangan_type Bil1;
	
	Bulat(Bil) = 4;
	TipeBilangan(Bil) = BULAT;
	TulisBilangan(Bil);
	
	Pecahan(Bil1) = MakePecahan(12, -5);
	TipeBilangan(Bil1) = PECAHAN;
	TulisBilangan(Bil1);
	
	Bil = Bagi(Bil, Bil1);
	TulisBilangan(Bil);
	
	return 0;
}