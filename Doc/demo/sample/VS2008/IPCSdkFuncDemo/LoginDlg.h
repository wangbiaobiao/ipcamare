#if !defined(AFX_LOGINDLG_H__E512DF3C_9F04_448E_A07A_445B8409D80D__INCLUDED_)
#define AFX_LOGINDLG_H__E512DF3C_9F04_448E_A07A_445B8409D80D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog
#include "resource.h"
class CLoginDlg : public CDialog
{
// Construction
public:


    BOOL GetLoginInfo(TEST_PLAYER_LOGININFO *pInfo);
	bool GetLoginIp(CString& strIp);
    CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CLoginDlg)
    enum { IDD = IDD_DIALOG_LOGIN };
    CComboBox    m_ctrlResolution;
    CString    m_strIP;
    long    m_lPort;
    CString    m_strPsw;
    CString    m_strUser;
    long    m_lStreamID ;
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CLoginDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CLoginDlg)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__E512DF3C_9F04_448E_A07A_445B8409D80D__INCLUDED_)
