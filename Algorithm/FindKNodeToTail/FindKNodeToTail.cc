/*
*  ��Ŀ�� Ѱ��һ������ĵ�����K��Ԫ��
*  Ҫ�㣺	1. ������Ϊһ��NULLʱ�Ĵ���
*			2. ����KΪ0ʱ
*			3. �����ܽڵ���С��Kʱ
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




