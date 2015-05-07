#pragma once

#include "IPCamera.h"
#include "afxwin.h"
// CCruiseDlg 对话框

class CCruiseDlg : public CDialog
{
	DECLARE_DYNAMIC(CCruiseDlg)

public:
	CCruiseDlg(ipcHandle device,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCruiseDlg();

// 对话框数据
	enum { IDD = IDD_DLG_CRUISE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnRun();
	afx_msg void OnBnClickedBtnStop();
	virtual BOOL OnInitDialog();

protected:
 	ipcHandle   m_hDevice;
	IPC_PTZCruiseParam  m_all[IPC_MAX_CRUISE_PATH];
	INT				m_count;
	void InitData();
public:
	CComboBox m_cmb_cruise;
	CButton m_cruise_enable;
	CListBox m_list_presets;
	afx_msg void OnCbnSelchangeComboCruise();
	CEdit m_cruisename;
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnClraeall();
	afx_msg void OnBnClickedBtnModify();
};
