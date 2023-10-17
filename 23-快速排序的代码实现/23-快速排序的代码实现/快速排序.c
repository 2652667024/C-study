#include<stdio.h>
void printArray(int array[], int str)//������ǰ�������ӡ������
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void swap(int array[], int start, int end)//��������
{
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;


}
int getmid(int array[], int start, int end)
{
	int key = array[start];
	while (start<end)//����ǰ����������������
    { 
		while (array[end]>=key&&start<end)//��end�Ĵ���ѡȡ�ģ�end--
		{
			end--;
		}
		swap(array,start,end);//�����С���򽻻�

        while (array[start] <= key && end > start)
		{
			start++;
		}
		swap(array,start,end);
	}
	array[start] = key;//��֤array��start�����䡣��Ҫ��ѡȡֵ������
	return start;//����ѡȡֵ
}
//дһ���ݹ�ĺ������ǿ�������ĹǼ�
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
