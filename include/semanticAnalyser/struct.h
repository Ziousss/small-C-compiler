#ifndef STRUCT_H
#define STRUCT_H

typedef struct symbolNode symbolNode;

typedef enum {
    SEM_INT, SEM_CHAR, SEM_STRING, SEM_VOID, SEM_ERROR
} semanticType;

typedef enum {
    SEM_FCT, SEM_PARAM, SEM_VAR
} semanticKind;

typedef struct {
    semanticType type;
    semanticKind kind;
    char *name;

    int param_count;
    semanticType *param;

    symbolNode *next;
} symbolNode;

#endif