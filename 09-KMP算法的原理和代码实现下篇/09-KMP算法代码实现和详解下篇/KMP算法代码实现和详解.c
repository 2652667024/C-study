#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
void getnext(char* sub, int* next)//sub的字符串，next数组
{
	/*这里面是一个新的开始，我们只是为了next才做了这个函数，
	这个函数的存在就是为了找到，外面的j该回溯到哪个位置
	从而使其可以与主字符串完全对应上，然后统计出第一个对应上的
	字符所在的位置，然后输出。
	*/
	//next只是一个数组空间，里面存的是sub回溯到的位置数字
	int lensub = strlen(sub);
	next[0] = -1;//规定0为-1，1为0；
	next[1] = 0;

	int j = 2;//从二开始i的下标
	int k = 0;//k是i前面的一个索引，p[i] = k;很关键
	while (j < lensub)//说明i可以遍历整个子字符串
	{
		if (k == -1 || sub[j - 1] == sub[k])
		{
			next[j] = k + 1;
			j++;//直到i等于lensub。然后跳出循环
			k++;
		}
		else//在next[i]!=p[k]的时候，就意味着出现了一个全新的，需要从头开始，也就是0出，此时k==-1.
		{
			k = next[k];

		}
	}


}
/*

str代表主串
sub代表子串
pos代表从主串pos位置找一般只能从0开始，

*/
int kmp(char* str, char* sub, int pos)//参数的判断。
{
	assert(str != NULL && sub != NULL);//使str 和sub不为空的一个函数
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	if (lenstr == 0 || lensub == 0)
	{
		return -1;//若两个字符串有一个为0则直接返回-1；
	}
	if (pos < 0 || pos >= lenstr)
	{
		return -1;//pos在主字符串的范围之内，超过或小于0，就失败了.
	}
	int* next = (int*)malloc(sizeof(int) * lensub);//开辟一个next空间，他的长度是子字符串长度。
	assert(next != NULL);//再次提醒next不能为空。
	getnext(sub, next);//开始寻找子字符串回溯到的位置，也就是j回溯到第几位。.
	int i = pos;//遍历主串
	int j = 0;//遍历子字串
	while (i < lenstr && j < lensub)//i j都小于各自字符串长度，可以进入循环
	{
		if (j == -1 || str[i] == sub[j])//如果说，第i和j位的字符相等，那么就各自往下瞬移接着判断。
			//j==-1是没有公共后缀的意思。跟next[0] = -1一个意思。
		{
			i++;
			j++;
		}
		else//如果，第一个就不匹配，就会变成-1，然后各自++，就能越过第一个了，
		{
			j = next[j];//如果这俩字符不相等，那么，子字符串的j就回溯到，next函数中j的位置，并赋值给j接着判断
		}

	}
	if (j >= lensub)//如果j大于等于子字符串的长度
	{
		return i - j + 1;//也就是子字符串已经找到最后一个相等的了且期间没有不相等的。这时候返回i-j+1的值，就是主字符串中
		//找到子字符串的位置
	}
	return -1;//都主字符串中不包含子字符串的话，返回-1.i走完了，j还没有走完，就只能返回失败了，因为不存在。
}
int main()
{
	printf("%d\n", kmp("abcdabe", "abe", 0));
	printf("%d\n", kmp("ababce", "ae", 0));
	printf("%d\n", kmp("ababce", "ce", 0));


	return 0;
}