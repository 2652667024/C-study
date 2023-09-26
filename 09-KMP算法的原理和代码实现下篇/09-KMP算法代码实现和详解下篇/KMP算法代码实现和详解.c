#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
void getnext(char* sub, int* next)//sub���ַ�����next����
{
	/*��������һ���µĿ�ʼ������ֻ��Ϊ��next���������������
	��������Ĵ��ھ���Ϊ���ҵ��������j�û��ݵ��ĸ�λ��
	�Ӷ�ʹ����������ַ�����ȫ��Ӧ�ϣ�Ȼ��ͳ�Ƴ���һ����Ӧ�ϵ�
	�ַ����ڵ�λ�ã�Ȼ�������
	*/
	//nextֻ��һ������ռ䣬��������sub���ݵ���λ������
	int lensub = strlen(sub);
	next[0] = -1;//�涨0Ϊ-1��1Ϊ0��
	next[1] = 0;

	int j = 2;//�Ӷ���ʼi���±�
	int k = 0;//k��iǰ���һ��������p[i] = k;�ܹؼ�
	while (j < lensub)//˵��i���Ա����������ַ���
	{
		if (k == -1 || sub[j - 1] == sub[k])
		{
			next[j] = k + 1;
			j++;//ֱ��i����lensub��Ȼ������ѭ��
			k++;
		}
		else//��next[i]!=p[k]��ʱ�򣬾���ζ�ų�����һ��ȫ�µģ���Ҫ��ͷ��ʼ��Ҳ����0������ʱk==-1.
		{
			k = next[k];

		}
	}


}
/*

str��������
sub�����Ӵ�
pos���������posλ����һ��ֻ�ܴ�0��ʼ��

*/
int kmp(char* str, char* sub, int pos)//�������жϡ�
{
	assert(str != NULL && sub != NULL);//ʹstr ��sub��Ϊ�յ�һ������
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	if (lenstr == 0 || lensub == 0)
	{
		return -1;//�������ַ�����һ��Ϊ0��ֱ�ӷ���-1��
	}
	if (pos < 0 || pos >= lenstr)
	{
		return -1;//pos�����ַ����ķ�Χ֮�ڣ�������С��0����ʧ����.
	}
	int* next = (int*)malloc(sizeof(int) * lensub);//����һ��next�ռ䣬���ĳ��������ַ������ȡ�
	assert(next != NULL);//�ٴ�����next����Ϊ�ա�
	getnext(sub, next);//��ʼѰ�����ַ������ݵ���λ�ã�Ҳ����j���ݵ��ڼ�λ��.
	int i = pos;//��������
	int j = 0;//�������ִ�
	while (i < lenstr && j < lensub)//i j��С�ڸ����ַ������ȣ����Խ���ѭ��
	{
		if (j == -1 || str[i] == sub[j])//���˵����i��jλ���ַ���ȣ���ô�͸�������˲�ƽ����жϡ�
			//j==-1��û�й�����׺����˼����next[0] = -1һ����˼��
		{
			i++;
			j++;
		}
		else//�������һ���Ͳ�ƥ�䣬�ͻ���-1��Ȼ�����++������Խ����һ���ˣ�
		{
			j = next[j];//��������ַ�����ȣ���ô�����ַ�����j�ͻ��ݵ���next������j��λ�ã�����ֵ��j�����ж�
		}

	}
	if (j >= lensub)//���j���ڵ������ַ����ĳ���
	{
		return i - j + 1;//Ҳ�������ַ����Ѿ��ҵ����һ����ȵ������ڼ�û�в���ȵġ���ʱ�򷵻�i-j+1��ֵ���������ַ�����
		//�ҵ����ַ�����λ��
	}
	return -1;//�����ַ����в��������ַ����Ļ�������-1.i�����ˣ�j��û�����꣬��ֻ�ܷ���ʧ���ˣ���Ϊ�����ڡ�
}
int main()
{
	printf("%d\n", kmp("abcdabe", "abe", 0));
	printf("%d\n", kmp("ababce", "ae", 0));
	printf("%d\n", kmp("ababce", "ce", 0));


	return 0;
}