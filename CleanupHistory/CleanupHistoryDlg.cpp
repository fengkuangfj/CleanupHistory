
// CleanupHistoryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CleanupHistory.h"
#include "CleanupHistoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCleanupHistoryDlg 对话框

CCleanupHistoryDlg::CCleanupHistoryDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCleanupHistoryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCleanupHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCleanupHistoryDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCleanupHistoryDlg::OnBnClickedTemporaryInternetFiles)
	ON_BN_CLICKED(IDC_BUTTON2, &CCleanupHistoryDlg::OnBnClickedInternetCookies)
	ON_BN_CLICKED(IDC_BUTTON3, &CCleanupHistoryDlg::OnBnClickedInternetHistoryItems)
END_MESSAGE_MAP()

// CCleanupHistoryDlg 消息处理程序

BOOL CCleanupHistoryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCleanupHistoryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCleanupHistoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCleanupHistoryDlg::OnBnClickedTemporaryInternetFiles()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR					tchDir[MAX_PATH] = {0};
	OS_VERSION_USER_DEFINED OsVersion = OS_VERSION_UNKNOWN;
	STARTUPINFO				StartupInfo = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im iexplore.exe"), TRUE, TRUE, NULL);

		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_INTERNET_CACHE, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		OsVersion = COperationSystemVersion::GetInstance()->GetOSVersion();
		if (OS_VERSION_WINDOWS_10 <= OsVersion)
			StringCchPrintf(tchDir, _countof(tchDir), _T("%s\\IE"), tchDir);
		else
			StringCchPrintf(tchDir, _countof(tchDir), _T("%s\\Content.IE5"), tchDir);

		CDirectoryControl::Delete(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedInternetCookies()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im iexplore.exe"), TRUE, TRUE, NULL);

		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_COOKIES, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Delete(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedInternetHistoryItems()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im iexplore.exe"), TRUE, TRUE, NULL);

		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_HISTORY, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Delete(tchDir);
	}
	__finally
	{
		;
	}

	return;
}
