#include "touwenjian.h" 

// 创建新节点
node1* create1(int data) {
    node1* newnode = (node1*)malloc(sizeof(node1));
    if (newnode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// 在双向链表头部插入节点
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

// 在双向链表尾部插入节点
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

// 在双向链表指定位置插入节点
void inany1(node1** head, int data, int position) {
    if (position < 0) {
        printf("无效位置\n");
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
            printf("位置超出链表长度\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("位置超出链表长度\n");
        return;
    }
    newnode->next = current->next;
    newnode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newnode;
    }
    current->next = newnode;
}

// 删除双向链表指定位置的节点
void deleteany1(node1** head, int position) {
    if (*head == NULL) {
        printf("链表为空\n");
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
        printf("位置超出链表长度\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// 显示双向链表中的所有节点
void display1(node1* head) {
    node1* current = head;
    if (current == NULL) {
        printf("链表为空\n");
        return;
    }
    printf("链表中的节点: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 查询双向链表节点
void searchnode1(node1* head, int key) {
    node1* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == key) {
            printf("节点 %d 在位置 %d\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("节点 %d 未找到\n", key);
}

void caidan2() {
    node1* head = NULL;
    int n = 0;
    int choice, data, position, key;
    do {
        printf("\n双向链表操作菜单\n");
        printf("1. 在链表头部插入节点\n");
        printf("2. 在链表尾部插入节点\n");
        printf("3. 在指定位置插入节点\n");
        printf("4. 删除指定位置的节点\n");
        printf("5. 显示链表中的所有节点\n");
        printf("6. 查询节点\n");
        printf("7. 退出\n");
        printf("请选择操作: ");
        if (scanf("%d", &choice) != 1) {
    		while (getchar() != '\n');
    		printf("输入错误，请输入一个整数\n");
    		continue; // 继续循环，等待用户重新输入
		}
        switch (choice) {
            case 1:
                printf("输入要插入的值: ");
                if (scanf("%d", &data) != 1) {
    			// 清空输入缓冲区
    				while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                instart1(&head, data);
                break;
            case 2:
                printf("输入要插入的值: ");
                if (scanf("%d", &data) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                inend1(&head, data);
                break;
            case 3:
                printf("输入要插入的值: ");
                if (scanf("%d", &data) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                printf("输入要插入的位置: ");
                if (scanf("%d", &position) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                inany1(&head, data, position);
                break;
            case 4:
                printf("输入要删除的位置: ");
                if (scanf("%d", &position) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                deleteany1(&head, position);
                break;
            case 5:
                display1(head);
                break;
            case 6:
                printf("输入要查询的节点值: ");
                if (scanf("%d", &key) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                searchnode1(head, key);
                break;
            case 7:
                printf("程序退出\n");
                break;
            default:
                printf("无效选择，请重新输入\n");
        }
    } while (choice != 7);
    return;
}
