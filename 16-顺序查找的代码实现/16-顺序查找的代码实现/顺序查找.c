//#include<stdio.h>
//#include<stdlib.h>
//typedef struct List//创建一个线表
//{
//	int* data;//线表里面有元素
//	int length;//线表的长度
//	int num;//线表的元素个数
//
//}List;
//
//List* initlist(int length)//初始化线表
//{
//	List* list = (List*)malloc(sizeof(List));//用线表结构创建一个动态控件
//	list->length = length;//线表长度就是初始化的长度
//	list->data = (int*)malloc(sizeof(int) * length);//给data创建整型动态空间
//	list->num = 0;//初始化元素个数
//	return list;//返回线表
//}
//
//void listAdd(List* list, int data)//添加元素到线表
//{
//	list->data[list->num] = data;//num初始化为0，将自己的data放到第一号位置
//	list->num = (list->num) + 1;//线表的num个数加一
//
//}
//int search(List* list, int key)//搜索key在不在线表中
//{
//	for (int i = 0; i < list->num; i++)
//	{
//		if (list->data[i] == key)
//		{
//			return i;//返回这个key的下标
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
//因为这个用于搜索大范围的有些不够用，所以吗，我们要创建一个更好的顺序查找。
//创建一个守卫，把这个位置看作KEY，如果有就返回，没有就是
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
    for (int i = 0;i<length;++i)//初始化链表
    {
        list->data[i] = 0;//每一项都是0
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

