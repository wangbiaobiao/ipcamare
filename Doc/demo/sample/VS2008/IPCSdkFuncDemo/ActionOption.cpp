// ActionOption.cpp : 实现文件
#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "ActionOption.h"


// CActionOption 对话框

IMPLEMENT_DYNAMIC(CActionOption, CDialog)

CActionOption::CActionOption(CWnd* pParent /*=NULL*/)
	: CDialog(CActionOption::IDD, pParent)
	, m_static_1(_T(""))
	, m_static_2(_T(""))
	, m_static_3(_T(""))
	, m_value_1(0)
	, m_value_2(0)
	, m_value_3(0)
{

}

CActionOption::CActionOption( CWnd* pParent, CEventSet* event_ )
	: CDialog(CActionOption::IDD, pParent)
	, m_static_1(_T(""))
	, m_static_2(_T(""))
	, m_static_3(_T(""))
	, m_value_1(0)
	, m_value_2(0)
	, m_value_3(0)
{
	m_Event = event_ ;
	memset(&m_ation, 0, sizeof(IPC_ActionOptionInfo)) ;
}

CActionOption::~CActionOption()
{
}

void CActionOption::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_ACTIONTYPE, m_ctlActionType);
	DDX_Control(pDX, IDC_COMBO_ACTION_ENABLE, m_ctlEnable);
	DDX_Text(pDX, IDC_STATIC_ACTION_1, m_static_1);
	DDX_Text(pDX, IDC_STATIC_ACTION_2, m_static_2);
	DDX_Text(pDX, IDC_STATIC_ACTION_3, m_static_3);
	DDX_Text(pDX, IDC_EDIT_ACTION_1, m_value_1);
	DDX_Text(pDX, IDC_EDIT_ACTION_2, m_value_2);
	DDX_Text(pDX, IDC_EDIT_ACTION_3, m_value_3);
}

BOOL CActionOption::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD lCurSel = 0 ;

	lCurSel = m_ctlActionType.AddString("视频录像");
	m_ctlActionType.SetItemData(lCurSel, IPC_EVENT_ACTIONTYPE_RECORD);

	lCurSel = m_ctlActionType.AddString("数字云台");
	m_ctlActionType.SetItemData(lCurSel, IPC_EVENT_ACTIONTYPE_DPTZ);

	lCurSel = m_ctlActionType.AddString("机械云台");
	m_ctlActionType.SetItemData(lCurSel, IPC_EVENT_ACTIONTYPE_PTZ);

	lCurSel = m_ctlActionType.AddString("报警输出");
	m_ctlActionType.SetItemData(lCurSel, IPC_EVENT_ACTIONTYPE_PORTOUTPUT);

	m_ctlActionType.SetCurSel(lCurSel) ;

	lCurSel = 0 ;
	lCurSel = m_ctlEnable.AddString("有效") ;
	m_ctlEnable.SetItemData(lCurSel, 1) ;

	lCurSel = m_ctlEnable.AddString("无效") ;
	m_ctlEnable.SetItemData(lCurSel, 0) ;

	m_ctlEnable.SetCurSel(lCurSel) ;
	
	_HideAllBtn() ;

	return TRUE ;
}


BEGIN_MESSAGE_MAP(CActionOption, CDialog)
	ON_BN_CLICKED(IDOK, &CActionOption::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_ACTIONTYPE, &CActionOption::OnCbnSelchangeComboActiontype)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CActionOption::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CActionOption 消息处理程序

void CActionOption::OnBnClickedOk()
{
	// TODO:
	if (m_Event!= NULL)
	{
		//m_Event->SetActionOption(&m_ation) ;
	}
	OnOK();
}

