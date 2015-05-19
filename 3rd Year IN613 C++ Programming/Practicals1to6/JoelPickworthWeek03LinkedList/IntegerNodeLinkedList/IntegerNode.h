#pragma once

ref class IntegerNode
{
private: 
	int integerData;
	
public:
	IntegerNode^ Next;

public:
	IntegerNode(int dataValue);
	int getIntegerData()	{return integerData;}
};
