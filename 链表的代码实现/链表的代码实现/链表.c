#include<stdio.h>
#include<stdlib.h>
typedef struct Node//初始化NODE。
{
	int data;
	struct Node* next;
}Node;
Node* initlist()
{
	Node* list = (Node*)malloc(sizeof(Node));
    list->data = 0;
	list->next = NULL;
	return list;
}
void deletelist(Node* list, int data)
{
	Node* pre = list;//将原头文件赋值给pre的指针里面
	Node* current = list->next;//将list指向的下一位赋值给current的指针里面。
	while(current)//如果curr是空集，null，跳出循环。
		{
		if (current->data == data)//查找我们要删除的那个参数，是不是list指向的下一个。
		{
			pre->next = current->next;//那么，下下一个赋值给原来的，
			free(current);//释放空间。
			break;//跳出循环。

		}
		else if(current->data!=data)
		{
			pre = current;
			current = current->next;//俩块都后移一位，直到找到那个数。
		}
	    }
	//list->data--;//本意是讲整个代码减一位。也可以不写。
}
void taillist(Node* list, int data)
{
	Node* head = list;//首先list在后面是会动得，没办法保持在首位，写个head代替一下。
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	//list = list->next;//多余，可以省。
	while (list->next)//list指向的下一个不是NULL的时候。
	{
		list = list->next;//就会下移一位，直到NULL之前。
	}
	list->next = node;//可以不写HEAD = data++；
}
void headlist(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));//在内存中申请一个空地，取名node。
	node->data = data;
	node->next = list->next;
	list->next = node;
	list->data++;//原来规定，list指向的data是0.现在有了一个新的node插入开头，所以这个就要顺位移动一位。如果再头插一个，list又要下移一位。
}
void printlist(Node* list)
{
	list = list->next;
	while (list)
	{
		printf("%d ",list->data);
		list = list->next;

	}
	printf("\n");

}
int main()
{
	Node* list = initlist();
	headlist(list, 1);
	headlist(list, 3);
	taillist(list, 5);
	taillist(list, 6);
	taillist(list, 10);
	deletelist(list, 10);
	printlist(list);
	return 0;
}