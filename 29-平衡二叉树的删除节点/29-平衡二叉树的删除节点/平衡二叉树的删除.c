
#include <stdio.h>
#include <stdlib.h>
//#define max(a,b) (a > b) ? a : b;
int max_a(int a, int b)
{
    return (a > b) ? a : b;
}


// �������ṹ
typedef struct Node {
    int val;// ������
    int height;// ����
    struct Node* left;
    struct Node* right;
}Node;

//���庯�������µĽ�㣬����ֵ��ָ���������ָ��
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// ��ȡ���ĸ߶�
int getHeight(Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}



//������������
Node* leftRoate(Node* root) {
    // 1. ��ǰ��������������Ϊ�����ĸ����
    // 2.��ǰ���root����Ϊ�����ĸ����newroot->left��������
    //������µ�������ԭ������������ԭ����������������Ϊ�ɸ�����������
    Node* newroot = root->right;
    // T2����������ԭ����������
    Node* T2 = newroot->left;

    // ��ǰ������Ϊ��������������
    newroot->left = root;
    root->right = T2;

    // �������ߣ�root newroot
    //root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newroot->height = 1 + max_a(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;

}

//������������
// 1. ��ǰ��������������Ϊ�����ĸ����
    // 2.��ǰ���root����Ϊ�����ĸ����newroot->right��������
    //������µ�������ԭ������������ԭ����������������Ϊ�ɸ�����������
Node* rightRotate(Node* root) {
    Node* newroot = root->left;
    Node* T2 = newroot->right;

    newroot->right = root;
    root->left = T2;

    //��������
    //root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newroot->height = 1 + max_a(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;
}
// ���庯������ȡƽ������
int getBalance(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}
//����ɾ���ڵ�
Node* deleteNode(Node* node, int key) {
    if (node == NULL) {
        return node;
    }
    if (key > node->val) {
        node->right = deleteNode(node->right, key);
    }
    else if(key<node->val)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key == node->val) {
//���������
        //û�������Һ���
        if (node->left == NULL && node->right == NULL) {
            Node* temp = node;
            node = NULL;
            free(temp);
        }
        //ֻ��һ�����ӣ�����
        else if (node->left != NULL && node->right == NULL)
        {
            Node* temp = node;
            node = node->left;
            free(temp);

        }
        //ֻ���Һ���
        else if (node->left == NULL && node->right != NULL)
        {
            Node* temp = node;
            node = node->right;
            free(temp);
        
        
        }
        //�����Ӷ���
                else if (node->left != NULL && node->right != NULL) {
                    Node* cur = node->right;//����һ��cur���洢node���Һ���
                    while (cur->left!=NULL)//����cur�����ӣ�ֱ��ΪNULL
                    {
                        cur = cur->left;

                    }
                    node->val = cur->val;//��node�Һ��ӵ����ӵ�����ֵ����node
                    node->right = deleteNode(node->right, cur->val);//����ǰ�潫cur����ԭ�������������󣬶���һ��node-��val��Ҫ����������ɾ�ˣ�cur->val����
                }

    }
    //ɾ����ɣ����濪ʼ����
    if (node == NULL)
    {
        return node;
    }
    //��������
    node->height = 1 + max_a(getHeight(node->left), getHeight(node->right));//�����ۼӣ�ÿ���µ�����������������߾ͻ�Ӹ�

    // ��ȡ��ǰ����ƽ������
    int balance = getBalance(node);
    // �����Ƿ���Ҫ������������ǿ�ƽ�������ǲ��Ǿ���ֵ����1
    // LL��ʧ��
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // LR��ʧ��           ������������ʧ����     L��ǰ��������R��ǰ���Ǹ���
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRoate(node->left);
        return rightRotate(node);

    }

    // RR��ʧ��
    if (balance < -1 && getBalance(node->right) <= 0)//�и���Ϊ0
        return leftRoate(node);

    // RL��ʧ��
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRoate(node);
    }

    return node;

}
// ���������ĺ���
Node* insertNode(Node* node, int key) {
    if (node == NULL)
        return newNode(key);//����Ҫ���õݹ�ԭ������������ΪNULL���½ڵ�

    if (key < node->val)
        node->left = insertNode(node->left, key);
    else if (key > node->val)
        node->right = insertNode(node->right, key);
    else
        return node;

    //��������
    node->height = 1 + max_a(getHeight(node->left), getHeight(node->right));//�����ۼӣ�ÿ���µ�����������������߾ͻ�Ӹ�

    // ��ȡ��ǰ����ƽ������
    int balance = getBalance(node);
    // �����Ƿ���Ҫ������������ǿ�ƽ�������ǲ��Ǿ���ֵ����1
    // LL��ʧ��
    if (balance > 1 && getBalance(node->left) > 0)
        return rightRotate(node);

    // LR��ʧ��           ������������ʧ����     L��ǰ��������R��ǰ���Ǹ���
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRoate(node->left);
        return rightRotate(node);

    }

    // RR��ʧ��
    if (balance < -1 && getBalance(node->right) < 0)
        return leftRoate(node);

    // RL��ʧ��
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRoate(node);
    }

    return node;
}

// �����������
void preOrder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}


// �����������
void midOrder(Node* root) {
    if (root == NULL)
        return;
    midOrder(root->left);
    printf("%d ", root->val);
    midOrder(root->right);
}

// ���庯������
Node* find(Node* root, int key, int* counter) {
    Node* cur = root;
    while (cur != NULL) {
        if (key < cur->val) {
            cur = cur->left;
            (*counter)++;
        }
        else if (key > cur->val) {
            cur = cur->right;
            (*counter)++;
        }
        else
            return cur;
    }
    // ����һȦ��û�ҵ�
    return NULL;

}

void test() {
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 70);

    int counter = 0;
    Node* result = find(root, 70, &counter);
    printf("���˼���:%d\n", counter);
    printf("-------����������--------\n");
    preOrder(root);
    printf("\n-------����������--------\n");
    midOrder(root);
    printf("\n");

    counter = 0;
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    result = find(root, 70, &counter);
    printf("���˼���:%d\n", counter);
    printf("-------����������--------\n");
    preOrder(root);
    printf("\n-------����������--------\n");
    midOrder(root);
    printf("\n");

}

int main() {
    test();
    return 0;
}