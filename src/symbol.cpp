/*********************************************************************** 
 * symbol.cpp                                                          *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

#include "calc.h"

Symbol::Symbol(DOMAIN_TYPE dom){
    domain = dom;
    index = NULL;
    range = new IntervalSet(Interval(DNumber::minus_inf, DNumber::plus_inf));
    value = NULL;
}

Symbol::Symbol(){
    domain = ID;
    index = NULL;
    range = new IntervalSet(Interval(DNumber::minus_inf, DNumber::plus_inf));
    value = NULL;
    return;
}

Symbol::Symbol(Literal* lit){
    type = LIT;
    domain = lit->getDomain();
    if(domain == ID){
        id = new string(lit->toString());    
    }else{
        setValue(lit);
    }
    index = NULL;
    range = new IntervalSet(Interval(DNumber::minus_inf, DNumber::plus_inf));
}

Symbol::~Symbol(){
    //TODO::
    return;
}

void Symbol::setRange(DOMAIN_TYPE d, IntervalSet* set){
    //create IntervalSet* range from set

    this->domain = d;

    if (this->range) {
        delete range;
    }
    this->range = set;
}

void Symbol::setID(string new_id){
    if(id){
        delete id;
    }
    id = new std::string(new_id);
}

void Symbol::setValue(Expr_node* expr){
    if(dynamic_cast<ExprList*>(expr)){
        value = (ExprList*)expr;
    }else{
        value = new ExprList(expr);
    }
}

Expr_node* Symbol::getValue(){
    if(value != NULL){
        return value;
    }else{
        //return new Literal(domain, id->c_str());
        return NULL;
    }
}

bool Symbol::hasValue(){
    if(value != NULL){
        return true;
    }else{
        return false;
    }
}

Expr_node* Symbol::getValue_at(int i){
    if(value){
        if(!index){
            std::cout << "BAD SYMBOL ACCESS 1D" << std::endl;
            return NULL;
        }
        return value->at(i - atoi(index->at(0)->lower().to_str().c_str()));
    }else{
        return NULL;
    }
}

Expr_node* Symbol::getValue_at(int i, int j){
    if(value){
        if(!index){
            std::cout << "BAD SYMBOL ACCESS 2D" << std::endl;
            return NULL;
        }
        ExprList* tmp = (ExprList*) value->at(i - atoi(index->at(0)->lower().to_str().c_str()));
        ExprList* tmp_i = (ExprList*) tmp->at(0); //??Parser initialize too many innested ExprList??
        return tmp_i->at(j - atoi(index->at(1)->lower().to_str().c_str()));
    }else{
        return NULL;
    }
}

void Symbol::importIndexes(std::queue<Symbol*>* list){
    if(!index){
        index = new std::vector<IntervalSet*>();
    }
    Symbol* tmp;
    while(!list->empty()){
        tmp = list->front();
        list->pop();

        index->push_back(tmp->exportIndex());
        delete tmp;
    }
}

IntervalSet* Symbol::exportIndex(){
    IntervalSet* tmp = this->range;
    this->range = NULL; // TODO: memory leak?
    return tmp;
}

string Symbol::domain2str(){
    switch(domain){
        case INT:
            return "Int";
            break;
        case BOOL:
            return "Bool";
            break;
        case FLOAT:
            return "Real";
            break;
        default:
            return "Invalid DOMAIN";
            break;
    }
}

string Symbol::printName(string name,DNumber i,DNumber j,DNumber k){
    return name + "__" + i.to_str() + "__" + j.to_str() + "__" + k.to_str();
}

void Symbol::decideName(string name,DNumber i,DNumber j,DNumber k){
    std::cout << "(declare-fun "<< printName(name,i,j,k) << " () "<< domain2str() <<" )"<< std::endl;
}

void Symbol::printRange(string name, bool isArray, DNumber i,DNumber j,DNumber k, IntervalSet* range){
    if(! isArray){
        std::cout << "(assert (and (<= "
                  << range->lower().to_str() << " "
                  << name << ") (<= " << name << " "
                  << range->upper().to_str() << ")))"
                  << std::endl;
    } else {
        // EDIT: stronger, can be more effective for smt2 theory solvers
        std::cout << "(assert (and (<= "
                  << range->lower().to_str() << " "
                  << printName(name, i, j, k) << ") (<= " << printName(name, i, j, k) << " "
                  << range->upper().to_str() << ")))" << std::endl;
        if(range->is_fragmented()){
            std::cout << "(assert (or ";
            for (IntervalSet::subset_iterator it = range->subset_begin(),
                    end = range->subset_end(); it != end; ++it) {
                std::cout << "(and  (<= "
                          << it->lower().to_str() << " "
                          << printName(name, i, j, k) << ") (<= "<< printName(name, i, j, k) << " "
                          << it->upper().to_str()
                          <<")) ";
            }
            std::cout << "))" << endl;
        }
    }
}

void Symbol::printDecl(){
    if(ti_type == PAR || ti_type == SETPAR){
        return;
    }

    if(index == NULL){
        std::cout << "(declare-fun "<< *id << " () "<< domain2str() <<" )"<< std::endl;
        printRange(*id,false,0,0,0,range);
    }else{
        switch(this->index->size()){
            case 1:
                //TODO:: think about fragmented index intervals: maybe if(isFragmented){ret ERROR} ??
                for (IntervalSet::value_iterator it = ((*index)[0])->value_begin(), end = ((*index)[0])->value_end(); it != end; ++it) {
                    decideName(*id,*it,0,0);
                    printRange(*id,true,*it,0,0,range);
                }
                break;
            case 2:
                //TODO:: think about fragmented index intervals: maybe if(isFragmented){ret ERROR} ??
                for (IntervalSet::value_iterator it = ((*index)[0])->value_begin(), end_1 = ((*index)[0])->value_end();
            it != end_1; ++it) {
                    for (IntervalSet::value_iterator itt = ((*index)[1])->value_begin(), end_2 = ((*index)[1])->value_end();
            itt != end_2; ++itt) {
                        decideName(*id,*it,*itt,0);
                        printRange(*id,true,*it,*itt,0,range);
                    }
                }
                break;
            case 3:
                //TODO:: raise NotImplemented
                break;
            default:
                std::cerr << "printDecl invalid index dimension" << endl;
                break;
        }
    }
}

/*************
FUNC POINTERS
******/

