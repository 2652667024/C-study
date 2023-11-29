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
//�������
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
//�����ڵ�
BSTtree* search(BSTtree* T,int val) {
	//�����ǵݹ�������Ҫ�Ľڵ����������Ǽ���дһ�������Ĵ���
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
	//�������÷�������һ���µĽڵ㣬�ж�����ڵ㸳ֵ֮���Ƿ���ڡ�
	BSTtree* cur = T;//��ͷ��㸳��cur
	while (cur != NULL) {//�ж�cur��Ϊ�� 
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
	return NULL;//��������ô��Ϊ��

}

int main()
{
	BSTtree* T = NULL;
	int data;
	for (int i = 0; i < 6; i++)
	{
		printf("����������:");
		scanf("%d", &data);
		insert(&T, data);
	}
	printf("\n");
	midtree(T);
	printf("\n");

	BSTtree* node = search(T, 8);//�����������ڵ��پ����ݹ��жϺ��ǲ��ǿ�
	if (node == NULL) {
		printf("û���ҵ�\n");
	}
	else {
		printf("%d", node->data);
	}

	return 0;
}