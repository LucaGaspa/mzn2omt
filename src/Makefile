#/*********************************************************************** 
# * Makefile                                                            *
# *                                                                     *
# * 2015 Luca Gasparetto                                                *
# *                                                                     *
# *                                                                     *
# * This software may be modified and distributed under the terms       *
# * of the MIT license.  See the LICENSE file for details.              *
# ***********************************************************************/

LEX = flex
YACC = bison -d
# LEX = flex 
# YACC = bison -d

# We assume that your C-compiler is called cc

CC = g++ -w -std=c++11

# calc is the final object that we will generate, it is produced by
# the C compiler from the y.tab.o and from the lex.yy.o

calc: parser.tab.o lex.yy.o Expr.cpp
	$(CC) -lgmp -o ../bin/mzn2smt parser.tab.o lex.yy.o expr.cpp item.cpp atom.cpp literal.cpp symbol.cpp number.cpp

# These dependency rules indicate that 
# (1) lex.yy.o depends on lex.yy.c and y.tab.h
# (2) lex.yy.o and y.tab.o depend on calc.h.
# Make uses the dependencies to figure out what rules must be run when
# a file has changed.

lex.yy.o: lex.yy.c parser.tab.h
#lex.yy.o y.tab.o: calc.h

## This rule will use yacc to generate the files y.tab.c and y.tab.h
## from our file calc.y

parser.tab.c parser.tab.h: parser.y
	$(YACC) -v parser.y

## this is the make rule to use lex to generate the file lex.yy.c from
## our file calc.l

lex.yy.c: lexer.l
	$(LEX) lexer.l


## Make clean will delete all of the generated files so we can start
## from scratch

clean:
	-rm -f *.o lex.yy.c *.tab.*  calc *.output
