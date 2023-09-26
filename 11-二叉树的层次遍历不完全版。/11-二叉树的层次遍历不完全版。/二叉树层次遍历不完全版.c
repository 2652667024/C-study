#include<stdio.h>
#include<stdlib.h>
typedef struct treenode//写一个二叉树的结构体
{
	char data;
	struct treenode* left;
	struct treenode* right;

}treenode;
//因为这个层次遍历，需要插入个别字符，所以需要用到队列
//创建队列结构,包含头尾俩指针
typedef struct Queue
{
	char data;
	struct Queue* pre;
	struct Queue* next;

}Queue;
//代码有点乱，先写一个初始化队列的代码
Queue* initQueue()//这里面，写了一个初始化的代码，申请了一个Q的空间，方便写队列.
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->data = NULL;
	Q->next = Q;
	Q->pre = Q;
	return Q;
}
//写一个入队操作，
void enQueue(treenode* data, Queue* Q)
{
	Queue* node = (Queue*)malloc(sizeof(Queue));
	node->data = data;
	node->pre = Q;
	node->next = Q;
	Q->pre->next = node;//d队列头结点的位置由node替代，
	Q->pre = node;


}
//这里写判断队列中插入的是否为空
int isEmply(Queue* Q)
{
	if (Q->data == Q)
	{
		return NULL;
	}
	else
	{
		return 1;
	}
}
//后面跟一个出队列的函数
// //先不写了，明天补
void deQueue(Queue* Q)
{

}


int main()
{
	return 0;
}
//今天写的很有问题，明天补充后续，所以今天的文件为二叉树的层次遍历不完全版
//总结一下，我对于结构体创建是没有问题的
//然后初始化也会，
//插入我也会，。
//删除后记得释放开辟的空间
//删除之前一定要判断队列里面是不是空的空的话直接返回NULL,
//然后，我对于二叉树那边的创建遍历可能是不太懂，需要学习、