#define _CRT_SECURE_NO_WARNINGS 1

#include"slist.h"
#if 0 //1，选择程序段
int main()//测试
{
	SListNode *phead1;
	//SListNode *phead2;
	SListNode *tmp;
	SListNode *tmp2;
	SListInit(&phead1);
	//SListInit(&phead2);
	SListPushFront(&phead1, 8);
	tmp = phead1;
	SListPushFront(&phead1, 7);
	SListPushFront(&phead1, 6);
	SListPushFront(&phead1, 5);
	SListPushFront(&phead1, 4);
	SListPushFront(&phead1, 3);
	tmp2 = phead1;
	SListPushFront(&phead1, 2);
	SListPushFront(&phead1, 1);
	tmp->next = tmp2;
	//phead2->next = phead1->next->next;
	SListNode * ret = detectCycle(phead1);
	if (ret)
	{
		printf("%d\n", ret->data);
	}
	else
	{
		printf("NULL\n");
	}
	//SListDestory(&phead1);
	//SListDestory(&phead2);
	return 0;
}

#else
int main()//测试
{
	SListNode *phead;
	SListInit(&phead);
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 5);
	SListPushFront(&phead, 6);
	SListPushFront(&phead, 7);
	SListPushFront(&phead, 8);
	SListPushFront(&phead, 9);
	//SListPopFront(&phead);
	//SListPopFront(&phead);
	/*
	SListInsertAfter(SListFind(phead, 6), 9);
	SListEraseAfter(SListFind(phead, 4));
	SListRemove(&phead, 7);
	SListPrint(phead);
	*/
	//SListRemoveAll(&phead, 8);
	SListReverse2(&phead);
	SListPrint(phead);
	SListDestory(&phead);
	//SListPrint(phead);
	return 0;
}


#endif
//int main()//约瑟夫环问题，链表解决
//{
//	SListNode *phead;
//	SListNode *plast;
//	SListNode *cur;
//	int m = 11, n = 3;
//	int i;
//	SListInit(&phead);
//	SListPushFront(&phead, m);
//	plast = phead;
//	for (i = m - 1; i >= 1; i--)
//	{
//		SListPushFront(&phead, i);
//	}
//	plast->next = phead;
//	cur = plast;
//	for (; m > 1; m--)
//	{
//		for (i = 1; i < n; i++)
//		{
//			cur = cur->next;
//			printf("%d号报数字%d\n", cur->data, i);
//		}
//		printf("%d号被去掉\n", cur->next->data);
//		SListEraseAfter(cur);
//	}
//	printf("%d号最终获胜\n", cur->data);
//	free(cur);
//	return 0;
//}