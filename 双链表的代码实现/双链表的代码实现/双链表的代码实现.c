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
	Node* node = L->next;//��Lָ�����һ����ֵ��node
	Node* prev = L;//L��ֵ��prev
	while (node != L) //��NODE���ڣ��Ҳ���L����Ҳ�����洴�������ˡ�
	{
		if (node->data == data) //��nodeָ���data���ǲ���
		{   //��������жϡ�
			//�ҵ���Ҫɾ���Ľڵ�
			if (node->next != NULL) 
			{
				//�ڵ㲻��β�ڵ�
				prev->next = node->next;//�������ͼ���Ժܺõ���⣬�������飬����˫����û����ġ�
				node->next->pre = prev;
			}
			else 
			{
				//�ڵ���β�ڵ�
				prev->next = NULL;//ɾ�����β�ͣ���Ϊ����ѭ��˫�������ԣ�prevָ��NULL��
			}
			free(node);//��Ϊnode�������ˣ�����û��Ҫ�ͷš�
			L->data--;
			return;
		}
		prev = node;//����˳λ�ƶ�
		node = node->next;
	}
}
void taillist(Node* L, int data)
{
	Node* tou = L;//L���ֲ��䣬��ֵ��tou����tou���б仯����Ѱ��node��λ�á�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (tou->next)//��whileѭ���ڣ���������ָ��Ĵ�������Ƿ�Ϊ1�ı�׼��
	{
		tou = tou->next;
	}
	node->next = tou->next;//�����Ǹ�whileѭ����ֱ��node�������һλָ��NULL/0Ϊֹ��
	tou->next = node;//˳���ܴ��Ȱ��ص�ȷ����һ����N��
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