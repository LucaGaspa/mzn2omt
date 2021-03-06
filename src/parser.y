/*********************************************************************** 
 * parser.y                                                            *
 *                                                                     *
 * 2016 Luca Gasparetto                                                *
 *                                                                     *
 *                                                                     *
 * This software may be modified and distributed under the terms       *
 * of the MIT license.  See the LICENSE file for details.              *
 ***********************************************************************/

%{  
    #include "calc.h"
  
  void yyerror(const char *);
    int yylex(void);
%}

%union {
  char* var;
  Expr_node* expr;
  Symbol* symbol;
  std::queue<Symbol*>* symbolList;
}

%error-verbose

%token <var> MZN_INTEGER_LITERAL "integer literal" MZN_BOOL_LITERAL "bool literal"
%token <var> MZN_FLOAT_LITERAL "float literal"
%token <var> MZN_IDENTIFIER "identifier" MZN_QUOTED_IDENTIFIER "quoted identifier" MZN_STRING_LITERAL "string literal"
%token MZN_STRING_QUOTE_START "interpolated string start" MZN_STRING_QUOTE_MID "interpolated string middle" MZN_STRING_QUOTE_END "interpolated string end"
%token MZN_TI_IDENTIFIER "type-inst identifier" MZN_DOC_COMMENT "documentation comment" MZN_DOC_FILE_COMMENT "file-level documentation comment"

%token MZN_VAR "var" MZN_PAR "par"

%token MZN_ABSENT "<>"
%token MZN_ANN "ann"
%token MZN_ANNOTATION "annotation"
%token MZN_ANY "any"
%token MZN_ARRAY "array"
%token MZN_BOOL "bool"
%token MZN_CASE "case"
%token MZN_CONSTRAINT "constraint"
%token MZN_DEFAULT "default"
%token MZN_ELSE "else"
%token MZN_ELSEIF "elseif"
%token MZN_ENDIF "endif"
%token MZN_ENUM "enum"
%token MZN_FLOAT "float"
%token MZN_FUNCTION "function"
%token MZN_IF "if"
%token MZN_INCLUDE "include"
%token MZN_INFINITY "infinity"
%token MZN_INT "int"
%token MZN_LET "let"
%token MZN_LIST "list"
%token MZN_MAXIMIZE "maximize"
%token MZN_MINIMIZE "minimize"
%token MZN_OF "of"
%token MZN_OPT "opt"
%token MZN_SATISFY "satisfy"
%token MZN_OUTPUT "output"
%token MZN_PREDICATE "predicate"
%token MZN_RECORD "record"
%token MZN_SET "set"
%token MZN_SOLVE "solve"
%token MZN_STRING "string"
%token MZN_TEST "test"
%token MZN_THEN "then"
%token MZN_TUPLE "tuple"
%token MZN_TYPE "type"
%token MZN_UNDERSCORE "_"
%token MZN_VARIANT_RECORD "variant_record"
%token MZN_WHERE "where"

%token MZN_LEFT_BRACKET "["
%token MZN_LEFT_2D_BRACKET "[|"
%token MZN_RIGHT_BRACKET "]"
%token MZN_RIGHT_2D_BRACKET "|]"

// Used to signal an error when parsing a MiniZinc file
// that contains identifiers starting with _
%token FLATZINC_IDENTIFIER

%token MZN_INVALID_INTEGER_LITERAL "invalid integer literal"
%token MZN_INVALID_FLOAT_LITERAL "invalid float literal"
%token MZN_UNTERMINATED_STRING "unterminated string"
%token MZN_INVALID_NULL "null character"

%token END 0 "end of file"

%token MZN_EQUIV "<->"
%token MZN_IMPL "->" MZN_RIMPL "<-"
%token MZN_OR "\\/" MZN_XOR "xor"
%token MZN_AND "/\\"
%token MZN_LE "<" MZN_GR ">" MZN_LQ "<=" MZN_GQ ">=" MZN_EQ "=" MZN_NQ "!="
%token MZN_IN "in" MZN_SUBSET "subset" MZN_SUPERSET "superset"
%token MZN_UNION "union" MZN_DIFF "diff" MZN_SYMDIFF "symdiff"
%token MZN_DOTDOT ".."
%token MZN_PLUS "+" MZN_MINUS "-"
%token MZN_MULT "*" MZN_DIV "/" MZN_IDIV "div" MZN_MOD "mod" MZN_INTERSECT "intersect"
%token MZN_NOT "not"
%token MZN_PLUSPLUS "++"
%token MZN_COLONCOLON "::"

