#pragma once

#include "resource.h"
// CFileCutDlg �Ի���

class CFileCutDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileCutDlg)

public:
	CFileCutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileCutDlg();

// �Ի�������
	enum { IDD = IDD_DLG_CUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nStart;
	int m_nEnd;
	int m_max;
	CString m_strPath;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
