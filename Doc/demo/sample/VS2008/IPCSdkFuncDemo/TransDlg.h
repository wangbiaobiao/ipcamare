#pragma once
#include "afxcmn.h"

#include "PTZTransPropGet.h"

#include "PTZTransPropSet.h"

#include "IPCSdkFuncDemoDlg.h"
// CTransDlg 对话框

class CTransDlg : public CDialog
{
	DECLARE_DYNAMIC(CTransDlg)

public:
	CTransDlg(CIPCPlayerDemoDlg* owner,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTransDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_TRANS_OPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
