#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
int duplicate(int arr[],int len)
{
	int i;
	if (len < 0)
	{
		return 0;
	}
	for (i = 0; i < len; i++)
	{
		if (arr[i] < 0 || arr[i]>len - 1)
		{
			return 0;
		}
		while (arr[i] != i)
		{
			if (arr[i] != i)
			{
				if (arr[i] != arr[arr[i]])
				{
					Swap(&arr[i], &arr[arr[i]]);
				}
				else
				{
					return arr[i];
				}
			}
		}
	}
	return 0;
}
int _main()
{
	int arr[] = {2,3,1,0,2,5,3};
	printf("%d", duplicate(arr, SIZE(arr)));
	return 0;
}