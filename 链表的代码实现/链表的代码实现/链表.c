#include<stdio.h>
#include<stdlib.h>
typedef struct Node//��ʼ��NODE��
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
	Node* pre = list;//��ԭͷ�ļ���ֵ��pre��ָ������
	Node* current = list->next;//��listָ�����һλ��ֵ��current��ָ�����档
	while(current)//���curr�ǿռ���null������ѭ����
		{
		if (current->data == data)//��������Ҫɾ�����Ǹ��������ǲ���listָ�����һ����
		{
			pre->next = current->next;//��ô������һ����ֵ��ԭ���ģ�
			free(current);//�ͷſռ䡣
			break;//����ѭ����

		}
		else if(current->data!=data)
		{
			pre = current;
			current = current->next;//���鶼����һλ��ֱ���ҵ��Ǹ�����
		}
	    }
	//list->data--;//�����ǽ����������һλ��Ҳ���Բ�д��
}
void taillist(Node* list, int data)
{
	Node* head = list;//����list�ں����ǻᶯ�ã�û�취��������λ��д��head����һ�¡�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	//list = list->next;//���࣬����ʡ��
	while (list->next)//listָ�����һ������NULL��ʱ��
	{
		list = list->next;//�ͻ�����һλ��ֱ��NULL֮ǰ��
	}
	list->next = node;//���Բ�дHEAD = data++��
}
void headlist(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));//���ڴ�������һ���յأ�ȡ��node��
	node->data = data;
	node->next = list->next;
	list->next = node;
	list->data++;//ԭ���涨��listָ���data��0.��������һ���µ�node���뿪ͷ�����������Ҫ˳λ�ƶ�һλ�������ͷ��һ����list��Ҫ����һλ��
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