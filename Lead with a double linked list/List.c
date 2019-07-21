#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void ListInit(List* plist)//��ʼ��
{
	plist->head = (ListNode*)malloc(sizeof(ListNode));
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}
void ListDestory(List* plist)//��������
{
	while (plist->head != plist->head->next)
	{
		ListPopFront(plist);
	}
	free(plist->head);
	plist->head = NULL;
}

void ListPushBack(List* plist, LTDataType x)//�Ӻ��������
{
	ListInsertFront(plist->head, x);
}
void ListPopBack(List* plist)//�Ӻ���ɾ����
{
	ListErase(plist->head->prev);
}
void ListPushFront(List* plist, LTDataType x)//��ǰ�������
{
	ListInsertAfter(plist->head, x);
}
void ListPopFront(List* plist)//��ǰ��ɾ����
{
	ListErase(plist->head->next);
}

ListNode* ListFind(List* plist, LTDataType x)//��x����
{
	ListNode* cur;
	for (cur = plist->head->next; cur != plist->head; cur = cur->next)
	{
		if (cur->data == x)
			return cur;
	}
	return NULL;
}
void ListInsertFront(ListNode* pos, LTDataType x)//��ǰ�������
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->prev;
	cur->data = x;
	cur->next = pos;
	pos->prev = cur;
	tmp->next = cur;
	cur->prev = tmp;
}
void ListInsertAfter(ListNode* pos, LTDataType x)//�Ӻ��������
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode * tmp = pos->next;

	cur->data = x;

	pos->next = cur;
	cur->prev = pos;
	tmp->prev = cur;
	cur->next = tmp;
}
void ListErase(ListNode* pos)//ɾ��posλ�õ�����
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x)//�Ƴ�x
{
	ListNode* cur=ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListDistinct(List* plist)//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ��
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
void ListMerge(List* plist1, List* plist2)//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
{
	ListNode *cur1 = plist1->head->next, *cur2 = plist2->head->next;
	//cur1��cur2������1������2�ĵ�һ������
	ListNode *tmp1, *tmp2;
	while (cur1 != plist1->head && cur2 != plist2->head)//˫�����������������
	{
		if (cur1->data > cur2->data)//�������1��ǰ�ڵ�����ݱ�����2�Ĵ�˵������2������ڵ�Ӧ�ò嵽����1�ĵ�ǰ�ڵ�ǰ��
		{
			tmp1 = cur1->prev; //����cur1��prev�ᱻ�޸ģ�������һ������
			tmp2 = cur2->next; //����cur2��next�ᱻ�޸ģ�������һ������

			cur1->prev = cur2; //cur1��������cur2
			cur2->next = cur1; //cur2��������cur1����������
			tmp1->next = cur2; //tmp1(cur1��prev)����������cur2
			cur2->prev = tmp1; //cur2����������tmp1����������

			cur2 = tmp2; //cur2�ҵ�������һ���ڵ�
		}
		else
		{
			cur1 = cur1->next; //���cur1��ֵ������С����ôֱ����������һ���ڵ�
		}
	}

	if (cur1 == plist1->head) //�������������list1��ĩβ�ˣ�֤��list2��û����������list2ʣ�µĽڵ��ֵ����list1������Ҫ��list2ʣ�µ����нڵ����list1����
	{
		tmp2 = plist2->head->prev; //��¼��Ҫ�ҵ����һ���ڵ㣬cur2������Ҫ�ҵĵ�һ���ڵ㣬Ҳ����Ҫ��cur2��tmp��һ�νڵ����cur1��ĩβ

		cur2->prev = cur1->prev; //��cur2����������list1�����һ���ڵ㣨��ʱcur1����list1��ͷ������cur1���������ľ���list1��β�ڵ㣩
		cur1->prev->next = cur2; //��list1��β�ڵ����������cur2��ǣ�ֳɹ�����ʱcur2��������list1��β��

		tmp2->next = cur1; //�м�����нڵ㲻��Ҫ��������һ��Ҫ������ֻ��β�ڵ�tmp����tmp����������list1��ͷ��
		cur1->prev = tmp2; //list1��ͷ����������tmp2��ǣ�ֳɹ���tmp2����list1��β�ڵ�
	}
	//���������������list2����ĩβ����ô˵��list2��Ԫ���Ѿ�ȫ������list1���ˣ���ֱ���ͷ�ͷ��

	free(plist2->head); //����ͷŵ�list2�н�ʣ��ͷ��
}
void ListPrint(List* plist)//�������
{
	ListNode * cur;

	printf("head->");
	for (cur = plist->head->next; cur != plist->head; cur = cur->next)
	{
		printf("%d->",cur->data);
	}
	printf("head");
}
