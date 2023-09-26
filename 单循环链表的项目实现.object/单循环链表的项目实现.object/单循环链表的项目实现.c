#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

//单链表的循环和单链表其实本质很像，可以理解为头结点的NEXT->的是本身的DATA。
//首先创建一个结构
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
//初始化头结点
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	return L;//创建完成，使其返回L。
}
//现在开始删除的做法。
//int deletelist(Node* L, int data)
//{
//	Node* pre = L;//因为L是要改变的，就要pre变成L让我们调用。
//	Node* node = L->next;
//	while (node!=L)//
//	{
//		if (node->data==data)//如果NODE的data就是我们要删除的。
//		{
//			pre->next = node->next;//就将node的下一位直接覆盖到node上
//			free(node);//并且释放空间
//			return TRUE;
//
//		}
//			pre = node;//如果node指向的data不是我们要的，就往下移动，直到达到我们要的。
//			node = node->next;
//		
//	}
//    return FALSE;//如果都不是，那么直接判断失败。
//
//}
//还有一个思路，就是单链表思路。
void deletelist(Node* L, int data)
{
	Node* pre = L;
	Node* node = L->next;
	while (node != L)
	{
		if (node->data == data)
		{
			pre->next = node->next;
			free(node);
			break;

		}
		pre = node;
		node = node->next;
	}


}
//综上,俩OK;
//现在准备尾插法
void taillist(Node*L,int data)
{
	Node* n = L;//因为L在后边是需要变换位置的，所以设立一个N来代替L。
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (n->next!=L)//当N指向的下一位不是L的话，进行大括号内的操作。
	{
		n = n->next;//顺位后移，直到N能指向的下一位是L为止，也就是找到尾巴。
	}
	node->next = L;//已经在循环内找到N是指向下一个L的位置了，那么就让L赋值给node->next了。
	n->next = node;//将node给到最后一位的后面，插进去了。
	//一定要理解，这里的NODE是插入的块，不要跟N混淆了。
}
 //现在开始头插法
void headlist(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));//开辟一个名字为node的一个空间。
	node->data = data;
	node->next = L->next;	
	L->next = node;
}
void printlist(Node* L)//node指向的L的指针。
{
	Node* node = L->next;//讲L指向的下一位存到NODE 中。
	while (node!= L)//当NODE指向的下一位不是L的时候，就会往下顺位打印。
	{
		printf("%d->", node-> data);//打印node中的data。
		node = node->next;//往下移动一位，然后在与L比较，如果等于，就直接指向MULL。
	}
	printf("NULL\n");
}
int main()

{
	Node*node = initlist();
	headlist(node, 4);
	headlist(node, 5);
	headlist(node, 6);
	taillist(node, 7);
	printlist(node);
	deletelist(node, 7);
	printlist(node);
	return 0;
}