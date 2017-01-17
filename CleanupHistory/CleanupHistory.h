
// CleanupHistory.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#define MOD_CLEANUP_HISTORY _T("清理历史记录")

#ifndef __AFXWIN_H__
#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CCleanupHistoryApp:
// 有关此类的实现，请参阅 CleanupHistory.cpp
//

class CCleanupHistoryApp : public CWinAppEx
{
public:
	CCleanupHistoryApp();

	// 重写
public:
	virtual BOOL InitInstance();

	// 实现

	DECLARE_MESSAGE_MAP()

private:
	BOOL
		Init();

	BOOL
		Unload();
};

extern CCleanupHistoryApp theApp;
