#include "touwenjian.h"

// ���ʽڵ�
void visit(NodePtr node) {
    printf("%d ", node->value);
}

// ��ʼ������������
Status BST_init(BinarySortTreePtr BST) {
    BST->root = NULL;
    return succeed;
}

// �����������ڶ����������в���ڵ�
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

// ����Ԫ��
Status BST_insert(BinarySortTreePtr BST, ElemType value) {
    BST->root = insertNode(BST->root, value);
    return succeed;
}

// �����������ڶ�����������ɾ���ڵ�
NodePtr deleteNode(NodePtr root, ElemType value) {
    if (root == NULL) {
        return NULL; // δ�ҵ�Ҫɾ���Ľڵ㣬����NULL
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // �ҵ���Ҫɾ���Ľڵ�
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }
        // �ҵ��������е���С�ڵ㣨��̽ڵ㣩
        NodePtr temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// ɾ��Ԫ��
Status BST_delete(BinarySortTreePtr BST, ElemType value) {
    if (BST == NULL) {
        return failed; // �����Ϊ�գ�ɾ��ʧ��
    }
    BST->root = deleteNode(BST->root, value);
    if (BST->root == NULL) {
        return failed; // ���ɾ����ĸ��ڵ�Ϊ�գ�ɾ��ʧ��
    }
    return succeed;
}

// �����������ڶ����������в���Ԫ��
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

// ����Ԫ��
Status BST_search(BinarySortTreePtr BST, ElemType value) {
    return searchNode(BST->root, value);
}

// ��������������������ǵݹ飩
void preorderIterative(NodePtr root, void (*visit)(NodePtr)) {
    // ʹ��ջʵ���������
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

// ����������ǵݹ飩
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    preorderIterative(BST->root, visit);
    return succeed;
}

// ����������ݹ飩
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

// ��������������������ǵݹ飩
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

// ����������ǵݹ飩
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    inorderIterative(BST->root, visit);
    return succeed;
}

// ����������ݹ飩
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

// ��������������������ǵݹ飩
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

// ����������ǵݹ飩
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    postorderIterative(BST->root, visit);
    return succeed;
}

// ��������������������ݹ飩
void postorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return;

    postorderRecursive(root->left, visit);
    postorderRecursive(root->right, visit);
    visit(root);
}

// ����������ݹ�) 
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL) {
        return failed;
    }
    // ���õݹ鸨���������к������
    postorderRecursive(BST->root, visit);
    return succeed;
}
// �������
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    if (BST == NULL || BST->root == NULL) {
        return succeed;
    }

    // ����һ���������ڲ������
    std::queue<NodePtr> q;
    NodePtr node, left, right;

    // �����ڵ����
    q.push(BST->root);

    // �����в�Ϊ��ʱ�����б���
    while (!q.empty()) {
        node = q.front();  // ��ȡ����ǰ�˵Ľڵ�
        q.pop();          // ������ǰ�˵Ľڵ����

        // ���ʵ�ǰ�ڵ�
        visit(node);

        // �����ǰ�ڵ������ӽڵ㣬�����ӽڵ����
        if (node->left != NULL) {
            q.push(node->left);
        }

        // �����ǰ�ڵ������ӽڵ㣬�����ӽڵ����
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
void menu() {
    int choice;
    int a = -1;
    BinarySortTree BST;
    BST_init(&BST);
    while (1) {
        printf("1. ����\n2. ɾ��\n3. ����\n4. ����������ݹ飩\n5. ����������ݹ飩\n6. ����������ݹ飩\n7. ����������ݹ飩\n8. ����������ǵݹ飩\n9. ����������ǵݹ飩\n10. ����������ǵݹ飩\n11. �˳�\n");
        choice = getInput();
        switch (choice) {
            case 1:
                printf("������Ҫ�����ֵ: ");
                int value;
                value = getInput();
                BST_insert(&BST, value);
                break;
            case 2:
    			printf("������Ҫɾ����ֵ: ");
    			value = getInput();
    			if (BST_delete(&BST, value) == succeed) {
        			printf("ɾ���ɹ���\n");
    			} else {
        			printf("ɾ��ʧ�ܣ�ֵ�����������С�\n");
    			}
    			break;
            case 3:
                printf("������Ҫ���ҵ�ֵ: ");
                value = getInput();
                if (BST_search(&BST, value)) {
                    printf("ֵ���ҵ���\n");
                } else {
                    printf("ֵδ�ҵ���\n");
                }
                break;
            case 4:
                printf("�������������ݹ飩: ");
                BST_preorderR(&BST, visit);
                printf("\n");
                break;
            case 5:
                printf("�������������ݹ飩: ");
                BST_inorderR(&BST, visit);
                printf("\n");
                break;
            case 6:
                printf("�������������ݹ飩: ");
                BST_postorderR(&BST, visit);
                printf("\n");
                break;
            case 7:
                printf("�������������ݹ飩: ");
                BST_levelOrder(&BST, visit);
                printf("\n");
                break;
            case 8:
                printf("�������������ǵݹ飩: ");
                BST_preorderI(&BST, visit);
                printf("\n");
                break;
            case 9:
                printf("�������������ǵݹ飩: ");
                BST_inorderI(&BST, visit);
                printf("\n");
                break;
            case 10:
                printf("�������������ǵݹ飩: ");
                BST_postorderI(&BST, visit);
                printf("\n");
                break;
            case 11:
                printf("�������˳���\n");
                exit(0);
                break;
            default:
                printf("��Ч��ѡ�������ԡ�\n");
        }
    }
}
