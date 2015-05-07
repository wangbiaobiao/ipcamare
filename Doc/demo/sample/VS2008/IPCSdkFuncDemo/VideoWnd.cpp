// VideoWnd.cpp : implementation file
//

#include "stdafx.h"

#include "shlwapi.h"

#include "resource.h"

#include "LoginDlg.h"

#include "VideoWnd.h"

#include "IPCSdkFuncDemoDlg.h"

#include "IPCDefine.h"

#include "IPCamera.h"

#include "UpdateFilePath.h"

#include "CruiseDlg.h"
#include "BufferTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define TIMER_ZOOM 1

int  myWideCharToMultiByte(LPCWSTR  lpWideCharStr,int cchWideChar,LPSTR  lpMultiByteStr,int  cbMultiByte)
{
	return WideCharToMultiByte(CP_THREAD_ACP, 0,lpWideCharStr,cchWideChar,lpMultiByteStr,cbMultiByte,NULL,NULL);
}

int  myMultiByteToWideChar(LPCSTR   lpMultiByteStr, int  cbMultiByte, LPWSTR  lpWideCharStr, int cchWideChar)
{
	return MultiByteToWideChar(CP_THREAD_ACP, 0,lpMultiByteStr,cbMultiByte,lpWideCharStr,cchWideChar);
}

/////////////////////////////////////////////////////////////////////////////
// CVideoWnd
void WINAPI my_LiveFrame_CallBack( playHandle hPlayer_, const IPC_FrameInfo * frameType_,const CHAR* frameData_,INT dataLen_, LPVOID context_ ) ;

void WINAPI playerdemo_Message_CallBack(ipcHandle handle,INT cmd_,LPVOID data_,LPVOID pFrame) ;

VOID WINAPI MyAudioCallbackEx( LPVOID handle, const IPC_FrameInfoEx* info, LPVOID context)  ;

void WINAPI ipcYUVCallBack( playHandle hPlayer , const IPC_FrameInfo * lpFrameInfo,const CHAR* lpData,INT iDataLen, LPVOID lpContext );

VOID WINAPI myHeartBeatCallback(ipcHandle handle,BOOL isOnline, LPVOID context) ;

CVideoWnd::CVideoWnd()
{
     ;

    m_hSdkHandle = 0 ;

    m_hSdkPlayer = 0 ;

    m_lWndState = 0;

    m_rc.SetRect(0,0,0,0);

    m_pParent = NULL;

    m_lIndex  = 0;

    m_bSnapShot = FALSE;

    m_pFrame = 0 ;

    m_dptz_zoom = 0;

    m_stream_Id = 0;

    m_IsPTZMode = TRUE ;
    
    m_posdInfo = (LPIPC_OSDPARAM)new BYTE[MAX_OSD_BUFFER_SIZEE] ;

	memset(m_posdInfo, 0, sizeof(MAX_OSD_BUFFER_SIZEE));

    

	m_bShowLogoPicture = false;
	m_bShowLogoText = false;
	memset(&m_ftLogoText, 0, sizeof(LOGFONT));
	m_ftLogoText.lfWidth			= 32;//24;
	m_ftLogoText.lfHeight			= m_ftLogoText.lfWidth;
	m_ftLogoText.lfEscapement		= 0;
	m_ftLogoText.lfOrientation		= 0;
	m_ftLogoText.lfWeight			= FW_NORMAL;
	m_ftLogoText.lfItalic			= FALSE;
	m_ftLogoText.lfUnderline		= FALSE;
	m_ftLogoText.lfStrikeOut		= 0;
	m_ftLogoText.lfCharSet			= ANSI_CHARSET;
	m_ftLogoText.lfOutPrecision		= OUT_DEFAULT_PRECIS;
	m_ftLogoText.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	m_ftLogoText.lfQuality			= DEFAULT_QUALITY;
	m_ftLogoText.lfPitchAndFamily	= VARIABLE_PITCH;	
	strcpy(m_ftLogoText.lfFaceName,"Fixedsys");

	//必须初始化OSD,如不需使用则要清空
	m_posdInfo->pic_crMask = 0 ;
	m_posdInfo->pic_data = (BYTE*)(((BYTE*)(m_posdInfo))+sizeof(IPC_OSDPARAM) );
	m_posdInfo->pic_data_len = 0 ;
	m_posdInfo->pic_lHeight = 0 ;
	m_posdInfo->pic_lWidth = 0 ;
	m_posdInfo->pic_x = 0 ;
	m_posdInfo->pic_y = 0 ;
	m_posdInfo->picture = false ;

	m_posdInfo->text = false ;
	memset(m_posdInfo->text_context,0,sizeof(m_posdInfo->text_context)) ;
	m_posdInfo->text_crColor = 0 ;
	m_posdInfo->text_font = m_ftLogoText ;
	m_posdInfo->text_lHeight = 0 ;
	m_posdInfo->text_lWidth = 0 ;
	m_posdInfo->text_x = 0 ;
	m_posdInfo->text_y = 0 ;
	//

	m_pEventCallBack = NULL ;

	m_pSystemSettingCallBack = NULL ;

	m_pCameraConfigCallBack = NULL ;

    memset(&m_LoginInfo,0,sizeof(m_LoginInfo) ) ;

}

CVideoWnd::~CVideoWnd()
{    
     ;

    Close();

    if (m_posdInfo)
    {
        delete[] m_posdInfo ;
        m_posdInfo = NULL ;
    }
}

BEGIN_MESSAGE_MAP(CVideoWnd, CWnd)
    //{{AFX_MSG_MAP(CVideoWnd)
    ON_WM_PAINT()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_DESTROY()
    ON_WM_RBUTTONDOWN()
    ON_WM_LBUTTONUP()
    //}}AFX_MSG_MAP
	ON_WM_MOVE()
	ON_WM_SIZE()
	ON_WM_MOVING()
	ON_WM_MOUSEWHEEL()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


void CVideoWnd::SetMainFrame(CIPCPlayerDemoDlg* pFrame)
{
     ;

    m_pFrame = pFrame ;
}
/////////////////////////////////////////////////////////////////////////////
void CVideoWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
     ;

    m_pFrame->SetCurrentWnd(m_hWnd) ;

    return ;
}

/////////////////////////////////////////////////////////////////////////////
// CVideoWnd message handlers

BOOL CVideoWnd::Create(long lIndex, CRect rc, CWnd *pParentWnd)
{
     ;

    m_rc      = rc;

    m_pParent = pParentWnd;

    m_lIndex  = lIndex;

    DWORD    dwStyle = WS_CHILD /*| WS_CLIPCHILDREN*/ | WS_VISIBLE ;//| WS_BORDER;

    return CWnd::Create(NULL,NULL,dwStyle,rc,pParentWnd,0XFFFFFFFF,NULL);

    //!roy!todo:enum the process searching module-name and version number to log.
}

void CVideoWnd::OnPaint() 
{
     ;

    CPaintDC dc(this); // device context for painting

    // TODO: Add your message handler code here

    CRect    rc;

    GetClientRect(&rc);

    CBrush        brush;

    brush.CreateSolidBrush(RGB(32,32,32));

    CDC        *pDC = &dc;

    CBrush* oriBrush = pDC->SelectObject(&brush);

    CPen        pen;

    pen.CreatePen(PS_SOLID,1,RGB(128,128,128));

    CPen* oriPen = pDC->SelectObject(&pen);

    pDC->Rectangle(rc);

    if ( NULL == m_hSdkPlayer )
    {                
        CString        strText = _T("");

        strText.Format("%02d",m_lIndex + 1);

        pDC->SetBkColor(RGB(32,32,32));

        pDC->SetTextColor(RGB(128,128,128));

        pDC->TextOut(rc.Width() / 2 - 40,rc.Height() / 2 - 20,strText); 

    }
    else
    {     
        Refresh() ;
        //IPC_Player_Refresh(m_hPlayer,rc.left + 2,rc.top + 2,rc.Width() - 4,rc.Height() - 4);        
    }
    pDC->SelectObject(oriPen) ;

    pDC->SelectObject(oriBrush) ;

    // Do not call CWnd::OnPaint() for painting messages
}

