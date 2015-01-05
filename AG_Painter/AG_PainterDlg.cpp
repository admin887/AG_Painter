
// AG_PainterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AG_Painter.h"
#include "AG_PainterDlg.h"
#include "afxdialogex.h"
#include "Point.h"
#include "Rectangle.h"
#include "Elipse.h"
#include "Line.h"

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
	Shape *s = new Elipse(point.x,point.y,point.x+50,point.y+50);
	Shape *r = new Rec(point.x,point.y,point.x+50,point.y+50);
	Shape *p = new Point(point.x,point.y,10,RGB(0,0,255));
	Shape *l = new Line(point.x,point.y,point.x+50,point.y+50);

	
	CClientDC dc(this);
	l->Paint(&dc);






	//Point *p = new Point(point.x,point.y,10,RGB(0,0,255));
	//CClientDC dc(this);

	// TODO: Add your message handler code here and/or call default
		//CClientDC dc(this);
		//CPen myPen1(PS_SOLID, 3, RGB(255,0,0));
		//CPen *oldPen;
		//oldPen=dc.SelectObject( &myPen1 ); 
		//dc.SetROP2(R2_NOTXORPEN);  
		//dc.MoveTo(10,55);
		//dc.LineTo(20, 100);
		//dc.SetPixel(100,100,RGB(255,0,0));
		//dc.SelectObject( oldPen ); 
	//CDialog::OnMouseMove(nFlags, point);
	//p->Paint(&dc);
	//Invalidate();
}


void CAG_PainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	

	
}


void CAG_PainterDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAG_PainterDlg::OnBnClickedDraw2()
{
	// TODO: Add your control notification handler code here
}


void CAG_PainterDlg::OnBnClickedDraw()
{
	// TODO: Add your control notification handler code here
}


void CAG_PainterDlg::OnBnClickedMfccolorbutton3()
{
	// TODO: Add your control notification handler code here
}
