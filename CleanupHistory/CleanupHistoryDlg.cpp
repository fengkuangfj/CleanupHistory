
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

// http://www.51itong.net/vc-7147.html
BEGIN_MESSAGE_MAP(CCleanupHistoryDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCleanupHistoryDlg::OnBnClickedTemporaryInternetFiles)
	ON_BN_CLICKED(IDC_BUTTON2, &CCleanupHistoryDlg::OnBnClickedInternetCookies)
	ON_BN_CLICKED(IDC_BUTTON3, &CCleanupHistoryDlg::OnBnClickedInternetHistoryItems)
	ON_BN_CLICKED(IDC_BUTTON4, &CCleanupHistoryDlg::OnBnClickedInternetTypedUrls)
	ON_BN_CLICKED(IDC_BUTTON5, &CCleanupHistoryDlg::OnBnClickedInternetProtectedStorageSystemProvider)
	ON_BN_CLICKED(IDC_BUTTON6, &CCleanupHistoryDlg::OnBnClickedIntelliForms)
	ON_BN_CLICKED(IDC_BUTTON7, &CCleanupHistoryDlg::OnBnClickedRASAdresses)
	ON_BN_CLICKED(IDC_BUTTON8, &CCleanupHistoryDlg::OnBnClickedTemp)
	ON_BN_CLICKED(IDC_BUTTON9, &CCleanupHistoryDlg::OnBnClickedRecycleBin)
	ON_BN_CLICKED(IDC_BUTTON10, &CCleanupHistoryDlg::OnBnClickedRunMRU)
	ON_BN_CLICKED(IDC_BUTTON11, &CCleanupHistoryDlg::OnBnClickedRecentDocs)
	ON_BN_CLICKED(IDC_BUTTON12, &CCleanupHistoryDlg::OnBnClickedWinlogonUserName)
	ON_BN_CLICKED(IDC_BUTTON13, &CCleanupHistoryDlg::OnBnClickedDocFindSpec)
	ON_BN_CLICKED(IDC_BUTTON14, &CCleanupHistoryDlg::OnBnClickedFindComputerMRU)
	ON_BN_CLICKED(IDC_BUTTON15, &CCleanupHistoryDlg::OnBnClickedNetHood)
	ON_BN_CLICKED(IDC_BUTTON16, &CCleanupHistoryDlg::OnBnClickedTelNet)
	ON_BN_CLICKED(IDC_BUTTON17, &CCleanupHistoryDlg::OnBnClickedQQ)
	ON_BN_CLICKED(IDC_BUTTON18, &CCleanupHistoryDlg::OnBnClickedRTX)
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

// Internet 临时文件
void CCleanupHistoryDlg::OnBnClickedTemporaryInternetFiles()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im iexplore.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Local\Microsoft\Windows\Temporary Internet Files
		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_INTERNET_CACHE, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Empty(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

// Cookie
void CCleanupHistoryDlg::OnBnClickedInternetCookies()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im iexplore.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Roaming\Microsoft\Windows\Cookies
		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_COOKIES, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Empty(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

// 历史记录
void CCleanupHistoryDlg::OnBnClickedInternetHistoryItems()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im iexplore.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Local\Microsoft\Windows\History
		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_HISTORY, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Empty(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

// 地址栏历史记录
void CCleanupHistoryDlg::OnBnClickedInternetTypedUrls()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\TypedUrls"));
	}
	__finally
	{
		;
	}

	return;
}

// 密码历史记录
void CCleanupHistoryDlg::OnBnClickedInternetProtectedStorageSystemProvider()
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	CString sKey;
	DWORD dwRet;

	if (IsWindows2k() || IsWindowsNT())//先判断系统
	{
	CString sBaseKey;
	SECURITY_DESCRIPTOR NewSD;
	BYTE* pOldSD;
	PACL pDacl = NULL;
	PSID pSid = NULL;
	TCHAR szSid[256];
	if (GetUserSid(&pSid))
	{
	//get the hiden key name
	GetSidString(pSid, szSid);

	sKey = _T("Software//Microsoft//Protected Storage System Provider//");
	sKey += szSid;

	//get old SD
	sBaseKey = sKey;
	GetOldSD(HKEY_CURRENT_USER, sBaseKey, &pOldSD);

	//set new SD and then clear
	if (CreateNewSD(pSid, &NewSD, &pDacl))
	{
	RegSetPrivilege(HKEY_CURRENT_USER, sKey, &NewSD, FALSE);

	sKey += _T("//Data");
	RegSetPrivilege(HKEY_CURRENT_USER, sKey, &NewSD, FALSE);

	sKey += _T("//e161255a-37c3-11d2-bcaa-00c04fd929db");
	RegSetPrivilege(HKEY_CURRENT_USER, sKey, &NewSD, TRUE);

	dwRet = SHDeleteKey(HKEY_CURRENT_USER, sKey);
	}

	if (pDacl != NULL)
	HeapFree(GetProcessHeap(), 0, pDacl);

	//restore old SD
	if (pOldSD)
	{
	RegSetPrivilege(HKEY_CURRENT_USER, sBaseKey, 
	(SECURITY_DESCRIPTOR*)pOldSD, FALSE);
	delete pOldSD;
	}
	}
	if (pSid)
	HeapFree(GetProcessHeap(), 0, pSid);
	}
	*/
}

