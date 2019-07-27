#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>

typedef char BTDataType;
#define ENDTAG '#'

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
<<<<<<< HEAD
void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeComplete(BTNode* root);
=======

void BinaryTreeLevelOrder(BTNode* root);
>>>>>>> e1caecfd4bbd6c79da02d1103f84d6994968cf96

#endif