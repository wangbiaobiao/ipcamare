// LoginDlg.cpp : implementation file
//

#include "stdafx.h"

#include "gmplayerdemo.h"

#include "TemplateDlg.h"

#include "client_camera_protocol.h"

#include<bitset>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTemplateDlg dialog


CTemplateDlg::CTemplateDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTemplateDlg::IDD, pParent)
{
    XSTACK() ;

    m_PortStatus = 0;
    m_PortValues = 0;
    m_RecTime = 0;
    m_PresetIndex = 0;
    m_PresetHome = 0;
    m_PresetTime = 0;

}


void CTemplateDlg::DoDataExchange(CDataExchange* pDX)
{
    XSTACK() ;

    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CTemplateDlg)
    //DDX_Control(pDX, IDC_LIST_USER_LOG, m_listLogView);
    //}}AFX_DATA_MAP
    DDX_Text(pDX,IDC_EDIT_PORT_STATUS_1,m_PortStatus);
//    DDV_MinMaxLong(pDX, m_PortStatus, 0, 0xffffffff);
    DDX_Text(pDX,IDC_EDIT_PORT_VALUE_1,m_PortValues);
//    DDV_MinMaxLong(pDX, m_PortValues, 0, 0xffffffff);

    DDX_Control(pDX, IDC_COMBO_MOTIONDETECT, m_MDetect);


    DDX_Text(pDX, IDC_EDIT_MAIL_LIST, m_strMailLists);
    DDV_MaxChars(pDX, m_strMailLists, 160);

    DDX_Text(pDX, IDC_EDIT_MAIL_SUBJECT, m_strMailSubject);
    DDV_MaxChars(pDX, m_strMailSubject, 160);

    DDX_Text(pDX, IDC_EDIT_MAIL_CONTENT, m_strMailContect);
    DDV_MaxChars(pDX, m_strMailContect, 160);


    m_RecTime = 1 ;
    DDX_Text(pDX,IDC_EDIT_REC_TIME,m_RecTime);
    DDV_MinMaxLong(pDX, m_RecTime, 1, 3600);

    DDX_Control(pDX, IDC_COMBO_REC_LOCATION, m_RecLocationID);

    DDX_Text(pDX, IDC_EDIT_REC_PATH, m_strRecPath);
    DDV_MaxChars(pDX, m_strRecPath, 256);

    
    DDX_Text(pDX,IDC_EDIT_PRESET_IDX,m_PresetIndex);
    DDV_MinMaxLong(pDX, m_PresetIndex, 0, 9);
    DDX_Text(pDX,IDC_EDIT_PRESET_HOME,m_PresetHome);
    DDV_MinMaxLong(pDX, m_PresetHome, 0, 1);
    DDX_Text(pDX,IDC_EDIT_PRESET_STAYTIME,m_PresetTime);
//    DDV_MinMaxLong(pDX, m_PresetTime, 1, 0xffffffff);
    

}


BEGIN_MESSAGE_MAP(CTemplateDlg, CDialog)
    //{{AFX_MSG_MAP(CTemplateDlg)
    //}}AFX_MSG_MAP
    //ON_BN_CLICKED(IDOK, &CTemplateDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDC_BUTTON_TRIGGER_SELECTED, &CTemplateDlg::OnBnClickedButtonTriggerSelected)
    ON_BN_CLICKED(IDC_CHECK_PS_0, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_1, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_2, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_3, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_4, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_5, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_6, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_7, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_8, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_9, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_10, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_11, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_12, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_13, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_14, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_15, &CTemplateDlg::OnBnClickedCheckPs)

    ON_BN_CLICKED(IDC_CHECK_PS_16, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_17, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_18, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_19, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_20, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_21, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_22, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_23, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_24, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_25, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_26, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_27, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_28, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_29, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_30, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_31, &CTemplateDlg::OnBnClickedCheckPs)
    ON_BN_CLICKED(IDC_CHECK_PS_SWITCH, &CTemplateDlg::OnBnClickedCheckPs)
    

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemplateDlg message handlers


