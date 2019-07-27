#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void ListInit(List* plist)//初始化
{
	plist->head = (ListNode*)malloc(sizeof(ListNode));
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}
void ListDestory(List* plist)//销毁链表
{
	while (plist->head != plist->head->next)
	{
		ListPopFront(plist);
	}
	free(plist->head);
	plist->head = NULL;
}

void ListPushBack(List* plist, LTDataType x)//从后面插数据
{
	ListInsertFront(plist->head, x);
}
void ListPopBack(List* plist)//从后面删数据
{
	ListErase(plist->head->prev);
}
void ListPushFront(List* plist, LTDataType x)//从前面插数据
{
	ListInsertAfter(plist->head, x);
}
void ListPopFront(List* plist)//从前面删数据
{
	ListErase(plist->head->next);
}

ListNode* ListFind(List* plist, LTDataType x)//找x数据
{
	ListNode* cur;
	for (cur = plist->head->next; cur != plist->head; cur = cur->next)
	{
		if (cur->data == x)
			return cur;
	}
	return NULL;
}
void ListInsertFront(ListNode* pos, LTDataType x)//从前面插数据
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->prev;
	cur->data = x;
	cur->next = pos;
	pos->prev = cur;
	tmp->next = cur;
	cur->prev = tmp;
}
void ListInsertAfter(ListNode* pos, LTDataType x)//从后面插数据
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode * tmp = pos->next;

	cur->data = x;

	pos->next = cur;
	cur->prev = pos;
	tmp->prev = cur;
	cur->next = tmp;
}
void ListErase(ListNode* pos)//删除pos位置的数据
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x)//移除x
{
	ListNode* cur=ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListDistinct(List* plist)//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针
{
	ListNode * cur;
	for (cur = plist->head->next; cur != plist->head->prev;)
	{
		if (cur->data==cur->next->data)
		{
			ListErase(cur->next);
		}
		else
		{
			cur = cur->next;
		}
	}
}
void ListMerge(List* plist1, List* plist2)//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
{
	ListNode *cur1 = plist1->head->next, *cur2 = plist2->head->next;
	//cur1和cur2是链表1和链表2的第一个数据
	ListNode *tmp1, *tmp2;
	while (cur1 != plist1->head && cur2 != plist2->head)//双链表遍历的跳出条件
	{
		if (cur1->data > cur2->data)//如果链表1当前节点的数据比链表2的大，说明链表2的这个节点应该插到链表1的当前节点前面
		{
			tmp1 = cur1->prev; //由于cur1的prev会被修改，这里做一个备份
			tmp2 = cur2->next; //由于cur2的next会被修改，这里做一个备份

			cur1->prev = cur2; //cur1左手拉起cur2
			cur2->next = cur1; //cur2右手拉起cur1，两手相连
			tmp1->next = cur2; //tmp1(cur1的prev)的右手拉起cur2
			cur2->prev = tmp1; //cur2的左手拉起tmp1，两手相连

			cur2 = tmp2; //cur2找到它的下一个节点
		}
		else
		{
			cur1 = cur1->next; //如果cur1的值反而较小，那么直接找他的下一个节点
		}
	}

	if (cur1 == plist1->head) //如果遍历结束后，list1到末尾了，证明list2还没结束，而且list2剩下的节点的值都比list1大，所以要把list2剩下的所有节点挂在list1后面
	{
		tmp2 = plist2->head->prev; //记录需要挂的最后一个节点，cur2就是需要挂的第一个节点，也就是要把cur2到tmp这一段节点挂在cur1的末尾

		cur2->prev = cur1->prev; //让cur2的左手拉起list1的最后一个节点（此时cur1就是list1的头，所以cur1的左手拉的就是list1的尾节点）
		cur1->prev->next = cur2; //让list1的尾节点的右手拉起cur2，牵手成功，此时cur2被挂在了list1的尾部

		tmp2->next = cur1; //中间的所有节点不需要操作，下一个要操作的只有尾节点tmp，让tmp的右手拉起list1的头。
		cur1->prev = tmp2; //list1的头的左手拉起tmp2，牵手成功，tmp2成了list1的尾节点
	}
	//如果遍历结束后，是list2到了末尾，那么说明list2的元素已经全部插入list1中了，则直接释放头。

	free(plist2->head); //最后，释放掉list2中仅剩的头部
}
void ListPrint(List* plist)//输出函数
{
	ListNode * cur;

	printf("head->");
	for (cur = plist->head->next; cur != plist->head; cur = cur->next)
	{
		printf("%d->",cur->data);
	}
	printf("head");
}
