/*********************************************************************** 
 * item.cpp                                                            *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

Item::Item(Atom* at){
	type = ATM;
	atom = at;
}
Item::Item(Fun* f){
	type = FUN;
	fun = f;
}
Item::Item(Let* l){
	type = LET;
	let = l;
}
Item::Item(Ite* i){
	type = ITE;
	ite = i;
}
Item::~Item(){
	switch(type){
		case ATM:
			delete atom;
			break;
		case FUN:
			delete fun;
			break;
		case LET:
			delete let;
			break;
		case ITE:
			delete ite;
			break;	
	}
}

Atom* Item::getAtom(){return atom;}
