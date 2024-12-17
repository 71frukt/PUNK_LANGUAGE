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

enum Operation_enum
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

struct MathOperation
{
    const Operation_enum  num;
    const char           *my_symbol;
    const char           *real_symbol;

    const FuncType       type;                                               // UNARY  / BINARY
    const FuncEntryForm  form;                                               // PREFIX / INFIX в
};

const int OPERATIONS_NUM = 14;

const MathOperation MathOperations[OPERATIONS_NUM] = 
{
    { BOOL_EQ,      "==",   "==",  BINARY, INFIX  },
    { BOOL_NEQ,     "!=",   "!=",  BINARY, INFIX  },
    { BOOL_GREATER, ">",    ">",   BINARY, INFIX  },
    { BOOL_LOWER,   "<",    "<",   BINARY, INFIX  },
    { ADD,          "+",    "+",   BINARY, INFIX  },
    { SUB,          "-",    "-",   BINARY, INFIX  },
    { MUL,          "*",    "*",   BINARY, INFIX  },
    { DIV,          "/",    "/",   BINARY, INFIX  },
    { DEG,          "^",    "^",   BINARY, INFIX  },
  
    { LN,           "��",   "ln",  UNARY,  PREFIX },
    { LOG,          "���",  "log", BINARY, PREFIX },
  
    { SIN,          "���",  "sin", UNARY,  PREFIX },
    { COS,          "���",  "cos", UNARY,  PREFIX },
    { TAN,          "���",  "tg",  UNARY,  PREFIX }
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

#endif