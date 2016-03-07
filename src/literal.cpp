/*********************************************************************** 
 * literal.cpp                                                         *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"


//Literal::Literal(char* lit) : id(lit) { }
Literal::Literal(char* lit){
	id = new string(lit);
}

Literal::~Literal(){
	//id.clear();
	id->clear();
}

string Literal::getID(){
	return *id;
	}