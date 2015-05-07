// IPCFilePlayDemoDlg.cpp : implementation file
//
#include "stdafx.h"
#include "IPCFilePlayDemo.h"
#include "IPCFilePlayDemoDlg.h"
#include "FileCutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void*	g_playHandle = NULL ;   // ���������

static CString g_sState[]={
								"STATE_NONE",	    
								"STATE_STOP",	    
								"STATE_PAUSE",	    
								"STATE_PLAY",	    
								"STATE_FAST",	    
								"STATE_SLOW",	    
								"STATE_BACK_NORMAL",	
								"STATE_NORMAL",	    
								"STATE_BACK_FAST",	
								"STATE_BACK_SLOW",	
								"STATE_LOAD",	    
								"STATE_OPEN",	    
								"STATE_CLOSE",	    
								"STATE_FILEEND",	    
								"STATE_ERROR"
							};

//����״̬�ص�
void WINAPI g_myMsgProc(DWORD dwCode, void *context)
{
	 int nIndex = dwCode-IPC_PLAY_STATE_NONE;
	 if(nIndex>=0 && nIndex< sizeof(g_sState))
	 {
		 CString sTrace;
		 sTrace.Format(_T("PlayStateCallback %s  \n"),g_sState[nIndex] );
		 OutputDebugString(sTrace);
	 }
}

//��Ƶ��Ƶ��������ص�
VOID CALLBACK g_myAvframeExProc(LPBYTE data,DWORD size,LPIPC_PLAYER_AV_FRAME pInfo,LPVOID pContext )
{
	switch( pInfo->nType )
	{
	case 1:
		{
			CString sTrace;
			sTrace.Format(_T("AvFrameCallBackEx  data=%d size=%d type=%d width=%d height=%d \n"), (int)data, size, pInfo->nType, pInfo->nWidth,pInfo->nHeight);
			OutputDebugString(sTrace);
		}break;
	case 2:
		{
			CString sTrace;
			sTrace.Format(_T("AvFrameCallBackEx  data=%d size=%d type=%d channel=%d bitpersample=%d samplepersec=%d\n"), (int)data, size, pInfo->nType, pInfo->nWidth,pInfo->nHeight,pInfo->nFrameRate);
			OutputDebugString(sTrace);

		}break;
	}
}

//��Ƶ��Ƶ����ص�
void WINAPI g_myAvframeProc(LPBYTE data,DWORD size,DWORD type,DWORD width,DWORD height,LPVOID pContext )
{
	LPBYTE d1 = data ;
	DWORD  s1 = size ;
	DWORD  w1 = width ;
	DWORD  h1 = height ;

	//CString sTrace;
	//sTrace.Format(_T("AvFrameCallBack  data=%d size=%d type=%d width=%d height=%d \n"), (int)data, size, type, width, height );
	//OutputDebugString(sTrace);
}

//���ص�
void WINAPI g_myMouseProc(int x, int y, int event, void *context )
{
	POINT pt ;
	pt.x = x ;
	pt.y = y ;
	DWORD e = event ;
}



/////////////////////////////////////////////////////////////////////////////
// CIPCFilePlayDemoDlg dialog

CIPCFilePlayDemoDlg::CIPCFilePlayDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPCFilePlayDemoDlg::IDD, pParent)
	, m_iFmPos(0)
	, m_left(0)
	, m_top(0)
	, m_right(0)
	, m_bottom(0)
	, m_backward(0)
	, m_forward(0)
{
	//{{AFX_DATA_INIT(CIPCFilePlayDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bOpenFile = false ;
	
	m_strFilePathName = _T("") ;
	
	m_nTotalTime = 0 ;

	m_bSelfSetPos = FALSE;
	m_bSliderCapture=FALSE;

	m_pRegionDlg = NULL ;

}

void CIPCFilePlayDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIPCFilePlayDemoDlg)
	//DDX_Control(pDX, IDC_STATIC_TIME, m_staTime) ;
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSliderProgress);
	DDX_Control(pDX, IDC_COMBO1, m_Speed);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_SLIDER_VOLUME, m_volume);
	DDX_Text(pDX, IDC_EDIT_FPOS, m_iFmPos);
	DDV_MinMaxInt(pDX, m_iFmPos, 0, 999999);
	DDX_Text(pDX, IDC_EDIT_LEFT, m_left);
	DDX_Text(pDX, IDC_EDIT_TOP, m_top);
	DDX_Text(pDX, IDC_EDIT_LEFT2, m_right);
	DDX_Text(pDX, IDC_EDIT_TOP2, m_bottom);
	DDX_Text(pDX, IDC_EDIT_BACKWARD, m_backward);
	DDX_Text(pDX, IDC_EDIT_FOEWARD, m_forward);
}

BEGIN_MESSAGE_MAP(CIPCFilePlayDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CIPCFilePlayDemoDlg)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, OnButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO1, &CIPCFilePlayDemoDlg::OnCbnSelchangeCombo1)
	ON_COMMAND(ID_FILE_OPEN, &CIPCFilePlayDemoDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_CLOSE, &CIPCFilePlayDemoDlg::OnFileClose)
	ON_WM_TIMER()
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CIPCFilePlayDemoDlg::OnTRBNThumbPosChangingSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CIPCFilePlayDemoDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_VOLUME, &CIPCFilePlayDemoDlg::OnNMReleasedcaptureSliderVolume)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_VOLUME, &CIPCFilePlayDemoDlg::OnTRBNThumbPosChangingSliderVolume)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_VOLUME, &CIPCFilePlayDemoDlg::OnNMCustomdrawSliderVolume)
	ON_BN_CLICKED(IDC_BTN_CAPTURE, &CIPCFilePlayDemoDlg::OnBnClickedBtnCapture)
	ON_BN_CLICKED(IDC_BTN_SETPOS, &CIPCFilePlayDemoDlg::OnBnClickedBtnSetpos)
	ON_BN_CLICKED(IDC_BTN_REPLAY, &CIPCFilePlayDemoDlg::OnBnClickedBtnReplay)
	ON_BN_CLICKED(IDC_BTN_GETRECT, &CIPCFilePlayDemoDlg::OnBnClickedBtnGetrect)
	ON_BN_CLICKED(IDC_BTN_SETRECT, &CIPCFilePlayDemoDlg::OnBnClickedBtnSetrect)
	ON_BN_CLICKED(IDC_BTN_FORWARD, &CIPCFilePlayDemoDlg::OnBnClickedBtnForward)
	ON_BN_CLICKED(IDC_BTN_BACKWARD, &CIPCFilePlayDemoDlg::OnBnClickedBtnBackward)
	ON_WM_MOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BTN_CAPTURETOBUFF, &CIPCFilePlayDemoDlg::OnBnClickedBtnCapturetobuff)
	ON_BN_CLICKED(IDC_BTN_CUT, &CIPCFilePlayDemoDlg::OnBnClickedBtnCut)
	ON_BN_CLICKED(IDC_CHECK_MUTE, &CIPCFilePlayDemoDlg::OnBnClickedCheckMute)
	ON_BN_CLICKED(IDC_BUTTON_RANGZOOM, &CIPCFilePlayDemoDlg::OnBnClickedButtonRangzoom)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPCFilePlayDemoDlg message handlers

BOOL CIPCFilePlayDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//������ʾ����----------
	RECT rc ;
	
	::GetClientRect(m_hWnd, &rc) ;
	
	DWORD dwWidth = rc.right - rc.left ;
	DWORD dwHight = rc.bottom - rc.top ;

	rc.bottom = rc.top + dwHight - 120 ;
	
	m_PlayViewWnd.Create(rc, this) ;
	
	m_PlayViewWnd.ShowWindow(SW_SHOW) ;
	//----------
	
	//��ʼ��������----------
	m_ctrlSliderProgress.SetRange(0, 0) ;
	
	m_ctrlSliderProgress.SetPos(0) ;
	//----------

	//��ʼ�������б�----------
	m_sPeedList.push_back(-8) ; // ��ֵ��Ϊ���˲���
	
	m_sPeedList.push_back(-4) ;
	
	m_sPeedList.push_back(-2) ;
	
	m_sPeedList.push_back(-1) ;
	
	m_sPeedList.push_back(-0.5) ;
	
	m_sPeedList.push_back(-0.25) ;
	
	m_sPeedList.push_back(-0.125) ;
	
	m_sPeedList.push_back(0.125) ;
	
	m_sPeedList.push_back(0.25) ;
	
	m_sPeedList.push_back(0.5) ;
	
	m_sPeedList.push_back(1) ;
	
	m_sPeedList.push_back(2) ;
	
	m_sPeedList.push_back(4) ;
	
	m_sPeedList.push_back(8) ;
	
	for ( std::list<float>::iterator it = m_sPeedList.begin() ;it!=m_sPeedList.end();it++)
	{
		TCHAR szTemp[32]={0} ;
		_stprintf(szTemp,TEXT("%f"),*it) ;
		int iSel = m_Speed.AddString(szTemp) ;
		m_Speed.SetItemData(iSel,(unsigned long)&(*it)) ;
		
	}
	
	m_Speed.SetCurSel(6) ;
	//----------

	EnableAllBtn(false) ;
	
	InitAvFilePlay() ;
	

	m_volume.SetRange(0,100);
	m_volume.SetPos(50);

	UpdateData(FALSE) ;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIPCFilePlayDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIPCFilePlayDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIPCFilePlayDemoDlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	

	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle Ϊ null  !\t"));

		return ;
	}

	//�����ļ�
	if (0 != ipcAvFileDec_Play(g_playHandle) )
	{
		AfxMessageBox(_T("ipcAvFileDec_Play  ʧ�� !\t"));

		return ;
	}
	//----------

	//���ò�������
	float rate = 0 ;
	
	INT iSel = m_Speed.GetCurSel() ;
	
	rate = *(float*)(m_Speed.GetItemData(iSel)) ;

	if ( 0 != ipcAvFileDec_Fast(g_playHandle, rate))
	{
		AfxMessageBox(_T("ipcAvFileDec_Fast  ʧ�� !\t"));
	}
	//----------

	EnablePlayBtn(true) ;
	
	m_PlayViewWnd.StratPlay(g_playHandle) ;
	
	LONG vol=50;
	if( 0 != ipcAvFileDec_GetVolume(g_playHandle,&vol) )
	{
		AfxMessageBox(_T("ipcAvFileDec_GetVolume  ʧ�� !\t"));
	}

	m_volume.SetPos(vol);

	UpdateData(FALSE) ;

	SetTimer(1,500,NULL);
}

void CIPCFilePlayDemoDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	
	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle  Ϊnull !\t"));

		return ;
	}
	
	//ֹͣ����
	if ( 0 != ipcAvFileDec_Stop(g_playHandle) )
	{
		AfxMessageBox(_T("ipcAvFileDec_Stop  ʧ�� !\t"));

		return ;
	}

	KillTimer(1);
	EnablePlayBtn(false) ;
	
	m_PlayViewWnd.StopPlay() ;
	m_ctrlSliderProgress.SetPos(0) ;
}

void CIPCFilePlayDemoDlg::OnButtonPause() 
{
	// TODO: Add your control notification handler code here

	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle  Ϊnull !\t"));

		return ;
	}
	
	//��ͣ����
	if ( 0 != ipcAvFileDec_Pause(g_playHandle))
	{
		AfxMessageBox(_T("ipcAvFileDec_Pause  ʧ�� !\t"));
	}
	
	::EnableWindow(GetDlgItem(IDC_BUTTON_PLAY)->m_hWnd, TRUE) ;
	
	
	UpdateData(TRUE) ;
}