%right PREC_ANNO
%left MZN_EQUIV
%left MZN_IMPL MZN_RIMPL
%left MZN_OR MZN_XOR
%left MZN_AND
%nonassoc MZN_LE MZN_GR MZN_LQ MZN_GQ MZN_EQ MZN_NQ
%nonassoc MZN_IN MZN_SUBSET MZN_SUPERSET
%left MZN_UNION MZN_DIFF MZN_SYMDIFF MZN_INTERSECT 
%nonassoc MZN_DOTDOT
%left MZN_PLUS MZN_MINUS
%left MZN_MULT MZN_DIV MZN_IDIV MZN_MOD
%nonassoc MZN_NOT
%right MZN_PLUSPLUS
%left MZN_QUOTED_IDENTIFIER
%left MZN_COLONCOLON

%token MZN_EQUIV_QUOTED "'<->'"
%token MZN_IMPL_QUOTED "'->'" MZN_RIMPL_QUOTED "'<-'"
%token MZN_OR_QUOTED "'\\/'" MZN_XOR_QUOTED "'xor'"
%token MZN_AND_QUOTED "'/\\'"
%token MZN_LE_QUOTED "'<'" MZN_GR_QUOTED "'>'" MZN_LQ_QUOTED "'<='" MZN_GQ_QUOTED "'>='" MZN_EQ_QUOTED "'='" MZN_NQ_QUOTED "'!='"
%token MZN_IN_QUOTED "'in'" MZN_SUBSET_QUOTED "'subset'" MZN_SUPERSET_QUOTED "'superset'"
%token MZN_UNION_QUOTED "'union'" MZN_DIFF_QUOTED "'diff'" MZN_SYMDIFF_QUOTED "'symdiff'"
%token MZN_DOTDOT_QUOTED "'..'"
%token MZN_PLUS_QUOTED "'+'" MZN_MINUS_QUOTED "'-'"
%token MZN_MULT_QUOTED "'*'" MZN_DIV_QUOTED "'/'" MZN_IDIV_QUOTED "'div'" MZN_MOD_QUOTED "'mod'" MZN_INTERSECT_QUOTED "'intersect'"
%token MZN_NOT_QUOTED "'not'"
%token MZN_COLONCOLON_QUOTED "'::'"
%token MZN_PLUSPLUS_QUOTED "'++'"

//%type <var> MZN_BOOL_LITERAL
%type <expr> expr_atom_head set_expr expr expr_list expr_list_head set_literal
%type <expr> comp_tail generator_list generator_list_head generator id_list id_list_head
%type <expr> set_comp simple_array_literal simple_array_literal_2d simple_array_literal_2d_list
%type <expr> simple_array_comp array_access_tail call_expr comp_or_expr if_then_else_expr let_expr
%type <symbol> base_ti_expr_tail base_ti_expr ti_expr ti_expr_and_id let_vardecl_item
%type <symbolList> ti_expr_list ti_expr_list_head let_vardecl_item_list

%%

model : item_list

item_list :
      /* empty */
    | item_list_head semi_or_none

item_list_head:
      item
             { } 
     | doc_file_comments item
             { } 
     | item_list_head ';' item
             { } 
     | item_list_head ';' doc_file_comments item
             { } 
     | error ';' item

doc_file_comments:
      MZN_DOC_FILE_COMMENT
             { } 
     | doc_file_comments MZN_DOC_FILE_COMMENT
             { } 
 
semi_or_none : | ';'

item : MZN_DOC_COMMENT item_tail
             { } 
     | item_tail
             { } 
 
item_tail :
      include_item
             { } 
     | vardecl_item
             { } 
     | assign_item
             { }
     | constraint_item
             { } 
     | solve_item
             { } 
     | output_item
             { } 
     | predicate_item
             { } 
     | function_item
             { } 
     | annotation_item
             { } 
 
include_item :
      MZN_INCLUDE MZN_STRING_LITERAL
             { } 
 
