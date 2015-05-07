// TransDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "TransDlg.h"


// CTransDlg 对话框

IMPLEMENT_DYNAMIC(CTransDlg, CDialog)

CTransDlg::CTransDlg(CIPCPlayerDemoDlg* Owner,CWnd* pParent /*=NULL*/)
	: CDialog(CTransDlg::IDD, pParent),m_Owner(Owner),m_StPrprtDlg(Owner),m_GtPrprtDlg(Owner)
{

}

CTransDlg::~CTransDlg()
{
}

BOOL CTransDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_TbCtrl.InsertItem(0,"SET");  
    m_TbCtrl.InsertItem(1,"GET");  
    m_TbCtrl.SetCurSel(0);//设置选中标签


    CRect rs;
    m_TbCtrl.GetClientRect(&rs);
    rs.top+=20;
    rs.bottom-=1;
    rs.left+=1;
    rs.right-=2;




    m_StPrprtDlg.Create (IDD_DIALOG_PTZ_TAB_SET,&m_TbCtrl);
    m_GtPrprtDlg.Create (IDD_DIALOG_PTZ_TAB_GET,&m_TbCtrl);



    m_StPrprtDlg.MoveWindow(&rs);

    m_GtPrprtDlg.MoveWindow(&rs);


    m_StPrprtDlg.ShowWindow(true);

    m_GtPrprtDlg.ShowWindow(false);

    return TRUE ;

}
void CTransDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB_GET_SET, m_TbCtrl);
}


BEGIN_MESSAGE_MAP(CTransDlg, CDialog)

    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_GET_SET, &CTransDlg::OnTcnSelchangeTabGetSet)
    ON_BN_CLICKED(IDCANCEL, &CTransDlg::OnBnClickedCancel)
    ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CTransDlg 消息处理程序

void CTransDlg::OnTcnSelchangeTabGetSet(NMHDR *pNMHDR, LRESULT *pResult)
{
    switch(m_TbCtrl.GetCurSel())
    {
    case 0:
        m_StPrprtDlg.ShowWindow(true);

        m_GtPrprtDlg.ShowWindow(false);

        break;
    case 1:

        m_StPrprtDlg.ShowWindow(false);

        m_GtPrprtDlg.ShowWindow(true);

        break;
    }

    *pResult = 0;
}

void CTransDlg::OnBnClickedCancel()
{
    // TODO: 在此添加控件通知处理程序代码
    OnCancel();
}

void CTransDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);


}
