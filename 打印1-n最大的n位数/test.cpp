#include<stdio.h>
#include<malloc.h>
#include<string.h>
bool  Intcrement(char *number)//���ַ�����ģ�����ֵļӷ�
{
	bool  isoverflow = false;
	int    ntakeover = 0;
	int   nlength = strlen(number);
	for (int i = nlength - 1; i >= 0; i--)
	{
		int  nsum = number[i] - '0' + ntakeover;//�ַ�ת����
		if (i == nlength - 1)//һλ��,ֱ�Ӽ�
		{
			nsum++;
		}
		if (nsum >= 10)
		{
			if (i == 0)
			{
				isoverflow = true;//��һλ������λ����������nλ��
			}
			else
			{
				nsum -= 10;
				ntakeover = 1;
				number[i] = nsum + '0';//����ת�ַ�
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
void Print1ToMaxOfNDigits(int n)//��ӡ1������nλ��
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