#ifndef HERLPERFUNCANALYSER_H
#define HERLPERFUNCANALYSER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../include/parser/ast.h"
#include "struct.h"

void push_to_scope(SymbolNode *sym);
void pop_out_scope(int count);
SymbolNode *find_in_scope(char *name);
SemanticType fromTokToSem(Tokentype type);
char *fromSemToString(SemanticType type);


#endif