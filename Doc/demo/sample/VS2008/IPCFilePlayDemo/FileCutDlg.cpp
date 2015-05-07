// FileCutDlg.cpp : 实现文件
//

#include  "stdafx.h"
#include  "FileCutDlg.h"
#include  "resource.h"
#include <shlwapi.h>
// CFileCutDlg 对话框

IMPLEMENT_DYNAMIC(CFileCutDlg, CDialog)

CFileCutDlg::CFileCutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileCutDlg::IDD, pParent)
	, m_nStart(0)
	, m_nEnd(5)
	, m_strPath(_T("d:\\cut.ipc"))
{
	m_max=1;
}

CFileCutDlg::~CFileCutDlg()
{
}

void CFileCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_START, m_nStart);
	DDV_MinMaxInt(pDX, m_nStart, 0, 2000000);
	DDX_Text(pDX, IDC_EDIT_END, m_nEnd);
	DDV_MinMaxInt(pDX, m_nEnd, 0, 2000000);
	DDX_Text(pDX, IDC_EDIT3, m_strPath);
}


BEGIN_MESSAGE_MAP(CFileCutDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CFileCutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFileCutDlg 消息处理程序

void CFileCutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if( !UpdateData())
	{
		return;
	}

	if( m_nStart<0 || m_nEnd<0 || m_nStart>=m_nEnd || m_nEnd > m_max)
	{
		MessageBox(_T("时间错误"));
		return ;
	}

	CString sDir ;

	if( m_strPath.ReverseFind(_T('\\')) >=0)
	{
		sDir  = m_strPath.Left( m_strPath.ReverseFind(_T('\\'))  );
	}

	if( ! ::PathFileExists(sDir) )
	{
		MessageBox(_T("目录不存在"));
		return ;
	}

	OnOK();
}

BOOL CFileCutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
    CString  sText;
	sText.Format(_T("最大值: %d"),m_max);
	SetDlgItemText(IDC_STATIC_MAX,sText);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
