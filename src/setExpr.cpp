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

	Interval s = Interval(lb->toString(),ub->toString());
	set = new IntervalSet(s);
}

IntervalSet* Set::exportRange(){
	IntervalSet* tmp = this->set;
	this->set = NULL;
	delete this;
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