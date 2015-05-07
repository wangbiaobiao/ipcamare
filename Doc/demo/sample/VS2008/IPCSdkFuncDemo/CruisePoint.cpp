// CruisePoint.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "CruisePoint.h"


// CCruisePoint �Ի���

IMPLEMENT_DYNAMIC(CCruisePoint, CDialog)

CCruisePoint::CCruisePoint(CWnd* pParent /*=NULL*/)
	: CDialog(CCruisePoint::IDD, pParent)
	, m_staytime(0)
	, m_speed(0)
{

}

CCruisePoint::~CCruisePoint()
{
}

void CCruisePoint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PRESET, m_presets);
	DDX_Text(pDX, IDC_EDIT_STAYTIME, m_staytime);
	DDV_MinMaxInt(pDX, m_staytime, 0, 10000);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDV_MinMaxInt(pDX, m_speed, 0, 255);
}


BEGIN_MESSAGE_MAP(CCruisePoint, CDialog)
	ON_BN_CLICKED(IDOK, &CCruisePoint::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCruisePoint::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCruisePoint ��Ϣ�������

void CCruisePoint::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	int nSel = m_presets.GetCurSel();
	if( nSel >= 0)
	{
		m_curId = m_presets.GetItemData(nSel);
	}

	OnOK();
}

void CCruisePoint::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	
	OnCancel();
}

BOOL CCruisePoint::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_presets.SetTopIndex(0);
	int count =  m_tmpPresets.size();

	for(int i=0; i<count;++i)
	{
		CString sText;
		sText.Format(_T("%d"),m_tmpPresets[i]);
		INT item = m_presets.AddString(sText);
		m_presets.SetItemData(item,m_tmpPresets[i]);
	}
	m_presets.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
