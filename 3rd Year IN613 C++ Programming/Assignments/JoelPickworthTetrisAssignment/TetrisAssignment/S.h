#pragma once
#include "TetrisShape.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class S : public TetrisShape
{
public:
	S(void);
	virtual array<Cell^>^ Rotate() override;
};