void CIPCFilePlayDemoDlg::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	if (NULL == g_playHandle)
	{
		return ;
	}
	
	//�ɴӲ���״̬�л�����֡����״̬
	if (0 != ipcAvFileDec_StepFrame(g_playHandle, FALSE))
	{
		AfxMessageBox(_T("ipcAvFileDec_StepFrame  ʧ�� !\t"));
	}

 
	::EnableWindow(GetDlgItem(IDC_BUTTON_PLAY)->m_hWnd, TRUE) ;
	
	UpdateData(TRUE) ;
}

void CIPCFilePlayDemoDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	
	if (NULL == g_playHandle)
	{
		return ;
	}
	//�ɴӲ���״̬�л�����֡����״̬
	if (0 != ipcAvFileDec_StepFrame(g_playHandle, TRUE))
	{
		AfxMessageBox(_T("ipcAvFileDec_StepFrame  ʧ�� !\t"));
	}

	
	::EnableWindow(GetDlgItem(IDC_BUTTON_PLAY)->m_hWnd, TRUE) ;
	
	UpdateData(TRUE) ;
}



void CIPCFilePlayDemoDlg::EnableAllBtn( bool bEnable )
{
	::EnableWindow(GetDlgItem(IDC_BUTTON_PLAY)->m_hWnd, bEnable) ;
	
	::EnableWindow(GetDlgItem(IDC_BUTTON_STOP)->m_hWnd, bEnable) ;
	
	::EnableWindow(GetDlgItem(IDC_BUTTON_PAUSE)->m_hWnd, bEnable) ;
	
	::EnableWindow(GetDlgItem(IDC_BUTTON_PREV)->m_hWnd, bEnable) ;
	
	::EnableWindow(GetDlgItem(IDC_BUTTON_NEXT)->m_hWnd, bEnable) ;
	
	::EnableWindow(GetDlgItem(IDC_SLIDER1)->m_hWnd, bEnable) ;
	
}

void CIPCFilePlayDemoDlg::EnablePlayBtn( bool bEnable )
{
	::EnableWindow(GetDlgItem(IDC_BUTTON_PLAY)->m_hWnd, !bEnable) ;

	::EnableWindow(GetDlgItem(IDC_BUTTON_STOP)->m_hWnd, bEnable) ;

	::EnableWindow(GetDlgItem(IDC_BUTTON_PAUSE)->m_hWnd, bEnable) ;

	::EnableWindow(GetDlgItem(IDC_BUTTON_PREV)->m_hWnd, bEnable) ;

	::EnableWindow(GetDlgItem(IDC_BUTTON_NEXT)->m_hWnd, bEnable) ;

	::EnableWindow(GetDlgItem(IDC_SLIDER1)->m_hWnd, bEnable) ;
}

//������������Դ
void CIPCFilePlayDemoDlg::InitAvFilePlay()
{

    if (NULL != g_playHandle)
	{
        //����ʼ��������
		if (0 != ipcAvFileDec_Done(g_playHandle))
		{
			AfxMessageBox(_T("ipcAvFileDec_Done ʧ�� !\t"));

			return ;
		}

		g_playHandle = NULL ;
	}
	
	if ( !::IsWindow(m_PlayViewWnd.m_hWnd) )
	{
		AfxMessageBox(_T("m_PlayViewWnd δ���� ʧ�� !\t"));

		return ;
	}

    ipcPlayerInitialize() ;

	//��ʼ��������
	g_playHandle = ipcAvFileDec_Init(m_PlayViewWnd.m_hWnd, 0, 0, 0) ;

	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("ipcAvFileDec_Init ʧ�� !\t"));

		return ;
	}

	if (0 != ipcAvFileDec_RegisterAVMsgCallBack(g_playHandle,g_myMsgProc,this) )
	{
		AfxMessageBox(_T("ipcAvFileDec_RegisterAVMsgCallBack ʧ�� !\t"));
	}

	if (0 != ipcAvFileDec_RegisterAVFrameCallBack(g_playHandle,g_myAvframeProc,this))
	{
		AfxMessageBox(_T("ipcAvFileDec_RegisterAVFrameCallBack ʧ�� !\t"));
	}

	if (0 != ipcAvFileDec_RegisterAVFrameCallBackEx(g_playHandle,g_myAvframeExProc,this))
	{
		AfxMessageBox(_T("ipcAvFileDec_RegisterAVFrameCallBack ʧ�� !\t"));
	}
	//
}

