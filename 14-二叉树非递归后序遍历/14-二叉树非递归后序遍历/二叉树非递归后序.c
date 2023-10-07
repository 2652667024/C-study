#include<stdio.h>
#include<stdlib.h>
typedef struct Treenode
{
	char data;
	struct Treenode* left;
	struct Treenode* right;
	int flag;//����һ����㣬������¼ĳһ��Ԫ����û�б����ʹ������磬����д��һ��B�����ǿ�����D�����D�ں����������᲻���ջ�ٽ�ջ���鷳�����ü�¼һ��

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
		(*T)->flag= 0;//��ʼ���Ĳ���������ڳ�ʼ����ʱ����û�з��ʹ���
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
Stacknode* gettop(Stacknode* S)//��ջ����ȥ
{
	//��һ�������ж��ǲ���ջ�գ��������ʲô��ȡ������
	if (isempty(S))
	{
		return NULL;
	}
	else
	{
		Stacknode* node = S->next;//��ͷָ�����һ��ֱ����Ϊnode������Ҳ���Ƿ��ʹ�һ�ε�Ԫ�أ�������ջ������
		return node;

	}

}
void postorder(Treenode* T)
{
	Treenode* node = T;//�Ѹ��ڵ��ֵ�ӹ���
	Stacknode* S = initstack();//�½�һ��ջ
	while (node || !isempty(S))//��node��Ϊ�ջ���ջ��Ϊ��
	{
		if (node)//��Ϊ��
		{
			push(node, S);//��ջ
			node = node->left;//��ʱnodeȥ����ڵ�

		}
		else//�������Ϊ��
		{
			//���ʱ��Ҫ��ջ�ˣ�
			Treenode* top = gettop(S)->data;//дһ���ӿڣ��õ�ջ��Ԫ��
			if (top->right && top->right->flag == 0)//���������ǿղ���������û�б����ʹ�
			{
				
				top = top->right;
				push(top, S);//����������ջ
				node = top->left;//��ʱ��node��topָ������ӣ������ж����Һ��Ӻ��Ƿ�Ϊ��
			}
			else//���Ϊ��
			{
				top = pop(S)->data;//top�ͱ����Ҫ��ջ���Ǹ�Ԫ��
				printf("%c ", top->data);//��ӡ���Ԫ��
				top->flag = 1;//���Ҵ�ʱtop���1��˵���Ѿ����ʹ��ˣ����治����Ѱ������
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
//������֣�����֮���һ��