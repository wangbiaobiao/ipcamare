#ifndef _CUPDATEFILEPATH_H
#define _CUPDATEFILEPATH_H

#pragma once
#include "afxwin.h"


// CUpdateFilePath �Ի���

class CUpdateFilePath : public CDialog
{
	DECLARE_DYNAMIC(CUpdateFilePath)

public:
	CUpdateFilePath(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpdateFilePath();

// �Ի�������
	enum { IDD = IDD_DIALOG_UPDATE_PATH };
	void	   SetUpdateIp(CString& strIp) ;
	void	   GetUpdateFilePath(CString& strPath_) ;
	CString    m_strIP;
	CString    m_strPath;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	CEdit m_strFilePath;
	afx_msg void OnBnClickedCancel();
};
#endif
