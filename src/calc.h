typedef enum{ATOM, EXPR, SET, FORALL, EXISTS, ALLDIFF, SUM, COMP, COUNT, LET, BOOL2INT, ABS, FMIN, FMAX} nodeType;
typedef enum{PARTYPE, VARTYPE, ARRAY1DTYPE, ARRAY2DTYPE, ARRAY3DTYPE, PAR1DTYPE, PAR2DTYPE,PAR3DTYPE} varType;
typedef enum{NONE, INTTYPE, FLOATTYPE, BOOLTYPE} basicType;

struct SymbolRec* symbolTable;

typedef struct uValue{
    basicType litType;
    union{
	    int iValue;
	    float fValue;
	    int bValue;
	};
} uValue;

typedef struct SmartSet {
	int setDim;
	uValue* values;
} SmartSet;

typedef struct u_or_set{
	nodeType type;
	union{
		uValue* val;
		SmartSet* set;
	};
} u_or_set;

//////////////////////////////////////////////////////
//	NODES
/////////////////////////////////////////////////////

typedef struct Ti_expr_node {
	char* idName;
	varType idType;
	struct Expr_node* idRange;
	struct Ti_expr_node* idIndex;
	
	struct Ti_expr_node* next;
} Ti_expr_node;

typedef struct Forall_node{
	struct Expr_node* param;
	struct Expr_node* body;
}Forall_node;

typedef struct Expr_node {
	nodeType type;
	varType ti_type;
	//ATOM
	basicType atomType;
	char* idName;
	struct Expr_node* arrAccess;
	uValue litVal;
	//SET
	SmartSet* set;
	uValue ub;
	uValue lb;
	struct Expr_node* ub_c;
	struct Expr_node* lb_c;
	//EXPR
	int oper;
	int nops;
	struct Expr_node** op;
	//FORALL
	struct Expr_node* where;
	struct Forall_node* forall;
	struct Ti_expr_node* let_decl;
	struct Expr_node* let_eq;
	struct Expr_node* let_body;
	
	struct Expr_node* next;
} Expr_node;

//////////////////////////////////////////////////////
//	TABLES
/////////////////////////////////////////////////////

typedef struct SymbolRec {
	char* symName;
	varType type;
	nodeType parType;
	basicType symType;
	uValue symValue;
	SmartSet* set;
	struct SymbolRec* next;
} SymbolRec;

typedef struct ArrayRec {
	char* arrayName;
	varType type;
	int index_start_1;
	int index_end_1;
	int dim_1;
	int index_start_2;
	int index_end_2;
	int dim_2;
	int index_start_3;
	int index_end_3;
	int dim_3;
	/*
	SmartSet* set;
	uValue ub;
	uValue lb;
	*/
	struct ArrayRec* next;
} ArrayRec;

typedef struct Tables {
	struct SymbolRec* symTab;
	struct ArrayRec* arrTab;
} Tables;
