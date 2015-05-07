// AudioDialog.cpp : 实现文件
//

#include "stdafx.h"

#include "IPCSdkFuncDemo.h"

#include "AudioDialog.h"

#include "IPCSdkFuncDemoDlg.h"

IMPLEMENT_DYNAMIC(CAudioDialog, CDialog)

CAudioDialog::CAudioDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAudioDialog::IDD, pParent),_lpOwner((CIPCPlayerDemoDlg*)pParent)
    , mVolume(_T(""))
    , m_CurDeviceString(_T(""))
{
    memset( &m_lpAudioDevice,0,sizeof(m_lpAudioDevice) ) ;
}

CAudioDialog::~CAudioDialog()
{
}

void CAudioDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, mVolume);
    DDX_Control(pDX, IDC_COMBO_AUDIO_FMT, m_AudioFMT);
    DDX_Control(pDX, IDC_COMBO_DEVICE, m_AudioDeviceList);
    DDX_Text(pDX, IDC_EDIT_CURDEVICE, m_CurDeviceString);
}


BEGIN_MESSAGE_MAP(CAudioDialog, CDialog)
    ON_BN_CLICKED(IDC_BUTTON1, &CAudioDialog::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CAudioDialog::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &CAudioDialog::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON_MUTE, &CAudioDialog::OnBnClickedButtonMute)
    ON_BN_CLICKED(IDC_BUTTON4, &CAudioDialog::OnBnClickedButton4)
    ON_WM_SHOWWINDOW()
    ON_CBN_SELCHANGE(IDC_COMBO_AUDIO_FMT, &CAudioDialog::OnCbnSelchangeComboAudioFmt)
    ON_CBN_SELCHANGE(IDC_COMBO_DEVICE, &CAudioDialog::OnCbnSelchangeComboDevice)
    ON_BN_CLICKED(IDC_BUTTON5, &CAudioDialog::OnBnClickedButton5)
END_MESSAGE_MAP()


// CAudioDialog 消息处理程序

void CAudioDialog::OnBnClickedButton1()
{
     GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
    _lpOwner->AudioOption() ;
    if(0 != _lpOwner->AudioOpen())
	{
       GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	}
}

void CAudioDialog::OnBnClickedButton2()
{
    _lpOwner->AudioClose();
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
}

void CAudioDialog::OnBnClickedButton3()
{
    _lpOwner->AudioOption() ;
}

void CAudioDialog::OnBnClickedButtonMute()
{
    static int iVolume = 50 ;

    iVolume = iVolume%100 ;

    _lpOwner->AudioVolume(iVolume) ;

    iVolume+=10 ;

}

void CAudioDialog::OnBnClickedButton4()
{
    int i = _lpOwner->GetAudioVolume() ;

    char szTemp[32]={0} ;

    sprintf( szTemp,"%d",i) ;

    mVolume = szTemp ;

    UpdateData(FALSE) ;
}

void CAudioDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);

    DWORD lCurSel = 0 ;

    lCurSel = m_AudioFMT.AddString("711") ;

    m_AudioFMT.SetItemData(lCurSel, 1) ;

    //lCurSel = m_AudioFMT.AddString("amr") ;

    //m_AudioFMT.SetItemData(lCurSel, 0) ;
 
    INT iCount = 0 ;

    _lpOwner->AudioEnumDevice(&m_lpAudioDevice[0],&iCount) ;

    for(int i = 0 ;i< iCount ;i++ )
    {
        INT idx = m_AudioDeviceList.AddString(m_lpAudioDevice[i].sDevName) ;

        m_AudioDeviceList.SetItemData(idx,m_lpAudioDevice[i].iId) ;
    }
       
}

void CAudioDialog::OnCbnSelchangeComboAudioFmt()
{
    DWORD lCurSel1 = m_AudioFMT.GetCurSel() ;

    dwAudioFmt = m_AudioFMT.GetItemData(lCurSel1) ;

    _lpOwner->SetAudioFormat(dwAudioFmt) ;
}

void CAudioDialog::OnCbnSelchangeComboDevice()
{
    m_CurrentDevice.iId = m_AudioDeviceList.GetItemData(m_AudioDeviceList.GetCurSel()) ;

    for (int i = 0;i<8;i++)
    {
        if ( m_lpAudioDevice[i].iId == m_CurrentDevice.iId )
        {
            m_CurrentDevice = m_lpAudioDevice[i] ;
            break;
        }
    }

    _lpOwner->SetAudioDevice(m_CurrentDevice) ;
}

void CAudioDialog::OnBnClickedButton5()
{
    _lpOwner->GetAudioDeviceName(m_CurDeviceString) ;
    UpdateData(FALSE) ;
}
