//#include<stdio.h>
//#include<stdlib.h>
//#define max(a,b) (a>b)?a:b
////创建平衡二叉树的结构体
//typedef struct Node {
//	int val;//数值
//	int height;//树高
//	struct Node* left;
//	struct Node* right;
//}Node;
////函数生成新的节点，返回值是指向这个节点的指针
//Node* newnode(int val) {//开辟一个新的节点
//	Node* node = (Node*)malloc(sizeof(Node));//自动申请内存
//	node->val = val;
//	node->height = 1;//每次创建一个新的节点都会将这个节点的高度设为1
//	node->left = NULL;
//	node->right = NULL;
//
//	return node;
//}
////获取树高
//int getHeight(Node* node) {
//	if (node == NULL)
//		return 0;
//	return node->height;
//
//}
//
////开始写左旋和右旋
////左旋  当前节点右子树作为新树的根，当前节点作为新树根节点的左子树。
////如果新树跟，有左子树，那么做为旧根节点的右子树
//Node* leftroot(Node* root) {
//	Node* newroot = root->right;
//	Node* t2 = newroot->left;
//
//	newroot->left = root;
//	root->right = t2;
//
//
//
//	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
//	newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));
//
//	return newroot;
//}
////右旋
//Node* rightroot(Node* root) {
//	Node* newroot = root->left;
//	Node* t2 = newroot->right;
//
//	newroot->right = root;
//	root->left = t2;
//
//
//
//	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
//	newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));
//
//	return newroot;
//}
////获得平衡因子
//int getbalance(Node*node)
//{
//	return getHeight(node->left) - getHeight(node->right);
//
//
//}
////定义插入节点
//Node* insertNode(Node* node, int key) {
//	if (node == NULL)
//		return newnode(key);
//	if (key < node->val) 
//		node->left = insertNode(node->left, key);
//	if (key > node->val)
//		node->right = insertNode(node->right, key);
//	else
//		return node;
//
////更新树高
//	node->height = 1 + max(getHeight(node->left) ,getHeight(node->right));
//	//获取当前树的平衡因子，来判断该怎么选择
//
//	int balance = getbalance(node);
//	//写四个失衡
//	//LL
//	if (balance>1&&getbalance(node->left)>0)
//	{
//		return rightroot(node);
//	}
//	//RL
//	if (balance < -1 && getbalance(node->right) > 0)
//	{
//		node->right = rightroot(node->right);
//		return leftroot(node);
//	}
//	//RR
//	if (balance <-1 && getbalance(node->right) < 0)
//	{
//		return leftroot(node);
//	}
//	//LR
//	if (balance > 1 && getbalance(node->left) < 0)
//	{
//		node->left = leftroot(node->left);
//		return rightroot(node);
//	}
//
//
//	return node;
//
//
//}
////定义前序遍历
//void preorder(Node*root) {
//	if (root == NULL)
//		return;
//	printf("%d ",root->val);
//	preorder(root->left);
//	preorder(root->right);
//
//}
//
//
////定义中序遍历
//void midorder(Node* root) {
//	if (root == NULL)
//		return;
//	
//	midorder(root->left);
//printf("%d ", root->val);
//	midorder(root->right);
//
//}
////定义函数查找
//Node* find(Node* root, int key, int* counter) {
//	Node* cur = root;
//	while (cur!=NULL)
//	{
//		if (key < cur->val) {
//			cur = cur->left;
//			(*counter)++;
//		}
//		else if (key > cur->val) {
//			cur = cur->right;
//			(*counter)++;
//		}
//		else 
//			return cur;
//	}
//	//没找到
//	return NULL;
//
//
//}
//
//
//
//void text()
//{
//	Node* root = NULL;
//	root = insertNode(root, 10);
//	root = insertNode(root, 20);
//	root = insertNode(root, 30);
//	root = insertNode(root,40);
//	root = insertNode(root, 50);
//	root = insertNode(root, 60);
//	root = insertNode(root, 70);
//	//root = insertNode(root, 80);
//
//	int counter = 0;
//	Node* result = find(root, 70, &counter);
//
//	printf("找了%d次\n", counter);
//	printf("先序遍历结果\n");
//	preorder(root);
//	printf("\n中序遍历结果\n");
//	midorder(root);
//
//}
//
//int main()
//{
//	text();
//
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a > b) ? a : b;

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
    newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

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
    newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;
}
// 定义函数，获取平衡因子
int getBalance(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
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
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));//依次累加，每有新的树长出来，这个树高就会加高

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

}

int main() {
    test();
    return 0;
}



//这一章节有几个小难点，第一，插入数字
//左旋，其实左旋了也就知道右旋该如何操作了
//左旋，是因为发生了不平恒事件。
// 1. 当前结点的右子树会作为新树的根结点
// 2.当前结点root会作为新树的根结点newroot->left的左子树
//如果，新的树根，原来有左子树，原来的左子树，就作为旧根结点的右子树
//
//
//
//
//





