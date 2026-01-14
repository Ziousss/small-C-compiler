#ifndef NODEANALYSER_H
#define NODEANALYSER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../include/parser/ast.h"
#include "struct.h"
#include "helperFuncAnalyser.h"

void programAnalyser(ASTnode *program);
void funcDefAnalyser(ASTnode *funcDefNode);


#endif