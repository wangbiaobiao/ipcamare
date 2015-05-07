#pragma once

#include "resource.h"

// CBufferTimeDlg 对话框

class CBufferTimeDlg : public CDialog
{
	DECLARE_DYNAMIC(CBufferTimeDlg)

public:
	CBufferTimeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBufferTimeDlg();

// 对话框数据
	enum { IDD = IDD_DLG_BUFFERTIME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nTime;
	afx_msg void OnBnClickedOk();
};
