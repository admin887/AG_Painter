
// AG_PainterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AG_Painter.h"
#include "AG_PainterDlg.h"
#include "afxdialogex.h"
//#include "Point.h"
#include "Rectangle.h"
#include "Elipse.h"
#include "Line.h"
#include "Document.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAG_PainterDlg dialog




CAG_PainterDlg::CAG_PainterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAG_PainterDlg::IDD, pParent)
	, isPressed(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAG_PainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAG_PainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CAG_PainterDlg::OnBnClickedOk)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CAG_PainterDlg::OnTcnSelchangeTab1)
	//ON_BN_CLICKED(IDC_DRAW2, &CAG_PainterDlg::OnBnClickedDraw2)
	ON_BN_CLICKED(IDC_DRAW, &CAG_PainterDlg::OnBnClickedDraw)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON3, &CAG_PainterDlg::OnBnClickedMfccolorbutton3)
	ON_COMMAND(ID_DRAW_ELIPSE, &CAG_PainterDlg::OnDrawElipse)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CAG_PainterDlg::OnDrawRectangle)
	ON_COMMAND(ID_DRAW_LINE, &CAG_PainterDlg::OnDrawLine)
	ON_COMMAND(ID_DRAW_POINTS, &CAG_PainterDlg::OnDrawPoints)
	ON_WM_MOUSEHOVER()
	ON_WM_LBUTTONUP()
//	ON_BN_CLICKED(IDC_BUTTON1, &CAG_PainterDlg::OnBnClickedButton1)
ON_WM_LBUTTONDBLCLK()
ON_COMMAND(ID_TOOLS_SELECT, &CAG_PainterDlg::OnToolsSelect)
ON_WM_RBUTTONDOWN()
ON_COMMAND(ID_TOOLS_MOVE, &CAG_PainterDlg::OnToolsMove)
END_MESSAGE_MAP()


// CAG_PainterDlg message handlers

BOOL CAG_PainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	curFill= RGB(255,0,0);
	curLine=RGB(0,0,0);

	myShapeGarage= new ShapesGarage();
	myDrawer = new Drawer(*myShapeGarage);
	mySelector= new selector(*myShapeGarage);
	myMover= new Mover(*myShapeGarage);

	thisDoc.setShapeGarade(*myShapeGarage);
	thisDoc.setCurrTool(*myDrawer);
	//Elipse *e =new Elipse();
	//myShapeGarage->getAliveShapes()->push_back(e);



   // CFont font;
    //font.CreatePointFont (500, _T ("Arial"));

	//!!8 b
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAG_PainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAG_PainterDlg::OnPaint()
{
	CPaintDC dc (this);
	CClientDC dc2(this);
	CRect rect;

	COLORREF myColors[]= {RGB(255,0,0),RGB(0,255,0),
						  RGB(0,0,255),RGB(255,128,0),
						  RGB(0,128,128),RGB(200,0,255),
						  RGB(128,128,64),RGB(0,0,0)
						 };
	
    GetClientRect (&rect);

	int startXX= 15;
	int startYY=30;
	int weight=50;
	int deltaX= 5;
	int deltaY= 5;

	int Color_Counter=0;

	for (int j = 1; j <= 4; j++)
	{
		
		for (int i = 1; i <= 2; i++)
		{
			startXX=startXX+deltaX*(i-1)+weight*(i-1);
			
			//dc.Rectangle(startXX,startYY,startXX+weight,startYY+weight);

			CBrush myBrush,*oldBrush;
			myBrush.CreateSolidBrush(myColors[Color_Counter]);
			oldBrush=dc.SelectObject( &myBrush );        

			CPen myPen1(PS_SOLID,1, myColors[Color_Counter]);

			CPen *oldPen;
			oldPen=dc.SelectObject( &myPen1 ); 
			dc.SetROP2(R2_NOTXORPEN);  
			dc.MoveTo(startXX, startYY);

			dc.Rectangle(startXX,startYY,startXX+weight,startYY+weight);
		
			dc.SelectObject( oldPen ); 
			dc.SetROP2(R2_COPYPEN);  
			dc.SelectObject( oldBrush ); 
			Color_Counter++;
			
		}
		startXX =15;
		startYY= startYY+deltaY+weight;
	}

		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(curFill);
			oldBrush=dc.SelectObject( &myBrush );        

			CPen myPen1(PS_SOLID,1, RGB(0,0,0));

			CPen *oldPen;
			oldPen=dc.SelectObject( &myPen1 ); 
			dc.SetROP2(R2_NOTXORPEN);  
			

			dc.Rectangle(15,332,120,330+20);
		
			dc.SelectObject( oldPen ); 
			dc.SetROP2(R2_COPYPEN);  
			dc.SelectObject( oldBrush ); 
	
		
			CBrush myBrush2,*oldBrush2;
			myBrush2.CreateSolidBrush(curLine);
			oldBrush2=dc.SelectObject( &myBrush2 );        

			CPen myPen2(PS_SOLID,1, RGB(0,0,0));

			CPen *oldPen2;
			oldPen2=dc.SelectObject( &myPen2 ); 
			dc.SetROP2(R2_NOTXORPEN);  
			

			dc.Rectangle(15,370,120,370+20);
		
			dc.SelectObject( oldPen ); 
			dc.SetROP2(R2_COPYPEN);  
			dc.SelectObject( oldBrush2 );
	

	int ListSize= myShapeGarage->getAliveShapes()->_Mysize;

	std::list<Shape*>::iterator i;

	for (i =myShapeGarage->getAliveShapes()->begin() ; i!=myShapeGarage->getAliveShapes()->end() ; i++)
	{
		i._Mynode()->_Myval->Paint(&dc);
	}

//	dc.Rectangle(10,20,120,250);




	//for (int i = 0; i < ListSize; i++)
	//{
	//	//myShapeGarage->getAliveShapes()->find
	//	myShapeGarage->getAliveShapes()->
	//	

	//}

	//for(int i = 0 , ptr = l.begin() ; i < N && ptr != l.end() ; i++ , ptr++ );

	//	if( ptr == l.end() ) {
	//		// list too short  
	//	} else {
	//		// 'ptr' points to N-th element of list
	//	}


}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAG_PainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAG_PainterDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CAG_PainterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if(point.x<120 && point.y<250 && point.x>10 && point.y > 20)
	{
		curFill= dc.GetPixel(point.x,point.y);
		Invalidate();
	}
	else
	{
		
		thisDoc.getShapeGarade()->setTypeToConstrct(myShapeType);
		thisDoc.getCurrTool().MouseDown(&dc,point);
		std::list<Shape*>::iterator i;
		i =myShapeGarage->getAliveShapes()->begin();
		Shape* temp=  i._Mynode()->_Myval;
		thisDoc.setCurrentShape(*temp);

		temp->setColorInside(curFill);
		temp->setColorOutside(curLine);

		isPressed=true;

		
	}
	//
}


