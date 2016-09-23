/*********************************************************************** 
 * setExpr.cpp                                                         *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

Set::Set(){
	set = new IntervalSet();
}

Set::Set(Expr_node* a){
	// a is an ExprList necessarily due to grammar construction
	// a should be a 1 dimension list (2 dim set has no sense)
	set = new IntervalSet();
	Literal* tmp;
	//ExprList used as box for a vector of values
	//to keep logic inside ExprList should implement wrapper for vector
	std::vector<Expr_node*>* v = ((ExprList*)a)->getValues();
	for (vector<Expr_node*>::iterator it = v->begin(); it != v->end(); it++){
		tmp = (*it)->eval();
		set->add(Interval(tmp->getValue()));
	}
}

Set::Set(Expr_node* a, Expr_node* b){
	Literal* lb = a->eval();
	Literal* ub = b->eval();

	if(lb->getDomain() == FLOAT || ub->getDomain() == FLOAT){
		this->domain = FLOAT;
	}else{
		this->domain = INT;
	}

    Interval s = Interval(lb->getValue(), ub->getValue());
	set = new IntervalSet(s);
}

/*
Set::Set(int oper, Expr_node* a, Expr_node* b){
	switch(oper){
		case MZN_UNION:
			break;
		default:
			break;
	}
}
*/

IntervalSet* Set::exportRange(){
	IntervalSet* tmp = this->set;
	this->set = NULL;
	return tmp;
}

void Set::interpret(){
	std::cout << *set << endl;
	return;
}

Literal* Set::eval(){
	std::cerr << "Wrong way: SetExpr.cpp" << std::endl;
	return NULL;
}

DOMAIN_TYPE Set::getDomain() const{
	return domain;
}
