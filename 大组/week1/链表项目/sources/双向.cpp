#include "touwenjian.h" 

// �����½ڵ�
node1* create1(int data) {
    node1* newnode = (node1*)malloc(sizeof(node1));
    if (newnode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// ��˫������ͷ������ڵ�
void instart1(node1** head, int data) {
    node1* newnode = create1(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        (*head)->prev = newnode;
        newnode->next = *head;
        *head = newnode;
    }
}

// ��˫������β������ڵ�
void inend1(node1** head, int data) {
    node1* newnode = create1(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        node1* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
        newnode->prev = last;
    }
}

// ��˫������ָ��λ�ò���ڵ�
void inany1(node1** head, int data, int position) {
    if (position < 0) {
        printf("��Чλ��\n");
        return;
    }
    if (position == 0) {
        instart1(head, data);
        return;
    }
    node1* newnode = create1(data);
    node1* current = *head;
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
    newnode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newnode;
    }
    current->next = newnode;
}

// ɾ��˫������ָ��λ�õĽڵ�
void deleteany1(node1** head, int position) {
    if (*head == NULL) {
        printf("����Ϊ��\n");
        return;
    }
    node1* temp = *head;
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("λ�ó���������\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// ��ʾ˫�������е����нڵ�
void display1(node1* head) {
    node1* current = head;
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

// ��ѯ˫������ڵ�
void searchnode1(node1* head, int key) {
    node1* current = head;
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

void caidan2() {
    node1* head = NULL;
    int n = 0;
    int choice, data, position, key;
    do {
        printf("\n˫����������˵�\n");
        printf("1. ������ͷ������ڵ�\n");
        printf("2. ������β������ڵ�\n");
        printf("3. ��ָ��λ�ò���ڵ�\n");
        printf("4. ɾ��ָ��λ�õĽڵ�\n");
        printf("5. ��ʾ�����е����нڵ�\n");
        printf("6. ��ѯ�ڵ�\n");
        printf("7. �˳�\n");
        printf("��ѡ�����: ");
        if (scanf("%d", &choice) != 1) {
    		while (getchar() != '\n');
    		printf("�������������һ������\n");
    		continue; // ����ѭ�����ȴ��û���������
		}
        switch (choice) {
            case 1:
                printf("����Ҫ�����ֵ: ");
                if (scanf("%d", &data) != 1) {
    			// ������뻺����
    				while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                instart1(&head, data);
                break;
            case 2:
                printf("����Ҫ�����ֵ: ");
                if (scanf("%d", &data) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                inend1(&head, data);
                break;
            case 3:
                printf("����Ҫ�����ֵ: ");
                if (scanf("%d", &data) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                printf("����Ҫ�����λ��: ");
                if (scanf("%d", &position) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                inany1(&head, data, position);
                break;
            case 4:
                printf("����Ҫɾ����λ��: ");
                if (scanf("%d", &position) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                deleteany1(&head, position);
                break;
            case 5:
                display1(head);
                break;
            case 6:
                printf("����Ҫ��ѯ�Ľڵ�ֵ: ");
                if (scanf("%d", &key) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                searchnode1(head, key);
                break;
            case 7:
                printf("�����˳�\n");
                break;
            default:
                printf("��Чѡ������������\n");
        }
    } while (choice != 7);
    return;
}
