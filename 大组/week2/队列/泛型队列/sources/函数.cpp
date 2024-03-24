#include "touwenjian.h"

void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = (Node *)malloc(sizeof(Node));
    if (!Q->front) {
        printf("��ʼ������ʧ�ܣ��ڴ�������\n");
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
    memcpy(e, Q->front->next->data, sizeof(void*)); // ʹ��memcpy�����ݿ�����eָ����ڴ�ռ���
    return TRUE;
}

int LengthLQueue(LQueue *Q) {
    return Q->length;
}

// EnLQueue �����Ķ���
Status EnLQueue(LQueue *Q, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("���ʧ�ܣ��ڴ�������\n");
        return FALSE;
    }
    
    // ������������
    const char *charData = static_cast<const char *>(data);  // ��������ת��
    char *dataCopy = strdup(charData);
    if (!dataCopy) {
        printf("���ʧ�ܣ��ַ������ƴ���\n");
        free(newNode);
        return FALSE;
    }
    
    newNode->data = dataCopy;
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
    printf("ֵΪ%s�Ķ�ͷ�Ѿ�����", temp->data);
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
    printf("%s\n", (char *)q); // �������Ҫ��ӡ��Ԫ��Ϊ�ַ�������
}

int getInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            // ������뻺����
            while (getchar() != '\n');
            printf("�������������һ������\n");
        } else {
            // ������뻺�����Ƿ�Ϊ��
            if (getchar() != '\n') {
                // ������뻺����
                while (getchar() != '\n');
                printf("�������������һ������\n");
            } else {
                // ������ȷ���˳�ѭ��
                break;
            }
        }
    }
    return input;
}

void newinput(char *input) {
	input = (char *)malloc(sizeof(char) * MAX_LENGTH);
}
