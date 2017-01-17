
// CleanupHistoryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CleanupHistory.h"
#include "CleanupHistoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCleanupHistoryDlg �Ի���

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

// CCleanupHistoryDlg ��Ϣ�������

BOOL CCleanupHistoryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCleanupHistoryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCleanupHistoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCleanupHistoryDlg::OnBnClickedTemporaryInternetFiles()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
