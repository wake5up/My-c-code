#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"
#include"BTree.h"
#include <math.h>
#include <stdlib.h>

void QueueInit(Queue* pq)//��ʼ��
{
	pq->front = NULL;
	pq->rear = NULL;
}

void QueueDestory(Queue* pq)//���ٶ���
{
	if (pq->front == NULL)
	{
		return;
	}

	while (pq->front)
	{
		QueuePop(pq);
	}
}

QueueNode * BuyQueueNode(QuDataType x)//����һ������
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->data = x;
	cur->next = NULL;
	return cur;
}

void QueuePop(Queue* pq)//ͷɾ
{
	if (pq->front == NULL)
	{
		return;
	}
	QueueNode* tmp = pq->front->next;
	free(pq->front);
	pq->front = tmp;
}

void QueuePush(Queue* pq, QuDataType x)//β��
{
	QueueNode * cur = BuyQueueNode(x);

	if (pq->front == NULL)
	{
		pq->front = pq->rear = cur;
	}
	else
	{
		pq->rear->next = cur;
		pq->rear = cur;
	}
}

QuDataType QueueFront(Queue* pq)//����ͷ����
{
	return pq->front->data;
}

int QueueIsEmpty(Queue* pq)//�п�
{
	return pq->front == NULL;
}