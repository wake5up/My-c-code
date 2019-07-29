#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

//#define SWAP(a,b) {int tmp;tmp=*a;*a=*b;*b=tmp}

void dealMergeSort(int *arr, int *tmp, int start, int end)//�鲢����
{
	if (start >= end)//����Ҷ�ӽڵ�
	{
		return;
	}
	int mid = (start + end) / 2;//����������
	dealMergeSort(arr, tmp, start, mid);
	dealMergeSort(arr, tmp, mid + 1, end);
	//��ʵ����һ���������ĺ������

	int a = start;
	int b = mid+1;
	int c = a;
	for (; a <= mid&&b <= end; c++)//a��b��ȫ������c��ʱ������
	{
		if (arr[a] >= arr[b])
		{
			tmp[c] = arr[b];
			b++;
		}
		else
		{
			tmp[c] = arr[a];
			a++;
		}
	}
	//�ж�a����bû����ȫ������c�У���������ȥ
	for (; a <= mid; a++, c++)
	{
		tmp[c] = arr[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = arr[b];
	}
	int i;
	for (i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}
void mergesort(int *arr, int n)//���ù鲢����ӿ�
{
	int *tmp = (int *)malloc(sizeof(int)*n);//��ʱ����
	dealMergeSort(arr, tmp, 0, n - 1);
	free(tmp);
}

void swapArgs(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void dealQSort(int * arr, int start, int end)
{
	int flag = 1;

	if (start >= end)
	{
		return;
	}

	int i = start, j = end;
	while (i < j)
	{
		if (arr[i] > arr[j])
		{
			swapArgs(arr + i, arr + j);
			flag = !flag;
		}

		flag ? j-- : i++;
	}

	dealQSort(arr, start, i - 1);
	dealQSort(arr, i + 1, end);
}
void QSort(int * arr, int n)//���ÿ��Žӿ�
{
	dealQSort(arr, 0, n - 1);
}
