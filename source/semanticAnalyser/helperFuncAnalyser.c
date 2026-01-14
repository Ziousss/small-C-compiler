#include "../include/semanticAnalyser/helperFuncAnalyser.h"

static symbolNode *stack_scope = NULL;

void push_to_scope(symbolNode *sym){
    sym->next = stack_scope;
    stack_scope = sym;
}

void pop_out_scope(int count){
    while(stack_scope != NULL && count-- > 0){
        symbolNode *tmp = stack_scope;
        stack_scope = stack_scope->next;
        free(tmp->name);
        free(tmp);
    }
}

symbolNode *find_in_scope(char *name){
    symbolNode *cur = stack_scope;
    while(cur){
        if(strcmp(cur->name, name) == 0){
            return cur;
        }

        cur = cur->next;
    }
    return NULL;
}

semanticType fromTokToSem(Tokentype type){
    switch (type){
        case TOK_CHAR:          return SEM_CHAR;
        case TOK_INT:           return SEM_INT;
        case TOK_VOID:          return SEM_VOID;
        
        default:                return SEM_ERROR;
    }
}