// FindMineDoc.cpp : CFindMineDoc ���ʵ��
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


// CFindMineDoc ����/����

CFindMineDoc::CFindMineDoc()
{
	// TODO: �ڴ����һ���Թ������

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
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CFindMineDoc ���

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


// CFindMineDoc ����
