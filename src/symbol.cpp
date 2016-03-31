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
	range = NULL;
}

void Symbol::setRange(Expr_node* set){
	//create IntervalSet* range from set

	//needed in set_expr: conversion from Expr_node*(ARR_INDEX) to Symbol
	//something like:
	this->range = ((Set*)(set))->exportRange();
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
	IntervalSet* tmp = this->range;
	this->range = NULL;
	delete this;
	return tmp;
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
	if(index == NULL){
		std::cout << "(declare-fun "<< *id << " () "<< domain2str() <<" )"<< std::endl;
	}else{
		if(index->size() == 1){
			//iterator di IntervalSet
			//TODO:: here
			std::cout << "(declare-ARRAY "<< *id << " () "<< domain2str() <<" )"<< std::endl;
		}
	}
	//if range != -inf,+inf -> print domain
	//if range != NULL id faster
}



//===================================================================//
//SymbolTable
//===================================================================//


SymbolTable::SymbolTable(){
	return;
}

/*
DOMAIN_TYPE SymbolTable::strDomain(string s){
	if(s.compare("true") == 0 || s.compare("false") == 0){
		return BOOL;
	}
	if((s.find(".") != std::string::npos)){
		return FLOAT;
	}
	return INT;
}

EXPR_DOMAIN SymbolTable::exprDomain(string s, string t){
	if((s.compare("true") == 0 || s.compare("false") == 0) &&
				(t.compare("true") == 0 || t.compare("false") == 0)){
		return BOOLBOOL;
	}
	if((s.find(".") != std::string::npos)){
		if(t.find(".") != std::string::npos){
			return FLOATFLOAT;
		}else{
			return FLOATINT;
		}
	}else{
		if(t.find(".") != std::string::npos){
			return INTFLOAT;
		}else{
			return INTINT;
		}
	}
	return INTINT;
}
*/
