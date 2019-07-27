#define _CRT_SECURE_NO_WARNINGS 1
#include"seqList.h"

void SeqListInit(SeqList* psl, size_t capacity)//����ռ䲢��ʼ��
{
	psl->array = (SLDataType*)calloc(capacity, sizeof(SeqList));
	psl->capicity = capacity;
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)//ɾ������˳���
{
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capicity = 0;
		psl->size = 0;
	}
}

void CheckCapacity(SeqList* psl)//����
{
	if (psl->size >= psl->capicity)
	{
		psl->capicity *=2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)//���
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)//��ɾ
{
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//��x�嵽��һλ��
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

void SeqListPopFront(SeqList* psl)//ͷɾ
{
	int i;
	for (i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//�ҵ�x��λ��
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

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//��pos�±�ǰ����x
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

void SeqListErase(SeqList* psl, size_t pos)//�������Ƴ����±�Ϊpos��ֵ
{
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)//�Ƴ�xֵ
{
	SeqListErase(psl,SeqListFind(psl, x));
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//��pos�±��ֵ�滻Ϊx
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

void SeqListBubbleSort(SeqList* psl)//ð������
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

int SeqListBinaryFind(SeqList* psl, SLDataType x)//���ֲ���
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

void SeqListRemoveAll(SeqList* psl, SLDataType x)//�Ƴ�����x����
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