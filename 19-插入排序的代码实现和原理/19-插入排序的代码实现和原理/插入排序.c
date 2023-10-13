#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printArray(int array[],int str)//将排序前的数组打印出来，
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
}
void insertsort(int array[],int str)//实现排序和打印的函数
{
	for (int i = 1;i<str;i++)//外层循环遍历，从第二个数组开始到最后一个截至
	{
		for (int j = 0; j < i; j++)//内层循环遍历这个的J从第一位开始只与I有关系，
		{
			if (array[i]<array[j])//当J<i时，并且array[j]>array[i]，的时候，这俩要进行调换操作
			{
				int temp = array[i];//首先，新建一个TEMP来存储这个时候第二位数组
				//for (int k = i-1;k>=j;k--)
				//{
				//	array[k + 1] = array[k];//往后移

				//}
				//我们先重新来写一个好理解的遍历循环
				for (int k=i-1;k>=j;k--)//外层循环是最开始的根，也只能拿来初始一边，所以另一边应该是当前的次级遍历的量。我们知道，i初始为1，j是0.所以K--才行
					//最后，我们要满足给前一个数留位置的条件，就要用k给到k+1才行，

				{
					array[k+1] = array[k];


				}
				array[j] = temp;//将temp赋值给array[j]；
			}
		}
		printArray(array,str);//每次i加过依次，就打印一次
	}
	//printArray(array, str);//打印最后结果
}

int main()
{
	int array[] = {13,4,1,5,3,19,9,6,7,17};
	int str = sizeof(array) /sizeof( array[0]);//改进了一下，直接先行计算数组长度，
	printArray(array,str);
	insertsort(array, str);
	return 0;
}
//明天在这个基础上设想一个二分排序法