BOOL CVideoWnd::OnCommand(WPARAM wParam, LPARAM lParam) 
{
    switch ( wParam )
    {
    case IDR_MENU_RUN:
        {

            Close();

			if (m_lWndState == 1)
			{
				PostMessage(WM_LBUTTONDBLCLK, 0 ,0) ;
			}
			
            CLoginDlg    dlgLogin(this);

            if ( IDOK != dlgLogin.DoModal() )
            {
                Invalidate(TRUE) ;
                break;
            }
			
			dlgLogin.GetLoginIp(m_strIP) ;

            memset(&m_LoginInfo,0,sizeof(m_LoginInfo));

            dlgLogin.GetLoginInfo(&m_LoginInfo);

            if ( !Open(m_LoginInfo) )
            {
                TCHAR szTemp[1024]={0} ;

                _stprintf( szTemp,TEXT("failed. [open - %s:%d,%d tream,user=%s,passwprd = %s]"),m_LoginInfo.szHostIP,m_LoginInfo.lHostPort,m_LoginInfo.lStreamID,m_LoginInfo.szUser,TEXT("XXXX") ) ;

                UserOperationRecording( TEXT("IPCamera"),TEXT("BROWSER"),szTemp ) ;

                AfxMessageBox("Open the IPCamera failed !\t");
                break;
            }else{
                TCHAR szTemp[1024]={0} ;

                _stprintf( szTemp,TEXT("successed. [open - %s:%d,%d tream,user=%s,passwprd = %s]"),m_LoginInfo.szHostIP,m_LoginInfo.lHostPort,m_LoginInfo.lStreamID,m_LoginInfo.szUser,TEXT("XXXX")) ;

                UserOperationRecording( TEXT("IPCamera"),TEXT("BROWSER"),szTemp ) ;
				SetSliderCtrl();
                break;
            }            
        }
        break;    
    case IDR_UPDATE_DEVICE:
        {
			if (NULL == m_hSdkHandle || !m_pFrame->m_bStartUpdateServer)
			{
				break;
			}

			CUpdateFilePath  dlgFilePath(this);
			dlgFilePath.SetUpdateIp(m_strIP);

			if ( IDOK != dlgFilePath.DoModal() )
			{
				break ;
			}

			CString strFilePath;
			dlgFilePath.GetUpdateFilePath(strFilePath);
			ipcUpgrade(m_hSdkHandle, strFilePath);

			UserOperationRecording( TEXT("IDR_UPDATE_DEVICE"),TEXT("Update"),strFilePath.GetBuffer() ) ;
        }break;
    case IDR_MENU_STOP:
        {
            Close();
			SetSliderCtrl();
            UserOperationRecording( TEXT("IPCamera"),TEXT("BROWSER"),TEXT("successed. - close ") ) ;

            Invalidate(TRUE);
        }
        break;
    case IDR_MENU_ABOUTBOX:
        {
            //CAboutDlg dlgAbout;
            //dlgAbout.DoModal();
        }
        break;
    case IDR_MENU_CLOSE:
        {
			if (m_lWndState == 1)
			{
				SendMessage(WM_LBUTTONDBLCLK, 0 ,0) ;
			}
            m_pParent->SendMessage(WM_CLOSE,0,0);
        }
        break;
    case IDR_MENU_FULLSCREEN:
        {
            //    FullScreen();
        }    
        break;    
    case IDR_MENU_SNAPSHOT:
        {
            static int idx = 1 ;

            if ( NULL == m_hSdkPlayer || m_bSnapShot )
            {
                UserOperationRecording( TEXT("IPCamera"),TEXT("SNAPSHOT"),TEXT("failed.") ) ;

                AfxMessageBox("Snapshot failed !");
                break;
            }

            m_csSnapShot.Lock();

            m_bSnapShot = TRUE;

            m_csSnapShot.Unlock();

            m_pFrame->UpdateData() ;

            CHAR* szFilename =(CHAR*) new CHAR[1024] ;

            WCHAR* swzFilename =(WCHAR*) new CHAR[1024] ;

            //generates a filename
            DWORD dwMinSize;

            CString path = this->m_pFrame->m_RecordingPath ;

            DWORD dwTime = GetTickCount() ;

            tm tt ;

            time_t t1 ;

            time(&t1) ;

            _localtime64_s( &tt, &t1 );

            sprintf(szFilename,"%s\\%04d%02d%02d%02d%02d%02d_strm%d_%03d.bmp",path.GetString(),tt.tm_year+1900,tt.tm_mon,tt.tm_mday,tt.tm_hour,tt.tm_min,tt.tm_sec,m_LoginInfo.lStreamID,idx++) ;

            //multibytes 2 unicode
            dwMinSize = myMultiByteToWideChar(szFilename, -1, NULL, 0) ;

            myMultiByteToWideChar(szFilename, -1, swzFilename, dwMinSize) ;  

            if(!m_pFrame->SnapshotToJpeg())
            {//save 2 bmp
                ipcCapturePicture(m_hSdkPlayer,1,swzFilename) ;

                UserOperationRecording( TEXT("IPCamera"),TEXT("SNAPSHOT"),TEXT("successed.[bmp]") ) ;

            }else{
                //save 2 jpeg
                WCHAR* lpFileExt = PathFindExtensionW(swzFilename) ;

                lpFileExt[1] = 'j' ;
                lpFileExt[2] = 'p' ;
                lpFileExt[3] = 'g' ;

                ipcCapturePicture(m_hSdkPlayer,2,swzFilename) ;

                UserOperationRecording( TEXT("IPCamera"),TEXT("SNAPSHOT"),TEXT("successed.[jpeg]") ) ;

            }

            delete[] (swzFilename) ;

            delete[] (szFilename) ;

            m_csSnapShot.Lock();

            m_bSnapShot = FALSE;

            m_csSnapShot.Unlock();

        }
        break;    
    case IDR_MENU_RECORD_START:
        {
            static int idx = 1 ;

            m_pFrame->UpdateData() ;

            DWORD dwMinSize;

            CHAR* szFilename = (CHAR*)new CHAR[1024] ;

            WCHAR* swzFilename = (WCHAR*)new WCHAR[1024] ;

            CString path = m_pFrame->m_RecordingPath ;

            DWORD dwTime = GetTickCount() ;

            tm tt ;

            time_t t1 ;

            time(&t1) ;

            _localtime64_s( &tt, &t1 );

            sprintf(szFilename,"%s\\%04d%02d%02d%02d%02d%02d_strm%d_%03d.asf",path.GetString(),tt.tm_year+1900,tt.tm_mon,tt.tm_mday,tt.tm_hour,tt.tm_min,tt.tm_sec,m_LoginInfo.lStreamID,idx++) ;

            dwMinSize = myMultiByteToWideChar(szFilename, -1, NULL, 0) ;

            myMultiByteToWideChar(szFilename, -1, swzFilename, dwMinSize) ;  

            ipcStartRecord(m_hSdkPlayer,swzFilename) ;

            delete[] (swzFilename) ;

            delete[] (szFilename) ;

            UserOperationRecording( TEXT("IPCamera"),TEXT("RECORDING"),TEXT("successed.[start]") ) ;

        }break;
    case IDR_MENU_RECORD_STOP:
        {
            ipcStopRecord(m_hSdkPlayer) ;

            UserOperationRecording( TEXT("IPCamera"),TEXT("RECORDING"),TEXT("successed.[stop]") ) ;
        }break;
	case IDR_MENU_ADDSTRING:
		{
			if (NULL == m_hSdkPlayer)
			{
				break;
			}

			if (!m_bShowLogoText)
			{
				m_bShowLogoText = true;
				COLORREF crText = RGB(255, 255, 255);
				CStringDlg	dlgString(m_ftLogoText,crText);

				if ( IDOK != dlgString.DoModal() )
				{
					break;
				}

				if ( !dlgString.m_bEnable)
				{
					m_posdInfo->text = false;
					m_bShowLogoText = false;
				}
				else
				{
					m_posdInfo->text = true;
				}

				m_posdInfo->text_x = dlgString.m_lX;
				m_posdInfo->text_y = dlgString.m_lY;
				m_posdInfo->text_lWidth = 640;
				m_posdInfo->text_lHeight = 480;
				m_posdInfo->text_font = m_ftLogoText;
				m_posdInfo->text_crColor = crText;

				myMultiByteToWideChar(dlgString.m_strCaption, -1, m_posdInfo->text_context, 256);
			}
			else
			{
				m_bShowLogoText = false;
				m_posdInfo->text = false;
			}

			ipcSetDisplayOSD(m_hSdkPlayer, m_posdInfo);
		}break;
	case IDR_MENU_ADDIMAGE:
		{

			if (NULL == m_hSdkPlayer)
			{
				break;
			}

			if ( !m_bShowLogoPicture)
			{
				m_bShowLogoPicture = true;
				CFile	file;
				
				if ( !file.Open("IPC_Logo.bmp"/*lpPath*/,CFile::modeRead | CFile::shareDenyNone) )
				{
					AfxMessageBox("Open file failed !");
					break;
				}

				BITMAPFILEHEADER	Header;
				long lLen = file.Read(&Header,sizeof(Header));
				if ( lLen <= 0 )
				{
					file.Close();
					AfxMessageBox("Read file failed !");
					break;
				}

				long lSize = Header.bfSize - sizeof(Header);
				if ( lSize <= sizeof(BITMAPINFOHEADER) )
				{
					file.Close();
					AfxMessageBox("the file is invalid !");
					break;
				}


                //m_posdInfo->pic_data = (BYTE*)(((BYTE*)m_posdInfo)+sizeof(IPC_OSDPARAM) );
				char *mydata= new char [lSize];
				m_posdInfo->pic_data=(BYTE *)mydata;

				int i= file.Read(m_posdInfo->pic_data,lSize);
				
				file.Close() ;
                m_posdInfo->picture = true;
                m_posdInfo->pic_x = 320;
                m_posdInfo->pic_y = 240;
                m_posdInfo->pic_lWidth = 640;
                m_posdInfo->pic_lHeight = 480;
                m_posdInfo->pic_crMask = RGB(0, 255, 255);
                m_posdInfo->pic_data_len = lSize;
			}
			else
			{
				m_bShowLogoPicture = false;
				m_posdInfo->picture = false;
			}
			
			//BYTE* pData = NULL;
 			//long lSize = 0;
 			//LoadLogoPicture("./IPC_Logo.bmp", &pData, &lSize);
			//m_osdInfo.picture = true;
			
			ipcSetDisplayOSD(m_hSdkPlayer, m_posdInfo);

		}break;
	case IDR_CRUISE:
		{
			if (NULL == m_hSdkPlayer)
			{
				MessageBox(_T("请先登录!"));
				break;
			}
			CCruiseDlg  dlg(m_hSdkHandle);
			dlg.DoModal();

		}break;
    case IDR_MENU_SETBUFTIME:
		{
			if (NULL == m_hSdkPlayer)
			{
				MessageBox(_T("请先登录!"));
				break;
			}
			DWORD dwTime=0;
			if( 0 != ipcGetBufferTime(m_hSdkPlayer,&dwTime) )
			{
				MessageBox(_T("获取播放缓存时间失败!"));
				break;
			}
			CBufferTimeDlg  dlg;
			dlg.m_nTime = dwTime;
			if( dlg.DoModal() == IDOK)
			{
				ipcSetBufferTime(m_hSdkPlayer,dlg.m_nTime);
			}

		 
		}break;
	
    default:
        break;
    }

    return CWnd::OnCommand(wParam, lParam);
}

