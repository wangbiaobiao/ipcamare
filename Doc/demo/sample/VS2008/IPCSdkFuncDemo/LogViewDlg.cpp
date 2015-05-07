// LoginDlg.cpp : implementation file
//

#include "stdafx.h"

#include "IPCSdkFuncDemo.h"

#include "LogViewDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogViewDlg dialog


CLogViewDlg::CLogViewDlg(LPVOID handle,CWnd* pParent /*=NULL*/)
: CDialog(CLogViewDlg::IDD, pParent)
, m_nMaxValue(1)
{
   m_hSdkHandle= handle;
}


void CLogViewDlg::DoDataExchange(CDataExchange* pDX)
{
	;

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogViewDlg)
	DDX_Control(pDX, IDC_LIST_USER_LOG, m_listLogView);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_COMBO_MODE, m_cmb_mode);
	DDX_Text(pDX, IDC_EDIT_MAXVALUE, m_nMaxValue);
	DDV_MinMaxInt(pDX, m_nMaxValue, 1, 30000);
	DDX_Control(pDX, IDC_DATETIME_START, m_start_time);
	DDX_Control(pDX, IDC_DATETIME_END, m_end_time);
}


BEGIN_MESSAGE_MAP(CLogViewDlg, CDialog)
    //{{AFX_MSG_MAP(CLogViewDlg)
    //}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_GETLOGCFG, &CLogViewDlg::OnBnClickedGetlogcfg)
	ON_BN_CLICKED(ID_SETLOGCFG, &CLogViewDlg::OnBnClickedSetlogcfg)
	ON_BN_CLICKED(IDCANCEL, &CLogViewDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE, &CLogViewDlg::OnCbnSelchangeComboMode)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CLogViewDlg::OnBnClickedButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CLogViewDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CLogViewDlg::OnBnClickedButtonDel)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_USER_LOG, &CLogViewDlg::OnNMRClickListUserLog)
	ON_COMMAND(ID_DEL_LOG, &CLogViewDlg::OnDelLog)
	ON_BN_CLICKED(IDC_BTN_GETCOUNT, &CLogViewDlg::OnBnClickedBtnGetcount)
	ON_BN_CLICKED(IDC_BTN_EXPORT, &CLogViewDlg::OnBnClickedBtnExport)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogViewDlg message handlers


BOOL CLogViewDlg::OnInitDialog() 
{
   

    CDialog::OnInitDialog();

	m_cmb_mode.SetTopIndex(0);
	int nIndex= m_cmb_mode.AddString(_T("最多保存条数"));
	m_cmb_mode.SetItemData(nIndex,0);
	nIndex=m_cmb_mode.AddString(_T("最多保存天数"));
	m_cmb_mode.SetItemData(nIndex,1);
	m_cmb_mode.SetCurSel(0);

    m_listLogView.InsertColumn(0,   _T( "序号")); 
    m_listLogView.InsertColumn(1,   _T( "时间")); 
    m_listLogView.InsertColumn(2,   _T( "事件类型")); 
    m_listLogView.InsertColumn(3,   _T( "用户")); 
	m_listLogView.InsertColumn(4,   _T( "摘要")); 
	m_listLogView.InsertColumn(5,   _T( "详情")); 

   m_listLogView.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES|LVS_EX_FULLROWSELECT);
    
    m_listLogView.SetColumnWidth(0,60); 
    
    m_listLogView.SetColumnWidth(1,180); 
    
    m_listLogView.SetColumnWidth(2,120); 
    
    m_listLogView.SetColumnWidth(3,60); 
	m_listLogView.SetColumnWidth(4,300); 
	m_listLogView.SetColumnWidth(5,300); 

	OnBnClickedGetlogcfg();

	UpdateData(FALSE);

	m_start_time.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_end_time.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));

  
    return TRUE;  // return TRUE unless you set the focus to a control
}
 
void CLogViewDlg::InsertRow(IPC_LOG & log)
{
	int   nInsertPos   =   m_listLogView.GetItemCount();                            //获得要插入的行数 
	CString sText;
	m_listLogView.InsertItem(nInsertPos   ,   " "); 

	sText.Format(_T("%d"),log.dwId);
	m_listLogView.SetItemText(nInsertPos,0,sText);//第一列 

	sText.Format(_T("%d-%d-%d %d:%d:%d"),log.stLogTime.dwYear,log.stLogTime.dwMonth,log.stLogTime.dwDay,log.stLogTime.dwHour,log.stLogTime.dwMinute,log.stLogTime.dwSecond);
	m_listLogView.SetItemText(nInsertPos,1,sText); 

	if( log.dwType == 1)
	{
		m_listLogView.SetItemText(nInsertPos,2, _T("访问日志")); 
	}
	else if(log.dwType == 2)
	{
		m_listLogView.SetItemText(nInsertPos,2, _T("报警日志")); 
	}
	else if(log.dwType == 4)
	{
		m_listLogView.SetItemText(nInsertPos,2, _T("系统日志")); 
	}

	m_listLogView.SetItemText(nInsertPos,3,log.sUser); 
	m_listLogView.SetItemText(nInsertPos,4,log.sSummary); 
	m_listLogView.SetItemText(nInsertPos,5,log.sDesp); 
}
 
