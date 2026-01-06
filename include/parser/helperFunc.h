#ifndef HELPERFUNC_H
#define HELPERFUNC_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"
#include "../lexer/tokenizer.h"

bool isTOKType(Tokentype type);
ASTnode *new_param_list();
ASTnode *create_param_tree(char *name, Tokentype type, int count);
void param_list_add(ASTnode *list, ASTnode *param);

#endif