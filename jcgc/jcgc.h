
// jcgc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CjcgcApp:
// �йش����ʵ�֣������ jcgc.cpp
//

class CjcgcApp : public CWinApp
{
public:
	CjcgcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CjcgcApp theApp;