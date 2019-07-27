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
	pq->rear++;//rear���ڿռ�Ϊ�գ�β����һ���ռ�

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
	pq->front++;//front���ڿռ䲻Ϊ��
	pq->size--;
	if (pq->front - pq->data == QueueMAX)
	{
		pq->front = pq->data;
	}
}
QuDataType QueueFront(Queue* pq)
{
	if (pq->size==0)//����Ϊ��ʱ�����0
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
	if (pq->rear == pq->data)//rear�ռ�Ϊ�գ�������Ҫ�жϣ���front����Ҫ
	{
		return pq->data[QueueMAX - 1];
	}
	return *(pq->rear-1);
}