BOOL CTemplateDlg::OnInitDialog() 
{
    XSTACK() ;

    CDialog::OnInitDialog();

    DWORD lCurSel = 0 ;
    lCurSel = m_RecLocationID.AddString("RECORD_FILELOCATION_NONE");
    m_RecLocationID.SetItemData(lCurSel,RECORD_FILELOCATION_NONE);

    lCurSel = m_RecLocationID.AddString("RECORD_FILELOCATION_FTP");
    m_RecLocationID.SetItemData(lCurSel,RECORD_FILELOCATION_FTP);

    lCurSel = m_RecLocationID.AddString("RECORD_FILELOCATION_SDCARD");
    m_RecLocationID.SetItemData(lCurSel,RECORD_FILELOCATION_SDCARD);

//     lCurSel = m_RecLocationID.AddString("RECORD_FILELOCATION_HARDDISK");
//     m_RecLocationID.SetItemData(lCurSel,RECORD_FILELOCATION_HARDDISK);
// 
//     lCurSel = m_MDetect.AddString("EVENT_MONTIONDETECTION_NONE");
//     m_MDetect.SetItemData(lCurSel,EVENT_MONTIONDETECTION_NONE);
// 
//     lCurSel = m_MDetect.AddString("EVENT_MONTIONDETECTION_START");
//     m_MDetect.SetItemData(lCurSel,EVENT_MONTIONDETECTION_START);
// 
//     lCurSel = m_MDetect.AddString("EVENT_MONTIONDETECTION_END");
//     m_MDetect.SetItemData(lCurSel,EVENT_MONTIONDETECTION_END);
// 
//     lCurSel = m_MDetect.AddString("EVENT_MONTIONDETECTION_CHANGE");
//     m_MDetect.SetItemData(lCurSel,EVENT_MONTIONDETECTION_CHANGE);    

    DisableAll() ;
    return TRUE;  // return TRUE unless you set the focus to a control
}

void CTemplateDlg::OnOK() 
{
    XSTACK() ;
    UpdateData() ;

    m_md = m_MDetect.GetItemData(m_MDetect.GetCurSel()) ;

    m_locationid = m_RecLocationID.GetItemData(m_RecLocationID.GetCurSel()); ;
    CDialog::OnOK();
}


void CTemplateDlg::OnBnClickedButtonTriggerSelected()
{

    //IDD_DIALOG_TEMPLATE
}

VOID CTemplateDlg::GetInputPort( DWORD& status_,DWORD& values_)
{
    status_=        m_PortStatus ;
    values_=        m_PortValues ;
}
VOID CTemplateDlg::GetMontionDetect(DWORD& md_)
{
    md_ = m_md ;
}
VOID CTemplateDlg::GetMail(CString& maillist_,CString& mailsubject_,CString& mailcontent_) 
{
    maillist_ = m_strMailLists;
    
    mailsubject_ = m_strMailSubject;
    
    mailcontent_ = m_strMailContect;

}
VOID CTemplateDlg::GetRecord(DWORD& timecount_,DWORD& locationid_,CString& path_) 
{
    timecount_ =        m_RecTime ;

    locationid_ =        m_locationid ;

    path_ =        m_strRecPath;

}
VOID CTemplateDlg::GetPreset(DWORD& index_,DWORD& home_,DWORD& time_) 
{

    index_ =m_PresetIndex ;

    home_ =m_PresetHome ;

    time_ =m_PresetTime ;

}
VOID CTemplateDlg::DisableAll()
{
    ::EnableWindow(GetDlgItem(IDC_EDIT_PORT_STATUS_1)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_EDIT_PORT_VALUE_1    )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_COMBO_MOTIONDETECT)->m_hWnd,FALSE) ;

    ::EnableWindow(GetDlgItem(IDC_EDIT_MAIL_LIST)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_EDIT_MAIL_SUBJECT)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_EDIT_MAIL_CONTENT)->m_hWnd,FALSE) ;

    ::EnableWindow(GetDlgItem(IDC_EDIT_REC_TIME)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_COMBO_REC_LOCATION)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_EDIT_REC_PATH)->m_hWnd,FALSE) ;

    ::EnableWindow(GetDlgItem(IDC_EDIT_PRESET_IDX)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_EDIT_PRESET_HOME)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_EDIT_PRESET_STAYTIME)->m_hWnd,FALSE) ;


    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_0 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_1 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_2 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_3 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_4 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_5 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_6 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_7 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_8 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_9 )->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_10)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_11)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_12)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_13)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_14)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_15)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_16)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_17)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_18)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_19)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_20)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_21)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_22)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_23)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_24)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_25)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_26)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_27)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_28)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_29)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_30)->m_hWnd,FALSE) ;
    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_31)->m_hWnd,FALSE) ;

    ::EnableWindow(GetDlgItem(IDC_CHECK_PS_SWITCH)->m_hWnd,FALSE) ;

    for( int i = 0 ;i< m_VisibleList.size();i++)
    {
        ::EnableWindow(GetDlgItem(m_VisibleList[i])->m_hWnd,TRUE) ;
    }

}

