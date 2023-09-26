#include<stdio.h>
#include<stdlib.h>
//构建结构体，包含data，字符串和len长度.

//众所周知，KMP算法言简意赅，但是包含的东西却是最多的，所以我把这个
//内容分成几个小块讲，一步一写
//今天主要是创建架构体和初始化
//外加理解什么是前缀后缀最大值
//
// 以下皆是注释讲解。可随时观看，
// 前缀，顾名思义，随机选一个值，他前面存在的东西都叫前缀
// {ababababababac}这个的前缀。就是{a,ab,aba,abab,,,,}直到到达C之前。
// 这个就是前缀。
// 后缀跟前缀一样、从c开始，列如{c,ac,bac,abac  ,,,,}等。
// 既然我们知道，什么是前缀后缀了，最大值，是什么呢
// 就是相同的一样的字符存在最多的数，就是最大比如上面那个例子，最大值就是0
// 因为没有一个可以跟含有C的相匹配。
//至于为啥讲这个最大数，往下看就了解了，




//我们要谈论一个问题，就是直到最大值，还有前缀后缀能干什么，这个KMP算法，实际就是主不动，客动。
//也就是，如何利用最大值达到我们移动子串的目的。。
//next数组的表示这个地方应该是该回溯的地方
//

typedef struct String{
	char* data;
	int len;

}String;
//初始化
String* initString()
{
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;
}
//写一个给字符串赋值的一个函数，
void stringAssign(String* s,char* data)
{
	if (s->data)
	{
		free(s->data);//如果s-》data存在数，要释放掉，
	}
	int len = 0;
	char* temp = data;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (len == 0)
	{
		s->data = NULL;
		s->len = 0;
	}
	else
	{
		temp = data;
		s->len = len;
		s->data = (char*)malloc(sizeof(char) * (len + 1));//因为有个\0
		for (int i = 0; i < len; i++, temp++)
		{
			s->data[i] = *temp;

		}
	}
}
void printString(String* s)
{
	for (int i = 0; i < s->len; i++)
	{
		printf(i == 0 ? " %c " : " ->%c ", s->data[i]);
	}
	printf("\n");
}
int main()
{
	String* s = initString();
	//String* s1 = initString();
	stringAssign(s,"abcdef");
	printString(s);

	return 0;
}