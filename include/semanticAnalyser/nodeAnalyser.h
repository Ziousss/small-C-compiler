#ifndef NODEANALYSER_H
#define NODEANALYSER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../include/parser/ast.h"
#include "struct.h"
#include "helperFuncAnalyser.h"

bool programAnalyser(ASTnode *program);
void funcDefAnalyser(ASTnode *funcDefAst, SemContext *context);
void blockAnalyser(ASTnode *blockAst, SemContext *context);
void stmtAnalyser(ASTnode *stmtAst, int *count, SemContext *context);
SemanticType expressionAnalyser(ASTnode *expressionAst, SemContext *context);
void returnAnalyser(ASTnode *returnAst, SemContext *context);
void assignAnalyser(ASTnode *assignment, SemContext *context);
SemanticType funcCallAnalyser(ASTnode *funcCallAst, SemContext *context);
void ifAnalyser(ASTnode *ifStmtAst, SemContext *context);
SemanticType binaryExprAnalyser(ASTnode *binary, SemContext *context);

#endif