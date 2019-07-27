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

ListNode* ListFind(List* plist, LTDataType x); // 在pos的前面进行插入
void ListInsertFront(ListNode* pos, LTDataType x); // 删除pos位置的节点
void ListInsertAfter(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);
void ListDistinct(List* plist);//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针
void ListMerge(List* plist1, List* plist2);//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的

#endif