#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>

typedef int LTDataType; 
typedef struct ListNode 
{
	LTDataType data; 
	struct ListNode* next;   
	struct ListNode* prev; 
}ListNode;

typedef struct List 
{ 
	ListNode* head;
}List;
void ListInit(List* plist); 
void ListDestory(List* plist);

void ListPushBack(List* plist, LTDataType x);
void ListPushBack(List* plist); 
void ListPushFront(List* plist, LTDataType x); 
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x); // ��pos��ǰ����в���
void ListInsertFront(ListNode* pos, LTDataType x); // ɾ��posλ�õĽڵ�
void ListInsertAfter(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);
void ListDistinct(List* plist);//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷ ָ��
void ListMerge(List* plist1, List* plist2);//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�

#endif