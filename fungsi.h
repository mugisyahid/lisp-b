#ifndef FUNGSI_H
#define FUNGSI_H

#define EOE			'\0'

#define TAMBAH		"+"
#define KURANG		"-"
#define	KALI		"*"
#define BAGI		"/"
#define MOD			"mod"
#define DIV			"div"
#define EXP			"exp"

#define LEBIHSAMA	">="
#define LEBIHDARI	">"
#define KURANGSAMA	"<="
#define KURANGDARI	"<"
#define SAMA		"="
#define NSAMA		"/="

#define AND			"and"
#define OR			"or"
#define NOT			"not"
#define TRUE		"T"
#define FALSE		"F"

#define IF			"if"
#define COND		"cond"

#define CAR			"car"
#define CDR			"cdr"
#define CONS		"cons"
#define LISTL		"list"
#define APPEND		"append"
#define REVERSE		"reverse"

#define ATOM 		"atom"
#define LISTP		"listp"
#define NIL			"null" 
#define EQUAL		"equal"

#define LOAD		"load"
#define SAVE		"save"
#define EXIT		"exit"

#define SETQ		"setq"
#define EVAL		"eval"

int IsFUNGSI(const char* Input);

int IsTAMBAH(const char* Input);

int IsKURANG(const char* Input);

int IsKALI(const char* Input);

int IsBAGI(const char* Input);

int IsMOD(const char* Input);

int IsDIV(const char* Input);

int IsEXP(const char* Input);

int IsLEBIHSAMA(const char* Input);

int IsLEBIHDARI(const char* Input);

int IsKURANGSAMA(const char* Input);

int IsKURANGDARI(const char* Input);

int IsSAMA(const char* Input);

int IsNSAMA(const char* Input);

int IsAND(const char* Input);

int IsOR(const char* Input);

int IsNOT(const char* Input);

int IsTRUE(const char* Input);

int IsFALSE(const char* Input);

int IsIF(const char* Input);

int IsCOND(const char* Input);

int IsCAR(const char* Input);

int IsCDR(const char* Input);

int IsCONS(const char* Input);

int IsLIST(const char* Input);

int IsAPPEND(const char* Input);

int IsREVERSE(const char* Input);

int IsATOM(const char* Input);

int IsLISTP(const char* Input);

int IsNULL(const char* Input);

int IsEQUAL(const char* Input);

int IsLOAD(const char* Input);

int IsSAVE(const char* Input);

int IsEXIT(const char* Input);

int IsSETQ(const char* Input);

int IsEVAL(const char* Input);

#endif