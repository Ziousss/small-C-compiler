#include "../include/IntermediateRep/IRheader.h"

void whileIR(ASTnode *whileStmt, IRContext *context){
    int condLabel = context->current_label++;
    int endLabel = context->current_label++;

    IRstruct *label = newLabel(context, condLabel);
    emit(label, context);

    Operand condition = expressionIR(whileStmt->data.while_node.condition, context);
    IRstruct *goOut = newJmpFalse(context, endLabel, condition);
    emit(goOut, context);

    blockIR(whileStmt->data.while_node.block, context);

    IRstruct *jmpBack = newJmp(context, condLabel);
    IRstruct *endWhile = newLabel(context, endLabel);
    emit(jmpBack, context);
    emit(endWhile, context);
}