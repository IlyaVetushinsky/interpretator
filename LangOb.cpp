#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "LangOb.h"
#include "BisonOb.tab.h"
      

char lbl = 0;
int building_var_right (Node* p, int level);
Node* building_var_left (Node* p, int level);
void init_VL();
void go_proc(VarNode* varn);
int find_rec_right(VarNode* varn1,VarNode* varn2);
int find_rec_left(VarNode* varn1,VarNode* varn2);
int find_rec(VarNode* &varn1,VarNode* &varn2);
void push_Varlist(Node* p);
int find_var(Node* p);
extern Node *np();
Node* moving(Node* p);

Node* ex(Node* p1) {
	if (!p1) return nullptr;
	if (lbl == p1->label)
		lbl = 0;
	if (!lbl)
		switch (p1->type) {
		case typeFun: { moving(p1); }
		case typeCon: {ConNode* conn = dynamic_cast<ConNode*>(p1); return conn; }
		case typeId: {VarNode* varn = dynamic_cast<VarNode*>(p1); return varn; }
		case typeOpr: {
			OprNode* p = dynamic_cast<OprNode*>(p1);
			switch (p->oper) {
			case WHILE: {Node* n = ex(p->children[0]);
				int r = 0;
				if (n->type == typeCon) {
					ConNode* conn = dynamic_cast<ConNode*> (n);
					r = conn->value;
				}
				else if (n->type == typeId) {
					VarNode* varn = dynamic_cast<VarNode*> (n);
					go_proc(varn);
					r = VarStore[{varn->vtype, varn->name}][varn->ind];
				}
				while (r) {
					ex(p->children[1]);
					n = ex(p->children[0]);
					if (n->type == typeId) {
						VarNode* varn = dynamic_cast<VarNode*> (n);
						go_proc(varn);
						r = VarStore[{varn->vtype, varn->name}][varn->ind];
					}
					else if (n->type == typeCon) {
						ConNode* conn = dynamic_cast<ConNode*> (n);
						r = conn->value;
					}
				}
				return nullptr; }
			case PRINT: { Node* n = ex(p->children[0]);
				int r = 0;
				if (n->type == typeId) {
					VarNode* varn = dynamic_cast<VarNode*> (n);
					go_proc(varn);
					std::cout << VarStore[{varn->vtype, varn->name}][varn->ind] << std::endl;
				}
				if (n->type == typeCon) {
					ConNode* conn = dynamic_cast<ConNode*> (n);
					if (conn->ctype == 0) {
						if (conn->value)
							std::cout << "T" << std::endl;
						else
							std::cout << "F" << std::endl;
					}
					else {
						std::cout << conn->value << std::endl;
					}
				}
				return nullptr;
			}
			case '\n': { Node* n = ex(p->children[0]);
				return ex(p->children[1]);
			}
			case ':': {Node* n = building_var_left(p, 0);
				VarNode* varn = dynamic_cast<VarNode*>(n);
				return varn;
			}
			case ';': {Node* n = building_var_left(p, 0);
				VarNode* varn = dynamic_cast<VarNode*>(n);
				return varn;
			}
			case '@': {
				Node* n1 = building_var_left(p->children[0], 0);
				Node* n2 = building_var_left(p->children[1], -1);
				VarNode* varn1 = dynamic_cast<VarNode*>(n1);
				VarNode* varn2 = dynamic_cast<VarNode*>(n2);
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
					std::cout << "Procedure identifier recursion" << std::endl;
				}
				return n11;
			}
			case '%': {
				Node* n1 = building_var_left(p->children[0], 0);
				Node* n2 = building_var_left(p->children[1], -1);
				VarNode* varn1 = dynamic_cast<VarNode*>(n1);
				VarNode* varn2 = dynamic_cast<VarNode*>(n2);
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
					std::cout << "The identifier was not associated with the procedure" << std::endl;
				}
				return n11;
			}
			case '=': { Node* n = ex(p->children[0]);
				VarNode* varn1 = dynamic_cast<VarNode*>(n);
				Node* n2 = p->children[1];
				if (varn1->vtype == 2) {
					if (n2->type == typeOpr) {
						OprNode* oprn = dynamic_cast<OprNode*>(n2);
						if (oprn->oper == 'c') {
							VarNode* varn = dynamic_cast<VarNode*>(oprn->children[0]);
							go_proc(varn);
						}
						ProcStore[{varn1->vtype, varn1->name}][varn1->ind] = n2;
						if (oprn->oper == ':' || oprn->oper == ';') {
							n2 = ex(p->children[1]);
							VarNode* varn2 = dynamic_cast<VarNode*>(n2);
							if (varn2->vtype == 2)
								ProcStore[{varn1->vtype, varn1->name}][varn1->ind] = ProcStore[{varn2->vtype, varn2->name}][varn2->ind];
							go_proc(varn2);
						}
					}
				}
				else {
					n2 = ex(p->children[1]);
					if (n2->type == typeCon) {
						ConNode* conn = dynamic_cast<ConNode*>(n2);
						VarStore[{varn1->vtype, varn1->name}][varn1->ind] = conn->value;
					}
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*>(n2);
						VarStore[{varn1->vtype, varn1->name}][varn1->ind] = VarStore[{varn2->vtype, varn2->name}][varn2->ind];
						go_proc(varn2);
					}
				}
				Node* n1 = con(1, 0);
				return n1;
			}
			case INC: { VarNode* varn = dynamic_cast<VarNode*> (ex(p->children[0]));
				go_proc(varn);
				++VarStore[{varn->vtype, varn->name}][varn->ind];
				return varn;
			}
			case DEC: { VarNode* varn = dynamic_cast<VarNode*> (ex(p->children[0]));
				go_proc(varn);
				--VarStore[{varn->vtype, varn->name}][varn->ind];
				return varn;
			}
					// { if (p->children[0]->type == typeOpr){
							// OprNode* oprn = dynamic_cast<OprNode*>(p->children[0]);
							// if (oprn->oper == ';' || oprn->oper == ':'){
								// VarNode* varn = building_var_left(oprn); 
								// --VarStore[{varn->vtype, varn->name}][varn->ind];
								// return varn;
							// }else{
								// VarNode* varn = dynamic_cast<VarNode*> (ex(p->children[0]));
								// --VarStore[{varn->vtype, varn->name}][varn->ind];
								// return varn;
							// }
						// } else if (p->children[0]->type == typeId){
							// VarNode* varn = dynamic_cast<VarNode*> (p->children[0]); 
							// --VarStore[{varn->vtype, varn->name}][varn->ind];
							// return varn;
						// } else {
							// //error
						// }
						// return 0;	
					// }
			case EQ: {Node* n1 = ex(p->children[0]);
				Node* n2 = ex(p->children[1]);

				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*> (n1);
					go_proc(varn1);
					if (varn1->vtype == 2 && n2->type == typeN) {
						if (!(ProcStore.find({ varn1->vtype, varn1->name }) != ProcStore.end() && ProcStore[{varn1->vtype, varn1->name}].find(varn1->ind) != ProcStore[{varn1->vtype, varn1->name}].end())) {
							Node* n11 = con(1, 0);
							return n11;
						}
					}
				}
				int r1 = 0;
				int r2 = 0;
				if (n1->type == typeId) {
					VarNode* varn = dynamic_cast<VarNode*> (n1);
					r1 = VarStore[{varn->vtype, varn->name}][varn->ind];
				}
				if (n1->type == typeCon) {
					ConNode* conn = dynamic_cast<ConNode*> (n1);
					r1 = conn->value;
				}
				if (n2->type == typeId) {
					VarNode* varn = dynamic_cast<VarNode*> (n2);
					r2 = VarStore[{varn->vtype, varn->name}][varn->ind];
				}
				if (n2->type == typeCon) {
					ConNode* conn = dynamic_cast<ConNode*> (n2);
					r2 = conn->value;
				}
				int  i = (r1 == r2);
				Node* n11 = con(i, 0);
				ConNode* conn = dynamic_cast<ConNode*>(n11);
				return conn;
			}
			case PARR: {Node* n1 = ex(p->children[0]);
				Node* n2 = ex(p->children[1]);
				bool b1 = 0;
				bool b2 = 0;
				if (n1->type == typeId) {
					VarNode* varn = dynamic_cast<VarNode*> (n1);
					go_proc(varn);
					b1 = VarStore[{varn->vtype, varn->name}][varn->ind];
				}
				if (n1->type == typeCon) {
					ConNode* conn = dynamic_cast<ConNode*> (n1);
					b1 = conn->value;
				}
				if (n2->type == typeId) {
					VarNode* varn = dynamic_cast<VarNode*> (n2);
					go_proc(varn);
					b2 = VarStore[{varn->vtype, varn->name}][varn->ind];
				}
				if (n2->type == typeCon) {
					ConNode* conn = dynamic_cast<ConNode*> (n2);
					b2 = conn->value;
				}
				bool b = !(b1 || b2);
				Node* n11 = con(b, 0);
				ConNode* conn = dynamic_cast<ConNode*>(n11);
				return conn;
				// VarNode* varn1;
				// ConNode* conn1;
				// VarNode* varn2;
				// ConNode* conn2;
				// int f1 = 0;
				// int f2 = 0;
				// if (p->children[0]->type == typeOpr){
					// OprNode* oprn = dynamic_cast<OprNode*>(p->children[0]);
					// if (oprn->oper == ';' || oprn->oper == ':'){
						// varn1 = building_var_left(oprn);
						// f1 = 1;
					// }else{
						// varn1 = dynamic_cast<VarNode*> (ex(p->children[0]));
						// f1 = 1;
					// }
				// }else if (p->children[0]->type == typeId){
					// varn1 = dynamic_cast<VarNode*> (p->children[0]);
					// f1 = 1;
				// } else {
					// conn1 = dynamic_cast<ConNode*> (p->children[1]);
					// f1 = 0;
				// }	
				// if (p->children[1]->type == typeOpr){
					// OprNode* oprn = dynamic_cast<OprNode*>(p->children[1]);
					// if (oprn->oper == ';' || oprn->oper == ':'){
						// varn2 = building_var_left(oprn);
						// f2 = 1;
					// }else{
						// varn2 = dynamic_cast<VarNode*> (ex(p->children[1]));
						// f2 = 1;
					// }
				// }else if (p->children[1]->type == typeId){
					// varn2 = dynamic_cast<VarNode*> (p->children[1]);
					// f2 = 1;
				// } else {
					// conn2 = dynamic_cast<ConNode*> (p->children[1]);
					// f2 = 0;
				// }	
				// bool r1 = 0;
				// bool r2 = 0;
				// if (f1){
					// r1 = VarStore[{varn1->vtype, varn1->name}][varn1->ind];
				// }else{
					// r1 = conn1->value; 
				// }
				// if (f2){
					// r2 = VarStore[{varn2->vtype, varn2->name}][varn2->ind];
				// }else{
					// r2 = conn2->value; 
				// }
				// return !(r1 || r2);
			}
				case 'c': { Node* n = ex(p->children[0]);
					if (n == nullptr) {
						Node* n1 = con(0, 0);
						return n1;
					}
					if (n->type == typeN) {
						Node* n1 = con(0, 0);
						return n1;
					}
					if (n->type == typeCon) {
						ConNode* conn1 = dynamic_cast<ConNode*> (n);
						return conn1;
					}
					VarNode* varn = dynamic_cast<VarNode*>(n);
					go_proc(varn);
					return varn;
				}
				case GOTO: {  Node* n = ex(p->children[0]);
					if (n->type == typeCon) {
						ConNode* conn1 = dynamic_cast<ConNode*> (n);
						if (conn1->value) {
							VarNode* varn = dynamic_cast<VarNode*>(p->children[1]);
							if (addr.find(varn->name) == addr.end())
								std::cout << "Label with this name not declared" << std::endl;
							else
								lbl = varn->name;
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
								lbl = varn->name;
						}
					}
					Node* n1 = con(1, 0);
					return n1;
					}
				}
			}
		}
