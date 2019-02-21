#include <stdio.h>
#include "listoflist.h"

int main(){
	address Pdel;
	listoflist Lis, Lis1, Lis2;
	infotype Inf, Inf1, Inf2, Inf3, Inf4, Inf5;
	bilangan_type Bil, Bil1, Bil2, Bil3, Bil4;
	
	CreateList(&Lis);
	CreateList(&Lis1);
	
	Bulat(Bil) = 10;
	TipeBilangan(Bil) = BULAT;
	Bilangan(Inf) = Bil;
	TipeInfo(Inf) = BILANGAN;
	
	
	Pecahan(Bil1) = MakePecahan(11, 12);
	TipeBilangan(Bil1) = PECAHAN;
	Bilangan(Inf1) = Bil1;
	TipeInfo(Inf1) = BILANGAN;
	
	Pembilang(Bil2) = 13;
	Penyebut(Bil2) = 14;
	TipeBilangan(Bil2) = PECAHAN;
	Bilangan(Inf2) = Bil2;
	TipeInfo(Inf2) = BILANGAN;
	
	Bulat(Bil3) = 15;
	TipeBilangan(Bil3) = BULAT;
	Bilangan(Inf3) = Bil3;
	TipeInfo(Inf3) = BILANGAN;
	
	Riil(Bil4) = 16.17;
	TipeBilangan(Bil4) = RIIL;
	Bilangan(Inf4) = Bil4;
	TipeInfo(Inf4) = BILANGAN;
	
	Lis1 = Konso(Inf2, Lis1);
	Lis1 = Konso(Inf3, Lis1);
	Lis1 = Konso(Inf4, Lis1);
	
	List(Inf5) = Lis1;
	TipeInfo(Inf5) = LIST;
	
	Lis = Konso(Inf, Lis);
	Lis = Konso(Inf1, Lis);
	Lis = Konso(Inf5, Lis);
	
	PrintList(Lis);
	printf("\n");
	
	Lis = InversList(Lis);
	
	PrintList(Lis);
	printf("\n");
	
	Lis = Concat(Lis, InversList(Lis));
	
	PrintList(Lis);
	printf("\n");
	
	Lis2 = CopyList(Lis);
	
	PrintList(Lis2);
	printf("\n");

	return 0;
}