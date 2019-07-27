#ifndef _SLIST_H_
#define _SLTST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef int SLTDataType; 
typedef struct SListNode 
{ 
	SLTDataType data;    
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* pphead, SLTDataType x); // ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x); // ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SListNode** pphead, SLTDataType x);
void SListRemoveAll(SListNode** pphead, SLTDataType x);
void SListPrint(SListNode* pphead);

void SListReverse(SListNode **pphead);
void SListReverse2(SListNode **pphead);

SListNode* getIntersectionNode(SListNode* headA, SListNode*headB);
SListNode *detectCycle(SListNode *head);


#endif