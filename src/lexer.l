%{
	#include "calc.h"
	#include "parser.tab.h"
%}

%x string
%x string_quote
%x multilinecomment
%x doccomment
%x doccomment_file
%s bracket_exp
%s quoted_exp

%%

<*>\x0              {
						return MZN_INVALID_NULL;
					}

\xa               	{
						
                  	}
[ \f\xd\t]         	{/* ignore whitespace */}

"/**"             	{}
<doccomment>{
  "*/"            	{}
  [^*\xa]+       	{}
  "*"             	{}
  \xa               {}
}

"/***"             	{}
<doccomment_file>{
  "*/"            	{return MZN_DOC_FILE_COMMENT; }
  [^*\xa]+       	{}
  "*"             	{}
  \xa              	{}
}

"/*"              	{}
<multilinecomment>{
  "*/"            	{}
  [^*\xa]+       	{}
  "*"             	{}
  \xa               {}
}


"["               { return MZN_LEFT_BRACKET; }
"[|"              { return MZN_LEFT_2D_BRACKET; }
"]"               { return MZN_RIGHT_BRACKET; }
"|]"              { return MZN_RIGHT_2D_BRACKET; }
%[^\xa]*          { /* ignore comments */ }

"true"            { //yylval.literal.litType = BOOLTYPE;
					//yylval.literal.bValue = 1;					
					return MZN_BOOL_LITERAL; }
"false"           { //yylval.literal.litType = BOOLTYPE;
					//yylval.literal.bValue = 0;					
					return MZN_BOOL_LITERAL; }
[0-9]+            {	//yylval.literal.litType = INTTYPE;
					//yylval.literal.iValue = atoi(yytext);					
					return MZN_INTEGER_LITERAL;}
0x[0-9A-Fa-f]+    { //BASE 16
					//yylval.literal.litType = INTTYPE;
					//yylval.literal.iValue = strtol(yytext, NULL, 16);					
					return MZN_INTEGER_LITERAL;}
0o[0-7]+          { //BASE 8
					//yylval.literal.litType = INTTYPE;
					//yylval.literal.iValue = strtol(yytext, NULL, 8);					
					return MZN_INTEGER_LITERAL;}
[0-9]+\.[0-9]+    { //yylval.literal.litType = FLOATTYPE;
					//yylval.literal.fValue = atof(yytext);					
					return MZN_FLOAT_LITERAL;}
[0-9]+\.[0-9]+[Ee][+-]?[0-9]+  {
                    //yylval.literal.litType = FLOATTYPE;
					//yylval.literal.fValue = atof(yytext);					
					return MZN_FLOAT_LITERAL;
                   }
[0-9]+[Ee][+-]?[0-9]+  {
                    //yylval.literal.litType = FLOATTYPE;
					//yylval.literal.fValue = atof(yytext);					
					return MZN_FLOAT_LITERAL;
                   }
[:;|{},\[\]\.]    { return *yytext; }
\.\.              { return MZN_DOTDOT; }
"'\.\.'"          { return MZN_DOTDOT_QUOTED; }
::                { return MZN_COLONCOLON; }
_                 { return MZN_UNDERSCORE; }
"ann"             { return MZN_ANN; }
"annotation"      { return MZN_ANNOTATION; }
"any"             { return MZN_ANY; }
"array"           { return MZN_ARRAY; }
"bool"            { return MZN_BOOL; }
"case"            { return MZN_CASE; }
"constraint"      { return MZN_CONSTRAINT; }
"default"         { return MZN_DEFAULT; }
"div"             { return MZN_IDIV; }
"'div'"           { return MZN_IDIV_QUOTED; }
"diff"            { return MZN_DIFF; }
"'diff'"          { return MZN_DIFF_QUOTED; }
"else"            { return MZN_ELSE; }
"elseif"          { return MZN_ELSEIF; }
"endif"           { return MZN_ENDIF; }
"enum"            { return MZN_ENUM; }
"float"           { return MZN_FLOAT; }
"function"        { return MZN_FUNCTION; }
"if"              { return MZN_IF; }
"include"         { return MZN_INCLUDE; }
"infinity"        { return MZN_INFINITY; }
"intersect"       { return MZN_INTERSECT; }
"'intersect'"     { return MZN_INTERSECT_QUOTED; }
"in"              { return MZN_IN; }
"'in'"            { return MZN_IN_QUOTED; }
"int"             { return MZN_INT; }
"let"             { return MZN_LET; }
"list"            { return MZN_LIST; }
"maximize"        { return MZN_MAXIMIZE; }
"minimize"        { return MZN_MINIMIZE; }
"mod"             { return MZN_MOD; }
"'mod'"           { return MZN_MOD_QUOTED; }
"not"             { return MZN_NOT; }
"'not'"           { return MZN_NOT_QUOTED; }
"of"              { return MZN_OF; }
"output"          { return MZN_OUTPUT; }
"opt"             { return MZN_OPT; }
"par"             { return MZN_PAR; }
"predicate"       { return MZN_PREDICATE; }
"record"          { return MZN_RECORD; }
"satisfy"         { return MZN_SATISFY; }
"set"             { return MZN_SET; }
"solve"           { return MZN_SOLVE; }
"string"          { return MZN_STRING; }
"subset"          { return MZN_SUBSET; }
"'subset'"        { return MZN_SUBSET_QUOTED; }
"superset"        { return MZN_SUPERSET; }
"'superset'"      { return MZN_SUPERSET_QUOTED; }
"symdiff"         { return MZN_SYMDIFF; }
"'symdiff'"       { return MZN_SYMDIFF_QUOTED; }
"test"            { return MZN_TEST; }
"then"            { return MZN_THEN; }
"tuple"           { return MZN_TUPLE; }
"type"            { return MZN_TYPE; }
"union"           { return MZN_UNION; }
"'union'"         { return MZN_UNION_QUOTED; }
"var"             { return MZN_VAR; }
"variant_record"  { return MZN_VARIANT_RECORD; }
"where"           { return MZN_WHERE; }
"xor"             { return MZN_XOR; }
"'xor'"           { return MZN_XOR_QUOTED; }
"+"               { return MZN_PLUS; }
"'+'"             { return MZN_PLUS_QUOTED; }
"-"               { return MZN_MINUS; }
"'-'"             { return MZN_MINUS_QUOTED; }
"*"               { return MZN_MULT; }
"'*'"             { return MZN_MULT_QUOTED; }
"/"               { return MZN_DIV; }
"'/'"             { return MZN_DIV_QUOTED; }
"++"              { return MZN_PLUSPLUS; }
"'++'"            { return MZN_PLUSPLUS_QUOTED; }
"<>"              { return MZN_ABSENT; }
"<"               { return MZN_LE; }
"'<'"             { return MZN_LE_QUOTED; }
"<="              { return MZN_LQ; }
"'<='"            { return MZN_LQ_QUOTED; }
">"               { return MZN_GR; }
"'>'"             { return MZN_GR_QUOTED; }
">="              { return MZN_GQ; }
"'>='"            { return MZN_GQ_QUOTED; }
"=="              { return MZN_EQ; }
"'=='"            { return MZN_EQ_QUOTED; }
"="               { return MZN_EQ; }
"'='"             { return MZN_EQ_QUOTED; }
"!="              { return MZN_NQ; }
"'!='"            { return MZN_NQ_QUOTED; }
"->"              { return MZN_IMPL; }
"'->'"            { return MZN_IMPL_QUOTED; }
"<-"              { return MZN_RIMPL; }
"'<-'"            { return MZN_RIMPL_QUOTED; }
"<->"             { return MZN_EQUIV; }
"'<->'"           { return MZN_EQUIV_QUOTED; }
"\\/"             { return MZN_OR; }
"'\\/'"           { return MZN_OR_QUOTED; }
"/\\"             { return MZN_AND; }
"'/\\'"           { return MZN_AND_QUOTED; }

