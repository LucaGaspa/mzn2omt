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

//interpret -> prints the parsed tree
void Expr::interpret(){
    Literal* cond = NULL;
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
            std::cerr << "Not supported expr encoding: expr.cpp 1" << std::endl;
            break;
        case MZN_SUBSET:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 2" << std::endl;
            break;
        case MZN_SUPERSET:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 3" << std::endl;
            break;
        case MZN_UNION:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 4" << std::endl;
            break;
        case MZN_DIFF:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 5" << std::endl;
            break;
        case MZN_SYMDIFF:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 6" << std::endl;
            break;
        case MZN_DOTDOT:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 7" << std::endl;
            break;
        case MZN_DOTDOT_QUOTED:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 8" << std::endl;
            break;
        case MZN_INTERSECT:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 9" << std::endl;
            break;
        case MZN_PLUSPLUS:
            //TODO:: choose an encoding
            std::cerr << "Not supported expr encoding: expr.cpp 10" << std::endl;
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
            std::cerr << "Not supported expr encoding: expr.cpp 11" << std::endl;
            break;

        case MZN_NOT:
            std::cout << "(not ";
            op->at(0)->interpret();
            std::cout << ")";
            break;
        case MZN_IF:
            cond = (Literal*) op->at(0)->eval();
            if(cond->getDomain() != ID){
                //just print right branch
                if(cond->getValue()){
                    op->at(1)->interpret();
                }else{
                    op->at(2)->interpret();
                }
            }else{
                std::cout << "(and (=> ";
                op->at(0)->interpret();
                std::cout << " ";
                op->at(1)->interpret();
                std::cout << ") (=> (not ";
                op->at(0)->interpret();
                std::cout << ") ";
                op->at(2)->interpret();
                std::cout << "))";
            }
            break;
        default:
            std::cerr << "Not supported expr encoding: expr.cpp 12 :: default" << std::endl;
            break;
    }
    return;
}

