/*********************************************************************** 
 * calc.h                                                              *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
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
#include <queue> 
#include <string>
#include <stack>
#include <stdarg.h> 
#include "number.h"
#include "intervalset.h"

using namespace std;

template class msat::Interval<DNumber>;
template class msat::IntervalSet<DNumber>;
typedef msat::Interval<DNumber> Interval;
typedef msat::IntervalSet<DNumber> IntervalSet;

enum DOMAIN_TYPE{INT,FLOAT,BOOL};
enum TI_TYPE{VAR,PAR,SETVAR,SETPAR};
enum ATOM_TYPE{ARR,SET,LIT};

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

class Expr_node {
	//Container for various items. Never istantiated (Pure virtual class).
public:
	virtual void interpret() = 0;
};


class Expr: public Expr_node {
	//Expr represents expr non-terminal. Briefly all MZN possible math operations
	int oper;					//operator code
	int nops;					//number of operands
	std::vector<Expr_node*>* op;	//operands

public:
	Expr(int oper, int nops, ...);
	
	void interpret();
};


class ExprList: public Expr_node {
	//ExprList represents expr_list non-terminal and is useful also for array indexing
	std::vector<Expr_node*>* element;

public:
	ExprList(Expr_node* el);

	void interpret();

	void add(Expr_node* el);
};


class Literal: public Expr_node {
	//Literal represnts both IDs, (int,bool,float) literals and array IDs with index to access
	string* id;					//ID
	ExprList* index;			//indexs to access the array

public:
	Literal(char* lit);
	
	void interpret();
};

class Fun: public Expr_node {
	//Fun represents call_expr non-terminal
	string* id; //function identifier (forall, exist, sum, ...)

	//maybe ExprList args; or vector<Literal*>* args;	//args
	ExprList* args;				//args
	Expr_node* body;			//body (actually a free-standing parse tree)
	Expr_node* condition;		//example where condition in forall

public:
	void interpret();
};

class Let: public Expr_node {
	//Let represents let_expr non-terminal
	Hashtable* letMap;			//SymbolTable* let_map
	Expr_node* body;			//body of the let

public:
	void interpret();
};

class Ite: public Expr_node {
	//Ite represents if_then_else_expr non-terminal
	//if condition is analizable evaluates it at runtime and choose the branch
	//else add a constraint that is equal to it

	Expr_node* condition;		//condition
	Expr_node* trueBranch;		//case true
	Expr_node* falseBranch;		//case false

public:
	void interpret();
};


class Symbol {
	//symbol is initialized in declaration phase and creates ths symbol table
	ATOM_TYPE type;				//type
	DOMAIN_TYPE domain;			//domain
	TI_TYPE ti_type;			//VAR,PAR,VARSET,PARSET (error-checking purpose)
	
	IntervalSet* range;			//ID domain (INT o FLOAT)

	vector<IntervalSet*>* index;	//array index must be PAR and INT

	string* id;					//ID
	ExprList* value;			//values if PAR. Literals stored in value[0]\

public:		
	Symbol(DOMAIN_TYPE dom);
	Symbol(Expr_node* set);
	~Symbol();

	void setTi_type(TI_TYPE t);
	void setSymbolType(ATOM_TYPE tp);
	void setIdentifier(char* ident);

	void importIndexes(queue<Symbol*>* ind);
	IntervalSet* exportIndex();

	string domain2str();
	void printDecl();
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
