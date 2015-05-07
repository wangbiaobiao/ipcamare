#pragma once


// CPTZTransPropGet �Ի���
#include "IPCSdkFuncDemoDlg.h"
class CPTZTransPropGet : public CDialog
{
	DECLARE_DYNAMIC(CPTZTransPropGet)

public:
	CPTZTransPropGet(CIPCPlayerDemoDlg* Owner,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPTZTransPropGet();

// �Ի�������
	enum { IDD = IDD_DIALOG_PTZ_TAB_GET };

    BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
    CIPCPlayerDemoDlg* m_Owner;
public:
    afx_msg void OnBnClickedOk();
    CString m_protocol;
    CString m_address;
    CString m_baudrate;
    CString m_databit;
    CString m_parity;
    CString m_stopbit;
    afx_msg void OnBnClickedButton1();
};
