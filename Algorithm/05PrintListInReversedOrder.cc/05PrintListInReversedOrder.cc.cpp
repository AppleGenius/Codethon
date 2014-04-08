// 05PrintListInReversedOrder.cc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/List.cc"
#include <stack>

void PrintListReversed_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}


void PrintListReversed_Recursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
		{
			PrintListReversed_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}

//================================== Test code ===================================================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversed_Iteratively(pHead);
	printf("\n");
	PrintListReversed_Recursively(pHead);
}

// Normal
void Test1()
{
	printf("\nTest1 begins...\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// only have one head
void Test2()
{
	printf("\nTest2 begins...\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);
	DestroyList(pNode1);
}

// Null List
void Test3()
{
	printf("\nTest3 begins...\n");

	Test(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	return 0;
}

