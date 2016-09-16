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

string Symbol::printName(string name,DNumber i,DNumber j,DNumber k){
    return name + "__" + i.to_str() + "__" + j.to_str() + "__" + k.to_str();
}

void Symbol::decideName(string name,DNumber i,DNumber j,DNumber k){
    std::cout << "(declare-fun "<< printName(name,i,j,k) << " () "<< domain2str() <<" )"<< std::endl;
}

void Symbol::printRange(string name,DNumber i,DNumber j,DNumber k, IntervalSet* range){
    if(range != NULL){
        std::cout << "(assert (or ";
        //optimization: if(not fragmented): NO 'or' AND NO 'for' needed
        for (IntervalSet::subset_iterator it = (*range).subset_begin(), end = (*range).subset_end();
            it != end; ++it) {
            std::cout << "(and  (>= " << printName(name,i,0,0) << " " << it->lower().to_str() <<") (<= "<< printName(name,i,0,0) << " " << it->upper().to_str() <<")) ";
        }
        std::cout << "))" << endl;
    }else{
        //limit on MiniZinc entire domain. TODO:: put a MACRO instead of number
        std::cout << "(assert (and  (>= "<< printName(name,i,0,0) << " (- 0 10000000)) (<= "<< printName(name,i,0,0) << " 10000000)))" << endl;
    }
}

void Symbol::printDecl(){
    if(ti_type == PAR || ti_type == SETPAR){
        return;
    }

    if(index == NULL){
        std::cout << "(declare-fun "<< *id << " () "<< domain2str() <<" )"<< std::endl;
    }else{
        switch(this->index->size()){
            case 1:
                //TODO:: think about fragmented index intervals: maybe if(isFragmented){ret ERROR} ??
                for (IntervalSet::value_iterator it = ((*index)[0])->value_begin(), end = ((*index)[0])->value_end(); it != end; ++it) {
                    decideName(*id,*it,0,0);
                    printRange(*id,*it,0,0,range);
                }
                break;
            case 2:
                //TODO:: think about fragmented index intervals: maybe if(isFragmented){ret ERROR} ??
                for (IntervalSet::value_iterator it = ((*index)[0])->value_begin(), end_1 = ((*index)[0])->value_end();
            it != end_1; ++it) {
                    for (IntervalSet::value_iterator itt = ((*index)[1])->value_begin(), end_2 = ((*index)[1])->value_end();
            itt != end_2; ++itt) {
                        decideName(*id,*it,*itt,0);
                        printRange(*id,*it,0,0,range);
                    }
                }
                break;
            case 3:
                //TODO:: raise NotImplemented
                break;
            default:
                std::cerr << "printDecl invalid index dimension" << endl;
                break;
        }
    }
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

void SymbolTable::globalInsert(Symbol* symbol, Expr_node* expr){
    symbol->setValue(expr);
    globalTable->insert(symbol->getID(), symbol);
}

Symbol* SymbolTable::get(std::string key){
    //TODO:: consider local environments
    return globalTable->get(key);
}