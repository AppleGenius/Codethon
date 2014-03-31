/*
*  题目： 寻找一个链表的倒数第K个元素
*  要点：	1. 当输入为一个NULL时的处理
*			2. 输入K为0时
*			3. 链表总节点数小于K时
*/

#include <stdio.h>

struct ListNode{
	int data;
	struct ListNode * next;
};


ListNode *FindKNodeToTail(ListNode *pListHead, unsigned int k);

int main(int argc, const char *argv[])
{
	return 0;
}

ListNode* FindkNodeToTail(ListNode *pListHead, unsigned int k)
{
	if (pListHead == NULL)
		return NULL;

	ListNode *pHead = pListHead;
	ListNode *pBehind = pListHead;

	for (unsigned int i = 0; i < k - 1; ++i)
		pHead = pHead->next;

	while (pHead->next != NULL){
		pHead = pHead->next;
		pBehind = pBehind->next;
	}

	return pBehind;
}




