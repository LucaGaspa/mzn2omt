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
#include "intervalSetLib/number.h"
#include "intervalSetLib/intervalset.h"

using namespace std;

template class msat::Interval<DNumber>;
template class msat::IntervalSet<DNumber>;
typedef msat::Interval<DNumber> Interval;
typedef msat::IntervalSet<DNumber> IntervalSet;

enum DOMAIN_TYPE{INT,FLOAT,BOOL,ID};
enum TI_TYPE{VAR,PAR,SETVAR,SETPAR};
enum ATOM_TYPE{ARR,SET,LIT};
enum EXPR_DOMAIN{INTINT,FLOATINT,INTFLOAT,FLOATFLOAT,BOOLBOOL};


class Literal;
class ExprList;

class Expr_node {
	//Container for various items. Never istantiated (Pure virtual class).
public:
	virtual void interpret() = 0;
	virtual Expr_node* eval() = 0;
};


class Expr: public Expr_node {
	//Expr represents expr non-terminal. Briefly all MZN possible math operations
	int oper;					//operator code
	int nops;					//number of operands
	std::vector<Expr_node*>* op;	//operands

public:
	Expr(int oper, int nops, ...);
	
	Expr_node* getOp_1();
	Expr_node* getOp_2();

	void interpret();
	Expr_node* eval();
};


class ExprList: public Expr_node {
	//ExprList represents expr_list non-terminal and is useful also for array indexing
	std::vector<Expr_node*>* element;

public:
	ExprList();
	ExprList(Expr_node* el);

	void interpret();
	Expr_node* eval();

	void add(Expr_node* el);
	int size();
	Expr_node* at(int index);
	//std::vector<Expr_node*>* getValues();
};


class Literal: public Expr_node {
	//Literal represnts both IDs, (int,bool,float) literals and array IDs with access index
	DOMAIN_TYPE domain;			//domain of literal
	string id;					//ID
	DNumber value;				//VALUE
	ExprList* index;			//indexs to access the array

public:
	Literal(DOMAIN_TYPE d, const char* lit);
	Literal(DOMAIN_TYPE d, string lit);
	Literal(DOMAIN_TYPE d, DNumber lit);

	Literal& operator +(const Literal& other) const;
	Literal& operator -(const Literal & other) const;
	Literal& operator *(const Literal & other) const;
	Literal& operator /(const Literal & other) const;
	Literal& operator <(const Literal & other) const;
	Literal& operator <=(const Literal & other) const;
	Literal& operator >(const Literal & other) const;
	Literal& operator >=(const Literal & other) const;
	Literal& operator ==(const Literal & other) const;
	
	void interpret();
	Expr_node* eval();

	string toString() const;
	DOMAIN_TYPE getDomain() const;
	DNumber getValue() const;
	void addIndex(Expr_node* exp);
};

class Set: public Expr_node {
	DOMAIN_TYPE domain;			//domain of the Set
	IntervalSet* set;

public:
	Set();
	Set(Expr_node* a);
	Set(int oper, Expr_node* a, Expr_node* b);

	IntervalSet* exportRange();
	void interpret();
	Expr_node* eval();

	DOMAIN_TYPE getDomain() const;
	IntervalSet* getSet();
	bool set_in(Literal* value);
	Set* set_union(Set* other);
};

class Comp: public Expr_node {
	std::vector<pair<Literal*,Set*>*>* ids;
	Expr* condition;
	Expr_node* expression;
	ExprList* decompressedExpr;
public:
	Comp(Expr* e);
	void add(Expr_node* e);
	void setCondition(Expr_node* e);
	void setExpression(Expr_node* e);
	void initDecompression();
	void decompress(int index);
	void deleteDecompression();

	void interpret();
	Expr_node* eval();
};

class Fun: public Expr_node {
	//Fun represents call_expr non-terminal
	string id; //function identifier (forall, exist, sum, ...)

	//maybe ExprList args; or vector<Literal*>* args;	//args
	std::vector<pair<Literal*,Set*>*>* ids;
	ExprList* args;				//args
	Expr_node* body;			//body (actually a free-standing parse tree)
	Expr_node* condition;		//example where condition in forall

public:
	Fun(ExprList* e);
	Fun(ExprList* e, Expr_node* c);

