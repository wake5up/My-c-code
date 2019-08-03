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
//�ݹ����
void dealQSort(int * arr, int start, int end)//��������
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

int Partition(int * arr, int start, int end)//����ȡ�з���ȡkey��
{
	int mid = (start + end) / 2;
	if (arr[start] > arr[mid])
	{
		swapArgs(arr+start,arr+mid);
	}
	if (arr[mid] > arr[end])
	{
		swapArgs(arr+mid,arr+end);
	}
	if (arr[start] > arr[mid])
	{
		swapArgs(arr+start,arr+mid);
	}
	if (end - start <= 2)
	{
		return mid;
	}
	swapArgs(arr+mid,arr+end-1);
	
	int i = start + 1;
	int j = end - 2;
	while (arr[i] > arr[end - 1])
	{
		i++;
	}
	while (arr[j] > arr[end - 1])
	{
		j--;
	}
	while (i < j)
	{
		swapArgs(arr + i, arr + j);
		i++;
		j--;
		while (arr[i] > arr[end - 1])
		{
			i++;
		}
		while (arr[j] > arr[end - 1])
		{
			j--;
		}
	}
	swapArgs(arr + i, arr + end - 1);
	return i;
}

void InsertSort(int * arr, int n)//��������
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = arr[i];//��������

		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];//ǰһ�����ݸ�ֵ����һ������
		}
		arr[j] = tmp;//�ѱ�������ݸ�ֵ������С�ĺ��棬�������ǰ��
	}
}

void dealHQSort(int * arr, int start, int end)
{
	if (end - start > INSERT_SORT_LENTH)
	{
		int pivot = Partition(arr, start, end);
		dealHQSort(arr, start, pivot - 1);
		dealHQSort(arr, pivot + 1, end);
	}
	else
	{
		InsertSort(arr + start, end - start + 1);
	}
}

void HQSort(int * arr, int n)
{
	dealHQSort(arr, 0, n - 1);
	//QuickSortNonR(arr, 0, n - 1);
}

void ShellSort(int * arr, int n)//ϣ������
{
	int i, j, k;
	int tmp;
	int gap = n / 2;//����Ԫ�صĿ��

	for (; gap > 0; gap /= 2)
	{
		for (k = 0; k < gap; k++)
		{
			for (i = k + gap; i < n; i += gap)
			{
				tmp = arr[i];

				for (j = i; j > 0 && arr[j - gap] > tmp; j -= gap)
				{
					arr[j] = arr[j - gap];
				}
				arr[j] = tmp;
			}
		}
	}
}
