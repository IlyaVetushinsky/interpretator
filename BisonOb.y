%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdarg.h>
#include "LangOb.h"
extern FILE * yyin;
/* prototypes */
Node *opr(std::string n, int oper, int nops, ...);
Node *id(int i, int t);
Node *con(int value, int t);
void setlabel (int i ,Node *p);
void freeNode(Node *p);
int exec(Node *p);
void print_Tree(Node *p, int level);
int yylex();
void init (void);
void yyerror(char *s);
extern std::map<std::vector<int>,std::map<std::vector<int>,int>> VarStore;                  
Node* addr[26];

%}

%union {
	int iValue;                 /* integer value */
	int sIndex;                /* name *//////////////////////
	Node *nPtr;             /* node pointer */
};
%nonassoc END
%token <iValue> INTEGER LOGIC
%token <sIndex> LOGVAR INTVAR LABEL PROC
%token WHILE PRINT GOTO PLS NP MF MB MR ML TP AS
%left ';'
%right ':'
%left EQ
%right INC DEC PARR
%nonassoc UMINUS
%type <nPtr> stmt nexpr nvariable narr lexpr lvariable larr stmt_list function integ bool

%%

program:
	function {exec($1); print_Tree($1,0); freeNode($1);exit(0);}
	;
	
function:
	function stmt	{$$ =  opr("\\n", '\n', 2, $1, $2);/*ex($2); freeNode($2);*/ }
	|	            { init(); $$ = 0;}
	;
	
stmt:
	'\n'	{ $$ = opr("\\n", '\n', 2, NULL, NULL); }																		
	| nexpr '\n'                       { $$ = $1; }
	| lexpr '\n'                       { $$ = $1; }
	| PRINT nexpr '\n' 					{ $$ = opr("print", PRINT, 1, $2); }
	| PRINT lexpr '\n' 					{ $$ = opr("print", PRINT, 1, $2); }
	| nvariable AS nexpr '\n'          { $$ = opr("<-", '=', 2, $1, $3); }
	| lvariable AS lexpr '\n' 			{ $$ = opr("<-", '=', 2, $1, $3); }
	|'(' lexpr ')' stmt       	 		 { $$ = opr("while", WHILE, 2, $2, $4); }
	| '{' stmt_list '}'               { $$= $2; }
	| LABEL stmt				  		{ setlabel ($1, $2); $$ = $2;}
	| '[' lexpr ']' LABEL '\n'		  { $$ = opr("go to", GOTO, 1, id($4,2));}
	| '[' lexpr ']' PLS LABEL '\n'	  { $$ = opr("go to", GOTO, 1, id($5,2));}
	;

stmt_list:
	stmt        			{ $$ = $1; }
	| stmt_list stmt        { $$ = opr("\\n", '\n', 2, $1, $2); }
	;

nexpr:
	integ                	 { $$ = $1 }
	| nvariable              { $$ = $1; }
	| '(' nexpr ')'           { $$ = $2; }
	;

nvariable:
	INTVAR							{ $$ = id($1,1); }
	| narr							{ $$ = $1; }
	| INC nvariable				{$$ = opr("inc", INC, 1, $2); }
	| DEC nvariable				{$$ = opr("dec", DEC, 1, $2); }
	| nvariable EQ integ          { $$ = opr("eq", EQ, 2, $1, $3); }
	;
	
narr:
	INTVAR ':' nexpr				{ $$ = opr(":", ':', 2, $1, $3);}
	|narr ';' nexpr					{ $$ = opr(";", ';', 2, $1, $3);}
	;
	
integ:
	INTEGER                  { $$ = con($1, 1); }
	| '-' integ %prec UMINUS { $$ = opr("-", UMINUS, 1, $2); }	
	
lexpr:
	bool							{ $$ = $1; }
	| lvariable             		{ $$ = $1; }
	| PARR lexpr lexpr				{ $$ = opr("parr", 'PARR', 2, $2, $3);}
	| '(' lexpr ')'         		{ $$ = $2; }
	;

lvariable:
	LOGVAR							{ $$ = id($1,0); }
	| larr							{ $$ = $1; }
	| lvariable EQ bool         	{ $$ = opr("eq", EQ, 2, $1, $3); }
	;
	
larr:
	LOGVAR ':' nexpr				{ $$ = opr(":", ':', 2, $1, $3);}
	|larr ';' nexpr					{ $$ = opr(";", ';', 2, $1, $3);}
	;
	
bool:
	LOGIC							{ $$ = con($1, 0); }
	
	
	
	
	
%%



Node *con(int value, int t) {
	if (t == 0 && value == 70)
		value = 0;
	else if (t == 0)
		value = 1;
	Node *p = new ConNode(value, t, typeCon);
	return p;
}

Node *id(int i, int t) {
	Node *p = new VarNode(i, t, typeId);
	return p;
}

Node *opr(std::string n, int oper, int nops, ...) {
	va_list ap;
	Node *p = new OprNode(n, oper, nops, typeOpr);
	va_start(ap, nops);
	for (int i = 0; i < nops; i++)
		p->children.push_back(va_arg(ap, Node*));
	va_end(ap);
	return p;
}

void freeNode(Node *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
		OprNode* oprn = dynamic_cast<OprNode*>(p);
		for (i = 0; i < oprn->nops; i++)
			freeNode(oprn->children[i]);
	}
	delete (p);
}

void setlabel (int i,Node *p)
{
	p->label = i;
	addr[i] = p;
}

void init (void)
{
	int i;
	for (i = 0;i<26;++i)
	addr[i] = 0;
}

void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

int main(void) {
	yyin = fopen ("./test.txt", "r");
	yyparse();
	fclose (yyin);
	return 0;
}

	






















