#pragma once

#include "resource.h"
// CFileCutDlg 对话框

class CFileCutDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileCutDlg)

public:
	CFileCutDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFileCutDlg();

// 对话框数据
	enum { IDD = IDD_DLG_CUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nStart;
	int m_nEnd;
	int m_max;
	CString m_strPath;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
