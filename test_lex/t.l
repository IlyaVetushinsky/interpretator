%option noyywrap yylineno
%option c++
%{
	#include <iostream>
	#include <fstream>
	#include <string>
	std::string str;
%}

%%
[TF]	{
	str = yytext; std::cout << str;
}
"\."[0-9]+ { 
	++yytext;
	str = yytext; std::cout << str;
	}
","[0-9]+ { 
	++yytext;
	str = yytext; std::cout << str;
	}
"$"[0-9]+ { 
	++yytext;
	str = yytext; std::cout << str;
	}
"~"[0-9]+ { 
	++yytext;
	str = yytext; std::cout << str;
	}
[0-9]+ {
	str = yytext; std::cout << str;
	}
",#" {
	str = yytext; std::cout << str;
	};
",*" {
	str = yytext; std::cout << str;
	};
".#" {
	str = yytext; std::cout << str;
	};
"eq" {
	str = yytext; std::cout << str;
	};
"np" {
	str = yytext; std::cout << str;
	};
"mf" {
	str = yytext; std::cout << str;
	};
"mb" {
	str = yytext; std::cout << str;
	};
"mr" {
	str = yytext; std::cout << str;
	};
"ml" {
	str = yytext; std::cout << str;
	};
"tp" {
	str = yytext; std::cout << str;
	};
"<-" {
	str = yytext; std::cout << str;
	};
"please" {
	str = yytext; std::cout << str;
	};
"print" {
	str = yytext; std::cout << str;
	};
[@%\n-;:.] {
	str = yytext; std::cout << str;
	}; 
[ \t]+ ;
. {
	str = "Unknown"; std::cout << str;
	}; 
(\n)+ {}
%%
int main(){
	std::ifstream fin("test.txt");
	std::ofstream fout("Strings255.txt", std::ofstream::app);
	yyFlexLexer ftp(fin, fout);
	std::cout << "Hello\n";
	if (!fin.is_open()) {
		std::cout << "nope\n";
		return 0;
	}
	else {
		std::cout << "opened\n";
	}
	if (!fout.is_open()) {
		std::cout << "nope\n";
		return 0;
	}
	else {
		std::cout << "opened\n";
	}
	ftp.yylex();
	fin.close();
	fout.close();
	return 0;
}