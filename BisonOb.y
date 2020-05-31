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
Node* ex_find_er(Node *p1);
int exec_find_er(Node *p);
Node* building_var_left (Node* p, int level);
int building_var_right (Node* p, int level);
void print_Tree(Node *p, int level);
void init_VL();
void go_proc(VarNode* varn);
void go_proc_er(VarNode* varn);
int find_rec_right(VarNode* varn1,VarNode* varn2);
int find_rec_left(VarNode* varn1,VarNode* varn2);
int find_rec(VarNode* &varn1,VarNode* &varn2);
void push_Varlist(Node* p);
int find_var(Node* p);
void clear_id_store(std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >>& IdStore);
extern Node *np();
void l_ballance(Node* n);
int lb_ballance(Node* p);
void wrong_lbls();
int yylex();
void yyerror(char *s);
std::vector<std::string> err_arr;
std::map<std::vector<int>,std::map<std::vector<int>,int>> VarStore;    
std::map<std::vector<int>,std::map<std::vector<int>,Node*>> ProcStore;   
std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >> IdStore;      
std::vector<std::vector<int>> Varlist;
std::map<int, Node*> addr;
char lbll = 0;

%}

%union {
	int iValue;                 /* integer value */
	int sIndex;                /* name *//////////////////////
	Node *nPtr;             /* node pointer */
};
%nonassoc END
%token <iValue> INTEGER LOGIC
%token <sIndex> LOGVAR INTVAR LABEL PROC
%token WHILE PRINT GOTO PLS NP MF MB MR ML TP AS SN
%left ';'
%right ':'
%left EQ
%right INC DEC PARR
%nonassoc UMINUS
%type <nPtr> stmt stmt_list function expr

%%

program:
	function { 
				print_Tree($1, 0);
				lb_ballance($1);
				if (err_arr.size() != 0) {
					for (int i = 0; i < err_arr.size(); ++i) {
						std::cout << err_arr[i] << std::endl;
					}
					exit(0);
				}
				exec_find_er($1);
				wrong_lbls();
				if (err_arr.size() != 0) {
					for (int i = 0; i < err_arr.size(); ++i) {
						std::cout << err_arr[i] << std::endl;
					}
					exit(0);
				}
				VarStore.clear();
				ProcStore.clear();
				clear_id_store(IdStore);
				exec($1); freeNode($1);exit(0);}
	;
	
function:
	function stmt	{$$ =  opr("\\n", '\n', 2, $1, $2);/*ex($2); freeNode($2);*/ }
	|	            { $$ = 0;}
	;
	
stmt:
	'\n'	{ $$ = opr("\\n", '\n', 2, NULL, NULL); }																		
	| expr '\n'                       { $$ = opr("call", 'c', 1, $1); }
	| PRINT expr '\n' 					{ $$ = opr("print", PRINT, 1, $2); }
	| expr AS stmt 						{ $$ = opr("<-", '=', 2, $1, $3); }
	| expr '@' expr '\n' 					{ $$ = opr("@", '@', 2, $1, $3); }
	| expr '%' expr	'\n' 					{ $$ = opr("%", '%', 2, $1, $3); }
	|'(' expr ')' stmt       	 		 { $$ = opr("while", WHILE, 2, $2, $4); }
	| '{' stmt_list '}'               { $$= $2; }
	| LABEL stmt						{ setlabel($1,$2); $$ = $2; }
	| '[' expr ']' LABEL '\n'			  { $$ = opr("go to", GOTO, 2, $2, id($4,3));}
	| '[' expr ']' PLS LABEL '\n'		  { $$ = opr("go to", GOTO, 2, $2, id($5,3));}
	;

stmt_list:
	stmt        			{ $$ = $1; }
	| stmt_list stmt        { $$ = opr("\\n", '\n', 2, $1, $2); }
	;

