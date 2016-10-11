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
	string name = this->id;
	DNumber i = DNumber(0);
	DNumber j = DNumber(0);
	DNumber k = DNumber(0);
	std::vector<Expr_node*>* v;

	if(index){
		v = index->getValues();
		switch(v->size()){
			case 3:
				k = ((Literal*) v->at(2)->eval())->getValue();
			case 2:
				j = ((Literal*) v->at(1)->eval())->getValue(); 
			case 1:
				i = ((Literal*) v->at(0)->eval())->getValue();
		}
		name = SymbolTable::getInstance().printName(name, i, j, k);
	}

	if(domain == ID){
		Symbol* sym = SymbolTable::getInstance().get(this->id);
		if(sym != NULL){
			if(index != NULL){
				Expr_node* tmp = sym->getValue();
				if(tmp){
					std::vector<Expr_node*>* val = ((ExprList*) tmp)->getValues();
					//TODO:: 3d arrays??
					if(v->size() == 1){
						int index = atoi(i.to_str().c_str());
						val->at(index)->interpret();
					}else{
						int index_1 = atoi(i.to_str().c_str());
						int index_2 = atoi(j.to_str().c_str());
						ExprList* row = (ExprList*) ((ExprList*) tmp)->at(index_1);
						ExprList* col = (ExprList*) row->at(0);
						Expr_node* el = col->at(index_2);
						el->interpret();
					}
				}else{
					std::cout << name;
				}
			}else{
				Literal* tmp = (Literal*)((Literal*) sym->getValue())->eval();
				std::cout << tmp->toString();
			}
		}else{
			std::cout << name;
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
			return tmp->getValue()->eval();
		}else{
			std::cerr << "id: " << this->id << std::endl;
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

void Literal::addIndex(Expr_node* exp){
	if(!index){
		index = (ExprList*) exp;
	}else{
		index->add(exp);
	}
}

string Literal::toString() const{
	if(domain == ID){
		return id;
	}else{
		return value.to_str();
	}
}