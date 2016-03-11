/*********************************************************************** 
 * atom.cpp                                                            *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"


Atom::Atom(Array* arr){
	type = ARR;
	array = arr;
}
Atom::Atom(IntIntervalSet* s){
	type = SET;
	set = s;
}
Atom::Atom(Literal* lit){
	type = LIT;
	literal = lit;
}
Atom::~Atom(){
	switch(type){
		case ARR:
			delete array;
			break;
		case SET:
			delete set;
			break;
		case LIT:
			delete literal;
			break;
	}
}

Literal* Atom::getLiteral(){return literal;}
