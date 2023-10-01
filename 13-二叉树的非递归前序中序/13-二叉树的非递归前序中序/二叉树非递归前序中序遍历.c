#include<stdio.h>
#include<stdlib.h>
//����һ���������ṹ��
typedef struct Treenode
{
	char data;
	struct Treenode* left;
	struct Treenode* right;

}Treenode;
//����һ��ջ��������Ŷ�ȡ������ַ����Ƚ����ԭ��
typedef struct Stacknode
{
	Treenode* data;//ջ��ͷ�Ƕ�������data
	struct Stacknode* next;//����һ��nextָ��

}Stacknode;
//дһ���������㷨
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
		createTree(&((*T)->left), data, index);//�ݹ�������
		createTree(&((*T)->right), data, index);//�ݹ�������

	}

}
//��ʼ��ջ
Stacknode* initstack()//һ��ջͷ
{
	Stacknode* S = (Stacknode*)malloc(sizeof(Stacknode));
	S->data = NULL;
	S->next = NULL;
	return S;
}
//дһ����ջ�Ĳ���
void push(Treenode* data, Stacknode* S)
{
	//���ȿ���һ��ջ�Ŀռ�
	Stacknode* node = (Stacknode*)malloc(sizeof(Stacknode));
	node->data = data;
	//ͷ�巨ʵ�ֽ�ջ
	node->next = S->next;
	S->next = node;
}
//�ж�ջ��
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
//дһ����ջ��������Stacknode

Stacknode* pop(Stacknode* S)//��ջ����ȥ
{
	//��һ�������ж��ǲ���ջ�գ��������ʲô��ȡ������
	if (isempty(S))
	{
		return NULL;
	}
	else
	{
		Stacknode* node = S->next;//Sͷ�ڵ�ָ�����һλ��������node��nodeָ�����һ������ԭ��ͷָ�����һ�����γɱջ�
		S->next = node->next;
		return node;

	}

}
void preOrder(Treenode* T)//ǰ��ı����߼�
{
	Treenode* node = T;
	Stacknode* S = initstack();
	while (node || !isempty(S))
	{
		if (node)//ǰ������ȷ����ڽ�ջ
		{
			printf("%c ", node->data);
			push(node, S);
			//��ʼѭ������������ߵ�
			node = node->left;
		}
		else
		{
			node = pop(S)->data;
			node = node->right;

		}
	}


}
void inOrder(Treenode* T)//����ı����߼�
{
	Treenode* node = T;
	Stacknode* S = initstack();
	while (node || !isempty(S))
	{
		if (node)//ǰ������ȷ����ڽ�ջ
		{

			push(node, S);
			//��ʼѭ������������ߵ�
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