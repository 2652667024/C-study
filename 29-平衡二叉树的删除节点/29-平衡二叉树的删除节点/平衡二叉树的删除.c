
#include <stdio.h>
#include <stdlib.h>
//#define max(a,b) (a > b) ? a : b;
int max_a(int a, int b)
{
    return (a > b) ? a : b;
}


// 定义树结构
typedef struct Node {
    int val;// 数据域
    int height;// 树高
    struct Node* left;
    struct Node* right;
}Node;

//定义函数生成新的结点，返回值是指向这个结点的指针
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// 获取树的高度
int getHeight(Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}



//定义左旋函数
Node* leftRoate(Node* root) {
    // 1. 当前结点的右子树会作为新树的根结点
    // 2.当前结点root会作为新树的根结点newroot->left的左子树
    //如果，新的树根，原来有左子树，原来的左子树，就作为旧根结点的右子树
    Node* newroot = root->right;
    // T2保存新树根原来的左子树
    Node* T2 = newroot->left;

    // 当前结点会作为新树根的左子树
    newroot->left = root;
    root->right = T2;

    // 更新树高，root newroot
    //root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newroot->height = 1 + max_a(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;

}

//定义右旋函数
// 1. 当前结点的左子树会作为新树的根结点
    // 2.当前结点root会作为新树的根结点newroot->right的右子树
    //如果，新的树根，原来有右子树，原来的右子树，就作为旧根结点的左子树
Node* rightRotate(Node* root) {
    Node* newroot = root->left;
    Node* T2 = newroot->right;

    newroot->right = root;
    root->left = T2;

    //更新树高
    //root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newroot->height = 1 + max_a(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;
}
// 定义函数，获取平衡因子
int getBalance(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}
//定义删除节点
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
//分情况讨论
        //没有左孩子右孩子
        if (node->left == NULL && node->right == NULL) {
            Node* temp = node;
            node = NULL;
            free(temp);
        }
        //只有一个孩子，左孩子
        else if (node->left != NULL && node->right == NULL)
        {
            Node* temp = node;
            node = node->left;
            free(temp);

        }
        //只有右孩子
        else if (node->left == NULL && node->right != NULL)
        {
            Node* temp = node;
            node = node->right;
            free(temp);
        
        
        }
        //俩孩子都有
                else if (node->left != NULL && node->right != NULL) {
                    Node* cur = node->right;//创建一个cur来存储node的右孩子
                    while (cur->left!=NULL)//遍历cur的左孩子，直到为NULL
                    {
                        cur = cur->left;

                    }
                    node->val = cur->val;//将node右孩子的左孩子的最终值给到node
                    node->right = deleteNode(node->right, cur->val);//我们前面将cur带给原根结点的右子树后，多了一个node-》val，要把这个多余的删了（cur->val）；
                }

    }
    //删除完成，下面开始调整
    if (node == NULL)
    {
        return node;
    }
    //更新树高
    node->height = 1 + max_a(getHeight(node->left), getHeight(node->right));//依次累加，每有新的树长出来，这个树高就会加高

    // 获取当前结点的平衡因子
    int balance = getBalance(node);
    // 我们是否需要调整这个树，是看平衡因子是不是绝对值大于1
    // LL型失衡
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // LR型失衡           左子树的右数失衡了     L在前就是正数R在前就是负数
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRoate(node->left);
        return rightRotate(node);

    }

    // RR型失衡
    if (balance < -1 && getBalance(node->right) <= 0)//有概率为0
        return leftRoate(node);

    // RL型失衡
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRoate(node);
    }

    return node;

}
// 定义插入结点的函数
Node* insertNode(Node* node, int key) {
    if (node == NULL)
        return newNode(key);//很重要利用递归原理开辟左右字数为NULL的新节点

    if (key < node->val)
        node->left = insertNode(node->left, key);
    else if (key > node->val)
        node->right = insertNode(node->right, key);
    else
        return node;

    //更新树高
    node->height = 1 + max_a(getHeight(node->left), getHeight(node->right));//依次累加，每有新的树长出来，这个树高就会加高

    // 获取当前结点的平衡因子
    int balance = getBalance(node);
    // 我们是否需要调整这个树，是看平衡因子是不是绝对值大于1
    // LL型失衡
    if (balance > 1 && getBalance(node->left) > 0)
        return rightRotate(node);

    // LR型失衡           左子树的右数失衡了     L在前就是正数R在前就是负数
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRoate(node->left);
        return rightRotate(node);

    }

    // RR型失衡
    if (balance < -1 && getBalance(node->right) < 0)
        return leftRoate(node);

    // RL型失衡
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRoate(node);
    }

    return node;
}

// 定义先序遍历
void preOrder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}


// 定义中序遍历
void midOrder(Node* root) {
    if (root == NULL)
        return;
    midOrder(root->left);
    printf("%d ", root->val);
    midOrder(root->right);
}

// 定义函数查找
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
    // 找了一圈，没找到
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
    printf("找了几次:%d\n", counter);
    printf("-------先序遍历结果--------\n");
    preOrder(root);
    printf("\n-------中序遍历结果--------\n");
    midOrder(root);
    printf("\n");

    counter = 0;
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    result = find(root, 70, &counter);
    printf("找了几次:%d\n", counter);
    printf("-------先序遍历结果--------\n");
    preOrder(root);
    printf("\n-------中序遍历结果--------\n");
    midOrder(root);
    printf("\n");

}

int main() {
    test();
    return 0;
}