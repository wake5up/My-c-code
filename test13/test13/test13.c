#define _CRT_SECURE_NO_WARNINGS 1
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
//
//2.
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5

//#include<stdio.h>
//#include<string.h>
//
//void Adjust_array(int str[10],int len)
//{
//	int i = 0;
//	int j = 0;
//	int left = 0;
//	int right = len-1;
//	int p[20] = {0};
//	for (j = 0; j < len; j++)
//	{
//		p[j] = str[j];
//	}
//	while (left <= right)
//	{
//		if (p[i] % 2 == 1)
//		{
//			str[left] = p[i];
//			i++;
//			left++;
//		}
//		else
//		{
//			str[right] = p[i];
//			i++;
//			right--;
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ",str[i]);
//	}
//}
//int main()
//{
//	int str[9] = {1,2,3,4,5,6,7,8,9};
//	int len = sizeof(str) / sizeof(str[0]) ;
//	Adjust_array(str,len);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//
//int Find_num(int arr[][3],int n)
//{
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			if (n == arr[i][j])
//				return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, {3,4,5} };
//	printf("��������Ҫ���ҵ�����:\n");
//	scanf("%d",&n);
//	int ret = Find_num(arr, n);
//	if (ret == 1)
//	{
//		printf("�ҵ��ˣ�\n");
//	}
//	else
//	{
//		printf("û�ҵ���\n");
//	}
//	system("pause");
//	return 0;
//}
