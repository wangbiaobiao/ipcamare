#pragma once
#include "afxwin.h"


// CPTZTransPropSet 对话框
#include "IPCSdkFuncDemoDlg.h"
class CPTZTransPropSet : public CDialog
{
	DECLARE_DYNAMIC(CPTZTransPropSet)

public:
	CPTZTransPropSet(CIPCPlayerDemoDlg* Owner,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPTZTransPropSet();

// 对话框数据
	enum { IDD = IDD_DIALOG_PTZ_TAB_SET };

    BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
    CIPCPlayerDemoDlg* m_Owner;
public:
    afx_msg void OnBnClickedOk();
    CComboBox m_ctrl_protocol;
    CComboBox m_ctrl_address;
    CComboBox m_ctrl_baudrate;
    CComboBox m_ctrl_databit;
    CComboBox m_ctrl_parity;
    CComboBox m_ctrl_stopbit;
    afx_msg void OnBnClickedButton1();
};
