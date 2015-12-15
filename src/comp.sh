#!/bin/sh

flex lexer.l
bison -d parser.y
g++ -o ../bin/mzn2smt parser.tab.c lex.yy.c
