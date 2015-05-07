#if !defined(AFX_VIDEOWND_H__F78EF2F0_B84C_478E_A84C_FBB3D0158075__INCLUDED_)
#define AFX_VIDEOWND_H__F78EF2F0_B84C_478E_A84C_FBB3D0158075__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVideoWnd window
#include <afxmt.h>

#include <list>

#include <string>

#include "IPCamera.h"

#include "StringDlg.h"

#include "IEventCallBackRegister.h"

class CIPCPlayerDemoDlg ;

class CVideoWnd : public CWnd, public ICallBackInterfaceSink
{
    friend void WINAPI playerdemo_Message_CallBack(LPVOID handle,INT cmd_,LPVOID data_,LPVOID pFrame) ;//sdk的异步通信回调函数

    LPVOID                m_hSdkHandle ;                                                            //sdk的设备句柄
    
    LPVOID                m_hSdkPlayer ;                                                            //sdk的流句柄

    long                m_lWndState;                                                            //最大化
//    bool                m_bSignal;

    long                m_lIndex ;                                                                //最大化的窗口在数组中的编号
    
    CWnd                *m_pParent;                                                                //父窗口
    
    CRect                m_rc;                                                                    //窗口矩形区

    //dptz
    INT                    m_dptz_zoom ;                                                            //dptz缩放的数值

    INT                    m_stream_Id ;                                                            //当前的stream id

    BOOL                    m_IsPTZMode ;                                                           //是否为物理云台模式

	CString					m_strIP;																//当前设备ip

    //current window 
    CIPCPlayerDemoDlg* m_pFrame ;                                                                //父窗口的实例

    TEST_PLAYER_LOGININFO m_LoginInfo;                                                                  //登录信息

// Construction
public:
    static CONST INT MAX_OSD_BUFFER_SIZEE = 3*1024*1024 ;                                              //osd结构最大支持的长度
    CVideoWnd();

    void SetMainFrame(CIPCPlayerDemoDlg* pFrame) ;                                                //设置父窗口实例

    VOID UserOperationRecording(const TCHAR* cmd_,const TCHAR* state_,const TCHAR* reason_) ;    //操作留痕 

public:
	virtual void RegisterEventCallBack(ICallBackInterface* pCallback);	//event dlg 注册回调
	virtual void  RegisterSystemSettingCallBack(ICallBackInterface* pCallback);//system dlg 注册回调
	virtual void  RegisterCameraConfigCallBack(ICallBackInterface* pCallback) ;

private:
	ICallBackInterface*							m_pEventCallBack ;	
	ICallBackInterface*							m_pSystemSettingCallBack ;
	ICallBackInterface*							m_pCameraConfigCallBack ;
	
// Attributes
public:
    BOOL                m_bSnapShot;                                                            //是否在截取图片

    CCriticalSection    m_csSnapShot;                                                            //图片截取用的锁

private:
	LPIPC_OSDPARAM	m_posdInfo;																	//显示文字图片信息
	bool		m_bShowLogoPicture;																//是否显示logo图片
	bool		m_bShowLogoText;																//是否显示logo标题
	LOGFONT		m_ftLogoText;																	//loge标题文字属性

protected:
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);                                        //菜单事件响应

    void OnCommandResult(IPC_COMMAND_CONTEXT* context) ;                                            //收到设备通讯指令

    void OnGetCameraConfigResult(IPC_COMMAND_CONTEXT* context) ;                                        //收到读取设备信息的返回内容

    void OnSetCameraConfigResult(IPC_COMMAND_CONTEXT* context) ;                                        //收到设置设备指令的应答（是否成功）

    void OnEventResult(IPC_EVENT_CONTEXT* context) ;                                                //事件指令

    void OnSystemSettingResult(IPC_COMMAND_CONTEXT* context) ;                                    //系统设置指令
	
	void OnCameraConfig(IPC_COMMAND_CONTEXT* context) ;												//摄像机属性指令

	void OnConnectStateChange(INT state)	;													//设备连接状态变化情况
    //}}AFX_VIRTUAL

// Implementation
public:
    BOOL Create(long lIndex,CRect rc,CWnd *pParentWnd);
    virtual ~CVideoWnd();

    // Generated message map functions
