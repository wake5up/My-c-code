#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"
#include"queue.h"
<<<<<<< HEAD
#include"stack.h"
=======
>>>>>>> e1caecfd4bbd6c79da02d1103f84d6994968cf96

BTNode* BinaryTreeCreate(BTDataType* a)
{
	BTNode * cur;
	static int i = 0;

	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[i];
	i++;
	cur->_left = BinaryTreeCreate(a);
	cur->_right = BinaryTreeCreate(a);
	return cur;
}
void BinaryTreePrevOrder(BTNode* root)//ǰ��
{
	if (root != NULL)
	{
		printf("%c",root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}	
}
void BinaryTreeInOrder(BTNode* root)//����
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root)//����
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c", root->_data);
	}
}

void BinaryTreeLevelOrder(BTNode* root)//���򡪡�����ȱ�������
{
	Queue qu;
	BTNode * tmp;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c", tmp->_data);
		if (tmp->_left)
		{
			QueuePush(&qu, tmp->_left);
		}
		if (tmp->_right)
		{
			QueuePush(&qu, tmp->_right);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}

<<<<<<< HEAD
//�ǵݹ飬��ջʵ�ֲ���(ǰ��)
//1.��ӡ��
//2.��������Һ��ӣ���ô���к��ӽ�ջ������������ӣ���ôֱ�ӽ�������
//3.���û�����ӣ�ֱ������ջ����Ȼ���ջ
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;

	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))
	{
		putchar(cur->_data);

		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}

		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackFront(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

//�ǵݹ飬��ջʵ�ֲ���(����)
/*
1.��ѹ�Լ�
2.��������ӣ��������ӣ�֪������û��Ϊֹ
3.��ӡջ��ֵ���Լ���ջ��������Һ��ӣ������Һ���
*/
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;

	StackInit(&st, 100);

	while (1)
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
		}

		while (1)
		{
			cur = StackFront(&st);
			putchar(cur->_data);
			StackPop(&st);

			if (cur->_right)
			{
				cur = cur->_right;
				break;
			}

			if (StackIsEmpty(&st))
			{
				StackDestory(&st);
				return;
			}									
		}
	}
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st)) //��curΪ����ջΪ��ʱ��ѭ���������������������
	{
		for (; cur; cur = cur->_left)
			//1����Ŀǰ�ĸ��������е�����ѹջ��ֱ���Ҳ�������Ϊֹ
			//2����Ŀǰ���Һ�����Ϊ��������������������ѹջ
		{
			StackPush(&st, cur);
		}

		if (!StackIsEmpty(&st))
		{
			cur = StackFront(&st);
			//1�����ӱ�����Ϻ󣬵�һ��û�����ӵĽڵ��������ĵ�һ�����
			//2������Һ���Ϊ�գ���ʱջ�ｫ������һ��Ҫ���ʵĽڵ�
			//   ������Һ��ӣ���ô��ʱջ�ｫ�������Ǹ��Һ���Ϊ���������е�һ��û�����ӵĽڵ�
			putchar(cur->_data);
			//1������û�������ˣ����Դ�ӡ��
			StackPop(&st);
			cur = cur->_right;
			//1���������͸����������󣬱�������������
		}
	}
	StackDestory(&st);
}

		
//�ǵݹ飬��ջʵ�ֲ���(����)
int SeqFind(BTNode * src[], size_t size, BTNode * f)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (src[i] == f)
		{
			return 1;
		}
	}
	return 0;
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	BTNode * tmp = NULL;
	BTNode * visited[20];
	BTNode * printed[20];
	size_t size = 0, sizep = 0;
	int flag = 0;

	StackInit(&st, 100);

	StackPush(&st, root);
	while (cur || !StackIsEmpty(&st))
	{
		if (cur->_right)
		{
			if (!SeqFind(visited, size, cur->_right))
			{
				StackPush(&st, cur->_right);
				visited[size] = cur->_right;
				size++;
			}
		}

		if (cur->_left)
		{
			if (!SeqFind(visited, size, cur->_left))
			{
				StackPush(&st, cur->_left);
				visited[size] = cur->_left;
				size++;
				cur = cur->_left;
			}
		}
		else
		{
			if (!SeqFind(printed, sizep, cur->_right))
			{
				cur = cur->_right;
			}
		}

		if ((cur->_left == NULL || SeqFind(visited, size, cur->_left)) &&
			(cur->_right == NULL || SeqFind(visited, size, cur->_right)))
		{
			putchar(cur->_data);
			StackPop(&st);
			printed[sizep] = cur;
			sizep++;
			cur = StackFront(&st);
		}

	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode * cur = root;

	Stack st;
	int tag[32] = { 0 }; //���ӱ�����ǩ

	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))
	{
		for (; cur; cur = cur->_left) //�������򣬽�������ջ��curΪ��ʱ��������һ���ڵ���Һ���Ϊ�գ�ֻ������������ſ��ܽ��������while
		{
			StackPush(&st, cur); //push�����ᵼ��size+1
			tag[st.size] = 0; //������ջ�������ӣ�������������ӱ�����ǩ��0
		}

		//ֻҪ�����forִ�й�����һ��ѭ�����Һ��Ӳ�Ϊ�գ������while�ĺ�벿������������������
		while (!StackIsEmpty(&st) && tag[st.size] == 1) //���ӻ�û�������ʱ�����ܽ����ӡ
			//���ԣ�����ȷ����ֻ�������������������ʱ���Ż�������while
		{
			cur = StackFront(&st);
			putchar(cur->_data); //��ӡ��
			StackPop(&st); //pop�����ᵼ��size-1
			cur = NULL; //Ϊ��ѭ����������
		}

		if (!StackIsEmpty(&st))
		{
			tag[st.size] = 1; //��������֤��������������ϣ���������ǩ��1
			cur = StackFront(&st)->_right; //������������������
		}
	}
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)//�ж��Ƿ�����ȫ������
{
	Queue qu;
	BTNode * tmp;
	int leafflag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c", tmp->_data);

		QueuePop(&qu);
		if (leafflag)
		{
			if (tmp->_left || tmp->_right)
			{
				return 0;
			}
			continue;
		}

		if (tmp->_left && tmp->_right)
		{
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else if (tmp->_right && !tmp->_left)
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->_left)
			{
				QueuePush(&qu, tmp->_left);
			}
		}
	}
	QueueDestory(&qu);
	return 1;
}

void BinaryTreeDesotry(BTNode* root)
{
	BTNode *left, *right;
	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDesotry(left);	
		BinaryTreeDesotry(right);
	}
}
=======

>>>>>>> e1caecfd4bbd6c79da02d1103f84d6994968cf96



