#include<stdio.h>
#include<stdlib.h>
//线索二叉树中序遍历，用到了线性结构，里面包含了两个指针和两个标记
typedef struct Treenode
{
	char data;
	struct Treenode* left;//指向左孩子的指针
	struct Treenode* right;//指向右孩子的指针
	int ltag;//规定指向左边的标记
	int rtag;//右边的标记
}Treenode;
void createTree(Treenode** T, char* data, int* index)
{
	char ch;//用字符类型的ch来接收数组
	ch = data[*index];
	*index += 1;
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (Treenode*)malloc(sizeof(Treenode));//如果ch内的字符不是#，就开辟一个新的空间来接收下一个结构体
		(*T)->data = ch;
		(*T)->ltag = 0;//初始化标记
		(*T)->rtag = 0;
		createTree(&((*T)->left), data, index);//递归左子树
		createTree(&((*T)->right), data, index);//递归右字数

	}

}
//线索化二叉树
void inthreadtree(Treenode*T,Treenode** pre)//记录前驱节点，二级指针把pre搓成全局变量。
{
	if (T)//如果根结点存在
	{
		inthreadtree(T->left, pre);//递归左边
		//做了一些事
		if (T->left == NULL)//如果左边为空了，那么可以指向前驱了。
		{
			T->ltag = 1;//这时候标记一下ltag为1，说明左边没东西了
			T->left = *pre;//pre是个二级指针，*代表取值，给t->de left。
		}
		if (*pre != NULL && (*pre)->right == NULL)//开始处理pre。如果头不为空。并且头指向的右边是空
		{
			//就可以指向后继了。
			(*pre)->rtag = 1;//那么头指向右标记为1
			(*pre)->right = T;//将头节点付给右孩子

		}
		*pre = T;//把头节点变成当前的T。
		inthreadtree(T->right, pre);//这是遍历右孩子

	}

}
//对一棵线索二叉树进行遍历
Treenode* getfirst(Treenode* T)
{
	while(T->ltag == 0)
		T = T->left;
	return T;
}
Treenode* getnext(Treenode* node)
{
	if (node->rtag == 1)
	{
		return node->right;
	}
	else
	{
		return getfirst(node->right);
	}


}
int main()
{
	Treenode* T;//初始化一个根节点
	Treenode* pre = NULL;//头结点为空
	int index = 0;
	char data[] = "ABD##E##C##";
	createTree(&T, data, &index);
	inthreadtree(T, &pre);
	pre->rtag = 1;
	pre->right = NULL;
	for (Treenode*node = getfirst(T);node != NULL;node = getnext(node))
	{
		printf("%c ",node->data);
	}
	printf("\n");

	return 0;
}