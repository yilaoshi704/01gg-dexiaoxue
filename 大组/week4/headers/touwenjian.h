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
// ���ʽڵ�ĺ�������
void visit(NodePtr node);

// ��ʼ�������������ĺ�������
Status BST_init(BinarySortTreePtr BST);

// �������������������ڶ����������в���ڵ�
NodePtr insertNode(NodePtr root, ElemType value);

// ����Ԫ�صĺ�������
Status BST_insert(BinarySortTreePtr BST, ElemType value);

// �������������������ڶ�����������ɾ���ڵ�
NodePtr deleteNode(NodePtr root, ElemType value);

// ɾ��Ԫ�صĺ�������
Status BST_delete(BinarySortTreePtr BST, ElemType value);

// �������������������ڶ����������в���Ԫ��
Status searchNode(NodePtr root, ElemType value);

// ����Ԫ�صĺ�������
Status BST_search(BinarySortTreePtr BST, ElemType value);

// ����������������������������ǵݹ飩
void preorderIterative(NodePtr root, void (*visit)(NodePtr));

// ����������ǵݹ飩�ĺ�������
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

// ����������ݹ飩�ĺ�������
void preorderRecursive(NodePtr root, void (*visit)(NodePtr));

// ����������ݹ飩�ĺ�������
Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

// ����������������������������ǵݹ飩
void inorderIterative(NodePtr root, void (*visit)(NodePtr));

// ����������ǵݹ飩�ĺ�������
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

// ����������ݹ飩�ĺ�������
void inorderRecursive(NodePtr root, void (*visit)(NodePtr));

// ����������ݹ飩�ĺ�������
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

// �����������������ں���������ǵݹ飩
void postorderIterative(NodePtr root, void (*visit)(NodePtr));

// ����������ǵݹ飩�ĺ�������
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

// ����������ݹ飩�ĺ�������
void postorderRecursive(NodePtr root, void (*visit)(NodePtr));

// ����������ݹ飩�ĺ�������
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

// ��������ĺ�������
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr));

// ��ȡ����ĺ�������
int getInput();

// �˵����ܵĺ�������
void menu();
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
