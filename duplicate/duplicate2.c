#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

int count_r(const int *arr,int start, int end,int len)
{
	int count = 0;
	int i = 0;
	for (; i < len; i++)
	{
		if (arr[i] >= start&&arr[i] <= end)
		{
			count++;
		}
	}
	return count;
}
int duplicate1(const int *arr, int len)
{
	if (len < 0)
	{
		return 0;
	}
	int start = 1, end = len - 1;
	int count = 0;
	while (end >= start)
	{
		int mid = ((end - start) >> 1) + start;
		count = count_r(arr,start, mid,len);
		if (count>(mid - start + 1))
		{
			end = mid;
		}
		else
		{
			start = mid+1;
		}
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
	}
	return 0;
}
int main()
{
	int arr[] = { 2, 3, 5,4,3,2,6,7 };
	printf("%d", duplicate1(arr, SIZE(arr)));
	return 0;
}