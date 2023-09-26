#include<stdio.h>
#include<stdlib.h>

typedef struct treenode//定义treenode节点
{
	char data;//存放ABCDE。
	struct tree* lchild;
	struct tree* rchild;

}treenode;
//判断根结点有没有孩子
//前序，根-》左-》右
//中序，左-》根-》右
//后序，左-》右-》根
// 三种遍历方式，（简单的）
//创建二叉树,
void createtree(treenode** T,char* data,int* index)//这里用到二级指针是因为树创建他的孩子时候，需要使用二级指针指向他们的数据域和指针域。
{
//创建二叉树的逻辑
	char ch;//ch保存data里面的数据
	ch = data[*index];//index是为了控制全局变量，
	*index += 1;//*index改变索引值，
	//定义一个规则，
	if (ch == '#')
	{
    //此时为空节点。
		*T = NULL;
	}
	else
	{
		//此时不为空
		*T = (treenode*)malloc(sizeof(treenode));
		(*T)->data = ch;
		//创建左和右子树意义上跟这个根结点一样的，直接递归
		createtree(&((*T)->lchild),data,index);
		createtree(&((*T)->rchild),data,index);
	}

}
void preorder(treenode* T)//前序
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c-> ",T->data);
		//先办事
		preorder(T->lchild);
		//处理左孩子
		preorder(T->rchild);
	    //处理右孩子
	}

}
void inorder(treenode* T)//中序
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//处理左孩子
		inorder(T->lchild);
		
        printf("%c-> ", T->data);
		inorder(T->rchild);
		//处理右孩子
	}

}
void postorder(treenode* T)//后序
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		postorder(T->lchild);
		//处理左孩子
		postorder(T->rchild);
		//处理右孩子
	   printf("%c-> ", T->data);
	}

}
int main(void)
{
	treenode* T;
	int index = 0;
	char data[] = "AB##C##";
	//scanf("%c",&data);
	createtree(&T, data, &index);
	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	return 0;
}