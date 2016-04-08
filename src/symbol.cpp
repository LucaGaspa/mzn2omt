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
	value = NULL;
}

Symbol::~Symbol(){
	//TODO::
	return;
}

void Symbol::setRange(Expr_node* set){
	//create IntervalSet* range from set

	//needed in set_expr: conversion from Expr_node*(ARR_INDEX) to Symbol
	//something like:
	this->range = ((Set*)(set))->exportRange();
}

void Symbol::setValue(Expr_node* expr){
	if(dynamic_cast<ExprList*>(expr)){
		value = (ExprList*)expr;
	}else{
		value = new ExprList(expr);
	}
}

Literal* Symbol::getValue(){
	if(value != NULL){
		return value->eval();
	}else{
		return new Literal(domain, id->c_str());
	}
	
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
	globalTable = new HashTable();
	localTable = new std::vector<HashTable*>();
}

void SymbolTable::setValue(Symbol* symbol, Expr_node* expr){
	globalTable->get(symbol->getID())->setValue(expr);
}

void SymbolTable::globalInsert(std::string key, Symbol* value){
	globalTable->insert(key, value);
}

void SymbolTable::globalInsert(Symbol* symbol){
	globalTable->insert(symbol->getID(), symbol);	
}

Symbol* SymbolTable::get(std::string key){
	//TODO:: consider local environments
	return globalTable->get(key);
}