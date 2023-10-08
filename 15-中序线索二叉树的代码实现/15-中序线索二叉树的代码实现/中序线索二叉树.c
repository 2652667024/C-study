#include<stdio.h>
#include<stdlib.h>
//��������������������õ������Խṹ���������������ָ����������
typedef struct Treenode
{
	char data;
	struct Treenode* left;//ָ�����ӵ�ָ��
	struct Treenode* right;//ָ���Һ��ӵ�ָ��
	int ltag;//�涨ָ����ߵı��
	int rtag;//�ұߵı��
}Treenode;
void createTree(Treenode** T, char* data, int* index)
{
	char ch;//���ַ����͵�ch����������
	ch = data[*index];
	*index += 1;
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (Treenode*)malloc(sizeof(Treenode));//���ch�ڵ��ַ�����#���Ϳ���һ���µĿռ���������һ���ṹ��
		(*T)->data = ch;
		(*T)->ltag = 0;//��ʼ�����
		(*T)->rtag = 0;
		createTree(&((*T)->left), data, index);//�ݹ�������
		createTree(&((*T)->right), data, index);//�ݹ�������

	}

}
//������������
void inthreadtree(Treenode*T,Treenode** pre)//��¼ǰ���ڵ㣬����ָ���pre���ȫ�ֱ�����
{
	if (T)//�����������
	{
		inthreadtree(T->left, pre);//�ݹ����
		//����һЩ��
		if (T->left == NULL)//������Ϊ���ˣ���ô����ָ��ǰ���ˡ�
		{
			T->ltag = 1;//��ʱ����һ��ltagΪ1��˵�����û������
			T->left = *pre;//pre�Ǹ�����ָ�룬*����ȡֵ����t->de left��
		}
		if (*pre != NULL && (*pre)->right == NULL)//��ʼ����pre�����ͷ��Ϊ�ա�����ͷָ����ұ��ǿ�
		{
			//�Ϳ���ָ�����ˡ�
			(*pre)->rtag = 1;//��ôͷָ���ұ��Ϊ1
			(*pre)->right = T;//��ͷ�ڵ㸶���Һ���

		}
		*pre = T;//��ͷ�ڵ��ɵ�ǰ��T��
		inthreadtree(T->right, pre);//���Ǳ����Һ���

	}

}
//��һ���������������б���
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
	Treenode* T;//��ʼ��һ�����ڵ�
	Treenode* pre = NULL;//ͷ���Ϊ��
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