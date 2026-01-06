#include "../include/parser/helperFunc.h"

bool isTOKType(Tokentype type){
    if(type != TOK_INT && type != TOK_CHAR && type != TOK_VOID){
        return false;
    }
    return true;
}

ASTnode *create_param_tree(char *name, Tokentype type, int count){
    ASTnode *tmp = malloc(sizeof(ASTnode));
    tmp->type = AST_PARAM_DECL;
    tmp->data.parameter.data.param_decla.type = type;
    tmp->data.parameter.data.param_decla.name = name;
    tmp->data.parameter.data.param_decla.count = count;
    tmp->data.parameter.next = NULL;
    return tmp;
}

ASTnode *new_param_list() {
    ASTnode *tmp = malloc(sizeof(ASTnode));
    tmp->type = AST_PARAM_LIST;
    tmp->data.parameter.data.param_list.first = NULL;
    tmp->data.parameter.next = NULL;
    return tmp;
}

void param_list_add(ASTnode *list, ASTnode *param) {
    if (!list->data.parameter.data.param_list.first) {
        list->data.parameter.data.param_list.first = param;
        return;
    }

    ASTnode *tmp = list->data.parameter.data.param_list.first;
    while (tmp->data.parameter.next)
        tmp = tmp->data.parameter.next;

    tmp->data.parameter.next = param;
}