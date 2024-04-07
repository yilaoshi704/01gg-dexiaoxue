#include "touwenjian.h"

// 访问节点
void visit(NodePtr node) {
    printf("%d ", node->value);
}

// 初始化二叉排序树
Status BST_init(BinarySortTreePtr BST) {
    BST->root = NULL;
    return succeed;
}

// 辅助函数：在二叉排序树中插入节点
NodePtr insertNode(NodePtr root, ElemType value) {
    if (root == NULL) {
        root = (NodePtr)malloc(sizeof(Node));
        if (root == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        root->value = value;
        root->left = root->right = NULL;
    } else if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// 插入元素
Status BST_insert(BinarySortTreePtr BST, ElemType value) {
    BST->root = insertNode(BST->root, value);
    return succeed;
}

// 辅助函数：在二叉排序树中删除节点
NodePtr deleteNode(NodePtr root, ElemType value) {
    if (root == NULL) {
        return NULL; // 未找到要删除的节点，返回NULL
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // 找到了要删除的节点
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }
        // 找到右子树中的最小节点（后继节点）
        NodePtr temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// 删除元素
Status BST_delete(BinarySortTreePtr BST, ElemType value) {
    if (BST == NULL) {
        return failed; // 如果树为空，删除失败
    }
    BST->root = deleteNode(BST->root, value);
    if (BST->root == NULL) {
        return failed; // 如果删除后的根节点为空，删除失败
    }
    return succeed;
}

// 辅助函数：在二叉排序树中查找元素
Status searchNode(NodePtr root, ElemType value) {
    if (root == NULL) {
        return failed;
    }
    if (root->value == value) {
        return succeed;
    } else if (value < root->value) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// 查找元素
Status BST_search(BinarySortTreePtr BST, ElemType value) {
    return searchNode(BST->root, value);
}

// 辅助函数：先序遍历（非递归）
void preorderIterative(NodePtr root, void (*visit)(NodePtr)) {
    // 使用栈实现先序遍历
    if (root == NULL)
        return;

    NodePtr stack[MAX_STACK_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        NodePtr node = stack[top--];
        visit(node);

        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }
}

// 先序遍历（非递归）
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    preorderIterative(BST->root, visit);
    return succeed;
}

// 先序遍历（递归）
void preorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return;

    visit(root);
    preorderRecursive(root->left, visit);
    preorderRecursive(root->right, visit);
}

Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    preorderRecursive(BST->root, visit);
    return succeed;
}

// 辅助函数：中序遍历（非递归）
void inorderIterative(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return;

    NodePtr stack[MAX_STACK_SIZE];
    int top = -1;
    NodePtr current = root;

    while (current || top >= 0) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        visit(current);
        current = current->right;
    }
}

// 中序遍历（非递归）
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    inorderIterative(BST->root, visit);
    return succeed;
}

// 中序遍历（递归）
void inorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return;

    inorderRecursive(root->left, visit);
    visit(root);
    inorderRecursive(root->right, visit);
}

Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    inorderRecursive(BST->root, visit);
    return succeed;
}

// 辅助函数：后序遍历（非递归）
void postorderIterative(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return;

    NodePtr stack1[MAX_STACK_SIZE];
    NodePtr stack2[MAX_STACK_SIZE];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        NodePtr node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }

    while (top2 >= 0) {
        NodePtr node = stack2[top2--];
        visit(node);
    }
}

// 后序遍历（非递归）
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    postorderIterative(BST->root, visit);
    return succeed;
}

// 辅助函数：后序遍历（递归）
void postorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return;

    postorderRecursive(root->left, visit);
    postorderRecursive(root->right, visit);
    visit(root);
}

// 后序遍历（递归) 
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL) {
        return failed;
    }
    // 调用递归辅助函数进行后序遍历
    postorderRecursive(BST->root, visit);
    return succeed;
}
// 层序遍历
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL || BST->root == NULL) {
        return succeed;
    }

    // 创建一个队列用于层序遍历
    std::queue<NodePtr> q;
    NodePtr node, left, right;

    // 将根节点入队
    q.push(BST->root);

    // 当队列不为空时，进行遍历
    while (!q.empty()) {
        node = q.front();  // 获取队列前端的节点
        q.pop();          // 将队列前端的节点出队

        // 访问当前节点
        visit(node);

        // 如果当前节点有左子节点，将左子节点入队
        if (node->left != NULL) {
            q.push(node->left);
        }

        // 如果当前节点有右子节点，将右子节点入队
        if (node->right != NULL) {
            q.push(node->right);
        }
    }

    return succeed;
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
void menu() {
    int choice;
    int a = -1;
    BinarySortTree BST;
    BST_init(&BST);
    while (1) {
        printf("1. 插入\n2. 删除\n3. 查找\n4. 先序遍历（递归）\n5. 中序遍历（递归）\n6. 后序遍历（递归）\n7. 层序遍历（递归）\n8. 先序遍历（非递归）\n9. 中序遍历（非递归）\n10. 后序遍历（非递归）\n11. 退出\n");
        choice = getInput();
        switch (choice) {
            case 1:
                printf("请输入要插入的值: ");
                int value;
                value = getInput();
                BST_insert(&BST, value);
                break;
            case 2:
    			printf("请输入要删除的值: ");
    			value = getInput();
    			if (BST_delete(&BST, value) == succeed) {
        			printf("删除成功。\n");
    			} else {
        			printf("删除失败！值不存在于树中。\n");
    			}
    			break;
            case 3:
                printf("请输入要查找的值: ");
                value = getInput();
                if (BST_search(&BST, value)) {
                    printf("值已找到。\n");
                } else {
                    printf("值未找到。\n");
                }
                break;
            case 4:
                printf("先序遍历结果（递归）: ");
                BST_preorderR(&BST, visit);
                printf("\n");
                break;
            case 5:
                printf("中序遍历结果（递归）: ");
                BST_inorderR(&BST, visit);
                printf("\n");
                break;
            case 6:
                printf("后序遍历结果（递归）: ");
                BST_postorderR(&BST, visit);
                printf("\n");
                break;
            case 7:
                printf("层序遍历结果（递归）: ");
                BST_levelOrder(&BST, visit);
                printf("\n");
                break;
            case 8:
                printf("先序遍历结果（非递归）: ");
                BST_preorderI(&BST, visit);
                printf("\n");
                break;
            case 9:
                printf("中序遍历结果（非递归）: ");
                BST_inorderI(&BST, visit);
                printf("\n");
                break;
            case 10:
                printf("后序遍历结果（非递归）: ");
                BST_postorderI(&BST, visit);
                printf("\n");
                break;
            case 11:
                printf("程序已退出。\n");
                exit(0);
                break;
            default:
                printf("无效的选择，请重试。\n");
        }
    }
}
