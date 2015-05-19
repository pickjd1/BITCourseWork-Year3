#include "StdAfx.h"
#include "LinkedList.h"

//==============================================================
// LinkedList constructor
//==============================================================
LinkedList::LinkedList(void)
{
	head = nullptr;
	tail = nullptr;
}

//==============================================================
// addNode(IntegerNode^ newNode)
// Adds newNode at the end of the list
// Head and Tail updated as required to maintain integrity of data structure
// Remember to handle special case of adding to an empty list
//==============================================================
void LinkedList::addNode(IntegerNode^ newNode)
{
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->Next = newNode;
		tail = newNode;
	}
}


//==============================================================
// deleteNode(IntegerNode^ nodeToDelete)
// Removes nodeToDelete from the list
// Head and Tail updated as required to maintain integrity of data structure
// All Next pointers updated as required to maintain integrity of data structure
// Remember to handle special cases:
//	1) Deleting the only node from a one-node list
//	2) Deleting the first node from a multi-node list
//	3) Deleting the tail node of a multi-node list
//==============================================================
void LinkedList::deleteNode(IntegerNode^ nodeToDelete)
{
	if(nodeToDelete == head)
	{
		if(head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->Next;
		}

	}
	else
	{
		IntegerNode^ nodeWalker;
		nodeWalker = head;

		while (nodeWalker->Next != nodeToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}

		nodeWalker->Next = nodeToDelete->Next;

		if (nodeToDelete == tail)
		{
			tail = nodeWalker;
		}

	}
}


//==============================================================
// countNodes()
// Returns the number of nodes in the list
//==============================================================
int LinkedList::countNodes()
{
	int nodeCount = 0; 

	IntegerNode^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeCount++;
		nodeWalker = nodeWalker->Next;
	}

	return nodeCount;		
}


//==============================================================
// printListValues(ListBox^ displayListBox)
// Write the data value of each node in the list to displayListBox
// Starts from the node at Head and writes, in list order, to the node at Tail.
//==============================================================
void LinkedList::printListValues(ListBox^ displayListBox)
{
	displayListBox->Items->Add("==========================================");

	IntegerNode^ nodeWalker =  head;
	while (nodeWalker != nullptr)
	{
		displayListBox->Items->Add(nodeWalker->getIntegerData());
		nodeWalker = nodeWalker->Next;
	}
}