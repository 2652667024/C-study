//#include<stdio.h>
//#include<string.h>
//void reverseString(char* s, int nums) {
//	int start = 0;
//	int end = nums - 1;
//	char temp = 0;
//	if (nums == 1 || nums == 0) {//多考虑一个情况，就是传进来的字符串为0或者只有一个字符串，
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
//	printf("反转后的字符串为:%s\n", s);
//
//}
//
//
//
//int main()
//{
//	int len = 0;
//	char s[10] = { 0 };
//	printf("请输入字符串；");
//	scanf("%s", &s);
//	len = strlen(s);
//	printf("你输入的字符串为:%s,字符串长度为:%d.\n", s, len);
//	reverseString(s, len);
//
//	return 0;
//}
//基础连续字符串可以进行反转，那么一个句子呢？；

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
	char arr[101];//创建一个字符串数组
	gets(arr);//输入一串字符串
	char* p = arr;//将字符串首元素地址给到P

	while (*p!='\0')//当P不是最后一位的时候（此时P代表的是数组）
	{
		char* start = p;//创建两个指针，一个代表开头，一个代表末尾
		char* end = p;
		while (*end != ' '&&*end != '\0')//当结尾的指针，不是空格，并且不是末尾项的\0的时候(end代表一个地址，只有*end才是代表那个数字)。
		{
			end++;//end自增
		}
		//单个字符的逆置.
		reverse(start, end - 1);//因为我们反转字符串的时候，从开头到最后一个字符，中间是end-1个字符，所以不能把\0算进去，
		if (*end != '\0') {//当end代表的那个字符位置不是末尾的时候，就说明反转字符串没有反转完，后面还有呢，
			p = end + 1;//因为end的自增缘故，end现在指的是空格处
		}
		else //当指向的是\0的时候，
			p = end;//P就结束了，这个时候end和上面的\0就是一个意思，P也是\0。
		
	}
	puts(arr);//好多人很奇怪为什么上面是P，这里输出又是ARR，那是因为地址可以改变里面的内容，但是不是复制或者克隆，本体还是ARR。

	//整个字符串的逆置
	int len = strlen(arr);
	reverse(arr, arr + len - 1);
	puts(arr);
	return 0;
}
//以上，就是面试题字符串反转的一部分，还有没写完的，明天补，今日11.14.



