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
	if(domain == ID){
		id = string(lit);
		value = DNumber("0");
	}else{
		id = "NULL";
		string tmp = lit;
		value = DNumber(tmp);
	}
	index = NULL;
}

Literal::Literal(DOMAIN_TYPE d, string lit){
	domain = d;
	if(domain == ID){
		id = lit;
		value = DNumber("0");
	}else{
		id = "NULL";
		value = DNumber(lit);
	}
	index = NULL;
}

Literal::Literal(DOMAIN_TYPE d, DNumber lit){
	domain = d;
	value = lit;
	index = NULL;
}

void Literal::interpret(){
	//TODO:: if(index != NULL) --> return printName();
	if(domain == ID){
		Symbol* sym = SymbolTable::getInstance().get(this->id);
		if(sym != NULL){
			Literal* tmp = (Literal*) sym->getValue();
			std::cout << tmp->toString();
		}else{
			std::cout << id;
		}
	}else{
		std::cout << value.to_str();
	}
}

Expr_node* Literal::eval(){
	//TODO:: if(index != NULL) --> return SymbolTable::getInstance().get(printName(id));
	if(domain == ID){
		Symbol* tmp = SymbolTable::getInstance().get(this->id);
		if(tmp != NULL){
			return tmp->getValue();
		}else{
			std::cerr << "LITERAL EVAL ERROR -- literal.cpp" << std::endl;
		}
	}
	return this;
}

DOMAIN_TYPE Literal::getDomain() const{
	return domain;
}

DNumber Literal::getValue() const{
	return value;
}

string Literal::toString() const{
	if(domain == ID){
		return id;
	}else{
		return value.to_str();
	}
}