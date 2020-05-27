#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "LangOb.h"
#include "BisonOb.tab.h"

char lbl = 0;

Node* ex(Node *p1) {
	if (!p1) return nullptr;
	if (lbl == p1->label)
		lbl = 0;
	if (!lbl)
		switch(p1->type) {
			case typeCon: {ConNode* conn = dynamic_cast<ConNode*>(p1); return conn;}
			case typeId: {VarNode* varn = dynamic_cast<VarNode*>(p1); return varn;}
			case typeOpr: {
				OprNode* p = dynamic_cast<OprNode*>(p1);
				switch(p->oper) {
					case WHILE:  {Node* n = ex(p->children[0]);
						int r = 0;
						if (n->type == typeCon) {
							ConNode* conn = dynamic_cast<ConNode*> (n);
							r = conn->value;
						} else if (n->type == typeId) {
							VarNode* varn = dynamic_cast<VarNode*> (n);
							r = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						while (r) {
							ex(p->children[1]);
							n = ex(p->children[0]);
							if (n->type == typeId) {
								VarNode* varn = dynamic_cast<VarNode*> (n);
								r = VarStore[{varn->vtype, varn->name}][varn->ind];
							} else if (n->type == typeCon) {
								ConNode* conn = dynamic_cast<ConNode*> (n);
								r = conn->value;
							}
						} 
						return nullptr;}
					case PRINT: { Node* n = ex(p->children[0]);
						int r = 0;
						if (n->type == typeId){
							VarNode* varn = dynamic_cast<VarNode*> (n);
							r = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						if (n->type == typeCon){
							ConNode* conn = dynamic_cast<ConNode*> (n);
							r = conn->value;
						}
						printf("%d\n", r); return nullptr;}
					case '\n': { ex(p->children[0]); return ex(p->children[1]);}
					case ':': { VarNode* varn = building_var_left(p);
							return varn;
							}
					case ';': { VarNode* varn = building_var_left(p);
							return varn;
							}
					case '=': { VarNode* varn = building_var_left(p->children[0]);
							int right_res = building_var_right(p->children[1]);
							int i = VarStore[{varn->vtype, varn->name}][varn->ind] = right_res;
							ConNode* conn (i,0,typeCon);
							return conn;
						}
					case UMINUS: { ConNode* conn = ex(p->children[0]);
						conn->value = -conn->value;
						return conn;
						}
					case INC: { VarNode* varn = dynamic_cast<VarNode*> (ex(p->children[0]));
						++VarStore[{varn->vtype, varn->name}][varn->ind];
						return varn;
					}
					case DEC: { VarNode* varn = dynamic_cast<VarNode*> (ex(p->children[0]));
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
						int r1 = 0;
						int r2 = 0;
						if (n1->type == typeId){
							VarNode* varn = dynamic_cast<VarNode*> (n1);
							r1 = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						if (n1->type == typeCon){
							ConNode* conn = dynamic_cast<ConNode*> (n1);
							r1 = conn->value;
						}
						if (n2->type == typeId){
							VarNode* varn = dynamic_cast<VarNode*> (n2);
							r2 = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						if (n2->type == typeCon){
							ConNode* conn = dynamic_cast<ConNode*> (n2);
							r2 = conn->value;
						}
						int  i = r1 == r2;
						ConNode* conn(i,0,typeCon);
						return conn;
					}
					case PARR: {Node* n1 = ex(p->children[0]);
						Node* n2 = ex(p->children[1]);
						bool b1 = 0;
						bool b2 = 0;
						if (n1->type == typeId){
							VarNode* varn = dynamic_cast<VarNode*> (n1);
							b1 = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						if (n1->type == typeCon){
							ConNode* conn = dynamic_cast<ConNode*> (n1);
							b1 = conn->value;
						}
						if (n2->type == typeId){
							VarNode* varn = dynamic_cast<VarNode*> (n2);
							b2 = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						if (n2->type == typeCon){
							ConNode* conn = dynamic_cast<ConNode*> (n2);
							b2 = conn->value;
						}
						bool b = !(b1 || b2);
						ConNode* conn(b,0,typeCon);
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
					/*case GOTO: {VarNode* varn = dynamic_cast<VarNode*>(p->children[0]); //////////////////////////////////////////////РАЗОБРАТЬСЯ С МЕТКАМИ
						if (!addr[varn->i])
							printf("Identificator '%c' is not detected: - ignore goto!\n", varn->name);
						else
							lbl = varn->i;
						return 0;}*/
				}
			}
		}
	else
	{
		switch(p1->type) {
			case typeCon: {return nullptr;}
			case typeId: {return nullptr;}
			case typeOpr:{
				OprNode* p = dynamic_cast<OprNode*>(p1);
				switch(p->oper) {
					case WHILE: {int r = 0;
						Node* n;
						do ex(p->children[1]);
						n = ex(p->children[0]);
						if (n->type == typeCon) {
							ConNode* conn = dynamic_cast<ConNode*> (n);
							r = conn->value;
						} else if (n->type == typeId) {
							VarNode* varn = dynamic_cast<VarNode*> (n);
							r = VarStore[{varn->vtype, varn->name}][varn->ind];
						}
						while (r); return nullptr;}
					case '\n': {ex(p->children[0]); return ex(p->children[1]);}
					default: return nullptr;
				}
			}
		}
		return nullptr;
	}
}
int exec(Node *p)
{
	do
	{
		ex(p);
	}
	while (lbl);
}


Node* building_var_left (Node* p){ 
	int res;
	if (p->type == typeOpr){
		if (p->children[0]->type == typeId){
			VarNode* varn = dynamic_cast<VarNode*>(p->children[0]);
			int index = building_var_right(p->children[1]);
			varn->ind.push_back(index);
			return p->children[0];
			// if (p1->type == typeId){
				// VarNode* varn1 = dynamic_cast<VarNode*>(p1);
				// varn->ind.push_back(VarStore[{varn1->vtype, varn1->name}][varn1->ind]);
			// } else if (p1->type == typeCon){
				// ConNode* conn1 = dynamic_cast<ConNode*>(p1);
				// varn->ind.push_back(conn1->value);
			// }
			// ConNode* res_conn(VarStore[{varn->vtype, varn->name}][varn->ind], varn->vtype, typeCon);
			// return res_conn;
		} else if (p->children[0]->type == typeOpr){
			Node* p1 = building_var_left(p->children[0]);
			int index = building_var_right(p->children[0]);
			VarNode* varn = dynamic_cast<VarNode*>(p1);
			varn->ind.push_back(index);
			return p1;
		}else if (p->children[0]->type == typeCon){
			//error
		}
	}else if (p->type == typeId){
		VarNode* varn = dynamic_cast<VarNode*>(p);
		return varn;
	}else if (p->type == typeCon){
		ConNode* conn = dynamic_cast<ConNode*>(p);
		return conn;
	}
	
	return nullptr;
}

int building_var_right (Node* p){ //return conn
	if (p->type == typeOpr){
		if (p->children[0]->type == typeId){
			VarNode* varn = dynamic_cast<VarNode*>(p->children[0]);
			int p1 = building_var_right(p->children[1]);
			varn->ind.push_back(p1);
			return VarStore[{varn->vtype, varn->name}][varn->ind];	
		} else if (p->children[0]->type == typeOpr){
			Node* p1 = building_var_left(p->children[0]); //typeId
			int index = building_var_right(p->children[0]);
			VarNode* varn = dynamic_cast<VarNode*>(p1);
			varn->ind.push_back(index);
			return VarStore[{varn->vtype, varn->name}][varn->ind];
		}else if (p->children[0]->type == typeCon){
			//error
		}
	}else if (p->type == typeId){
		VarNode* varn = dynamic_cast<VarNode*>(p);
		return VarStore[{varn->vtype, varn->name}][varn->ind];
	}else if (p->type == typeCon){
		ConNode* conn = dynamic_cast<ConNode*>(p);
		return conn->value;
	}
	return 0;
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
		if(p->type == typeCon) { 
			ConNode* conn = dynamic_cast<ConNode*>(p);
			printf("%d\n", conn->value);
		}
		if (p->type == typeId) {
			VarNode* varn = dynamic_cast<VarNode*>(p);
			printf("%c\n", varn->name); 
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