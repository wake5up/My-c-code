#define _CRT_SECURE_NO_WARNINGS 1
#include"seqList.h"

void SeqListInit(SeqList* psl, size_t capacity)//申请空间并初始化
{
	psl->array = (SLDataType*)calloc(capacity, sizeof(SeqList));
	psl->capicity = capacity;
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)//删除整个顺序表
{
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capicity = 0;
		psl->size = 0;
	}
}

void CheckCapacity(SeqList* psl)//扩容
{
	if (psl->size >= psl->capicity)
	{
		psl->capicity *=2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)//后插
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)//后删
{
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//把x插到第一位数
{
	int i;
	CheckCapacity(psl);
	for (i = psl->size-1; i >=0; i--)
	{
		psl->array[i+1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl)//头删
{
	int i;
	for (i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//找到x的位置
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//在pos下标前插入x
{
	int i;
	CheckCapacity(psl);
	for (i = psl->array[psl->size - 1]; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//擦掉（移除）下标为pos的值
{
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)//移除x值
{
	SeqListErase(psl,SeqListFind(psl, x));
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//把pos下标的值替换为x
{
	psl->array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ",psl->array[i]);
	}
}

void SeqListBubbleSort(SeqList* psl)//冒泡排序
{
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

int SeqListBinaryFind(SeqList* psl, SLDataType x)//二分查找
{
	int left = 0;
	int right = psl->size - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->array[mid] > x)
		{
			right = mid-1;
		}
		else if (psl->array[mid] < x)
		{
			left = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* psl, SLDataType x)//移除所有x数据
{
	int i;
	int gap = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			gap++;
			psl->array[i] = psl->array[i + gap];
		}
	}
	psl->size -= gap;
}