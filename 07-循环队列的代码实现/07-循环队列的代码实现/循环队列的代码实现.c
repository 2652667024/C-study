#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
//����ṹ�壬����ͷβ������.
typedef struct queue
{
	int front;
	int rear;
	int data[MAXSIZE];

}queue;
//��ʼ������
queue* initqueue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->front = Q->rear = 0;
	return Q;
}
//����
void printqueue(queue* Q)//��������
{
	int i = 0;
	int length = (Q->rear - Q->front + MAXSIZE) % MAXSIZE;//����ӳ���
	int index = Q->front;//��ͷ��ֵ��index
	for (i = 0; i < length; i++)
	{
		printf("%d ->",Q->data[index]);
		index = (index + 1) % MAXSIZE;//index+=1����index+4��ʱ����Ϊ0��Ҳ����ζ����.

	}
	printf("NULL\n");
}
int isfull(queue* Q)//�ж��Ƿ�����
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int enqueue(queue*Q,int data)
{
	if (isfull(Q))//���ˣ�ֱ�ӷ���0
	{
		return 0;
	}
	else//û���������
	{
		Q->data[Q->rear] = data;//���������ֵ�浽��βָ�����һ���ط�
		Q->rear = (Q->rear + 1) % MAXSIZE;//���ң���β��λ��Ҫ+1�����ƶ�һλ��max���ڵ��������Ϊ���ҵ���һ������������֤������
		return 1;
	}
}
//�жϳ��ӵ�ʱ���ǲ���Ϊ��
int isempty(queue* Q)
{
	if (Q->front == Q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
//���Ӳ���
int dequeue(queue* Q) 
{
	if (isempty(Q))
    {
		return -1;
	}
	else
	{
		int data = Q->data[Q->front];//��Q��ͷָ������ֹ涨Ϊdata
		Q->front = (Q->front + 1) % MAXSIZE;//��ͷָ�����һλ��ֵ��ͷ���൱��ͷ��������һλ�������˿�ͷ��
		return data;//����data

	}

}
int main()
{
	queue* Q = initqueue();
	enqueue(Q, 1);
	enqueue(Q, 2);
	enqueue(Q, 3);
	enqueue(Q, 4);
	//enqueue(Q, 5);//�Ѿ����ˣ����ǰ�max���6.
	printqueue(Q);
	dequeue(Q);
	dequeue(Q);
	dequeue(Q);
	//dequeue(Q);
	printqueue(Q);
	return 0;
}