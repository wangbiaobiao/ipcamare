// CruiseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IPCSdkFuncDemo.h"
#include "CruiseDlg.h"
#include "CruisePoint.h"

// CCruiseDlg 对话框

IMPLEMENT_DYNAMIC(CCruiseDlg, CDialog)

CCruiseDlg::CCruiseDlg(ipcHandle device,CWnd* pParent /*=NULL*/)
	: CDialog(CCruiseDlg::IDD, pParent)
{
	m_hDevice = device;

	memset(m_all,0,sizeof(m_all));
	m_count=0;
}

CCruiseDlg::~CCruiseDlg()
{
}

void CCruiseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CRUISE, m_cmb_cruise);
	DDX_Control(pDX, IDC_CHECK_CRUISE, m_cruise_enable);
	DDX_Control(pDX, IDC_LIST_PRESTS, m_list_presets);
	DDX_Control(pDX, IDC_EDIT_CRUISE_NAME, m_cruisename);
}


BEGIN_MESSAGE_MAP(CCruiseDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADD, &CCruiseDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, &CCruiseDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDOK, &CCruiseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_RUN, &CCruiseDlg::OnBnClickedBtnRun)
	ON_BN_CLICKED(IDC_BTN_STOP, &CCruiseDlg::OnBnClickedBtnStop)
	ON_CBN_SELCHANGE(IDC_COMBO_CRUISE, &CCruiseDlg::OnCbnSelchangeComboCruise)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CCruiseDlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_CLRAEALL, &CCruiseDlg::OnBnClickedBtnClraeall)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CCruiseDlg::OnBnClickedBtnModify)
END_MESSAGE_MAP()


// CCruiseDlg 消息处理程序

void CCruiseDlg::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}

	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		int nCruiseId = m_cmb_cruise.GetItemData(sel);
		vector<int> tmp;
		for(int i=1; i<=32; i++)
		{
			int nCount = m_list_presets.GetCount();
			int m=0;
			for(; m<nCount;m++)
			{
				int presetid = m_list_presets.GetItemData(m);
				if( i == presetid) break;//find 
			}
			if(m == nCount)//not in use
			{
				tmp.push_back(i);
			}
		}

		CCruisePoint  dlg;
		dlg.m_tmpPresets = tmp;

		if( IDOK == dlg.DoModal())
		{
			int speed= dlg.m_speed;
			int staytime= dlg.m_staytime;
			IPC_PRESET_CRUISE_POINT_t  pt={0};
			pt.iPresetIdx = dlg.m_curId;
			pt.iStaySec = staytime;
			pt.iMoveSpeed = speed;
			if( ipcFAULT == ipcSetPTZCruise(m_hDevice,IPC_SET_PRESET_CRUISE,nCruiseId,&pt) )
			{
				MessageBox(_T("修改巡航点信息失败"));
				return ;
			}
			OnCbnSelchangeComboCruise();
		}
		 
	}

}

void CCruiseDlg::OnBnClickedBtnDel()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}

	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		int nCruiseId = m_cmb_cruise.GetItemData(sel);

		int nSel = m_list_presets.GetCurSel();
		if( nSel >= 0)
		{
			int presetid = m_list_presets.GetItemData(nSel);

			IPC_PRESET_CRUISE_POINT_t  pt={0};
			pt.iPresetIdx = presetid;
			pt.iStaySec = 0;
			pt.iMoveSpeed = 0;

			if( ipcFAULT == ipcSetPTZCruise(m_hDevice,IPC_DEL_PRESET_CRUISE,nCruiseId,&pt) )
			{
				MessageBox(_T("删除巡航点信息失败"));
				return ;
			}
			OnCbnSelchangeComboCruise();
		}
	}

}

void CCruiseDlg::OnBnClickedBtnModify()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}

	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		int nCruiseId = m_cmb_cruise.GetItemData(sel);

		int nSel = m_list_presets.GetCurSel();
		if( nSel >= 0)
		{
			 int presetid = m_list_presets.GetItemData(nSel);
			 vector<int> tmp;
			 tmp.push_back(presetid);
			 CCruisePoint  dlg;
			 dlg.m_tmpPresets = tmp;

			 if( IDOK == dlg.DoModal())
			 {
				 int speed= dlg.m_speed;
				 int staytime= dlg.m_staytime;
				 IPC_PRESET_CRUISE_POINT_t  pt={0};
				 pt.iPresetIdx = presetid;
				 pt.iStaySec = staytime;
				 pt.iMoveSpeed = speed;
				 if( ipcFAULT == ipcSetPTZCruise(m_hDevice,IPC_SET_PRESET_CRUISE,nCruiseId,&pt) )
				 {
					 MessageBox(_T("修改巡航点信息失败"));
					 return ;
				 }
				OnCbnSelchangeComboCruise();
			 }
		}
	}
}
 

void CCruiseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}

	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		INT id = m_cmb_cruise.GetItemData(sel);
		 
		m_all[sel].iEnable=m_cruise_enable.GetCheck();
		CString sName;
		m_cruisename.GetWindowText(sName);
		strcpy(m_all[sel].name,(LPCSTR)sName);

		if( ipcFAULT == ipcSetPTZCruise(m_hDevice,IPC_SET_CRUISE_ALLDATA,id,&m_all[sel]) )
		{
			MessageBox(_T("设置巡航路径失败"));
		}
	}

}

void CCruiseDlg::OnBnClickedBtnRun()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}

	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		INT id = m_cmb_cruise.GetItemData(sel);
		if( ipcFAULT == ipcSetPTZCruiseControl(m_hDevice,id,1))
		{
			MessageBox(_T("启动巡航失败！"));
		}
	}

}

void CCruiseDlg::OnBnClickedBtnStop()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}
	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		INT id = m_cmb_cruise.GetItemData(sel);
		if( ipcFAULT == ipcSetPTZCruiseControl(m_hDevice,id,0))
		{
			MessageBox(_T("停止巡航失败！"));
		}
	}
}

BOOL CCruiseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitData();

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CCruiseDlg::InitData()
{
	memset(m_all,0,sizeof(m_all));
	m_count=0;

	m_cmb_cruise.ResetContent();
	m_cmb_cruise.SetTopIndex(0);
	if(m_hDevice != 0)
	{
		INT count=0;
		
		if( ipcSUCCESS == ipcGetPTZCruise(m_hDevice,0,m_all,&m_count) )
		{
			for(int i=0; i < m_count;i++)
			{
				CString sText;
				sText.Format(_T("%d"),m_all[i].id);
				INT item = m_cmb_cruise.AddString(sText);
				m_cmb_cruise.SetItemData(item,m_all[i].id);
			}
			m_cmb_cruise.SetCurSel(0);
		}
		else
		{
			MessageBox(_T("获取巡航路径信息失败！"));
		}
	}
	else
	{
			MessageBox(_T("请先登录设备！"));
	}
	OnCbnSelchangeComboCruise();
}
void CCruiseDlg::OnCbnSelchangeComboCruise()
{
	// TODO: 在此添加控件通知处理程序代码

	int sel = m_cmb_cruise.GetCurSel();

	if( sel >= 0)
	{
		//获取巡航路径信息
		INT cruiseid = m_cmb_cruise.GetItemData(sel);
		INT count =0;
		if( ipcFAULT == ipcGetPTZCruise(m_hDevice,cruiseid,&m_all[sel],&count) )
		{
			MessageBox(_T("获取巡航路径信息失败"));
			return ;
		}
		m_cmb_cruise.SetItemData(sel,m_all[sel].id);
		m_cruise_enable.SetCheck(m_all[sel].iEnable);
		m_cruisename.SetWindowText(m_all[sel].name);

		m_list_presets.ResetContent();
		m_list_presets.SetTopIndex(0);
		for(int i=0 ;i< m_all[sel].iCount; i++)
		{
			CString sText;
			sText.Format(_T("id=%d,speed=%d,staytime=%d"),m_all[sel].point[i].iPresetIdx,m_all[sel].point[i].iMoveSpeed,m_all[sel].point[i].iStaySec);
			int item = m_list_presets.AddString(sText);
			m_list_presets.SetItemData(item,m_all[sel].point[i].iPresetIdx);
		}
	}
}

void CCruiseDlg::OnBnClickedBtnClear()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}
	int sel = m_cmb_cruise.GetCurSel();
	if( sel >= 0)
	{
		INT id = m_cmb_cruise.GetItemData(sel);
		if( ipcFAULT == ipcSetPTZCruise(m_hDevice,IPC_CLEAR_CRUISE,id,NULL))
		{
			MessageBox(_T("清空巡航路径失败！"));
			return ;
		}
	}

	OnCbnSelchangeComboCruise();
}

void CCruiseDlg::OnBnClickedBtnClraeall()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_hDevice ==0 ) 
	{
		MessageBox(_T("请先登录设备"));
		return ;
	}
	if( ipcFAULT == ipcSetPTZCruise(m_hDevice,IPC_CLEAR_ALL_CRUISE,0,NULL))
	{
		MessageBox(_T("清空全部巡航路径失败！"));
	}
	
	InitData();

}
