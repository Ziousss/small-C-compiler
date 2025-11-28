#ifndef AST_H
#define AST_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Forward declaration
typedef struct ASTnode ASTnode;

typedef enum {
    NODE_PROGRAM, 
    NODE_FUNCDEF, 
    NODE_PARAMETERS, 
    NODE_STATEMENT, 
    NODE_DECLARATION, 
    NODE_BLOCK, 
    NODE_TYPE,
    NODE_NUMBER,
    NODE_IDENTIFIER,
    NODE_OPERATOR,
    NODE_EXPRESSION,
    NODE_FUNCCALL
} NodeType;

typedef struct {
    double value;
} NumberNode;

typedef struct {
    char *name;
} IdentifierNode;

typedef struct {
    ASTnode* indentifier;
    ASTnode* expression;
} AssignementNode; 

typedef struct {
    char operator;
    ASTnode* left;
    ASTnode* right;
} OperatorNode;

typedef struct {
    ASTnode** statements;
    int stmt_count;
} BlockNode;

typedef struct {
    ASTnode** parameters;
    int count;
} ParameterNode;

typedef struct {
    char *name;
    ASTnode *return_type;
    ASTnode *parameters;
    ASTnode *body;
} FunctionDefNode;

typedef struct {
    char *name;
    ASTnode** arguments;
    int arg_count;
} FunctionCallNode;

// Main AST node
struct ASTnode {
    NodeType type;
    union {
        NumberNode number;
        OperatorNode operator;
        FunctionDefNode function_def;
        FunctionCallNode function_call;
        BlockNode block;
        IdentifierNode identifier;
        ParameterNode parameter;
        AssignementNode assignement;
    } data;
};

#endif