%{  
	#include <iostream>
	#include <stdlib.h>
	void yyerror(const char *);
	int yylex(void);
%}

%union {

}

%error-verbose

%token <literal> MZN_INTEGER_LITERAL "integer literal" MZN_BOOL_LITERAL "bool literal"
%token <literal> MZN_FLOAT_LITERAL "float literal"
%token <ident> MZN_IDENTIFIER "identifier" MZN_QUOTED_IDENTIFIER "quoted identifier" MZN_STRING_LITERAL "string literal"
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
             { } 
     | ti_expr_and_id annotations MZN_EQ expr
             { } 
 
assign_item :
      MZN_IDENTIFIER MZN_EQ expr
             { } 
 
constraint_item :
      MZN_CONSTRAINT expr
             { } 
 
solve_item :
      MZN_SOLVE annotations MZN_SATISFY
             { } 
     | MZN_SOLVE annotations MZN_MINIMIZE expr
             { } 
     | MZN_SOLVE annotations MZN_MAXIMIZE expr
             { } 
 
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
             { } 
 
ti_expr_list : ti_expr_list_head comma_or_none
             { } 
 
ti_expr_list_head :
      ti_expr
             { } 
     | ti_expr_list_head ',' ti_expr
             { } 
 
ti_expr :
      base_ti_expr 
			 { }
    | MZN_ARRAY MZN_LEFT_BRACKET ti_expr_list MZN_RIGHT_BRACKET MZN_OF base_ti_expr
             { } 
     | MZN_LIST MZN_OF base_ti_expr
             { } 
 
base_ti_expr :
      base_ti_expr_tail
             { } 
     | MZN_OPT base_ti_expr_tail
             { } 
     | MZN_PAR opt_opt base_ti_expr_tail
             { } 
     | MZN_VAR opt_opt base_ti_expr_tail
             { } 
     | opt_opt MZN_SET MZN_OF base_ti_expr_tail
             { } 
     | MZN_PAR opt_opt MZN_SET MZN_OF base_ti_expr_tail
             { } 
     | MZN_VAR opt_opt MZN_SET MZN_OF base_ti_expr_tail
             { } 
 
opt_opt:
      /* nothing */
      { }
    | MZN_OPT
      { }

base_ti_expr_tail:
      MZN_INT
      { }
    | MZN_BOOL
      { }
    | MZN_FLOAT
      { }
    | MZN_STRING
      { }
    | MZN_ANN
      { } 
     | set_expr
      { }
    | MZN_TI_IDENTIFIER
      { }

expr_list : expr_list_head comma_or_none
	  { }

expr_list_head :
      expr
      { }
    | expr_list_head ',' expr
      { }

///

set_expr :
      expr_atom_head
      { }
    | set_expr MZN_COLONCOLON expr_atom_head
      { }
    | set_expr MZN_UNION set_expr
      { } 
     | set_expr MZN_DIFF set_expr
      { }
    | set_expr MZN_SYMDIFF set_expr
      { }
    | set_expr MZN_DOTDOT set_expr
      { }
    | MZN_DOTDOT_QUOTED '(' expr ',' expr ')'
      { }
    | set_expr MZN_INTERSECT set_expr
      { }
    | set_expr MZN_PLUSPLUS set_expr
      { }
    | set_expr MZN_PLUS set_expr
      { }
    | set_expr MZN_MINUS set_expr
      { }
    | set_expr MZN_MULT set_expr
      { }
    | set_expr MZN_DIV set_expr
      { }
    | set_expr MZN_IDIV set_expr
      { }
    | set_expr MZN_MOD set_expr
      { }
    | set_expr MZN_QUOTED_IDENTIFIER set_expr
      { }
    | MZN_PLUS set_expr %prec MZN_NOT
      { }
    | MZN_MINUS set_expr %prec MZN_NOT
      { }

///

expr :
      expr_atom_head
      { }
    | expr MZN_COLONCOLON expr_atom_head
      { }
    | expr MZN_EQUIV expr
      { }
    | expr MZN_IMPL expr
      { }
    | expr MZN_RIMPL expr
      { }
    | expr MZN_OR expr
      { }
    | expr MZN_XOR expr
      { }
    | expr MZN_AND expr
      { }
    | expr MZN_LE expr
      { }
    | expr MZN_GR expr
      { }
    | expr MZN_LQ expr
      { }
    | expr MZN_GQ expr
      { }
    | expr MZN_EQ expr
      { }
    | expr MZN_NQ expr
      { }
    | expr MZN_IN expr
      { }
    | expr MZN_SUBSET expr
      { }
    | expr MZN_SUPERSET expr
      { }
    | expr MZN_UNION expr
      { }
    | expr MZN_DIFF expr
      { }
    | expr MZN_SYMDIFF expr
      { }
    | expr MZN_DOTDOT expr
      { }
    | MZN_DOTDOT_QUOTED '(' expr ',' expr ')'
      { }
    | expr MZN_INTERSECT expr
      { }
    | expr MZN_PLUSPLUS expr
      { }
    | expr MZN_PLUS expr
      { }
    | expr MZN_MINUS expr
      { }
    | expr MZN_MULT expr
      { }
    | expr MZN_DIV expr
      { }
    | expr MZN_IDIV expr
      { }
    | expr MZN_MOD expr
      { }
    | expr MZN_QUOTED_IDENTIFIER expr
      { }
    | MZN_NOT expr %prec MZN_NOT
      { }
    | MZN_PLUS expr %prec MZN_NOT
      { }
    | MZN_MINUS expr %prec MZN_NOT
      { }

