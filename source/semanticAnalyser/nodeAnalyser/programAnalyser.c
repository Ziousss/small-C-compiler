#include "../include/semanticAnalyser/nodeAnalyser.h"

void programAnalyser(ASTnode *program){
    if(program == NULL || program->ast_type != AST_PROGRAM){
        printf("This is not a program ast, check the given ast.\n");
        return;
    }

    static symbolNode stack_scope;
    ASTnode *func_def_node = program->data.program_node.func_def;
    ASTnode *tmp = program->data.program_node.func_def;
    while (func_def_node != 0)
    {
        funcDefAnalyser(func_def_node);
        func_def_node = func_def_node->next;
    } 

    return;
}