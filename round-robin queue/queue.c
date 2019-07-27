#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

void QueueInit(Queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueueDestory(Queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}

void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size + 1 == QueueMAX)
	{
		return;
	}
	/*
	if (pq->rear + 1 - QueueMAX == pq->data &&
	pq->front == pq->data ||
	pq->rear + 1 == pq->front)
	{
	return;
	}
	*/
	*pq->rear = x;
	pq->rear++;//rear所在空间为空，尾部下一个空间

	pq->size++;

	if (pq->rear - pq->data == QueueMAX)
	{
		pq->rear = pq->data;
	}
}
void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;//front所在空间不为空
	pq->size--;
	if (pq->front - pq->data == QueueMAX)
	{
		pq->front = pq->data;
	}
}
QuDataType QueueFront(Queue* pq)
{
	if (pq->size==0)//数组为空时，输出0
	{
		return (QuDataType)-1;
	}
	return *pq->front;
}
QuDataType QueueBack(Queue* pq)
{
	if (pq->size == 0)
	{
		return (QuDataType)-1;
	}
	if (pq->rear == pq->data)//rear空间为空，所以需要判断，而front不需要
	{
		return pq->data[QueueMAX - 1];
	}
	return *(pq->rear-1);
}