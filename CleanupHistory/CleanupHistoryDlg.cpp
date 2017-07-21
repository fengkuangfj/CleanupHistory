
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
	ON_BN_CLICKED(IDC_BUTTON19, &CCleanupHistoryDlg::OnBnClickedFoxmail)
	ON_BN_CLICKED(IDC_BUTTON20, &CCleanupHistoryDlg::OnBnClickedGoogleChrome)
	ON_BN_CLICKED(IDC_BUTTON21, &CCleanupHistoryDlg::OnBnClickedYoudaoDict)
	ON_BN_CLICKED(IDC_BUTTON22, &CCleanupHistoryDlg::OnBnClickedThunder)
	ON_BN_CLICKED(IDC_BUTTON23, &CCleanupHistoryDlg::OnBnClickedXmp)
	ON_BN_CLICKED(IDC_BUTTON24, &CCleanupHistoryDlg::OnBnClickedYoudaoNote)
	ON_BN_CLICKED(IDC_BUTTON25, &CCleanupHistoryDlg::OnBnClicked360se)
	ON_BN_CLICKED(IDC_BUTTON26, &CCleanupHistoryDlg::OnBnClicked360Safe)
	ON_BN_CLICKED(IDC_BUTTON27, &CCleanupHistoryDlg::OnBnClickedAll)
	ON_BN_CLICKED(IDC_BUTTON28, &CCleanupHistoryDlg::OnBnClickedWeChat)
	ON_BN_CLICKED(IDC_BUTTON29, &CCleanupHistoryDlg::OnBnClickedDingDing)
	ON_BN_CLICKED(IDC_BUTTON30, &CCleanupHistoryDlg::OnBnClickedFeiGe)
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

		for (; *tchDir <= _T('Z'); (*tchDir)++)
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

		for (; *tchDir <= _T('Z'); (*tchDir)++)
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

		for (; *tchDir <= _T('Z'); (*tchDir)++)
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
		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\RAS AutoDial\\Addresses"));
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

		for (; *tchDir <= _T('Z'); (*tchDir)++)
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
		if (S_OK != hResult && E_UNEXPECTED != hResult)
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
		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU"));
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

		for (; *tchDir <= _T('Z'); (*tchDir)++)
			CDirectoryControl::Empty(tchDir);

		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RecentDocs"));
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
		SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\RecentDocs"), _T("DefaultUserName"));

		SHDeleteValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\RecentDocs"), _T("AltDefaultUserName"));

		SHDeleteValue(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Winlogon\\RecentDocs"), _T("DefaultUserName"));
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
		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Doc Find Spec"));

		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\ContainingTextMRU"));

		SHDeleteKey(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\FilesNamedMRU"));
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
		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FindComputerMRU"));

		SHDeleteKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\ComputerNameMRU"));
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

		for (; *tchDir <= _T('Z'); (*tchDir)++)
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
	TCHAR tchAccount[MAX_PATH] = {0};
	TCHAR tchDirRoaming[MAX_PATH] = {0};
	TCHAR tchDirProgramData[MAX_PATH] = {0};
	TCHAR tchDirDocuments[MAX_PATH] = {0};
	TCHAR tchPath[MAX_PATH] = {0};


	__try
	{
		if (!GetAccount(_T("QQ"), tchAccount, _countof(tchAccount)))
			__leave;

		CCommandLine::Execute(_T("taskkill /f /im qqprotect.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im qq.exe"), TRUE, TRUE, NULL);

		// 目录

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent"), tchDirRoaming);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::DeleteInternalDir(tchPath, tchAccount, FALSE);

		// C:\ProgramData
		if (!SHGetSpecialFolderPath(NULL, tchDirProgramData, CSIDL_COMMON_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQProtect\\Qscan\\%s"), tchDirProgramData, tchAccount);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::Delete(tchPath);

		// D:\My Documents
		if (!SHGetSpecialFolderPath(NULL, tchDirDocuments, CSIDL_MYDOCUMENTS, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\%s"), tchDirDocuments, tchAccount);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::Delete(tchPath);

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent\\QQ\\Misc\\%s"), tchDirRoaming, tchAccount);
		DeleteFile(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\All Users\\QQ\\Misc"), tchDirDocuments);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::DeleteInternalFile(tchPath, tchAccount, TRUE);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Tencent Files\\All Users\\QQ"), tchDirDocuments);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::DeleteInternalFile(tchPath, _T(".db"), TRUE);

		// 注册表
		StringCchPrintf(tchPath, _countof(tchPath), _T("SOFTWARE\\Tencent\\Plugin\\VAS\\%s"), tchAccount);
		SHDeleteKey(HKEY_CURRENT_USER, tchPath);
	}
	__finally
	{
		;
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
		if (!GetAccount(_T("RTX"), tchAccount, _countof(tchAccount)))
			__leave;

		CCommandLine::Execute(_T("taskkill /f /im rtx.exe"), TRUE, TRUE, NULL);

		// 目录

		// D:\My Documents
		if (!SHGetSpecialFolderPath(NULL, tchDirDocuments, CSIDL_MYDOCUMENTS, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\My RTX Files\\%s"), tchDirDocuments, tchAccount);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::Delete(tchPath);

		OsProcessorType = COperationSystemVersion::GetInstance()->GetOSProcessorType();
		if (OS_PROCESSOR_TYPE_X64 == OsProcessorType)
			StringCchPrintf(tchSubKey, _countof(tchSubKey), _T("SOFTWARE\\Wow6432Node\\Tencent\\RTXC"));
		else
			StringCchPrintf(tchSubKey, _countof(tchSubKey), _T("SOFTWARE\\Tencent\\RTXC"));

		dwDataBufSizeB = sizeof(tchInstDir);
		lStatus = RegGetValue(
			HKEY_LOCAL_MACHINE,
			tchSubKey,
			_T("INSTDIR"),
			RRF_RT_REG_SZ,
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
					for (; *tchPath <= _T('Z'); (*tchPath)++)
						CDirectoryControl::Delete(tchPath);

					StringCchPrintf(tchPathCfg, _countof(tchPathCfg), _T("%s\\RTXC File List\\%s\\Accounts\\rtx.cfg"), tchDirDocuments, tchInstDir);
					if (GetPrivateProfileString(_T("Default"), _T("file_page_path"), _T(""), tchPath, _countof(tchPath), tchPathCfg))
					{
						StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\%s"), tchPath, tchAccount);
						for (; *tchPath <= _T('Z'); (*tchPath)++)
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

void CCleanupHistoryDlg::OnBnClickedFoxmail()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS lStatus = ERROR_SUCCESS;
	DWORD	dwType = 0;
	TCHAR	tchInstDir[MAX_PATH] = {0};
	TCHAR	tchDirRoaming[MAX_PATH] = {0};
	DWORD	dwInstDirSizeB = 0;
	TCHAR	tchAccount[MAX_PATH] = {0};
	TCHAR	tchPath[MAX_PATH] = {0};
	TCHAR	tchVersion[MAX_PATH] = {0};
	LPTSTR	lpPosition = NULL;


	__try
	{
		if (!GetAccount(_T("Foxmail"), tchAccount, _countof(tchAccount)))
			__leave;

		CCommandLine::Execute(_T("taskkill /f /im foxmail.exe"), TRUE, TRUE, NULL);

		// 目录

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		dwInstDirSizeB = sizeof(tchInstDir);
		lStatus = RegGetValue(
			HKEY_CURRENT_USER,
			_T("Software\\Aerofox\\FoxmailPreview"),
			_T("Executable"),
			RRF_RT_REG_SZ,
			&dwType,
			tchInstDir,
			&dwInstDirSizeB
			);
		if (ERROR_SUCCESS == lStatus)
		{
			if (PathRemoveFileSpec(tchInstDir))
			{
				StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Storage\\%s"), tchInstDir, tchAccount);
				for (; *tchPath <= _T('Z'); (*tchPath)++)
					CDirectoryControl::Delete(tchPath);

				lpPosition = PathFindFileName(tchInstDir);
				if (lpPosition)
				{
					StringCchPrintf(tchVersion, _countof(tchVersion), lpPosition);
					lpPosition = StrRChr(tchVersion, NULL, _T(' '));
					if (lpPosition)
					{
						StringCchPrintf(tchVersion, _countof(tchVersion), lpPosition + 1);
						lpPosition = StrRChr(tchVersion, NULL, _T('.'));
						if (lpPosition)
						{
							*lpPosition = _T('\0');
							StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Foxmail%s"), tchDirRoaming, tchVersion);
							for (; *tchPath <= _T('Z'); (*tchPath)++)
								CDirectoryControl::Empty(tchPath);
						}
					}
				}
			}
		}

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Global\\domain.ini"), tchInstDir);
		DeleteFile(tchPath);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedGoogleChrome()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR			tchLocal[MAX_PATH] = {0};
	TCHAR			tchPreferences[MAX_PATH] = {0};
	HANDLE			hFile = INVALID_HANDLE_VALUE;
	LARGE_INTEGER 	liFileSize = {0};
	LPSTR			lpstrData = NULL;
	DWORD			dwReaded = 0;
	LPTSTR			lptstrData = NULL;
	ULONG			ultchPathSizeCh = 0;
	LPTSTR			lpPathBegin = NULL;
	LPTSTR			lpPathEnd = NULL;
	TCHAR			tchPath[MAX_PATH] = {0};
	TCHAR			tchUser[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im chrome.exe"), TRUE, TRUE, NULL);

		// 目录

		// C:\Users\Administrator\AppData\Local
		if (!SHGetSpecialFolderPath(NULL, tchLocal, CSIDL_LOCAL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchPreferences, _countof(tchPreferences), _T("%s\\Google\\Chrome\\User Data\\Default\\Preferences"), tchLocal);

		hFile = CreateFile(
			tchPreferences,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL			
			);
		if (INVALID_HANDLE_VALUE != hFile)
		{
			if (GetFileSizeEx(hFile, &liFileSize))
			{
				lpstrData = (LPSTR)calloc(1, (size_t)liFileSize.QuadPart);
				if (lpstrData)
				{
					if (ReadFile(
						hFile,
						lpstrData,
						(DWORD)liFileSize.QuadPart,
						&dwReaded,
						NULL
						))
					{
						if (!CStringInternal::ASCIIToUNICODE(lptstrData, &ultchPathSizeCh, lpstrData, (ULONG)liFileSize.QuadPart, CP_UTF8))
						{
							if (ultchPathSizeCh)
							{
								lptstrData = (LPTSTR)calloc(1, ultchPathSizeCh * sizeof(TCHAR));
								if (lptstrData)
								{
									if (CStringInternal::ASCIIToUNICODE(lptstrData, &ultchPathSizeCh, lpstrData, (ULONG)liFileSize.QuadPart, CP_UTF8))
									{
										lpPathBegin = StrStr(lptstrData, _T("\"download\":{\"default_directory\":\""));
										if (lpPathBegin)
										{
											lpPathBegin += _tcslen(_T("\"download\":{\"default_directory\":\""));
											lpPathEnd = StrStr(lpPathBegin, _T("\""));
											if (lpPathEnd)
											{
												*lpPathEnd = _T('\0');
												StringCchPrintf(tchPath, _countof(tchPath), _T("%s"), lpPathBegin);
												for (; *tchPath <= _T('Z'); (*tchPath)++)
													CDirectoryControl::Delete(tchPath);
											}
										}
									}
								}
							}	
						}						
					}
				}
			}
		}		

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Google\\Chrome\\User Data"), tchLocal);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::Delete(tchPath);		

		StringCchPrintf(tchUser, _countof(tchUser), _T("%s"), tchLocal);
		if (PathRemoveFileSpec(tchUser))
		{
			if (PathRemoveFileSpec(tchUser))
			{
				StringCchPrintf(tchUser, _countof(tchUser), _T("%s\\Downloads"), tchUser);
				for (; *tchUser <= _T('Z'); (*tchUser)++)
					CDirectoryControl::Delete(tchUser);
			}
		}
	}
	__finally
	{
		if (lptstrData)
			free(lptstrData);

		if (lpstrData)
			free(lpstrData);

		if (INVALID_HANDLE_VALUE != hFile)
			CloseHandle(hFile);
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedYoudaoDict()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchAccount[MAX_PATH] = {0};
	TCHAR tchLocal[MAX_PATH] = {0};
	TCHAR tchPath[MAX_PATH] = {0};


	__try
	{
		if (!GetAccount(_T("YoudaoDict"), tchAccount, _countof(tchAccount)))
			__leave;

		CCommandLine::Execute(_T("taskkill /f /im yodaodict.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im youdaoie.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im wordbook.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im youdaodicthelper.exe"), TRUE, TRUE, NULL);

		// 目录

		// C:\Users\Administrator\AppData\Local
		if (!SHGetSpecialFolderPath(NULL, tchLocal, CSIDL_LOCAL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Yodao\\DeskDict\\WbData\\%s"), tchLocal, tchAccount);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::Delete(tchPath);

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Yodao\\DeskDict\\wordbookloginhistory.dat"), tchLocal);
		DeleteFile(tchPath);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedThunder()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR	tchAccount[MAX_PATH] = {0};
	LSTATUS	lStatus = ERROR_SUCCESS;
	DWORD	dwType = 0;
	TCHAR	tchInstDir[MAX_PATH] = {0};
	DWORD	dwInstDirSizeB = 0;
	TCHAR	tchDir[MAX_PATH] = {0};
	TCHAR	tchNewTask[MAX_PATH] = {0};
	BOOL	bCheckAll = FALSE;


	__try
	{
		if (!GetAccount(_T("Thunder"), tchAccount, _countof(tchAccount)))
			__leave;

		CCommandLine::Execute(_T("taskkill /f /im thunder.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im thunderbrowser.exe"), TRUE, TRUE, NULL);

		// 目录
		dwInstDirSizeB = sizeof(tchInstDir);
		lStatus = RegGetValue(
			HKEY_CURRENT_USER,
			_T("Software\\Thunder Network\\Thunder"),
			_T("Path"),
			RRF_RT_REG_SZ,
			&dwType,
			tchInstDir,
			&dwInstDirSizeB
			);
		if (ERROR_SUCCESS != lStatus)
		{
			if (OS_PROCESSOR_TYPE_X86 == COperationSystemVersion::GetInstance()->GetOSProcessorType())
				StringCchPrintf(tchInstDir, _countof(tchInstDir), _T("C:\\Program Files\\Thunder Network\\Thunder\\Program\\Thunder.exe"));
			else
				StringCchPrintf(tchInstDir, _countof(tchInstDir), _T("C:\\Program Files (x86)\\Thunder Network\\Thunder\\Program\\Thunder.exe"));

			bCheckAll = TRUE;
		}

		for (; *tchInstDir <= _T('Z'); (*tchInstDir)++)
		{
			if (PathRemoveFileSpec(tchInstDir))
			{
				if (PathRemoveFileSpec(tchInstDir))
				{
					StringCchPrintf(tchNewTask, _countof(tchNewTask), _T("%s\\Profiles\\newtask.ini"), tchInstDir);
					if (GetPrivateProfileString(_T("TaskDefaultSettings"), _T("DefaultPath"), _T(""), tchDir, _countof(tchDir), tchNewTask))
					{
						if (_T('\\') == *(tchDir + _tcslen(tchDir) - 1))
							*(tchDir + _tcslen(tchDir) - 1) = _T('\0');

						for (; *tchDir <= _T('Z'); (*tchDir)++)
							CDirectoryControl::Delete(tchDir);

						WritePrivateProfileString(_T("TaskDefaultSettings"), _T("DefaultPath"), _T(""), tchNewTask);
					}

					StringCchPrintf(tchDir, _countof(tchDir), _T("%s\\Profiles"), tchInstDir);

					for (; *tchDir <= _T('Z'); (*tchDir)++)
						CDirectoryControl::EmptyExceptFile(tchDir, _T("Thunder.ico"), FALSE);
				}
			}

			if (!bCheckAll)
				break;
		}

		StringCchPrintf(tchDir, _countof(tchDir), _T("C:\\迅雷下载"));
		for (; *tchDir <= _T('Z'); (*tchDir)++)
			CDirectoryControl::Delete(tchDir);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedXmp()
{
	// TODO: 在此添加控件通知处理程序代码
	LSTATUS							lStatus = ERROR_SUCCESS;
	DWORD							dwType = 0;
	TCHAR							tchInstDir[MAX_PATH] = {0};
	DWORD							dwInstDirSizeB = 0;
	TCHAR							tchDir[MAX_PATH] = {0};
	TCHAR							tchTemp[MAX_PATH] = {0};
	OS_PROCESSOR_TYPE_USER_DEFINED	OsProcessorType = OS_PROCESSOR_TYPE_UNKNOWN;
	TCHAR							tchSubKey[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im xmp.exe"), TRUE, TRUE, NULL);

		// 目录

		// C:\Users\Administrator\AppData\Local\Temp
		if (!GetTempPath(_countof(tchTemp), tchTemp))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "GetTempPath failed. (%d)", GetLastError());
			__leave;
		}

		StringCchPrintf(tchDir, _countof(tchDir), _T("%sxmp"), tchTemp);
		for (; *tchDir <= _T('Z'); (*tchDir)++)
			CDirectoryControl::Delete(tchDir);

		OsProcessorType = COperationSystemVersion::GetInstance()->GetOSProcessorType();
		if (OS_PROCESSOR_TYPE_X64 == OsProcessorType)
			StringCchPrintf(tchSubKey, _countof(tchSubKey), _T("SOFTWARE\\Wow6432Node\\Thunder Network\\Xmp"));
		else
			StringCchPrintf(tchSubKey, _countof(tchSubKey), _T("SOFTWARE\\Thunder Network\\Xmp"));

		dwInstDirSizeB = sizeof(tchInstDir);
		lStatus = RegGetValue(
			HKEY_LOCAL_MACHINE,
			tchSubKey,
			_T("CoreDir"),
			RRF_RT_REG_SZ,
			&dwType,
			tchInstDir,
			&dwInstDirSizeB
			);
		if (ERROR_SUCCESS == lStatus)
		{
			if (PathRemoveFileSpec(tchInstDir))
			{
				StringCchPrintf(tchDir, _countof(tchDir), _T("%s\\ProgramData"), tchInstDir);
				for (; *tchDir <= _T('Z'); (*tchDir)++)
					CDirectoryControl::Delete(tchDir);

			}
		}

		StringCchPrintf(tchDir, _countof(tchDir), _T("C:\\xmpcache"));
		for (; *tchDir <= _T('Z'); (*tchDir)++)
			CDirectoryControl::Delete(tchDir);

		dwInstDirSizeB = sizeof(tchInstDir);
		lStatus = RegGetValue(
			HKEY_LOCAL_MACHINE,
			tchSubKey,
			_T("StorePath"),
			RRF_RT_REG_SZ,
			&dwType,
			tchDir,
			&dwInstDirSizeB
			);
		if (ERROR_SUCCESS == lStatus)
		{
			for (; *tchDir <= _T('Z'); (*tchDir)++)
				CDirectoryControl::Delete(tchDir);

			SHDeleteValue(
				HKEY_LOCAL_MACHINE,
				tchSubKey,
				_T("StorePath")
				);
		}
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedYoudaoNote()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchAccount[MAX_PATH] = {0};
	TCHAR tchLocal[MAX_PATH] = {0};
	TCHAR tchPath[MAX_PATH] = {0};


	__try
	{
		if (!GetAccount(_T("YoudaoNote"), tchAccount, _countof(tchAccount)))
			__leave;

		CCommandLine::Execute(_T("taskkill /f /im youdaonote.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im YNoteCefRender.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im DocToPDF.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Local
		if (!SHGetSpecialFolderPath(NULL, tchLocal, CSIDL_LOCAL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		// 目录
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\YNote\\Data"), tchLocal);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::Empty(tchPath);

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\youdao\\ynote"), tchLocal);
		for (; *tchPath <= _T('Z'); (*tchPath)++)
			CDirectoryControl::DeleteInternalFile(tchPath, tchAccount, TRUE);

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\youdao\\ynote\\history15.dat"), tchLocal);
		DeleteFile(tchPath);
	}
	__finally
	{
		;
	}

	return;
}

BOOL
CCleanupHistoryDlg::GetAccount(
							   __in		LPTSTR	lpKey,
							   __inout	LPTSTR	lpAccount,
							   __in		ULONG	ulSizeCh
							   )
{
	BOOL	bRet = FALSE;

	TCHAR	tchPath[MAX_PATH] = {0};


	__try
	{
		if (!lpKey || !lpAccount || !ulSizeCh)
			__leave;

		if (!CProcessControl::GetInstance()->Get(TRUE, 0, tchPath, _countof(tchPath)))
			__leave;

		if (!PathRemoveFileSpec(tchPath))
			__leave;

		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\Account.ini"), tchPath);

		if (!GetPrivateProfileString(
			_T("Account"),
			lpKey,
			NULL,
			lpAccount,
			ulSizeCh,
			tchPath
			))
			__leave;

		if (!_tcslen(lpAccount))
			__leave;

		bRet = TRUE;
	}
	__finally
	{
		;
	}

	return bRet;
}

void CCleanupHistoryDlg::OnBnClicked360se()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR tchDirRoaming[MAX_PATH] = {0};
	TCHAR tchLoginIni[MAX_PATH] = {0};
	TCHAR tchDir[MAX_PATH] = {0};
	ULONG ulVersion = 10;


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im 360se.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		// 文件
		StringCchPrintf(tchLoginIni, _countof(tchLoginIni), _T("%s\\360se\\apps\\data\\common\\Favorites\\OptionFav.ini"), tchDirRoaming);
		if (!PathFileExists(tchLoginIni))
		{
			do 
			{
				StringCchPrintf(tchLoginIni, _countof(tchLoginIni), _T("%s\\360se%d\\apps\\data\\common\\Favorites\\OptionFav.ini"), tchDirRoaming, ulVersion--);
				if (PathFileExists(tchLoginIni))
				{
					DeleteFile(tchLoginIni);
					break;
				}
			} while (1 <= ulVersion);
		}
		else
			DeleteFile(tchLoginIni);

		StringCchPrintf(tchLoginIni, _countof(tchLoginIni), _T("%s\\360se\\apps\\data\\users\\login.ini"), tchDirRoaming);
		if (!PathFileExists(tchLoginIni))
		{
			ulVersion = 10;
			do 
			{
				StringCchPrintf(tchLoginIni, _countof(tchLoginIni), _T("%s\\360se%d\\apps\\data\\users\\login.ini"), tchDirRoaming, ulVersion--);
				if (PathFileExists(tchLoginIni))
				{
					GetPrivateProfileString(
						_T("NowLogin"),
						_T("AppUserDataPath"),
						NULL,
						tchDir,
						_countof(tchDir),
						tchLoginIni
						);
					break;
				}
			} while (1 <= ulVersion);
		}
		else
			GetPrivateProfileString(
			_T("NowLogin"),
			_T("AppUserDataPath"),
			NULL,
			tchDir,
			_countof(tchDir),
			tchLoginIni
			);

		// 目录
		if (4 <= _tcslen(tchDir))
		{
			if (_T('\\') == *(tchDir + _tcslen(tchDir) - 1))
				*(tchDir + _tcslen(tchDir) - 1) = _T('\0');

			for (; *tchDir <= _T('Z'); (*tchDir)++)
				CDirectoryControl::Delete(tchDir);
		}

		// 文件
		DeleteFile(tchLoginIni);
	}
	__finally
	{
		;
	}

	return;
}

void CCleanupHistoryDlg::OnBnClicked360Safe()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR			tchDirRoaming[MAX_PATH] = {0};
	TCHAR			tchDirExpression[MAX_PATH] = {0};
	HANDLE			hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA ffd = { 0 };
	TCHAR			tchPath[MAX_PATH] = {0};
	ULONG			ulVersion = 10;
	LSTATUS			lResult = ERROR_SUCCESS;


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im 360Safe.exe"), TRUE, TRUE, NULL);

		// 注册表
		SHDeleteValue(
			HKEY_CURRENT_USER,
			_T("Software\\360safe"),
			_T("IDLastedU")
			);
		if (ERROR_SUCCESS != lResult)
		{
			lResult = SHSetValue(
				HKEY_CURRENT_USER,
				_T("Software\\360safe"),
				_T("IDLastedU"),
				REG_SZ,
				_T("\0"),
				sizeof(TCHAR)
				);
		}

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		// 目录
		StringCchPrintf(tchDirExpression, _countof(tchDirExpression), _T("%s\\360Login\\*"), tchDirRoaming);

		hFind = FindFirstFile(tchDirExpression, &ffd);
		if (INVALID_HANDLE_VALUE == hFind)
		{
			printfEx(MOD_DIRECTORY_CONTROL, PRINTF_LEVEL_ERROR, "FindFirstFile failed. (%S) (%d)",
				tchDirExpression, GetLastError());

			__leave;
		}

		do
		{
			if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (0 != _tcsnicmp(ffd.cFileName, _T("."), wcslen(_T("."))) &&
					0 != _tcsnicmp(ffd.cFileName, _T(".."), wcslen(_T(".."))))
				{
					StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\360Login\\%s"), tchDirRoaming, ffd.cFileName);

					if (0 != _tcsicmp(_T("safeid"), ffd.cFileName))
					{
						for (; *tchPath <= _T('Z'); (*tchPath)++)
							CDirectoryControl::Delete(tchPath);

						StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\360Safe\\safeid\\safe\\%s"), tchDirRoaming, ffd.cFileName);
						for (; *tchPath <= _T('Z'); (*tchPath)++)
							CDirectoryControl::Delete(tchPath);
					}
				}
			}
		} while (0 != FindNextFile(hFind, &ffd));

		if (INVALID_HANDLE_VALUE != hFind)
		{
			FindClose(hFind);
			hFind = INVALID_HANDLE_VALUE;
		}

		// 文件
		StringCchPrintf(tchPath, _countof(tchPath), _T("%s\\360Login\\GlobleAccount.ini"), tchDirRoaming);
		DeleteFile(tchPath);
	}
	__finally
	{
		if (INVALID_HANDLE_VALUE != hFind)
		{
			FindClose(hFind);
			hFind = INVALID_HANDLE_VALUE;
		}
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedAll()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedTemporaryInternetFiles();
	OnBnClickedInternetCookies();
	OnBnClickedInternetHistoryItems();
	OnBnClickedInternetTypedUrls();
	OnBnClickedInternetProtectedStorageSystemProvider();
	OnBnClickedIntelliForms();
	OnBnClickedRASAdresses();
	OnBnClickedTemp();
	OnBnClickedRecycleBin();
	OnBnClickedRunMRU();
	OnBnClickedRecentDocs();
	OnBnClickedWinlogonUserName();
	OnBnClickedDocFindSpec();
	OnBnClickedFindComputerMRU();
	OnBnClickedNetHood();
	OnBnClickedTelNet();
	OnBnClickedQQ();
	OnBnClickedRTX();
	OnBnClickedFoxmail();
	OnBnClickedGoogleChrome();
	OnBnClickedYoudaoDict();
	OnBnClickedThunder();
	OnBnClickedXmp();
	OnBnClickedYoudaoNote();
	OnBnClicked360se();
	OnBnClicked360Safe();
	OnBnClickedWeChat();
	OnBnClickedDingDing();
	OnBnClickedFeiGe();

	return;
}

void CCleanupHistoryDlg::OnBnClickedWeChat()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR			tchDirDocuments[MAX_PATH] = {0};
	TCHAR			tchDirAllUsers[MAX_PATH] = {0};
	CHAR			chDirDocuments[MAX_PATH] = {0};
	TCHAR			tchFileConfigData[MAX_PATH] = {0};
	HANDLE			hFile = INVALID_HANDLE_VALUE;
	LARGE_INTEGER	liFileSize = {0};
	LPSTR			lpstrData = NULL;
	DWORD			dwReaded = 0;
	LPSTR			lpFileAccInfoDat = NULL;
	CHAR			chFileAccInfoDat[MAX_PATH] = {0};
	CHAR			chAccount[MAX_PATH] = {0};
	TCHAR			tchAccount[MAX_PATH] = {0};
	LPSTR			lpPosition = NULL;
	TCHAR			tchDirAccount[MAX_PATH] = {0};
	ULONG			ultchPathSizeCh = 0;


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im WeChat.exe"), TRUE, TRUE, NULL);

		// D:\My Documents
		if (!SHGetSpecialFolderPath(NULL, tchDirDocuments, CSIDL_MYDOCUMENTS, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		// 文件
		StringCchPrintf(tchDirAllUsers, _countof(tchDirAllUsers), _T("%s\\WeChat Files\\All Users"), tchDirDocuments);
		for (; *tchDirAllUsers <= _T('Z'); (*tchDirAllUsers)++)
			CDirectoryControl::DeleteInternalFile(tchDirAllUsers, _T(".jpg"), TRUE);

		// 目录
		StringCchPrintf(tchFileConfigData, _countof(tchFileConfigData), _T("%s\\config\\config.data"), tchDirAllUsers);

		hFile = CreateFile(
			tchFileConfigData,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL			
			);
		if (INVALID_HANDLE_VALUE == hFile)
			__leave;

		if (!GetFileSizeEx(hFile, &liFileSize))
			__leave;

		lpstrData = (LPSTR)calloc(1, (size_t)liFileSize.QuadPart);
		if (!lpstrData)
			__leave;

		if (!ReadFile(
			hFile,
			lpstrData,
			(DWORD)liFileSize.QuadPart,
			&dwReaded,
			NULL
			))
			__leave;

		CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;

		// D:\My Documents
		if (!SHGetSpecialFolderPathA(NULL, chDirDocuments, CSIDL_MYDOCUMENTS, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		lpFileAccInfoDat = CStringInternal::Find(lpstrData, (ULONG)liFileSize.QuadPart / sizeof(CHAR), chDirDocuments, strlen(chDirDocuments));
		if (!lpFileAccInfoDat)
			__leave;

		memcpy(chFileAccInfoDat, lpFileAccInfoDat, (size_t)liFileSize.QuadPart - (lpFileAccInfoDat - lpstrData) * sizeof(CHAR));
		StringCchPrintfA(chAccount, _countof(chAccount), "%s", chFileAccInfoDat + strlen(chDirDocuments) + strlen("\\WeChat Files\\"));
		lpPosition = StrChrA(chAccount, '\\');
		if (!lpPosition)
			__leave;

		*lpPosition = '\0';

		ultchPathSizeCh = _countof(tchAccount);
		CStringInternal::ASCIIToUNICODE(tchAccount, &ultchPathSizeCh, chAccount, strlen(chAccount), CP_UTF8);
		if (!ultchPathSizeCh)
			__leave;

		StringCchPrintf(tchDirAccount, _countof(tchDirAccount), _T("%s\\WeChat Files\\%s"), tchDirDocuments, tchAccount);
		for (; *tchDirAccount <= _T('Z'); (*tchDirAccount)++)
			CDirectoryControl::Delete(tchDirAccount);

		// 文件
		DeleteFile(tchFileConfigData);
	}
	__finally
	{
		if (lpstrData)
		{
			free(lpstrData);
			lpstrData = NULL;
		}

		if (INVALID_HANDLE_VALUE != hFile)	
		{
			CloseHandle(hFile);
			hFile = INVALID_HANDLE_VALUE;
		}
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedDingDing()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR			tchDirRoaming[MAX_PATH] = {0};
	TCHAR			tchDirAccount[MAX_PATH] = {0};
	TCHAR			tchDirLog[MAX_PATH] = {0};
	TCHAR			tchFileFlag[MAX_PATH] = {0};
	TCHAR			tchFileStorage[MAX_PATH] = {0};
	LPSTR			lpAccount = NULL;
	CHAR			chAccount[MAX_PATH] = {0};
	HANDLE			hFile = INVALID_HANDLE_VALUE;
	LARGE_INTEGER	liFileSize = {0};
	LPSTR			lpstrData = NULL;
	DWORD			dwReaded = 0;
	DWORD			i = 0;


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im DingTalk.exe"), TRUE, TRUE, NULL);
		CCommandLine::Execute(_T("taskkill /f /im DingTalkHelper.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		// 文件
		StringCchPrintf(tchFileStorage, _countof(tchFileStorage), _T("%s\\DingTalk\\globalStorage\\storage.db"), tchDirRoaming);
		DeleteFile(tchFileStorage);

		StringCchPrintf(tchFileFlag, _countof(tchFileFlag), _T("%s\\DingTalk\\flag.dat"), tchDirRoaming);

		hFile = CreateFile(
			tchFileFlag,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
			);
		if (INVALID_HANDLE_VALUE == hFile)
			__leave;

		if (!GetFileSizeEx(hFile, &liFileSize))
			__leave;

		lpAccount = (LPSTR)calloc(1, (size_t)liFileSize.QuadPart);
		if (!lpAccount)
			__leave;

		if (!ReadFile(
			hFile,
			lpAccount,
			(DWORD)liFileSize.QuadPart,
			&dwReaded,
			NULL
			))
			__leave;

		CloseHandle(hFile);
		hFile = INVALID_HANDLE_VALUE;

		DeleteFile(tchFileFlag);

		memcpy(chAccount, lpAccount, dwReaded);

		// 目录
		StringCchPrintf(tchDirAccount, _countof(tchDirAccount), _T("%s\\DingTalk\\%S"), tchDirRoaming, chAccount);
		for (; *tchDirAccount <= _T('Z'); (*tchDirAccount)++)
			CDirectoryControl::Delete(tchDirAccount);

		StringCchPrintf(tchDirLog, _countof(tchDirLog), _T("%s\\DingTalk\\log"), tchDirRoaming);
		for (; *tchDirLog <= _T('Z'); (*tchDirLog)++)
			CDirectoryControl::Delete(tchDirLog);
	}
	__finally
	{
		if (lpAccount)
		{
			free(lpAccount);
			lpAccount = NULL;
		}

		if (INVALID_HANDLE_VALUE != hFile)
		{
			CloseHandle(hFile);
			hFile = INVALID_HANDLE_VALUE;
		}
	}

	return;
}

void CCleanupHistoryDlg::OnBnClickedFeiGe()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR	tchDirRoaming[MAX_PATH] = {0};
	TCHAR	tchFileHistoryList[MAX_PATH] = {0};
	TCHAR	tchDirInstal[MAX_PATH] = {0};
	TCHAR	tchFileCustomName[MAX_PATH] = {0};
	TCHAR	tchFileSettingCfg[MAX_PATH] = {0};
	TCHAR	tchDirDownload[MAX_PATH] = {0};
	TCHAR	tchDirRecvFile[MAX_PATH] = {0};
	TCHAR	tchDirSaveAs[MAX_PATH] = {0};


	__try
	{
		CCommandLine::Execute(_T("taskkill /f /im Feige.exe"), TRUE, TRUE, NULL);

		// C:\Users\Administrator\AppData\Roaming
		if (!SHGetSpecialFolderPath(NULL, tchDirRoaming, CSIDL_APPDATA, FALSE))
		{
			CSimpleLogSR(MOD_CLEANUP_HISTORY_DLG, LOG_LEVEL_ERROR, "SHGetSpecialFolderPath failed. (%d)", GetLastError());
			__leave;
		}

		// 文件
		StringCchPrintf(tchFileHistoryList, _countof(tchFileHistoryList), _T("%s\\Feige\\HistoryList.db"), tchDirRoaming);
		DeleteFile(tchFileHistoryList);

		if (OS_PROCESSOR_TYPE_X86 == COperationSystemVersion::GetInstance()->GetOSProcessorType())
			StringCchPrintf(tchDirInstal, _countof(tchDirInstal), _T("C:\\Program Files\\Feige"));
		else
			StringCchPrintf(tchDirInstal, _countof(tchDirInstal), _T("C:\\Program Files (x86)\\Feige"));

		for (; *tchDirInstal <= _T('Z'); (*tchDirInstal)++)
		{
			StringCchPrintf(tchFileCustomName, _countof(tchFileCustomName), _T("%s\\CustomName.ini"), tchDirInstal);
			if (PathFileExists(tchFileCustomName))
				WritePrivateProfileString(_T("FeigeConfig"), _T("UserName"), _T(""), tchFileCustomName);

			// DefaultRecvFileDir
// 			for (; *tchDirRecvFile <= _T('Z'); (*tchDirRecvFile)++)
// 				CDirectoryControl::Delete(tchDirRecvFile);

			// DefaultSaveAsPath
// 			for (; *tchDirSaveAs <= _T('Z'); (*tchDirSaveAs)++)
// 				CDirectoryControl::Delete(tchDirSaveAs);
		}

		StringCchPrintf(tchDirDownload, _countof(tchDirDownload), _T("C:\\FeigeDownload"));
		for (; *tchDirDownload <= _T('Z'); (*tchDirDownload)++)
			CDirectoryControl::Delete(tchDirDownload);
	}
	__finally
	{
		;
	}

	return;
}
