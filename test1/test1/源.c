#define _CRT_SECURE_NO_WARNINGS 1
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//
//2.使用函数实现两个数的交换。
//
//3.实现一个函数判断year是不是润年。
//
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//
//5.实现一个函数，判断一个数是不是素数。

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
//	printf("请输入需要的乘法口诀表数字:\n");
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
//	printf("请输入需要交换的两个数字:\n");
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
//	printf("请输入需要判断是否为闰年的年份:\n");
//	scanf("%d",&n);
//	if (year(n) == 1)
//		printf("%d年是闰年\n",n);
//	else
//		printf("%d年不是闰年\n",n);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//void menu()
//{
//	printf("*******************************\n");
//	printf("*********0.初始化数组**********\n");
//	printf("*********1.清空数组************\n");
//	printf("*********2.数组元素逆序********\n");
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
//		printf("请输入数字:\n");
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
//			printf("请输入正确的数字！\n");
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
//	/*printf("请输入需要判断素数的数字:\n");//判断一个数
//	scanf("%d",&n);*/
//	for (i = 100; i < 300; i++)//判断100到300之间是否为素数
//	{
//		Is_prime(i);
//		if (Is_prime(i) == 1)
//			printf("%d是素数\n", i);
//		else
//			printf("%d不是素数\n", i);
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

int Fac(int n, int a[10])//创建异或函数
{
	//相等的数字异或之后就成0了
	int temp = 0;//必须先初始化0，或a[0]
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
	printf("请输入数组个数:\n");
	scanf("%d",&n);
	printf("请输入数组元素:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	ret = Fac(n, a);
	printf("%d",ret);
	system("pause");
	return 0;
}