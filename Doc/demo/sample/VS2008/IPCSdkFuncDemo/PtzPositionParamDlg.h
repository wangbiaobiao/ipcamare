#pragma once
#include "resource.h"
#include "IPCSdkFuncDemoDlg.h"
// CPtzPositionParamDlg dialog

class CPtzPositionParamDlg : public CDialog
{
	DECLARE_DYNAMIC(CPtzPositionParamDlg)

public:
	CPtzPositionParamDlg(CIPCPlayerDemoDlg* Owner,CWnd* pParent = NULL);   // standard constructor
	virtual ~CPtzPositionParamDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_PTZ_POSITION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGet();
private:
	CIPCPlayerDemoDlg* m_Owner;
	CString m_x;
	CString m_y;
	CString m_z;
	CString m_xSpeed;
	CString m_ySpeed;
};
