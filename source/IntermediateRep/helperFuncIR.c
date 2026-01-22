#include "../include/IntermediateRep/helperFuncIR.h"

void emit(IRstruct *to_add, IRContext *context){
    to_add->next = NULL;

    if(context->head == NULL){
        context->head = to_add;
        context->tail = to_add;
        return;
    }

    context->tail->next = to_add;
    context->tail = to_add;
}