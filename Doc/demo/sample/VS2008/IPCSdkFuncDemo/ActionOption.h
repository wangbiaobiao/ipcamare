#pragma once

#ifdef _WIN32_WCE
#error "Windows CE ��֧�� CDHtmlDialog��"
#endif 
#include "EventSet.h"
#include "afxwin.h"
// CActionOption �Ի���


class CActionOption : public CDialog
{
	DECLARE_DYNAMIC(CActionOption)

public:
	CActionOption(CWnd* pParent = NULL);   // ��׼���캯��
	CActionOption(CWnd* pParent, CEventSet* event_);
	virtual ~CActionOption();

// �Ի�������
	enum { IDD = IDD_DIALOG_ACTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog() ;
	DECLARE_MESSAGE_MAP()

private:
	CEventSet*		m_Event ;
	IPC_ActionOptionInfo m_ation ;
	CComboBox m_ctlActionType;
	CComboBox m_ctlEnable;

	CString m_static_1;
	CString m_static_2;
	CString m_static_3;
	DWORD m_value_1;
	DWORD m_value_2;
	DWORD m_value_3;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeComboActiontype();
	afx_msg void OnBnClickedButtonSave();
	void GetActionOption(IPC_ActionOptionInfo* option) ;
	void SetActionOption(IPC_ActionOptionInfo* option) ;
private:
	void _HideAllBtn() ;
};
