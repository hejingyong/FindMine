// FindMine.h : FindMine Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFindMineApp:
// �йش����ʵ�֣������ FindMine.cpp
//

class CFindMineApp : public CWinApp
{
public:
	CFindMineApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFindMineApp theApp;