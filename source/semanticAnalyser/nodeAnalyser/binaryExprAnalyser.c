#include "../include/semanticAnalyser/nodeAnalyser.h"

SemanticType binaryExprAnalyser(ASTnode *binary, SemContext *context){
    SemanticType left = expressionAnalyser(binary->data.binary.left, context);
    SemanticType right = expressionAnalyser(binary->data.binary.right, context);
    if(left == SEM_ERROR || right == SEM_ERROR){
        return SEM_ERROR;
    }

    Tokentype op = binary->data.binary.op;
    if(isCalculus(op)){
        if(left == SEM_INT && right == SEM_INT){
            return SEM_INT;
        }
        printf("Arithmetic operator %s line %d can only take two ints; here left is type %s and right is type %s.\n", tokenTypeToString(binary->data.binary.op), binary->line, fromSemToString(left), fromSemToString(right));
        context->error_count++;
        return SEM_ERROR;
    }
    else if(isBool(op)){
        if(left == SEM_INT && right == SEM_INT){
            return SEM_BOOL;
        }
        printf("Comparaison operator %s line %d can only take two ints; here leftside is type %s and rightside is type %s.\n", tokenTypeToString(binary->data.binary.op), binary->line, fromSemToString(left), fromSemToString(right));
        context->error_count++;
        return SEM_ERROR;
    }
    printf("Unknown binary operator %s at line %d.\n", tokenTypeToString(op), binary->line);
    context->error_count++;
    return SEM_ERROR;

}