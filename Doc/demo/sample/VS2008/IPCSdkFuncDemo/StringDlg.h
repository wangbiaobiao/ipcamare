#if !defined(AFX_STRINGDLG_H__0BB1236F_C74C_419E_B667_F6B71F6C689E__INCLUDED_)
#define AFX_STRINGDLG_H__0BB1236F_C74C_419E_B667_F6B71F6C689E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StringDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStringDlg dialog

class CStringDlg : public CDialog
{
public:
	LOGFONT&	m_pft;
	COLORREF*	m_crFt;
// Construction
public:
	CStringDlg(LOGFONT& ft,COLORREF& crText,CWnd* pParent = NULL);   // standard constructor
	~CStringDlg()
	{
		//m_pft = NULL;
	}
// Dialog Data
	//{{AFX_DATA(CStringDlg)
	enum { IDD = IDD_DIALOG_STRING };
	CString	m_strCaption;
	BOOL	m_bEnable;
	long	m_lX;
	long	m_lY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStringDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStringDlg)
	virtual void OnOK();
	afx_msg void OnButtonFont();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRINGDLG_H__0BB1236F_C74C_419E_B667_F6B71F6C689E__INCLUDED_)
