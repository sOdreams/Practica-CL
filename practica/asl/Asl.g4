//COMO COMPILAR(en la carpeta "asl"):
//1. >> make antlr
//2. >> make
//3. ./asl ../examples/jp_chkt_01.asl


//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2020-2030  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '('parameters')' (':' type)? declarations statements ENDFUNC
        ;

parameters
        : ( (ID ':' type) (',' ID ':' type)*  )?;

declarations
        : (variable_decl)*
        ;

//Puedo poner una ID, pero si decido poner mas, antes habrá una coma, seguido del tipaje
variable_decl
        : VAR ID (',' ID)* ':' type
        ;

type    : INT
        | BOOL
        | FLOAT
        | CHAR
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           # assignStmt


          // if-then-else statements (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF       # ifStmt


         // while do statement
        | WHILE expr DO statements ENDWHILE                       #whileStmt


          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ident '(' ')' ';'                   # procCall


        //return (optional expr)
        | RETURN expr? ';'                         #returnCall


          // Read a variable
        | READ left_expr ';'                  # readStmt


          // Write an expression
        | WRITE expr ';'                      # writeExpr


          // Write a string
        | WRITE STRING ';'                    # writeString
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident                      # just_ident
        | ident LCOR expr RCOR       # left_array_acces
        ;

// Grammar for expressions with boolean, relational and aritmetic operators

expr    : LPAR expr RPAR                                    # parenthesis
        | op=(NOT|MINUS|PLUS) expr                          # unary
        | expr op=(MUL|DIV) expr                            # arithmetic
        | expr op=(PLUS|MINUS) expr                         # arithmetic
        | expr op=(EQUAL|NEQ|GT|GE|LT|LE) expr              # relational
        | ident LCOR expr RCOR                              # expr_array_acces
        | ident LPAR (expr (',' expr)*)? RPAR               # func_call
        | expr op=AND expr                                  # logical
        | expr op=OR expr                                   # logical
        | (INTVAL | FLOATVAL | BOOLVAL | CHARVAL)           # value
        | ident                                             # exprIdent
        ;

// Identifiers
ident   : ID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '=' ;
EQUAL     : '==' ;
NEQ       : '!=' ;
GT        : '>' ;
GE        : '>=' ;
LE        : '<=' ;
LT        : '<' ;
NOT       : 'not' ;
AND       : 'and' ;
OR        : 'or' ;
MINUS     : '-' ;
DIV       : '/' ;
LPAR      : '(';
RPAR      : ')';
LCOR      : '[';
RCOR      : ']';
PLUS      : '+' ;
MUL       : '*';
VAR       : 'var';
INT       : 'int';
BOOL      : 'bool';
FLOAT     : 'float';
CHAR      : 'char';
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE     : 'while' ;
DO        : 'do' ;
ENDWHILE  : 'endwhile';
RETURN    : 'return';
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
READ      : 'read' ;
WRITE     : 'write' ;


INTVAL    : ('0'..'9')+ ;
BOOLVAL   : ('true'|'false');
FLOATVAL  : ('0'..'9')+ ('.') ('0'..'9')+;
CHARVAL   : '\'' ( ESC_SEQ | ~('\\'|'"') ) '\'';



ID        : ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ; //identificadors, sempre declarats despres de les paraules clau

// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
