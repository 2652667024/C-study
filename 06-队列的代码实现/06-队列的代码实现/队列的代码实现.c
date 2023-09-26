#include<stdio.h>
#include<stdlib.h>
//�������ݽ��
typedef struct Node
{
	int data;
	struct Node* next;

}Node;
Node* initqueue()
{
	Node* Q = (Node*)malloc(sizeof(Node));
	Q->data = 0;
	Q->next = NULL;
	return Q;

}
//������
void enqueue(Node* Q, int data)
{
	Node* q = Q;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	for (int i = 0; i < Q->data; i++)
	{
		q = q->next;
	}
	node->next = q->next;
	q->next = node;
	Q->data++;
}
//������
//���ӵ�ʱ���ж϶ӿյ������
int isempty(Node* Q)
{
	if (Q->data == 0||Q->next == NULL)//���Q-�����ǿյģ���ô����1��
	{
		return 1;

	}
	return 0;
}
//����
int dequeue(Node* Q)
{
	if (isempty(Q))//�����1����ôֱ�ӷ���-1��
	{
		return -1;
	}
	else//��Ȼ������ĸ���node��node���ͷ��ˡ�
	{
		Node* node = Q->next;
		int data = node->data;
		Q->next = node->next;
		free(node);
		return data;
	}

}

//��������
void printqueue(Node* Q)
{
	Node* node = Q->next;
	while (node)
	{
		printf("%d ->",node->data);
		node = node->next;
	}
	printf("NULL\n");
}
//
int main()
{
	Node* Q = initqueue();
	enqueue(Q, 1);
	enqueue(Q, 2);
	enqueue(Q, 3);
	enqueue(Q, 4);
	printqueue(Q);
	int data = dequeue(Q);
	data = dequeue(Q);
	data = dequeue(Q);
	data = dequeue(Q);
	//data = dequeue(Q);
	printf("data = %d\n",data);
	printqueue(Q);
	return 0;
}
//��ᣬ�������ѭ�����У