expr_atom_head :
      '(' expr ')'
      { }
    | '(' expr ')' array_access_tail
      { }
    | MZN_IDENTIFIER
      { }
    | MZN_IDENTIFIER array_access_tail
      { }
    | MZN_UNDERSCORE
      { }
    | MZN_UNDERSCORE array_access_tail
      { }
    | MZN_BOOL_LITERAL
      { }
    | MZN_INTEGER_LITERAL
      { }
    | MZN_INFINITY
      { }
    | MZN_FLOAT_LITERAL
      { }
    | string_expr
      { }
    | MZN_ABSENT
      { }
    | set_literal
      { }
    | set_literal array_access_tail
      { }
    | set_comp
      { }
    | set_comp array_access_tail
      { }
    | simple_array_literal
      { }
    | simple_array_literal array_access_tail
      { }
    | simple_array_literal_2d
      { }
    | simple_array_literal_2d array_access_tail
      { }
    | simple_array_comp
      { }
    | simple_array_comp array_access_tail
      { }
    | if_then_else_expr
      { }
    | if_then_else_expr array_access_tail
      { }
    | let_expr
      { }
    | call_expr
      { }
    | call_expr array_access_tail
      { }

string_expr:
      MZN_STRING_LITERAL
      { }
    | MZN_STRING_QUOTE_START string_quote_rest
      { }

string_quote_rest:
      expr_list_head MZN_STRING_QUOTE_END
      { }
    | expr_list_head MZN_STRING_QUOTE_MID string_quote_rest
      { }

array_access_tail :
      MZN_LEFT_BRACKET expr_list MZN_RIGHT_BRACKET
      { }
    | array_access_tail MZN_LEFT_BRACKET expr_list MZN_RIGHT_BRACKET
      { }

set_literal :
      '{' '}'
      { }
    | '{' expr_list '}'
      { }

set_comp :
      '{' expr '|' comp_tail '}'
      { }

comp_tail :
      generator_list
      { }
    | generator_list MZN_WHERE expr
      { }

generator_list : generator_list_head comma_or_none

generator_list_head :
      generator
      { }
    | generator_list_head ',' generator
      { }

generator : 
      id_list MZN_IN expr
      { }

id_list : id_list_head comma_or_none

id_list_head :
      MZN_IDENTIFIER
      { }
    | id_list_head ',' MZN_IDENTIFIER
      { }

simple_array_literal : 
      MZN_LEFT_BRACKET MZN_RIGHT_BRACKET
      { }
    | MZN_LEFT_BRACKET expr_list MZN_RIGHT_BRACKET
      { }

simple_array_literal_2d :
      MZN_LEFT_2D_BRACKET MZN_RIGHT_2D_BRACKET
      { }
    | MZN_LEFT_2D_BRACKET simple_array_literal_2d_list MZN_RIGHT_2D_BRACKET
      { }
    | MZN_LEFT_2D_BRACKET simple_array_literal_2d_list '|' MZN_RIGHT_2D_BRACKET
      { }
    | MZN_LEFT_2D_BRACKET simple_array_literal_3d_list MZN_RIGHT_2D_BRACKET
      { }

simple_array_literal_3d_list :
      '|' '|'
      { }
    | '|' simple_array_literal_2d_list '|'
      { }
    | simple_array_literal_3d_list ',' '|' simple_array_literal_2d_list '|'
      { } 

simple_array_literal_2d_list :
      expr_list
      { }
    | simple_array_literal_2d_list '|' expr_list
      { }

simple_array_comp :
      MZN_LEFT_BRACKET expr '|' comp_tail MZN_RIGHT_BRACKET
      { }

if_then_else_expr :
      MZN_IF expr MZN_THEN expr elseif_list MZN_ELSE expr MZN_ENDIF
      { }

elseif_list :
      { }
    | elseif_list MZN_ELSEIF expr MZN_THEN expr
      { }

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
      { }
    | quoted_op_call
      { }
    | MZN_IDENTIFIER '(' comp_or_expr ')'
      { }
    | MZN_IDENTIFIER '(' comp_or_expr ')' '(' expr ')'
      { }

comp_or_expr :
      expr_list
      { }
    | expr_list MZN_WHERE expr
      { }

let_expr :
      MZN_LET '{' let_vardecl_item_list '}' MZN_IN expr %prec PREC_ANNO
      { }
    | MZN_LET '{' let_vardecl_item_list comma_or_semi '}' MZN_IN expr %prec PREC_ANNO
      { }

let_vardecl_item_list :
      let_vardecl_item
      { }
    | constraint_item
      { }
    | let_vardecl_item_list comma_or_semi let_vardecl_item
      { }
    | let_vardecl_item_list comma_or_semi constraint_item
      { }

comma_or_semi : ',' | ';'

let_vardecl_item :
      ti_expr_and_id annotations
      { }
    | ti_expr_and_id annotations MZN_EQ expr
      { }

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
	yyparse(); // yyparse automatically calls yylex to obtain tokens
	return 0;
}
