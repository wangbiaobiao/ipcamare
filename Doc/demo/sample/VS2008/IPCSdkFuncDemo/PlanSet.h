#pragma once
#include "afxwin.h"

#include "IPCamera.h"
#include "afxdtctl.h"
// CPlanSet �Ի���

class CPlanSet : public CDialog
{
	DECLARE_DYNAMIC(CPlanSet)

public:
	CPlanSet(CWnd* pParent = NULL);   // ��׼���캯��
	CPlanSet(CWnd* pParent, LPVOID handle_);
	virtual ~CPlanSet();

// �Ի�������
	enum { IDD = IDD_DIALOG_PLAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog() ;
	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_ctlPlanType;
	CComboBox m_ctlTimeIndex;
	CTime m_startTime;
	CTime m_endTime;
	CDateTimeCtrl m_ctlStartTime;
	CDateTimeCtrl m_ctlEndTime;
	CComboBox m_ctlPlanDate;
	DWORD	m_sTime[7][IPC_MAX_TIME_SEC] ;
	DWORD	m_eTime[7][IPC_MAX_TIME_SEC] ;

	DWORD		_planType ;

	ipcHandle	_handle ;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeComboPlanType();
	afx_msg void OnBnClickedButtonPlanSet();
	afx_msg void OnBnClickedButtonPlanGet();
};