VOID CTemplateDlg::EnableEvent(const DWORD& et_) 
{
//     switch(et_)
//     {
//     case EVENT_TRIGGERTYPE_INPUTPORT                :
//         {
//             m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PORT_STATUS_1) ;
//             m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PORT_VALUE_1) ;
// 
//             for(DWORD i = IDC_CHECK_PS_0;i<IDC_CHECK_PS_0+31;i++ )
//             {
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_0 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_1 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_2 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_3 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_4 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_5 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_6 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_7 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_8 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_9 ) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_10) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_11) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_12) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_13) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_14) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_15) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_16) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_17) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_18) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_19) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_20) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_21) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_22) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_23) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_24) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_25) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_26) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_27) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_28) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_29) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_30) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_31) ;
//                 m_VisibleList.insert(m_VisibleList.end(),IDC_CHECK_PS_SWITCH) ;
//                 
// 
//             }
// 
//         }break;
//     case EVENT_TRIGGERTYPE_MONTIONDETECTION            :
//         {
//             m_VisibleList.insert( m_VisibleList.end(),IDC_COMBO_MOTIONDETECT ) ;
//         }break;
//     };
}

VOID CTemplateDlg::EnableAction(const DWORD& at_) 
{
    switch(at_)
    {
    case  EVENT_ACTIONTYPE_NOTIFY_EMAIL   :
        {
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_MAIL_LIST) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_MAIL_SUBJECT) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_MAIL_CONTENT) ;
        }break ;
    case  EVENT_ACTIONTYPE_RECORD         :
        {
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_REC_TIME) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_COMBO_REC_LOCATION) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_REC_PATH) ;
        }break ;
    case  EVENT_ACTIONTYPE_PORTOUTPUT     :
        {
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PORT_STATUS_1) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PORT_VALUE_1) ;
        }break ;
    case  EVENT_ACTIONTYPE_DPTZ           :

    case  EVENT_ACTIONTYPE_PTZ            :
        {
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PRESET_IDX) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PRESET_HOME) ;
            m_VisibleList.insert(m_VisibleList.end(),IDC_EDIT_PRESET_STAYTIME) ;
        }break ;
    };
}
void CTemplateDlg::OnBnClickedCheckPs()
{
    std::bitset<32> bin32s ;
    bin32s[0] = ((CButton*) GetDlgItem(IDC_CHECK_PS_0 ))-> GetCheck();
    bin32s[1] = ((CButton*) GetDlgItem(IDC_CHECK_PS_1 ))-> GetCheck();
    bin32s[2] = ((CButton*) GetDlgItem(IDC_CHECK_PS_2 ))-> GetCheck();
    bin32s[3] = ((CButton*) GetDlgItem(IDC_CHECK_PS_3 ))-> GetCheck();
    bin32s[4] = ((CButton*) GetDlgItem(IDC_CHECK_PS_4 ))-> GetCheck();
    bin32s[5] = ((CButton*) GetDlgItem(IDC_CHECK_PS_5 ))-> GetCheck();
    bin32s[6] = ((CButton*) GetDlgItem(IDC_CHECK_PS_6 ))-> GetCheck();
    bin32s[7] = ((CButton*) GetDlgItem(IDC_CHECK_PS_7 ))-> GetCheck();
    bin32s[8] = ((CButton*) GetDlgItem(IDC_CHECK_PS_8 ))-> GetCheck();
    bin32s[9] = ((CButton*) GetDlgItem(IDC_CHECK_PS_9 ))-> GetCheck();
    bin32s[10] = ((CButton*)GetDlgItem(IDC_CHECK_PS_10))-> GetCheck();
    bin32s[11] = ((CButton*)GetDlgItem(IDC_CHECK_PS_11))-> GetCheck();
    bin32s[12] = ((CButton*)GetDlgItem(IDC_CHECK_PS_12))-> GetCheck();
    bin32s[13] = ((CButton*)GetDlgItem(IDC_CHECK_PS_13))-> GetCheck();
    bin32s[14] = ((CButton*)GetDlgItem(IDC_CHECK_PS_14))-> GetCheck();
    bin32s[15] = ((CButton*)GetDlgItem(IDC_CHECK_PS_15))-> GetCheck();
    bin32s[16] = ((CButton*)GetDlgItem(IDC_CHECK_PS_16))-> GetCheck();
    bin32s[17] = ((CButton*)GetDlgItem(IDC_CHECK_PS_17))-> GetCheck();
    bin32s[18] = ((CButton*)GetDlgItem(IDC_CHECK_PS_18))-> GetCheck();
    bin32s[19] = ((CButton*)GetDlgItem(IDC_CHECK_PS_19))-> GetCheck();
    bin32s[20] = ((CButton*)GetDlgItem(IDC_CHECK_PS_20))-> GetCheck();
    bin32s[21] = ((CButton*)GetDlgItem(IDC_CHECK_PS_21))-> GetCheck();
    bin32s[22] = ((CButton*)GetDlgItem(IDC_CHECK_PS_22))-> GetCheck();
    bin32s[23] = ((CButton*)GetDlgItem(IDC_CHECK_PS_23))-> GetCheck();
    bin32s[24] = ((CButton*)GetDlgItem(IDC_CHECK_PS_24))-> GetCheck();
    bin32s[25] = ((CButton*)GetDlgItem(IDC_CHECK_PS_25))-> GetCheck();
    bin32s[26] = ((CButton*)GetDlgItem(IDC_CHECK_PS_26))-> GetCheck();
    bin32s[27] = ((CButton*)GetDlgItem(IDC_CHECK_PS_27))-> GetCheck();
    bin32s[28] = ((CButton*)GetDlgItem(IDC_CHECK_PS_28))-> GetCheck();
    bin32s[29] = ((CButton*)GetDlgItem(IDC_CHECK_PS_29))-> GetCheck();
    bin32s[30] = ((CButton*)GetDlgItem(IDC_CHECK_PS_30))-> GetCheck();
    bin32s[31] = ((CButton*)GetDlgItem(IDC_CHECK_PS_31))-> GetCheck();

    DWORD BIT32 = bin32s.to_ulong() ;

    if ( ((CButton*)GetDlgItem(IDC_CHECK_PS_SWITCH))-> GetCheck() )
    {
        m_PortStatus = BIT32 ;
    } else{
        m_PortValues = BIT32 ;
    }
    UpdateData(FALSE)    ;
}
