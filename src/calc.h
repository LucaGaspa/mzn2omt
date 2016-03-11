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
#include "number.h"
#include "intervalset.h"

using namespace std;

template class msat::Interval<DNumber>;
template class msat::IntervalSet<DNumber>;
typedef msat::Interval<DNumber> IntInterval;
typedef msat::IntervalSet<DNumber> IntIntervalSet;

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
	//Literal represents Var_ID,Par_ID,Int,Float,Bool (everything identified by str)
	string* id;

public:
	Literal(char* lit);

	~Literal();

	string getID();
	
};

class Array {
	//Array represents IDs with index access (es: a[1])
	//maybe can be absorbed by Literal
	string id;
	//WIP:: std::vector<int> index; //means vector<IntervalSet*>* index;

};

class Atom {
	//Atom is a container for everything regarding Vars, pars, sets.
	ATOM_TYPE type;
	union{
		Array* array;
		IntIntervalSet* set;
		Literal* literal;
	};
	//vector<string> index;
public:
	Atom(Array* arr);
	Atom(IntIntervalSet* s);
	Atom(Literal* lit);
	~Atom();

	Literal* getLiteral();
};

class Fun {
	//Fun represents call_expr non-terminal
	string* id; //function identifier (forall, exist, sum, ...)

	vector<Atom*>* args;	//args
	Expr* body;				//body (actually a free-standing parse tree)
	Expr* condition;		//example where condition in forall

};

class Let {
	//Let represents let_expr non-terminal
	Hashtable* letMap;	//SymbolTable* let_map
	Expr* body;			//body of the let

};

class Ite {
	//Ite represents if_then_else_expr non-terminal
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



class Symbol {
	//symbol is initialized in declaration phase and creates ths symbol table
	ATOM_TYPE type;		//type
	DOMAIN_TYPE domain;	//domain
	TI_TYPE ti_type;
	Expr* set; 			//range:   Expr*->Item*->Atom*-> interval set
	//WIP:: //IntIntervalSet* range; //range:   Expr*->Item*->Atom*-> interval set
	//vector<Symbol>* index
	//ID
	//values
public:		
	Symbol(DOMAIN_TYPE dom);
	Symbol(Expr* set);

	void setTi_type(TI_TYPE t);
	void setSymbolType(ATOM_TYPE tp);
};

class SymbolTable {
	//HashTable --> <string,class*>
	Hashtable* table;
};

class Interpreter {
	//Interpreter stores all symbolTables used in global and local scope
	//moreover it prints every constraint once reduced
	SymbolTable* globalTable;
	stack<SymbolTable*> localTable;

	//printConstraint(Expr* expr);
};

#endif
