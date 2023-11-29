#include<stdio.h>
#include<stdlib.h>
typedef struct BSTtree {
	int data;
	struct BSTtree* left;
	struct BSTtree* right;

}BSTtree;

void insert(BSTtree** T, int data) {
	if (*T == NULL) {
		BSTtree* node = (BSTtree*)malloc(sizeof(BSTtree));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		*T = node;
	}
	else {
		if ((*T)->data > data) {
			insert((&(*T)->left), data);

		}
		else {
			insert((&(*T)->right), data);

		}
	}
}
//中序遍历
void midtree(BSTtree* T) {
	if (T == NULL) {
		return;
	}
	else
	{
		midtree(T->left);
		printf("%d ", T->data);
		midtree(T->right);
	}

}
//搜索节点
BSTtree* search(BSTtree* T,int val) {
	//下面是递归搜索需要的节点做法，我们继续写一个迭代的代码
	/*if (T == NULL)
	{
		return NULL;
	}
	if (T->data > val) {
		search(T->left, val);
	}
	else if (T->data < val) {
		search(T->right, val);
	}
	else if (T->data == val) {
		return T;
	}	
	else {
		return NULL;
	}*/
	//迭代的用法，创建一个新的节点，判断这个节点赋值之后是否存在。
	BSTtree* cur = T;//将头结点赋给cur
	while (cur != NULL) {//判断cur不为空 
		if (cur->data > val) {
			cur = cur->left;
		}
		else if (cur->data < val) {
			cur = cur->right;
		}
		else if(cur->data == val) {
			return cur;
		}
	
	}
	return NULL;//都不是那么就为空

}

int main()
{
	BSTtree* T = NULL;
	int data;
	for (int i = 0; i < 6; i++)
	{
		printf("请输入数字:");
		scanf("%d", &data);
		insert(&T, data);
	}
	printf("\n");
	midtree(T);
	printf("\n");

	BSTtree* node = search(T, 8);//本意就是这个节点再经过递归判断后是不是空
	if (node == NULL) {
		printf("没有找到\n");
	}
	else {
		printf("%d", node->data);
	}

	return 0;
}