BOOL CVideoWnd::Open(TEST_PLAYER_LOGININFO info)
{
    
    if(m_hSdkHandle)
    {
        return FALSE ;
    }

    m_stream_Id = info.lStreamID ;

    m_hSdkHandle = ipcCreateDevice() ;

    ipcConnect(m_hSdkHandle,info.szUser,info.szPsw,info.szHostIP,info.lHostPort/*,false*/) ;

    if( ipcWaitConnected(m_hSdkHandle,5000) !=0 )
    {
        return FALSE ;
    }

    m_hSdkPlayer = ipcCreateLivePlay( m_hSdkHandle,m_hWnd,0,info.lStreamID) ;

    Refresh() ;

    ipcStartLivePlay(m_hSdkPlayer) ;

    ipcRegisterMsgCallBack(m_hSdkHandle,(ipcNormalMsgCallback)playerdemo_Message_CallBack,this) ;

    ipcRegisterLiveFrameCallBack(m_hSdkPlayer,my_LiveFrame_CallBack,0) ;

    ipcSetAVCallbackEx(m_hSdkPlayer,MyAudioCallbackEx,0) ;

	ipcRegisterLiveYUVCallBack(m_hSdkPlayer,ipcYUVCallBack,0) ;

    ipcStartHeartbeat(m_hSdkHandle,3000,myHeartBeatCallback,this) ;


    ////IPC_PTZControl(m_hSdkHandle,0,0,0,0,0) ;
    //CHAR* lpVal = new CHAR[1024] ;
    //memset(lpVal,0,1024) ;
    //*((DWORD*)lpVal) = 999 ;
    //int iSucc = IPC_SetConfig(m_hSdkHandle,9,0,lpVal) ;

    //iSucc = IPC_GetConfig(m_hSdkHandle,9,0,lpVal) ;

    return TRUE;
}


void CVideoWnd::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    if ( NULL == m_pParent )
    {
        return;
    }

    if ( m_lWndState <= 0 )
    {
        m_lWndState = 1;
    }

    else if ( m_lWndState <= 1 )
    {
        m_lWndState = 0;
    }

    m_pParent->SendMessage(IPC_MSG_VIDEOWNDMOVE,m_lIndex,m_lWndState);

    CWnd::OnLButtonDblClk(nFlags, point);
}

void CVideoWnd::OnDestroy() 
{
     ;

    CWnd::OnDestroy();

    // TODO: Add your message handler code here
    /*    
    m_csRecord.Lock();
    if ( m_bRecord )
    {
    m_File.Close();
    }    

    m_bRecord = FALSE;

    m_csRecord.Unlock();
    */
}
VOID CVideoWnd::UserOperationRecording(const TCHAR* cmd_,const TCHAR* state_,const TCHAR* reason_) 
{
     ;

    m_pFrame->GetUserLogMgr().push(cmd_,state_,reason_) ;
}

void CVideoWnd::Close()
{

    ipcStopHeartbeat(m_hSdkHandle) ;

    ipcStopLivePlay(m_hSdkPlayer) ;

    ipcDestroyLivePlay(m_hSdkHandle,m_hSdkPlayer) ;

    m_hSdkPlayer = 0 ;

    ipcDisConnect(m_hSdkHandle) ;

    ipcDestroyDevice(m_hSdkHandle) ;

    m_hSdkHandle = 0 ;

    m_stream_Id = 0 ;

}

