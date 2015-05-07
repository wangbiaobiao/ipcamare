#pragma once

#include "videoWnd.h"

#include "IEventCallBack.h"
#include "afxwin.h"
// CCameraConfigSetting 对话框

class CCameraConfigSetting : public CDialog, public ICallBackInterface
{
	DECLARE_DYNAMIC(CCameraConfigSetting)

public:
	CCameraConfigSetting(CWnd* pParent = NULL);   // 标准构造函数
	CCameraConfigSetting( LPVOID hSdk_, CVideoWnd* pVideoWnd_, CWnd* pParent = NULL);
	virtual ~CCameraConfigSetting();

// 对话框数据
	enum { IDD = IDD_CONFIG_SETTING };

	virtual BOOL  InitializeCallBack();   //初始化回调

	virtual BOOL  UnInitializeCallBack();//反初始化

	virtual void  OnContextResult(LPVOID lpConText );// 处理数据

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()


	void _hideAllBtn() ;

	CVideoWnd*		m_pVideoWnd ;
	LPVOID          m_hSdkHandle ;  
private:
	

	CString m_strStatic1;
	CString m_strStatic2;
	CString m_strStatic3;
	CString m_strStatic4;
	CString m_strStatic5;
	CString m_strStatic6;
	CString m_strStatic7;
	CString m_strStatic8;
	CString m_strStatic9;
	CString m_strStatic10;
	CString m_strStatic11;
	CString m_strStatic12;
	CString m_strStatic13;
	CString m_strStatic14;
	LONG  m_dwEdit1;
	CString/*LONG*/ m_dwEdit2;  //  DWORD dwVal = atoi(m_PropertySet.GetString()) ;
	CString m_dwEdit3;
	DWORD m_dwEdit4;
	DWORD m_dwEdit5;
	DWORD m_dwEdit6;
	DWORD m_dwEdit7;
	DWORD m_dwEdit8;
	DWORD m_dwEdit9;
	DWORD m_dwEdit10;
	DWORD m_dwEdit11;
	DWORD m_dwEdit12;
	DWORD m_dwEdit13;
	DWORD m_dwEdit14;
	DWORD m_cmd ;
public:
	CComboBox m_ctlConfigList;
	afx_msg void OnBnClickedConfigSet();
	afx_msg void OnBnClickedConfigGet();
	afx_msg void OnCbnSelchangeCombo1();
private:
	
	

};