//�ͷŲ�������Դ
void CIPCFilePlayDemoDlg::UnInitAvFilePlay()
{
	KillTimer(1);

	if (NULL != g_playHandle)
	{
		if (0 != ipcAvFileDec_RegisterAVMsgCallBack(g_playHandle,NULL,NULL) )
		{
			AfxMessageBox(_T("ipcAvFileDec_RegisterAVMsgCallBack ʧ�� !\t"));
		}

		if (0 != ipcAvFileDec_RegisterAVFrameCallBack(g_playHandle,NULL,NULL))
		{
			AfxMessageBox(_T("ipcAvFileDec_RegisterAVFrameCallBack ʧ�� !\t"));
		}

		if (0 != ipcAvFileDec_Done(g_playHandle))
		{
			AfxMessageBox(_T("ipcAvFileDec_Done ʧ�� !\t"));
		}

        ipcPlayerUnInitialize() ;

		g_playHandle = NULL ;
	}
}

bool CIPCFilePlayDemoDlg::OpenFile()
{

	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle Ϊ null  !\t"));

		return false;
	}
	//
    TCHAR BASED_CODE szTempFilter[] = _T("IPC Files (*.ipc)|*.IPC|All Files (*.*)|*.*||") ;

    CFileDialog dlg(TRUE,   NULL,NULL,   OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ENABLESIZING, szTempFilter ,AfxGetMainWnd());

	INT dlgRet = (INT)dlg.DoModal() ;

	if( dlgRet != 1 )
	{
		return false;
	}
	
	//���ԭ�������ļ�δ�رգ����ȹر�
	if (m_bOpenFile)
	{
		//�ر��ļ�
		CloseFile() ;

		EnableAllBtn(false) ;

		m_bOpenFile = false ;
	}

	////
	m_strFilePathName = dlg.GetPathName() ;

	//������Ҫ���ŵ��ļ�
	if (0 != ipcAvFileDec_SetFileName(g_playHandle, m_strFilePathName, 0, 0))
	{
		AfxMessageBox(_T("ipcAvFileDec_SetFileName ʧ�� !\t"));

		return false ;
	}

	//��ȡ�����ļ�����ʱ��
	m_nTotalTime = (int)ipcAvFileDec_GetTotalTime(g_playHandle) ;

	m_ctrlSliderProgress.SetRange(0, m_nTotalTime) ;

	m_ctrlSliderProgress.SetPos(0) ;

	OnButtonPlay() ;

	return true ;
}

void CIPCFilePlayDemoDlg::CloseFile()
{
	if (NULL == g_playHandle)
	{
		return ;
	}

	//�رղ����ļ�
	if (0 != ipcAvFileDec_CloseFile(g_playHandle))
	{
		AfxMessageBox(_T("ipcAvFileDec_CloseFile ʧ�� !\t"));
	}

	m_strFilePathName = _T("") ;

	m_nTotalTime = 0 ;

	m_ctrlSliderProgress.SetRange(0, 0) ;

	m_ctrlSliderProgress.SetPos(0) ;


	m_PlayViewWnd.StopPlay() ;

}
 

void CIPCFilePlayDemoDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle Ϊ null  !\t"));
		return ;
	}

	UpdateData(TRUE) ;

	//���ò�������
	float rate = 0 ;

	INT iSel = m_Speed.GetCurSel() ;

	rate = *(float*)(m_Speed.GetItemData(iSel)) ;

	if (0 != ipcAvFileDec_Fast(g_playHandle, rate))
	{
		AfxMessageBox(_T("ipcAvFileDec_Fast ʧ�� !\t"));
	}

}


void CIPCFilePlayDemoDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	if ( NULL != m_pRegionDlg )
	{

		if (::IsWindow(m_pRegionDlg->m_hWnd))
		{
			m_pRegionDlg->DestroyWindow();

			delete m_pRegionDlg;
		}

		m_pRegionDlg = NULL;
	}

	m_sPeedList.clear() ;

	CloseFile() ;

	UnInitAvFilePlay() ;
}
 
void CIPCFilePlayDemoDlg::OnFileOpen()
{
	// TODO: �ڴ���������������
	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle Ϊ null  !\t"));
		return ;
	}

	if ( OpenFile() ) // �򿪲����ļ��ɹ�
	{
		EnableAllBtn(true) ;
		m_bOpenFile = true ;


		

		INT nW =  ipcAvFileDec_GetImageWidth(g_playHandle);
		INT nH =  ipcAvFileDec_GetImageHeight(g_playHandle);

		CString sTmp;
		sTmp.Format(_T("%d"),nW);

		 CWnd*  pWnd = GetDlgItem(IDC_STATIC_W);
		 pWnd->SetWindowText(sTmp);


		 sTmp.Format(_T("%d"),nH);
		 pWnd = GetDlgItem(IDC_STATIC_H);
		 pWnd->SetWindowText(sTmp);

		 LONG lTotal = ipcAvFileDec_GetTotalFrames(g_playHandle);

		 sTmp.Format(_T("%d"),lTotal);

		 pWnd = GetDlgItem(IDC_STATIC_TOTALFRAME);
		 pWnd->SetWindowText(sTmp);

		 float fTotal =  ipcAvFileDec_GetTotalTime(g_playHandle);
		 CString sText;
		 sText.Format(_T("%d"),(int)(fTotal+0.5));

		  pWnd = GetDlgItem(IDC_STATIC_TOTALTIME);
		 pWnd->SetWindowText(sText);
		 
	}

	m_ctrlSliderProgress.SetPos(0) ;

	UpdateData(FALSE) ;
}

void CIPCFilePlayDemoDlg::OnFileClose()
{
	// TODO: �ڴ���������������
	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle Ϊ null  !\t"));
		return ;
	}

	if (m_bOpenFile)
	{
		//�ر��ļ�
		CloseFile() ;
		EnableAllBtn(false) ;
		m_bOpenFile = false ;
	}
}



void CIPCFilePlayDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (NULL == g_playHandle  || m_bSliderCapture)
	{
		return  ;
	}
	
	//��ȡ��ǰ�ļ��Ĳ���ʱ���
	int nCurTime = (int)ipcAvFileDec_GetCurrentTime(g_playHandle) ;

	if (nCurTime == m_nTotalTime)
	{
		//OnButtonStop() ;
		nCurTime = 0 ;
	}

	m_bSelfSetPos=TRUE;
	m_ctrlSliderProgress.SetPos(nCurTime) ;
	m_bSelfSetPos=FALSE;


	LONG lFPos = ipcAvFileDec_GetCurrentPosition(g_playHandle);
	CString sText;
	sText.Format(_T("%d"),lFPos);

	CWnd* pWnd = GetDlgItem(IDC_STATIC_FPOS);
	pWnd->SetWindowText(sText);

	INT nState = ipcAvFileDec_GetCurrentState(g_playHandle);
     int nIndex = nState-IPC_FILEPLAY_BASE-1;
	 if(nIndex>=0 && nIndex< sizeof(g_sState))
	 {
		pWnd = GetDlgItem(IDC_STATIC_STATE);
		pWnd->SetWindowText(g_sState[nIndex]);
	 }

	//UpdateData(FALSE) ;

	CDialog::OnTimer(nIDEvent);
}

