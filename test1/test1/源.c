#define _CRT_SECURE_NO_WARNINGS 1
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
//
//2.ʹ�ú���ʵ���������Ľ�����
//
//3.ʵ��һ�������ж�year�ǲ������ꡣ
//
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
//
//5.ʵ��һ���������ж�һ�����ǲ���������

//#include<stdio.h>
//void cheng(int n)
//{
//	int i, j;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%4d*%d=%d", j, i, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n;
//	printf("��������Ҫ�ĳ˷��ھ�������:\n");
//	scanf("%d",&n);
//	cheng(n);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void swap(int n, int m)
//{
//	int tmp;
//	tmp = n;
//	n = m;
//	m = tmp;
//	printf("%d %d",n,m);
//}
//int main()
//{
//	int n, m;
//	printf("��������Ҫ��������������:\n");
//	scanf("%d%d",&n,&m);
//	swap(n,m);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//int year(int n)
//{
//	if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int n;
//	printf("��������Ҫ�ж��Ƿ�Ϊ��������:\n");
//	scanf("%d",&n);
//	if (year(n) == 1)
//		printf("%d��������\n",n);
//	else
//		printf("%d�겻������\n",n);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//void menu()
//{
//	printf("*******************************\n");
//	printf("*********0.��ʼ������**********\n");
//	printf("*********1.�������************\n");
//	printf("*********2.����Ԫ������********\n");
//	printf("*******************************\n");
//}
//void init(int a[5])
//{
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%d",&a[i]);
//	}
//
//}
//void empty(int a[5])
//{
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		a[i] = 0;//*(a+i)=0
//	}
//}
//void reverse(int ret,int a[5])
//{
//	int left=0, right=0,temp,i;
//	right = ret - 1;
//	while (left <= right)
//	{
//		temp=a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;
//		right--;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ",a[i]);
//	}
//	/*int i;
//	for (i = 4; i >=0; i--)
//	{
//		printf("%d  ",a[i]);
//	}*/
//}
//int main()
//{
//	int n=0,ret;
//	int a[5] = {1,2,3,4,5};
//	while (1)
//	{
//		menu();
//		printf("����������:\n");
//		scanf("%d",&n);
//		if (n == 0)
//			init(a);
//		else if (n == 1)
//			empty(a);
//		else if (n == 2)
//		{
//			ret = sizeof(a) / sizeof(a[0]);
//			reverse(ret,a);
//		}
//		else
//			printf("��������ȷ�����֣�\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int Is_prime(int n)
//{
//	int i;
//	for (i = 2; i < sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	if (i>sqrt(n))
//	return 1;
//}
//int main()
//{
//	int n;
//	int i;
//	/*printf("��������Ҫ�ж�����������:\n");//�ж�һ����
//	scanf("%d",&n);*/
//	for (i = 100; i < 300; i++)//�ж�100��300֮���Ƿ�Ϊ����
//	{
//		Is_prime(i);
//		if (Is_prime(i) == 1)
//			printf("%d������\n", i);
//		else
//			printf("%d��������\n", i);
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//
//}

#include<stdio.h>
#include<stdlib.h>

int Fac(int n, int a[10])//���������
{
	//��ȵ��������֮��ͳ�0��
	int temp = 0;//�����ȳ�ʼ��0����a[0]
	int i;
	for (i = 0; i < n; i++)
	{
		temp ^= a[i];
	}
	return temp;
}
int main()
{
	int i, n;
	int ret;
	int a[10];
	printf("�������������:\n");
	scanf("%d",&n);
	printf("����������Ԫ��:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	ret = Fac(n, a);
	printf("%d",ret);
	system("pause");
	return 0;
}