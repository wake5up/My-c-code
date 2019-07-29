#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))

void printArray(int * arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main()
{
	int a[] = { 7, 4, 2, 1, 8, 9, 3, 6 };

	mergesort(a, ARRSIZE(a));
	printArray(a, ARRSIZE(a));

	QSort(a, ARRSIZE(a));
	printArray(a, ARRSIZE(a));

	return 0;
}