void CIPCFilePlayDemoDlg::OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	
	m_bSliderCapture=TRUE;

	*pResult = 0;
}

void CIPCFilePlayDemoDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

 
	if( m_bSelfSetPos) return ;

	if (NULL == g_playHandle)
	{
		AfxMessageBox(_T("g_playHandle Ϊ null  !\t"));
		
		return ;
	}

	int pos_current = m_ctrlSliderProgress.GetPos() ;
	
	static int pos = pos_current ;
	
	if( pos == pos_current)
	{
		 
		OutputDebugStringA("\n CIPCFilePlayDemoDlg::OnReleasedcaptureSlider1 return not seek");
		return ;
	}

	
	
	pos = pos_current ;
	
	char sDebug[256]={0};
	sprintf(sDebug," CIPCFilePlayDemoDlg::OnReleasedcaptureSlider1  pos=%d \n",pos);
	if (0 != ipcAvFileDec_SetCurrentTime(g_playHandle, (float)pos))
	{
		AfxMessageBox(_T("ipcAvFileDec_SetCurrentTime  ʧ�� !\t"));
	}

	
	*pResult = 0;
}

void CIPCFilePlayDemoDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	m_bSliderCapture=FALSE;

	*pResult = 0;
}
void CIPCFilePlayDemoDlg::OnNMReleasedcaptureSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

void CIPCFilePlayDemoDlg::OnTRBNThumbPosChangingSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	 
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	 

	*pResult = 0;
}

void CIPCFilePlayDemoDlg::OnNMCustomdrawSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	 
	if (NULL == g_playHandle)
	{
		return ;
	}

    if( !m_bOpenFile )
    {
        return ;
    }

	int nPos = m_volume.GetPos();


	INT ret = ipcAvFileDec_SetVolume(g_playHandle,nPos);

	CString sText;
	sText.Format(_T("\n pos= %d ret=%d "),nPos,ret);

	OutputDebugString(sText);
	if( ret != 0)
	{
		AfxMessageBox(_T("ipcAvFileDec_SetVolume  ʧ�� !\t"));
	}

	*pResult = 0;
}

void CIPCFilePlayDemoDlg::OnBnClickedBtnCapture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if (NULL == g_playHandle)
	{
		return ;
	}
	
	COleDateTime		dtCur = COleDateTime::GetCurrentTime();

	CString		strName = _T("");
	strName.Format(_T("D:\\ץͼ%s.bmp"), dtCur.Format(_T("%Y-%m-%d %H-%M-%S") ) );

	ipcAvFileDec_CapturePicture(g_playHandle,strName,_T("bmp"));

}

void CIPCFilePlayDemoDlg::OnBnClickedBtnSetpos()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}
	

	UpdateData();

	ipcAvFileDec_SetCurrentPosition(g_playHandle, m_iFmPos);

}

void CIPCFilePlayDemoDlg::OnBnClickedBtnReplay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}

	ipcAvFileDec_RePlay(g_playHandle);

	

	EnablePlayBtn(true) ;
	
	m_PlayViewWnd.StratPlay(g_playHandle) ;
}

void CIPCFilePlayDemoDlg::OnBnClickedBtnGetrect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}


    RECT rt;
	memset(&rt,0,sizeof(rt));
    ipcAvFileDec_GetDisplayPos(g_playHandle,&rt);

	m_left	=	rt.left;
	m_top	=	rt.top;
	m_right	=	rt.right;
	m_bottom=	rt.bottom;

    UpdateData(FALSE);


}

void CIPCFilePlayDemoDlg::OnBnClickedBtnSetrect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}
	UpdateData();

	RECT rt;
	
	rt.left=m_left;
	rt.top=m_top;
	rt.right=m_right;
	rt.bottom=m_bottom;

    ipcAvFileDec_SetDisplayPos(g_playHandle,&rt);

}

