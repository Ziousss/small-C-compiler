#include "../include/IntermediateRep/IRheader.h"

void funcDefIR(ASTnode *funcdef, IRContext *context){
    if(funcdef->ast_type != AST_FUNC_DEF && funcdef->ast_type != AST_FUNC_DEF_MAIN){
        printf("The wrong ASTnode has been given to the function funcDefIR.\n");
        return;
    }


    IRstruct *IRFuncDef = malloc(sizeof(IRstruct));
    if(IRFuncDef == NULL){
        printf("Malloc error in IRfunction.\n");
        context->errors++;
        return;
    }
    IRFuncDef->op = IR_LABEL;
    IRFuncDef->data.label.label_id = context->current_label++;

    emit(IRFuncDef, context);

    blockIR(funcdef->data.func_def.body, context);
}