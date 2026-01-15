#ifndef STRUCT_H
#define STRUCT_H

typedef struct SymbolNode SymbolNode;
typedef struct ScopeNode ScopeNode;
typedef struct SemContext SemContext;

typedef enum {
    SEM_INT, SEM_CHAR, SEM_STRING, SEM_VOID, SEM_ERROR
} SemanticType;

typedef enum {
    SEM_FCT, SEM_PARAM, SEM_VAR
} SemanticKind;

typedef struct {
    SemanticType type;
    SemanticKind kind;
    char *name;

    int param_count;
    SemanticType *param;

    SymbolNode *next;
} SymbolNode;

typedef struct {
    ScopeNode *parent;
    SymbolNode *symbols;
} ScopeNode;

typedef struct {
    ScopeNode *current_node;
    SymbolNode *current_function;
    int error_count;
} SemContext;

#endif