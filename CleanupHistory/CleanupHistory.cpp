
// CleanupHistory.cpp : ����Ӧ�ó��������Ϊ��
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

// CCleanupHistoryApp ����

CCleanupHistoryApp::CCleanupHistoryApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CCleanupHistoryApp ����

CCleanupHistoryApp theApp;

// CCleanupHistoryApp ��ʼ��

BOOL CCleanupHistoryApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	Init();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CCleanupHistoryDlg dlg;
	m_pMainWnd = &dlg;

	TCHAR tchWarning[MAX_PATH] = {0};
	if (dlg.GetAccount(_T("Warning"), tchWarning, _countof(tchWarning)) &&
		0 == _tcsicmp(_T("1"), tchWarning))
		MessageBox(
		NULL,
		_T("����������¼�˺ŵ�������Ϣ��\
		   \r1���û���������\
		   \r2�����õ�����Ŀ¼�µ������ļ�\
		   \r3�����˺���ص��ļ���Ŀ¼\
		   \r4�����������ҳ���ļ���ʷ��¼\
		   \n\
		   \rAccount.ini���뱾exeͬĿ¼����ʽ����\
		   \r[Account]\
		   \rQQ=464447966\
		   \rRTX=yuexiang\
		   \rFoxmail=yuexiang@huatusoft.com\
		   \rYoudaoDict=fly464447966@126.com\
		   \rThunder=fengkuangfj\
		   \rYoudaoNote=fly464447966@126.com\
		   \r360se=fly464447966@126.com\
		   \n\
		   \rע��\
		   \r1����������ݲ�֧�ֻ�������Account.ini�������˺�\
		   \r2�������ڳ�����Ϲ黹���ñʼǱ�ʱʹ��(����������ϵͳ��ԭ�Ļ�)\
		   \r3�����Allһ������\
		   \r4������ΪʲôҪ�����㶮��"),
		   _T("��ʾ"),
		   MB_OK
		   );

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�

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
