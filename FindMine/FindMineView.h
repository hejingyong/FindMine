// FindMineView.h : CFindMineView ��Ľӿ�
//
#pragma once
#include "MineGrid.h"
#include "FindMineDoc.h"

#include "MainFrm.h"
#include "FindMine.h"

class CFindMineView : public CView
{
protected: // �������л�����
	CFindMineView();
	DECLARE_DYNCREATE(CFindMineView)

// ����
public:
	CFindMineDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
       
// ʵ��
public:
	virtual ~CFindMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAppStart();
    afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

private:
	int _width;
	int _height;
    int _wStep;
	int _hStep;
	int _isLoadDc;

	MineGrid *_grid;

	CBitmap _openBitMap;
	CBitmap _closeBitMap;
	CBitmap _markBitMap;
	CBitmap _mineBitMap;

	CDC _menDC ;

private:
	void DrawMine(int i,int j,CDC* pdc,MineItem* mine);
	void GetGirdLocation(int x,int y,int &i,int &j);
	void OnWin();
	void OnLost();
	void LoadDC(CDC *pDC);

};

#ifndef _DEBUG  // FindMineView.cpp �еĵ��԰汾
inline CFindMineDoc* CFindMineView::GetDocument() const
   { return reinterpret_cast<CFindMineDoc*>(m_pDocument); }
#endif

