#include "touwenjian.h" 

// 创建新节点
node* create(int data) {
    node* newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// 在链表头部插入节点
void instart(node** head, int data) {
    node* newnode = create(data);
    newnode->next = *head;
    *head = newnode;
}

// 在链表尾部插入节点
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

// 在指定位置插入节点
void inany(node** head, int data, int position) {
    if (position < 0) {
        printf("无效位置\n");
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
    current->next = newnode;
}

// 删除指定位置的节点
void deleteany(node** head, int position) {
    if (*head == NULL) {
        printf("链表为空\n");
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
        printf("位置超出链表长度\n");
        return;
    }
    node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}


// 显示链表中的所有节点
void display(node* head) {
    node* current = head;
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

// 查询节点
void searchnode(node* head, int key) {
    node* current = head;
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
// 交换相邻节点
void swap(node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return; // 如果链表为空或只有一个节点，则无需交换
    node *prev = NULL;
    node *current = *head;
    node *nextnode = current->next;
    // 将头指针指向第二个节点
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
//找到中点
void findmid(node *head, int n) {
	if (head == NULL) {
		printf("链表为空\n");
		return;
	}
	if (n % 2 == 0) {
		int i = n / 2;
		while (i-- != 1){
			(head) = (head)->next;
		}
		printf("链表中点是第%d个节点和第%d个节点，值为%d %d\n", n/2-1, n/2, (head)->data, (head)->next->data);
	}
	else {
		int i = n /2;
		while (i--) {
			(head) = (head)->next;
		}
		printf("链表中点是第%d个节点，值为%d\n", n/2, (head)->data);
	}
	return;
}
//反转链表
// 非递归版本：反转链表
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
    *head = prev; // 更新头指针
    return;
}

// 递归版本：反转链表
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
        printf("\n单向链表操作菜单（默认从第0个结点开始）\n");
        printf("1. 在链表头部插入节点\n");
        printf("2. 在链表尾部插入节点\n");
        printf("3. 在指定位置插入节点\n");
        printf("4. 删除指定位置的节点\n");
        printf("5. 显示链表中的所有节点\n");
        printf("6. 查询节点\n");
        printf("7. 交换奇偶节点\n");
        printf("8. 找到中点\n");
        printf("9. 非递归反转\n"); 
        printf("10. 递归反转\n");
        printf("11. 退出\n");
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
				n++;
				instart(&head, data);
				break; 
            case 2:
                printf("输入要插入的值: ");
                if (scanf("%d", &data) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                n++;
                inend(&head, data);
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
                n++;
                inany(&head, data, position);
                break;
            case 4:
                printf("输入要删除的位置: ");
                if (scanf("%d", &position) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
				}
                n--;
                deleteany(&head, position);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("输入要查询的节点值: ");
                if (scanf("%d", &key) != 1) {
        			while (getchar() != '\n');
    				printf("输入错误，请输入一个整数\n");
    				continue; // 继续循环，等待用户重新输入
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
                printf("程序退出\n");
                break;
            default:
                printf("无效选择，请重新输入\n");
        }
    } while (choice != 11);
    return;
} 