vardecl_item :
      ti_expr_and_id annotations
             {
              SymbolTable::getInstance().globalInsert($1);
              $1->printDecl(true,NULL);
             } 
     | ti_expr_and_id annotations MZN_EQ expr
             {
              SymbolTable::getInstance().globalInsert($1,$4);
              $1->printDecl(true,$4);
             } 
 
assign_item :
      MZN_IDENTIFIER MZN_EQ expr
             {
                string id = string($1);
                Symbol* mySym = SymbolTable::getInstance().get(id);
                if(mySym){
                  mySym->setValue($3);
                  mySym->printDecl(false,$3);
                }else{
                  std::cerr << "Assignment to a NOT DECLARED VAR: " << id << endl;
                  exit(0);
                }
             } 
 
constraint_item :
      MZN_CONSTRAINT expr
            {
                if($2 != NULL){
                    std::cout << "(assert ";
                    $2->interpret();
                    std::cout << ")" << std::endl;
                }else{
                    printf("warning: constraint not implemented! - parser.y\n");
                }
            } 
 
solve_item :
      MZN_SOLVE annotations MZN_SATISFY
             {
              std::cout << "(check-sat)\n";
              std::cout << "(get-model)\n";
             } 
     | MZN_SOLVE annotations MZN_MINIMIZE expr
             {
              std::cout << "(minimize ";
              $4->interpret();
              std::cout << ")\n";
              std::cout << "(check-sat)\n";
              std::cout << "(get-model)\n";
             } 
     | MZN_SOLVE annotations MZN_MAXIMIZE expr
             {
              std::cout << "(maximize ";
              $4->interpret();
              std::cout << ")\n";
              std::cout << "(check-sat)\n";
              std::cout << "(get-model)\n";
             } 
 
output_item :
      MZN_OUTPUT expr
             { } 
 
predicate_item :
        MZN_PREDICATE MZN_IDENTIFIER params annotations operation_item_tail
             { } 
       | MZN_TEST MZN_IDENTIFIER params annotations operation_item_tail
             { } 
 
function_item :
        MZN_FUNCTION ti_expr ':' id_or_quoted_op params annotations operation_item_tail
             { } 
       | ti_expr ':' MZN_IDENTIFIER '(' params_list ')' annotations operation_item_tail
             { } 
 
annotation_item :
        MZN_ANNOTATION MZN_IDENTIFIER params
             { } 
     | MZN_ANNOTATION MZN_IDENTIFIER params MZN_EQ expr
             { } 
 
operation_item_tail :
      /*empty*/
             { } 
     | MZN_EQ expr
             { } 
 
params :
      /* empty */
             { } 
     | '(' params_list ')'
             { } 
     | '(' error ')'
             { } 
 
params_list :
        /* empty */
             { } 
     | params_list_head comma_or_none
             { } 
 
params_list_head :
      ti_expr_and_id_or_anon
             { } 
     | params_list_head ',' ti_expr_and_id_or_anon
             { } 
 
comma_or_none : | ','

ti_expr_and_id_or_anon :
      ti_expr_and_id
             { } 
     | ti_expr
             { } 
     
ti_expr_and_id :
      ti_expr ':' MZN_IDENTIFIER
             {
               $$ = $1;
               $$->setIdentifier($3);
               delete $3;
             } 
 
ti_expr_list : ti_expr_list_head comma_or_none
             {
              $$ = $1;
             } 
 
ti_expr_list_head :
      ti_expr
             {
              $$ = new queue<Symbol*>();
              $$->push($1);
             } 
     | ti_expr_list_head ',' ti_expr
             {
              $1->push($3);
              $$ = $1;
             } 
 
ti_expr :
      base_ti_expr 
             {
              $$ = $1;
             }
    | MZN_ARRAY MZN_LEFT_BRACKET ti_expr_list MZN_RIGHT_BRACKET MZN_OF base_ti_expr
             {
              $$ = $6;
              $6->importIndexes($3);
             } 
     | MZN_LIST MZN_OF base_ti_expr
             { } 
 
