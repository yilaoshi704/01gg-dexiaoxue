#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点结构
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} node;

// 创建新节点
node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
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
void instart(node** head, int data) {
    node* newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        (*head)->prev = newnode;
        newnode->next = *head;
        *head = newnode;
    }
}

// 在双向链表尾部插入节点
void inend(node** head, int data) {
    node* newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
        newnode->prev = last;
    }
}

// 在双向链表指定位置插入节点
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
    newnode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newnode;
    }
    current->next = newnode;
}

// 删除双向链表指定位置的节点
void deleteany(node** head, int position) {
    if (*head == NULL) {
        printf("链表为空\n");
        return;
    }
    node* temp = *head;
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

// 查询双向链表节点
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

int main() {
    node* head = NULL;
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
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("输入要插入的值: ");
                scanf("%d", &data);
                instart(&head, data);
                break;
            case 2:
                printf("输入要插入的值: ");
                scanf("%d", &data);
                inend(&head, data);
                break;
            case 3:
                printf("输入要插入的值: ");
                scanf("%d", &data);
                printf("输入要插入的位置: ");
                scanf("%d", &position);
                inany(&head, data, position);
                break;
            case 4:
                printf("输入要删除的位置: ");
                scanf("%d", &position);
                deleteany(&head, position);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("输入要查询的节点值: ");
                scanf("%d", &key);
                searchnode(head, key);
                break;
            case 7:
                printf("程序退出\n");
                break;
            default:
                printf("无效选择，请重新输入\n");
        }
    } while (choice != 7);
    return 0;
}
