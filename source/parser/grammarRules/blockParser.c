#include "../include/parser/ast.h"
#include "../include/parser/grammarRules.h"
#include "../include/parser/helperFunc.h"

ASTnode *blockParse(Tokenstruct *tokenList, int *index){
    int i = *index;
    
    if(tokenList[i].type != TOK_LBRACE){
        printf("Expected '{' line %d", tokenList[i].line);
    } ++i;

    ASTnode *stmt_list = new_stmt_list();
    while (tokenList[i].type != TOK_RBRACE)
    {
        int start_i = i;
        if(tokenList[i].type == TOK_IDENTIFIER){
            ASTnode *func_call = funcCallParse(tokenList, &i);
            if(func_call != NULL){
                add_stmt_list(stmt_list, func_call);
                continue;
            }

            ASTnode *assignment = assignementParse(tokenList, &i);
            if(assignment != NULL){
                add_stmt_list(stmt_list, assignment);
                continue;
            }
        } 
        if(isTOKType(tokenList[i].type)){
            ASTnode *declaration = declaParse(tokenList, &i);
            if(declaration != NULL){
                add_stmt_list(stmt_list, declaration);
                continue;
            }
        }
        if(tokenList[i].type == TOK_IF){
            ASTnode *if_stat = ifStatParse(tokenList, &i);
            add_stmt_list(stmt_list, if_stat);
            continue;
        }
        if(tokenList[i].type == TOK_FOR){
            ASTnode *for_stat = forStatParse(tokenList, &i);
            add_stmt_list(stmt_list, for_stat);
            continue;
        }
        if(tokenList[i].type == TOK_WHILE){
            ASTnode *while_stat = whileStatParse(tokenList, &i);
            add_stmt_list(stmt_list, while_stat);
            continue;
        }  
        if(tokenList[i].type == TOK_RETURN){
            ASTnode *return_stat = returnStatParse(tokenList, &i);
            add_stmt_list(stmt_list, return_stat);
            continue;
        }  
        if (i == start_i) {
            printf("Unexpected token '%s' in block at line %d\n or error if error message.",tokenTypeToString(tokenList[i].type), tokenList[i].line);
            return NULL;
        }
    }
    ++i;
    *index = i;
    return stmt_list;
}