BOOL CVideoWnd::Refresh()
{
    CRect    rc;

    GetClientRect(&rc);

    RECT rt ;

    rt.left = rc.left + 2 ;

    rt.top = rc.top + 2 ;

    rt.right = rc.right - 4 ;

    rt.bottom = rc.bottom - 4 ;

    ipcSetDisplayRect(m_hSdkPlayer,rt) ;

    return TRUE ;

}

void CVideoWnd::OnRButtonDown(UINT nFlags, CPoint point) 
{

    CMenu        menu;

    menu.CreatePopupMenu();

    menu.AppendMenu(MF_STRING,IDR_MENU_RUN,"Open");

    menu.AppendMenu(MF_STRING,IDR_MENU_STOP,"Close");

    menu.AppendMenu(MF_SEPARATOR);

	menu.AppendMenu(MF_STRING,IDR_CRUISE,"Cruise");
    menu.AppendMenu(MF_STRING,IDR_MENU_SNAPSHOT,"Snapshot");    

 
    menu.AppendMenu(MF_STRING,IDR_MENU_SETBUFTIME,"BufferTime");    

    menu.AppendMenu(MF_SEPARATOR);

    menu.AppendMenu(MF_STRING,IDR_MENU_RECORD_START,"Recording Start") ;

    menu.AppendMenu(MF_STRING,IDR_MENU_RECORD_STOP,"Recording Stop") ;

    menu.AppendMenu(MF_SEPARATOR);

	menu.AppendMenu(MF_STRING,IDR_MENU_ADDSTRING,"Overlay string");
	menu.AppendMenu(MF_STRING,IDR_MENU_ADDIMAGE,"Overlay image");

    menu.AppendMenu(MF_SEPARATOR);
    menu.AppendMenu(MF_STRING,IDR_UPDATE_DEVICE,"Update");
	menu.AppendMenu(MF_SEPARATOR);

    menu.AppendMenu(MF_STRING,IDR_MENU_ABOUTBOX,"About...");

    menu.AppendMenu(MF_SEPARATOR);

    menu.AppendMenu(MF_STRING,IDR_MENU_CLOSE,"Exit");

    ClientToScreen(&point);

    menu.TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON, point.x, point.y, this );

    CWnd::OnRButtonDown(nFlags, point);
}

//VOID CVideoWnd::SetPTZMode(BOOL bIsPTZMode)
//{
//    m_IsPTZMode = bIsPTZMode ;
//}
//
//BOOL CVideoWnd::GetPTZMode()
//{
//    return m_IsPTZMode ;
//}

VOID CVideoWnd::Dptz_focus(BOOL bInOut,BOOL bStartStop)
{
    if( bInOut )
    {
        if( bStartStop )
        {
            ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_FOCUS_FAR,1,0) ;            
        }else{
            ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_FOCUS_FAR,0,0) ;  
        }
    }else{
        if( bStartStop )
        {
            ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_FOCUS_NEAR,1,0) ;            
        }else{
            ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_FOCUS_NEAR,0,0) ;  
        }   
    }
}

VOID CVideoWnd::Dptz_zoom(int step)
{
     ;

    m_dptz_zoom+=step ;

    if(m_dptz_zoom>11)
    {
        m_dptz_zoom = 11 ;
    }
    if(m_dptz_zoom<0)
    {
        m_dptz_zoom =  0 ;
    }

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_ZOOM,m_dptz_zoom,0) ;
}
VOID CVideoWnd::Dptz_left(int step )
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_LEFT,step,0) ;
}

VOID CVideoWnd::Dptz_right(int step )
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_RIGHT,step,0) ;
}

VOID CVideoWnd::Dptz_up(int step )
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_UP,step,0) ;
}

VOID CVideoWnd::Dptz_down(int step )
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_DOWN,step,0) ;
}

VOID CVideoWnd::Dptz_home()
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_GOTO_HOME,0,0) ;

    m_dptz_zoom = 0 ;
}

VOID CVideoWnd::Dptz_set_preset(int num,const CHAR* preset_name ) 
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_SET_PRESET,num,preset_name) ;
}

VOID CVideoWnd::Dptz_clear_preset(int num) 
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_CLEAR_PRESET,num,0) ;
}

VOID CVideoWnd::Dptz_clearall_preset()
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_CLEAR_ALL_PRESET,0,0) ;
}

VOID CVideoWnd::Dptz_goto_preset(int num)
{
     ;

    ipcDPTZControl(m_hSdkPlayer,IPC_CMD_DPTZ_GOTO_PRESET,num,0) ;

}


//////////////////////////////////////////////////////////////////////////
VOID CVideoWnd::Ptz_focus(BOOL zoom_in_out,BOOL ctrl_start_stop,int hspeed,int vspeed)
{
     ;
    if ( zoom_in_out )
    {
        ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_FOCUS_FAR,ctrl_start_stop,hspeed,vspeed) ;

    }else{

        ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_FOCUS_NEAR,ctrl_start_stop,hspeed,vspeed) ;
    }

}
VOID CVideoWnd::Ptz_zoom(BOOL zoom_in_out,BOOL ctrl_start_stop,int hspeed,int vspeed)
{
     ;

    if ( zoom_in_out )
    {
        ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_ZOOM_TELE,ctrl_start_stop,hspeed,vspeed) ;

    }else{

        ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_ZOOM_WIDE,ctrl_start_stop,hspeed,vspeed) ;
    }

}
VOID CVideoWnd::Ptz_left(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
     ;

    ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_LEFT,ctrl_start_stop,hspeed,vspeed) ;
}

VOID CVideoWnd::Ptz_right(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
     ;

    ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_RIGHT,ctrl_start_stop,hspeed,vspeed) ;
}


VOID CVideoWnd::Ptz_leftup(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
    ipcPTZUpleft(m_hSdkHandle,ctrl_start_stop,hspeed,vspeed) ;
}
VOID CVideoWnd::Ptz_leftdown(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
   ipcPTZDownleft(m_hSdkHandle,ctrl_start_stop,hspeed,vspeed) ;
}
VOID CVideoWnd::Ptz_rightup(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
   ipcPTZUpright(m_hSdkHandle,ctrl_start_stop,hspeed,vspeed) ;
}

VOID CVideoWnd::Ptz_rightdown(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
    ipcPTZDownright(m_hSdkHandle,ctrl_start_stop,hspeed,vspeed) ;
}
VOID CVideoWnd::Ptz_rotaion(int hspeed,int vspeed) 
{
	 ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_AUTOPAN,1,hspeed,vspeed) ;
}

VOID CVideoWnd::Ptz_up(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
     ;

    ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_UP,ctrl_start_stop,hspeed,vspeed) ;
}

VOID CVideoWnd::Ptz_down(BOOL ctrl_start_stop,int hspeed,int vspeed)
{
     ;

    ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_DOWN,ctrl_start_stop,hspeed,vspeed) ;
}

VOID CVideoWnd::Ptz_home(int hspeed,int vspeed)
{
     ;

    ipcPTZControl(m_hSdkHandle,0,IPC_CMD_PTZ_GOTO_HOME,1,hspeed,vspeed) ;
}

VOID CVideoWnd::Ptz_set_preset(int num,const CHAR* preset_name) 
{
     ;

    ipcPTZSetPreset(m_hSdkHandle,0,num,"") ;//preset_name
}

VOID CVideoWnd::Ptz_clear_preset(int num) 
{
     ;
    //IPC_DPTZControl(m_hSdkPlayer,0x00002000+6,num) ;
}