else
	{
	switch (p1->type) {
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
				ex(p->children[1]);
				do {
					n = ex(p->children[0]);
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
			case '\n': {ex(p->children[0]); return ex(p->children[1]); }
			default: {Node* n11 = con(0, 0);
				return n11; }
			}
		}
	}
	Node* n11 = con(0, 0);
	return n11;
	}
}
int exec(Node* p)
{
	do
	{
		ex(p);
	} while (lbl);
	return 0;
}


void go_proc(VarNode* varn1) {
	if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
		varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
	}
	for (int i = 0; i < varn1->id_1.size(); ++i) {
		if ((varn1->id_1[i])->id_1.size()) {
			go_proc(varn1->id_1[i]);
		}
		VarNode* varn2 = varn1->id_1[i];
		ex(ProcStore[{varn2->vtype, varn2->name}][varn2->ind]);
	}
}

void print_Tree(Node *p, int level)
{
	if (p) {
		for (int i = 0; i < 3 * level - 2; ++i) {
			printf(" ");
		}
		if (level){
			printf("-->");
		}
		if (p->type == typeFun){
					FunNode* f = dynamic_cast<FunNode*> (p);
					if (f->ftype == 1)
						std::cout << "mf" << std::endl;
					else if (f->ftype == 2)
						std::cout << "mb" << std::endl;
					else if (f->ftype == 3)
						std::cout << "mr" << std::endl;
					else if (f->ftype == 4)
						std::cout << "ml" << std::endl;
					else if (f->ftype == 5)
						std::cout << "tp" << std::endl;
				} 
		if(p->type == typeCon) { 
			ConNode* conn = dynamic_cast<ConNode*>(p);
			std::cout << conn->value << std::endl;
		}
		if (p->type == typeId) {
			VarNode* varn = dynamic_cast<VarNode*>(p);
			std::cout << varn->name << std::endl;
		}
		if (p->type == typeOpr) {
			OprNode* oprn = dynamic_cast<OprNode*>(p);
			std::cout << oprn->name << std::endl;
			for (int i = 0; i < oprn->nops; ++i) {
				print_Tree(oprn->children[i], level + 1);
			}
		}
	}
}