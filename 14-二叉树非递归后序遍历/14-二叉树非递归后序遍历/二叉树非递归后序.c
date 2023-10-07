#include<stdio.h>
#include<stdlib.h>
typedef struct Treenode
{
	char data;
	struct Treenode* left;
	struct Treenode* right;
	int flag;//创建一个结点，用来记录某一个元素有没有被访问过。例如，我们写了一个B。左是空右是D，这个D在后序遍历里面会不会出栈再进栈（麻烦），得记录一下

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
		(*T)->flag= 0;//初始化的操作，结点在初始化的时候都是没有访问过的
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
Stacknode* gettop(Stacknode* S)//把栈传进去
{
	//第一步，先判断是不是栈空，如果空了什么都取不出来
	if (isempty(S))
	{
		return NULL;
	}
	else
	{
		Stacknode* node = S->next;//把头指向的下一个直接作为node；返回也就是访问过一次的元素（不做出栈操作）
		return node;

	}

}
void postorder(Treenode* T)
{
	Treenode* node = T;//把根节点的值接过来
	Stacknode* S = initstack();//新建一个栈
	while (node || !isempty(S))//当node不为空或者栈不为空
	{
		if (node)//不为空
		{
			push(node, S);//进栈
			node = node->left;//此时node去找左节点

		}
		else//如果左孩子为空
		{
			//这个时候要出栈了，
			Treenode* top = gettop(S)->data;//写一个接口，拿到栈的元素
			if (top->right && top->right->flag == 0)//右子树不是空并且右子树没有被访问过
			{
				
				top = top->right;
				push(top, S);//将右子树进栈
				node = top->left;//这时候node是top指向的左孩子，继续判断左右孩子和是否为空
			}
			else//如果为空
			{
				top = pop(S)->data;//top就变成了要出栈的那个元素
				printf("%c ", top->data);//打印这个元素
				top->flag = 1;//并且此时top标记1，说明已经访问过了，后面不会再寻找她了
			}
		}

	}


}
int main()
{
	Treenode* T;
	int index = 0;
	char data[] = "ABD#E##F##C##";
	createTree(&T,data,&index);
	postorder(T);
	return 0;
}
//国庆快乐，假期之后第一更