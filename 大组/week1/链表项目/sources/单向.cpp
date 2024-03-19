#include "touwenjian.h" 

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
// �������ڽڵ�
void swap(node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬�����轻��
    node *prev = NULL;
    node *current = *head;
    node *nextnode = current->next;
    // ��ͷָ��ָ��ڶ����ڵ�
    *head = nextnode;
    while (current != NULL && nextnode != NULL) {
        current->next = nextnode->next;
        nextnode->next = current;
        if (prev != NULL) {
            prev->next = nextnode;
        }
        prev = current;
        current = current->next;
        if (current != NULL) {
            nextnode = current->next;
        }
    }
}
//�ҵ��е�
void findmid(node *head, int n) {
	if (head == NULL) {
		printf("����Ϊ��\n");
		return;
	}
	if (n % 2 == 0) {
		int i = n / 2;
		while (i-- != 1){
			(head) = (head)->next;
		}
		printf("�����е��ǵ�%d���ڵ�͵�%d���ڵ㣬ֵΪ%d %d\n", n/2-1, n/2, (head)->data, (head)->next->data);
	}
	else {
		int i = n /2;
		while (i--) {
			(head) = (head)->next;
		}
		printf("�����е��ǵ�%d���ڵ㣬ֵΪ%d\n", n/2, (head)->data);
	}
	return;
}
//��ת����
// �ǵݹ�汾����ת����
void feidigui(node** head) {
    node *prev = NULL;
    node *current = *head;
    node *nextnode = NULL;
    while (current != NULL) {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    *head = prev; // ����ͷָ��
    return;
}

// �ݹ�汾����ת����
node* digui(node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* newhead = digui(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
} 
void caidan1(){
	node* head = NULL;
	int n = 0;
    int choice, data, position, key;
    do {
        printf("\n������������˵���Ĭ�ϴӵ�0����㿪ʼ��\n");
        printf("1. ������ͷ������ڵ�\n");
        printf("2. ������β������ڵ�\n");
        printf("3. ��ָ��λ�ò���ڵ�\n");
        printf("4. ɾ��ָ��λ�õĽڵ�\n");
        printf("5. ��ʾ�����е����нڵ�\n");
        printf("6. ��ѯ�ڵ�\n");
        printf("7. ������ż�ڵ�\n");
        printf("8. �ҵ��е�\n");
        printf("9. �ǵݹ鷴ת\n"); 
        printf("10. �ݹ鷴ת\n");
        printf("11. �˳�\n");
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
				n++;
				instart(&head, data);
				break; 
            case 2:
                printf("����Ҫ�����ֵ: ");
                if (scanf("%d", &data) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                n++;
                inend(&head, data);
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
                n++;
                inany(&head, data, position);
                break;
            case 4:
                printf("����Ҫɾ����λ��: ");
                if (scanf("%d", &position) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                n--;
                deleteany(&head, position);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("����Ҫ��ѯ�Ľڵ�ֵ: ");
                if (scanf("%d", &key) != 1) {
        			while (getchar() != '\n');
    				printf("�������������һ������\n");
    				continue; // ����ѭ�����ȴ��û���������
				}
                searchnode(head, key);
                break;
            case 7:
				swap(&head);
				break; 
			case 8:
				findmid(head, n); 
				break;
			case 9:
				feidigui(&head); 
				break;
			case 10:
				head = digui(head); 
				break;
            case 11:
                printf("�����˳�\n");
                break;
            default:
                printf("��Чѡ������������\n");
        }
    } while (choice != 11);
    return;
} 
