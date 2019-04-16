#include<stdio.h>
#include<malloc.h>
#include<string.h>
bool  Intcrement(char *number)//在字符串上模拟数字的加法
{
	bool  isoverflow = false;
	int    ntakeover = 0;
	int   nlength = strlen(number);
	for (int i = nlength - 1; i >= 0; i--)
	{
		int  nsum = number[i] - '0' + ntakeover;//字符转数字
		if (i == nlength - 1)//一位数,直接加
		{
			nsum++;
		}
		if (nsum >= 10)
		{
			if (i == 0)
			{
				isoverflow = true;//第一位产生进位代表到达最大的n位数
			}
			else
			{
				nsum -= 10;
				ntakeover = 1;
				number[i] = nsum + '0';//数字转字符
			}
		}
		else
		{
			number[i] = nsum + '0';
			break;
		}

	}
	return    isoverflow;
}
void  PrintfNumber(char *number)
{
	bool  isbeginning0 = true;
	int len = strlen(number);
	for (int i = 0; i < len; i++)
	{
		if (isbeginning0&&number[i] != '0')
		{
			isbeginning0 = false;
		}
		if (!isbeginning0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
}
void Print1ToMaxOfNDigits(int n)//打印1到最大的n位数
{
	if (n <= 0)
	{
		return;
	}
	char *number = (char *)malloc(sizeof(char)*(n + 1));
	memset(number, '0', n);
	number[n] = '\0';
	while (!Intcrement(number))
	{
		PrintfNumber(number);
	}
}
int main()
{
	Print1ToMaxOfNDigits(4);
	return 0;
}