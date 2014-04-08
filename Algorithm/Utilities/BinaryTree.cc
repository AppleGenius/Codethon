#include "stdafx.h"
#include "BinaryTree.h"

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != NULL)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}


void PrintTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != NULL)
	{
		printf("value of this node is: %d\n", pNode->m_nValue);
	}
}