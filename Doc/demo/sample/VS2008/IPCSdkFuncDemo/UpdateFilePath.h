#ifndef _CUPDATEFILEPATH_H
#define _CUPDATEFILEPATH_H

#pragma once
#include "afxwin.h"


// CUpdateFilePath 对话框

class CUpdateFilePath : public CDialog
{
	DECLARE_DYNAMIC(CUpdateFilePath)

public:
	CUpdateFilePath(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUpdateFilePath();

// 对话框数据
	enum { IDD = IDD_DIALOG_UPDATE_PATH };
	void	   SetUpdateIp(CString& strIp) ;
	void	   GetUpdateFilePath(CString& strPath_) ;
	CString    m_strIP;
	CString    m_strPath;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	CEdit m_strFilePath;
	afx_msg void OnBnClickedCancel();
};
#endif
