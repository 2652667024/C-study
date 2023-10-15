//#include<stdio.h>
//
//void twobanarray(int* arr, int* str)
//{
//	//开始二分查找的代码实现
//	for (int i = 1; i < str; i++)
//	{
//		//二分查找位置
//		int start = 0;
//		int end = i - 1;
//
//		while (start <= end)
//		{
//			int mid = (start + end) / 2;
//			if (arr[i] < arr[mid])
//			{
//				start = mid + 1;
//			}
//			else
//			{
//				end = mid - 1;
//			}
//               
//		}
//		 int temp = arr[i];
//		     for (end = i-1; end >= start; end--)
//		     {
//			   arr[end+1] = arr[end];
//
//		     }
//		       arr[start] = temp;
//	}
//}
////void insertSortBinary(int arr[], int str)
////{
////    int i, j;
////    for (i = 1; i < str; i++)
////    {
////        if (arr[i] < arr[i - 1])
////        {
////            int temp = arr[i];
////            int left = 0, right = i - 1;
////            while (left <= right)
////            {
////                int mid = (left + right) / 2;
////                if (arr[mid] < temp)
////                {
////                    left = mid + 1;
////                }
////                else
////                {
////                    right = mid - 1;
////                }
////            }
////            //只是比较次数变少了，交换次数还是一样的
////            for (j = i; j > left; j--)
////            {
////                arr[j] = arr[j - 1];
////            }
////            arr[left] = temp;
////        }
////    }
////}
//int main()
//{
//	int arr[] = { 1,9,6,8,7,5 };
//	int str = sizeof(arr) / sizeof(arr[0]);
//	twobanarray(arr,str);
//   /* insertSortBinary(arr, str);*/
//	return 0;
//}


#include<stdio.h>
//int str 传递的是整数，而不是指针
void twobanarray(int* arr, int str)
{
    //开始二分查找的代码实现
    for (int i = 1; i < str; i++)//
    {
        //二分查找位置
        int start = 0;
        int end = i - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[i] > arr[mid]) //已排序部分找到比arr[i]大的
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }

        }
        int temp = arr[i];
        for (end = i - 1; end >= start; end--)
        {
            arr[end + 1] = arr[end];

        }
        arr[start] = temp;
    }
}

int main()
{
    int arr[] = {9,8,5,4,3,7,1,2};
    int str = sizeof(arr) / sizeof(arr[0]);
    twobanarray(arr, str);

    // 打印排序后的数组
    for (int i = 0; i < str; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
