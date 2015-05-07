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
	int nIndex= m_cmb_mode.AddString(_T("��ౣ������"));
	m_cmb_mode.SetItemData(nIndex,0);
	nIndex=m_cmb_mode.AddString(_T("��ౣ������"));
	m_cmb_mode.SetItemData(nIndex,1);
	m_cmb_mode.SetCurSel(0);

    m_listLogView.InsertColumn(0,   _T( "���")); 
    m_listLogView.InsertColumn(1,   _T( "ʱ��")); 
    m_listLogView.InsertColumn(2,   _T( "�¼�����")); 
    m_listLogView.InsertColumn(3,   _T( "�û�")); 
	m_listLogView.InsertColumn(4,   _T( "ժҪ")); 
	m_listLogView.InsertColumn(5,   _T( "����")); 

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
	int   nInsertPos   =   m_listLogView.GetItemCount();                            //���Ҫ��������� 
	CString sText;
	m_listLogView.InsertItem(nInsertPos   ,   " "); 

	sText.Format(_T("%d"),log.dwId);
	m_listLogView.SetItemText(nInsertPos,0,sText);//��һ�� 

	sText.Format(_T("%d-%d-%d %d:%d:%d"),log.stLogTime.dwYear,log.stLogTime.dwMonth,log.stLogTime.dwDay,log.stLogTime.dwHour,log.stLogTime.dwMinute,log.stLogTime.dwSecond);
	m_listLogView.SetItemText(nInsertPos,1,sText); 

	if( log.dwType == 1)
	{
		m_listLogView.SetItemText(nInsertPos,2, _T("������־")); 
	}
	else if(log.dwType == 2)
	{
		m_listLogView.SetItemText(nInsertPos,2, _T("������־")); 
	}
	else if(log.dwType == 4)
	{
		m_listLogView.SetItemText(nInsertPos,2, _T("ϵͳ��־")); 
	}

	m_listLogView.SetItemText(nInsertPos,3,log.sUser); 
	m_listLogView.SetItemText(nInsertPos,4,log.sSummary); 
	m_listLogView.SetItemText(nInsertPos,5,log.sDesp); 
}
 
void CLogViewDlg::OnBnClickedGetlogcfg()
{
	 SetDlgItemText(IDC_STATIC_VALUTYPE,_T("���������"));
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
				SetDlgItemText(IDC_STATIC_VALUTYPE,_T("�����־������"));
			}	 
			UpdateData(FALSE);

			MessageBox(_T("��ȡ�ɹ�"));
		}
		else
		{
			MessageBox(_T("��ȡʧ��"));
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
		MessageBox(_T("�������������1~365��"));
		return ;
	 }

	cfg.dwMaxValue = m_nMaxValue;

	if( NULL != m_hSdkHandle)
	{
	    if( 0 == ipcSetLogConfig(m_hSdkHandle,&cfg) )
		{
			 
			MessageBox(_T("���óɹ�"));
		}
		else
		{
			MessageBox(_T("����ʧ��"));
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
		SetDlgItemText(IDC_STATIC_VALUTYPE,_T("�����־������"));
	}
	else
	{
		SetDlgItemText(IDC_STATIC_VALUTYPE,_T("���������"));
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
		MessageBox(_T("������־ʧ��"));
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
		MessageBox(_T("�����־ʧ��"));
		return ;
	}
	else
	{
		MessageBox(_T("�����־�ɹ�"));
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
		MessageBox(_T("��������ɾ����־ʧ��"));
		return ;
	}
	else
	{
		MessageBox(_T("��������ɾ����־�ɹ�"));
		m_listLogView.DeleteAllItems();
	}

	OnBnClickedButtonQuery();

}

void CLogViewDlg::OnNMRClickListUserLog(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	 
	CMenu m;
	if(!m.LoadMenu(IDR_MENU_DEL)) MessageBox(_T("err"));
	CMenu * pm=m.GetSubMenu(0); //��ȡ�ӶԻ���
	CPoint pot;
	GetCursorPos(&pot);//��ȡ��굱ǰλ��
	pm->TrackPopupMenu(TPM_LEFTALIGN,pot.x,pot.y,this);//�����λ�õ����˵�

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
			MessageBox(_T("ɾ����־ʧ��"));
		}
		else
		{
			MessageBox(_T("ɾ����־�ɹ�"));
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
		MessageBox(_T("��ȡ��־����ʧ��"));
		return ;
	}
	else
	{
		CString sText;
		sText.Format(_T("��־���� %d"),retCount);
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
		MessageBox(_T("������־���ļ�ʧ�ܣ�"));
	}
	else
	{
		MessageBox(_T("������־���ļ��ɹ���"));
	}
}
