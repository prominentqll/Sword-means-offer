#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

/*
把数组排列成最小的数
{3,32,321} ==> 321323
*/
char str[100][10];
int My_Compare(const void *str1,const void *str2)   // 自定义比较
{
	static char ch_1[20];
	static char ch_2[20];

	char*s1 = (char *)str1;
	char*s2 = (char *)str2;

	sprintf(ch_1,"%s%s",s1,s2); //合并串
	sprintf(ch_2,"%s%s",s2,s1);

	return strcmp(ch_1,ch_2);
}

void Change(int *arr,int len)
{
	for(int i = 0;i < len;i++)
	{
		sprintf(str[i],"%d",arr[i]);//整数转字符串
	}
	qsort(str,len,sizeof(char)*10,My_Compare);
}

void Show(char (*str)[10],int len)
{
	for(int i = 0;i < len;i++)
	{
		printf("%s",str[i]);
	}	
	printf("\n");
}

int main()
{
	int arr[] = {3,32,321};
	int len = sizeof(arr) / sizeof (arr[0]);
	Change(arr,len);
	Show(str,len);
	return 0;
}
