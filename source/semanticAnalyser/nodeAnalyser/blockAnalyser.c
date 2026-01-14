#include "../include/semanticAnalyser/nodeAnalyser.h"

void blockAnalyser(ASTnode *blockAst){
    ASTnode *stmt = blockAst->data.block.stmts;
    int count = 0;

    while(stmt){
        stmtAnalyser(stmt, &count);
        stmt = stmt->next;
    }

    pop_out_scope(count);