"~"[+*=-]         { return MZN_QUOTED_IDENTIFIER; }
"'~"[+*=-]"'"	  { return MZN_IDENTIFIER; }

[A-Za-z][A-Za-z0-9_]* { 
					//yylval.ident = (char*) malloc(sizeof(char)*(strlen(yytext)+1));
					//strcpy(yylval.ident, yytext);
					//sprintf(yylval.ident, "%s\0",yytext);
                   	return MZN_IDENTIFIER; }
_[A-Za-z][A-Za-z0-9_]* {
                    	return FLATZINC_IDENTIFIER;
                    }
                    

"\xE2\x88\x80"      {  	//yylval.ident = (char*) malloc(sizeof(char)*(strlen(yytext)+1));
					   	//strcpy(yylval.ident, yytext);
					   	return MZN_IDENTIFIER; }
"\xE2\x88\x83"      {  	//yylval.ident = (char*) malloc(sizeof(char)*(strlen(yytext)+1));
						//strcpy(yylval.ident, yytext);
						return MZN_IDENTIFIER; }
"\xE2\x88\x88"      { return MZN_IN; }
"\xE2\x8A\x86"      { return MZN_SUBSET; }
"\xE2\x8A\x87"      { return MZN_SUPERSET; }
"\xE2\x88\x9E"      { return MZN_INFINITY; }
"\xC2\xAC"          { return MZN_NOT; }
"\xE2\x86\x90"      { return MZN_RIMPL; }
"\xE2\x86\x92"      { return MZN_IMPL; }
"\xE2\x86\x94"      { return MZN_EQUIV; }
"\xE2\x88\xA7"      { return MZN_AND; }
"\xE2\x88\xA8"      { return MZN_OR; }
"\xE2\x89\xA0"      { return MZN_NQ; }
"\xE2\x89\xA4"      { return MZN_LQ; }
"\xE2\x89\xA5"      { return MZN_GQ; }
"\xE2\x88\xAA"      { return MZN_UNION; }
"\xE2\x88\xA9"      { return MZN_INTERSECT; }

$[A-Za-z][A-Za-z0-9_]* {
                    return MZN_TI_IDENTIFIER; }

"(" {  return *yytext; }
<bracket_exp>")" {  return *yytext; }
<quoted_exp>")" { }

\"                {}
<string,string_quote>[^\\"\xa\xd\x0]* {}
<string,string_quote>\\n         {}
<string,string_quote>\\t         {}
<string,string_quote>\\[\\']     {}
<string,string_quote>\\[\\"]     {}
<string>\\"("       { return MZN_STRING_QUOTE_START; }
<string_quote>\\"(" { return MZN_STRING_QUOTE_MID;}
<string>\"          { return MZN_STRING_LITERAL; }
<string_quote>\"          { return MZN_STRING_QUOTE_END; }
<string,string_quote>. {  return (unsigned char)yytext[0]; }
<string,string_quote><<EOF>> {  return MZN_UNTERMINATED_STRING; }

`[A-Za-z][A-Za-z0-9_]*` {return MZN_QUOTED_IDENTIFIER; }
.                 { return (unsigned char)yytext[0]; }


%%

void yyerror(const char* s){
	//fprintf(stdout, "%s\n", s);
	printf(": %s at %s\n", s, yytext);
}
int yywrap()
{
	return 1;
}
