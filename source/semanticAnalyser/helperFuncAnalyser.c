#include "../include/semanticAnalyser/helperFuncAnalyser.h"

static SymbolNode *stack_scope = NULL;

void push_to_scope(SymbolNode *sym){
    sym->next = stack_scope;
    stack_scope = sym;
}

void pop_out_scope(int count){
    while(stack_scope != NULL && count-- > 0){
        SymbolNode *tmp = stack_scope;
        stack_scope = stack_scope->next;
        free(tmp->name);
        free(tmp);
    }
}

SymbolNode *find_in_scope(char *name){
    SymbolNode *cur = stack_scope;
    while(cur){
        if(strcmp(cur->name, name) == 0){
            return cur;
        }

        cur = cur->next;
    }
    return NULL;
}

SemanticType fromTokToSem(Tokentype type){
    switch (type){
        case TOK_CHAR:          return SEM_CHAR;
        case TOK_INT:           return SEM_INT;
        case TOK_VOID:          return SEM_VOID;
        
        default:                return SEM_ERROR;
    }
}

char *fromSemToString(SemanticType type){
    switch (type){
        case SEM_INT:   return "INT";
        case SEM_CHAR:  return "CHAR";
        case SEM_VOID:  return "VOID";

        default:        return "Not name yet";
    }
}