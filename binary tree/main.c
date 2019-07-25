#define _CRT_SECURE_NO_WARNINGS 1

#include"BTree.h"

int main()
{
	BTNode * testTree = BinaryTreeCreate("ABDF####CE#GH##I#J###");

	BinaryTreePrevOrder(testTree);
	putchar('\n');
	BinaryTreeInOrder(testTree);
	putchar('\n');
	BinaryTreePostOrder(testTree);
	putchar('\n');
	BinaryTreeLevelOrder(testTree);
	putchar('\n');
	return 0;
}

//��ŵ������
//void move(char pos1, char pos2)//�ƶ����躯��
//{
//	printf("%c-->%c\n", pos1, pos2);
//}
//void Hanoi(int n, char pos1, char pos2, char pos3)
//{
//	if (n == 1)
//	{
//		move(pos1, pos3);//�ݹ����
//	}
//	else
//	{
//		Hanoi(n - 1, pos1, pos3, pos2);
//		move(pos1, pos3);
//		Hanoi(n - 1, pos2, pos1, pos3);
//	}
//}
//int main()
//{
//	int n;
//	printf("�����뺺ŵ��������:");
//	scanf("%d", &n);
//	Hanoi(n, 'A', 'B', 'C');
//	return 0;
//}