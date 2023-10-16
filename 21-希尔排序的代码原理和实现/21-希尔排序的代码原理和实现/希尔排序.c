#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printArray(int array[], int str)//将排序前的数组打印出来，
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
}
void shellSort(int array[],int str,int step)
{
	for (int i = 0;i<str;i++)//这边是为了把整个数组传进来遍历
	{
		for (int j = i+step;j<str;j+=step)//因为我们只想把i的和他+step的这几项找出来
		{
			for (int k = i;k<j;k+=step)//这步是为了找空间换位置规定一个范围i到j之间找，每次找step个长度
			{
				if (array[j]<array[k])
				{
					int temp = array[j];//先手保存一下
					for (int l = j-step;l>=k;l-=step)//意思：左右区间为k到我们要找的那个数减去step的单位，并且这个循环就用一次
					{
						array[l+step] = array[l];//这个记住

					}
					array[k] = temp;
				}
			}
		}
	}

}

int main()
{
	int array[] = { 13,4,1,33,5,3,19,9,6,7,17,85 };
	int str = sizeof(array) / sizeof(array[0]);//改进了一下，直接先行计算数组长度，
	int step[] = { 5,4,3,2,1 };
	for (int i = 0;i<5;i++)
	{
		shellSort(array, str, step[i]);
		printArray(array, str);
	}
	return 0;
}