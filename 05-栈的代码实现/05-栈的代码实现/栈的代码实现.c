#include<stdio.h>
#include<stdlib.h>
//�����ṹ�����
typedef struct Node
{
	int data;
	struct Node* next;

}Node;
//��ʼ��ͷ���.
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	return L;
}
//�ж��Ƿ�Ϊ�ա�
int isempty(Node* L)
{
	if (L->data == 0||L->next ==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
//��ջ��Ԫ��
int gettop(Node* L)
{
	if (isempty(L))
	{
		return -1;
	}
	else
	{
		return L->next->data;
	}

}

//����ͷ�巨�������ȥ

void push(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}
//��ջ��Ҳ����ɾ����һ����
int pop(Node* L)
{
	if (isempty(L))//���ж�ջ���ǲ���û��Ԫ��
	{
		return -1;
	}
	else
	{
		Node* node = L->next;//����һ��L-������һ��Ϊnode
		int n = node->data;//��node��ֵ��������N
		L->next = node->next;//nodeɾ����ʧ���ˡ�
		free(node);//�ͷ�
		return n;
	}

}
//��ݴ�ӡ��
void printlist(Node* L)
{
	Node* node = L->next;
	while (node)
	{
		printf("%d ->",node->data);
		node = node->next;
	}
	printf("NULL\n");
}
int main()
{
	Node* L = initlist();
	push(L, 1);
	push(L, 2);
	push(L, 3);
	push(L, 4);
	printlist(L);

	int i = pop(L);
	printf("current elem = %d\n", i);
	printlist(L);

	return 0;
}