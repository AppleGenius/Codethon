// 07QueueWithTwoStacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"

void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed!\n");
	else
		printf("Test failed!\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');
	
	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}

