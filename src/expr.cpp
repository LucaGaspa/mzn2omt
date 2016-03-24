/*********************************************************************** 
 * expr.cpp                                                            *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"
#include "parser.tab.h"

Expr::Expr(int oper, int nops, ...){
	this->oper = oper;
	this->nops = nops;
	va_list ap;
    va_start(ap, nops);
    op = new std::vector<Expr_node*>();
    for(int i = 0; i < nops; i++) {
        op->push_back(va_arg(ap, Expr_node*));
    }
    va_end(ap);
}

void Expr::interpret(){
	//op->front()->interpret();
	//fat switch
	switch(oper){
		case MZN_EQUIV:
			break;
		case MZN_IMPL:
			break;
		case MZN_RIMPL:
			break;
		case MZN_OR:
			break;

		case MZN_PLUS:
			op->front()->interpret();
			break;
	}
	return;
}