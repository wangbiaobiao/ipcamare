// IPCPlayerDemoDlg.h : header file
//

#if !defined(AFX_IPCPlayerDEMODLG_H__7D287E43_E884_4067_B670_02D8DF395893__INCLUDED_)
#define AFX_IPCPlayerDEMODLG_H__7D287E43_E884_4067_B670_02D8DF395893__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIPCPlayerDemoDlg dialog
#include "IPCSdkFuncDemo.h"
#include "VideoWnd.h"
#include "UserLogMgr.h"
#include <vector>
#include <string>
#include "afxwin.h"
class CIPCPlayerDemoDlg : public CDialog
{
    long                m_lIndex;
    long                m_lState;
    CVideoWnd            m_VideoWnd[IPC_VIDEOWND_MAX];
    CRect                m_rcWnd[IPC_VIDEOWND_MAX];

    HWND                m_SelectedWindow ;

    BOOL        m_IsDptz ;
    double        m_HSpeed_Scale ;
    double        m_VSpeed_Scale ;
    INT            m_HSpeed ;
    INT            m_VSpeed ;
    BOOL        m_IsSavingJPEG ;
	

    CUserLogMgr    m_UserLogMgr ;                        //用户操作留痕管理
public:
    static const INT WM_AUDIO_DISCONNECTION = WM_USER+100; 
    //CONTROL
    CComboBox    m_ctrlPresetList;
    
    CString        m_RecordingPath ;
    bool		m_bStartUpdateServer;
    BOOL    SnapshotToJpeg(){return m_IsSavingJPEG;} ;

    DWORD dwAudioFmt ;
private:
    BOOL DivideWnd(int nNum);
public:
    void SetCurrentWnd(HWND hWnd) ;

    VOID Init_PTZ_Range(INT hMin,INT hMax,INT vMin,INT vMax) ;

    //用户操作属性和ptz之前需要选中一路视频
    CVideoWnd* GetSelectedWindowClass() ;

    CUserLogMgr& GetUserLogMgr() ;

// Construction
public:

    LRESULT OnLogSaving(WPARAM wParam, LPARAM lParam) ;

    LRESULT OnVideoWndMove(WPARAM wParam,LPARAM lParam);
    CIPCPlayerDemoDlg(CWnd* pParent = NULL);    // standard constructor

// Dialog Data
    //{{AFX_DATA(CIPCPlayerDemoDlg)
    enum { IDD = IDD_SDK_DEMO_DIALOG };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CIPCPlayerDemoDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    //{{AFX_MSG(CIPCPlayerDemoDlg)
    virtual BOOL OnInitDialog();

    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);

    afx_msg void OnPaint();

    afx_msg HCURSOR OnQueryDragIcon();

    afx_msg void OnDestroy();

    virtual void OnCancel();

    afx_msg void OnSize(UINT nType, int cx, int cy);

    afx_msg void OnMove(int x, int y);

    afx_msg void OnHScroll(UINT, UINT, CScrollBar*);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

    CString GetSpecifyFileVersion(LPCTSTR lpszFileName) ;

public:
    afx_msg void OnBnClickedPtzZoomIn();

    afx_msg void OnBnClickedPtzZoomOut();

    afx_msg void OnBnClickedButtonUp();

    afx_msg void OnBnClickedButtonDown();

    afx_msg void OnBnClickedButtonLeft();

    afx_msg void OnBnClickedButtonRight();

    afx_msg void OnBnClickedPtzHome();

    afx_msg void OnBnClickedButtonSetpreset();

    afx_msg void OnBnClickedButtonGoto();

    afx_msg void OnBnClickedPropertySet();

    afx_msg void OnBnClickedPropertyGet();

    afx_msg void OnCheckBoxSelected() ;

    afx_msg void OnBnClickedPtzFocusIn();

    afx_msg void OnBnClickedPtzFocusOut();

    afx_msg void OnBnClickedUserLogBtn();

    afx_msg void OnBnClickedButtonSystemsetting();
    afx_msg void OnBnClickedButtonUpdate();

	afx_msg void OnBnClickedButtonEventpanel();
	afx_msg void OnBnClickedButtonShowActivex();

	void OnTestSetEvent(CVideoWnd* pWnd, int nActiveType);
	void OnTestGetEvent(CVideoWnd* pWnd);
	void OnTestEnableEvent(CVideoWnd* pWnd) ;
	void OnTestIsEnableEvent(CVideoWnd* pWnd) ;
	void OnTestSetMDEvent(CVideoWnd* pWnd);
	void OnTestGetMDEvent(CVideoWnd* pWnd);
	void OnTestPropertySet(CVideoWnd* pWnd);
	void OnTestPropertyGet(CVideoWnd* pWnd) ;
	void OnTestSystemSet(CVideoWnd* pWnd) ;
	void OnTestSystemGet(CVideoWnd* pWnd) ;
public:
	BOOL		m_bReceiveSet;
	
    friend INT WINAPI MyAudioCallback(ipcHandle,INT type,const unsigned char* data,INT size,LPVOID context) ;
	afx_msg void OnBnClickedButtonConfigSetting();
	afx_msg void OnBnClickedButtonPlan();
    afx_msg void OnBnClickedButtonAudio();
    int AudioOpen(void);
    int AudioClose(void);
    int AudioEnumDevice(IPC_AudioDevice* device,int* size);
    int AudioOption(void);
    int AudioVolume(int vol) ;
    int GetAudioVolume() ;
    LRESULT OnSDKDisconnection(WPARAM wParam, LPARAM lParam) ;
    void CloseAllVideoWnd() ;
    int SetAudioFormat(INT fmt) ;
    int SetAudioDevice(IPC_AudioDevice ad) ;
    int GetAudioDeviceName(CString& str) ;
    afx_msg void OnBnClickedButtonPtzOpt();
    int TransPropSet(DWORD protocol, DWORD address, DWORD baudrate, DWORD databit, DWORD stopbit, DWORD parity);
    int TransPropGet(DWORD* protocol, DWORD* address, DWORD* baudrate, DWORD* databit, DWORD* stopbit, DWORD* parity);
    int TransDataSend(unsigned char* data, int len);
    int GetAllPresetInfo();
	int GetPtzPositionInfo(int* x, int* y, int* z, int* xSpeed,int* ySpeed);
	int AutoJudgeProSharpen();
    CString m_EdtPresetName;
	afx_msg void OnBnClickedBtnLeftborder();
	afx_msg void OnBnClickedBtnRightborder();
	afx_msg void OnBnClickedStartLinrscan();
	afx_msg void OnBnClickedStopLinescan();
	CComboBox m_cmb_point;
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedButtonLeftup();
	afx_msg void OnBnClickedButtonRightup();
	afx_msg void OnBnClickedButtonLeftdown();
	afx_msg void OnBnClickedButtonRightdown();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButtonTestTriggerAlarmOutput();
	int m_occupation;
	CComboBox m_cmbFocus;
	CSliderCtrl m_sliderSharDegree;
	float  m_fSharDegree;
	bool m_bStartSharpen;
	afx_msg void OnCbnSelchangeComboFocus();
	afx_msg void OnBnClickedRadioAuto();
	afx_msg void OnBnClickedRadioManual();
	afx_msg void OnBnClickedButton3dPositionTakeEffect();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int m_3D_X;
	int m_3D_Y;
	int m_3D_Width;
	int m_3D_Height;
public:
	afx_msg void OnBnClickedButtonPtzPositionParam();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCPlayerDEMODLG_H__7D287E43_E884_4067_B670_02D8DF395893__INCLUDED_)
