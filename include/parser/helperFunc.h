#ifndef HELPERFUNC_H
#define HELPERFUNC_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"
#include "../lexer/tokenizer.h"

bool isTOKType(Tokentype type);
ParameterNode *new_param_list();
ParameterNode *create_param_tree(char *name, Tokentype type, int count);
void param_list_add(ParameterNode **head, ParameterNode *param);
ASTnode *new_stmt_list();
void add_stmt_list(ASTnode *list, ASTnode *param);

#endif