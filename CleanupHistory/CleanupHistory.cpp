
// CleanupHistory.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "CleanupHistory.h"
#include "CleanupHistoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCleanupHistoryApp

BEGIN_MESSAGE_MAP(CCleanupHistoryApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CCleanupHistoryApp 构造

CCleanupHistoryApp::CCleanupHistoryApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CCleanupHistoryApp 对象

CCleanupHistoryApp theApp;

// CCleanupHistoryApp 初始化

BOOL CCleanupHistoryApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	Init();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CCleanupHistoryDlg dlg;
	m_pMainWnd = &dlg;

	TCHAR tchWarning[MAX_PATH] = {0};
	if (dlg.GetAccount(_T("Warning"), tchWarning, _countof(tchWarning)) &&
		0 == _tcsicmp(_T("1"), tchWarning))
		MessageBox(
		NULL,
		_T("清理各软件登录账号的以下信息：\
		   \r1、用户名、密码\
		   \r2、设置的下载目录下的所有文件\
		   \r3、与账号相关的文件、目录\
		   \r4、浏览过的网页、文件历史记录\
		   \n\
		   \rAccount.ini需与本exe同目录，格式如下\
		   \r[Account]\
		   \rQQ=464447966\
		   \rRTX=yuexiang\
		   \rFoxmail=yuexiang@huatusoft.com\
		   \rYoudaoDict=fly464447966@126.com\
		   \rThunder=fengkuangfj\
		   \rYoudaoNote=fly464447966@126.com\
		   \r360se=fly464447966@126.com\
		   \n\
		   \r注：\
		   \r1、其他软件暂不支持或无需在Account.ini中设置账号\
		   \r2、建议在出差完毕归还公用笔记本时使用(如果不想进行系统还原的话)\
		   \r3、点击All一键清理\
		   \r4、至于为什么要清理，你懂的"),
		   _T("提示"),
		   MB_OK
		   );

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。

	Unload();

	return FALSE;
}

BOOL
CCleanupHistoryApp::Init()
{
	BOOL				bRet = FALSE;

	CRUSH_HANDLER_INFO	CrushHandlerInfo;
	TCHAR				tchLog[MAX_PATH] = {0};


	__try
	{
		memset(&CrushHandlerInfo, 0, sizeof(CrushHandlerInfo));
		CrushHandlerInfo.EhType = EH_TYPE_S;
		CrushHandlerInfo.MiniDumpType = MiniDumpNormal;
		CSimpleDump::GetInstance()->RegisterCrushHandler(&CrushHandlerInfo);

		if (CProcessControl::GetInstance()->Get(TRUE, 0, tchLog, _countof(tchLog)))
		{
			PathRemoveExtension(tchLog);
			StringCchPrintf(tchLog, _countof(tchLog), _T("%s.log"), tchLog);
			CSimpleLog::GetInstance(tchLog);
		}

		bRet = TRUE;
	}
	__finally
	{
		;
	}

	return bRet;
}

BOOL
CCleanupHistoryApp::Unload()
{
	BOOL bRet = FALSE;


	__try
	{
		CSimpleLog::ReleaseInstance();
		CProcessControl::ReleaseInstance();
		CSimpleDump::ReleaseInstance();

		bRet = TRUE;
	}
	__finally
	{
		;
	}

	return bRet;
}
