#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
//定义结构体，包含头尾和数组.
typedef struct queue
{
	int front;
	int rear;
	int data[MAXSIZE];

}queue;
//初始化代码
queue* initqueue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->front = Q->rear = 0;
	return Q;
}
//遍历
void printqueue(queue* Q)//遍历过程
{
	int i = 0;
	int length = (Q->rear - Q->front + MAXSIZE) % MAXSIZE;//计算队长；
	int index = Q->front;//将头赋值给index
	for (i = 0; i < length; i++)
	{
		printf("%d ->",Q->data[index]);
		index = (index + 1) % MAXSIZE;//index+=1；当index+4的时候，余为0，也就意味满了.

	}
	printf("NULL\n");
}
int isfull(queue* Q)//判断是否满了
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
	if (isfull(Q))//满了，直接返回0
	{
		return 0;
	}
	else//没满的情况下
	{
		Q->data[Q->rear] = data;//讲输入的数值存到队尾指向的下一个地方
		Q->rear = (Q->rear + 1) % MAXSIZE;//并且，队尾的位置要+1向下移动一位。max存在的意义就是为了找到下一个的余数，保证有数。
		return 1;
	}
}
//判断出队的时候是不是为空
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
//出队操作
int dequeue(queue* Q) 
{
	if (isempty(Q))
    {
		return -1;
	}
	else
	{
		int data = Q->data[Q->front];//将Q的头指向的数字规定为data
		Q->front = (Q->front + 1) % MAXSIZE;//将头指向的下一位赋值给头，相当于头向下移了一位，舍弃了开头。
		return data;//返回data

	}

}
int main()
{
	queue* Q = initqueue();
	enqueue(Q, 1);
	enqueue(Q, 2);
	enqueue(Q, 3);
	enqueue(Q, 4);
	//enqueue(Q, 5);//已经满了，除非把max变成6.
	printqueue(Q);
	dequeue(Q);
	dequeue(Q);
	dequeue(Q);
	//dequeue(Q);
	printqueue(Q);
	return 0;
}