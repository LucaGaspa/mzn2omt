/*********************************************************************** 
 * calc.h                                                              *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include <unordered_map>
#include <vector> 
using namespace std;

enum VAR_TYPE {VAR, PAR, SET};
enum ITEM_TYPE {ATM,FUN,LET,ITE};


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


class Atom {
	//Atom is a container for everything regarding Vars, pars, sets.
	
	VAR_TYPE type;
	string str;
	//vector<string> index;
};

class Fun {
	//Fun represent call_expr element
	
	vector<Atom*> args;	//args
	Expr* body;			//body (actually a free-standing parse tree)
	Expr* condition;	//example where condition in forall

};

class Let {
	Hashtable* letMap; //SymbolTable* let_map
	Expr* body;			//body of the let

};

class Ite {
	//if condition is analizable evaluates it at runtime and choose the branch
	//else add a constraint that is equal to it

	Expr* condition;	//condition
	Expr* trueBranch;	//case true
	Expr* falseBranch;	//case false
};

class Item {
	//Item contains independent items find into expr

	ITEM_TYPE type; //distinguish between types od Atoms

	union{
		Atom* atom;	//var, par, or set
		Fun* fun;	//entire function node (ex: forall)
		Let* let;	//entire let node
		Ite* ite;	//if-then-else node
	};

};

class Expr {
	//Expr is a node of the parsing three containing operands or a leaf (Item)
	//Functions and Let are considered leaf because parsed by themself

	int nops;	//if(nops == 1) -> it's an Item
	int oper;	//if (isItem) -> oper not init
	
	union{
		vector<Expr*> op;	//operands of the Expr
		Item item;			//Item thought as a leaf (independently parsable item)
	};

};



//to review: Expr_node must be the sum of expr_node and ti_expr_node!

class SymbolTable {
	Hashtable* parTable;
	//vector<binSet>* setList;

};