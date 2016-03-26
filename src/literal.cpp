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

Literal::Literal(char* lit){
	id = new string(lit);
	index = NULL;
}

void Literal::interpret(){
	std::cout << *id;
	return;
}

//eval --> search in table then ret *id or tableID->val
string Literal::eval(){
	return *id;
}