#include<stdio.h>
void printArray(int array[], int str)//������ǰ�������ӡ������
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
}
void bubblesort(int array[],int str)
{
	for (int i = 0;i<str-1;i++)
	{
		for (int j = 0;j<str-1-i;j++)//�����ʵ��Ϊ�˷�ֹ���ù������Լ��ٺܶ�εıȽ�
		{
			if (array[j]>array[j+1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

		}
		printArray(array, str);
	}



}
int main()
{
	int array[] = {22,86,45,79,55,13,12,1};
	int str = sizeof(array) / sizeof(array[0]);
	printArray(array, str);
	bubblesort(array,str);
	//printArray(array,str);
	return 0;
}