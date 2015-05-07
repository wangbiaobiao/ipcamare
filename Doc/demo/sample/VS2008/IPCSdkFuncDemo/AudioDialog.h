#pragma once
#include "afxwin.h"
#include "IPCamera.h"

// CAudioDialog 对话框
class CIPCPlayerDemoDlg ;

class CAudioDialog : public CDialog
{
	DECLARE_DYNAMIC(CAudioDialog)

public:
	CAudioDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAudioDialog();

// 对话框数据
	enum { IDD = IDD_AUDIODIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();

    CIPCPlayerDemoDlg* _lpOwner ;
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButtonMute();
    afx_msg void OnBnClickedButton4();
    CString mVolume;
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

    CComboBox m_AudioFMT;

    DWORD dwAudioFmt ;

    IPC_AudioDevice m_lpAudioDevice[8] ;

    IPC_AudioDevice  m_CurrentDevice ;

    afx_msg void OnCbnSelchangeComboAudioFmt();
    CComboBox m_AudioDeviceList;
    afx_msg void OnCbnSelchangeComboDevice();
    afx_msg void OnBnClickedButton5();
    CString m_CurDeviceString;
};
