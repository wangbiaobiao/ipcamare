#pragma once

#include "IPCamera.h"
#include "afxwin.h"
// CEventSet 对话框

class CEventSet : public CDialog
{
	DECLARE_DYNAMIC(CEventSet)

public:
	CEventSet(CWnd* pParent = NULL);   // 标准构造函数
	CEventSet(CWnd* pParent, LPVOID handle_) ;
	virtual ~CEventSet();

// 对话框数据
	enum { IDD = IDD_DIALOG_EVENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CString m_strEventType;
	CString m_strEventPriority;
	CString m_strEventRespond;
	CComboBox m_ctlEventType;
	CComboBox m_ctlPriority;
	CComboBox m_ctlRespond;
	IPC_ActionOptionInfo	m_action ;
	IPC_MontionDetectionWindowInfo m_md[4] ;

	ipcHandle		_handle ;

public:

	void	SetActionOption(IPC_ActionOptionInfo* action) ;
	afx_msg void OnCbnSelchangeComboEventType();
	afx_msg void OnBnClickedButtonSet();
	afx_msg void OnBnClickedButtonGet();
	afx_msg void OnBnClickedButtonAction();
};
