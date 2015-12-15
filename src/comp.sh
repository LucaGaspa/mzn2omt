#!/bin/sh

#/*********************************************************************** 
# * comp.sh                                                             *
# *                                                                     *
# * Copyright (C) 2015 Luca Gasparetto                                  *
# * All rights reserved.                                                *
# *                                                                     *
# * This software may be modified and distributed under the terms       *
# * of the MIT license.  See the LICENSE file for details.              *
# ***********************************************************************/

flex lexer.l
bison -d parser.y
g++ -o ../bin/mzn2smt parser.tab.c lex.yy.c
