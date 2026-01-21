#include "../include/IntermidiateRep/IRheader.h"

void programIR(ASTnode *program){
    if(program->ast_type != AST_PROGRAM){
        printf("Given AST is not the program AST.\n");
        return;
    }

    ASTnode *funcdef = program->data.program_node.func_def;
    while(funcdef != NULL){
        funcDefIR(funcdef);
        funcdef = funcdef->next;
    }

    return;
}