
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
};