void CActionOption::OnCbnSelchangeComboActiontype()
{
	// TODO: 
	_HideAllBtn() ;
	DWORD dwType = m_ctlActionType.GetItemData(m_ctlActionType.GetCurSel()) ;
	switch (dwType)
	{
	case IPC_EVENT_ACTIONTYPE_RECORD:
		{
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_2)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_3)->m_hWnd, SW_SHOW) ;

			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_2)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_3)->m_hWnd, SW_SHOW) ;

			m_static_1 = _T("持续时间:") ;
			m_static_2 = _T("码流ID:") ;
			m_static_3 = _T("文件保存类型:") ;

			m_value_1 = m_ation.record.delay;
			m_value_2 = m_ation.record.streamID;
			m_value_3 = m_ation.record.locationID ;
		}break;
	case IPC_EVENT_ACTIONTYPE_PORTOUTPUT:
		{
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_1)->m_hWnd, SW_SHOW) ;
			m_static_1 = _T("高低电平:") ;
			m_value_1 = m_ation.output.level ;
		}break ;
	case IPC_EVENT_ACTIONTYPE_DPTZ:
		{
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_2)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_3)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_2)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_3)->m_hWnd, SW_SHOW) ;
			
			m_static_1 = _T("停留时间:") ;
			m_static_2 = _T("码流ID:") ;
			m_static_3 = _T("预置位ID:") ;

			m_value_1 = m_ation.dptz.delay;
			m_value_2 = m_ation.dptz.streamID;
			m_value_3 = m_ation.dptz.preset ;

		}break ;
	case IPC_EVENT_ACTIONTYPE_PTZ:
		{
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_2)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_1)->m_hWnd, SW_SHOW) ;
			::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_2)->m_hWnd, SW_SHOW) ;

			m_static_1 = _T("停留时间:") ;
			m_static_2 = _T("预置位ID:") ;
			m_value_1 = m_ation.ptz.delay;
			m_value_2 = m_ation.ptz.preset;
		}break ;
	}
	UpdateData(FALSE) ;
}

void CActionOption::OnBnClickedButtonSave()
{
	// TODO: 
	UpdateData(TRUE) ;
	DWORD dwType = m_ctlActionType.GetItemData(m_ctlActionType.GetCurSel()) ;
	switch (dwType)
	{
	case IPC_EVENT_ACTIONTYPE_RECORD:
		{
			m_ation.record.enable_flag = m_ctlEnable.GetItemData(m_ctlEnable.GetCurSel()) ;
			m_ation.record.delay = m_value_1 ;
			m_ation.record.streamID = m_value_2 ;
			m_ation.record.locationID = m_value_3 ;
		}break;
	case IPC_EVENT_ACTIONTYPE_PORTOUTPUT:
		{
			m_ation.output.enable_flag = m_ctlEnable.GetItemData(m_ctlEnable.GetCurSel()) ;
			m_ation.output.level = m_value_1 ;
		}break ;
	case IPC_EVENT_ACTIONTYPE_DPTZ:
		{
			m_ation.dptz.enable_flag = m_ctlEnable.GetItemData(m_ctlEnable.GetCurSel()) ;
			m_ation.dptz.delay = m_value_1 ;
			m_ation.dptz.streamID = m_value_2 ;
			m_ation.dptz.preset = m_value_3 ;
		}break ;
	case IPC_EVENT_ACTIONTYPE_PTZ:
		{
			m_ation.ptz.enable_flag = m_ctlEnable.GetItemData(m_ctlEnable.GetCurSel()) ;
			m_ation.ptz.delay = m_value_1 ;
			m_ation.ptz.preset = m_value_2 ;
		}break ;
	}
	
}

void CActionOption::_HideAllBtn()
{
	::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_1)->m_hWnd, SW_HIDE) ;
	::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_2)->m_hWnd, SW_HIDE) ;
	::ShowWindow(GetDlgItem(IDC_STATIC_ACTION_3)->m_hWnd, SW_HIDE) ;
	::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_1)->m_hWnd, SW_HIDE) ;
	::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_2)->m_hWnd, SW_HIDE) ;
	::ShowWindow(GetDlgItem(IDC_EDIT_ACTION_3)->m_hWnd, SW_HIDE) ;
}

void CActionOption::GetActionOption( IPC_ActionOptionInfo* option )
{
	if (NULL != option)
	{
		memcpy(option, &m_ation, sizeof(IPC_ActionOptionInfo)) ;
	}
}

void CActionOption::SetActionOption( IPC_ActionOptionInfo* option )
{
	if (NULL != option)
	{
		memcpy(&m_ation, option, sizeof(IPC_ActionOptionInfo)) ;
	}
}

