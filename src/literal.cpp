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
	}else{
		value = DNumber(lit);
	}
	index = NULL;
}

void Literal::interpret(){
	if(domain == ID){
		Symbol* sym = SymbolTable::getInstance().get(this->id);
		if(sym != NULL){
			Literal* tmp = sym->getValue();
			std::cout << tmp->toString();
		}else{
			std::cout << id;
		}
	}else{
		std::cout << value.mpq_to_str();
	}
}

Literal* Literal::eval(){
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
		return value.mpq_to_str();
	}
}