// ActiveDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "ActiveDlg.h"
#include "ActiveXCtl.h"


// CActiveDlg 对话框

IMPLEMENT_DYNAMIC(CActiveDlg, CDialog)

CActiveDlg::CActiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CActiveDlg::IDD, pParent)
{

}

CActiveDlg::~CActiveDlg()
{
}

void CActiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CActiveDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CActiveDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CActiveDlg 消息处理程序

void CActiveDlg::OnBnClickedButton1()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	if ( m_ActiveXCtl.Create("active", WS_CHILD | WS_VISIBLE, CRect(0, 0, 480, 360), this, 123) )
	{
		m_ActiveXCtl.put_AutoSize(FALSE) ;
	}
}
