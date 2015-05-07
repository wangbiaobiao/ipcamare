#pragma once
#include "ActiveXCtl.h"

// CActiveDlg 对话框

class CActiveDlg : public CDialog
{
	DECLARE_DYNAMIC(CActiveDlg)

public:
	CActiveDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CActiveDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ACTIVEX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CActiveXCtl		m_ActiveXCtl;
};
