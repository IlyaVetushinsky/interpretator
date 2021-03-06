typedef enum { typeCon, typeId, typeOpr, typeN, typeFun } nodeEnum;



typedef class Node {
	public:
	nodeEnum type;
	int label;
	std::vector <Node*> children;
	Node(nodeEnum t){
		type = t;
	}
	virtual ~Node(){};
};

typedef class ConNode : public Node{
	public:
	int ctype;// 0- bool, 1- int
	int value;
	ConNode(int v, int ct, nodeEnum t):Node(t){
		value = v;
		ctype = ct;
	}
};

typedef class VarNode : public Node{
	public:
	int vtype; // 0- bool, 1- int, 2- proc, 3- label
	int name;
	std::vector<int> ind; // indexes
	std::vector<VarNode*> id_1;//что идентифицирует эта переменная
	std::vector<VarNode*> id_2;//что идентифицирует эту переменную
	VarNode(int n, int vt, nodeEnum t):Node(t){
		name = n;
		vtype = vt;
	}
};

typedef class OprNode : public Node{
	public:
	std::string name;
	int oper; /* operator */
    int nops; /* number of operands */

	OprNode(std::string n, int op, int nop, nodeEnum t):Node(t){
		name = n;
		oper = op;
		nops = nop;
	}
};

typedef class Null : public Node{
	public:
	Null():Node(typeN){;}
};

typedef class FunNode : public Node{
public:
	int ftype;
	public:
	FunNode(int t):Node(typeFun){
		ftype = t;
	}
};

struct C{
	int X;
	int Y;
};
constexpr bool operator < (const C& _Left, const C& _Right) {

	return 1000*_Left.X + _Left.Y < 1000*_Right.X+ _Right.Y;
}

extern Node *opr(std::string n, int oper, int nops, ...);
extern Node *id(int i, int t);
extern Node *con(int value, int t);
extern void setlabel (int i ,Node *p);
extern void freeNode(Node *p);
extern int exec(Node *p);
extern Node* building_var_left (Node* p, int level);
extern int building_var_right (Node* p, int level);
extern void print_Tree(Node *p, int level);
extern int yylex();
extern void yyerror(char*);
extern Node* ex_find_er(Node *p1);
extern int exec_find_er(Node *p);
extern void init_VL();
extern void go_proc(VarNode* varn);
extern int find_rec_right(VarNode* varn1,VarNode* varn2);
extern int find_rec_left(VarNode* varn1,VarNode* varn2);
extern int find_rec(VarNode* &varn1,VarNode* &varn2);
extern void push_Varlist(Node* p);
extern int find_var(Node* p);
extern void clear_id_store(std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >>& IdStore);
extern Node *np();
extern void l_ballance(Node* n);
extern int lb_ballance(Node* p);
extern void wrong_lbls();
extern int dir;
extern C R_cord;
extern std::map<C,int> Land;
extern std::map<C, int> done_Land;
extern std::vector<std::string> err_arr;
extern std::map<std::vector<int>,std::map<std::vector<int>,int>> VarStore;
extern std::map<std::vector<int>,std::map<std::vector<int>,Node*>> ProcStore;  
extern std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >> IdStore; 
extern std::map<int, Node*> addr;    