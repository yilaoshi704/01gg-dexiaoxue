#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
#define MAX_STACK_SIZE 200
typedef int ElemType;
typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root = NULL;
} BinarySortTree, *BinarySortTreePtr;
// 访问节点的函数声明
void visit(NodePtr node);

// 初始化二叉排序树的函数声明
Status BST_init(BinarySortTreePtr BST);

// 辅助函数声明，用于在二叉排序树中插入节点
NodePtr insertNode(NodePtr root, ElemType value);

// 插入元素的函数声明
Status BST_insert(BinarySortTreePtr BST, ElemType value);

// 辅助函数声明，用于在二叉排序树中删除节点
NodePtr deleteNode(NodePtr root, ElemType value);

// 删除元素的函数声明
Status BST_delete(BinarySortTreePtr BST, ElemType value);

// 辅助函数声明，用于在二叉排序树中查找元素
Status searchNode(NodePtr root, ElemType value);

// 查找元素的函数声明
Status BST_search(BinarySortTreePtr BST, ElemType value);

// 辅助函数声明，用于先序遍历（非递归）
void preorderIterative(NodePtr root, void (*visit)(NodePtr));

// 先序遍历（非递归）的函数声明
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 先序遍历（递归）的函数声明
void preorderRecursive(NodePtr root, void (*visit)(NodePtr));

// 先序遍历（递归）的函数声明
Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 辅助函数声明，用于中序遍历（非递归）
void inorderIterative(NodePtr root, void (*visit)(NodePtr));

// 中序遍历（非递归）的函数声明
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 中序遍历（递归）的函数声明
void inorderRecursive(NodePtr root, void (*visit)(NodePtr));

// 中序遍历（递归）的函数声明
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 辅助函数声明，用于后序遍历（非递归）
void postorderIterative(NodePtr root, void (*visit)(NodePtr));

// 后序遍历（非递归）的函数声明
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 后序遍历（递归）的函数声明
void postorderRecursive(NodePtr root, void (*visit)(NodePtr));

// 后序遍历（递归）的函数声明
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 层序遍历的函数声明
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr));

// 获取输入的函数声明
int getInput();

// 菜单功能的函数声明
void menu();
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
