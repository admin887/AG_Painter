
#include "stdafx.h"
#include "AG_Painter.h"
#include "AG_PainterDlg.h"
#include "afxdialogex.h"
#include "Rectangle.h"
#include "Elipse.h"
#include "Line.h"
#include "Document.h"
#include "Eraser.h"
#include "Undoredo.h"
#pragma once
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CAG_PainterDlg::CAG_PainterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAG_PainterDlg::IDD, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CAG_PainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, TrackBar);
}

BEGIN_MESSAGE_MAP(CAG_PainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_ELIPSE, &CAG_PainterDlg::OnDrawElipse)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CAG_PainterDlg::OnDrawRectangle)
	ON_COMMAND(ID_DRAW_LINE, &CAG_PainterDlg::OnDrawLine)
	ON_COMMAND(ID_DRAW_POINTS, &CAG_PainterDlg::OnDrawPoints)
	ON_WM_MOUSEHOVER()
	ON_WM_LBUTTONUP()
ON_WM_LBUTTONDBLCLK()
ON_COMMAND(ID_TOOLS_SELECT, &CAG_PainterDlg::OnToolsSelect)
ON_WM_RBUTTONDOWN()
ON_COMMAND(ID_TOOLS_MOVE, &CAG_PainterDlg::OnToolsMove)
ON_COMMAND(ID_TOOLS_ERASER, &CAG_PainterDlg::OnToolsEraser)
ON_COMMAND(ID_EDIT_UNDO32773, &CAG_PainterDlg::OnEditUndo32773)
ON_COMMAND(ID_EDIT_REUNDO, &CAG_PainterDlg::OnEditReundo)
END_MESSAGE_MAP()


// CAG_PainterDlg message handlers

BOOL CAG_PainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);	
	SetIcon(m_hIcon, FALSE);

	curFill= RGB(255,0,0);
	curLine=RGB(0,255,0);

	myShapeGarage= new ShapesGarage();
	myDrawer = new Drawer(*myShapeGarage);
	mySelector= new selector(*myShapeGarage);
	myMover= new Mover(*myShapeGarage);
	myEraser= new Eraser(*myShapeGarage);
	myUndoRedo= new UndoRedo(*myShapeGarage);
	thisDoc.setShapeGarade(*myShapeGarage);
	thisDoc.setCurrTool(*myDrawer);

	TrackBar.SetRangeMin(2);
	TrackBar.SetRangeMax(10);
	return TRUE;
}
void CAG_PainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
HCURSOR CAG_PainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



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
	



}

void CAG_PainterDlg::OnToolsSelect()
{
	myShapeType = E_NULLSHAPE;
	thisDoc.setCurrTool(*mySelector);
		
	
}
void CAG_PainterDlg::OnDrawPoints()
{
	myShapeType= E_POINT;
	thisDoc.setCurrTool(*myDrawer);
}
void CAG_PainterDlg::OnDrawLine()
{
	myShapeType= E_LINE;
	thisDoc.setCurrTool(*myDrawer);
}
void CAG_PainterDlg::OnDrawElipse()
{
	myShapeType= E_ELIPSE;
	thisDoc.setCurrTool(*myDrawer);
}
void CAG_PainterDlg::OnDrawRectangle()
{
	myShapeType= E_RECTANGLE;
	thisDoc.setCurrTool(*myDrawer);
}
void CAG_PainterDlg::OnToolsMove()
{
		myShapeType = E_NULLSHAPE;
		thisDoc.setCurrTool(*myMover);
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
		thisDoc.getShapeGarade()->setCurFill(curFill);
		thisDoc.getShapeGarade()->setCurrLine(curLine);
		thisDoc.getShapeGarade()->setCurrWeight(TrackBar.GetPos());

		thisDoc.getShapeGarade()->setTypeToConstrct(myShapeType);
		thisDoc.getCurrTool().MouseDown(&dc,point);
		std::list<Shape*>::iterator i;
		i =myShapeGarage->getAliveShapes()->begin();
		Shape* temp=  i._Mynode()->_Myval;
		thisDoc.setCurrentShape(*temp);
	}
	
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
void CAG_PainterDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
}
void CAG_PainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	thisDoc.getCurrTool().MouseUp(&dc,point);
	Invalidate();
}
void CAG_PainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{

		CClientDC dc(this);
		thisDoc.getCurrTool().MouseOver(&dc,point);
		std::list<Shape*>::iterator i;
		i =myShapeGarage->getAliveShapes()->begin();
		Shape* temp=  i._Mynode()->_Myval;
		thisDoc.setCurrentShape(*temp);
}


void CAG_PainterDlg::OnToolsEraser()
{
	myShapeType = E_NULLSHAPE;
	thisDoc.setCurrTool(*myEraser);
}


void CAG_PainterDlg::OnEditUndo32773()
{
	myUndoRedo->Undo();
	Invalidate();
}


void CAG_PainterDlg::OnEditReundo()
{
	myUndoRedo->Redo();
	Invalidate();
}
