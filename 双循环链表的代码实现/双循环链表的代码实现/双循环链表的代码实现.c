#include<stdio.h>
#include<stdlib.h>
//�涨һ���ṹ�壬�������һ��data��һ��ͷһ��β��
typedef struct Node
{
	int data;
  struct Node* pre;
  struct Node* next;
}Node;
//��ʼ�����롣
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	L->pre = L;

	return L;
}

//����������˫�����������������һ����NEXTָ��ͷ��ͷ��PREָ�������һ����
//ɾ������
//void deletelist(Node* L, int data)
//{
//	Node* node = L->next;
//		while (node!=L)//��û�п���ɾ���ģ�ֱ������ѭ����
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
// β�巨
void taillist(Node* L, int data)
{  
	Node* head = L;
	
	while (head->next !=L)//�ж�head�ǲ���ָ��Lͷ��
	{
		head = head->next;
	}
    Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->pre = head;
	node->next = L;
	L->pre = node;
	head->next = node;//�ղ����ﱨ��һ������Ҫ��nodeָ��������ˣ�
	L->data++;

}
//ͷ�巨
void headlist(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0)
	{//����Ϊ�յ�ʱ��
		//�ĸ���·��ͷ��node֮��Ļ������ӡ�û�ж���Ŀ顣
		node->pre = L;
		node->next = L->next;
		L->next = node;
		L->pre = node;
		L->data++;
	}
	else
	{//����Ϊ��
		node->next = L->next;
		node->pre = L;
		L->next->pre = node->pre;//��һ�����е㲻����⣬Ӧ���Ǵ�������ġ���������д��.
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
//��������