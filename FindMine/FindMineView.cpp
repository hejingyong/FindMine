// FindMineView.cpp : CFindMineView 类的实现
//

#include "stdafx.h"
#include "FindMineView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFindMineView

IMPLEMENT_DYNCREATE(CFindMineView, CView)

BEGIN_MESSAGE_MAP(CFindMineView, CView)
	ON_COMMAND(ID_APP_START, &CFindMineView::OnAppStart)
	ON_WM_SIZE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFindMineView 构造/析构

CFindMineView::CFindMineView()
{
	_grid = new MineGrid(10,10,&CFindMineView::OnWin,&CFindMineView::OnLost,this);
	_grid->Initialization();

	_height = CMainFrame::HEIGHT;
	_width =  CMainFrame::WIDTH;
	_hStep = _height/_grid->Width();
	_wStep = _width/_grid->Height();

	_isLoadDc = false;
}

CFindMineView::~CFindMineView()
{
	DeleteObject(_grid);
}

BOOL CFindMineView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CFindMineView 绘制

void CFindMineView::OnDraw(CDC* pDC)
{
	LoadDC(pDC);

	for (int i=0;i<_grid->Height();i++)
		for (int j=0;j<_grid->Width();j++)
			DrawMine(i,j,pDC,_grid->Get(i,j));
}


// CFindMineView 诊断

#ifdef _DEBUG
void CFindMineView::AssertValid() const
{
	CView::AssertValid();
}

void CFindMineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFindMineDoc* CFindMineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFindMineDoc)));
	return (CFindMineDoc*)m_pDocument;
}
#endif //_DEBUG


// CFindMineView 消息处理程序

void CFindMineView::OnAppStart()
{
	_grid->Initialization();
	Invalidate();
}

void CFindMineView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
    _width = cx;
	_height = cy;
	_hStep = cy/_grid->Height();
	_wStep = cx/_grid->Width();
}

void CFindMineView::DrawMine( int i,int j,CDC* pdc,MineItem* mine )
{
	if (mine->IsOpen())
		if (mine->IsMine())
		  _menDC.SelectObject(&_mineBitMap);
		else
		  _menDC.SelectObject(&_openBitMap);
	else
		if(mine->IsMark())
			 _menDC.SelectObject(&_markBitMap);
		else
            _menDC.SelectObject(&_closeBitMap);
      
	  pdc->BitBlt(j*_wStep,i*_hStep,_wStep-1,_hStep-1,&_menDC,1,1,SRCCOPY);

      if (mine->IsOpen()&&!mine->IsMine()&&(mine->Neighbour()>0))
	  {
		  CString num;
		  num.Format(L"%d",mine->Neighbour());
		  pdc->TextOut(j*_wStep+19,i*_hStep+17,num);
	  }
}

void CFindMineView::GetGirdLocation( int x,int y,int &i,int &j )
{
       i = y/_hStep;
	   j = x/_wStep;
}

void CFindMineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	int i,j;

	CView::OnLButtonUp(nFlags, point);
	GetGirdLocation(point.x,point.y,i,j);

	_grid->Open(i,j);
	Invalidate();
}

void CFindMineView::OnRButtonUp(UINT nFlags, CPoint point)
{
	int i,j;

	CView::OnRButtonUp(nFlags, point);
	GetGirdLocation(point.x,point.y,i,j);

	_grid->Mark(i,j);
	Invalidate();
}

void CFindMineView::OnWin()
{
      MessageBox(L"WIN!");
	  _grid->OpenAll();
	  Invalidate();
}

void CFindMineView::OnLost()
{
	MessageBox(L"GAME OVER!");
	_grid->OpenAll();
	Invalidate();
}

void CFindMineView::LoadDC(CDC *pDC)
{
    if (!_isLoadDc)//只能加载一次
	{
        _isLoadDc = true;

		_openBitMap.LoadBitmap(IDB_BTNDOWN);
		_closeBitMap.LoadBitmap(IDB_BTNUP);
		_markBitMap.LoadBitmap(IDB_BTNMARK);
		_mineBitMap.LoadBitmap(IDB_BTNMINE);

		_menDC.CreateCompatibleDC(pDC);//每个dc这能创建一个关联的dc
	}
}
