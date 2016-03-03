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
using namespace std;


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
	string id;

public:
	Literal(char* lit) : id(lit) { }

	~Literal(){
		id.clear();
	}

	string getID(){
		return id;
	}
	
};

class binSet {
	//
};

class Array {
	string id;
	std::vector<int> index;

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
	Atom(Array* arr){
		type = ARR;
		array = arr;
	}
	Atom(binSet* s){
		type = SET;
		set = s;
	}
	Atom(Literal* lit){
		type = LIT;
		literal = lit;
	}
	~Atom(){
		switch(type){
			case ARR:
				delete array;
				break;
			case SET:
				delete set;
				break;
			case LIT:
				delete literal;
				break;
		}
	}

	Literal* getLiteral(){return literal;}
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
public:
	Item(Atom* at){
		type = ATM;
		atom = at;
	}
	Item(Fun* f){
		type = FUN;
		fun = f;
	}
	Item(Let* l){
		type = LET;
		let = l;
	}
	Item(Ite* i){
		type = ITE;
		ite = i;
	}
	~Item(){
		switch(type){
			case ATM:
				delete atom;
				break;
			case FUN:
				delete fun;
				break;
			case LET:
				delete let;
				break;
			case ITE:
				delete ite;
				break;	
		}
	}

	Atom* getAtom(){return atom;}

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
	Expr(char* lit){
		Literal* literal = new Literal(lit);
        Atom* atom = new Atom(literal);
        Item* it = new Item(atom);
        nops = 1;
        item = it;
	}
	Expr(int n, Item* it){
		nops = n;
		item = it;
	}
	Expr(int n, int o, vector<Expr*>* v){
		nops = n;
		oper = o;
		op = v;
	}
	~Expr(){
		if(nops == 1){
			delete item;
		}else{
			//TODO:: forall v in vector -> delete vector[i]
		}
	}

	Item* getItem(){return item;}

	/*Expr* createLiteral(char* lit){
		Literal* literal = new Literal(lit);
        Atom* atom = new Atom(literal);
        Item* it = new Item(atom);
        nops = 1;
        item = it;
	}*/

};



//to review: ti_expr_node creates Interpreter Tables, Expr_node use this!

class SymbolTable {
	Hashtable* parTable;
	//vector<binSet>* setList;

};

#endif
