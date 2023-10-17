#include<stdio.h>
void printArray(int array[], int str)//将排序前的数组打印出来，
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void swap(int array[], int start, int end)//交换函数
{
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;


}
int getmid(int array[], int start, int end)
{
	int key = array[start];
	while (start<end)//这是前置条件。必须满足
    { 
		while (array[end]>=key&&start<end)//当end的大于选取的，end--
		{
			end--;
		}
		swap(array,start,end);//如果不小，则交换

        while (array[start] <= key && end > start)
		{
			start++;
		}
		swap(array,start,end);
	}
	array[start] = key;//保证array【start】不变。就要把选取值还回来
	return start;//返回选取值
}
//写一个递归的函数这是快速排序的骨架
void quicksort(int array[],int start,int end)
{
	if (start<end)
	{
		int mid = getmid(array,start,end);
		quicksort(array,start,mid-1);
		quicksort(array,mid+1,end);
	}
}
int main()
{
	int array[] = {16,9,46,81,33,10,55};
	int str = sizeof(array) / sizeof(array[0]);
	quicksort(array, 0,str-1);
	printArray(array,str);
	return 0;
}
