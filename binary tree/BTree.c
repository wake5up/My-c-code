#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"
#include"queue.h"

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
void BinaryTreePrevOrder(BTNode* root)//前序
{
	if (root != NULL)
	{
		printf("%c",root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}	
}
void BinaryTreeInOrder(BTNode* root)//中序
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root)//后序
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c", root->_data);
	}
}

void BinaryTreeLevelOrder(BTNode* root)//层序——》广度遍历排序
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





