//#include<stdio.h>
//#include<stdlib.h>
//typedef struct List//����һ���߱�
//{
//	int* data;//�߱�������Ԫ��
//	int length;//�߱�ĳ���
//	int num;//�߱��Ԫ�ظ���
//
//}List;
//
//List* initlist(int length)//��ʼ���߱�
//{
//	List* list = (List*)malloc(sizeof(List));//���߱�ṹ����һ����̬�ؼ�
//	list->length = length;//�߱��Ⱦ��ǳ�ʼ���ĳ���
//	list->data = (int*)malloc(sizeof(int) * length);//��data�������Ͷ�̬�ռ�
//	list->num = 0;//��ʼ��Ԫ�ظ���
//	return list;//�����߱�
//}
//
//void listAdd(List* list, int data)//���Ԫ�ص��߱�
//{
//	list->data[list->num] = data;//num��ʼ��Ϊ0�����Լ���data�ŵ���һ��λ��
//	list->num = (list->num) + 1;//�߱��num������һ
//
//}
//int search(List* list, int key)//����key�ڲ����߱���
//{
//	for (int i = 0; i < list->num; i++)
//	{
//		if (list->data[i] == key)
//		{
//			return i;//�������key���±�
//		}
//
//	}
//	return -1;
//
//}
//void printList(List* list)
//{
//	for (int i = 0; i < list->num; i++)
//	{
//		printf("%d ->", list->data[i]);
//	
//	}
//	printf("NULL\n");
//
//}
//int main()
//{
//	List* list = initlist(5);
//	listAdd(list, 1);
//	listAdd(list, 2);
//	listAdd(list, 3);
//	listAdd(list, 4);
//	printList(list);
//	printf("%d",search(list,6));
//
//	return 0;
//}
//��Ϊ�������������Χ����Щ�����ã�����������Ҫ����һ�����õ�˳����ҡ�
//����һ�������������λ�ÿ���KEY������оͷ��أ�û�о���
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int* data;
    int length;
    int num;
}List;

List* initList(int length) {
    List* list = (List*)malloc(sizeof(List));
    list->length = length;
    list->data = (int*)malloc(sizeof(int) * length);
    for (int i = 0;i<length;++i)//��ʼ������
    {
        list->data[i] = 0;//ÿһ���0
    }
    list->num = 1;
    return list;
}

void listAdd(List* list, int data) {
    list->data[list->num] = data;
    list->num = (list->num) + 1;
}

void printList(List* list) {
    for (int i = 0; i < list->num; i++) {
        printf("%d -> ", list->data[i]);
    }
    printf("NULL\n");
}

int search(List* list, int key) {
    int i;
    list->data[0] = key;
    for (i = (list->num) - 1; list->data[i] != key; i--) {
        printf("i = %d\n", i);
    }
    return i;
}

int main()
{
    List* list = initList(5);
    listAdd(list, 4);
    listAdd(list, 5);
    listAdd(list, 6);
    listAdd(list, 7);
    printList(list);
    printf("%d\n", search(list, 8));
    printf("%d",list->data[0]);
    return 0;
}

