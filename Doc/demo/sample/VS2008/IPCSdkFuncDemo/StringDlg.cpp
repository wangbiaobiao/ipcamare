// StringDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "StringDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStringDlg dialog


CStringDlg::CStringDlg(LOGFONT& ft,COLORREF& crText,CWnd* pParent /*=NULL*/)
	: CDialog(CStringDlg::IDD, pParent),m_pft(ft)
{
	//{{AFX_DATA_INIT(CStringDlg)

	m_strCaption = _T("智能高清网络摄像机");
	m_bEnable = TRUE;
	m_lX = 32;
	m_lY = 32;
	//}}AFX_DATA_INIT

	m_crFt = &crText;
}


void CStringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStringDlg)
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_strCaption);
	DDV_MaxChars(pDX, m_strCaption, 1024);
	DDX_Check(pDX, IDC_CHECK_ENABLE, m_bEnable);
	DDX_Text(pDX, IDC_EDIT_X, m_lX);
	DDX_Text(pDX, IDC_EDIT_Y, m_lY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStringDlg, CDialog)
	//{{AFX_MSG_MAP(CStringDlg)
	ON_BN_CLICKED(IDC_BUTTON_FONT, OnButtonFont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStringDlg message handlers

void CStringDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	UpdateData(TRUE);
	if ( m_strCaption.IsEmpty() )
	{
		return ;
	}

	CDialog::OnOK();
}

void CStringDlg::OnButtonFont() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE) ;
	UpdateData(FALSE) ;
	CFontDialog		dlgFont(&m_pft);

	dlgFont.m_cf.rgbColors = *m_crFt;
	
	if ( dlgFont.DoModal() != IDOK)
	{
		return;
	}
	UpdateData(FALSE) ;	
	UpdateData(TRUE) ;
	dlgFont.GetCurrentFont(&m_pft);
	*m_crFt = dlgFont.GetColor();	
//	m_dwFtSize = dlgFont.GetSize();
}

BOOL CStringDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
