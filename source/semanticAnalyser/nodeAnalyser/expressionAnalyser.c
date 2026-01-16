#include "../include/semanticAnalyser/nodeAnalyser.h"

SemanticType expressionAnalyser(ASTnode *expressionAst, SemContext *context){
    Tokentype type = expressionAst->ast_type;
    switch (type){
        case AST_IDENTIFIER: {
            SymbolNode *identifier =  find_in_scope(expressionAst->data.identifier.name);
            if (identifier == NULL){
                printf("Identifier %s line %d not defined yet.\n", expressionAst->data.identifier.name, expressionAst->line);
                context->error_count += 1;
                return SEM_ERROR;
            }
            SemanticType identifier_type = identifier->type;
            return identifier_type;
        }

        case AST_NUMBER:            return SEM_INT;
        case AST_STRING_LITERAL:    return SEM_STRING;
        case AST_CHAR_LITERAL:      return SEM_CHAR;
        case AST_BOOLEAN:           return SEM_BOOL;

        case AST_BINARY_EXPR: {
            SemanticType left = expressionAnalyser(expressionAst->data.binary.left, context);
            SemanticType right = expressionAnalyser(expressionAst->data.binary.left, context);

            if(left != right){
                printf("In the binary expression line %d, the type on the left %s is not the same as on the right with %s.\n", expressionAst->line, fromSemToString(left), fromSemToString(right));
                context->error_count++;
                return SEM_ERROR;
            }

            return left;
        }

        case AST_FUNC_CALL: {
            SemanticType call_type = funcCallAnalyser(expressionAst, context);
            return call_type;
        }
    }
}