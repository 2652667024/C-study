#include<stdio.h>
#include<stdlib.h>

typedef struct treenode//����treenode�ڵ�
{
	char data;//���ABCDE��
	struct tree* lchild;
	struct tree* rchild;

}treenode;
//�жϸ������û�к���
//ǰ�򣬸�-����-����
//������-����-����
//������-����-����
// ���ֱ�����ʽ�����򵥵ģ�
//����������,
void createtree(treenode** T,char* data,int* index)//�����õ�����ָ������Ϊ���������ĺ���ʱ����Ҫʹ�ö���ָ��ָ�����ǵ��������ָ����
{
//�������������߼�
	char ch;//ch����data���������
	ch = data[*index];//index��Ϊ�˿���ȫ�ֱ�����
	*index += 1;//*index�ı�����ֵ��
	//����һ������
	if (ch == '#')
	{
    //��ʱΪ�սڵ㡣
		*T = NULL;
	}
	else
	{
		//��ʱ��Ϊ��
		*T = (treenode*)malloc(sizeof(treenode));
		(*T)->data = ch;
		//������������������ϸ���������һ���ģ�ֱ�ӵݹ�
		createtree(&((*T)->lchild),data,index);
		createtree(&((*T)->rchild),data,index);
	}

}
void preorder(treenode* T)//ǰ��
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c-> ",T->data);
		//�Ȱ���
		preorder(T->lchild);
		//��������
		preorder(T->rchild);
	    //�����Һ���
	}

}
void inorder(treenode* T)//����
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//��������
		inorder(T->lchild);
		
        printf("%c-> ", T->data);
		inorder(T->rchild);
		//�����Һ���
	}

}
void postorder(treenode* T)//����
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		postorder(T->lchild);
		//��������
		postorder(T->rchild);
		//�����Һ���
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