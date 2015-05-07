#if !defined(AFX_VIDEOWNDDLG_H__9EC2964C_BE60_4052_9A6F_E4538CCBE098__INCLUDED_)
#define AFX_VIDEOWNDDLG_H__9EC2964C_BE60_4052_9A6F_E4538CCBE098__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoWndDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVideoWndDlg dialog

class CVideoWndDlg : public CDialog
{
// Construction
public:
	CVideoWndDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVideoWndDlg)
	enum { IDD = IDD_DIALOG_VIDEOWND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVideoWndDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOWNDDLG_H__9EC2964C_BE60_4052_9A6F_E4538CCBE098__INCLUDED_)