void CLogViewDlg::OnBnClickedGetlogcfg()
{
	 SetDlgItemText(IDC_STATIC_VALUTYPE,_T("最多天数："));
	if( NULL != m_hSdkHandle)
	{
		IPC_LOG_CONFIG  cfg;
		memset(&cfg,0,sizeof(cfg));
	    if( 0 == ipcGetLogConfig(m_hSdkHandle,&cfg) )
		{
			m_cmb_mode.SetCurSel(cfg.dwType);
			m_nMaxValue = cfg.dwMaxValue;

			if( cfg.dwType  == 0)
			{
				SetDlgItemText(IDC_STATIC_VALUTYPE,_T("最多日志条数："));
			}	 
			UpdateData(FALSE);

			MessageBox(_T("获取成功"));
		}
		else
		{
			MessageBox(_T("获取失败"));
		}
		
	}
}

void CLogViewDlg::OnBnClickedSetlogcfg()
{
	 UpdateData();
	
	 IPC_LOG_CONFIG  cfg;
	 memset(&cfg,0,sizeof(cfg));

	 int nSel = m_cmb_mode.GetCurSel();
	 cfg.dwType = m_cmb_mode.GetItemData(nSel);

	 if( cfg.dwType == 1 && m_nMaxValue > 365)
	 {
		MessageBox(_T("最大天数必须在1~365间"));
		return ;
	 }

	cfg.dwMaxValue = m_nMaxValue;

	if( NULL != m_hSdkHandle)
	{
	    if( 0 == ipcSetLogConfig(m_hSdkHandle,&cfg) )
		{
			 
			MessageBox(_T("设置成功"));
		}
		else
		{
			MessageBox(_T("设置失败"));
		}
	}
}

void CLogViewDlg::OnBnClickedCancel()
{
	 
	OnCancel();
}

void CLogViewDlg::OnCbnSelchangeComboMode()
{
	int nSel = m_cmb_mode.GetCurSel();
	if( nSel  == 0)
	{
		SetDlgItemText(IDC_STATIC_VALUTYPE,_T("最多日志条数："));
	}
	else
	{
		SetDlgItemText(IDC_STATIC_VALUTYPE,_T("最多天数："));
	}
}

BOOL CLogViewDlg::GetUIData(DWORD & dwType,IPC_TIME&  tmStart,BOOL& bUseStart,IPC_TIME&  tmEnd,BOOL& bUseEnd)
{
	CButton*  pBtn = (CButton*) GetDlgItem(IDC_CHECK_ALARM);

	if( pBtn->GetCheck())
	{
		dwType |= 2;
	}

	pBtn = (CButton*) GetDlgItem(IDC_CHECK_VISIT);
	if( pBtn->GetCheck())
	{
		dwType |= 1;
	}

	pBtn = (CButton*) GetDlgItem(IDC_CHECK_SYSTEM);
	if( pBtn->GetCheck())
	{
		dwType |= 4;
	}
	 		
	pBtn = (CButton*) GetDlgItem(IDC_CHECK_ALL);
	if( pBtn->GetCheck())
	{
		dwType=0;
	}

	CTime tmp;
	m_start_time.GetTime(tmp);

	tmStart.dwYear = tmp.GetYear();
	tmStart.dwMonth = tmp.GetMonth();
	tmStart.dwDay = tmp.GetDay();
	tmStart.dwHour = tmp.GetHour();
	tmStart.dwMinute = tmp.GetMinute();
	tmStart.dwSecond = tmp.GetSecond();


	m_end_time.GetTime(tmp);

	tmEnd.dwYear = tmp.GetYear();
	tmEnd.dwMonth = tmp.GetMonth();
	tmEnd.dwDay = tmp.GetDay();
	tmEnd.dwHour = tmp.GetHour();
	tmEnd.dwMinute = tmp.GetMinute();
	tmEnd.dwSecond = tmp.GetSecond();


	pBtn =(CButton*)  GetDlgItem(IDC_CHECK_NOTUSESTART);
	if( pBtn->GetCheck())
	{
		bUseStart=TRUE;
	}
	else
	{
		bUseStart=FALSE;
	}
	pBtn =(CButton*)  GetDlgItem(IDC_CHECK_NOTUSEEND);
	if( pBtn->GetCheck())
	{
		bUseEnd=TRUE;
	}
	else
	{
		bUseEnd=FALSE;
	}

	return TRUE;

}

