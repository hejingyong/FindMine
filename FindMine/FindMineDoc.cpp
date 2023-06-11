// FindMineDoc.cpp : CFindMineDoc 类的实现
//

#include "stdafx.h"
#include "FindMine.h"

#include "FindMineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFindMineDoc

IMPLEMENT_DYNCREATE(CFindMineDoc, CDocument)

BEGIN_MESSAGE_MAP(CFindMineDoc, CDocument)
END_MESSAGE_MAP()


// CFindMineDoc 构造/析构

CFindMineDoc::CFindMineDoc()
{
	// TODO: 在此添加一次性构造代码

}

CFindMineDoc::~CFindMineDoc()
{
}

BOOL CFindMineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}


void CFindMineDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CFindMineDoc 诊断

#ifdef _DEBUG
void CFindMineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFindMineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFindMineDoc 命令
