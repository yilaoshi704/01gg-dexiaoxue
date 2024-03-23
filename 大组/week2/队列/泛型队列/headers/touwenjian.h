#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;			
int getInput();
void InitLQueue(LQueue *Q);
void DestoryLQueue(LQueue *Q);
Status IsEmptyLQueue(const LQueue *Q);
Status GetHeadLQueue(LQueue *Q, void *e);
int LengthLQueue(LQueue *Q);
Status EnLQueue(LQueue *Q, void *data);
Status DeLQueue(LQueue *Q);
void ClearLQueue(LQueue *Q);
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));
void LPrint(void *q);
#endif 


