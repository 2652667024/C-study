//#include<stdio.h>
//#include<string.h>
//void reverseString(char* s, int nums) {
//	int start = 0;
//	int end = nums - 1;
//	char temp = 0;
//	if (nums == 1 || nums == 0) {//�࿼��һ����������Ǵ��������ַ���Ϊ0����ֻ��һ���ַ�����
//		s = s;
//	}
//	while (start<end)
//	{
//		temp = s[start];
//		s[start] = s[end];
//		s[end] = temp;
//
//		start++;
//		end--;
//	}
//	printf("��ת����ַ���Ϊ:%s\n", s);
//
//}
//
//
//
//int main()
//{
//	int len = 0;
//	char s[10] = { 0 };
//	printf("�������ַ�����");
//	scanf("%s", &s);
//	len = strlen(s);
//	printf("��������ַ���Ϊ:%s,�ַ�������Ϊ:%d.\n", s, len);
//	reverseString(s, len);
//
//	return 0;
//}
//���������ַ������Խ��з�ת����ôһ�������أ���

#include<stdio.h>
#include<string.h>
void reverse(char* start, char* end) {
	char t;
	while (start<end)
	{
		t = *start;
		*start = *end;
		*end = t;

		start++;
		end--;

	}
}
int main()
{
	char arr[101];//����һ���ַ�������
	gets(arr);//����һ���ַ���
	char* p = arr;//���ַ�����Ԫ�ص�ַ����P

	while (*p!='\0')//��P�������һλ��ʱ�򣨴�ʱP����������飩
	{
		char* start = p;//��������ָ�룬һ������ͷ��һ������ĩβ
		char* end = p;
		while (*end != ' '&&*end != '\0')//����β��ָ�룬���ǿո񣬲��Ҳ���ĩβ���\0��ʱ��(end����һ����ַ��ֻ��*end���Ǵ����Ǹ�����)��
		{
			end++;//end����
		}
		//�����ַ�������.
		reverse(start, end - 1);//��Ϊ���Ƿ�ת�ַ�����ʱ�򣬴ӿ�ͷ�����һ���ַ����м���end-1���ַ������Բ��ܰ�\0���ȥ��
		if (*end != '\0') {//��end������Ǹ��ַ�λ�ò���ĩβ��ʱ�򣬾�˵����ת�ַ���û�з�ת�꣬���滹���أ�
			p = end + 1;//��Ϊend������Ե�ʣ�end����ָ���ǿո�
		}
		else //��ָ�����\0��ʱ��
			p = end;//P�ͽ����ˣ����ʱ��end�������\0����һ����˼��PҲ��\0��
		
	}
	puts(arr);//�ö��˺����Ϊʲô������P�������������ARR��������Ϊ��ַ���Ըı���������ݣ����ǲ��Ǹ��ƻ��߿�¡�����廹��ARR��

	//�����ַ���������
	int len = strlen(arr);
	reverse(arr, arr + len - 1);
	puts(arr);
	return 0;
}
//���ϣ������������ַ�����ת��һ���֣�����ûд��ģ����첹������11.14.



