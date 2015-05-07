// PTZTransPropSet.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "PTZTransPropSet.h"


// CPTZTransPropSet 对话框

IMPLEMENT_DYNAMIC(CPTZTransPropSet, CDialog)

CPTZTransPropSet::CPTZTransPropSet(CIPCPlayerDemoDlg* Owner,CWnd* pParent /*=NULL*/)
	: CDialog(CPTZTransPropSet::IDD, pParent),m_Owner(Owner)
{

}

CPTZTransPropSet::~CPTZTransPropSet()
{
}

BOOL CPTZTransPropSet::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    //
    INT idx = 0 ;

    idx = m_ctrl_protocol.AddString("PROTOCOL_D") ;

    m_ctrl_protocol.SetItemData(idx,1) ;

    idx = m_ctrl_protocol.AddString("PROTOCOL_P") ;

    m_ctrl_protocol.SetItemData(idx,2) ;

    m_ctrl_protocol.SetCurSel(0) ;
    //
    CHAR szVal[128]={0} ;
    for( int i = 0 ;i<256; i++ )
    {
        sprintf(szVal,"%d",i) ;

        idx = m_ctrl_address.AddString(szVal) ;

        m_ctrl_address.SetItemData(idx,i) ;
    }
    m_ctrl_address.SetCurSel(0) ;
    //
    idx = m_ctrl_baudrate.AddString("300") ;
    m_ctrl_baudrate.SetItemData(idx,0) ;
    idx = m_ctrl_baudrate.AddString("1200") ;
    m_ctrl_baudrate.SetItemData(idx,1) ;
    idx = m_ctrl_baudrate.AddString("2400") ;
    m_ctrl_baudrate.SetItemData(idx,2) ;
    idx = m_ctrl_baudrate.AddString("4800") ;
    m_ctrl_baudrate.SetItemData(idx,3) ;
    idx = m_ctrl_baudrate.AddString("9600") ;
    m_ctrl_baudrate.SetItemData(idx,4) ;
    idx = m_ctrl_baudrate.AddString("19200") ;
    m_ctrl_baudrate.SetItemData(idx,5) ;
    idx = m_ctrl_baudrate.AddString("38400") ;
    m_ctrl_baudrate.SetItemData(idx,6) ;
    idx = m_ctrl_baudrate.AddString("115200") ;
    m_ctrl_baudrate.SetItemData(idx,7) ;
    idx = m_ctrl_baudrate.AddString("460800") ;
    m_ctrl_baudrate.SetItemData(idx,8) ;
    idx = m_ctrl_baudrate.AddString("921600") ;
    m_ctrl_baudrate.SetItemData(idx,9) ;
    m_ctrl_baudrate.SetCurSel(0) ;
    //
    idx = m_ctrl_databit.AddString("7") ;
    m_ctrl_databit.SetItemData(idx,7) ;
    idx = m_ctrl_databit.AddString("8") ;
    m_ctrl_databit.SetItemData(idx,8) ;
    m_ctrl_databit.SetCurSel(0) ;
    //
    idx = m_ctrl_stopbit.AddString("1") ;
    m_ctrl_stopbit.SetItemData(idx,1) ;
    idx = m_ctrl_stopbit.AddString("2") ;
    m_ctrl_stopbit.SetItemData(idx,2) ;
    m_ctrl_stopbit.SetCurSel(0) ;
    //
    idx = m_ctrl_parity.AddString("PARITY_NONE") ;
    m_ctrl_parity.SetItemData(idx,0) ;
    idx = m_ctrl_parity.AddString("PARITY_ODD") ;
    m_ctrl_parity.SetItemData(idx,1) ;
    idx = m_ctrl_parity.AddString("PARITY_EVEN") ;
    m_ctrl_parity.SetItemData(idx,2) ;
    m_ctrl_parity.SetCurSel(0) ;

    return TRUE ;
}

void CPTZTransPropSet::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_PROTOCOL, m_ctrl_protocol);
    DDX_Control(pDX, IDC_COMBO_ADDRESS, m_ctrl_address);
    DDX_Control(pDX, IDC_COMBO_BRATE, m_ctrl_baudrate);
    DDX_Control(pDX, IDC_COMBO_DBIT, m_ctrl_databit);
    DDX_Control(pDX, IDC_COMBO_PRIORTY, m_ctrl_parity);
    DDX_Control(pDX, IDC_COMBO_SBIT, m_ctrl_stopbit);
}


BEGIN_MESSAGE_MAP(CPTZTransPropSet, CDialog)
    ON_BN_CLICKED(IDOK, &CPTZTransPropSet::OnBnClickedOk)
    ON_BN_CLICKED(IDC_BUTTON1, &CPTZTransPropSet::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPTZTransPropSet 消息处理程序

void CPTZTransPropSet::OnBnClickedOk()
{
    DWORD protocol = m_ctrl_protocol.GetItemData(m_ctrl_protocol.GetCurSel()) ;
    DWORD address = m_ctrl_address.GetItemData(m_ctrl_address.GetCurSel()) ;
    DWORD baudrate = m_ctrl_baudrate.GetItemData(m_ctrl_baudrate.GetCurSel()) ;
    DWORD databit = m_ctrl_databit.GetItemData(m_ctrl_databit.GetCurSel()) ;
    DWORD stopbit = m_ctrl_stopbit.GetItemData(m_ctrl_stopbit.GetCurSel()) ;
    DWORD parity = m_ctrl_parity.GetItemData(m_ctrl_parity.GetCurSel()) ;

    m_Owner->TransPropSet(protocol,address,baudrate,databit,stopbit,parity) ;
}

void CPTZTransPropSet::OnBnClickedButton1()
{
    int ilen = 1024*10+444 ;

    unsigned char* lpData = new unsigned char[ilen] ;

    for ( int i = 0 ;i< ilen ;i++ )
    {
        lpData[i]=('0'+(i%10)) ;
    }

    m_Owner->TransDataSend(lpData,ilen) ;

    delete[] lpData ;
}
