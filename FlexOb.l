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
%option yylineno
%%
"T"	{
	//yylloc.last_line = yylloc.first_line = yylineno; 
	yylval.iValue = 1;
	return LOGIC;
}
"F" {
	//yylloc.last_line = yylloc.first_line = yylineno; 
	yylval.iValue = 0;
	return LOGIC;
}
"\."[0-9]+ { 
	//yylloc.last_line = yylloc.first_line = yylineno; 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return LOGVAR;
	}
","[0-9]+ { 
	//yylloc.last_line = yylloc.first_line = yylineno; 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return INTVAR;
	}
"$"[0-9]+ { 
	//yylloc.last_line = yylloc.first_line = yylineno; 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return PROC;
	}
"~"[0-9]+ { 
	//yylloc.last_line = yylloc.first_line = yylineno; 
	++yytext;
	yylval.sIndex = atoi(yytext);
	return LABEL;
	}
("-"){0,1}[0-9]+ {
	//yylloc.last_line = yylloc.first_line = yylineno; 
	yylval.iValue = atoi(yytext);
	return INTEGER;
	}
",#" return INC;
",*" return DEC;
".#" return PARR;
"eq" return EQ;
"np" return NP;
"mf" return MF;//1
"mb" return MB;//2
"mr" return MR;//3
"ml" return ML;//4
"tp" return TP;//5
"<-" return AS;
"please" return PLS;
"print" return PRINT;
[@%\n\{\};:\(\)\[\].] return *yytext; 
[ \t\r]+ ;
. { yyerror("Unknown character");}
%%