#include "../include/semanticAnalyser/nodeAnalyser.h"

void funcDefAnalyser(ASTnode *funcDefAst){
    if(funcDefAst == NULL){
        return;
    }

    symbolNode *funcDefSem = malloc(sizeof(symbolNode));
    semanticType type = fromTokToSem(funcDefAst->data.func_def.return_type);
    if(type == SEM_ERROR){
        printf("the return type of the function %s is not supported yet.\n", funcDefAst->data.func_def.name);
        return;
    }
    funcDefSem->name = strdup(funcDefAst->data.func_def.name);
    funcDefSem->kind = SEM_FCT;
    funcDefSem->type = type;
    funcDefSem->next = NULL;

    push_to_scope(funcDefSem);

    int count = 0;
    ParameterNode *paramAst = funcDefAst->data.func_def.parameters;
    while(paramAst){
        symbolNode *paramSem = malloc(sizeof(symbolNode));

        paramSem->kind = SEM_PARAM;
        paramSem->name = strdup(paramAst->name);
        paramSem->type = fromTokToSem(paramAst->ret_type);
        paramSem->next = NULL;

        push_to_scope(paramSem);
        paramAst = paramAst->next;
    }

    blockAnalyser(funcDefAst->data.func_def.body);

    pop_out_scope(count);
}