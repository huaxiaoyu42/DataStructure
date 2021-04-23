#ifndef BINARY_TREE
#define BINARY_TREE

#define ElemType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode;


#endif