void init_forall(std::vector<pair<Literal*,Set*>*>* ids){
    SymbolTable::getInstance().newLocalTable();
    if(! ids){
        std::cerr << "No ids in init_forall\n";
        return;
    }
    for (vector<pair<Literal*,Set*>*>::iterator it = ids->begin(); it != ids->end(); it++){
        SymbolTable::getInstance().localInsert((*it)->first->toString(), new Symbol((*it)->first));
    }
}

void cycle_forall(int index, std::vector<pair<Literal*,Set*>*>* ids, Expr_node* body, Expr_node* condition){
    if(index >= ids->size()){
        if(condition){
            if( ((Literal*)condition->eval())->getValue() ){
                body->interpret();
                std::cout << " ";
            }
        }else{
            body->interpret();
            std::cout << " ";
        }
    }else{
        IntervalSet* range = ((ids->at(index))->second)->getSet();
        for (IntervalSet::value_iterator it = range->value_begin(),
                        end = range->value_end(); it != end; ++it) {
            SymbolTable::getInstance().localInsert((
                        ids->at(index))->first->toString(),
                        new Symbol(
                            new Literal(
                                        ((ids->at(index))->second)->getDomain(),
                                        *it)
                            )
                        );
            cycle_forall(index+1,ids,body,condition);
        }
    }
}

void delete_forall(){
    SymbolTable::getInstance().deleteLocalTable();
}

