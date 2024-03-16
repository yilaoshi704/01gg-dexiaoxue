#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
}node;

// �����½ڵ�
node* create(int data) {
    node* newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// ������ͷ������ڵ�
void instart(node** head, int data) {
    node* newnode = create(data);
    newnode->next = *head;
    *head = newnode;
}

// ������β������ڵ�
void inend(node** head, int data) {
    node* newnode = create(data);
    node* last = *head;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newnode;
}

// ��ָ��λ�ò���ڵ�
void inany(node** head, int data, int position) {
    if (position < 0) {
        printf("��Чλ��\n");
        return;
    }
    if (position == 0) {
        instart(head, data);
        return;
    }
    node* newnode = create(data);
    node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            printf("λ�ó���������\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("λ�ó���������\n");
        return;
    }
    newnode->next = current->next;
    current->next = newnode;
}

// ɾ��ָ��λ�õĽڵ�
void deleteany(node** head, int position) {
    if (*head == NULL) {
        printf("����Ϊ��\n");
        return;
    }
    node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("λ�ó���������\n");
        return;
    }
    node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// ��ʾ�����е����нڵ�
void display(node* head) {
    node* current = head;
    if (current == NULL) {
        printf("����Ϊ��\n");
        return;
    }
    printf("�����еĽڵ�: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ��ѯ�ڵ�
void searchnode(node* head, int key) {
    node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == key) {
            printf("�ڵ� %d ��λ�� %d\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("�ڵ� %d δ�ҵ�\n", key);
}

int main() {
    node* head = NULL;
    int choice, data, position, key;
    do {
        printf("\n������������˵�\n");
        printf("1. ������ͷ������ڵ�\n");
        printf("2. ������β������ڵ�\n");
        printf("3. ��ָ��λ�ò���ڵ�\n");
        printf("4. ɾ��ָ��λ�õĽڵ�\n");
        printf("5. ��ʾ�����е����нڵ�\n");
        printf("6. ��ѯ�ڵ�\n");
        printf("7. �˳�\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("����Ҫ�����ֵ: ");
                scanf("%d", &data);
                instart(&head, data);
                break;
            case 2:
                printf("����Ҫ�����ֵ: ");
                scanf("%d", &data);
                inend(&head, data);
                break;
            case 3:
                printf("����Ҫ�����ֵ: ");
                scanf("%d", &data);
                printf("����Ҫ�����λ��: ");
                scanf("%d", &position);
                inany(&head, data, position);
                break;
            case 4:
                printf("����Ҫɾ����λ��: ");
                scanf("%d", &position);
                deleteany(&head, position);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("����Ҫ��ѯ�Ľڵ�ֵ: ");
                scanf("%d", &key);
                searchnode(head, key);
                break;
            case 7:
                printf("�����˳�\n");
                break;
            default:
                printf("��Чѡ������������\n");
        }
    } while (choice != 7);
    return 0;
}
