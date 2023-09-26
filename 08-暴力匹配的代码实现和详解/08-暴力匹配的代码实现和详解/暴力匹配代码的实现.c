#include<stdio.h>
#include<stdlib.h>
//创建结构体，里面有char类型数组，和一个LEN记载长度。
typedef struct string
{
	char* data;//char类型的指针，一次跳一个字节.
	int len;//定义一个len为字符串长度
}string;
//初始化结构体，以便开始进行储存和匹配
string* initstring()
{
	string* S = (string*)malloc(sizeof(string));
	S->data = NULL;
	S->len = 0;
	return S;
}
//初始化完成之后开始准备在字符串中写入内容进行比较.
void stringassign(string* s, char* data)
{
	//首先考虑一个情况，那就是开辟空间的时候，data内部有没有东西，也就是野指针
	if (s->data)//如果S的data有东西那就是不为NULL，那么就要释放掉他
	{
		free(s->data);
	}
	int len = 0;//将LEN初始化，
	char* temp = data;//把data的字符串传递给temp的指针里面，
	while (*temp)//不为空
	{
		len++;
		temp++;//自我遍历，总结len，直到temp指到\0为止，就跳出循环了，
	}
	if (len == 0)//遍历完，len为0，说明没有字符串传进来。
	{
		s->data = NULL;
		s->len = 0;
	}
	else
	{
		temp = data;//len不等于0，那么直接将data的字符内容赋值给temp。
		s->len = len;//开始总结，
		s->data = (char*)malloc(sizeof(char) * (len + 1));//计算添加的字符串长度，多加1，因为存在/0。
		for (int i = 0; i < len; i++,temp++)
		{
			s->data[i] = *temp;//将temp（data）的内容按0到∞的顺序存进去，*temp是将内容数字化了，存的是地址。

		}
	}
}
void printstring(string* s)
{
	for (int i = 0; i < s->len; i++)
	{
		printf(i == 0 ? "%c": "->%c", s->data[i]);//这个方法更便捷

	}
	printf("\n");
}
//暴力匹配的真实原理
void forcematch(string* master, string* sub)
{
	int i = 0;
	int j = 0;
	while (i < master->len && j<sub->len)//如果i j分别小于总长度，那么可以运行.
	{
		if (master->data[i] == sub->data[j])//在第i  j 位的时候，相同字符，就各自加一
		{
			i++;
			j++;

		}
		else
		{
			i = i - j + 1;//i往下移动一位，
			j = 0;//j从0开始，重新对比，

		}
	}
	if (j = sub->len)//当J的数字为子分支的长度时。说明子分支遍历完了，且没有遇到不一样的，可以通过。
	{
		printf("匹配成功\n");
	}
	else
	{
		printf("匹配失败\n");
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
//在输入字符串储存的过程中，用到了指针的相关知识，
//          int num = 1;
//我们知道，int *ptr = &num;
//          也就是说，ptr里面存的是，num的地址，*了就结出来一个值。
//          同理。*temp是把data的字符串解出来。
//                从第一位开始，直到\0结束，结合for（）里面的temp++.就是将整个字符串存进去了，

//不会的小伙伴，可以再看看指针一节的讲解.
//明天学习KMP算法。