// PtzPositionParamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PtzPositionParamDlg.h"


// CPtzPositionParamDlg dialog

IMPLEMENT_DYNAMIC(CPtzPositionParamDlg, CDialog)

CPtzPositionParamDlg::CPtzPositionParamDlg(CIPCPlayerDemoDlg* Owner,CWnd* pParent /*=NULL*/)
	: CDialog(CPtzPositionParamDlg::IDD, pParent),m_Owner(Owner)
{

}

CPtzPositionParamDlg::~CPtzPositionParamDlg()
{
}

void CPtzPositionParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PTZ_X, m_x);
	DDX_Text(pDX, IDC_EDIT_PTZ_Y, m_y);
	DDX_Text(pDX, IDC_EDIT_PTZ_Z, m_z);
	DDX_Text(pDX, IDC_EDIT_PTZ_X_SPEED, m_xSpeed);
	DDX_Text(pDX, IDC_EDIT_PTZ_Y_SPEED, m_ySpeed);
}


BEGIN_MESSAGE_MAP(CPtzPositionParamDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_GET, &CPtzPositionParamDlg::OnBnClickedButtonGet)
END_MESSAGE_MAP()


// CPtzPositionParamDlg message handlers

void CPtzPositionParamDlg::OnBnClickedButtonGet()
{
	// TODO: Add your control notification handler code here
	int x ;
	int y ;
	int z ;
	int xSpeed;
	int ySpeed ;
	CHAR temp[128]={0} ;
	if(0 == m_Owner->GetPtzPositionInfo(&x,&y,&z,&xSpeed,&ySpeed))
	{
		itoa(x,temp,10) ;
		m_x = temp ;

		itoa(y,temp,10) ;
		m_y = temp ;

		itoa(z,temp,10) ;
		m_z = temp ;

		itoa(xSpeed,temp,10) ;
		m_xSpeed = temp ;

		itoa(ySpeed,temp,10) ;
		m_ySpeed = temp ;

	}
	UpdateData(FALSE) ;
	
}
