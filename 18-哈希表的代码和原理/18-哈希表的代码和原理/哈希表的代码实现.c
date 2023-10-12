#include<stdio.h>
#include<stdlib.h>
#define NUM 5
typedef struct hashlist
{
	int num;
	char* data;

}hashlist;
//��ʼ����ϣ��
hashlist* initlist()
{
	hashlist* list = (hashlist*)malloc(sizeof(hashlist));
	list->num = 0;
	list->data = (char*)malloc(sizeof(char) * NUM);
	for (int i = 0;i<NUM;i++)//����ϣ�������ȫ����ʼ��Ϊ0
	{
		list->data[i] = 0;
	}
	return list;
}
int hash(int data)//����һ����ϣ�����������asciiֵ
{
	return data % NUM;//ģ��NUM
}
void put(hashlist*list,int data)//��д��ASCIIֵ����list��
{
	int index = hash(data);//��index�����ϣ�����ķ���ֵ���磬94 % NUM = 2������index = 2
	if (list->data[index] != 0)//������ͻ�����ϣ�index = 2
	{
		int count = 1;
		while (list->data[index]!=0)//��index = 2ʱ��
		{
			index = hash(hash(data) + count);//index��˳λ����һ��λ�ã��浽�Ǹ�λ����ȥ
			count++;//�����һ��λ����������Ҫ�����´档
		}
	}
	list->data[index] = data;//���data�浽index���Դ�ĵط�
}


int main()
{
	hashlist* list = initlist();
	put(list,0);
	put(list,1);
	put(list,6);
	put(list,11);
	put(list,16);
	printf("%d\n",list->data[0]);
	printf("%d\n",list->data[1]);
	printf("%d\n",list->data[2]);
	printf("%d\n",list->data[3]);
	printf("%d\n",list->data[4]);
	//���а��������ǹ涨����Ϊ5����ôȡģ��ʱ��ֻ��%5.���վdata[]�����λ�ã�Ȼ��Ҫ��������һ������˳λռ�õڶ�������������
	return 0;
}