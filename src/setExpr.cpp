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
#include "parser.tab.h"

Set::Set(){
	set = new IntervalSet();
}

Set::Set(Expr_node* a){
	//this->domain = INT;

	// a is an ExprList necessarily due to grammar construction
	// a should be a 1 dimension list (2 dim set has no sense)
	set = new IntervalSet();
	Expr_node* tmp;
	//ExprList used as box for a vector of values
	//to keep logic inside ExprList should implement wrapper for vector
	std::vector<Expr_node*>* v = ((ExprList*)a)->getValues();
	for (vector<Expr_node*>::iterator it = v->begin(); it != v->end(); it++){
		tmp = (*it)->eval();
		this->domain = ((Literal*) tmp)->getDomain();
		set->add(Interval(((Literal*) tmp)->getValue()));
	}
}

Set::Set(int oper, Expr_node* a, Expr_node* b){
	Interval s;

	Expr_node* lb = a->eval();
	Expr_node* ub = b->eval();
	if(((Literal*) lb)->getDomain() == FLOAT || ((Literal*) ub)->getDomain() == FLOAT){
		this->domain = FLOAT;
	}else{
		this->domain = INT;
	}
	switch(oper){
		case MZN_DOTDOT:
		    s = Interval(((Literal*) lb)->getValue(), ((Literal*) ub)->getValue());
			set = new IntervalSet(s);
			break;
		case MZN_UNION:
			*set = ((Set*) lb)->set->set_union(*(((Set*) ub)->getSet()));
			break;
		default:
			break;
	}
}

IntervalSet* Set::exportRange(){
	IntervalSet* tmp = this->set;
	this->set = NULL;
	return tmp;
}

void Set::interpret(){
	std::cout << *set << endl;
	//set->to_str();
	return;
}

Expr_node* Set::eval(){
	return this;
}

DOMAIN_TYPE Set::getDomain() const{
	return domain;
}

IntervalSet* Set::getSet(){
	return set;
}

bool Set::set_in(Literal* value){
	return set->set_in(value->getValue());
}

Set* Set::set_union(Set* other){
	return new Set(MZN_UNION, this, other);
	//return set->set_union((other->getSet());
}