//eval -> tries to calculate the value of the parsed tree
Expr_node* Expr::eval(){
    Expr_node* op1 = op->at(0)->eval();
    Expr_node* op2 = op->at(1)->eval();
    Expr_node* res;
    if( ((Literal*) op1)->getDomain() == ID || ((Literal*) op1)->getDomain() == ID ){
        res = new Literal(ID,"Bad Eval");
        return res;
    }
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
            res = &(*((Literal*)op1) >= *((Literal*)op2));
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
            res = new Set(MZN_DOTDOT,op1,op2);
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
            res = &(*((Literal*)op1) * *((Literal*)op2));
            break;
        case MZN_DIV:
            res = &(*((Literal*)op1) / *((Literal*)op2));
            break;
        case MZN_IDIV:
            //res = &(*((Literal*)op1) / *((Literal*)op2));
            break;
        case MZN_MOD:
            //res = &(*((Literal*)op1) % *((Literal*)op2));
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
    if(nops > 0){
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
    
    ExprList* op1 = (ExprList*) ((Expr*) e)->getOp_1();
    Expr_node* op2 = ((Expr*) e)->getOp_2();
    op2 = op2->eval();

    for(int i=0; i < op1->size(); i++){
        ids->push_back(new pair<Literal*,Set*>((Literal*)(op1->at(i)), (Set*)op2));
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
    ExprList* op1 = (ExprList*) ((Expr*) e)->getOp_1();
    Expr_node* op2 = ((Expr*) e)->getOp_2();
    op2 = op2->eval(); //TODO:: Memory leak??

    for(int i=0; i < op1->size(); i++){
        ids->push_back(new pair<Literal*,Set*>((Literal*)(op1->at(i)), (Set*)op2));
    }
}

Expr_node* Comp::eval(){
    this->decompressedExpr = new ExprList();

    this->initDecompression();
    this->decompress(0);
    this->deleteDecompression();

    return this->decompressedExpr;
}

void Comp::deleteDecompression(){
    SymbolTable::getInstance().deleteLocalTable();
}

void Comp::initDecompression(){
    SymbolTable::getInstance().newLocalTable();
    for (vector<pair<Literal*,Set*>*>::iterator it = ids->begin(); it != ids->end(); it++){
        SymbolTable::getInstance().localInsert((*it)->first->getID(), new Symbol((*it)->first));
    }
}

void Comp::decompress(int index){
    if(index >= this->ids->size()){
        if(condition){
            if(((Literal*)condition->eval())->getValue()){
                this->decompressedExpr->add(this->expression->eval());
            }
        }else{
            this->decompressedExpr->add(this->expression->eval());
        }
    }else{
        IntervalSet* range = ((this->ids->at(index))->second)->getSet();
        for (IntervalSet::value_iterator it = range->value_begin(),
                        end = range->value_end(); it != end; ++it) {
            SymbolTable::getInstance().localInsert((
                        this->ids->at(index))->first->getID(),
                        new Symbol(
                            new Literal(
                                        ((this->ids->at(index))->second)->getDomain(),
                                        *it)
                            )
                        );
        this->decompress(index+1);
        }
    }
}

void Comp::interpret(){}

/*******************************

   FUN CLASS

*/

Fun::Fun(ExprList* e){
    args = e;
    condition = NULL;
    body = NULL;
    ids = NULL;
}

Fun::Fun(ExprList* e, Expr_node* c){
    args = e;
    condition = c;
    body = NULL;
    ids = NULL;
}

void Fun::assignSet(std::queue<Expr_node*>* id_lit, Expr_node* e){
    if(!ids){
        ids = new std::vector<pair<Literal*,Set*>*>();
    }
    Expr_node* tmp;
    Set* s = (Set*) e;//->eval();
    
    while(!id_lit->empty()){
        tmp = id_lit->front();
        id_lit->pop();
        ids->push_back(new pair<Literal*,Set*>((Literal*)(tmp), s));    
    }
}

void Fun::expand_args(){
    std::queue<Expr_node*>* id_lit = new std::queue<Expr_node*>();
    for (int i = 0; i < args->size(); ++i)
    {
        if(dynamic_cast<Expr*>(args->at(i))){
            Expr* e = (Expr*) args->at(i);
            id_lit->push(e->getOp_1());
            Expr_node* toAssign =  e->getOp_2();
            if( ! dynamic_cast<Set*>(toAssign) ){
                

                toAssign =  toAssign->eval();
                if( ! dynamic_cast<Set*>( toAssign ) ){
                    cerr << "ERROR ASSIGNING SET" << endl;
                }
            }
            assignSet(id_lit, toAssign);
        }else{
            id_lit->push(args->at(i)); 
        }
    }
    delete id_lit;
}

void Fun::setBody(Expr_node* b){
    body = b;
    expand_args();
}

void Fun::setReference(string id){
    this->id = id;
}

void Fun::interpret(){
    fptr f = SymbolTable::getInstance().call_lib_function_interpret(id);
    if(f){
        f(this);
    }
}
Expr_node* Fun::eval(){
    return NULL;
}

/* LET EXPR */

Let::Let(std::queue<Symbol*>* q, Expr_node* b){
    local_ids = q;
    body = b;
}

Expr_node* Let::eval(){}

void Let::interpret(){
    SymbolTable* s = & SymbolTable::getInstance();
    s->newLocalTable();

    std::queue<Symbol*>* ids_buffer = new std::queue<Symbol*>();
    Symbol* tmp;
    while(!local_ids->empty()){
        tmp = local_ids->front();
        local_ids->pop();
        ids_buffer->push(tmp);

        if(! tmp->hasValue()){
            //FRESH VARS -> declare with new name -> assign new name as val :D (became a wrapper)
            Symbol* mySym = tmp;
            string old_name = mySym->getID();
            Literal* wrap_value = new Literal(ID, old_name+"@_wrap_@");
            mySym->setID(wrap_value->getID());
            mySym->printDecl(true,NULL);
            mySym->setID(old_name);
            mySym->setValue(wrap_value);
        } //else :: VARS assigned with old values -> no need to declare, just a wrapper

        s->localInsert(tmp->getID(), tmp);
    }
    
    body->interpret();
    delete local_ids;
    //saving the queue again in the obj for future iterations
    local_ids = ids_buffer;
    s->deleteLocalTable();
}
