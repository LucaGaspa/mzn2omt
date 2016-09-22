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

Set::Set(Expr_node* a, Expr_node* b){
	Literal* lb = a->eval();
	Literal* ub = b->eval();

	if(lb->getDomain() == FLOAT || ub->getDomain() == FLOAT){
		this->domain = FLOAT;
	}else{
		this->domain = INT;
	}

    //std::string lb_repr = lb->toString();
    //std::string ub_repr = ub->toString();

    //DNumber lb_num = DNumber(lb_repr);
    //DNumber ub_num = DNumber(ub_repr);

	Interval s = Interval(lb->getValue(), ub->getValue());
	set = new IntervalSet(s);
}

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