expr:
	INTEGER                 { $$ = con($1, 1); }
	| INTVAR				{ $$ = id($1,1); }
	| expr EQ expr        { $$ = opr("eq", EQ, 2, $1, $3); }
	| INC expr				{$$ = opr("inc", INC, 1, $2); }           //СДЕЛАТЬ ПРОВЕРКУ НА ТО ЧТО ЭТО не процедура
	| DEC expr				{$$ = opr("dec", DEC, 1, $2); }			  //СДЕЛАТЬ ПРОВЕРКУ НА ТО ЧТО ЭТО не процедура
	| expr ':' expr		{ $$ = opr(":", ':', 2, $1, $3);}		 //СДЕЛАТЬ ПРОВЕРКУ НА ТО ЧТО ЭТО переменная
	| expr ';' expr 		{ $$ = opr(";", ';', 2, $1, $3);} 		  //СДЕЛАТЬ ПРОВЕРКУ НА ТО ЧТО ЭТО массив
	| '(' expr ')'           { $$ = $2; }								 //СДЕЛАТЬ кучу проверок
	| LOGIC							{ $$ = con($1, 0); }
	| LOGVAR						{ $$ = id($1,0); }
	| PARR expr expr				{ $$ = opr("parr", PARR, 2, $2, $3);}
	| PROC							{ $$ = id($1,2); }
	| NP							{ $$ = np(); }
	;

	
	
	
	
	
%%



Node *con(int value, int t) {
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

Node* np() {
	Node* p = new Null();
	return p;
}


struct lp {
	int L_is;
	int G_is;
};

std::map<int, lp> t_lstore;

struct LQA {
	std::vector<int> Q;
	std::vector<int> A;
};

LQA L_qa;



void l_ballance(Node* p) {
	if (p) {
		if (p->label) {
			lp l = { 0,0 };
			t_lstore.emplace(p->label, l);
			std::map<int, lp>::iterator it;
			it = t_lstore.find(p->label);
			it->second.L_is = 1;
			
		}
		if (p->type == typeOpr) {
			OprNode* oprn = dynamic_cast<OprNode*>(p);
			if (oprn->oper == GOTO) {
				Node* n = oprn->children[1];
				VarNode* varn = dynamic_cast<VarNode*>(n);
				lp l = { 0,0 };
				t_lstore.emplace(varn->name, l);
				std::map<int, lp>::iterator it;
				it = t_lstore.find(varn->name);
				it->second.G_is = 1;
			}
			if (oprn->oper == '=') {
				l_ballance(oprn->children[0]);
				return;
			}
			for (int i = 0; i < oprn->nops; ++i) {
				l_ballance(oprn->children[i]);
			}
		}
	}
}

int lb_ballance(Node* p) {
	l_ballance(p);
	int k = 0;
	std::map<int, lp>::iterator it;
	for (auto it = t_lstore.begin(); it != t_lstore.end(); ++it) {
		if (it->second.L_is == 1) {
			//err_arr.push_back("Entering the procedure by the label from the outside");
			L_qa.Q.push_back(it->first);
		}
		if (it->second.G_is == 1 && it->second.L_is == 0) {
			err_arr.push_back("Label leads beyond procedure or Label with this name not declared");
			L_qa.A.push_back(it->first);
			++k;
		}
	}
	for (auto it = t_lstore.begin(); it != t_lstore.end(); ++it) {
		it->second = {0,0};
	}
	return k;
}

void wrong_lbls() {
	for (int i = 0; i< L_qa.Q.size(); ++i) {
		for (int j = 0;j< L_qa.A.size(); ++j)
			if (L_qa.Q[i] == L_qa.A[j]) {
				err_arr.push_back("Entering the procedure by the label from the outside");
				//err_arr.push_back(std::to_string(L_qa.A[j]));
			}
	}
}

void clear_id_store(std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >>& IdStore) {
	std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >> ::iterator it;
	for (auto it = IdStore.begin(); it != IdStore.end(); ++it) {
		std::map < std::vector<int>, VarNode* >::iterator it1;
		for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
			it1->second->id_1.clear();
			it1->second->id_2.clear();
		}
	}
}

int find_var(Node* p) {
	VarNode* varn = dynamic_cast<VarNode*>(p);
	int t = 0;
	int a = 0;
	a = varn->ind.size();
	if (varn->vtype == 0) {
		t = 0;
		if (a)
			t = 3;
	}
	if (varn->vtype == 1) {
		t = 1;
		if (a) {
			t = 4;
		}
	}
	if (varn->vtype == 2) {
		t = 2;
		if (a)
			t = 5;
	}
	for (int i = 0; i < Varlist.size(); ++i) {
		for (int j = 0; j < Varlist[i].size(); ++j) {
			if (varn->name == Varlist[i][j] && i != t)
				return 1;
		}
	}
	return 0;
}

