#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printArray(int array[], int str)//������ǰ�������ӡ������
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
}
void shellSort(int array[],int str,int step)
{
	for (int i = 0;i<str;i++)//�����Ϊ�˰��������鴫��������
	{
		for (int j = i+step;j<str;j+=step)//��Ϊ����ֻ���i�ĺ���+step���⼸���ҳ���
		{
			for (int k = i;k<j;k+=step)//�ⲽ��Ϊ���ҿռ任λ�ù涨һ����Χi��j֮���ң�ÿ����step������
			{
				if (array[j]<array[k])
				{
					int temp = array[j];//���ֱ���һ��
					for (int l = j-step;l>=k;l-=step)//��˼����������Ϊk������Ҫ�ҵ��Ǹ�����ȥstep�ĵ�λ���������ѭ������һ��
					{
						array[l+step] = array[l];//�����ס

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
	int str = sizeof(array) / sizeof(array[0]);//�Ľ���һ�£�ֱ�����м������鳤�ȣ�
	int step[] = { 5,4,3,2,1 };
	for (int i = 0;i<5;i++)
	{
		shellSort(array, str, step[i]);
		printArray(array, str);
	}
	return 0;
}