
// CleanupHistoryDlg.h : ͷ�ļ�
//

#pragma once

#define MOD_CLEANUP_HISTORY_DLG _T("������ʷ��¼�Ի���")

// CCleanupHistoryDlg �Ի���
class CCleanupHistoryDlg : public CDialog
{
	// ����
public:
	CCleanupHistoryDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_CLEANUPHISTORY_DIALOG };

	BOOL
		GetAccount(
		__in	LPTSTR	lpKey,
		__inout	LPTSTR	lpAccount,
		__in	ULONG	ulSizeCh
		);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedTemporaryInternetFiles();
	afx_msg void OnBnClickedInternetCookies();
	afx_msg void OnBnClickedInternetHistoryItems();
	afx_msg void OnBnClickedInternetTypedUrls();
	afx_msg void OnBnClickedInternetProtectedStorageSystemProvider();
	afx_msg void OnBnClickedIntelliForms();
	afx_msg void OnBnClickedRASAdresses();
	afx_msg void OnBnClickedTemp();
	afx_msg void OnBnClickedRecycleBin();
	afx_msg void OnBnClickedRunMRU();
	afx_msg void OnBnClickedRecentDocs();
	afx_msg void OnBnClickedWinlogonUserName();
	afx_msg void OnBnClickedDocFindSpec();
	afx_msg void OnBnClickedFindComputerMRU();
	afx_msg void OnBnClickedNetHood();
	afx_msg void OnBnClickedTelNet();
	afx_msg void OnBnClickedQQ();
	afx_msg void OnBnClickedRTX();
	afx_msg void OnBnClickedFoxmail();
	afx_msg void OnBnClickedGoogleChrome();
	afx_msg void OnBnClickedYoudaoDict();
	afx_msg void OnBnClickedThunder();
	afx_msg void OnBnClickedXmp();
	afx_msg void OnBnClickedYoudaoNote();
	afx_msg void OnBnClicked360se();
	afx_msg void OnBnClicked360Safe();
	afx_msg void OnBnClickedAll();
	afx_msg void OnBnClickedWeChat();
};
