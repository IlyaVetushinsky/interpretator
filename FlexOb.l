%option noyywrap
%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "LangOb.h"
#include "BisonOb.tab.h"
void yyerror(char *);
%}
%%
[TF]	{
	yylval.iValue = atoi(yytext);
	return LOGIC;
}
"\."[0-9]+ { 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return LOGVAR;
	}
","[0-9]+ { 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return INTVAR;
	}
"$"[0-9]+ { 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return PROC;
	}
"~"[0-9]+ { 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return LABEL;
	}
[0-9]+ {
	yylval.iValue = atoi(yytext);
	return INTEGER;
	}
",#" return INC;
",*" return DEC;
".#" return PARR;
"eq" return EQ;
ЦИКЛ?
"np" return NP;
"mf" return MF;
"mb" return MB;
"mr" return MR;
"ml" return ML;
"tp" return TP;
"<-" return AS;
"please" return PLS;
"print" return PRINT;
[@%\n-;:.] return *yytext; 
[ \t]+ ;
. yyerror("Unknown character");
%%