void CAG_PainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if(isPressed)
	{
		CClientDC dc(this);
		thisDoc.getCurrTool().MouseOver(&dc,point);
		std::list<Shape*>::iterator i;
		i =myShapeGarage->getAliveShapes()->begin();
		Shape* temp=  i._Mynode()->_Myval;
		thisDoc.setCurrentShape(*temp);
	}
}


void CAG_PainterDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{

}


void CAG_PainterDlg::OnBnClickedDraw2()
{
	
}


void CAG_PainterDlg::OnBnClickedDraw()
{
	
}


void CAG_PainterDlg::OnBnClickedMfccolorbutton3()
{
	
}


void CAG_PainterDlg::OnDrawElipse()
{
//	Document *thisDoc= new Document();
	//Elipse *e= new Elipse(0,0,0,0,1,RGB(255,0,0),RGB(200,200,200));

	//Shape *myshape=   myShapeGarage->CreateShape(EnumShapes::E_ELI);

	myShapeType= E_ELIPSE;

	//Drawer *d= new Drawer(*myShapeGarage);

	thisDoc.setCurrTool(*myDrawer);
	
	//thisDoc.setCurrentShape(*myshape);

	
}


void CAG_PainterDlg::OnDrawRectangle()
{
	//Rec *e= new Rec(0,0,0,0,1,RGB(0,255,0),RGB(200,200,200));
	//Drawer *d= new Drawer();


	//thisDoc.setDrawer(*d);
	//thisDoc.setCurrentShape(*e);

	myShapeType= E_RECTANGLE;
	thisDoc.setCurrTool(*myDrawer);
}


void CAG_PainterDlg::OnDrawLine()
{
	/*Line *e= new Line(0,0,0,0);
	Drawer *d= new Drawer();


	thisDoc.setDrawer(*d);
	thisDoc.setCurrentShape(*e);*/
	myShapeType= E_LINE;
	thisDoc.setCurrTool(*myDrawer);
}


void CAG_PainterDlg::OnDrawPoints()
{
	myShapeType= E_POINT;
	thisDoc.setCurrTool(*myDrawer);

	/*Point *e= new Point(0,0,6);
	Drawer *d= new Drawer();


	thisDoc.setDrawer(*d);
	thisDoc.setCurrentShape(*e);*/
}


void CAG_PainterDlg::OnMouseHover(UINT nFlags, CPoint point)
{



}


void CAG_PainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isPressed=false;
	Invalidate();
}


void CAG_PainterDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CAG_PainterDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	thisDoc.getCurrTool().DoubleClick(&dc,point);
	Invalidate();
}


void CAG_PainterDlg::OnToolsSelect()
{
	myShapeType = E_NULLSHAPE;
	thisDoc.setCurrTool(*mySelector);
		
	
}


void CAG_PainterDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(point.x<120 && point.y<250 && point.x>10 && point.y > 20)
	{
	CClientDC dc(this);
	curLine= dc.GetPixel(point.x,point.y);
	Invalidate();
	}
}


void CAG_PainterDlg::OnToolsMove()
{
		myShapeType = E_NULLSHAPE;
		thisDoc.setCurrTool(*myMover);
}
