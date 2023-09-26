#include<stdio.h>
#include<stdlib.h>
//�����ṹ�壬������char�������飬��һ��LEN���س��ȡ�
typedef struct string
{
	char* data;//char���͵�ָ�룬һ����һ���ֽ�.
	int len;//����һ��lenΪ�ַ�������
}string;
//��ʼ���ṹ�壬�Ա㿪ʼ���д����ƥ��
string* initstring()
{
	string* S = (string*)malloc(sizeof(string));
	S->data = NULL;
	S->len = 0;
	return S;
}
//��ʼ�����֮��ʼ׼�����ַ�����д�����ݽ��бȽ�.
void stringassign(string* s, char* data)
{
	//���ȿ���һ��������Ǿ��ǿ��ٿռ��ʱ��data�ڲ���û�ж�����Ҳ����Ұָ��
	if (s->data)//���S��data�ж����Ǿ��ǲ�ΪNULL����ô��Ҫ�ͷŵ���
	{
		free(s->data);
	}
	int len = 0;//��LEN��ʼ����
	char* temp = data;//��data���ַ������ݸ�temp��ָ�����棬
	while (*temp)//��Ϊ��
	{
		len++;
		temp++;//���ұ������ܽ�len��ֱ��tempָ��\0Ϊֹ��������ѭ���ˣ�
	}
	if (len == 0)//�����꣬lenΪ0��˵��û���ַ�����������
	{
		s->data = NULL;
		s->len = 0;
	}
	else
	{
		temp = data;//len������0����ôֱ�ӽ�data���ַ����ݸ�ֵ��temp��
		s->len = len;//��ʼ�ܽᣬ
		s->data = (char*)malloc(sizeof(char) * (len + 1));//������ӵ��ַ������ȣ����1����Ϊ����/0��
		for (int i = 0; i < len; i++,temp++)
		{
			s->data[i] = *temp;//��temp��data�������ݰ�0���޵�˳����ȥ��*temp�ǽ��������ֻ��ˣ�����ǵ�ַ��

		}
	}
}
void printstring(string* s)
{
	for (int i = 0; i < s->len; i++)
	{
		printf(i == 0 ? "%c": "->%c", s->data[i]);//������������

	}
	printf("\n");
}
//����ƥ�����ʵԭ��
void forcematch(string* master, string* sub)
{
	int i = 0;
	int j = 0;
	while (i < master->len && j<sub->len)//���i j�ֱ�С���ܳ��ȣ���ô��������.
	{
		if (master->data[i] == sub->data[j])//�ڵ�i  j λ��ʱ����ͬ�ַ����͸��Լ�һ
		{
			i++;
			j++;

		}
		else
		{
			i = i - j + 1;//i�����ƶ�һλ��
			j = 0;//j��0��ʼ�����¶Աȣ�

		}
	}
	if (j = sub->len)//��J������Ϊ�ӷ�֧�ĳ���ʱ��˵���ӷ�֧�������ˣ���û��������һ���ģ�����ͨ����
	{
		printf("ƥ��ɹ�\n");
	}
	else
	{
		printf("ƥ��ʧ��\n");
	}
}
int main()
{
	string* s1 = initstring();
	string* s2 = initstring();
	stringassign(s1, "hello");
	stringassign(s2, "llo");

	printstring(s1);
	printstring(s2);
	 
	forcematch(s1, s2);
	return 0;
}
//�������ַ�������Ĺ����У��õ���ָ������֪ʶ��
//          int num = 1;
//����֪����int *ptr = &num;
//          Ҳ����˵��ptr�������ǣ�num�ĵ�ַ��*�˾ͽ����һ��ֵ��
//          ͬ��*temp�ǰ�data���ַ����������
//                �ӵ�һλ��ʼ��ֱ��\0���������for���������temp++.���ǽ������ַ������ȥ�ˣ�

//�����С��飬�����ٿ���ָ��һ�ڵĽ���.
//����ѧϰKMP�㷨��