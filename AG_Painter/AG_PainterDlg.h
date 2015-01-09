
// AG_PainterDlg.h : header file
//

#pragma once
#include "document.h"
//nclude "Document.h"

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDraw2();
	afx_msg void OnBnClickedDraw();
	afx_msg void OnBnClickedMfccolorbutton3();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnDrawElipse();
	Document thisDoc;
	bool isPressed;
	afx_msg void OnDrawRectangle();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawPoints();
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
};
