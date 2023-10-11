#include<stdio.h>
#include<stdlib.h>
typedef struct List
{
	int* data;
	int length;
	int num;
}List;
//初始化List
List* initlist(int length)
{
	List* list = (List*)malloc(sizeof(List));
	list->data = (int*)malloc(sizeof(int)*length);
	//List* data = (int*)malloc(sizeof(int));
	list->length = length;
	list->num = 0;
	return list;
}
//现在开始做添加，打印遍历的代码实现
void listAdd(int data,List* list)
{
	list->data[list->num] = data;
	list->num = list->num + 1;

}
void printlist(List* list)
{
	for (int i =0;i<list->num;i++)
	{
		printf("%d ",list->data[i]);
	}
	printf("\n");
}

//开始二分查找的判断
int binarySearch(int key,List* list)
{
	int start = 0;
	int end = list->num - 1;
	int mid;
	while (start<=end)//是一个while循环的查找的，比较慢不如递归（时间复杂度）
	{
		mid = (start + end) / 2;
		if (list->data[mid]<key)
		{
			start = mid + 1;

		}
		else if (list->data[mid]>key)
		{
			end = mid - 1;

		}
		else
		{
			return mid;
		}

	}
		return -1;

}
//创建一个递归的
int binarySearchRecursion(int key, List* list, int start, int end)//start和end是
{
	if (start == end)//如果开头等于结尾
	{
		if (list->data[start] == key)//相等，就是这个
		{
			return start;

		}
		else//不等，那就-1
		{
			return -1;
		}
	}
	int mid = (start + end) / 2;
	if (list->data[mid] < key)//mid已经取半了，递归继续取半判断
	{
		return binarySearchRecursion(key, list, mid + 1, end);
	}
	else if (list->data[mid] > key)
	{
		return binarySearchRecursion(key, list, start, mid - 1);

	}
	else
	{
		return mid;
	}
}
int main()
{
	List*list = initlist(7);
	listAdd(1,list);
	listAdd(2,list);
	listAdd(3,list);
	listAdd(4,list);
	listAdd(5,list);
	listAdd(6,list);
	listAdd(7,list);
	printlist(list);
	printf("mid %d = %d\n",1,binarySearch(1,list));
	printf("mid %d = %d\n",1, binarySearchRecursion(1,list,0,list->num));
	printf("mid %d = %d\n",2, binarySearchRecursion(2,list,0,list->num));
	printf("mid %d = %d\n",3, binarySearchRecursion(3,list,0,list->num));
	return 0;
}