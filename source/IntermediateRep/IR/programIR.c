#include "../include/IntermediateRep/IRheader.h"

IRstruct *programIR(ASTnode *program){
    if(program->ast_type != AST_PROGRAM){
        printf("Given AST is not the program AST.\n");
        return;
    }

    IRContext *context = malloc(sizeof(IRContext));
    if(context == NULL){
        printf("Malloc error in programIR.\n");
        return NULL;
    }

    context->head = NULL;
    context->tail = NULL;
    context->current_label = 0;
    context->current_tmp = 0;

    ASTnode *funcdef = program->data.program_node.func_def;
    while(funcdef != NULL){
        funcDefIR(funcdef, context);
        funcdef = funcdef->next;
    }

    if(context->errors == 0){
        return context->head;
    }

    return NULL;
}