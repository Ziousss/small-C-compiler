#include "../include/parser/helperFunc.h"

bool isTOKType(Tokentype type){
    if(type != TOK_INT && type != TOK_CHAR && type != TOK_VOID){
        return false;
    }
    return true;
}

ParameterNode *create_param_tree(char *name, Tokentype type, int count){
    ParameterNode *tmp = malloc(sizeof(ParameterNode));
    tmp->next = NULL;
    tmp->count = count;
    tmp->name = name;
    tmp->ret_type = type;
    return tmp;
}

void param_list_add(ParameterNode **head, ParameterNode *param) {
    if(*head == NULL){
        *head = param;
        return;
    }

    ParameterNode *cur = *head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = param;
}

ASTnode *new_stmt_list() {
    ASTnode *tmp = malloc(sizeof(ASTnode));
    tmp->ast_type = AST_STMT_LIST;
    tmp->data.block.stmts = NULL;
    return tmp;
}

void add_stmt_list(ASTnode *list, ASTnode *stmt) {
    ASTnode *tmp = list->data.block.stmts->next;
    while (tmp->data.block.stmts->next)
        tmp = tmp->data.block.stmts->next;

    tmp->data.block.stmts->next = stmt;
}