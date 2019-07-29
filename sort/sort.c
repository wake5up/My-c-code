#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

//#define SWAP(a,b) {int tmp;tmp=*a;*a=*b;*b=tmp}

void dealMergeSort(int *arr, int *tmp, int start, int end)//归并排序
{
	if (start >= end)//到了叶子节点
	{
		return;
	}
	int mid = (start + end) / 2;//分左右子树
	dealMergeSort(arr, tmp, start, mid);
	dealMergeSort(arr, tmp, mid + 1, end);
	//其实就是一个二叉树的后序遍历

	int a = start;
	int b = mid+1;
	int c = a;
	for (; a <= mid&&b <= end; c++)//a或b完全拷贝到c里时，跳出
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
	//判断a还是b没有完全拷贝到c中，并拷贝进去
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
void mergesort(int *arr, int n)//调用归并排序接口
{
	int *tmp = (int *)malloc(sizeof(int)*n);//临时数组
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
void QSort(int * arr, int n)//调用快排接口
{
	dealQSort(arr, 0, n - 1);
}
