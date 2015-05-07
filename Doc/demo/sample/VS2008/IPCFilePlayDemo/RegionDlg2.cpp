// RegionDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "RegionDlg2.h"


// CRegionDlg2 对话框

IMPLEMENT_DYNAMIC(CRegionDlg2, CDialog)

CRegionDlg2::CRegionDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CRegionDlg2::IDD, pParent)
{

}

CRegionDlg2::CRegionDlg2( void *pStreamPlayer,CRect rc,CWnd* pParent /*= NULL*/ )
	: CDialog(CRegionDlg2::IDD, pParent)
{
	m_pPlayerHandle = pStreamPlayer;
	m_rc			= rc;
}

CRegionDlg2::~CRegionDlg2()
{
}

void CRegionDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegionDlg2, CDialog)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &CRegionDlg2::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CRegionDlg2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	RECT rcPlay;
	GetClientRect(&rcPlay);

	m_LivePlayView.Create(rcPlay, this) ;
	m_LivePlayView.ShowWindow(SW_SHOW) ;

	m_LivePlayView.StratPlay(m_pPlayerHandle);

	RECT	rc = m_rc;

	if (NULL != m_pPlayerHandle)
	{
		if ( !ipcAvFileDec_SetDisplayRegion(m_pPlayerHandle, 1, rc, m_LivePlayView.m_hWnd, TRUE) )
		{

		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CRegionDlg2::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	if (m_pPlayerHandle != NULL)
	{
		ipcAvFileDec_RefreshDisplayRegion(m_pPlayerHandle, 1) ;
	}
}

void CRegionDlg2::OnSize( UINT nType, int cx, int cy )
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	if ( !::IsWindow(m_hWnd) )
	{
		return;
	}

	ipcAvFileDec_RefreshDisplayRegion(m_pPlayerHandle, 1) ;
}

BOOL CRegionDlg2::DestroyWindow()
{
	RECT	rc;
	rc.left		= 0;
	rc.top		= 0;
	rc.right	= 0;
	rc.bottom	= 0;

	ipcAvFileDec_SetDisplayRegion(m_pPlayerHandle, 1, rc, m_LivePlayView.m_hWnd, FALSE) ;

	m_LivePlayView.StopPlay();

	return CDialog::DestroyWindow();
}

void CRegionDlg2::OnClose()
{
	RECT	rc;
	rc.left		= 0;
	rc.top		= 0;
	rc.right	= 0;
	rc.bottom	= 0;

	ipcAvFileDec_SetDisplayRegion(m_pPlayerHandle, 1, rc, m_LivePlayView.m_hWnd, FALSE) ;

	m_LivePlayView.StopPlay();

	CDialog::OnClose() ;
}


// CRegionDlg2 消息处理程序

void CRegionDlg2::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
