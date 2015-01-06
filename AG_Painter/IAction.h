#include "stdafx.h"
class IAction
{
	public:
		virtual void MouseDown()=0;
		virtual void MouseUp()=0;
		virtual void DoubleClick()=0;
};