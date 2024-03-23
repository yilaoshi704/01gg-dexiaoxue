#include "touwenjian.h"

void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = (Node *)malloc(sizeof(Node));
    if (!Q->front) {
        printf("初始化队列失败，内存分配错误\n");
        exit(EXIT_FAILURE);
    }
    Q->front->next = NULL;
    Q->length = 0;
}

void DestoryLQueue(LQueue *Q) {
    ClearLQueue(Q);
    free(Q->front);
    Q->front = Q->rear = NULL;
}

Status IsEmptyLQueue(const LQueue *Q) {
    return Q->front == Q->rear ? TRUE : FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e) {
    if (IsEmptyLQueue(Q)) {
        return FALSE;
    }
    e = Q->front->next->data;
    return TRUE;
}

int LengthLQueue(LQueue *Q) {
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("入队失败，内存分配错误\n");
        return FALSE;
    }
    newNode->data = data;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    Q->length++;
    return TRUE;
}

Status DeLQueue(LQueue *Q) {
    if (IsEmptyLQueue(Q)) {
        return FALSE;
    }
    Node *temp = Q->front->next;
    Q->front->next = temp->next;
    if (Q->rear == temp) {
        Q->rear = Q->front;
    }
    free(temp);
    Q->length--;
    return TRUE;
}

void ClearLQueue(LQueue *Q) {
    while (!IsEmptyLQueue(Q)) {
        DeLQueue(Q);
    }
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
    Node *p = Q->front->next;
    while (p) {
        foo(p->data);
        p = p->next;
    }
    return TRUE;
}

void LPrint(void *q) {
    printf("%s\n", (char *)q); // 这里假设要打印的元素为字符串类型
}

int getInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            // 清空输入缓冲区
            while (getchar() != '\n');
            printf("输入错误，请输入一个整数\n");
        } else {
            // 检查输入缓冲区是否为空
            if (getchar() != '\n') {
                // 清空输入缓冲区
                while (getchar() != '\n');
                printf("输入错误，请输入一个整数\n");
            } else {
                // 输入正确，退出循环
                break;
            }
        }
    }
    return input;
}
