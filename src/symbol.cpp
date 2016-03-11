/*********************************************************************** 
 * symbol.cpp                                                          *
 *                                                                     *
 * 2015 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

Symbol::Symbol(DOMAIN_TYPE dom){
	domain = dom;
	//TODO:: settare il range al massimo dei valori consentiti "(-inf,+inf)"
}

Symbol::Symbol(Expr* s){
	set = s;
}

void Symbol::setTi_type(TI_TYPE t){
	ti_type = t;
}

void Symbol::setSymbolType(ATOM_TYPE tp){
	type = tp;
}