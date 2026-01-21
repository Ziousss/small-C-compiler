#ifndef IRHEADER_H
#define IRHEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structIR.h"
#include "../include/parser/ast.h"

void programIR(ASTnode *program);
void funcDefIR(ASTnode *funcdef);

#endif