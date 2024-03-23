#include "touwenjian.h" 

//��ʼ������ջ���ÿգ��������� 
Status initLStack(LinkStack *s) {  
    s->top = NULL; 
    s->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) {
    return (s->count == 0) ? SUCCESS : ERROR;
}

Status getTopLStack(LinkStack *s, ElemType *e) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s) {
    while (s->top != NULL) {
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
    }
    s->count = 0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s) {
    clearLStack(s);
    s->top = NULL;
    return SUCCESS;
}

Status LStackLength(LinkStack *s, int *length) {
    *length = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data) {
    LinkStackPtr node = (LinkStackPtr)malloc(sizeof(StackNode));
    node->data = data;
    node->next = s->top;
    s->top = node;
    s->count++;
    return SUCCESS;
}

Status popLStack(LinkStack *s, ElemType *data) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *data = s->top->data;
    LinkStackPtr p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}

Status print(LinkStack* s) {
    LinkStackPtr p = s->top;
    printf("Stack: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return SUCCESS;
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
