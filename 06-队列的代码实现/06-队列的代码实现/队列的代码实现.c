#include<stdio.h>
#include<stdlib.h>
//定义数据结点
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
//进队列
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
//出队列
//出队的时候判断队空的情况；
int isempty(Node* Q)
{
	if (Q->data == 0||Q->next == NULL)//如果Q-》的是空的，那么返回1；
	{
		return 1;

	}
	return 0;
}
//出队
int dequeue(Node* Q)
{
	if (isempty(Q))//如果是1，那么直接返回-1；
	{
		return -1;
	}
	else//不然，后面的覆盖node，node被释放了。
	{
		Node* node = Q->next;
		int data = node->data;
		Q->next = node->next;
		free(node);
		return data;
	}

}

//遍历队列
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
//完结，明天更新循环队列；