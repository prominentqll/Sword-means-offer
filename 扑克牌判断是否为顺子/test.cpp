#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/*
问题描述：

从扑克牌中随机取5张，判断是不是一个顺子
其中A看成1，J,Q,K分别看成11，12，13，大小王可以看成0
也就是说输入的5个数字范围是0-13，其中0可以任意变换填充空缺


*/

int compare(const void* number1, const void* number2)//自定义的比较
{
	return *(int*)number1 - *(int*)number2;
}

bool  IsContinuous(int* numbers, int len)//从扑克牌中随机抽取5张牌，判断是不是顺子
{

	/*
	解题思路：

	首先把数组排序，统计数组中0的个数，最后统计排序后数组中相邻数字之间的空缺的个数
	如果空缺的个数小于或者等于0的个数，这个数组就是连续的，否则就是不连续的
	*/

	if (numbers == NULL || len <= 0)        
	{
		return false;
	}
	qsort(numbers, len, sizeof(int), compare);
	int numberofzero = 0;//0的个数
	int numberofgap = 0;//间隔的个数
	for (int i = 0; i < len && numbers[i] == 0; i++)
	{
		numberofzero++;	//计算数组中0的个数
	}
	int small = numberofzero;//small指向第一个非零数字
	int big = small + 1;//big指向下一个非零数字
	while (big < len)//0,1,3,4,5
	{
		if (numbers[small] == numbers[big])//出现对子,就不可能是顺子
		{
			return false;
		}
		numberofgap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return (numberofgap > numberofzero) ? false : true;//由于0可以当成任意数，因此可以用来填补空缺
}

int main()
{
	int arr[] = { 9,0,4,3,2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	if (IsContinuous(arr, len))
	{
		printf("是顺子\n");
	}
	else
	{
		printf("不是顺子\n");
	}

	int  arr1[] = { 1,3,0,4,5 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	if (IsContinuous(arr1, len1))
	{
		printf("是顺子\n");
	}
	else
	{
		printf("不是顺子\n");
	}


	int arr2[] = { 0,1,2,3,5 };
	int len2= sizeof(arr2) / sizeof(arr2[0]);
	if (IsContinuous(arr2, len2))
	{
		printf("是顺子\n");
	}
	else
	{
		printf("不是顺子\n");
	}


	int arr3[] = { 1,2,4,5,6 };
	int len3 = sizeof(arr3) / sizeof(arr3[0]);
	if (IsContinuous(arr3, len3))
	{
		printf("是顺子\n");
	}
	else
	{
		printf("不是顺子\n");
	}

	return 0;
}