#ifndef _SYSTEM_SETTING_DLG_H_
#define _SYSTEM_SETTING_DLG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSystemSettingDlg dialog
#include "resource.h"

#include "videoWnd.h"

#include "IEventCallBack.h"

class CVideoWnd ;
class CSystemSettingDlg : public CDialog, public ICallBackInterface
{
    CString m_systemsettingValue ;

    DWORD                    m_cmd ;

    LPVOID                m_hSdkHandle ;                                    //sdk的设备句柄

public:

    CSystemSettingDlg( LPVOID hSdk_, CVideoWnd* pVideoWnd_, CWnd* pParent = NULL);

	virtual ~CSystemSettingDlg() ;

    enum { IDD = IDD_DIALOG_SYSTEMSETTING };

    CComboBox m_cmdList ;

	virtual BOOL  InitializeCallBack();   //初始化回调

	virtual BOOL  UnInitializeCallBack();//反初始化

	virtual void  OnContextResult(LPVOID lpConText );// 处理数据

protected:
	void	DisableAll() ;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonSystemsettingSet();
    afx_msg void OnBnClickedButtonSystemsettingGet();
	afx_msg void OnCbnSelchangeComboSystemsetting();
	afx_msg void OnBnClickedRadioSystemDisable();
	afx_msg void OnBnClickedRadioSystemAble();	
private:
	CString m_strSystemData1;
	CString m_strSystemData2;
	CString m_strSystemData3;
	CString m_strSystemData4;
	CString m_strSystemData5;
	CString m_strSystemData6;
	CString m_strSystemData7;
	CString m_strSystemData8;
	CString m_strSystemData9;
	CString m_strSystemData10;
	CString m_strSystemData11;
	CString m_strSystemData12;

	DWORD m_dwSystemSetData1;
	DWORD m_dwSystemSetData2;
	DWORD m_dwSystemSetData3;
	DWORD m_dwSystemSetData4;
	CString m_strSystemSetData5;
	CString m_strSystemSetData6;
	CString m_strSystemSetData7;
	CString m_strSystemSetData8;
	CString m_strSystemSetData9;
	CString m_strSystemSetData10;
	CString m_strSystemSetData11;
	CString m_strSystemSetData12;

	CVideoWnd*		m_pVideoWnd ;
public:
	afx_msg void OnBnClickedButtonRestart();
	afx_msg void OnBnClickedButtonDefault();
	afx_msg void OnBnClickedButtonWaiting();
	afx_msg void OnBnClickedButtonWakeup();
};

#endif //_SYSTEM_SETTING_DLG_H_
