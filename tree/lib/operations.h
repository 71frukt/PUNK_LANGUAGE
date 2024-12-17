#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>

#include "tree_elem_t_info.h"

enum FuncEntryForm
{
    PREFIX,
    INFIX
};

enum FuncType
{
    UNARY,
    BINARY
};

enum MathOperation_enum
{
    BOOL_EQ,
    BOOL_NEQ,
    BOOL_GREATER,
    BOOL_LOWER,
    ADD,
    SUB,
    MUL,
    DIV,
    DEG,

    LN,
    LOG,

    SIN,
    COS,
    TAN
};

struct Node;
void PrintAsmForMathOP (Node *math_op, FILE *dest_file);
void PrintAsmCodeForArg(Node *arg,     FILE *dest_file);

struct MathOperation
{
    const MathOperation_enum  num;
    const char           *my_symbol;
    const char           *real_symbol;
    const char           *asm_symbol;

    const FuncType       type;                                               // UNARY  / BINARY
    const FuncEntryForm  form;                                               // PREFIX / INFIX
};

const int OPERATIONS_NUM = 14;

const MathOperation MathOperations[OPERATIONS_NUM] = 
{
    { BOOL_EQ,      "==",   "==",  NULL,  BINARY, INFIX  },
    { BOOL_NEQ,     "!=",   "!=",  NULL,  BINARY, INFIX  },
    { BOOL_GREATER, ">",    ">",   NULL,  BINARY, INFIX  },
    { BOOL_LOWER,   "<",    "<",   NULL,  BINARY, INFIX  },
    { ADD,          "+",    "+",   "ADD", BINARY, INFIX  },
    { SUB,          "-",    "-",   "SUB", BINARY, INFIX  },
    { MUL,          "*",    "*",   "MUL", BINARY, INFIX  },
    { DIV,          "/",    "/",   "DIV", BINARY, INFIX  },
    { DEG,          "^",    "^",   NULL,  BINARY, INFIX  },
  
    { LN,           "��",   "ln",  NULL, UNARY,  PREFIX },
    { LOG,          "���",  "log", NULL, BINARY, PREFIX },
  
    { SIN,          "���",  "sin", "SIN", UNARY,  PREFIX },
    { COS,          "���",  "cos", "COS", UNARY,  PREFIX },
    { TAN,          "���",  "tg",  "TG",  UNARY,  PREFIX }
};

//------------------------------------------------------------------------------------------------------------//

enum Managers_enum
{
    OPEN_BLOCK_BRACKET,
    CLOSE_BLOCK_BRACKET,
    OPEN_EXPR_BRACKET,
    CLOSE_EXPR_BRACKET,
    COMMA,
    EOT
};

struct ManageElem
{
    const Managers_enum  name;
    const char          *my_symbol;
    const char          *real_symbol;
};

const int MANAGE_ELEMS_NUM = 6;

const ManageElem Managers[MANAGE_ELEMS_NUM] = 
{
    { OPEN_BLOCK_BRACKET,  "������_�����", "{"   },
    { CLOSE_BLOCK_BRACKET, "�����_�����",  "}"   },
    { OPEN_EXPR_BRACKET,   "(",            "("   },
    { CLOSE_EXPR_BRACKET,  ")",            ")"   },
    { COMMA,               ",",            ","   },
    { EOT,                 "$",            "EOT" }
};

//------------------------------------------------------------------------------------------------------------//

enum KeyWord_enum
{
    VAR_T_INDICATOR,
    FUNC_T_INDICATOR,
    FUNC_CALL,
    INT_INIT,
    DOUBLE_INIT,
    NEW_EXPR,
    NEW_FUNC,
    ASSIGN,
    IF,
    WHILE,
    RETURN
};

struct KeyWord
{
    const KeyWord_enum  name;
    const char         *my_symbol;
    const char         *real_symbol;
};

const int KEY_WORDS_NUM = 11;

const KeyWord KeyWords[KEY_WORDS_NUM] = 
{
    { VAR_T_INDICATOR,  "���_�",         "var_t"     },
    { FUNC_T_INDICATOR, "����_�",        "func_t"    },
    { FUNC_CALL,        "���",           "func_call" },
    { INT_INIT,         "���",           "int"       },
    { DOUBLE_INIT,      "����",          "double"    },
    { NEW_EXPR,         "�����_������",  "new_line"  },
    { NEW_FUNC,         "�����_�������", "new_func"  },
    { ASSIGN,           "=" ,            "="         },
    { IF,               "����",          "if"        },
    { WHILE,            "����",          "while"     },
    { RETURN,           "���",           "return"    }
};

//---------------------------------------------------------------------------------------------------------------//

enum SymbolMode
{
    MY_CODE_MODE,
    REAL_CODE_MODE
};

const MathOperation *GetOperationBySymbol  (char *sym, SymbolMode mode);
const KeyWord       *GetKeyWordBySymbol    (char *sym, SymbolMode mode);
const ManageElem    *GetManageElemBySymbol (char *sym, SymbolMode mode);

void PrintAsmCodeByNode(Node *node, FILE *dest_file);

#endif