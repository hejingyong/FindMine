// FindMineView.h : CFindMineView 类的接口
//
#pragma once
#include "MineGrid.h"
#include "FindMineDoc.h"

#include "MainFrm.h"
#include "FindMine.h"

class CFindMineView : public CView
{
protected: // 仅从序列化创建
	CFindMineView();
	DECLARE_DYNCREATE(CFindMineView)

// 属性
public:
	CFindMineDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
       
// 实现
public:
	virtual ~CFindMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // FindMineView.cpp 中的调试版本
inline CFindMineDoc* CFindMineView::GetDocument() const
   { return reinterpret_cast<CFindMineDoc*>(m_pDocument); }
#endif

