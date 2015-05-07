// BufferTimeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BufferTimeDlg.h"


// CBufferTimeDlg �Ի���

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


// CBufferTimeDlg ��Ϣ�������

void CBufferTimeDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if( m_nTime< 0 || m_nTime> 1000)
	{
		MessageBox(_T("����ʱ��������0---1000֮��"));
		return ;
	}
	OnOK();
}