base_ti_expr :
      base_ti_expr_tail
             {
              $$ = $1;
              $$->setTi_type(PAR);
             } 
     | MZN_OPT base_ti_expr_tail
             {
              $$ = $2;
              $$->setTi_type(PAR);
             } 
     | MZN_PAR opt_opt base_ti_expr_tail
             {
              $$ = $3;
              $$->setTi_type(PAR);
             } 
     | MZN_VAR opt_opt base_ti_expr_tail
             {
              $$ = $3;
              $$->setTi_type(VAR);
             } 
     | opt_opt MZN_SET MZN_OF base_ti_expr_tail
             {
              $$ = $4;
              $$->setTi_type(SETPAR);
             } 
     | MZN_PAR opt_opt MZN_SET MZN_OF base_ti_expr_tail
             {
              $$ = $5;
              $$->setTi_type(SETPAR);
             } 
     | MZN_VAR opt_opt MZN_SET MZN_OF base_ti_expr_tail
             {
              $$ = $5;
              $$->setTi_type(SETVAR);
             } 
 
opt_opt:
      /* nothing */
      { }
    | MZN_OPT
      { }

base_ti_expr_tail:
      MZN_INT
      {
        $$ = new Symbol(INT);
      }
    | MZN_BOOL
      {
        $$ = new Symbol(BOOL);
      }
    | MZN_FLOAT
      {
        $$ = new Symbol(FLOAT);
      }
    | MZN_STRING
      {
        //NOT SUPPORTED
      }
    | MZN_ANN
      {
        //NOT SUPPORTED
      } 
     | set_expr
      {
        $$ = new Symbol();
        Expr_node* to_transform = $1;
        Set* transformed;
        //to be put in SET constructor
        if(dynamic_cast<Literal*>(to_transform)){
            if(((Literal*) to_transform)->getDomain() == ID){
                Symbol* mySym = SymbolTable::getInstance().get(((Literal*) to_transform)->getID());
                if(mySym){
                    if(mySym->hasValue()){
                        transformed = (Set*) ((ExprList*) mySym->getValue())->at(0);
                    }else{
                        std::cerr << "cannot eval set_expr" << std::endl;  
                    }
                }else{
                    std::cerr << "cannot find id in set_expr" << std::endl;
                } 
            }else{
                transformed = new Set(MZN_DOTDOT,
                                      new Literal(INT,"0"),
                                      to_transform);  
            }
        }else{
            if(dynamic_cast<Expr*>(to_transform)){
                transformed = new Set(MZN_DOTDOT,
                                      new Literal(INT,"0"),
                                      to_transform->eval());
            }else{
              transformed = (Set*) to_transform;
            }
        }
        $$->setRange((transformed)->getDomain(),(transformed)->exportRange());
        //delete no more needed. now it data comes from symboltable.
      }
    | MZN_TI_IDENTIFIER
      {
        //NOT SUPPORTED
      }

expr_list : expr_list_head comma_or_none
      {
        $$ = $1;
      }

expr_list_head :
      expr
      {
        $$ = new ExprList($1);
      }
    | expr_list_head ',' expr
      {
        $$ = $1;
        ((ExprList*)($$))->add($3);
      }

///

set_expr :
      expr_atom_head
      {
        $$ = $1;
      }
    | set_expr MZN_COLONCOLON expr_atom_head
      {
        //NOT SUPPORTED
      }
    | set_expr MZN_UNION set_expr
      {
        $$ = new Set(MZN_UNION, $1, $3);
      } 
     | set_expr MZN_DIFF set_expr
      {
        //TODO:: $$ = new Set(MZN_DIFF,$1,$3);
      }
    | set_expr MZN_SYMDIFF set_expr
      {
        //TODO:: $$ = new Set(MZN_SYMDIFF,$1,$3);
      }
    | set_expr MZN_DOTDOT set_expr
      {
        $$ = new Set(MZN_DOTDOT,$1,$3);
        //$$ = new Expr(MZN_DOTDOT,2,$1,$3);
      }
    | MZN_DOTDOT_QUOTED '(' expr ',' expr ')'
      {
        //NOT SUPPORTED
      }
    | set_expr MZN_INTERSECT set_expr
      {
        //TODO:: $$ = new Set(MZN_INTERSECT,$1,$3);
      }
    | set_expr MZN_PLUSPLUS set_expr
      {
        //TODO:: $$ = new Set(MZN_PLUSPLUS,$1,$3);
      }
    | set_expr MZN_PLUS set_expr
      {
        $$ = new Expr(MZN_PLUS,2,$1,$3);
      }
    | set_expr MZN_MINUS set_expr
      {
        $$ = new Expr(MZN_MINUS,2,$1,$3);
      }
    | set_expr MZN_MULT set_expr
      {
        $$ = new Expr(MZN_MULT,2,$1,$3); 
      }
    | set_expr MZN_DIV set_expr
      {
        $$ = new Expr(MZN_DIV,2,$1,$3);
      }
    | set_expr MZN_IDIV set_expr
      {
        //TODO::
      }
    | set_expr MZN_MOD set_expr
      {
        //TODO::
      }
    | set_expr MZN_QUOTED_IDENTIFIER set_expr
      {
        //NOT SUPPORTED
      }
    | MZN_PLUS set_expr %prec MZN_NOT
      {
        //TODO::
      }
    | MZN_MINUS set_expr %prec MZN_NOT
      {
        //TODO::
      }

