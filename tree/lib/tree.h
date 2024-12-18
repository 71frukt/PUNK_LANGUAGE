#ifndef DIFF_TREE_H
#define DIFF_TREE_H

#include <stdio.h>

#define TREE_DEBUG

#include "tree_elem_t_info.h"

#include "operations.h"

const int TREE_ALLOC_MARKS_NUM = 20;
const int START_TREE_SIZE      = 100;
const int TOKEN_LEN            = 50;

const int START_NAMES_TABLE_CAPA = 10;

const TreeElem_t POISON_VAL = 0xDEB11;

#define LEFT_MARK      "L"
#define RIGHT_MARK     "R"
#define UNIQ_ARG_MARK  "U"
#define POISON_SYMBOL  "POISON"

#ifdef TREE_DEBUG
#define ON_TREE_DEBUG(...)  __VA_ARGS__
#else
#define ON_TREE_DEBUG(...)
#endif

const size_t NODE_TYPES_COUNT = 9;

enum NodeType
{
    NUM,
    VAR,
    FUNC,
    VAR_OR_FUNC,
    MATH_OP,
    KEY_WORD,
    MANAGER,
    NEW_BLOCK,

    POISON_TYPE,
};

struct ProperName
{
    size_t number;
    char   name[TOKEN_LEN];
};

struct NamesTable
{
    ProperName *names;
    size_t size;
    size_t capacity;
};

#define NEW_BLOCK_SYM  "new_block"

struct Block
{
    NamesTable names_table;
    Node *prev_block;

    size_t shift;   // ���������� �������� ������������ ������� ����� (����� �������)
};

union NodeVal
{
    TreeElem_t           num;
    ProperName          *prop_name;
    Block                block;
    const MathOperation *math_op;
    const KeyWord       *key_word;
    const ManageElem    *manager;
};

struct Node
{
    NodeType type;
    NodeVal  val;

    Node    *left;
    Node    *right;

    size_t born_line;
    size_t born_column;
};


struct TreeAllocMarks
{
    Node   *data[TREE_ALLOC_MARKS_NUM];
    size_t  size;
};

struct Tree
{
    Node **node_ptrs;
    Node *root_ptr;
    Node *cur_block;

    size_t capacity;
    size_t size;

    NamesTable names_table;

    TreeAllocMarks alloc_marks;

    ON_TREE_DEBUG(const char *name);
};

void    TreeCtor      (Tree *tree, size_t start_capacity ON_TREE_DEBUG(, const char *name));
void    TreeDtor      (Tree *tree);
void    TreeRecalloc  (Tree *tree, size_t new_capacity);
Node   *NewNode       (Tree *tree, NodeType type, NodeVal val, Node *left, Node *right);
void    RemoveNode    (Tree *tree, Node **node);
void    RemoveSubtree (Tree *tree, Node **start_node);
Node   *TreeCopyPaste (Tree *source_tree, Tree *dest_tree, Node *coping_node);
size_t  GetTreeHeight (Node *cur_node);
char   *NodeValToStr  (Node *node);

ProperName *FindNameInTable (NamesTable *table, char *name);
ProperName *FindNameInBlock (Node   *cur_block, char *name);
ProperName *NewNameInTable  (NamesTable *table, char *name);

void GetBlockNamesTable       (Tree *tree, Node *block, Node *cur_node);
void MakeNamesTablesForBlocks (Tree *tree, Node *cur_node);

Node *GetNodeInfoBySymbol(char *sym, Tree *tree, Node *cur_node, SymbolMode mode);

void    NamesTableCtor  (size_t start_capa, NamesTable *table);
void    NamesTableDtor  (NamesTable *table);

bool    SubtreeContainsType   (Node *cur_node, NodeType type);
bool    OpNodeIsCommutativity (Node *op_node);
bool    IsInitialise          (Node *node);
bool    IsBool                (Node *node);

#endif