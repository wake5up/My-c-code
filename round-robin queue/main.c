#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

int main()
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePop(&qu);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);
	QueuePop(&qu); 
	QueuePush(&qu, 5);
	QueuePush(&qu, 6);
	QueuePop(&qu);
	printf("%d\n", QueueFront(&qu));
	printf("%d\n", QueueBack(&qu));
	return 0;
}