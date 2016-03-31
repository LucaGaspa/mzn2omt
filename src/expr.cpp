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
	//fat switch
	switch(oper){
		case MZN_EQUIV:
			std::cout << "(= ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_IMPL:
			std::cout << "(=> ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_RIMPL:
			std::cout << "(=> ";
			op->at(1)->interpret();
			std::cout << " ";
			op->at(0)->interpret();
			std::cout << ")";
			break;
		case MZN_OR:
			std::cout << "(or ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_XOR:
			std::cout << "(xor ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_AND:
			std::cout << "(and ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_LE:
			std::cout << "(< ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_GR:
			std::cout << "(> ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_LQ:
			std::cout << "(<= ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_GQ:
			std::cout << "(>= ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_EQ:
			std::cout << "(= ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_NQ:
			std::cout << "(distinct ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;

		case MZN_IN:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_SUBSET:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_SUPERSET:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_UNION:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_DIFF:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_SYMDIFF:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_DOTDOT:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_DOTDOT_QUOTED:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_INTERSECT:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_PLUSPLUS:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;

		case MZN_PLUS:
			std::cout << "(+ ";
			op->at(0)->interpret();
			std::cout << " ";
			if(nops == 1){
				std::cout << "0";
			}else{
				op->at(1)->interpret();	
			}
			std::cout << ")";
			break;
		case MZN_MINUS:
			std::cout << "(- ";
			op->at(0)->interpret();
			std::cout << " ";
			if(nops == 1){
				std::cout << "0";
			}else{
				op->at(1)->interpret();	
			}
			std::cout << ")";
			break;
		case MZN_MULT:
			std::cout << "(* ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_DIV:
			std::cout << "(/ ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_IDIV:
			std::cout << "(/ ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;
		case MZN_MOD:
			std::cout << "(mod ";
			op->at(0)->interpret();
			std::cout << " ";
			op->at(1)->interpret();
			std::cout << ")";
			break;

		case MZN_QUOTED_IDENTIFIER:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;

		case MZN_NOT:
			std::cout << "(not ";
			op->at(0)->interpret();
			std::cout << ")";
			break;
	}
	return;
}

//eval -> elaborate values and return their strval
Literal* Expr::eval(){
	Literal* op1 = op->at(0)->eval();
	Literal* op2 = op->at(1)->eval();
	Literal* res;
	switch(oper){
		case MZN_EQUIV:
			
			break;
		case MZN_IMPL:
			
			break;
		case MZN_RIMPL:
			
			break;
		case MZN_OR:
			
			break;
		case MZN_XOR:
			
			break;
		case MZN_AND:
			
			break;
		case MZN_LE:
			
			break;
		case MZN_GR:
			
			break;
		case MZN_LQ:
			
			break;
		case MZN_GQ:
			
			break;
		case MZN_EQ:
			
			break;
		case MZN_NQ:
			
			break;

		case MZN_IN:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_SUBSET:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_SUPERSET:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_UNION:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_DIFF:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_SYMDIFF:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_DOTDOT:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_DOTDOT_QUOTED:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_INTERSECT:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;
		case MZN_PLUSPLUS:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;

		case MZN_PLUS:
			res = &(*op1 + *op2);
			break;
		case MZN_MINUS:
			//res = &(*op1 - *op2);
			break;
		case MZN_MULT:
			//res = &(*op1 * *op2);
			break;
		case MZN_DIV:
			//res = &(*op1 / *op2);
			break;
		case MZN_IDIV:
			//res = &(*op1 / *op2);
			break;
		case MZN_MOD:
			//res = &(*op1 % *op2);
			break;

		case MZN_QUOTED_IDENTIFIER:
			//TODO:: choose an encoding
			std::cerr << "Not supported expr encoding: expr.cpp";
			break;

		case MZN_NOT:
			//res = &(!*op1);
			break;
	}
	return res;
}