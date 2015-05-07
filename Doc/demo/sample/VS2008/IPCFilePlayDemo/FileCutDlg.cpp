// FileCutDlg.cpp : ʵ���ļ�
//

#include  "stdafx.h"
#include  "FileCutDlg.h"
#include  "resource.h"
#include <shlwapi.h>
// CFileCutDlg �Ի���

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


// CFileCutDlg ��Ϣ�������

void CFileCutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if( !UpdateData())
	{
		return;
	}

	if( m_nStart<0 || m_nEnd<0 || m_nStart>=m_nEnd || m_nEnd > m_max)
	{
		MessageBox(_T("ʱ�����"));
		return ;
	}

	CString sDir ;

	if( m_strPath.ReverseFind(_T('\\')) >=0)
	{
		sDir  = m_strPath.Left( m_strPath.ReverseFind(_T('\\'))  );
	}

	if( ! ::PathFileExists(sDir) )
	{
		MessageBox(_T("Ŀ¼������"));
		return ;
	}

	OnOK();
}

BOOL CFileCutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
    CString  sText;
	sText.Format(_T("���ֵ: %d"),m_max);
	SetDlgItemText(IDC_STATIC_MAX,sText);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
