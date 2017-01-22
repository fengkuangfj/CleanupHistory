
// CleanupHistoryDlg.h : 头文件
//

#pragma once

#define MOD_CLEANUP_HISTORY_DLG _T("清理历史记录对话框")

// CCleanupHistoryDlg 对话框
class CCleanupHistoryDlg : public CDialog
{
	// 构造
public:
	CCleanupHistoryDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_CLEANUPHISTORY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
};
