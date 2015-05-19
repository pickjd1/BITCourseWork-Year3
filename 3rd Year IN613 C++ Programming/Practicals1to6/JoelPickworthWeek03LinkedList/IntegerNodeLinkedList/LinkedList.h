#pragma once
#include "IntegerNode.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class LinkedList
{
	IntegerNode^ head;
	IntegerNode^ tail;
	IntegerNode^ nodeWalker;
public:
	LinkedList(void);

	void addNode(IntegerNode^ newNode);
	void deleteNode(IntegerNode^ nodeToDelete);
	int countNodes();
	void printListValues(ListBox^ displayListBox);
};
