
// AG_Painter.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAG_PainterApp:
// See AG_Painter.cpp for the implementation of this class
//

class CAG_PainterApp : public CWinApp
{
public:
	CAG_PainterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAG_PainterApp theApp;