///

expr :
      expr_atom_head
      {
        $$ = $1;
      }
    | expr MZN_COLONCOLON expr_atom_head
      {
        //NOT SUPPORTED
      }
    | expr MZN_EQUIV expr
      {
        $$ = new Expr(MZN_EQUIV,2,$1,$3);
      }
    | expr MZN_IMPL expr
      {
        $$ = new Expr(MZN_IMPL,2,$1,$3);
      }
    | expr MZN_RIMPL expr
      {
        $$ = new Expr(MZN_RIMPL,2,$1,$3);
      }
    | expr MZN_OR expr
      {
        $$ = new Expr(MZN_OR,2,$1,$3);
      }
    | expr MZN_XOR expr
      {
        $$ = new Expr(MZN_XOR,2,$1,$3);
      }
    | expr MZN_AND expr
      {
        $$ = new Expr(MZN_AND,2,$1,$3);
      }
    | expr MZN_LE expr
      {
        $$ = new Expr(MZN_LE,2,$1,$3);
      }
    | expr MZN_GR expr
      {
        $$ = new Expr(MZN_GR,2,$1,$3);
      }
    | expr MZN_LQ expr
      {
        $$ = new Expr(MZN_LQ,2,$1,$3);
      }
    | expr MZN_GQ expr
      {
        $$ = new Expr(MZN_GQ,2,$1,$3);
      }
    | expr MZN_EQ expr
      {
        $$ = new Expr(MZN_EQ,2,$1,$3);
      }
    | expr MZN_NQ expr
      {
        $$ = new Expr(MZN_NQ,2,$1,$3);
      }
    | expr MZN_IN expr
      {
        $$ = new Expr(MZN_IN,2,$1,$3);
      }
    | expr MZN_SUBSET expr
      {
        $$ = new Expr(MZN_SUBSET,2,$1,$3);
      }
    | expr MZN_SUPERSET expr
      {
        $$ = new Expr(MZN_SUPERSET,2,$1,$3);
      }
    | expr MZN_UNION expr
      {
        $$ = new Expr(MZN_UNION,2,$1,$3);
      }
    | expr MZN_DIFF expr
      {
        $$ = new Expr(MZN_DIFF,2,$1,$3);
      }
    | expr MZN_SYMDIFF expr
      {
        $$ = new Expr(MZN_SYMDIFF,2,$1,$3);
      }
    | expr MZN_DOTDOT expr
      {
        //$$ = new Expr(MZN_DOTDOT,2,$1,$3);
        $$ = new Set(MZN_DOTDOT,$1,$3);
      }
    | MZN_DOTDOT_QUOTED '(' expr ',' expr ')'
      {
        //NOT SUPPORTED
      }
    | expr MZN_INTERSECT expr
      {
        $$ = new Expr(MZN_INTERSECT,2,$1,$3);
      }
    | expr MZN_PLUSPLUS expr
      {
        $$ = new Expr(MZN_PLUSPLUS,2,$1,$3);
      }
    | expr MZN_PLUS expr
      {
        $$ = new Expr(MZN_PLUS,2,$1,$3);
      }
    | expr MZN_MINUS expr
      {
        $$ = new Expr(MZN_MINUS,2,$1,$3);
      }
    | expr MZN_MULT expr
      {
        $$ = new Expr(MZN_MULT,2,$1,$3);
      }
    | expr MZN_DIV expr
      {
        $$ = new Expr(MZN_DIV,2,$1,$3);
      }
    | expr MZN_IDIV expr
      {
        $$ = new Expr(MZN_IDIV,2,$1,$3);
      }
    | expr MZN_MOD expr
      {
        $$ = new Expr(MZN_MOD,2,$1,$3);
      }
    | expr MZN_QUOTED_IDENTIFIER expr
      {
        //NOT SUPPORTED
      }
    | MZN_NOT expr %prec MZN_NOT
      {
        $$ = new Expr(MZN_NOT,1,$2);
      }
    | MZN_PLUS expr %prec MZN_NOT
      {
        $$ = new Expr(MZN_PLUS,1,$2);
      }
    | MZN_MINUS expr %prec MZN_NOT
      {
        $$ = new Expr(MZN_MINUS,1,$2);
      }