protected:
    //{{AFX_MSG(CVideoWnd)
    //窗口控制部分
    afx_msg void OnPaint();

    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

    afx_msg void OnDestroy();

    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

    afx_msg void OnLButtonUp(UINT nFlags, CPoint point) ;
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
private:
	bool LoadLogoPicture(LPCTSTR lpPath, BYTE** pData, long* lSize);

public:
    BOOL Open(TEST_PLAYER_LOGININFO info);                                                                                //开启视频

    void Close();                                                                                                        //关闭视频

    BOOL Refresh() ;

    VOID Dptz_focus(BOOL bInOut,BOOL bStartStop) ;                                                                       //数字云台对焦

    VOID Dptz_zoom(int step);                                                                                            //数字云台缩放

    VOID Dptz_left(int step);                                                                                            //数字云台左

    VOID Dptz_right(int step);                                                                                            //数字云台右

    VOID Dptz_up(int step);                                                                                                //数字云台上

    VOID Dptz_down(int step);                                                                                            //数字云台下

    VOID Dptz_home() ;                                                                                                    //数字云台起始位置

    VOID Dptz_set_preset(int num,const CHAR* preset_name) ;                                                                //数字云台设置预置位

    VOID Dptz_clear_preset(int num) ;                                                                                    //数字云台清除指定预置位

    VOID Dptz_clearall_preset() ;                                                                                        //数字云台清除所有预置位

    VOID Dptz_goto_preset(int num) ;                                                                                    //数字云台移动到指定预置位

    VOID Ptz_focus(BOOL zoom_in_out,BOOL ctrl_start_stop,int hspeed,int vspeed) ;                                        //物理云台焦距

    VOID Ptz_zoom(BOOL zoom_in_out,BOOL ctrl_start_stop,int hspeed,int vspeed);                                            //物理云台缩放

    VOID Ptz_left(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //物理云台左

    VOID Ptz_right(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //物理云台右

    VOID Ptz_up(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //物理云台上

    VOID Ptz_down(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //物理云台下

	VOID Ptz_leftup(BOOL ctrl_start_stop,int hspeed,int vspeed);														//物理云台左上
	VOID Ptz_leftdown(BOOL ctrl_start_stop,int hspeed,int vspeed);														//物理云台左下
	VOID Ptz_rightup(BOOL ctrl_start_stop,int hspeed,int vspeed);														//物理云台右上
	VOID Ptz_rightdown(BOOL ctrl_start_stop,int hspeed,int vspeed);														//物理云台右下
	VOID Ptz_rotaion(int hspeed,int vspeed);																			//水平旋转
    VOID Ptz_home(int hspeed,int vspeed) ;                                                                                //物理云台起始位置

    VOID Ptz_set_preset(int num,const CHAR* preset_name) ;                                                                //物理云台预置位设置

    VOID Ptz_clear_preset(int num) ;                                                                                    //物理云台清除指定预置位

    VOID Ptz_clearall_preset() ;                                                                                        //物理云台清除所有预置位

    VOID Ptz_goto_preset(int num,int hspeed,int vspeed) ;                                                                //物理云台焦距移动到指定预置位

    BOOL Property_Set_INT(DWORD cmd,const DWORD& val) ;                                                                    //设置数值型属性

    BOOL Property_Get_INT(DWORD cmd,DWORD& val) ;                                                                        //读取数值型属性

    BOOL Property_Set_STR(DWORD cmd,const char* val) ;                                                                    //设置字符型属性

    BOOL Property_Get_STR(DWORD cmd,char* val) ;                                                                        //读取字符型属性

	INT StartImageSharpen(float amount=1.2f);
	INT ChangeSharpenDegree(float amount);
	INT StopImageSharpen();

    ipcHandle GetSdkHandle() ;

    playHandle GetPlayHandle() ;
	
    INT GetStreamID() ;

    VOID SetPTZMode(BOOL bIsPTZMode) ;                                                                                  //设置是否为物理云台

    BOOL GetPTZMode() ;                                                                                                 //获取云台模式 ，物理/数字
	void SetSliderCtrl();

    afx_msg void OnMove(int x, int y);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	BOOL setFocusMode(int nMode);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOWND_H__F78EF2F0_B84C_478E_A84C_FBB3D0158075__INCLUDED_)
