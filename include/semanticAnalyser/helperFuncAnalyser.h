#ifndef HERLPERFUNCANALYSER_H
#define HERLPERFUNCANALYSER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../include/parser/ast.h"
#include "struct.h"

void push_to_scope(symbolNode *sym);
void pop_out_scope(int count);
symbolNode *find_in_scope(char *name);
semanticType fromTokToSem(Tokentype type);

#endif