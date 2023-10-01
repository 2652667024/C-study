#include<stdio.h>
#include<stdlib.h>
//创建一个二叉树结构体
typedef struct Treenode
{
	char data;
	struct Treenode* left;
	struct Treenode* right;

}Treenode;
//创建一个栈，用来存放读取存入的字符，先进后出原则
typedef struct Stacknode
{
	Treenode* data;//栈的头是二叉树的data
	struct Stacknode* next;//创建一个next指针

}Stacknode;
//写一个二叉树算法
void createTree(Treenode** T, char* data, int* index)
{
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#')
	{
		*T = NULL;

	}
	else
	{
		*T = (Treenode*)malloc(sizeof(Treenode));
		(*T)->data = ch;
		createTree(&((*T)->left), data, index);//递归左子树
		createTree(&((*T)->right), data, index);//递归右字数

	}

}
//初始化栈
Stacknode* initstack()//一个栈头
{
	Stacknode* S = (Stacknode*)malloc(sizeof(Stacknode));
	S->data = NULL;
	S->next = NULL;
	return S;
}
//写一个进栈的操作
void push(Treenode* data, Stacknode* S)
{
	//首先开辟一个栈的空间
	Stacknode* node = (Stacknode*)malloc(sizeof(Stacknode));
	node->data = data;
	//头插法实现进栈
	node->next = S->next;
	S->next = node;
}
//判断栈空
int isempty(Stacknode* S)
{
	if (S->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
//写一个出栈函数，用Stacknode

Stacknode* pop(Stacknode* S)//吧栈传进去
{
	//第一步，先判断是不是栈空，如果空了什么都取不出来
	if (isempty(S))
	{
		return NULL;
	}
	else
	{
		Stacknode* node = S->next;//S头节点指向的下一位给创建的node，node指向的下一个就是原来头指向的下一个。形成闭环
		S->next = node->next;
		return node;

	}

}
void preOrder(Treenode* T)//前序的遍历逻辑
{
	Treenode* node = T;
	Stacknode* S = initstack();
	while (node || !isempty(S))
	{
		if (node)//前序遍历先访问在进栈
		{
			printf("%c ", node->data);
			push(node, S);
			//开始循环遍历，找左边的
			node = node->left;
		}
		else
		{
			node = pop(S)->data;
			node = node->right;

		}
	}


}
void inOrder(Treenode* T)//中序的遍历逻辑
{
	Treenode* node = T;
	Stacknode* S = initstack();
	while (node || !isempty(S))
	{
		if (node)//前序遍历先访问在进栈
		{

			push(node, S);
			//开始循环遍历，找左边的
			node = node->left;
		}
		else
		{
			node = pop(S)->data;
			printf("%c ", node->data);
			node = node->right;

		}
	}
}
int main()
{
	Treenode* T;
	int index = 0;
	char data[] = "ABC####";

	createTree(&T, data, &index);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");

	return 0;
}