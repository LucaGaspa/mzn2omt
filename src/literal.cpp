/*********************************************************************** 
 * literal.cpp                                                         *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

#include "literal_operators.h"

Literal::Literal(DOMAIN_TYPE d, const char* lit){
	domain = d;
	id = new string(lit);
	index = NULL;
}

void Literal::interpret(){
	std::cout << *id;
	return;
}

//eval --> search in table then ret *id or tableID->val
Literal* Literal::eval(){
	return this;
}

DOMAIN_TYPE Literal::getDomain() const{
	return domain;
}
string Literal::toString() const{
	return *id;
}