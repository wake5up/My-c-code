#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"
#include"BTree.h"
#include <math.h>
#include <stdlib.h>

void QueueInit(Queue* pq)//初始化
{
	pq->front = NULL;
	pq->rear = NULL;
}

void QueueDestory(Queue* pq)//销毁队列
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

QueueNode * BuyQueueNode(QuDataType x)//创建一个队列
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->data = x;
	cur->next = NULL;
	return cur;
}

void QueuePop(Queue* pq)//头删
{
	if (pq->front == NULL)
	{
		return;
	}
	QueueNode* tmp = pq->front->next;
	free(pq->front);
	pq->front = tmp;
}

void QueuePush(Queue* pq, QuDataType x)//尾插
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

QuDataType QueueFront(Queue* pq)//返回头数据
{
	return pq->front->data;
}

int QueueIsEmpty(Queue* pq)//判空
{
	return pq->front == NULL;
}