/*********************************************************************** 
 * calc.h                                                              *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector> 
#include <string>
#include <stack>

using namespace std;


enum DOMAIN_TYPE{INT,FLOAT,BOOL};
enum TI_TYPE{VAR,PAR,SETVAR,SETPAR}; //maybe useless
enum ATOM_TYPE{ARR,SET,LIT};
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


class Expr;	

class Literal {
	string* id;

public:
	Literal(char* lit);

	~Literal();

	string getID();
	
};

class binSet {
	//means IntervalSet
};

class Array {
	string id;
	std::vector<int> index; //means vector<IntervalSet*>* index;

};

class Atom {
	//Atom is a container for everything regarding Vars, pars, sets.
	ATOM_TYPE type;
	union{
		Array* array;
		binSet* set;
		Literal* literal;
	};
	//vector<string> index;
public:
	Atom(Array* arr);
	Atom(binSet* s);
	Atom(Literal* lit);
	~Atom();

	Literal* getLiteral();
};

class Fun {
	//Fun represent call_expr element
	string* id; //function identifier (forall, exist, sum, ...)

	vector<Atom*>* args;	//args
	Expr* body;				//body (actually a free-standing parse tree)
	Expr* condition;		//example where condition in forall

};

class Let {
	Hashtable* letMap;	//SymbolTable* let_map
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
public:
	Item(Atom* at);
	Item(Fun* f);
	Item(Let* l);
	Item(Ite* i);
	~Item();

	Atom* getAtom();
};

class Expr {
	//Expr is a node of the parsing three containing operands or a leaf (Item)
	//Functions and Let are considered leaf because parsed by themself

	int nops;	//if(nops == 1) -> it's an Item
	int oper;	//if (isItem) -> oper not init
	union{
		vector<Expr*>* op;	//operands of the Expr
		Item* item;			//Item thought as a leaf (independently parsable item)
	};
public:
	Expr(char* lit);	//create an Expr with an Item-Atom-Literal, means ID
	Expr(int n, Item* it);
	Expr(int n, int o, vector<Expr*>* v);
	~Expr();
	
	Item* getItem();
	
};


//to review: ti_expr_node creates Interpreter Tables, Expr_node use this!

class Symbol {
	ATOM_TYPE type;		//type
	DOMAIN_TYPE domain;	//domain
	TI_TYPE ti_type;
	//range:   Expr*->Item*->Atom*-> interval set
	//vector<index*>*: interval set
	//ID
	//values
public:		
	Symbol(DOMAIN_TYPE dom);
	//Symbol(Expr* set);

	void setTi_type(TI_TYPE t);
	void setSymbolType(ATOM_TYPE tp);
};

class SymbolTable {
	Hashtable* table;
};

class Interpreter {
	SymbolTable* globalTable;
	stack<SymbolTable*> localTable;

	//printConstraint(Expr* expr);
};

#endif
