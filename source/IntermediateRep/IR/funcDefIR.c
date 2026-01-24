#include "../include/IntermediateRep/IRheader.h"

void funcDefIR(ASTnode *funcdef, IRContext *context){
    if(funcdef->ast_type != AST_FUNC_DEF && funcdef->ast_type != AST_FUNC_DEF_MAIN){
        printf("The wrong ASTnode has been given to the function funcDefIR.\n");
        return;
    }

    int label = context->current_label++;
    IRstruct *IRFuncDef = newLabel(context, label);
    if(IRFuncDef != NULL){
        emit(IRFuncDef, context);
    }

    blockIR(funcdef->data.func_def.body, context);
}