/*********************************************************************** 
 * calc.h                                                              *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

enum VAR_TYPE {VAR, PAR, SET};


class Hashtable {
    std::unordered_map<const void *, const void *> htmap;

public:
    void put(const void *key, const void *value) {
            htmap[key] = value;
    }

    const void *get(const void *key) {
            return htmap[key];
    }

};

//class Node;
class Expr;	

class binSet {
	//
};


class Var {
	VAR_TYPE type;
	std::string;
	Vector<string> index;
};

class Fun {
	Vector<Var> args;
	Expr* body;
	Expr* condition;


};

class Let {
	Hashtable* letMap;
	Expr* body;

};

class Atom {
	bool isFun;
	bool isVar;
	bool isLet;

	Var* var;
	Fun* fun;
	Let* let;

};

class Expr {
	int nops;
	int oper;
	Vector<Expr> op;

};



//to review: Expr_node must be the sum of expr_node and ti_expr_node!

class SymbolTable {
	Hashtable* parTable;
	Vector<binSet>* setList;


};