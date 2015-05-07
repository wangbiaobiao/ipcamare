// EventSet.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "EventSet.h"
#include "ActionOption.h"

// CEventSet 对话框

IMPLEMENT_DYNAMIC(CEventSet, CDialog)

CEventSet::CEventSet(CWnd* pParent /*=NULL*/)
	: CDialog(CEventSet::IDD, pParent)
	, m_strEventType(_T(""))
	, m_strEventPriority(_T(""))
	, m_strEventRespond(_T(""))
{
	memset(&m_action, 0, sizeof(IPC_ActionOptionInfo)) ;
	memset(m_md, 0, sizeof(IPC_MontionDetectionWindowInfo)*4) ;
}

CEventSet::CEventSet( CWnd* pParent /*= NULL*/, LPVOID handle_ )
	: CDialog(CEventSet::IDD, pParent)
	, _handle(handle_)
	, m_strEventType(_T(""))
	, m_strEventPriority(_T(""))
	, m_strEventRespond(_T(""))
{
	memset(&m_action, 0, sizeof(IPC_ActionOptionInfo)) ;
	memset(m_md, 0, sizeof(IPC_MontionDetectionWindowInfo)*4) ;
}

CEventSet::~CEventSet()
{
}

void CEventSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_EVENT_TYPE, m_strEventType);
	DDX_CBString(pDX, IDC_COMBO_EVENT_PRIORITY, m_strEventPriority);
	DDX_CBString(pDX, IDC_COMBO_RESPOND, m_strEventRespond);
	DDX_Control(pDX, IDC_COMBO_EVENT_TYPE, m_ctlEventType);
	DDX_Control(pDX, IDC_COMBO_EVENT_PRIORITY, m_ctlPriority);
	DDX_Control(pDX, IDC_COMBO_RESPOND, m_ctlRespond);
}

BEGIN_MESSAGE_MAP(CEventSet, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_EVENT_TYPE, &CEventSet::OnCbnSelchangeComboEventType)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CEventSet::OnBnClickedButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_GET, &CEventSet::OnBnClickedButtonGet)
	ON_BN_CLICKED(IDC_BUTTON_ACTION, &CEventSet::OnBnClickedButtonAction)
END_MESSAGE_MAP()


BOOL CEventSet::OnInitDialog()
{
	::ShowWindow(GetDlgItem(IDC_STATIC_MDWND)->m_hWnd, SW_HIDE) ;
	::ShowWindow(GetDlgItem(IDC_BUTTON_MDWINDOW)->m_hWnd, SW_HIDE) ;

	CDialog::OnInitDialog();

	DWORD lCurSel = 0 ;

	lCurSel = m_ctlEventType.AddString("视频异常");
	m_ctlEventType.SetItemData(lCurSel, IPC_EVENT_CAMERATAMPERING);

	lCurSel = m_ctlEventType.AddString("移动侦测");
	m_ctlEventType.SetItemData(lCurSel, IPC_EVENT_MONTIONDETECTION);

	lCurSel = m_ctlEventType.AddString("I/O报警输入");
	m_ctlEventType.SetItemData(lCurSel, IPC_EVENT_INPUTPORT);

	m_ctlEventType.SetCurSel(lCurSel) ;

	lCurSel = 0;

	lCurSel = m_ctlPriority.AddString("LOW");
	m_ctlPriority.SetItemData(lCurSel, 0); 

	lCurSel = m_ctlPriority.AddString("MID");
	m_ctlPriority.SetItemData(lCurSel, 1); 

	lCurSel = m_ctlPriority.AddString("HIGH");
	m_ctlPriority.SetItemData(lCurSel, 2); 

	m_ctlPriority.SetCurSel(lCurSel) ;

	lCurSel = 0 ;

	lCurSel = m_ctlRespond.AddString("有效期响应");
	m_ctlRespond.SetItemData(lCurSel, 0);

	lCurSel = m_ctlRespond.AddString("有变化的时间点响应");
	m_ctlRespond.SetItemData(lCurSel, 1);

	lCurSel = m_ctlRespond.AddString("开始时的时间点响应");
	m_ctlRespond.SetItemData(lCurSel, 2);

	lCurSel = m_ctlRespond.AddString("结束时的时间点响应");
	m_ctlRespond.SetItemData(lCurSel, 3);

	m_ctlRespond.SetCurSel(lCurSel) ;


	return TRUE ;
}
// CEventSet 消息处理程序

