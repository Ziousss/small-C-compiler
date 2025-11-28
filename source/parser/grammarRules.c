#include "../include/parser/ast.h"
#include "../include/parser/grammarRules.h"
#include "../include/lexer/tokenizer.h"

/*
Structure:
program -> functiondef
funcitondef -> Type Indentifier '(' paramters ')' Block
paramters -> Type Indentifier {',' Type Identifier} | empty
block -> '{' statement '}'
statement -> declaration | assignement | ifstatement | whilestatement | 
    forststement | return statement | expressionstatement | block
declaration -> Type identifier ['=' expression] ';'
assignement -> Identifier '=' expression ';'
expressionstatement -> expression ';'
IfStatement -> 'if' '(' Expression ')' Statement ['else' Statement]
WhileStatement -> 'while' '(' Expression ')' Statement
ForStatement -> 'for' '(' [Declaration | Assignment] ';' Expression ';' Assignment ')' Statement
ReturnStatement -> 'return' [Expression] ';'
Expression -> Literal | Identifier | Expression Operator Expression | '(' Expression ')' | FunctionCall
FunctionCall -> Identifier '(' Arguments ')'
Arguments -> Expression {',' Expression}* | ε
Type -> 'int' | 'float' | 'char' | 'void' | 'double' | ...
Literal -> IntegerLiteral | FloatLiteral | CharLiteral | StringLiteral
Operator -> '+' | '-' | '*' | '/' | '%' | '==' | '!=' | '<' | '>' | '<=' | '>=' | '&&' | '||' | ...
*/