void push_Varlist(Node* p) {
	VarNode* varn = dynamic_cast<VarNode*>(p);
	int t = 0;
	if (varn->vtype == 0) {
		t = 0;
		if (varn->ind.size())
			t = 3;
	}
	if (varn->vtype == 1) {
		t = 1;
		if (varn->ind.size())
			t = 4;
	}
	if (varn->vtype == 2) {
		t = 2;
		if (varn->ind.size())
			t = 5;
	}
	Varlist[t].push_back(varn->name);
}

int find_rec_left(VarNode* varn1, VarNode* varn2) {
	int k = 0;
	for (int i = 0; i < varn1->id_2.size(); ++i) {
		if ((varn1->id_2[i])->id_2.size()) {
			k = find_rec_left(varn1->id_2[i], varn2);
		}
		else {
			VarNode* varn = varn1->id_2[i];
			if (ProcStore[{varn->vtype, varn->name}][varn->ind] == ProcStore[{varn2->vtype, varn2->name}][varn2->ind]) {
				k = 1;
			}
		}
	}
	return k;
}

int find_rec_right(VarNode* varn1, VarNode* varn2) {
	int k = 0;
	for (int i = 0; i < varn2->id_1.size(); ++i) {
		if ((varn2->id_1[i])->id_1.size()) {
			k = find_rec_right(varn1, varn2->id_1[i]);
		}
		else {
			VarNode* varn = varn2->id_1[i];
			if (ProcStore[{varn->vtype, varn->name}][varn->ind] == ProcStore[{varn1->vtype, varn1->name}][varn1->ind]) {
				k = 1;
			}
		}
	}
	return k;
}

int find_rec(VarNode* &varn1, VarNode* &varn2) {
	int k = 0;
	if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
		varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
	}
	if (IdStore.find({ varn2->vtype, varn2->name }) != IdStore.end() && IdStore[{varn2->vtype, varn2->name}].find(varn2->ind) != IdStore[{varn2->vtype, varn2->name}].end()) {
		varn2 = IdStore[{varn2->vtype, varn2->name}][varn2->ind];
	}
	if (varn1 == varn2) {
		return 1;
	}
	k = find_rec_left(varn1, varn2);
	k = find_rec_right(varn1, varn2);
	return k;
}

void go_proc_er(VarNode* varn1) {
	if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
		varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
	}
	for (int i = 0; i < varn1->id_1.size(); ++i) {
		if (varn1 == varn1->id_1[i]) {
			return ;
		}
		if ((varn1->id_1[i])->id_1.size()) {
			go_proc_er(varn1->id_1[i]);
		}
		VarNode* varn2 = varn1->id_1[i];
		Node* n = ProcStore[{varn2->vtype, varn2->name}][varn2->ind];
		if (!lb_ballance(n))
			ex_find_er(ProcStore[{varn2->vtype, varn2->name}][varn2->ind]);
	}
}


