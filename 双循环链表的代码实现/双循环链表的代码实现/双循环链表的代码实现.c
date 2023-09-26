#include<stdio.h>
#include<stdlib.h>
//规定一个结构体，里面包含一个data和一个头一个尾。
typedef struct Node
{
	int data;
  struct Node* pre;
  struct Node* next;
}Node;
//初始化代码。
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	L->pre = L;

	return L;
}

//这个代码的与双链表的区别就在于最后一个的NEXT指向头，头的PRE指向了最后一个，
//删除数字
//void deletelist(Node* L, int data)
//{
//	Node* node = L->next;
//		while (node!=L)//当没有可以删除的，直接跳出循环。
//	   {
//	   	if (node->data == data)
//	   	{
//	   		node->pre->next = node->next;
//	   		node->next->pre = node->pre;
//	   		free(node);
//	   		L->data--;
//	   	/*	return 1;*/
//	   	}
//	   
//
//	   }
//	   //return 0;
//}
void deletelist(Node* L, int data)
{
	Node* node = L->next;
	Node* prev = L;
	while (node!=L)
	{
		if (node->data == data)
		{
			prev->next = node->next;
			node->next->pre = prev;
			free(node);
			L->data--;
			return;
		}
		prev = node;
		node = node->next;
	}

}
// 尾插法
void taillist(Node* L, int data)
{  
	Node* head = L;
	
	while (head->next !=L)//判断head是不是指向L头。
	{
		head = head->next;
	}
    Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->pre = head;
	node->next = L;
	L->pre = node;
	head->next = node;//刚才这里报了一个错，不要把node指向给别人了；
	L->data++;

}
//头插法
void headlist(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0)
	{//链表为空的时候
		//四个线路，头和node之间的互相连接。没有多余的块。
		node->pre = L;
		node->next = L->next;
		L->next = node;
		L->pre = node;
		L->data++;
	}
	else
	{//链表不为空
		node->next = L->next;
		node->pre = L;
		L->next->pre = node->pre;//这一块是有点不好理解，应该是存在问题的。现在是我写的.
		L->next = node;
		L->data++;
	}
}
void printlist(Node* L)
{
	Node* node = L->next;
	while (node !=L)
	{
		printf("%d ->",node->data);
		node = node->next;

	}
	printf("NULL\n");


}
int main()

{
	Node* L = initlist();
	headlist(L, 1);
	headlist(L, 2);
	headlist(L, 3);
	headlist(L, 4);
	taillist(L, 6);
	deletelist(L, 3);
	printlist(L);
	return 0;
}
//完美撒花