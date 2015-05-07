// VideoWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VideoWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoWndDlg dialog


CVideoWndDlg::CVideoWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVideoWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CVideoWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideoWndDlg, CDialog)
	//{{AFX_MSG_MAP(CVideoWndDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoWndDlg message handlers
