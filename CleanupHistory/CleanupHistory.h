
// CleanupHistory.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#define MOD_CLEANUP_HISTORY _T("������ʷ��¼")

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCleanupHistoryApp:
// �йش����ʵ�֣������ CleanupHistory.cpp
//

class CCleanupHistoryApp : public CWinAppEx
{
public:
	CCleanupHistoryApp();

	// ��д
public:
	virtual BOOL InitInstance();

	// ʵ��

	DECLARE_MESSAGE_MAP()

private:
	BOOL
		Init();

	BOOL
		Unload();
};

extern CCleanupHistoryApp theApp;