	void setBody(Expr_node* b);
	void setReference(string id);
	void assignSet(std::queue<Expr_node*>* id_lit, Expr_node* e);
	void expand_args();

	inline string getID(){return id;};
	inline ExprList* getArgs(){return args;};
	inline Expr_node* getBody(){return body;};
	inline Expr_node* getCondition(){return condition;};
	inline std::vector<pair<Literal*,Set*>*>* getIDS(){return ids;};

	void interpret();
	Expr_node* eval();
};

class Let: public Expr_node {
	//Let represents let_expr non-terminal
	//Hashtable* letMap;			//SymbolTable* let_map
	Expr_node* body;			//body of the let

public:
	void interpret();
	Expr_node* eval();
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
	Expr_node* eval();
};


class Symbol {
	//symbols are initialized in declaration phase and create the symbol table
	ATOM_TYPE type;				//type
	DOMAIN_TYPE domain;			//domain
	TI_TYPE ti_type;			//VAR,PAR,VARSET,PARSET (error-checking purpose)
	
	IntervalSet* range;			//ID domain (INT o FLOAT)

	vector<IntervalSet*>* index;	//array index must be PAR and INT

	string* id;					//ID
	ExprList* value;			//values. if PAR: Literals stored in value[0]\

public:		
	Symbol();
	Symbol(Literal* lit);
	Symbol(DOMAIN_TYPE dom);
	//Symbol(Expr_node* set);
	~Symbol();

	void setRange(DOMAIN_TYPE d, IntervalSet* set);
	inline void setTi_type(TI_TYPE t){ti_type = t;};
	inline void setSymbolType(ATOM_TYPE tp){type = tp;};
	inline void setIdentifier(char* ident){id = new std::string(ident);};
	void setValue(Expr_node* expr);

	inline DOMAIN_TYPE getDomain(){return domain;};
	inline string getID(){return *id;};
	inline TI_TYPE getTi_type(){return ti_type;};
	inline int getIndexSize(){return index->size();};
	inline std::vector<IntervalSet*>* getIndexes(){return index;};

	bool hasValue();
	Expr_node* getValue();
	Expr_node* getValue_at(int i);
	Expr_node* getValue_at(int i, int j);

	void importIndexes(queue<Symbol*>* ind);
	IntervalSet* exportIndex();

	string domain2str();
	string printName(string name,DNumber i,DNumber j,DNumber k);
	void decideName(string name,DNumber i,DNumber j,DNumber k);
	void printRange(string name, bool isArray, DNumber i,DNumber j,DNumber k, IntervalSet* range);
	void printDecl();
};

class HashTable {
	//human readable class for unordered_map usage
    std::unordered_map<std::string, Symbol*> htmap;

public:
	HashTable(){};

    inline void insert(std::string key, Symbol* value) {htmap[key] = value;}

    inline Symbol* get(std::string key) {return htmap[key];}

};//*/

typedef void (*fptr)(Fun*);
class SymbolTable
{
	//Singleton paradigm
    public:
        static SymbolTable & getInstance()
        {
            static SymbolTable instance;			// Guaranteed to be destroyed.
            										// Instantiated on first use.
            return instance;
        }
    private:
        HashTable* globalTable;					//table for global variables
        std::vector<HashTable*>* localTable;	//vector for each local table

        std::vector<std::pair<std::string, fptr>> libr_func;

        //Singleton methods
        SymbolTable();
    
        //SymbolTable(SymbolTable const&);			// Don't Implement
        //void operator=(SymbolTable const&);		// Don't implement

    public:
        SymbolTable(SymbolTable const&) = delete;
        void operator=(SymbolTable const&) = delete;

        //Methods
        void setValue(Symbol* symbol, Expr_node* expr);

        void globalInsert(std::string key, Symbol* value);
        void globalInsert(Symbol* symbol);
        void globalInsert(Symbol* symbol, Expr_node* expr);

        void deleteLocalTable();
        void newLocalTable();
        void localInsert(string key, Symbol* value);

        fptr call_lib_function_interpret(string id);

        Symbol* get(string key);
        string printName(string name,DNumber i,DNumber j,DNumber k);


};

#endif
