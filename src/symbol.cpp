/*********************************************************************** 
 * symbol.cpp                                                          *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

Symbol::Symbol(DOMAIN_TYPE dom){
	domain = dom;
	//TODO:: settare il range al massimo dei valori consentiti "(-inf,+inf)" o (-10kk, 10kk)
	//range = new IntervalSet(-inf,+inf);
	index = NULL;
}

Symbol::Symbol(Expr_node* set){
	//create IntervalSet* range from set

	//needed in set_expr: conversion from Expr_node*(ARR_INDEX) to Symbol
	//something like:
	//range = this->Expr_nodeToSet(set)
	//which domain?? INT or FLOAT??? --> try if(string.find('.')){domain = FLOAT}
}

Symbol::~Symbol(){
	//TODO::
	return;
}

void Symbol::setTi_type(TI_TYPE t){
	ti_type = t;
}

void Symbol::setSymbolType(ATOM_TYPE tp){
	type = tp;
}

void Symbol::setIdentifier(char* ident){
	id = new std::string(ident);
}

void Symbol::importIndexes(std::queue<Symbol*>* list){
	if(!index){
		index = new std::vector<IntervalSet*>();
	}
	Symbol* tmp;
	while(!list->empty()){
		tmp = list->front();
		list->pop();

		index->push_back(tmp->exportIndex());

	}
}

IntervalSet* Symbol::exportIndex(){
	if(this->index->size() == 1){
		IntervalSet* tmp = this->index->front();
		this->index = NULL;
		delete this;
		return tmp;	
	}else{
		std::cerr << "export single index, but there are more than one :(" << std::endl;
	}
	
}

string Symbol::domain2str(){
	switch(domain){
		case INT:
			return "Int";
			break;
		case BOOL:
			return "Bool";
			break;
		case FLOAT:
			return "Real";
			break;
	}
}

void Symbol::printDecl(){
	std::cout << "(declare-fun "<< *id << " () "<< domain2str() <<" )"<< std::endl;
	//if range != -inf,+inf -> print domain
}