expr_atom_head :
      '(' expr ')'
      {
        $$ = $2;
      }
    | '(' expr ')' array_access_tail
      {
        //NOT SUPPORTED
      }
    | MZN_IDENTIFIER
      {
        $$ = new Literal(ID,$1);
        delete $1;
      }
    | MZN_IDENTIFIER array_access_tail
      {
        Literal* tmp = new Literal(ID,$1);
        delete $1;
        tmp->addIndex($2);
        $$ = tmp;
      }
    | MZN_UNDERSCORE
      {
        //TODO::
      }
    | MZN_UNDERSCORE array_access_tail
      {
        //TODO::
      }
    | MZN_BOOL_LITERAL
      {
        $$ = new Literal(BOOL,$1);
        delete $1;
      }
    | MZN_INTEGER_LITERAL
      {
        $$ = new Literal(INT,$1);
        delete $1;
      }
    | MZN_INFINITY
      {
        //TODO::
      }
    | MZN_FLOAT_LITERAL
      {
        $$ = new Literal(FLOAT,$1);
        delete $1;
      }
    | string_expr
      { /*nothing to do*/ $$ = NULL; }
    | MZN_ABSENT
      { /* NOT SUPPORTED */}
    | set_literal
      {
        $$ = $1;
      }
    | set_literal array_access_tail
      { /* TODO:: */ }
    | set_comp
      {
        $$ = $1;
      }
    | set_comp array_access_tail
      { /* TODO:: */ }
    | simple_array_literal
      {
        $$ = $1;
      }
    | simple_array_literal array_access_tail
      { /* TODO:: */ }
    | simple_array_literal_2d
      {
        $$ = $1;
      }
    | simple_array_literal_2d array_access_tail
      { /* TODO:: */ }
    | simple_array_comp
      {
        $$ = $1;
      }
    | simple_array_comp array_access_tail
      { /* TODO:: */ }
    | if_then_else_expr
      {
        $$ = $1;
      }
    | if_then_else_expr array_access_tail
      { /* NOT SUPPORTED */ }
    | let_expr
      {
        $$ = $1;
      }
    | call_expr
      {
        $$ = $1;
      }
    | call_expr array_access_tail
      { /* NOT SUPPORTED */}

string_expr:
      MZN_STRING_LITERAL
      { /* nothing to do */ }
    | MZN_STRING_QUOTE_START string_quote_rest
      { /* nothing to do */ }

string_quote_rest:
      expr_list_head MZN_STRING_QUOTE_END
      { /* nothing to do */ }
    | expr_list_head MZN_STRING_QUOTE_MID string_quote_rest
      { /* nothing to do */ }

array_access_tail :
      MZN_LEFT_BRACKET expr_list MZN_RIGHT_BRACKET
      {
        $$ = $2;
      }
    | array_access_tail MZN_LEFT_BRACKET expr_list MZN_RIGHT_BRACKET
      {
        ExprList* tmp = (ExprList*) $1;
        tmp->add($3);
        $$ = tmp;
      }

set_literal :
      '{' '}'
      {
        $$ = new Set();
      }
    | '{' expr_list '}'
      {
        $$ = new Set($2);
      }

set_comp :
      '{' expr '|' comp_tail '}'
      { 
        ((Comp*)$4)->setExpression($2);
        $$ = new Set(($4)->eval());
      }

