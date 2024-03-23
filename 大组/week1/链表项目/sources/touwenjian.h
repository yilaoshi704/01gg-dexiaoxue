#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
// 定义双向链表节点结构
typedef struct Node1 {
    int data;
    struct Node1* prev;
    struct Node1* next;
} node1;


// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
}node;

int getInput(); 
node* create(int data);
void instart(node** head, int data);
void inend(node** head, int data);
void inany(node** head, int data, int position);
void deleteany(node** head, int position);
void display(node* head);
void searchnode(node* head, int key);
void swap(node** head);
void findmid(node *head, int n);
void feidigui(node** head);
node* digui(node* head);

node1* create1(int data);
void instart1(node1** head, int data);
void inend1(node1** head, int data);
void inany1(node1** head, int data, int position);
void deleteany1(node1** head, int position);
void display1(node1* head);
void searchnode1(node1* head, int key);

void caidan1();
void caidan2();
