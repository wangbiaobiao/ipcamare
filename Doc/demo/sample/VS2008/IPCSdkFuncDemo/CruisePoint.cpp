// CruisePoint.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "CruisePoint.h"


// CCruisePoint 对话框

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


// CCruisePoint 消息处理程序

void CCruisePoint::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	
	
	OnCancel();
}

BOOL CCruisePoint::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	// 异常: OCX 属性页应返回 FALSE
}
