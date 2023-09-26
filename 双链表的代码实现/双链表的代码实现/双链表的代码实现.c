#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* pre;

}Node;
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = NULL;
	L->next = NULL;
	return L;
}
//Node* deletelist(Node* L, int data)
//{
//	Node* temp = L;
//	while (temp)
//	{
//		if (temp->data == data)
//		{
//			if (temp->pre == NULL)
//			{
//				L = temp->next;
//				temp->next = NULL;
//				free(temp);
//				return L;
//			}
//			else if(temp->next == NULL)
//			{
//				temp->pre->next = NULL;
//				free(temp);
//				return L;
//
//			}
//			else
//			{
//				temp->pre->next = temp->next;
//				temp->next->pre = temp->pre;
//				free(temp);
//				return L;
//
//			}
//		}
//		temp = temp->next;
//	}
//	return L;
//
//
//
//}
//void deletelist(Node* L, int data)
//{
//	Node* head = L;
//	Node* current = L->next;
//	while (current)
//	{
//		if (current->data == data)
//		{
//			current->next = head->next;
//			current->pre->next = current->next;
//			free(current);
//		}
//		head = head->next;
//		current = current->next;
//	}
//}
//void deletelist(Node* L, int data)
//{
//	Node* node = L->next;
//	while (node && node != L)
//	{
//		if (node->data == data)
//		{
//			if (node->next)
//			{
//				node->pre->next = node->next;
//				node->next->pre = node->pre;
//			}
//			else
//			{
//				node->pre->next = NULL;
//			}
//			free(node);
//			break;
//		}
//		node = node->next;
//	}
//	L->data--;
//}
void deletelist(Node* L, int data)
{
	Node* node = L->next;//将L指向的下一个赋值给node
	Node* prev = L;//L赋值给prev
	while (node != L) //当NODE存在，且不是L本身也就是真创建出来了。
	{
		if (node->data == data) //当node指向的data就是参数
		{   //分俩情况判断。
			//找到需要删除的节点
			if (node->next != NULL) 
			{
				//节点不是尾节点
				prev->next = node->next;//如果画个图可以很好的理解，两个方块，互相双联，没多余的。
				node->next->pre = prev;
			}
			else 
			{
				//节点是尾节点
				prev->next = NULL;//删除这个尾巴，因为不是循环双链，所以，prev指向NULL。
			}
			free(node);//因为node被覆盖了，所以没了要释放。
			L->data--;
			return;
		}
		prev = node;//往下顺位移动
		node = node->next;
	}
}
void taillist(Node* L, int data)
{
	Node* tou = L;//L保持不变，赋值给tou，让tou进行变化，来寻找node的位置。
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (tou->next)//在while循环内，不允许用指向的代码代表是否为1的标准，
	{
		tou = tou->next;
	}
	node->next = tou->next;//经过那个while循环，直到node到达最后一位指向NULL/0为止。
	tou->next = node;//顺序不能错，先把重点确定，一定是N。
	node->pre = tou;
	L->data++;
}
void headlist(Node* L,int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data ==0)
	{
		node->next = L->next;
		node->pre = L;
		L->next = node;
	}
	else
	{
   
	node->pre = L;
	node->next = L->next;
	L->next->pre = node;
	L->next = node;
	}
}
void printlist(Node*L)
{
	Node* node = L->next;
	while (node)
	{
		printf(" %d ->",node->data);
		node = node->next;
	}
	printf(" NULL\n");
}
int main()
{
	Node* L = initlist();
	headlist(L, 1);
	headlist(L, 2);
	headlist(L, 3);
	headlist(L, 4);
	headlist(L, 5);
	printlist(L);
	deletelist(L, 2);
	printlist(L);

	return 0;
}