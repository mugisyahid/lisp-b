#include <stdio.h>
#include "fungsi.h"

int IsFUNGSI(const char* Input){
	int Tipe;
	
	Tipe = IsTAMBAH(Input);
	
	if(Tipe == 0){
		Tipe = IsKURANG(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsKALI(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsBAGI(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsMOD(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsDIV(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsEXP(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsLEBIHSAMA(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsLEBIHDARI(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsKURANGSAMA(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsKURANGDARI(Input);
	}

	if(Tipe == 0){
		Tipe = IsSAMA(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsNSAMA(Input);
	}

	if(Tipe == 0){
		Tipe = IsAND(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsOR(Input);
	}

	if(Tipe == 0){
		Tipe = IsNOT(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsOR(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsTRUE(Input);
	}

	if(Tipe == 0){
		Tipe = IsFALSE(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsIF(Input);
	}

	if(Tipe == 0){
		Tipe = IsCOND(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsCAR(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsCDR(Input);
	}

	if(Tipe == 0){
		Tipe = IsCONS(Input);
	}

	if(Tipe == 0){
		Tipe = IsLIST(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsAPPEND(Input);
	}

	if(Tipe == 0){
		Tipe = IsREVERSE(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsATOM(Input);
	}

	if(Tipe == 0){
		Tipe = IsLISTP(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsNULL(Input);
	}

	if(Tipe == 0){
		Tipe = IsEQUAL(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsLOAD(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsSAVE(Input);
	}
	
	if(Tipe == 0){
		Tipe = IsEXIT(Input);
	}

	if(Tipe == 0){
		Tipe = IsSETQ(Input);
	}

	if(Tipe == 0){
		Tipe = IsEVAL(Input);
	}
	
	return Tipe;
}

int IsTAMBAH(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == TAMBAH[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 1;
	} else {
		return 0;
	}
}

int IsKURANG(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == KURANG[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 2;
	} else {
		return 0;
	}
}

int IsKALI(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == KALI[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 3;
	} else {
		return 0;
	}
}

int IsBAGI(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == BAGI[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 4;
	} else {
		return 0;
	}
}

int IsMOD(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == MOD[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 5;
	} else {
		return 0;
	}
}

int IsDIV(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == DIV[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 6;
	} else {
		return 0;
	}
}

int IsEXP(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == EXP[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 7;
	} else {
		return 0;
	}
}

int IsLEBIHSAMA(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == LEBIHSAMA[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 8;
	} else {
		return 0;
	}
}

int IsLEBIHDARI(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == LEBIHDARI[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 9;
	} else {
		return 0;
	}
}

int IsKURANGSAMA(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == KURANGSAMA[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 10;
	} else {
		return 0;
	}
}

int IsKURANGDARI(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == KURANGDARI[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 11;
	} else {
		return 0;
	}
}

int IsSAMA(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == SAMA[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 12;
	} else {
		return 0;
	}
}

int IsNSAMA(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == NSAMA[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 13;
	} else {
		return 0;
	}
}

int IsAND(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == AND[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 14;
	} else {
		return 0;
	}
}

int IsOR(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == OR[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 15;
	} else {
		return 0;
	}
}

int IsNOT(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == NOT[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 16;
	} else {
		return 0;
	}
}

int IsTRUE(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == TRUE[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 17;
	} else {
		return 0;
	}
}

int IsFALSE(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == FALSE[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 18;
	} else {
		return 0;
	}
}

int IsIF(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == IF[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 19;
	} else {
		return 0;
	}
}

int IsCOND(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == COND[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 20;
	} else {
		return 0;
	}
}

int IsCAR(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == CAR[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 21;
	} else {
		return 0;
	}
}

int IsCDR(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == CDR[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 22;
	} else {
		return 0;
	}
}

int IsCONS(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == CONS[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 23;
	} else {
		return 0;
	}
}

int IsLIST(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == LISTL[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 24;
	} else {
		return 0;
	}
}

int IsAPPEND(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == APPEND[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 25;
	} else {
		return 0;
	}
}

int IsREVERSE(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == REVERSE[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 26;
	} else {
		return 0;
	}
}

int IsATOM(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == ATOM[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 27;
	} else {
		return 0;
	}
}

int IsLISTP(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == LISTP[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 28;
	} else {
		return 0;
	}
}

int IsNULL(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == NIL[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 29;
	} else {
		return 0;
	}
}

int IsEQUAL(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == EQUAL[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 30;
	} else {
		return 0;
	}
}

int IsLOAD(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == LOAD[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 31;
	} else {
		return 0;
	}
}

int IsSAVE(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == SAVE[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 32;
	} else {
		return 0;
	}
}

int IsEXIT(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == EXIT[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 33;
	} else {
		return 0;
	}
}

int IsSETQ(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == SETQ[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 34;
	} else {
		return 0;
	}
}

int IsEVAL(const char* Input){
	int Idx;
	
	Idx = 0;
	while(Input[Idx] != EOE && Input[Idx] == EVAL[Idx]){
		Idx++;
	}
	if(Input[Idx] == EOE){
		return 35;
	} else {
		return 0;
	}
}