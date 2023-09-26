#include<stdio.h>
#include<stdlib.h>
//创建结构体变量
typedef struct Node
{
	int data;
	struct Node* next;

}Node;
//初始化头结点.
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	return L;
}
//判断是否为空。
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
//读栈顶元素
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

//利用头插法将结点插进去

void push(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}
//出栈，也就是删除第一个；
int pop(Node* L)
{
	if (isempty(L))//先判断栈顶是不是没有元素
	{
		return -1;
	}
	else
	{
		Node* node = L->next;//设置一个L-》的下一个为node
		int n = node->data;//将node的值付出来给N
		L->next = node->next;//node删除消失掉了。
		free(node);//释放
		return n;
	}

}
//便捷打印。
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