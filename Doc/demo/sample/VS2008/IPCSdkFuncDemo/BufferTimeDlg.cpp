// BufferTimeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BufferTimeDlg.h"


// CBufferTimeDlg 对话框

IMPLEMENT_DYNAMIC(CBufferTimeDlg, CDialog)

CBufferTimeDlg::CBufferTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBufferTimeDlg::IDD, pParent)
	, m_nTime(0)
{

}

CBufferTimeDlg::~CBufferTimeDlg()
{
}

void CBufferTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TIME, m_nTime);
}


BEGIN_MESSAGE_MAP(CBufferTimeDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CBufferTimeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CBufferTimeDlg 消息处理程序

void CBufferTimeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if( m_nTime< 0 || m_nTime> 1000)
	{
		MessageBox(_T("缓存时间必须介于0---1000之间"));
		return ;
	}
	OnOK();
}
