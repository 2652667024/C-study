#include<stdio.h>
#include<stdlib.h>
#define NUM 5
typedef struct hashlist
{
	int num;
	char* data;

}hashlist;
//初始化哈希表
hashlist* initlist()
{
	hashlist* list = (hashlist*)malloc(sizeof(hashlist));
	list->num = 0;
	list->data = (char*)malloc(sizeof(char) * NUM);
	for (int i = 0;i<NUM;i++)//将哈希表的内容全部初始化为0
	{
		list->data[i] = 0;
	}
	return list;
}
int hash(int data)//定义一个哈希函数传入的是ascii值
{
	return data % NUM;//模上NUM
}
void put(hashlist*list,int data)//将写的ASCII值给到list中
{
	int index = hash(data);//用index来存哈希函数的返回值例如，94 % NUM = 2，所以index = 2
	if (list->data[index] != 0)//发生冲突了综上，index = 2
	{
		int count = 1;
		while (list->data[index]!=0)//当index = 2时。
		{
			index = hash(hash(data) + count);//index就顺位下移一个位置，存到那个位置离去
			count++;//如果下一个位置有数，就要再往下存。
		}
	}
	list->data[index] = data;//最后将data存到index可以存的地方
}


int main()
{
	hashlist* list = initlist();
	put(list,0);
	put(list,1);
	put(list,6);
	put(list,11);
	put(list,16);
	printf("%d\n",list->data[0]);
	printf("%d\n",list->data[1]);
	printf("%d\n",list->data[2]);
	printf("%d\n",list->data[3]);
	printf("%d\n",list->data[4]);
	//运行案例，我们规定长度为5，那么取模的时候。只能%5.结果站data[]里面的位置，然后要是有俩抢一个，就顺位占用第二个。依次排列
	return 0;
}