VOID CVideoWnd::Ptz_clearall_preset()
{
     ;
    //IPC_DPTZControl(m_hSdkPlayer,0x00002000+8,0) ;
}

VOID CVideoWnd::Ptz_goto_preset(int num,int hspeed,int vspeed)
{
     ;
    //IPC_PTZPreset(m_hSdkHandle,0,IPC_COMMAND_PTZ_GOTO_PRESET,num,preset_name) ;
    ipcPTZGotoPreset(m_hSdkHandle,0,num,hspeed,vspeed) ;

}
//////////////////////////////////////////////////////////////////////////


BOOL CVideoWnd::Property_Set_INT(DWORD cmd,const DWORD& val)
{
     ;

    BOOL bRet = ipcSetConfig(m_hSdkHandle,cmd,m_stream_Id,(CHAR*)&val) ;

    if (bRet != 0)
    {
        MessageBox("SetConfig failed.",0,0) ;
    }
    return bRet ;
}
BOOL CVideoWnd::Property_Get_INT(DWORD cmd,DWORD& val)
{
     ;

    CHAR szTemp[1024]={0} ;

    BOOL bRet = ipcGetConfig(m_hSdkHandle,cmd,m_stream_Id,szTemp) ;

    if (bRet != 0)
    {
        MessageBox("SetConfig failed.",0,0) ;
    }
    val = *((DWORD*)szTemp) ;

    return bRet ;
}

BOOL CVideoWnd::Property_Set_STR(DWORD cmd,const char* val)
{
     ;

    BOOL bRet = ipcSetConfig(m_hSdkHandle,cmd,m_stream_Id,val) ;

    if (bRet != 0)
    {
        MessageBox("SetConfig failed.",0,0) ;
    }

    return bRet ;
}

BOOL CVideoWnd::Property_Get_STR(DWORD cmd,char* val)
{
     ;

    BOOL bRet = ipcGetConfig(m_hSdkHandle,cmd,m_stream_Id,val) ;

    if (bRet != 0)
    {
        MessageBox("SetConfig failed.",0,0) ;
    }

    return bRet ;

}

INT CVideoWnd::StartImageSharpen(float amount)
{
	;
	return ipcStartLiveImageSharpen(m_hSdkPlayer,amount);
}

INT CVideoWnd::ChangeSharpenDegree(float amount)
{
	;
	return ipcChangeLiveSharpenDegree(m_hSdkPlayer,amount);

}

INT CVideoWnd::StopImageSharpen()
{
	;
	return ipcStopLiveImageSharpen(m_hSdkPlayer);

}

void WINAPI my_LiveFrame_CallBack( playHandle hPlayer_, const IPC_FrameInfo * frameType_,const CHAR* frameData_,INT dataLen_, LPVOID context_ )
{
    // ;
    XTRACE("264 frame incoming.") ;
    //264 frame .
    int i = 0 ;
}
VOID WINAPI MyAudioCallbackEx( LPVOID handle, const IPC_FrameInfoEx* info, LPVOID context) 
{
    CHAR *szTemp = new CHAR[1024] ;

    memset( szTemp,0,1024*sizeof(CHAR) ) ;

    switch( info->lType)
    {
    case 'I':
    case 'B':
    case 'P':
        {
            sprintf(szTemp,("IPC_FrameInfo:type = %d ,frame:%d,format=%d,width=%d,height=%d\n"),info->lType,info->info.video.lFrameRate,info->info.video.lVideoFormat,info->info.video.lWidth,info->info.video.lHeight) ;

        }break;
    case 'A':
        {
            sprintf(szTemp,("IPC_FrameInfo:type = %d ,format=%d,SamplesPerSec=%d,BitsPerSample=%d,channel=%d\n"),info->lType,info->info.audio.lAudioFormat,info->info.audio.lSamplesPerSec,info->info.audio.lBitsPerSample,info->info.audio.lChannels) ;

        }break;
    }
    
    //FILE* hf = fopen("d:\\callback_log.txt","ab") ;

    //fwrite( szTemp,1,strlen(szTemp),hf) ;

    //fclose(hf) ;

    //OutputDebugStringW((LPCWSTR)szTemp) ;

    delete[] szTemp ;
}

void WINAPI ipcYUVCallBack( playHandle hPlayer , const IPC_FrameInfo * lpFrameInfo,const CHAR* lpData,INT iDataLen, LPVOID lpContext )
{
	CHAR szTemp[1024] ;
    memset( szTemp,0,1024*sizeof(CHAR) ) ;
	sprintf(szTemp,("ipcYUVCallBack:type = %d, width=%d, height=%d, frame rate=%d, frame length=%d\n"),
		lpFrameInfo->lType,lpFrameInfo->lWidth,lpFrameInfo->lHeight,lpFrameInfo->lFrameRate, iDataLen);
	//OutputDebugStringA( szTemp );
}

VOID WINAPI myHeartBeatCallback(ipcHandle handle,BOOL isOnline, LPVOID context)
{
    if( !isOnline )
    {
        printf("offline") ;
    }
}


void WINAPI playerdemo_Message_CallBack(ipcHandle handle,INT cmd_,LPVOID data_,LPVOID pFrame)
{
     ;

    ipcHandle hdl = handle ;

    CVideoWnd* lpVideoWnd = ((CVideoWnd*)pFrame) ;

    if( handle == lpVideoWnd->m_hSdkHandle )
    {
        switch(cmd_)
        {
        case ipc_App_Config :
            {
				lpVideoWnd->OnCameraConfig((IPC_COMMAND_CONTEXT*)data_) ;
               // lpVideoWnd->OnCommandResult((IPC_COMMAND_CONTEXT*)data_) ;
            }break ;

        case ipc_App_Ptz :
            {
                lpVideoWnd->OnCommandResult((IPC_COMMAND_CONTEXT*)data_) ;
            }break ;

        case ipc_App_Event :
            {
                lpVideoWnd->OnEventResult((IPC_EVENT_CONTEXT*)data_) ;
            }break ;

        case ipc_App_SysSetting:
            {
                lpVideoWnd->OnSystemSettingResult((IPC_COMMAND_CONTEXT*)data_) ;
            }break ;
        case ipc_App_Connect:
            {
				INT state = IPC_CONNECT_UNKNOW ;
				memcpy(&state, data_, sizeof(INT)) ;
				lpVideoWnd->OnConnectStateChange(state) ;
                //lpVideoWnd->UserOperationRecording("Session Layer","CONNECT",(CHAR*)data_) ;
            }break ;
        }

    }

}

