/*********************************************************************** 
 * calc.h                                                              *
 *                                                                     *
 * Copyright (C) 2015 Luca Gasparetto                                  *
 * All rights reserved.                                                *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

enum Expr_type {ATOM, EXPR, FUN};
enum ID_type {VAR, PAR, SET};
enum VP_type {DIM_1, DIM_2, DIM_3};
enum Lit_type {INT, FLOAT, BOOL};


class Expr_node;	

class binSet {
	int setDim;
	int* values;
};

class uValue {
	Lit_type type;
	union{
		int iValue;
		float fValue;
		bool bValue;
	};
};

class Atom {
	ID_type type;
	char* name;
	VP_type dim;
	union{
		uValue* value;
		binSet* set;
	};
};

class Expr {
	int oper;
	int nops;
	Expr_node** op;
};

class Func {
	//body
	int body; //tmp var
};

class Expr_node {
	Expr_type type;
	union{
		Atom atom;
		Expr expr;
		Func func;
	};
};


