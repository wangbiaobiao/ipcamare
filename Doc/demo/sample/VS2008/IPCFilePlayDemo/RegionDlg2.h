#pragma once


// CRegionDlg2 对话框
#include "resource.h"
#include "IPCPlayer.h"
#include "LivePlayView.h"

class CRegionDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CRegionDlg2)

public:
	CRegionDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegionDlg2();
	CRegionDlg2(void *pStreamPlayer,CRect rc,CWnd* pParent = NULL);   // standard constructor
	virtual BOOL DestroyWindow();
// 对话框数据
	enum { IDD = IDD_DIALOG_REGION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog() ;

	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose() ;
private:
	CLivePlayView		m_LivePlayView ;	//显示窗口
	void*				m_pPlayerHandle;

	CRect				m_rc;
public:
	afx_msg void OnBnClickedOk();
};