void CIPCFilePlayDemoDlg::OnBnClickedBtnForward()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}

	UpdateData();

	ipcAvFileDec_Forward(g_playHandle,m_forward);	
}

void CIPCFilePlayDemoDlg::OnBnClickedBtnBackward()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}

	UpdateData();

	ipcAvFileDec_Backward(g_playHandle,m_backward);

}

void CIPCFilePlayDemoDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	// TODO: �ڴ˴������Ϣ����������
	UpdateWindow();
}

void CIPCFilePlayDemoDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialog::OnLButtonDblClk(nFlags, point);
}

void CIPCFilePlayDemoDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialog::OnLButtonDown(nFlags, point);
}

void CIPCFilePlayDemoDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialog::OnLButtonUp(nFlags, point);
}

void CIPCFilePlayDemoDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialog::OnMouseMove(nFlags, point);
}

void CIPCFilePlayDemoDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	 

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CIPCFilePlayDemoDlg::OnBnClickedBtnCapturetobuff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}

	UpdateData();

	LONG lLen=0;
	if( ipcAvFileDec_CapturePictToBuff(g_playHandle,NULL,&lLen) != 0)
	{
		MessageBox(_T("��ȡ�ڴ泤��ʧ��"));
		return ;
	}
    BYTE * pBuf = new BYTE[lLen];
	memset(pBuf,0,lLen);
	if( ipcAvFileDec_CapturePictToBuff(g_playHandle,pBuf,&lLen) != 0)
	{
		MessageBox(_T("ץͼ���ڴ�ʧ��"));
		delete [] pBuf;
		return ;
	}

	delete [] pBuf;
	pBuf=NULL;


}

void CIPCFilePlayDemoDlg::OnBnClickedBtnCut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == g_playHandle)
	{
		return ;
	}

	UpdateData();

	CFileCutDlg  dlg;
	dlg.m_max = (int)ipcAvFileDec_GetTotalTime(g_playHandle) ;

	if( dlg.DoModal() != IDOK )
	{
		return ;
	}
	CString sPath = dlg.m_strPath;
	int nStart = dlg.m_nStart;
	int nEnd   = dlg.m_nEnd;

	if( 0 != ipcAvFileDec_Cut(g_playHandle,(LPTSTR)(LPCTSTR)sPath,nStart,nEnd) )
	{
		MessageBox(_T("����ʧ��"));
	}
	else
	{
		MessageBox(_T("���гɹ�"));
	}

}

void CIPCFilePlayDemoDlg::OnBnClickedCheckMute()
{
	static BOOL bMute = TRUE ;

	INT iRet = ipcAvFileDec_SetMute(g_playHandle,bMute) ;

	if( iRet !=0 )
	{
		//TRACE("ipcAvFileDec_SetMute failed.") ;
		return ;
	}
	bMute=!bMute ;

}

void CIPCFilePlayDemoDlg::OnBnClickedButtonRangzoom()
{
	// TODO:
	UpdateData(TRUE);

	RECT	rc;
	rc.left		= 0;
	rc.top		= 0;
	rc.right	= rc.left	+ 480;
	rc.bottom	= rc.top	+ 360;

	if ( NULL != m_pRegionDlg )
	{
		if (::IsWindow(m_pRegionDlg->m_hWnd))
		{
			m_pRegionDlg->DestroyWindow();

			delete m_pRegionDlg;
		}
		m_pRegionDlg = NULL;
	}

	if (NULL != g_playHandle)
	{
		m_pRegionDlg	= new CRegionDlg2(g_playHandle,rc);
		m_pRegionDlg->Create(IDD_DIALOG_REGION,this);

		m_pRegionDlg->CenterWindow(this);
		m_pRegionDlg->ShowWindow(TRUE);
	}
}