Node* ex_find_er(Node* p1) {
	if (!p1) return nullptr;
	if (lbll == p1->label)
		lbll = 0;
	if (!lbll) {
		switch (p1->type) {
		case typeN: { Null* n = dynamic_cast<Null*>(p1); return n; }
		case typeCon: {ConNode* conn = dynamic_cast<ConNode*>(p1); return conn; }
		case typeId: {VarNode* varn = dynamic_cast<VarNode*>(p1); return varn; }
		case typeOpr: {
			OprNode* p = dynamic_cast<OprNode*>(p1);
			switch (p->oper) {
			case WHILE: {Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1->type == typeN) {
					err_arr.push_back("No action operator cannot be a condition");
				}
				if (n2->type == typeN) {
					err_arr.push_back("No action operator cannot be a condition");
				}
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*>(n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					go_proc_er(varn1);
				}
				if (n2->type == typeId) {
					VarNode* varn2 = dynamic_cast<VarNode*>(n2);
					if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
						Node* n11 = con(0, 0);
						return n11;
					}
				}
				return nullptr; }
			case PRINT: {Node* n1 = ex_find_er(p->children[0]);
				if (n1->type == typeN) {
					err_arr.push_back("No action operator cannot be displayed");
				}
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*>(n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn1->vtype == 2) {
						err_arr.push_back("The procedure variable cannot be displayed");
					}
					go_proc_er(varn1);
				}
				Node* n11 = con(1, 0);
				return n11; 
			}
			case '\n': { ex_find_er(p->children[0]); return ex_find_er(p->children[1]); }
			case ':': {Node* n = building_var_left(p, 0);
				VarNode* varn = dynamic_cast<VarNode*>(n);
				return varn;
			}
			case ';': {Node* n0 = p;
				while (n0->children.size()!= 0 && n0->children[0]->type == typeOpr) {
					n0 = n0->children[0];
				}
				OprNode* oprn = dynamic_cast<OprNode*>(n0);
				if (oprn->oper == ';') {
					err_arr.push_back("Incorrect indexing mode, expected ':' after array name");
				}
				Node* n = building_var_left(p, 0);
				VarNode* varn = dynamic_cast<VarNode*>(n);
				return varn;
			}
			case '@': {
				Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeN) {
					err_arr.push_back("np cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeCon) {
					err_arr.push_back("Constant cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeOpr) {
					err_arr.push_back("Operation cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				VarNode* varn1 = dynamic_cast<VarNode*>(n1);
				if (find_var(varn1)) {
					err_arr.push_back("A variable with this name already exists");
				}
				if (n2 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n2->type != typeId) {
					err_arr.push_back("The right value for identification can only be a procedure variabler");
				}
				else {
					VarNode* varn2 = dynamic_cast<VarNode*>(n2);
					if (!(ProcStore.find({ varn2->vtype, varn2->name }) != ProcStore.end() && ProcStore[{varn2->vtype, varn2->name}].find(varn2->ind) != ProcStore[{varn2->vtype, varn2->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn2->vtype != 2) {
						err_arr.push_back("The right value for identification can only be a procedure variabler");
						Node* n11 = con(1, 0);
						return n11;
					}
					int k = find_rec(varn1, varn2);
					Node* n11 = con(1, 0);
					if (!k) {
						varn1->id_1.push_back(varn2);
						varn2->id_2.push_back(varn1);
						IdStore[{varn1->vtype, varn1->name}][varn1->ind] = varn1;
						IdStore[{varn2->vtype, varn2->name}][varn2->ind] = varn2;
					}
					else {
						n11 = con(0, 0);
					}
					if (varn2->id_2.size() > 20) {
						int f = 0;
						for (int i = 0; i < varn2->id_2.size(); ++i) {
							if (varn2->id_2[i] == varn2->id_2[5])
								++f;
						}
						if (f > 10) {
							err_arr.push_back("Procedure identifier recursion");
							clear_id_store(IdStore);
						}
					}
					return n11;
				}
			}
			case '%': {
				Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeN) {
					err_arr.push_back("np cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeCon) {
					err_arr.push_back("Constant cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeOpr) {
					err_arr.push_back("Operation cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				VarNode* varn1 = dynamic_cast<VarNode*>(n1);
				if (n2 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n2->type != typeId) {
					err_arr.push_back("The right value for identification can only be a procedure variabler");
				}
				else {
					VarNode* varn2 = dynamic_cast<VarNode*>(n2);
					if (!(ProcStore.find({ varn2->vtype, varn2->name }) != ProcStore.end() && ProcStore[{varn2->vtype, varn2->name}].find(varn2->ind) != ProcStore[{varn2->vtype, varn2->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn2->vtype != 2) {
						err_arr.push_back("The right value for identification can only be a procedure variabler");
						Node* n11 = con(1, 0);
						return n11;
					}
					int k = 0;
					if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
						varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
					}
					if (IdStore.find({ varn2->vtype, varn2->name }) != IdStore.end() && IdStore[{varn2->vtype, varn2->name}].find(varn2->ind) != IdStore[{varn2->vtype, varn2->name}].end()) {
						varn2 = IdStore[{varn2->vtype, varn2->name}][varn2->ind];
					}
					for (int i = 0; i < varn1->id_1.size(); ++i) {
						if (ProcStore[{(varn1->id_1[i])->vtype, (varn1->id_1[i])->name}][varn1->id_1[i]->ind] == ProcStore[{varn2->vtype, varn2->name}][varn2->ind]) {
							varn1->id_1.erase(varn1->id_1.begin() + i);
							++k;
						}
					}
					for (int i = 0; i < varn2->id_2.size(); ++i) {
						if (ProcStore[{(varn2->id_2[i])->vtype, (varn2->id_2[i])->name}][varn2->id_2[i]->ind] == ProcStore[{varn1->vtype, varn1->name}][varn1->ind]) {
							varn2->id_2.erase(varn2->id_2.begin() + i);
							++k;
						}
					}
					Node* n11 = con(1, 0);
					if (!k) {
						n11 = con(0, 0);
					}
					return n11;
				}
			}
			case '=': { Node* n = ex_find_er(p->children[0]);
				Node* n2 = p->children[1];
				if (n == nullptr) {
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n->type == typeN) {
					err_arr.push_back("Assigning a value to a np");
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n->type == typeCon) {
					err_arr.push_back("Assigning a value to a constant");
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n->type == typeOpr) {
					err_arr.push_back("Operation cannot be an lvalue");
					Node* n11 = con(0, 0);
					return n11;
				}
				VarNode* varn1 = dynamic_cast<VarNode*>(n);
				if (find_var(varn1)) {
					err_arr.push_back("A variable with this name already exists");
				}
				if (n2 == nullptr) {
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n2->type == typeN) {
					err_arr.push_back("Assigning a np");
					Node* n1 = con(0, 0);
					return n1;
				}
				if (varn1->vtype == 2) {
					ProcStore[{varn1->vtype, varn1->name}][varn1->ind] = n2;
					push_Varlist(varn1);
					if (n2->type == typeOpr) {
						OprNode* oprn = dynamic_cast<OprNode*>(n2);
						if (oprn->oper == ':' || oprn->oper == ';') {
							n2 = building_var_left(p->children[1], 0);
							VarNode* varn2 = dynamic_cast<VarNode*>(n2);
							if ( varn2->vtype != 2) {
								err_arr.push_back("Non procedural variable cannot be assigned a procedural variable");
							}
							if (varn2->vtype == 2) {
								ProcStore[{varn1->vtype, varn1->name}][varn1->ind] = ProcStore[{varn2->vtype, varn2->name}][varn2->ind];
								go_proc_er(varn2);
							}
						} 
					}
				}
				else {
					if (n2->type == typeOpr) {
						OprNode* oprn = dynamic_cast<OprNode*>(n2);
						if (oprn->oper == '\n') {
							err_arr.push_back("A statement cannot be assigned to a non-procedural variable");
							Node* n1 = con(0, 0);
							return n1;
						}
					}
					n2 = ex_find_er(p->children[1]);
					if (n2->type == typeCon) {
						ConNode* conn = dynamic_cast<ConNode*>(n2);
						VarStore[{varn1->vtype, varn1->name}][varn1->ind] = conn->value;
						push_Varlist(varn1);
					}
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*>(n2);
						if (varn2->vtype == 2) {
							err_arr.push_back("Non procedural variable cannot be assigned a procedural variable");
						}
						VarStore[{varn1->vtype, varn1->name}][varn1->ind] = VarStore[{varn2->vtype, varn2->name}][varn2->ind];
						push_Varlist(varn1);
						go_proc_er(varn2);
					}
				}
				Node* n1 = con(1, 0);
				return n1;
			}

			case INC: { Node* n = ex_find_er(p->children[0]);
				if (n->type != typeId) {
					err_arr.push_back("Incrementing a constant");
					return n;
				}
				VarNode* varn = dynamic_cast<VarNode*> (n);
				if (varn->vtype != 1) {
					err_arr.push_back("Incrementing a non-integer variable");
				}
				if (!(VarStore.find({ varn->vtype, varn->name }) != VarStore.end() && VarStore[{varn->vtype, varn->name}].find(varn->ind) != VarStore[{varn->vtype, varn->name}].end())) {
					err_arr.push_back("Uninitialized memory access");
				}
				go_proc_er(varn);
				//inc
				return varn;
			}
			case DEC: { Node* n = ex_find_er(p->children[0]);
				if (n->type != typeId) {
					err_arr.push_back("Decrementing a constant");
					return n;
				}
				VarNode* varn = dynamic_cast<VarNode*> (n);
				if (varn->vtype != 1) {
					err_arr.push_back("Decrementing a non-integer variable");
				}
				if (!(VarStore.find({ varn->vtype, varn->name }) != VarStore.end() && VarStore[{varn->vtype, varn->name}].find(varn->ind) != VarStore[{varn->vtype, varn->name}].end())) {
					err_arr.push_back("Uninitialized memory access");
				}
				go_proc_er(varn);
				return varn;
			}
			case EQ: {Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*> (n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn1->vtype == 2 && n2->type != typeN) {
						err_arr.push_back("A procedure can only be compared with a null operator (np)");
					}
					go_proc_er(varn1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (varn1->vtype != varn2->vtype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
						if (varn1->vtype != 2 && varn2->vtype != 2) {
							Node* n12 = con((VarStore[{varn1->vtype, varn1->name}][varn1->ind] == VarStore[{varn2->vtype, varn2->name}][varn2->ind]), 0);
							return n12;
						}
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (varn1->vtype != conn2->ctype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						if (varn1->vtype != 2 ) {
							Node* n12 = con((VarStore[{varn1->vtype, varn1->name}][varn1->ind] == conn2->value), 0);
							return n12;
						}
					}
				}
				if (n1->type == typeCon) {
					ConNode* conn1 = dynamic_cast<ConNode*> (n1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (conn1->ctype != varn2->vtype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
						if (varn2->vtype != 2) {
							Node* n12 = con((conn1->value == VarStore[{varn2->vtype, varn2->name}][varn2->ind]), 0);
							return n12;
						}
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (conn1->ctype != conn2->ctype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						int f = 0;
						if (conn1->value == conn2->value) {
							f = 1;
						}
						Node* n12 = con(f, 0);
						return n12;
					}
				}
				Node* n12 = con(0, 0);
				return n12;
			}
			case PARR: {Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*> (n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					go_proc_er(varn1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (varn1->vtype || varn2->vtype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
						
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (varn1->vtype || conn2->ctype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
					}
				}
				if (n1->type == typeCon) {
					ConNode* conn1 = dynamic_cast<ConNode*> (n1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (conn1->ctype || varn2->vtype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (conn1->ctype || conn2->ctype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
					}
				}
				Node* n11 = con(0, 0);
				return n11;

				}
				case 'c': { Node* n = ex_find_er(p->children[0]);
					if (n == nullptr) {
						Node* n1 = con(0, 0);
						return n1;
					}
					if (n->type == typeN) {
						err_arr.push_back("np cannot be an identifier");
						Node* n1 = con(0, 0);
						return n1;
					}
					if (n->type == typeOpr) {
						err_arr.push_back("Operation cannot be an rvalue and identifier");
						Node* n11 = con(0, 0);
						return n11;
					}
					if (n->type == typeCon) {
						ConNode* conn1 = dynamic_cast<ConNode*> (n);
						return conn1;
					}
					VarNode* varn = dynamic_cast<VarNode*>(n);
					go_proc_er(varn);
					return varn;
				}
				case GOTO: {  Node* n = ex_find_er(p->children[0]);
					if (n == nullptr) {
						Node* n1 = con(1, 0);
						return n1;
					}
					if (n->type == typeN) {
						err_arr.push_back("np cannot be a condition");
						Node* n1 = con(1, 0);
						return n1;
					}
					if (n->type == typeCon) {
						ConNode* conn1 = dynamic_cast<ConNode*> (n);
						VarNode* varn = dynamic_cast<VarNode*>(p->children[1]);
						if (addr.find(varn->name) == addr.end())
							err_arr.push_back("Label with this name not declared");
						if (conn1->value) {
							if (addr.find(varn->name) != addr.end())
								lbll = varn->name;
						}
					}
					if (n->type == typeId) {
						VarNode* varn = dynamic_cast<VarNode*>(n);
						if (varn->vtype == 2) {
							err_arr.push_back("A procedure variable cannot be a condition");
						}
						else if (VarStore[{varn->vtype, varn->name}][varn->ind]) {
							VarNode* varn = dynamic_cast<VarNode*>(p->children[1]);
							if (addr.find(varn->name) == addr.end())
								err_arr.push_back("Label with this name not declared");
							else
								lbll= varn->name;
						}
					}
					Node* n1 = con(1, 0);
					return n1;
				}
			}
		}
		}
	}
	else
	{
	switch (p1->type) {
		case typeN: {Node* n11 = con(0, 0);
			return n11;
		}
		case typeCon: {Node* n11 = con(0, 0);
			return n11;
		}
		case typeId: {Node* n11 = con(0, 0);
			return n11;
		}
		case typeOpr: {
			OprNode* p = dynamic_cast<OprNode*>(p1);
			switch (p->oper) {
			case WHILE: {
				int r = 0;
				Node* n;
				ex_find_er(p->children[1]);
				do {
					n = ex_find_er(p->children[0]);
					if (n->type == typeCon) {
						ConNode* conn = dynamic_cast<ConNode*> (n);
						r = conn->value;
					}
					else if (n->type == typeId) {
						VarNode* varn = dynamic_cast<VarNode*> (n);
						go_proc(varn);
						r = VarStore[{varn->vtype, varn->name}][varn->ind];
					}
				} while (r);
				Node* n11 = con(0, 0);
				return n11;
			}
			case '\n': {ex_find_er(p->children[0]); return ex_find_er(p->children[1]); }
			default: {Node* n11 = con(0, 0);
				return n11; }
			}
		}
	}
	Node* n11 = con(0, 0);
	return n11;
	}
}
int exec_find_er(Node* p)
{
	do
	{
		ex_find_er(p);
	} while (lbll);
	return 0;
}





Node* building_var_left(Node* p, int level) {
	int res;
	if (p->type == typeOpr) {
		if (p->children[0]->type == typeId) {
			VarNode* varn = dynamic_cast<VarNode*>(p->children[0]);
			int index = building_var_right(p->children[1], level + 1);
			varn->ind.push_back(index);
			return p->children[0];
		}
		else if (p->children[0]->type == typeOpr) {
			Node* p1 = building_var_left(p->children[0], level + 1);
			int index = building_var_right(p->children[1], level + 1);
			VarNode* varn = dynamic_cast<VarNode*>(p1);
			varn->ind.push_back(index);
			return p1;
		}
		else if (p->children[0]->type == typeCon) {
			err_arr.push_back("The array name must be a variable");
		}
		else {
			err_arr.push_back("The array name must be a variable");
		}
	}
	else if (p->type == typeId) {
		VarNode* varn = dynamic_cast<VarNode*>(p);
		return varn;
	}
	else if (p->type == typeCon) {
		ConNode* conn = dynamic_cast<ConNode*>(p);
		return conn;
	}
	else if (p->type == typeN) {
		Null* nn = dynamic_cast<Null*>(p);
		return nn;
	}
	Null* nn = dynamic_cast<Null*>(p);
	return nn;
}

int building_var_right(Node* p, int level) { //return conn
	if (p->type == typeOpr) {
		if (p->children[0]->type == typeId) {
			VarNode* varn = dynamic_cast<VarNode*>(p->children[0]);
			int p1 = building_var_right(p->children[1], level + 1);
			varn->ind.push_back(p1);
			return VarStore[{varn->vtype, varn->name}][varn->ind];
		}
		else if (p->children[0]->type == typeOpr) {
			Node* p1 = building_var_left(p->children[0], 0); //typeId
			int index = building_var_right(p->children[1], level + 1);
			VarNode* varn = dynamic_cast<VarNode*>(p1);
			varn->ind.push_back(index);
			return VarStore[{varn->vtype, varn->name}][varn->ind];
		}
		else if (p->children[0]->type == typeCon) {
			err_arr.push_back("The array name must be a variable");
		}
		else {
			err_arr.push_back("The array name must be a variable");
		}

	}
	else if (p->type == typeId) {
		VarNode* varn = dynamic_cast<VarNode*>(p);
		if (varn->vtype != 1 && level) {
			err_arr.push_back("Indexing with a non-integer variable");
		}
		return VarStore[{varn->vtype, varn->name}][varn->ind];
	}
	else if (p->type == typeCon) {
		ConNode* conn = dynamic_cast<ConNode*>(p);
		if (conn->ctype != 1 && level) {
			err_arr.push_back("Indexing with a non-integer variable");
		}
		return conn->value;
	}
	else {
		Null* nn = dynamic_cast<Null*>(p);
		err_arr.push_back("Indexing with a non-integer variable");
		return 0;
	}
	return 0;
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
	if (addr.find(i) != addr.end())
		err_arr.push_back("Label with this name is already declared");
	p->label = i;
	addr.insert({ i,p });
}

void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

void init_VL(){
	for (int i = 0; i<6; ++i){
		std::vector<int> a;
		a.push_back(-1);
		Varlist.push_back(a);
	}
}

int main(void) {
	yyin = fopen ("./test.txt", "r");
	init_VL();
	yyparse();
	fclose (yyin);
	return 0;
}

	






















