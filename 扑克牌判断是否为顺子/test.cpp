#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/*
����������

���˿��������ȡ5�ţ��ж��ǲ���һ��˳��
����A����1��J,Q,K�ֱ𿴳�11��12��13����С�����Կ���0
Ҳ����˵�����5�����ַ�Χ��0-13������0��������任����ȱ


*/

int compare(const void* number1, const void* number2)//�Զ���ıȽ�
{
	return *(int*)number1 - *(int*)number2;
}

bool  IsContinuous(int* numbers, int len)//���˿����������ȡ5���ƣ��ж��ǲ���˳��
{

	/*
	����˼·��

	���Ȱ���������ͳ��������0�ĸ��������ͳ���������������������֮��Ŀ�ȱ�ĸ���
	�����ȱ�ĸ���С�ڻ��ߵ���0�ĸ��������������������ģ�������ǲ�������
	*/

	if (numbers == NULL || len <= 0)        
	{
		return false;
	}
	qsort(numbers, len, sizeof(int), compare);
	int numberofzero = 0;//0�ĸ���
	int numberofgap = 0;//����ĸ���
	for (int i = 0; i < len && numbers[i] == 0; i++)
	{
		numberofzero++;	//����������0�ĸ���
	}
	int small = numberofzero;//smallָ���һ����������
	int big = small + 1;//bigָ����һ����������
	while (big < len)//0,1,3,4,5
	{
		if (numbers[small] == numbers[big])//���ֶ���,�Ͳ�������˳��
		{
			return false;
		}
		numberofgap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return (numberofgap > numberofzero) ? false : true;//����0���Ե�������������˿����������ȱ
}

int main()
{
	int arr[] = { 9,0,4,3,2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	if (IsContinuous(arr, len))
	{
		printf("��˳��\n");
	}
	else
	{
		printf("����˳��\n");
	}

	int  arr1[] = { 1,3,0,4,5 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	if (IsContinuous(arr1, len1))
	{
		printf("��˳��\n");
	}
	else
	{
		printf("����˳��\n");
	}


	int arr2[] = { 0,1,2,3,5 };
	int len2= sizeof(arr2) / sizeof(arr2[0]);
	if (IsContinuous(arr2, len2))
	{
		printf("��˳��\n");
	}
	else
	{
		printf("����˳��\n");
	}


	int arr3[] = { 1,2,4,5,6 };
	int len3 = sizeof(arr3) / sizeof(arr3[0]);
	if (IsContinuous(arr3, len3))
	{
		printf("��˳��\n");
	}
	else
	{
		printf("����˳��\n");
	}

	return 0;
}