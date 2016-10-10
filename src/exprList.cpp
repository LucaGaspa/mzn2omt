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

ExprList::ExprList(){
	element = new std::vector<Expr_node*>();
}

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
	//DEBUG PURPOSE
	std::cout << "ExprList printing: DEBUG PURPOSE" << std::endl;
	for (vector<Expr_node*>::iterator it = element->begin(); it != element->end(); it++){
		std::cout << std::endl;
		(*it)->interpret();
		std::cout << std::endl;
	}
	return;
}

Expr_node* ExprList::eval(){
	
	//should be called only when searching a symbol in the symboltable
	//return element->front()->eval();

	if(element->size() == 1){
		return element->front()->eval();
	}else{
		return this;
	}
}