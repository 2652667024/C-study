#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printArray(int array[],int str)//������ǰ�������ӡ������
{
	for (int i = 0; i < str; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
}
void insertsort(int array[],int str)//ʵ������ʹ�ӡ�ĺ���
{
	for (int i = 1;i<str;i++)//���ѭ���������ӵڶ������鿪ʼ�����һ������
	{
		for (int j = 0; j < i; j++)//�ڲ�ѭ�����������J�ӵ�һλ��ʼֻ��I�й�ϵ��
		{
			if (array[i]<array[j])//��J<iʱ������array[j]>array[i]����ʱ������Ҫ���е�������
			{
				int temp = array[i];//���ȣ��½�һ��TEMP���洢���ʱ��ڶ�λ����
				//for (int k = i-1;k>=j;k--)
				//{
				//	array[k + 1] = array[k];//������

				//}
				//������������дһ�������ı���ѭ��
				for (int k=i-1;k>=j;k--)//���ѭ�����ʼ�ĸ���Ҳֻ��������ʼһ�ߣ�������һ��Ӧ���ǵ�ǰ�Ĵμ���������������֪����i��ʼΪ1��j��0.����K--����
					//�������Ҫ�����ǰһ������λ�õ���������Ҫ��k����k+1���У�

				{
					array[k+1] = array[k];


				}
				array[j] = temp;//��temp��ֵ��array[j]��
			}
		}
		printArray(array,str);//ÿ��i�ӹ����Σ��ʹ�ӡһ��
	}
	//printArray(array, str);//��ӡ�����
}

int main()
{
	int array[] = {13,4,1,5,3,19,9,6,7,17};
	int str = sizeof(array) /sizeof( array[0]);//�Ľ���һ�£�ֱ�����м������鳤�ȣ�
	printArray(array,str);
	insertsort(array, str);
	return 0;
}
//�������������������һ����������