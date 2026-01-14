#include "../include/semanticAnalyser/nodeAnalyser.h"

void stmtAnalyser(ASTnode *stmtAst, int *count){
    NodeType ast_type = stmtAst->ast_type;
    switch (ast_type){
        case AST_VAR_DECL: {
            if(find_in_scope(stmtAst->data.declaration.identifier)){
                printf("Redefinition of the %s identifier.\n", stmtAst->data.declaration.identifier);
                return;
            }

            symbolNode *sym = malloc(sizeof(symbolNode));
            sym->kind = SEM_VAR;
            sym->name = strdup(stmtAst->data.declaration.identifier);
            sym->type = fromTokToSem(stmtAst->data.declaration.type);
            sym->next = NULL;

            push_to_scope(sym);
            (*count)++;

            if(stmtAst->data.declaration.expression != NULL){
                expressionAnalyser(stmtAst->data.declaration.expression);
            }
            break;
        }
        case AST_RETURN: {
            expressionAnalyser(stmtAst->data.return_node.expr);   
            break;
        }
        case AST_ASSIGN_EXPR: {
            expressionAnalyser(stmtAst->data.assign.target);
            expressionAnalyser(stmtAst->data.assign.value);
            break;
        }
        case AST_IF_STMT: {
            expressionAnalyser(stmtAst->data.if_node.condition);
            
            blockAnalyser(stmtAst->data.if_node.if_branch);
            if(stmtAst->data.if_node.else_branch){
                blockAnalyser(stmtAst->data.if_node.else_branch);
            }
            break;
        }
        case AST_WHILE_STMT: {
            expressionAnalyser(stmtAst->data.while_node.condition);
            blockAnalyser(stmtAst->data.while_node.block);
            break;
        }
        case AST_FOR_STMT: {
            expressionAnalyser(stmtAst->data.for_node.initialisation);
            expressionAnalyser(stmtAst->data.for_node.condition);
            expressionAnalyser(stmtAst->data.for_node.incrementation);
            blockAnalyser(stmtAst->data.for_node.block);
            break;
        }
    }
}