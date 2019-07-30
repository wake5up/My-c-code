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
//递归快排
void dealQSort(int * arr, int start, int end)//快速排序
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

int Partition(int * arr, int start, int end)//三数取中法（取key）
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

void InsertSort(int * arr, int n)//插入排序
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = arr[i];//保存数据

		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];//前一个数据赋值给后一个数据
		}
		arr[j] = tmp;//把保存的数据赋值给比他小的后面，比他大的前面
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

void ShellSort(int * arr, int n)//希尔排序
{
	int i, j, k;
	int tmp;
	int gap = n / 2;//交换元素的跨度

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
