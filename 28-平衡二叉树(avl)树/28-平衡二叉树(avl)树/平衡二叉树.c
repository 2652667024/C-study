//#include<stdio.h>
//#include<stdlib.h>
//#define max(a,b) (a>b)?a:b
////����ƽ��������Ľṹ��
//typedef struct Node {
//	int val;//��ֵ
//	int height;//����
//	struct Node* left;
//	struct Node* right;
//}Node;
////���������µĽڵ㣬����ֵ��ָ������ڵ��ָ��
//Node* newnode(int val) {//����һ���µĽڵ�
//	Node* node = (Node*)malloc(sizeof(Node));//�Զ������ڴ�
//	node->val = val;
//	node->height = 1;//ÿ�δ���һ���µĽڵ㶼�Ὣ����ڵ�ĸ߶���Ϊ1
//	node->left = NULL;
//	node->right = NULL;
//
//	return node;
//}
////��ȡ����
//int getHeight(Node* node) {
//	if (node == NULL)
//		return 0;
//	return node->height;
//
//}
//
////��ʼд����������
////����  ��ǰ�ڵ���������Ϊ�����ĸ�����ǰ�ڵ���Ϊ�������ڵ����������
////�����������������������ô��Ϊ�ɸ��ڵ��������
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
////����
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
////���ƽ������
//int getbalance(Node*node)
//{
//	return getHeight(node->left) - getHeight(node->right);
//
//
//}
////�������ڵ�
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
////��������
//	node->height = 1 + max(getHeight(node->left) ,getHeight(node->right));
//	//��ȡ��ǰ����ƽ�����ӣ����жϸ���ôѡ��
//
//	int balance = getbalance(node);
//	//д�ĸ�ʧ��
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
////����ǰ�����
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
////�����������
//void midorder(Node* root) {
//	if (root == NULL)
//		return;
//	
//	midorder(root->left);
//printf("%d ", root->val);
//	midorder(root->right);
//
//}
////���庯������
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
//	//û�ҵ�
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
//	printf("����%d��\n", counter);
//	printf("����������\n");
//	preorder(root);
//	printf("\n����������\n");
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
    newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

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
    newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;
}
// ���庯������ȡƽ������
int getBalance(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
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
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));//�����ۼӣ�ÿ���µ�����������������߾ͻ�Ӹ�

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

}

int main() {
    test();
    return 0;
}



//��һ�½��м���С�ѵ㣬��һ����������
//��������ʵ������Ҳ��֪����������β�����
//����������Ϊ�����˲�ƽ���¼���
// 1. ��ǰ��������������Ϊ�����ĸ����
// 2.��ǰ���root����Ϊ�����ĸ����newroot->left��������
//������µ�������ԭ������������ԭ����������������Ϊ�ɸ�����������
//
//
//
//
//