void forall_interpret(Fun* f){
    string id = f->getID();
    ExprList* args = f->getArgs();
    Expr_node* body = f->getBody();
    Expr_node* condition = f->getCondition();
    std::vector<pair<Literal*,Set*>*>* ids = f->getIDS();

    init_forall(ids);
    if(id.compare("forall") == 0){
        std::cout << "(and ";
    }else if(id.compare("alldifferent") == 0){
        std::cout << "(distinct ";
    }else if(id.compare("sum") == 0){
        std::cout << "(+ ";
    }else if(id.compare("exist") == 0){
        std::cout << "(or ";
    }
    cycle_forall(0,ids,body,condition);
    std::cout << ")";
    delete_forall();
}

void count_interpret(Fun* f){
    string id = f->getID();
    ExprList* args = f->getArgs();

    Symbol* ident = SymbolTable::getInstance().get(((Literal*) args->at(0))->toString());
    string id_sum = "pbsum_" + ident->getID();
    
    if(! ident){
        std::cerr << "Count Error:: No symbol found" << std::endl;
    }
    if(ident->getIndexSize() != 1){
        std::cerr << "Count Error:: Wrong array indexes" << std::endl;
    }else{
        std::cout << "\r"; //delete "(assert " string coming from parser default
        IntervalSet* index = ident->getIndexes()->at(0);
        for (IntervalSet::value_iterator it = index->value_begin(),
                        end = index->value_end(); it != end; ++it) {
            std::cout << "(assert-soft (not (= ";
                      f->getArgs()->at(1)->interpret();
            std::cout << " "
                      <<  SymbolTable::getInstance().printName(ident->getID(), *it, 0,0)
                      << ")) :id "
                      << id_sum << ")\n";
        }
    }

    std::cout << "(assert "
              << "(= " << id_sum << " ";
    f->getArgs()->at(2)->interpret();
    std::cout << ")";
}

//===================================================================//
//SymbolTable
//===================================================================//

SymbolTable::SymbolTable(){
    globalTable = new HashTable();
    localTable = new std::vector<HashTable*>();

    libr_func.push_back(std::pair<std::string, fptr>("forall", forall_interpret));
    libr_func.push_back(std::pair<std::string, fptr>("alldifferent", forall_interpret));
    libr_func.push_back(std::pair<std::string, fptr>("sum", forall_interpret));
    libr_func.push_back(std::pair<std::string, fptr>("exist", forall_interpret));
    libr_func.push_back(std::pair<std::string, fptr>("count", count_interpret));
}

void SymbolTable::setValue(Symbol* symbol, Expr_node* expr){
    globalTable->get(symbol->getID())->setValue(expr);
}

void SymbolTable::globalInsert(std::string key, Symbol* value){
    globalTable->insert(key, value);
}

void SymbolTable::globalInsert(Symbol* symbol){
    globalTable->insert(symbol->getID(), symbol);   
}

void SymbolTable::globalInsert(Symbol* symbol, Expr_node* expr){
    symbol->setValue(expr);
    globalTable->insert(symbol->getID(), symbol);
}

void SymbolTable::deleteLocalTable(){
    //memory leak
    localTable->pop_back();
}

void SymbolTable::newLocalTable(){
    localTable->push_back(new HashTable());
}

void SymbolTable::localInsert(std::string key, Symbol* value){
    (localTable->back())->insert(key, value);
}

fptr SymbolTable::call_lib_function_interpret(string id){
    for (vector<pair<string, fptr>>::iterator it = libr_func.begin(); it != libr_func.end(); it++){
        if( (*it).first.compare(id) == 0){
            return (*it).second;
        }
    }
    return NULL;
}

Symbol* SymbolTable::get(std::string key){
    Symbol* tmp;
    //for (vector<HashTable*>::iterator it = localTable->end(); it != localTable->begin(); it--){
    for (vector<HashTable*>::reverse_iterator it = localTable->rbegin(); it != localTable->rend(); it++){
        tmp = (*it)->get(key);
        if(tmp != NULL)
            return tmp;
    }
    return globalTable->get(key);
}

string SymbolTable::printName(string name,DNumber i,DNumber j,DNumber k){
    return name + "__" + i.to_str() + "__" + j.to_str() + "__" + k.to_str();
}
