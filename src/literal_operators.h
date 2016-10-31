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
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value + other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator -(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value - other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator <(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value < other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator <=(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value <= other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator >(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value > other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator >=(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value >= other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator ==(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value == other.getValue();
	return *(new Literal(d, tmp));
}

// NOT YET SUPPORTED in DNumber -> TODO:: TEST PLZ
Literal& Literal::operator *(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value * other.getValue();
	return *(new Literal(d, tmp));
}

Literal& Literal::operator /(const Literal & other) const {
	DOMAIN_TYPE d;
	if(domain == FLOAT || other.getDomain() == FLOAT){
		d = FLOAT;
	}else{
		d = INT;
	}

	DNumber tmp = value / other.getValue();
	return *(new Literal(d, tmp));
}
//****************************************************************/