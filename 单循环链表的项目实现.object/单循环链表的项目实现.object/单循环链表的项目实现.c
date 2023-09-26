#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

//�������ѭ���͵�������ʵ���ʺ��񣬿������Ϊͷ����NEXT->���Ǳ����DATA��
//���ȴ���һ���ṹ
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
//��ʼ��ͷ���
Node* initlist()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	return L;//������ɣ�ʹ�䷵��L��
}
//���ڿ�ʼɾ����������
//int deletelist(Node* L, int data)
//{
//	Node* pre = L;//��ΪL��Ҫ�ı�ģ���Ҫpre���L�����ǵ��á�
//	Node* node = L->next;
//	while (node!=L)//
//	{
//		if (node->data==data)//���NODE��data��������Ҫɾ���ġ�
//		{
//			pre->next = node->next;//�ͽ�node����һλֱ�Ӹ��ǵ�node��
//			free(node);//�����ͷſռ�
//			return TRUE;
//
//		}
//			pre = node;//���nodeָ���data��������Ҫ�ģ��������ƶ���ֱ���ﵽ����Ҫ�ġ�
//			node = node->next;
//		
//	}
//    return FALSE;//��������ǣ���ôֱ���ж�ʧ�ܡ�
//
//}
//����һ��˼·�����ǵ�����˼·��
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
//����,��OK;
//����׼��β�巨
void taillist(Node*L,int data)
{
	Node* n = L;//��ΪL�ں������Ҫ�任λ�õģ���������һ��N������L��
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (n->next!=L)//��Nָ�����һλ����L�Ļ������д������ڵĲ�����
	{
		n = n->next;//˳λ���ƣ�ֱ��N��ָ�����һλ��LΪֹ��Ҳ�����ҵ�β�͡�
	}
	node->next = L;//�Ѿ���ѭ�����ҵ�N��ָ����һ��L��λ���ˣ���ô����L��ֵ��node->next�ˡ�
	n->next = node;//��node�������һλ�ĺ��棬���ȥ�ˡ�
	//һ��Ҫ��⣬�����NODE�ǲ���Ŀ飬��Ҫ��N�����ˡ�
}
 //���ڿ�ʼͷ�巨
void headlist(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));//����һ������Ϊnode��һ���ռ䡣
	node->data = data;
	node->next = L->next;	
	L->next = node;
}
void printlist(Node* L)//nodeָ���L��ָ�롣
{
	Node* node = L->next;//��Lָ�����һλ�浽NODE �С�
	while (node!= L)//��NODEָ�����һλ����L��ʱ�򣬾ͻ�����˳λ��ӡ��
	{
		printf("%d->", node-> data);//��ӡnode�е�data��
		node = node->next;//�����ƶ�һλ��Ȼ������L�Ƚϣ�������ڣ���ֱ��ָ��MULL��
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