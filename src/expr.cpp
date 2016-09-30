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
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_SUBSET:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_SUPERSET:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_UNION:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_DIFF:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_SYMDIFF:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_DOTDOT:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_DOTDOT_QUOTED:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_INTERSECT:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_PLUSPLUS:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
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
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
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
Expr_node* Expr::eval(){
    Expr_node* op1 = op->at(0)->eval();
    Expr_node* op2 = op->at(1)->eval();
    Expr_node* res;
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
            res = &(*((Literal*)op1) < *((Literal*)op2));
            break;
        case MZN_GR:
            res = &(*((Literal*)op1) > *((Literal*)op2));
            break;
        case MZN_LQ:
            res = &(*((Literal*)op1) <= *((Literal*)op2));
            break;
        case MZN_GQ:
            //res = &(*op1 >= *op2);
            break;
        case MZN_EQ:
            res = &(*((Literal*)op1) == *((Literal*)op2));
            break;
        case MZN_NQ:
            //TODO::
            break;

        case MZN_IN:
            if(((Set*)op2)->set_in((Literal*)op1)){
                res = new Literal(INT,1);
            }else{
                res = new Literal(INT,0);
            }
            break;
        case MZN_SUBSET:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_SUPERSET:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_UNION:
            return ((Set*) op1)->set_union((Set*) op2);
            break;
        case MZN_DIFF:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_SYMDIFF:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_DOTDOT:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_DOTDOT_QUOTED:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_INTERSECT:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;
        case MZN_PLUSPLUS:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;

        case MZN_PLUS:
            res = &(*((Literal*)op1) + *((Literal*)op2));
            break;
        case MZN_MINUS:
            res = &(*((Literal*)op1) - *((Literal*)op2));
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
            std::cerr << "Not supported expr encoding: expr.cpp" << std::endl;
            break;

        case MZN_NOT:
            //res = &(!*op1);
            break;
    }
    return res;
}

Expr_node* Expr::getOp_1(){
    if(nops){
        return op->at(0);
    }else{
        return NULL;
    }
}
Expr_node* Expr::getOp_2(){
    if(nops > 1){
        return op->at(1);
    }else{
        return NULL;
    }
}
/*******************************

    COMPRESSION CLASS

*/
Comp::Comp(Expr* e){
    condition = NULL;
    ids = new std::vector<pair<Literal*,Set*>*>();
    
    Expr_node* op1 = e->getOp_1();
    Expr_node* op2 = e->getOp_2();

    std::vector<Expr_node*>* v = ((ExprList*)op1)->getValues();

    for (vector<Expr_node*>::iterator it = v->begin(); it != v->end(); it++){
        ids->push_back(new pair<Literal*,Set*>((Literal*)(*it), (Set*)op2));
    }
}

void Comp::setCondition(Expr_node* e){
    //TODO::check id e is an Expr or a Literal
    condition = (Expr*)e;
}

void Comp::setExpression(Expr_node* e){
    expression = e;
}

void Comp::add(Expr_node* e){
    //TODO::check if e is an Expr or a literal
    Expr_node* op1 = ((Expr*)e)->getOp_1();
    Expr_node* op2 = ((Expr*)e)->getOp_2();

    std::vector<Expr_node*>* v = ((ExprList*)op1)->getValues();

    for (vector<Expr_node*>::iterator it = v->begin(); it != v->end(); it++){
        ids->push_back(new pair<Literal*,Set*>((Literal*)(*it), (Set*)op2));
    }
}

Expr_node* Comp::eval(){
    /* TODO:: 
        case MZN_WHERE:
        // generator_list where exrp
        // list of (list of IDs MZN_IN (presumably) Set) (MZN_WHERE expr | **empty**)
        // i.e.: i,j IN 1..3, k IN 1..4 WHERE i<k
        /*
        create new local table.
        cycle each ID over the set changing its local value at each iter
        check that each local id value correspond to the WHERE condition

        needs a separate funciont: expr->evalConditioned(expr, comp_tail)
        get list of id with domains
        get condition
        set environment
        start ciclying
    return list of values. (that will become a Set)
    */


    //vector di pair di Literal con set su cui deve ciclare

    /*
    1 - creare tabella locale
    2 - caricare ids
    3 - per ogni pair ciclare sui possibili valori (innestandoli)
    4 - se condition è true valutare la combinazione di valori (expression->eval())
    5 - aggiungere expression->eval() alla ExprList da ritornare
    */

}

void Comp::interpret(){}