// 表单数据
void CCleanupHistoryDlg::OnBnClickedIntelliForms()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\IntelliForms"));
	}
	__finally
	{
		;
	}

	return;
}

// RAS自动拨号历史记录
void CCleanupHistoryDlg::OnBnClickedRASAdresses()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\RAS AutoDial\\Addresses"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

// 临时目录
void CCleanupHistoryDlg::OnBnClickedTemp()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		// C:\Users\ADMINI~1\AppData\Local\Temp
		if (!GetTempPath(_countof(tchDir), tchDir))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "GetTempPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Empty(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

// 回收站
void CCleanupHistoryDlg::OnBnClickedRecycleBin()
{
	// TODO: 在此添加控件通知处理程序代码
	HRESULT hResult = S_OK;


	__try
	{
		hResult = SHEmptyRecycleBin(NULL, NULL, SHERB_NOCONFIRMATION | SHERB_NOPROGRESSUI | SHERB_NOSOUND);
		if (S_OK != hResult)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHEmptyRecycleBin failed. (%d)", hResult);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

// 运行历史记录
void CCleanupHistoryDlg::OnBnClickedRunMRU()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

// 文档历史记录
void CCleanupHistoryDlg::OnBnClickedRecentDocs()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR	tchDir[MAX_PATH] = {0};
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_RECENT, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		CDirectoryControl::Empty(tchDir);

		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RecentDocs"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

// 登录用户历史记录
void CCleanupHistoryDlg::OnBnClickedWinlogonUserName()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		lStatus = SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\RecentDocs"), _T("DefaultUserName"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteValue failed. (%d)", lStatus);
			__leave;
		}

		lStatus = SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\RecentDocs"), _T("AltDefaultUserName"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteValue failed. (%d)", lStatus);
			__leave;
		}

		lStatus = SHDeleteValue(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Winlogon\\RecentDocs"), _T("DefaultUserName"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteValue failed. (%d)", lStatus);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

