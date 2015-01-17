
// AG_PainterDlg.h : header file
//

#pragma once
#include "document.h"
#include "shapesgarage.h"
#include "drawer.h"
#include "selector.h"
#include "Mover.h"
#include "Eraser.h"
//nclude "Document.h"
#include "Undoredo.h"
#include "afxcmn.h"
// CAG_PainterDlg dialog
class CAG_PainterDlg : public CDialogEx
{
// Construction
public:

	CAG_PainterDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	enum { IDD = IDD_AG_PAINTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnDrawElipse();
	Document thisDoc;
	afx_msg void OnDrawRectangle();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawPoints();

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	
	ShapesGarage *myShapeGarage;
	Drawer *myDrawer;
	selector *mySelector;
	Eraser *myEraser;
	ENUM_SHAPES myShapeType;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnToolsSelect();
	COLORREF curFill;
	COLORREF curLine;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnToolsMove();
	Mover *myMover;
	afx_msg void OnToolsEraser();
	afx_msg void OnEditUndo32773();
	UndoRedo *myUndoRedo;
	afx_msg void OnEditReundo();
	CSliderCtrl TrackBar;
};