void CEventSet::OnCbnSelchangeComboEventType()
{
	// TODO:
	
	if (IPC_EVENT_MONTIONDETECTION==m_ctlEventType.GetItemData(m_ctlEventType.GetCurSel()))
	{
		//::ShowWindow(GetDlgItem(IDC_EDIT_1)->m_hWnd, SW_SHOW) ;
		::ShowWindow(GetDlgItem(IDC_STATIC_MDWND)->m_hWnd, SW_SHOW) ;
		::ShowWindow(GetDlgItem(IDC_BUTTON_MDWINDOW)->m_hWnd, SW_SHOW) ;
	}
	else
	{
		::ShowWindow(GetDlgItem(IDC_STATIC_MDWND)->m_hWnd, SW_HIDE) ;
		::ShowWindow(GetDlgItem(IDC_BUTTON_MDWINDOW)->m_hWnd, SW_HIDE) ;
	}
}


void CEventSet::OnBnClickedButtonSet()
{
	// TODO: 
	UpdateData(TRUE) ;
	m_action.priority = m_ctlPriority.GetItemData(m_ctlPriority.GetCurSel()) ;
	m_action.respond_option = m_ctlRespond.GetItemData(m_ctlRespond.GetCurSel()) ;
	DWORD eventType = m_ctlEventType.GetItemData(m_ctlEventType.GetCurSel()) ;
	switch (eventType)
	{
	case IPC_EVENT_CAMERATAMPERING:
		{
			if (ipcSetCameraUnusualEvent(_handle, 10, m_action) == 0)
			{
				MessageBox(_T("设置成功"), _T("视频异常"), 0) ;
			}
			else
			{
				MessageBox(_T("设置失败"), _T("视频异常"), 0) ;
			}
		}break;
	case IPC_EVENT_MONTIONDETECTION:
		{
			if (ipcSetMontionDetectionEvent(_handle, 4, m_md, m_action) == 0)
			{
				MessageBox(_T("设置成功"), _T("移动侦测"), 0) ;
			}
			else
			{
				MessageBox(_T("设置失败"), _T("移动侦测"), 0) ;
			}
		}break ;
	case IPC_EVENT_INPUTPORT:
		{
			if (ipcSetInputEvent(_handle, 0, m_action) == 0)
			{
				MessageBox(_T("设置成功"), _T("报警输入"), 0) ;
			}
			else
			{
				MessageBox(_T("设置失败"), _T("报警输入"), 0) ;
			}
		}break ;	
	}
}

void CEventSet::OnBnClickedButtonGet()
{
	// TODO: 
	UpdateData(TRUE) ;
	memset(&m_action, 0, sizeof(IPC_ActionOptionInfo)) ;
	DWORD eventType = m_ctlEventType.GetItemData(m_ctlEventType.GetCurSel()) ;
	DWORD dwtmp = 0;
	switch (eventType)
	{
	case IPC_EVENT_CAMERATAMPERING:
		{
			if (ipcGetCameraUnusualEvent(_handle, &dwtmp, &m_action) == 0)
			{
				MessageBox(_T("获取成功"), _T("视频异常"), 0) ;
			}
			else
			{
				MessageBox(_T("获取失败"), _T("视频异常"), 0) ;
			}
		}break;
	case IPC_EVENT_MONTIONDETECTION:
		{
			memset(m_md, 0, sizeof(IPC_MontionDetectionWindowInfo)*4) ;
			if (ipcGetMontionDetectionEvent(_handle, &dwtmp, m_md, &m_action) == 0)
			{
				MessageBox(_T("获取成功"), _T("移动侦测"), 0) ;
			}
			else
			{
				MessageBox(_T("获取失败"), _T("移动侦测"), 0) ;
			}
		}break ;
	case IPC_EVENT_INPUTPORT:
		{
			if (ipcGetInputEvent(_handle, &dwtmp, &m_action) == 0)
			{
				MessageBox(_T("获取成功"), _T("报警输入"), 0) ;
			}
			else
			{
				MessageBox(_T("获取失败"), _T("报警输入"), 0) ;
			}
		}break ;	
	}
}

void CEventSet::OnBnClickedButtonAction()
{
	// TODO:
	CActionOption option(this, this) ;
	option.SetActionOption(&m_action) ;
	if (option.DoModal())
	{
		option.GetActionOption(&m_action) ;
	}
}