void CVideoWnd::OnGetCameraConfigResult(IPC_COMMAND_CONTEXT* context)
{
     ;

    CHAR szTemp[32]={0} ;

#define RECORD_GET_COMMAND(name) case name:                                                                            \
    {                                                                                                            \
    if(context->result !=0 ){                                                                                \
    UserOperationRecording( TEXT(#name),TEXT("GET"),TEXT("failed.") ) ;                                        \
    }else{                                                                                                    \
    UserOperationRecording( TEXT(#name),TEXT("GET"),TEXT("successed.") ) ;                                        \
    }                                                                                                        \
    }break;

    switch( context->subtype )
    {
	case IPC_VIDEO_IRCUT_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_IMGIRCUT lpIrcut= (LPIPC_IMGIRCUT)context->data ;
				UserOperationRecording( TEXT("IPC_VIDEO_IRCUT_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_VIDEO_IRCUT_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}

		}break ;
	case IPC_VIDEO_DCIRIS_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_IMGIRIS lpDC= (LPIPC_IMGIRIS)context->data ;
				UserOperationRecording( TEXT("IPC_VIDEO_DCIRIS_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_VIDEO_DCIRIS_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}
		}break ;
	case IPC_VIDEO_SHUTTER_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_IMGSHUTTER lpShutter= (LPIPC_IMGSHUTTER)context->data ;
				UserOperationRecording( TEXT("IPC_VIDEO_SHUTTER_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_VIDEO_SHUTTER_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}
		}break ;
	case IPC_VIDEO_PM_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_IMGPM lpPm= (LPIPC_IMGPM)context->data ;
				UserOperationRecording( TEXT("IPC_VIDEO_PM_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_VIDEO_PM_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}
		}break ;
	case IPC_ENCODE_ENC_ENC_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_ENCENC lpEncCur = (LPIPC_ENCENC)context->data ;
				UserOperationRecording( TEXT("IPC_ENCODE_ENC_ENC_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_ENCODE_ENC_ENC_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}
		}break ;
	case IPC_ENCODE_ENC_SN_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_ENCSN lpEncSn = (LPIPC_ENCSN)context->data ;
				UserOperationRecording( TEXT("IPC_ENCODE_ENC_SN_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_ENCODE_ENC_SN_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}
		}break ;
	case IPC_ENCODE_SN_TEXT_GROUP:
		{
			if (context->result == 0)
			{
				LPIPC_SNTEXT lpEncSn = (LPIPC_SNTEXT)context->data ;
				UserOperationRecording( TEXT("IPC_ENCODE_SN_TEXT_GROUP"),TEXT("GET"),TEXT("successed.") ) ;
			}
			else
			{
				UserOperationRecording( TEXT("IPC_ENCODE_SN_TEXT_GROUP"),TEXT("GET"),TEXT("failed.") ) ;
			}

		}break ;

        RECORD_GET_COMMAND(IPC_VIDEO_EXPOSURE_MODE                )
            RECORD_GET_COMMAND(IPC_VIDEO_MAX_GAIN                  )
            RECORD_GET_COMMAND(IPC_VIDEO_SLOW_SHUTTER              )
            RECORD_GET_COMMAND(IPC_VIDEO_AE_PREFERENCE             )
            RECORD_GET_COMMAND(IPC_VIDEO_DN_MODE                   )
            RECORD_GET_COMMAND(IPC_VIDEO_METERING_MODE             )
            RECORD_GET_COMMAND(IPC_VIDEO_BACKLIGHT_COMP            )
            RECORD_GET_COMMAND(IPC_VIDEO_LOCAL_EXPOSURE            )
            RECORD_GET_COMMAND(IPC_VIDEO_MCTF_STRENGTH             )
            RECORD_GET_COMMAND(IPC_VIDEO_AE_TARGET_RATION          )
            RECORD_GET_COMMAND(IPC_VIDEO_WBC                       )

            RECORD_GET_COMMAND(IPC_ENCODE_ENC_MODE                )
            RECORD_GET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE0         )
			RECORD_GET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE1         )
			RECORD_GET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE2         )
			RECORD_GET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE3         )
			//RECORD_GET_COMMAND(IPC_CMD_PTZ_PROTOCOL)
			RECORD_GET_COMMAND(IPC_VIDEO_IMGPRO_GROUP)
            
            RECORD_GET_COMMAND(IPC_ENCODE_STR_I_INTERVAL)
            RECORD_GET_COMMAND(IPC_ENCODE_STR_FORCE_I)
            RECORD_GET_COMMAND(IPC_VIDEO_AF_ENABLE)
            RECORD_GET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM0         )
            RECORD_GET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM1         )
            RECORD_GET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM2         )
            RECORD_GET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM3         )
            RECORD_GET_COMMAND(IPC_VIDEO_WBC_CUSTOM_R_GAIN         )
            RECORD_GET_COMMAND(IPC_VIDEO_WBC_CUSTOM_B_GAIN         )
            

            

    default:{throw -1;}break;

    }


}

void CVideoWnd::OnCommandResult(IPC_COMMAND_CONTEXT* context)
{
     ;

#define CHECK_COMMAND(name) case name:                                                                \
    {                                                                                                \
    if(context->result!=0)                                                                        \
    {                                                                                            \
    UserOperationRecording( TEXT(#name),TEXT("SET"),TEXT("failed.") ) ;                            \
    }else{                                                                                        \
    UserOperationRecording( TEXT(#name),TEXT("SET"),TEXT("successed.") ) ;                            \
    }                                                                                            \
    }break;

    switch(context->cmd)
    {
            CHECK_COMMAND(IPC_CMD_DPTZ_FOCUS_NEAR                   )
            CHECK_COMMAND(IPC_CMD_DPTZ_FOCUS_FAR                    )
            CHECK_COMMAND(IPC_CMD_DPTZ_ZOOM                         )
            CHECK_COMMAND(IPC_CMD_DPTZ_UP                           )
            CHECK_COMMAND(IPC_CMD_DPTZ_DOWN                         )
            CHECK_COMMAND(IPC_CMD_DPTZ_LEFT                         )
            CHECK_COMMAND(IPC_CMD_DPTZ_RIGHT                        )
            CHECK_COMMAND(IPC_CMD_DPTZ_SET_PRESET                   )
            CHECK_COMMAND(IPC_CMD_DPTZ_CLEAR_PRESET                 )
            CHECK_COMMAND(IPC_CMD_DPTZ_GOTO_PRESET                  )
            CHECK_COMMAND(IPC_CMD_DPTZ_CLEAR_ALL_PRESET             )
            CHECK_COMMAND(IPC_CMD_DPTZ_GOTO_HOME                    )
            CHECK_COMMAND(IPC_CMD_PTZ_FOCUS_NEAR                    )
            CHECK_COMMAND(IPC_CMD_PTZ_FOCUS_FAR                    )
            CHECK_COMMAND(IPC_CMD_PTZ_ZOOM_WIDE                    )
            CHECK_COMMAND(IPC_CMD_PTZ_ZOOM_TELE                    )
            CHECK_COMMAND(IPC_CMD_PTZ_UP                            )
            CHECK_COMMAND(IPC_CMD_PTZ_DOWN                        )
            CHECK_COMMAND(IPC_CMD_PTZ_LEFT                        )
            CHECK_COMMAND(IPC_CMD_PTZ_RIGHT                        )
            CHECK_COMMAND(IPC_CMD_PTZ_SET_PAN_SPEED                )
            CHECK_COMMAND(IPC_CMD_PTZ_SET_TILT_SPEED                )
            CHECK_COMMAND(IPC_CMD_PTZ_SET_PRESET                    )
            CHECK_COMMAND(IPC_CMD_PTZ_GOTO_PRESET                )
            CHECK_COMMAND(IPC_CMD_PTZ_GOTO_HOME                    )
    }
}

void CVideoWnd::OnEventResult(IPC_EVENT_CONTEXT* context)
{
     ;

 	if (NULL != m_pEventCallBack)
 	{
 		m_pEventCallBack->OnContextResult(context) ;
 	}

    switch(context->cmd)
    {
	case IPC_CMD_GET_PROPERTY:
		{
			if(context->result !=0 )
			{    
				UserOperationRecording( TEXT("IPC_CMD_GET_PROPERTY"),TEXT("GET"),TEXT("failed.") ) ;
			}else{
				UserOperationRecording( TEXT("IPC_CMD_GET_PROPERTY"),TEXT("GET"),TEXT("successed.") ) ;
			}
		}break;
	case IPC_CMD_SET_PROPERTY:
		{
			if(context->result !=0 )
			{    
				UserOperationRecording( TEXT("IPC_CMD_SET_PROPERTY"),TEXT("SET"),TEXT("failed.") ) ;
			}else{
				UserOperationRecording( TEXT("IPC_CMD_SET_PROPERTY"),TEXT("SET"),TEXT("successed.") ) ;
			}
		}break;
   default:
         {
         }
    }
}
void CVideoWnd::OnSystemSettingResult(IPC_COMMAND_CONTEXT* context)
{
     ;

 	if (NULL != m_pSystemSettingCallBack)
 	{
 		m_pSystemSettingCallBack->OnContextResult(context) ;
 	}

#define CHECK_SYSTEM(name) case name:                                                                \
	{                                                                                                \
	if(context->result!=0)                                                                        \
	{                                                                                            \
	UserOperationRecording( TEXT(#name),TEXT("SET"),TEXT("failed.") ) ;                            \
	}else{                                                                                        \
	UserOperationRecording( TEXT(#name),TEXT("SET"),TEXT("successed.") ) ;                            \
	}                                                                                            \
	}break;

    switch(context->cmd)
    {
    case IPC_CMD_GET_PROPERTY                    :
        {
			switch (context->subtype)
			{
			case IPC_SYSTEM_SETGET_DATEINFO:
				{
					if(context->result!=0)                                                                        
					{                                                                                            
						UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_DATEINFO"),TEXT("SYS-GET"),TEXT("failed.") ) ;                            
					}
					else
					{                                                                            
						LPIPC_SYSDATEINFO lpDate = (LPIPC_SYSDATEINFO)context->data;
						UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_DATEINFO"),TEXT("SYS-GET"),TEXT("successed.") ) ;
					}                 
				}break;
			case IPC_SYSTEM_SETGET_SMTPINFO:
				{
					if(context->result!=0)                                                                        
					{                                                                                            
						UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_SMTPINFO"),TEXT("SYS-GET"),TEXT("failed.") ) ;                            
					}
					else
					{                                                                            
						LPIPC_SYSSMTP lpDate = (LPIPC_SYSSMTP)context->data;
						UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_SMTPINFO"),TEXT("SYS-GET"),TEXT("successed.") ) ;
					}       
				}break;
			case IPC_SYSTEM_SETGET_FTPINFO:
				{
					if(context->result!=0)                                                                        
					{                                                                                            
						UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_FTPINFO"),TEXT("SYS-GET"),TEXT("failed.") ) ;                            
					}
					else
					{                                                                            
						LPIPC_SYSFTP lpDate = (LPIPC_SYSFTP)context->data;
						UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_FTPINFO"),TEXT("SYS-GET"),TEXT("successed.") ) ;
					}   
				}break;
			case IPC_SYSTEM_SETGET_IPINFO:
				if(context->result!=0)                                                                        
				{                                                                                            
					UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_IPINFO"),TEXT("SYS-GET"),TEXT("failed.") ) ;                            
				}
				else
				{                                                                            
					LPIPC_SYSIPINFO lpDate = (LPIPC_SYSIPINFO)context->data;
					UserOperationRecording( TEXT("IPC_SYSTEM_SETGET_IPINFO"),TEXT("SYS-GET"),TEXT("successed.") ) ;
				}  
				break;
			case IPC_SYSTEM_SETGET_UPNPINFO:
				break;
			case IPC_SYSTEM_UPNP_NAME:
			case IPC_SYSTEM_UPNP_PORT:
			case IPC_SYSTEM_UPNP_ENABLE:
			case IPC_SYSTEM_GET_RTP_ADDR:
			case IPC_SYSTEM_GET_RTP_ADDR2 :
			case IPC_SYSTEM_GET_RTP_ADDR3 :
			case IPC_SYSTEM_GET_RTP_ADDR4 :
			case IPC_SYSTEM_GET_SD_STATUS :
			case IPC_SYSTEM_GET_SD_RW :
			case IPC_SYSTEM_GET_SD_SPACE :
			case IPC_SYSTEM_GET_SD_FREE_SAPCE :
			case IPC_SYSTEM_GET_DEVICE_NAME :
			case IPC_SYSTEM_GET_DEVICE_MANUFACTURER :
			case IPC_SYSTEM_GET_FW_VERSION :
			case IPC_SYSTEM_GET_HW_VERSION :
            case IPC_SYSTEM_GET_DEVICE_SN :
			case IPC_SYSTEM_GET_REC_FILES :
				{
					if(context->result!=0)                                                                        
					{                                                                                            
						UserOperationRecording( TEXT("IPC_SYS_GET_PROPERTY"),TEXT("SYS-GET"),TEXT("failed.") ) ;                            
					}
					else
					{                                                                            
						UserOperationRecording( TEXT("IPC_SYS_GET_PROPERTY"),TEXT("SYS-GET"),TEXT("successed.") ) ;
					}    
				}break ;
			}                                                                                             
        }break ;
    case IPC_CMD_SET_PROPERTY                    :
        {
			switch (context->subtype)
			{
				CHECK_SYSTEM(IPC_SYSTEM_SET_SD_CMD )
					CHECK_SYSTEM(IPC_SYSTEM_SET_REC_DEL_FILES )
					CHECK_SYSTEM(IPC_SYSTEM_SET_REC_UPLOAD_FILES )
					CHECK_SYSTEM(IPC_SYSTEM_UPNP_ENABLE )
					CHECK_SYSTEM(IPC_SYSTEM_UPNP_PORT )
					CHECK_SYSTEM(IPC_SYSTEM_UPNP_NAME )
					CHECK_SYSTEM(IPC_SYSTEM_SETGET_UPNPINFO )
					CHECK_SYSTEM(IPC_SYSTEM_SETGET_DATEINFO )
					CHECK_SYSTEM(IPC_SYSTEM_SETGET_SMTPINFO )
					CHECK_SYSTEM(IPC_SYSTEM_SETGET_FTPINFO )
					CHECK_SYSTEM(IPC_SYSTEM_SETGET_IPINFO )
			}	 
        }break;
    }
}

void CVideoWnd::OnCameraConfig( IPC_COMMAND_CONTEXT* context )
{
	if (NULL != context)
	{
		if (NULL != m_pCameraConfigCallBack)
		{
			m_pCameraConfigCallBack->OnContextResult(context) ;
		}

		if (context->cmd == IPC_CMD_GET_PROPERTY)
		{
			OnGetCameraConfigResult(context) ;
		}
		else if (context->cmd == IPC_CMD_SET_PROPERTY)
		{
			OnSetCameraConfigResult(context) ;
		}
	}
}

ipcHandle CVideoWnd::GetSdkHandle()
{
    return m_hSdkHandle ;
}
playHandle CVideoWnd::GetPlayHandle() 
{
    return m_hSdkPlayer ;
}
bool CVideoWnd::LoadLogoPicture( LPCTSTR lpPath, BYTE** pData, long* lSize)
{
	CFile	file;
	if ( !file.Open("IPC_Logo.bmp"/*lpPath*/,CFile::modeRead | CFile::shareDenyNone) )
	{
		AfxMessageBox("Open file failed !");
		return false;
	}

	BITMAPFILEHEADER	Header;
	long lLen = file.Read(&Header,sizeof(Header));
	if ( lLen <= 0 )
	{
		file.Close();
		AfxMessageBox("Read file failed !");
		return false;
	}

	/*long lSize*/
	*lSize = Header.bfSize - sizeof(Header);
	if ( *lSize <= sizeof(BITMAPINFOHEADER) )
	{
		file.Close();
		AfxMessageBox("the file is invalid !");
		return false;
	}

	/*unsigned char **/
	*pData = new unsigned char [*lSize];
	if ( NULL == *pData )
	{
		file.Close();
		AfxMessageBox("the memory is null !");
		return false;
	}

	//
	if ( file.Read(*pData,*lSize) <= 0 )
	{
		delete [] (*pData);
		*pData = NULL;

		file.Close();
		AfxMessageBox("Read image data failed !");
		return false;
	}

	file.Close();
	
	return true ;
}

void CVideoWnd::OnSetCameraConfigResult(IPC_COMMAND_CONTEXT* context)
{
     ;

    CHAR szTemp[32]={0} ;
#define RECORD_SET_COMMAND(name) case name:                                                                            \
    {                                                                                                            \
    itoa( (INT)(context->data),szTemp,10 ) ;                                                                \
    if(context->result !=0 ){                                                                                \
    UserOperationRecording( TEXT(#name),TEXT("SET"),TEXT("failed.") ) ;                                        \
    }else{                                                                                                    \
    UserOperationRecording( TEXT(#name),TEXT("SET"),TEXT("successed.") ) ;                                        \
    }                                                                                                        \
    }break;

    switch( context->subtype )
    {

        RECORD_SET_COMMAND(IPC_VIDEO_EXPOSURE_MODE                )
            RECORD_SET_COMMAND(IPC_VIDEO_MAX_GAIN                  )
            RECORD_SET_COMMAND(IPC_VIDEO_SLOW_SHUTTER              )
            RECORD_SET_COMMAND(IPC_VIDEO_AE_PREFERENCE             )
            RECORD_SET_COMMAND(IPC_VIDEO_DN_MODE                   )
            RECORD_SET_COMMAND(IPC_VIDEO_METERING_MODE             )
            RECORD_SET_COMMAND(IPC_VIDEO_BACKLIGHT_COMP            )
            RECORD_SET_COMMAND(IPC_VIDEO_LOCAL_EXPOSURE            )
            RECORD_SET_COMMAND(IPC_VIDEO_MCTF_STRENGTH             )
            RECORD_SET_COMMAND(IPC_VIDEO_AE_TARGET_RATION          )
            RECORD_SET_COMMAND(IPC_VIDEO_WBC                       )

            RECORD_SET_COMMAND(IPC_ENCODE_ENC_MODE                )
			RECORD_SET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE0         )
			RECORD_SET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE1         )
			RECORD_SET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE2         )
			RECORD_SET_COMMAND(IPC_ENCODE_SN_TIME_ENABLE3         )
            /////////////////////////////////////////
            RECORD_SET_COMMAND(IPC_VIDEO_DCIRIS_GROUP              )
			RECORD_SET_COMMAND(IPC_VIDEO_SHUTTER_GROUP              )
			RECORD_SET_COMMAND(IPC_VIDEO_PM_GROUP              )
			RECORD_SET_COMMAND(IPC_ENCODE_SN_TEXT_GROUP              )
			RECORD_SET_COMMAND(IPC_ENCODE_ENC_SN_GROUP              )
			RECORD_SET_COMMAND(IPC_VIDEO_MJPEG_QUALITY)
			RECORD_SET_COMMAND(IPC_VIDEO_IMGPRO_GROUP)
            RECORD_SET_COMMAND(IPC_ENCODE_STR_I_INTERVAL)
            RECORD_SET_COMMAND(IPC_ENCODE_STR_FORCE_I)
            RECORD_SET_COMMAND(IPC_VIDEO_AF_ENABLE)
            RECORD_SET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM0         )
            RECORD_SET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM1         )
            RECORD_SET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM2         )
            RECORD_SET_COMMAND(IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM3         )
            RECORD_SET_COMMAND(IPC_VIDEO_WBC_CUSTOM_R_GAIN         )
            RECORD_SET_COMMAND(IPC_VIDEO_WBC_CUSTOM_B_GAIN         )

    default:
		{
			//throw -1;
		}break;

    }
}

void CVideoWnd::RegisterEventCallBack( ICallBackInterface* pCallback )
{
	
	m_pEventCallBack = pCallback ;

}

void CVideoWnd::RegisterSystemSettingCallBack( ICallBackInterface* pCallback )
{
	 ;

	m_pSystemSettingCallBack = pCallback ;
}

void CVideoWnd::RegisterCameraConfigCallBack(ICallBackInterface* pCallback)
{
	m_pCameraConfigCallBack = pCallback ;
}

void CVideoWnd::OnConnectStateChange( INT state )
{
	std::string state_text ;
	switch (state)
	{
	case IPC_CONNECT_CONNECTING:
		state_text = ("连接中");
		break;
	case IPC_CONNECT_OK:
		state_text = ("连接成功");
		break;
	case IPC_CONNECT_FAILCONNECT:
		state_text = ("连接失败");
		break;
	case IPC_CONNECT_DISCONNECT:
		state_text = ("断开连接");
		break;
	case IPC_CONNECT_RECONNECT:
		state_text = ("重新连接");
		break;
	case IPC_CONNECT_AUTHOK:
		state_text = ("登录成功");
		break;
	case IPC_CONNECT_FAILAUTH:
		state_text = ("验证失败");
		break;
	case IPC_CONNECT_UNKNOW:
		state_text = ("无法识别连接情况");
		break;
	}
	UserOperationRecording("Session Layer","CONNECT",(CHAR*)state_text.c_str()) ;
}

INT CVideoWnd::GetStreamID()
{
	return m_stream_Id ;
}
void CVideoWnd::OnMove(int x, int y)
{
    __super::OnMove(x, y);

    Refresh() ;
    // TODO: 在此处添加消息处理程序代码
}

void CVideoWnd::OnSize(UINT nType, int cx, int cy)
{
    __super::OnSize(nType, cx, cy);

    Refresh() ;
    // TODO: 在此处添加消息处理程序代码
}

void CVideoWnd::OnMoving(UINT fwSide, LPRECT pRect)
{
    __super::OnMoving(fwSide, pRect);

    Refresh() ;
    // TODO: 在此处添加消息处理程序代码
}

BOOL CVideoWnd::setFocusMode(int nMode)
{
	int	nResult	= ipcSetConfig(m_hSdkHandle,IPC_VIDEO_AF_ENABLE,m_stream_Id,(CHAR*)&nMode) ;
	if (nResult < 0)
	{
		return FALSE ;
	}	
	return TRUE;
}

BOOL CVideoWnd::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default
	int iMultiple = zDelta/120;
	iMultiple = abs(iMultiple);
	if(zDelta > 0)
	{
		static BOOL ctrl_start_stop = FALSE ;

		Ptz_zoom(1,ctrl_start_stop,100,100) ;

		ctrl_start_stop=!ctrl_start_stop ;
		SetTimer(TIMER_ZOOM, 100*iMultiple, NULL);
	}
	else if(zDelta < 0)
	{
		static BOOL ctrl_start_stop = FALSE ;

		Ptz_zoom(0,ctrl_start_stop,100,100) ;

		ctrl_start_stop=!ctrl_start_stop ;
		SetTimer(TIMER_ZOOM, 100*iMultiple, NULL);
	}
	Invalidate(TRUE);
	return __super::OnMouseWheel(nFlags, zDelta, pt);
}

void CVideoWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetFocus();
	__super::OnLButtonDown(nFlags, point);

}

void CVideoWnd::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch(nIDEvent)
	{
	case TIMER_ZOOM:
		KillTimer(TIMER_ZOOM);
		Ptz_zoom(1,TRUE,0,0) ;

		break;
	default:
		break;
	}

	__super::OnTimer(nIDEvent);
}

void  CVideoWnd::SetSliderCtrl()
{
	m_pFrame->m_sliderSharDegree.SetPos(0);
	m_pFrame->SetDlgItemText(IDC_STATIC_SHARPEN_DEGREE,_T("0%"));
	m_pFrame->m_bStartSharpen = FALSE;
}