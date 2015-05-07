#ifndef _LOG_VIEW_DLG_H_
#define _LOG_VIEW_DLG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogViewDlg dialog
#include "resource.h"

#include "UserLogMgr.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "IPCamera.h"

class CLogViewDlg : public CDialog
{

public:

    CLogViewDlg(LPVOID handle, CWnd* pParent = NULL);

    enum { IDD = IDD_DIALOG_LOG_VIEW };

    CListCtrl m_listLogView ;

	 LPVOID                m_hSdkHandle ;                                    //sdkµÄÉè±¸¾ä±ú

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    virtual BOOL OnInitDialog();


    DECLARE_MESSAGE_MAP()

public:
 
	BOOL GetUIData(DWORD & dwType,IPC_TIME&  tmStart,BOOL& bUseStart,IPC_TIME&  tmEnd,BOOL& bUseEnd);
    void InsertRow(IPC_LOG & log);
	afx_msg void OnBnClickedGetlogcfg();
	afx_msg void OnBnClickedSetlogcfg();
	afx_msg void OnBnClickedCancel();
	CComboBox m_cmb_mode;
	int m_nMaxValue;
	afx_msg void OnCbnSelchangeComboMode();
	afx_msg void OnBnClickedButtonQuery();
	CDateTimeCtrl m_start_time;
	CDateTimeCtrl m_end_time;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnNMRClickListUserLog(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDelLog();
	afx_msg void OnBnClickedBtnGetcount();
	afx_msg void OnBnClickedBtnExport();
};

#endif //_LOG_VIEW_DLG_H_
