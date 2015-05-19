#pragma once

#include "TetrisShape.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class L : public TetrisShape
{
public:
	L(void);
	virtual array<Cell^>^ Rotate() override;
};
