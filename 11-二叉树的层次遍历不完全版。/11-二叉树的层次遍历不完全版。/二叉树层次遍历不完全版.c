#include<stdio.h>
#include<stdlib.h>
typedef struct treenode//дһ���������Ľṹ��
{
	char data;
	struct treenode* left;
	struct treenode* right;

}treenode;
//��Ϊ�����α�������Ҫ��������ַ���������Ҫ�õ�����
//�������нṹ,����ͷβ��ָ��
typedef struct Queue
{
	char data;
	struct Queue* pre;
	struct Queue* next;

}Queue;
//�����е��ң���дһ����ʼ�����еĴ���
Queue* initQueue()//�����棬д��һ����ʼ���Ĵ��룬������һ��Q�Ŀռ䣬����д����.
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->data = NULL;
	Q->next = Q;
	Q->pre = Q;
	return Q;
}
//дһ����Ӳ�����
void enQueue(treenode* data, Queue* Q)
{
	Queue* node = (Queue*)malloc(sizeof(Queue));
	node->data = data;
	node->pre = Q;
	node->next = Q;
	Q->pre->next = node;//d����ͷ����λ����node�����
	Q->pre = node;


}
//����д�ж϶����в�����Ƿ�Ϊ��
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
//�����һ�������еĺ���
// //�Ȳ�д�ˣ����첹
void deQueue(Queue* Q)
{

}


int main()
{
	return 0;
}
//����д�ĺ������⣬���첹����������Խ�����ļ�Ϊ�������Ĳ�α�������ȫ��
//�ܽ�һ�£��Ҷ��ڽṹ�崴����û�������
//Ȼ���ʼ��Ҳ�ᣬ
//������Ҳ�ᣬ��
//ɾ����ǵ��ͷſ��ٵĿռ�
//ɾ��֮ǰһ��Ҫ�ж϶��������ǲ��ǿյĿյĻ�ֱ�ӷ���NULL,
//Ȼ���Ҷ��ڶ������ǱߵĴ������������ǲ�̫������Ҫѧϰ��