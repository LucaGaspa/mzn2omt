/*********************************************************************** 
 * expr.cpp                                                            *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

 
Expr::Expr(char* lit){
	Literal* literal = new Literal(lit);
    Atom* atom = new Atom(literal);
    Item* it = new Item(atom);
    nops = 1;
    this->item = it;
}
Expr::Expr(int n, Item* it){
	this->nops = n;
	this->item = it;
}
Expr::Expr(int n, int o, vector<Expr*>* v){
	this->nops = n;
	this->oper = o;
	this->op = v;
}
Expr::~Expr(){
	if(nops == 1){
		delete item;
	}else{
		//TODO:: forall v in vector -> delete vector[i]
	}
}

Item* Expr::getItem(){return item;}
