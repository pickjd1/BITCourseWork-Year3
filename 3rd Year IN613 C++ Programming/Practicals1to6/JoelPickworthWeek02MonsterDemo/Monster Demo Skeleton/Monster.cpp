#include "StdAfx.h"
#include "Monster.h"


Monster::Monster(void)
{
}

void Monster::Speak()
{
	MessageBox::Show("I'm a Monster! Roar");
}