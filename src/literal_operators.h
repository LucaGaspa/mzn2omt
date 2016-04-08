/*********************************************************************** 
 * literal_operators.cpp                                               *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

Literal& Literal::operator +(const Literal & other) const {
	Literal* res = NULL;
	stringstream tmp;

	//const Literal* op1 = this;
	//const Literal* op2 = &other;

	SymbolTable* table = &SymbolTable::getInstance();
	Literal* op1;
	Literal* op2;

	if(domain == ID){
		Symbol* swapper = table->get(this->toString());
		if(!swapper){
			std::cerr << "plus evaluation error with ID recovering\n";
			exit(0);
		}else{
			op1 = swapper->getValue();
			std::cout << op1->toString() << std::endl;
		}
	}else{
		op1 = new Literal(domain, toString().c_str());
	}

	if(other.getDomain() == ID){
		//TODO::
		//search in table
		//store val | ret NULL	
		//new op2
	}

	switch(domain){
		case INT:
			switch(other.getDomain()){
				case INT:
					tmp << (atoi(toString().c_str()) + atoi(other.toString().c_str()));
					res = new Literal(INT, (tmp.str()).c_str());
					break;
				case FLOAT:
					tmp << (atoi(toString().c_str()) + atof(other.toString().c_str()));
					res = new Literal(INT, (tmp.str()).c_str());
					break;
				case BOOL:
					cerr << "Mmm, nope!  --- literal.cpp" << std::endl;
					//return NULL;
					break;
			}
			break;
		case FLOAT:
			switch(getDomain()){
				case INT:
					tmp << (atof(toString().c_str()) + atoi(other.toString().c_str()));
					res = new Literal(INT, (tmp.str()).c_str());
					break;
				case FLOAT:
					tmp << (atof(toString().c_str()) + atof(other.toString().c_str()));
					res = new Literal(INT, (tmp.str()).c_str());
					break;
				case BOOL:
					cerr << "Mmm, nope!  --- literal.cpp" << std::endl;
					//return NULL;
					break;
			}
			break;
		case BOOL:
			std::cerr << "Are you ok?!  --- literal.cpp" << std::endl;
			//return NULL;
			break;
	}
	return *res;
}