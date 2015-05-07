// PTZTransPropGet.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "PTZTransPropGet.h"


// CPTZTransPropGet 对话框

IMPLEMENT_DYNAMIC(CPTZTransPropGet, CDialog)

CPTZTransPropGet::CPTZTransPropGet(CIPCPlayerDemoDlg* Owner,CWnd* pParent /*=NULL*/)
	: CDialog(CPTZTransPropGet::IDD, pParent),m_Owner(Owner)
    , m_protocol(_T(""))
    , m_address(_T(""))
    , m_baudrate(_T(""))
    , m_databit(_T(""))
    , m_parity(_T(""))
    , m_stopbit(_T(""))
{

}

CPTZTransPropGet::~CPTZTransPropGet()
{
}
BOOL CPTZTransPropGet::OnInitDialog()
{
    CDialog::OnInitDialog();

    return TRUE ;
}
void CPTZTransPropGet::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_PROTOCOL, m_protocol);
    DDX_Text(pDX, IDC_EDIT_ADDRESS, m_address);
    DDX_Text(pDX, IDC_EDIT_BRATE, m_baudrate);
    DDX_Text(pDX, IDC_EDIT_DBIT, m_databit);
    DDX_Text(pDX, IDC_EDIT_PRIORITY, m_parity);
    DDX_Text(pDX, IDC_EDIT_SBIT, m_stopbit);
}


BEGIN_MESSAGE_MAP(CPTZTransPropGet, CDialog)
    ON_BN_CLICKED(IDOK, &CPTZTransPropGet::OnBnClickedOk)
    ON_BN_CLICKED(IDC_BUTTON1, &CPTZTransPropGet::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPTZTransPropGet 消息处理程序

void CPTZTransPropGet::OnBnClickedOk()
{
    DWORD protocol ;
    DWORD address ;
    DWORD baudrate ;
    DWORD databit ;
    DWORD stopbit ;
    DWORD parity ;
    m_Owner->TransPropGet(&protocol,&address,&baudrate,&databit,&stopbit,&parity) ;

    if(protocol==1)
    {
        m_protocol = "PROTOCOL_D" ;
    }
    if(protocol==2)
    {
        m_protocol = "PROTOCOL_P" ;
    }

    CHAR temp[128]={0} ;
    itoa(address,temp,10) ;
    m_address = temp ;

    //prop校验
    DWORD dwBaudRate = 0 ;

    switch(baudrate)
    {
    case 0:
        dwBaudRate =300 ;
        break;
    case 1:
        dwBaudRate =1200;
        break;
    case 2:
        dwBaudRate =2400;
        break;
    case 3:
        dwBaudRate =4800;
        break;
    case 4:
        dwBaudRate =9600;
        break;
    case 5:
        dwBaudRate =19200;
        break;
    case 6:
        dwBaudRate =38400;
        break;
    case 7:
        dwBaudRate =115200;
        break;
    case 8:
        dwBaudRate =460800;
        break;
    case 9:
        dwBaudRate =921600;
        break;
    };
    itoa(dwBaudRate,temp,10) ;
    m_baudrate = temp ;

    itoa(databit,temp,10) ;
    m_databit = temp ;

    itoa(stopbit,temp,10) ;
    m_stopbit = temp ;

    itoa(parity,temp,10) ;
    m_parity = temp ;

    UpdateData(FALSE) ;
}

void CPTZTransPropGet::OnBnClickedButton1()
{
    m_Owner->GetAllPresetInfo() ;
}
