#pragma once
#include "afxcmn.h"

#include "PTZTransPropGet.h"

#include "PTZTransPropSet.h"

#include "IPCSdkFuncDemoDlg.h"
// CTransDlg �Ի���

class CTransDlg : public CDialog
{
	DECLARE_DYNAMIC(CTransDlg)

public:
	CTransDlg(CIPCPlayerDemoDlg* owner,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTransDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_TRANS_OPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
    CIPCPlayerDemoDlg* m_Owner ;
public:

    CPTZTransPropSet m_StPrprtDlg;

    CPTZTransPropGet m_GtPrprtDlg;
    afx_msg void OnTcnSelchangeTabGetSet(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedCancel();
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    CTabCtrl m_TbCtrl;

};
