// 16ReverseList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Utilities\List.cc"

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;

		if (pNext == NULL)
			pReverseHead = pNode;

		pNode->m_pNext = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}

//============================= Test Code ===================================
ListNode* Test(ListNode* pHead)
{
	printf("The original list is : \n");
	PrintList(pHead);

	ListNode* pReverseHead = ReverseList(pHead);
	printf("The result is: \n");
	PrintList(pReverseHead);

	return pReverseHead;
}

void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	

	ListNode*pReverseHead = Test(pNode1);

	DestroyList(pReverseHead);

}

// only have one node
void Test2()
{
	ListNode* pNode = CreateListNode(1);
	ListNode* pReverseHead = Test(pNode);
	DestroyList(pReverseHead);
}

// NULL
void Test3()
{
	Test(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	return 0;
}