// 搜索历史记录
void CCleanupHistoryDlg::OnBnClickedDocFindSpec()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Doc Find Spec"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}

		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\ContainingTextMRU"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}

		lStatus = SHDeleteKey(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\FilesNamedMRU"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

// 查找
void CCleanupHistoryDlg::OnBnClickedFindComputerMRU()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;


	__try
	{
		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FindComputerMRU"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}

		lStatus = SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\ComputerNameMRU"));
		if (ERROR_SUCCESS != lStatus)
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHDeleteKey failed. (%d)", lStatus);
			__leave;
		}
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedNetHood()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDir[MAX_PATH] = {0};


	__try
	{
		if (!SHGetSpecialFolderPath(NULL, tchDir, CSIDL_NETHOOD, FALSE))
			__leave;

		CDirectoryControl::Empty(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedTelNet()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;
	ULONG	ulIndex = 0;
	TCHAR	tchReg[MAX_PATH] = {0};


	__try
	{
		for (; ulIndex <= 8; ulIndex++)
		{
			StringCchPrintf(tchReg, _countof(tchReg), _T("Machine%d"), ulIndex);
			SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Telnet"), tchReg);

			StringCchPrintf(tchReg, _countof(tchReg), _T("Service%d"), ulIndex);
			SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Telnet"), tchReg);

			StringCchPrintf(tchReg, _countof(tchReg), _T("TermType%d"), ulIndex);
			SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Telnet"), tchReg);
		}

		SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Telnet"), _T("LastMachine"));
		SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Telnet"), _T("LastService"));
		SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Telnet"), _T("LastTermType"));
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedQQ()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchQQ[MAX_PATH] = {0};
	TCHAR tchDirRoaming[MAX_PATH] = {0};
	TCHAR tchDirProgramData[MAX_PATH] = {0};
	TCHAR tchDirDocuments[MAX_PATH] = {0};
	TCHAR tchPath[MAX_PATH] = {0};


	__try
	{
		StringCchPrintf(tchQQ, _countof(tchQQ), _T("464447966"));

		CCommandLine::Execute(_T("taskkill /f /im qq.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im qqprotect.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im qq.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im qqprotect.exe"), TRUE, TRUE, NULL);

		// 目录

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
			__leave;

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQ\\Misc\\com.tencent.gamelife\\QQGameLife\\%s"), tchDirRoaming, tchQQ);
		CDirectoryControl::Delete(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQ\\SNS\\Com.Tencent.PersonalCard\\%s"), tchDirRoaming, tchQQ);
		CDirectoryControl::Delete(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQ\\webkit_cache\\%s"), tchDirRoaming, tchQQ);
		CDirectoryControl::Delete(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQMiniDL\\%s"), tchDirRoaming, tchQQ);
		CDirectoryControl::Delete(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\Users\\%s"), tchDirRoaming, tchQQ);
		CDirectoryControl::Delete(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQ\\webkit_cache\\%s_medalwall"), tchDirRoaming, tchQQ);
		CDirectoryControl::Delete(tchPath);

		// C:\ProgramData
		if (!SHGetSpecialFolderPath(NULL, tchDirProgramData, CSIDL_COMMON_APPDATA, FALSE))
			__leave;

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQProtect\\Qscan\\%s"), tchDirProgramData, tchQQ);
		CDirectoryControl::Delete(tchPath);

		// D:\My Documents
		if (!SHGetSpecialFolderPath(NULL, tchDirDocuments, CSIDL_MYDOCUMENTS, FALSE))
			__leave;

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\%s"), tchDirDocuments, tchQQ);
		CDirectoryControl::Delete(tchPath);

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQ\\Misc\\%s"), tchDirRoaming, tchQQ);
		DeleteFile(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\All Users\\QQ\\Misc\\com.tencent.qqshow\\qqshow6\\qqshow_%s.jpg"), tchDirDocuments, tchQQ);
		DeleteFile(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\All Users\\QQ\\Misc\\com.tencent.qqshow\\xml6\\%s.xml"), tchDirDocuments, tchQQ);
		DeleteFile(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\All Users\\QQ\\Misc\\com.tencent.qqshow\\xml6\\%s_f.xml"), tchDirDocuments, tchQQ);
		DeleteFile(tchPath);

		// 注册表
		StringCchPrintf(tchPath, _countof(tchPath), _T("SOFTWARE\\Tencent\\Plugin\\VAS\\%s"), tchQQ);
		SHDeleteKey(HKEY_CURRENT_USER, tchPath);
	}
	__finally
	{

	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedRTX()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR							tchAccount[MAX_PATH] = {0};
	TCHAR							tchDirDocuments[MAX_PATH] = {0};
	TCHAR							tchPath[MAX_PATH] = {0};
	TCHAR							tchInstDir[MAX_PATH] = {0};
	OS_PROCESSOR_TYPE_USER_DEFINED	OsProcessorType = OS_PROCESSOR_TYPE_UNKNOWN;
	TCHAR							tchPathCfg[MAX_PATH] = {0};
	DWORD							dwType = 0;
	DWORD							dwDataBufSizeB = 0;
	TCHAR							tchSubKey[MAX_PATH] = {0};
	LSTATUS							lStatus = ERROR_SUCCESS;
	LPTSTR							lpPosition = NULL;


	__try
	{
		StringCchPrintf(tchAccount, _countof(tchAccount), _T("yuexiang"));

		CCommandLine::Execute(_T("taskkill /f /im rtx.exe"), TRUE, TRUE, NULL);

		// 目录

		// D:\My Documents
		if (!SHGetSpecialFolderPath(NULL, tchDirDocuments, CSIDL_MYDOCUMENTS, FALSE))
			__leave;

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\My RTX Files\\%s"), tchDirDocuments, tchAccount);
		CDirectoryControl::Delete(tchPath);

		OsProcessorType = COperationSystemVersion::GetInstance()->GetOSProcessorType();
		if (OS_PROCESSOR_TYPE_X64 == OsProcessorType)
			StringCchPrintf(tchSubKey, _countof(tchSubKey), _T("SOFTWARE\\Wow6432Node\\Tencent\\RTXC"));
		else
			StringCchPrintf(tchSubKey, _countof(tchSubKey), _T("SOFTWARE\\Tencent\\RTXC"));

		dwDataBufSizeB = sizeof(tchInstDir);
		lStatus = SHRegGetValue(
			HKEY_LOCAL_MACHINE,
			tchSubKey,
			_T("INSTDIR"),
			SRRF_RT_REG_SZ,
			&dwType,
			tchInstDir,
			&dwDataBufSizeB
			);
		if (ERROR_SUCCESS == lStatus)
		{
			if (_T('\\') == *(tchInstDir + _tcslen(tchInstDir) - 1))
				*(tchInstDir + _tcslen(tchInstDir) - 1) = _T('\0');	

			do 
			{
				lpPosition = StrRChr(tchInstDir, NULL, _T('\\'));
				if (!lpPosition)
					break;

				*lpPosition = _T('_');
			} while (TRUE);

			lpPosition = StrRChr(tchInstDir, NULL, _T(':'));
			if (lpPosition)
			{
				*lpPosition = *(lpPosition - 1);
				StringCchPrintf(tchInstDir, _countof(tchInstDir), _T("%s"), lpPosition);

				for (*tchInstDir = _T('C'); *tchInstDir <= _T('Z'); (*tchInstDir)++)
				{
					StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\RTXC File List\\%s\\Accounts\\%s"), tchDirDocuments, tchInstDir, tchAccount);
					CDirectoryControl::Delete(tchPath);

					StringCchPrintf(tchPathCfg, _countof(tchPathCfg), _T("%s\\RTXC File List\\%s\\Accounts\\rtx.cfg"), tchDirDocuments, tchInstDir);

					if (GetPrivateProfileString(_T("Default"), _T("file_page_path"), _T(""), tchPath, _countof(tchPath), tchPathCfg))
					{
						StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\%s"), tchPath, tchAccount);
						CDirectoryControl::Delete(tchPath);

						WritePrivateProfileString(_T("Default"), _T("file_page_path"), _T(""), tchPathCfg);
					}

					WritePrivateProfileString(_T("Default"), _T("strAccount"), _T(""), tchPathCfg);
					WritePrivateProfileString(_T("Default"), _T("strPassword"), _T(""), tchPathCfg);
				}
			}		
		}

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\RTXC File List\\%s\\Accounts\\UserPhotos\\%s"), tchDirDocuments, tchInstDir, tchAccount);
		DeleteFile(tchPath);
	}
	__finally
	{
		;
	}

	return;
}