comp_tail :
      generator_list
      {
        $$ = $1;
      }
    | generator_list MZN_WHERE expr
      {
        $$ = $1;
        ((Comp*)$$)->setCondition($3);
      }

generator_list : 
      generator_list_head comma_or_none
      {
        $$ = $1;
      }

generator_list_head :
      generator
      {
        $$ = new Comp((Expr*)$1);
      }
    | generator_list_head ',' generator
      {
        $$ = $1;
        ((Comp*)$$)->add($3);
      }

generator : 
      id_list MZN_IN expr
      {
        $$ = new Expr(MZN_IN,2,$1,$3);
      }

id_list : 
      id_list_head comma_or_none
      {
        $$ = $1;
      }

id_list_head :
      MZN_IDENTIFIER
      {
        $$ = new ExprList(new Literal(ID,$1));
      }
    | id_list_head ',' MZN_IDENTIFIER
      {
        $$ = $1;
        ((ExprList*)$$)->add(new Literal(ID,$3));
      }

simple_array_literal : 
      MZN_LEFT_BRACKET MZN_RIGHT_BRACKET
      {
        $$ = new ExprList();
      }
    | MZN_LEFT_BRACKET expr_list MZN_RIGHT_BRACKET
      {
        $$ = $2;
      }

simple_array_literal_2d :
      MZN_LEFT_2D_BRACKET MZN_RIGHT_2D_BRACKET
      {
        $$ = new ExprList();
      }
    | MZN_LEFT_2D_BRACKET simple_array_literal_2d_list MZN_RIGHT_2D_BRACKET
      {
        $$ = $2;
      }
    | MZN_LEFT_2D_BRACKET simple_array_literal_2d_list '|' MZN_RIGHT_2D_BRACKET
      {
        $$ = $2;
      }
    | MZN_LEFT_2D_BRACKET simple_array_literal_3d_list MZN_RIGHT_2D_BRACKET
      { /* TODO:: */ }

simple_array_literal_3d_list :
      '|' '|'
      { /* TODO:: */ }
    | '|' simple_array_literal_2d_list '|'
      { /* TODO:: */ }
    | simple_array_literal_3d_list ',' '|' simple_array_literal_2d_list '|'
      { /* TODO:: */ } 

simple_array_literal_2d_list :
      expr_list
      {
        $$ = new ExprList();
        ((ExprList*) $$)->add($1);
      }
    | simple_array_literal_2d_list '|' expr_list
      {
        $$ = $1;
        ((ExprList*) $$)->add($3);
      }

simple_array_comp :
      MZN_LEFT_BRACKET expr '|' comp_tail MZN_RIGHT_BRACKET
      {
        ((Comp*)$4)->setExpression($2);
        $$ = ($4)->eval();
      }

if_then_else_expr :
      MZN_IF expr MZN_THEN expr elseif_list MZN_ELSE expr MZN_ENDIF
      {
        $$ = new Expr(MZN_IF,3,$2,$4,$7);
      }

elseif_list :
      { }
    | elseif_list MZN_ELSEIF expr MZN_THEN expr
      {
        std::cerr << "parser: NOT SUPPORTED elseif\n";
        exit(0);
      }

quoted_op :
      MZN_EQUIV_QUOTED
      { }
    | MZN_IMPL_QUOTED
      { }
    | MZN_RIMPL_QUOTED
      { }
    | MZN_OR_QUOTED
      { }
    | MZN_XOR_QUOTED
      { }
    | MZN_AND_QUOTED
      { }
    | MZN_LE_QUOTED
      { }
    | MZN_GR_QUOTED
      { }
    | MZN_LQ_QUOTED
      { }
    | MZN_GQ_QUOTED
      { }
    | MZN_EQ_QUOTED
      { }
    | MZN_NQ_QUOTED
      { }
    | MZN_IN_QUOTED
      { }
    | MZN_SUBSET_QUOTED
      { }
    | MZN_SUPERSET_QUOTED
      { }
    | MZN_UNION_QUOTED
      { }
    | MZN_DIFF_QUOTED
      { }
    | MZN_SYMDIFF_QUOTED
      { }
    | MZN_PLUS_QUOTED
      { }
    | MZN_MINUS_QUOTED
      { }
    | MZN_MULT_QUOTED
      { }
    | MZN_DIV_QUOTED
      { }
    | MZN_IDIV_QUOTED
      { }
    | MZN_MOD_QUOTED
      { }
    | MZN_INTERSECT_QUOTED
      { }
    | MZN_PLUSPLUS_QUOTED
      { }
    | MZN_NOT_QUOTED
      { }

