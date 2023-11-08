//今天晚上，学习内容，两点，第一个fgets 第二个fguts。
//#include<stdio.h>
//int main(void)
//{
//	//fputs
//	char str[50] = {0};
//	puts("Enter strings (empty line to quit):");//直接打印意思
//	while (fgets(str,50,stdin) != NULL&&str[0]!='\n')//这里面其实是有两个判断，fgets输入的字符不为null，其次数组第一位不是换行符。
//	{
//		fputs(str, stdout);//满足刚才的俩条件，。就可以打印出来。打印到屏幕上。注意，stdout是屏幕，stdin是键盘。
//	}
//	puts("Done.");//都不满足了，就打印这个。
//
//	return 0;
//}

//刚才那个，有瑕疵，如果我们输入一个超级大的字符，只能打印49个字符和一个\0。所以又会重新申请空间，来打印剩下的字符
//#include<stdio.h>
//int main(void)
//{
//	char arr[10];
//	int i;
//	while (fgets(arr,10,stdin)!=NULL&&arr[0]!='\n')
//	{
//		i = 0;
//		while (arr[i] != '\n' && arr[i] != '\0') 
//			i++;
//			if (arr[i] == '\n')//如果输入的字符串没有9位，小于9.
//				arr[i] == '\0';//则后面的直接变成\0
//			else//arr[i] == '\0'//当输入的字符串大于9位
//				while (getchar() != '\n')//当输入的字符串，来到第9号位，后面还有东西，所以就不是\N，那么跳过后面的东西。
//					continue;//直接跳过还要继续执行；不能用break，因为会跳过整个循环，不会排去后面的字符、
//		puts(arr);//我补充一下，getchar()本质就是我输入了一串字符串，zxcvbnmzxc，到10位的时候，其实是多余了，。然后呢，这个C不是\N。continue,继续判断下一个字符
//		//如果下一个就是回车，那么终止循环，如果下一个还是字符，继续跳过，然后重复执行。这样就不会出现换行还打印出来的情况了，
//	}
//	puts("Done");
//
//
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//
//	long long int n;
//	int i = 0;
//	int arr[10000000] = { 0 };
//	long long int sum = 0;
//	scanf("%lld", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	while (arr[i])
//	{
//		sum += arr[i];
//		i++;
//	}
//
//	if (sum % 2 == 0)
//	{
//		printf("Bob");
//	}
//	if (sum % 2 == 1) {
//		printf("Alice");
//
//	}
//      
//
//	return 0;
//}  

#include<stdio.h>
int n;
int a[150], s[150];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		s[0] = 0;
		s[i] = s[i - 1] + a[i];
	}
	//printf("%s",((s[n])&1)?"Alice":"Bob");//利用换位与的关系判断奇偶性
	if (s[n] % 2)//如果真，那么是Alice
		printf("Alice");
	else {
		printf("Bob");
	}
	return 0;
}
//以上包含两个知识点和一道洛谷前缀和的例题
//换位与讲一下，比如，我们输入9，  1 0 0 1
//                          与1    0 0 0 1
//1&1=1；0&1=0；                   0 0 0 1 = 1；
// 
// 
// 所以结果是1；          输入8；  1 0 0 0 
//                           与1   0 0 0 1
//结果是                           0 0 0 0 = 0；
//所以三元运算符，是1的话就是Alice 是0 的话bob。
//所以换位与这个知识点，很有用.

