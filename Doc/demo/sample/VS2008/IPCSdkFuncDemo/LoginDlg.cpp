// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CLoginDlg::IDD, pParent)
{
     ;
    //{{AFX_DATA_INIT(CLoginDlg)
    m_strIP = _T("10.0.0.2");

    m_lPort = 30000;

    m_strPsw = _T("");

    m_strUser = _T("admin");

    m_lStreamID = 0 ;
    //}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
     ;

    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CLoginDlg)
    DDX_Control(pDX, IDC_COMBO_RESOLUTION, m_ctrlResolution);
    
    DDX_Text(pDX, IDC_EDIT_IP, m_strIP);
    
    DDV_MaxChars(pDX, m_strIP, 20);
    
    DDX_Text(pDX, IDC_EDIT_PORT, m_lPort);
    
    DDV_MinMaxLong(pDX, m_lPort, 1, 65535);
    
    DDX_Text(pDX, IDC_EDIT_PSW, m_strPsw);
    
    DDV_MaxChars(pDX, m_strPsw, 32);
    
    DDX_Text(pDX, IDC_EDIT_USER, m_strUser);
    
    DDV_MaxChars(pDX, m_strUser, 32);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
    //{{AFX_MSG_MAP(CLoginDlg)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

BOOL CLoginDlg::GetLoginInfo(TEST_PLAYER_LOGININFO *pInfo)
{
     ;

    if ( NULL == pInfo )
    {
        return FALSE;
    }
    
    strcpy_s(pInfo->szHostIP,sizeof(pInfo->szHostIP),(m_strIP.GetBuffer(0)));
    
    strcpy_s(pInfo->szUser,sizeof(pInfo->szUser),(m_strUser.GetBuffer(0)));
    
    strcpy_s(pInfo->szPsw,sizeof(pInfo->szPsw),(m_strPsw.GetBuffer(0)));    
    //strcpy(pInfo->szHostIP,m_strIP);
    //strcpy(pInfo->szUser,m_strUser);
    //strcpy(pInfo->szPsw,m_strPsw);

    pInfo->lHostPort    = m_lPort;

    pInfo->lStreamID    = m_lStreamID ;

    return TRUE;
}

BOOL CLoginDlg::OnInitDialog() 
{
     ;

    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here
    
    long    lCurSel = 0;
    
    lCurSel = m_ctrlResolution.AddString("stream 1");
    
    m_ctrlResolution.SetItemData(lCurSel,0);

    lCurSel = m_ctrlResolution.AddString("stream 2");
    
    m_ctrlResolution.SetItemData(lCurSel,1);

    lCurSel = m_ctrlResolution.AddString("stream 3");
    
    m_ctrlResolution.SetItemData(lCurSel,2);

    lCurSel = m_ctrlResolution.AddString("stream 4");
    
    m_ctrlResolution.SetItemData(lCurSel,3);

    m_ctrlResolution.SetCurSel(0);

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnOK() 
{
     ;

    UpdateData(TRUE);

    m_lStreamID    = m_ctrlResolution.GetItemData(m_ctrlResolution.GetCurSel());

    if ( m_strIP.IsEmpty() )
    {
        AfxMessageBox("The IP address is empty !");

        return ;
    }

    CDialog::OnOK();
}

bool CLoginDlg::GetLoginIp( CString& strIp )
{
	strIp = m_strIP;

	return true;
}