void CLogViewDlg::OnBnClickedButtonQuery()
{
	if( NULL == m_hSdkHandle)
	{
		return ;
	}
	m_listLogView.DeleteAllItems();

	DWORD dwType=0;
	IPC_TIME tmStart={0};
	IPC_TIME tmEnd={0};

	BOOL bUseStartTm = TRUE;
	BOOL bUseEndTm   = TRUE;

 
	GetUIData(dwType,tmStart,bUseStartTm,tmEnd,bUseEndTm);

	IPC_TIME * pStart = &tmStart;
	IPC_TIME * pEnd   = &tmEnd;

	if(bUseStartTm)
	{
		pStart=NULL;
	}

	if(bUseEndTm)
	{
		pEnd=NULL;
	}
	
	long lFind = ipcFindLog(m_hSdkHandle,dwType,pStart,pEnd);

	if( lFind == ipcFAULT)
	{
		MessageBox(_T("查找日志失败"));
		return ;
	}

	IPC_LOG  log;

	memset(&log,0,sizeof(log));

	while( IPC_LOG_SUCCESS == ipcFindNextLog(lFind,&log) )
	{
		InsertRow(log);

		memset(&log,0,sizeof(log));
	}

	ipcFindLogClose(lFind);
}

void CLogViewDlg::OnBnClickedButtonClear()
{
	if( NULL == m_hSdkHandle)
	{
		return ;
	}

	if( ipcFAULT == ipcClearLog(m_hSdkHandle))
	{
		MessageBox(_T("清空日志失败"));
		return ;
	}
	else
	{
		MessageBox(_T("清空日志成功"));
	}

	 OnBnClickedButtonQuery();
}

void CLogViewDlg::OnBnClickedButtonDel()
{
	 if( NULL == m_hSdkHandle)
	{
		return ;
	}
	

	DWORD dwType=0;
	IPC_TIME tmStart={0};
	IPC_TIME tmEnd={0};

	BOOL bUseStartTm = TRUE;
	BOOL bUseEndTm   = TRUE;

	GetUIData(dwType,tmStart,bUseStartTm,tmEnd,bUseEndTm);

	IPC_TIME * pStart = &tmStart;
	IPC_TIME * pEnd   = &tmEnd;

	if(bUseStartTm)
	{
		pStart=NULL;
	}

	if(bUseEndTm)
	{
		pEnd=NULL;
	}
	
	if( ipcFAULT == ipcDeleteLog(m_hSdkHandle,dwType,pStart,pEnd) )
	{
		MessageBox(_T("按照条件删除日志失败"));
		return ;
	}
	else
	{
		MessageBox(_T("按照条件删除日志成功"));
		m_listLogView.DeleteAllItems();
	}

	OnBnClickedButtonQuery();

}

void CLogViewDlg::OnNMRClickListUserLog(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	 
	CMenu m;
	if(!m.LoadMenu(IDR_MENU_DEL)) MessageBox(_T("err"));
	CMenu * pm=m.GetSubMenu(0); //获取子对话框
	CPoint pot;
	GetCursorPos(&pot);//获取鼠标当前位置
	pm->TrackPopupMenu(TPM_LEFTALIGN,pot.x,pot.y,this);//在鼠标位置弹出菜单

	*pResult = 0;
}

void CLogViewDlg::OnDelLog()
{
   if( NULL == m_hSdkHandle)
	{
		return ;
	}

    INT nIDCount = 0;
	INT nID[1000] = {0};
	int count = m_listLogView.GetItemCount();
    
	for(int i =0 ; i< count;i++)
	{
		if( m_listLogView.GetCheck(i)  &&  nIDCount < sizeof(nID) )
		{
			CString sIp   = m_listLogView.GetItemText(i,0);
            nID[nIDCount] = _ttoi( (LPCTSTR)sIp);
			nIDCount++;
		}
	}

    if( nIDCount > 0)
	{
		if( ipcFAULT == ipcDeleteLogById(m_hSdkHandle,nID,nIDCount) )
		{
			MessageBox(_T("删除日志失败"));
		}
		else
		{
			MessageBox(_T("删除日志成功"));
			OnBnClickedButtonQuery();
		}
	}

}

void CLogViewDlg::OnBnClickedBtnGetcount()
{
	if( NULL == m_hSdkHandle)
	{
		return ;
	}
	
	DWORD dwType=0;
	IPC_TIME tmStart={0};
	IPC_TIME tmEnd={0};

	BOOL bUseStartTm = TRUE;
	BOOL bUseEndTm   = TRUE;

 
	GetUIData(dwType,tmStart,bUseStartTm,tmEnd,bUseEndTm);

	IPC_TIME * pStart = &tmStart;
	IPC_TIME * pEnd   = &tmEnd;

	if(bUseStartTm)
	{
		pStart=NULL;
	}

	if(bUseEndTm)
	{
		pEnd=NULL;
	}
	INT		retCount=0;

	if( ipcFAULT == ipcQueryLogCount(m_hSdkHandle,dwType,pStart,pEnd,&retCount) )
	{
		MessageBox(_T("获取日志条数失败"));
		return ;
	}
	else
	{
		CString sText;
		sText.Format(_T("日志条数 %d"),retCount);
		MessageBox(sText);
	}
}

void CLogViewDlg::OnBnClickedBtnExport()
{
	if( NULL == m_hSdkHandle)
	{
		return ;
	}
    WCHAR * pFile = L"d:\\tt.text";
	if(  ipcFAULT == ipcExportLog(m_hSdkHandle,pFile) )
	{
		MessageBox(_T("导出日志到文件失败！"));
	}
	else
	{
		MessageBox(_T("导出日志到文件成功！"));
	}
}
