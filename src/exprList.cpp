/*********************************************************************** 
 * exprList.cpp                                                        *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

ExprList::ExprList(Expr_node* el){
	element = new std::vector<Expr_node*>();
	element->push_back(el);
}

void ExprList::add(Expr_node* el){
	element->push_back(el);
}

std::vector<Expr_node*>* ExprList::getValues(){
	return element;
}

void ExprList::interpret(){
	//TODO::
	//this should never happen!
	std::cerr << "Hey dude, this should never happen :/" << std::endl;
	return;
}

Expr_node* ExprList::eval(){
	//cerr << "Hey dude, this should never happen : exprList.cpp";
	
	//should be called only when searching a symbol in the symboltable
	return element->front()->eval();
}