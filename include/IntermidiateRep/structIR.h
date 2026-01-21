#ifndef STRUCTIR_H
#define STRUCTIR_H

typedef struct Operand Operand;
typedef struct IRstruct IRstruct;

typedef enum {
    IR_ADD, IR_SUB, IR_CALL, IR_JMP, IR_LABEL, IR_RET
} IRoperation;

typedef enum {
    IR_VAR, IR_CONST, IR_TMP
} IRtype;

typedef enum {
    IR_INT, IR_STRING, IR_CHAR, IR_BOOL
} CstTypes;

typedef struct {
    IRtype IR_type;
    union {
        struct {
            char *identifier;
        } IR_Variable;
        
        struct {
            CstTypes cst_type;
            union {
                struct {
                    char *string;
                }string;

                struct {
                    int number;
                }number;

                struct {
                    char chr;
                }chr;

                struct {
                    bool boolean;
                }boolean;
            }value;
        } IR_constant;

        struct {
            int id;
        } IR_tmp;
        
    }data; 
} Operand;


typedef struct  {
    IRoperation op;
    Operand dst, src1, src2;
    IRstruct *next;
} IRstruct;


#endif