quoted_op_call :
      quoted_op '(' expr ',' expr ')'
      { }
    | quoted_op '(' expr ')'
      { }

call_expr :
      MZN_IDENTIFIER '(' ')'
      { /* TODO:: */ }
    | quoted_op_call
      { /* NOT SUPPORTED */ }
    | MZN_IDENTIFIER '(' comp_or_expr ')'
      {
        ((Fun*) $3)->setReference(string($1));
        $$ = $3;
      }
    | MZN_IDENTIFIER '(' comp_or_expr ')' '(' expr ')'
      {
        ((Fun*) $3)->setReference(string($1));
        ((Fun*) $3)->setBody($6);
        $$ = $3;
      }

comp_or_expr :
      expr_list
      {
        $$ = new Fun((ExprList*) $1);
      }
    | expr_list MZN_WHERE expr
      {
        $$ = new Fun((ExprList*) $1,$3);
      }

let_expr :
      MZN_LET '{' let_vardecl_item_list '}' MZN_IN expr %prec PREC_ANNO
      {
        $$ = new Let($3, $6);
      }
    | MZN_LET '{' let_vardecl_item_list comma_or_semi '}' MZN_IN expr %prec PREC_ANNO
      {
        $$ = new Let($3,$7);
      }

let_vardecl_item_list :
      let_vardecl_item
      {
        $$ = new std::queue<Symbol*>();
        $$->push($1);
      }
    | constraint_item
      { /* NOT SUPPORTED */ }
    | let_vardecl_item_list comma_or_semi let_vardecl_item
      {
        $$ = $1;
        $$->push($3);
      }
    | let_vardecl_item_list comma_or_semi constraint_item
      { /* NOT SUPPORTED */ }

comma_or_semi : ',' | ';'

let_vardecl_item :
      ti_expr_and_id annotations
      {
        $$ = $1;
      }
    | ti_expr_and_id annotations MZN_EQ expr
      {
        $$ = $1;
        $$->setValue($4);
      }

annotations :
      /* empty */
      { }
    | ne_annotations

ne_annotations :
      MZN_COLONCOLON expr_atom_head
      { }
    | ne_annotations MZN_COLONCOLON expr_atom_head
      { }

id_or_quoted_op :
      MZN_IDENTIFIER
      { }
    | MZN_EQUIV_QUOTED
      { }
    | MZN_IMPL_QUOTED
      { }
    | MZN_RIMPL_QUOTED
      { }
    | MZN_OR_QUOTED
      { }
    | MZN_XOR_QUOTED
      { }
    | MZN_AND_QUOTED
      { }
    | MZN_LE_QUOTED
      { }
    | MZN_GR_QUOTED
      { }
    | MZN_LQ_QUOTED
      { }
    | MZN_GQ_QUOTED
      { }
    | MZN_EQ_QUOTED
      { }
    | MZN_NQ_QUOTED
      { }
    | MZN_IN_QUOTED
      { }
    | MZN_SUBSET_QUOTED
      { }
    | MZN_SUPERSET_QUOTED
      { }
    | MZN_UNION_QUOTED
      { }
    | MZN_DIFF_QUOTED
      { }
    | MZN_SYMDIFF_QUOTED
      { }
    | MZN_DOTDOT_QUOTED
      { }
    | MZN_PLUS_QUOTED
      { }
    | MZN_MINUS_QUOTED
      { }
    | MZN_MULT_QUOTED
      { }
    | MZN_DIV_QUOTED
      { }
    | MZN_IDIV_QUOTED
      { }
    | MZN_MOD_QUOTED
      { }
    | MZN_INTERSECT_QUOTED
      { }
    | MZN_NOT_QUOTED
      { }
    | MZN_PLUSPLUS_QUOTED
      { }


%%


int main() {
  
  //yyin -> file pointer
  yyparse(); // yyparse automatically calls yylex to obtain tokens

    return 0;
}
