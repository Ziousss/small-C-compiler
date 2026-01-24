#include "../include/IntermediateRep/IRheader.h"

void forIR(ASTnode *forStmt, IRContext *context){
    //initialisation
    blockIR(forStmt->data.for_node.initialisation, context);

    //condition
    int condition_label = context->current_label++;
    int end_label = context->current_label++;

    IRstruct *label = newLabel(context, condition_label);
    emit(label, context);

    Operand condition = expressionIR(forStmt->data.for_node.condition, context);
    IRstruct *condIR = newJmpFalse(context, end_label, condition);
    emit(condIR, context);

    //body of the for loop
    blockIR(forStmt->data.for_node.block, context);

    //incrementation, block because assignment and declaration are in blockIR
    blockIR(forStmt->data.for_node.incrementation, context);

    IRstruct *jumpBack = newJmp(context, condition_label);
    IRstruct *forEnd = newLabel(context, end_label);
    emit(jumpBack, context);
    emit(forEnd, context);
}