// FindMineDoc.h : CFindMineDoc ��Ľӿ�
//


#pragma once


class CFindMineDoc : public CDocument
{
protected: // �������л�����
	CFindMineDoc();
	DECLARE_DYNCREATE(CFindMineDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CFindMineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


