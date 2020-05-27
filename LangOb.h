typedef enum { typeCon, typeId, typeOpr } nodeEnum;

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
	int vtype; // 0- bool, 1- int
	int name;
	std::vector<int> ind; // indexes
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

extern std::map<std::vector<int>,std::map<std::vector<int>,int>> VarStore;
extern Node* addr[26];