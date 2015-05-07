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
    friend void WINAPI playerdemo_Message_CallBack(LPVOID handle,INT cmd_,LPVOID data_,LPVOID pFrame) ;//sdk���첽ͨ�Żص�����

    LPVOID                m_hSdkHandle ;                                                            //sdk���豸���
    
    LPVOID                m_hSdkPlayer ;                                                            //sdk�������

    long                m_lWndState;                                                            //���
//    bool                m_bSignal;

    long                m_lIndex ;                                                                //��󻯵Ĵ����������еı��
    
    CWnd                *m_pParent;                                                                //������
    
    CRect                m_rc;                                                                    //���ھ�����

    //dptz
    INT                    m_dptz_zoom ;                                                            //dptz���ŵ���ֵ

    INT                    m_stream_Id ;                                                            //��ǰ��stream id

    BOOL                    m_IsPTZMode ;                                                           //�Ƿ�Ϊ������̨ģʽ

	CString					m_strIP;																//��ǰ�豸ip

    //current window 
    CIPCPlayerDemoDlg* m_pFrame ;                                                                //�����ڵ�ʵ��

    TEST_PLAYER_LOGININFO m_LoginInfo;                                                                  //��¼��Ϣ

// Construction
public:
    static CONST INT MAX_OSD_BUFFER_SIZEE = 3*1024*1024 ;                                              //osd�ṹ���֧�ֵĳ���
    CVideoWnd();

    void SetMainFrame(CIPCPlayerDemoDlg* pFrame) ;                                                //���ø�����ʵ��

    VOID UserOperationRecording(const TCHAR* cmd_,const TCHAR* state_,const TCHAR* reason_) ;    //�������� 

public:
	virtual void RegisterEventCallBack(ICallBackInterface* pCallback);	//event dlg ע��ص�
	virtual void  RegisterSystemSettingCallBack(ICallBackInterface* pCallback);//system dlg ע��ص�
	virtual void  RegisterCameraConfigCallBack(ICallBackInterface* pCallback) ;

private:
	ICallBackInterface*							m_pEventCallBack ;	
	ICallBackInterface*							m_pSystemSettingCallBack ;
	ICallBackInterface*							m_pCameraConfigCallBack ;
	
// Attributes
public:
    BOOL                m_bSnapShot;                                                            //�Ƿ��ڽ�ȡͼƬ

    CCriticalSection    m_csSnapShot;                                                            //ͼƬ��ȡ�õ���

private:
	LPIPC_OSDPARAM	m_posdInfo;																	//��ʾ����ͼƬ��Ϣ
	bool		m_bShowLogoPicture;																//�Ƿ���ʾlogoͼƬ
	bool		m_bShowLogoText;																//�Ƿ���ʾlogo����
	LOGFONT		m_ftLogoText;																	//loge������������

protected:
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);                                        //�˵��¼���Ӧ

    void OnCommandResult(IPC_COMMAND_CONTEXT* context) ;                                            //�յ��豸ͨѶָ��

    void OnGetCameraConfigResult(IPC_COMMAND_CONTEXT* context) ;                                        //�յ���ȡ�豸��Ϣ�ķ�������

    void OnSetCameraConfigResult(IPC_COMMAND_CONTEXT* context) ;                                        //�յ������豸ָ���Ӧ���Ƿ�ɹ���

    void OnEventResult(IPC_EVENT_CONTEXT* context) ;                                                //�¼�ָ��

    void OnSystemSettingResult(IPC_COMMAND_CONTEXT* context) ;                                    //ϵͳ����ָ��
	
	void OnCameraConfig(IPC_COMMAND_CONTEXT* context) ;												//���������ָ��

	void OnConnectStateChange(INT state)	;													//�豸����״̬�仯���
    //}}AFX_VIRTUAL

// Implementation
public:
    BOOL Create(long lIndex,CRect rc,CWnd *pParentWnd);
    virtual ~CVideoWnd();

    // Generated message map functions
protected:
    //{{AFX_MSG(CVideoWnd)
    //���ڿ��Ʋ���
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
    BOOL Open(TEST_PLAYER_LOGININFO info);                                                                                //������Ƶ

    void Close();                                                                                                        //�ر���Ƶ

    BOOL Refresh() ;

    VOID Dptz_focus(BOOL bInOut,BOOL bStartStop) ;                                                                       //������̨�Խ�

    VOID Dptz_zoom(int step);                                                                                            //������̨����

    VOID Dptz_left(int step);                                                                                            //������̨��

    VOID Dptz_right(int step);                                                                                            //������̨��

    VOID Dptz_up(int step);                                                                                                //������̨��

    VOID Dptz_down(int step);                                                                                            //������̨��

    VOID Dptz_home() ;                                                                                                    //������̨��ʼλ��

    VOID Dptz_set_preset(int num,const CHAR* preset_name) ;                                                                //������̨����Ԥ��λ

    VOID Dptz_clear_preset(int num) ;                                                                                    //������̨���ָ��Ԥ��λ

    VOID Dptz_clearall_preset() ;                                                                                        //������̨�������Ԥ��λ

    VOID Dptz_goto_preset(int num) ;                                                                                    //������̨�ƶ���ָ��Ԥ��λ

    VOID Ptz_focus(BOOL zoom_in_out,BOOL ctrl_start_stop,int hspeed,int vspeed) ;                                        //������̨����

    VOID Ptz_zoom(BOOL zoom_in_out,BOOL ctrl_start_stop,int hspeed,int vspeed);                                            //������̨����

    VOID Ptz_left(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //������̨��

    VOID Ptz_right(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //������̨��

    VOID Ptz_up(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //������̨��

    VOID Ptz_down(BOOL ctrl_start_stop,int hspeed,int vspeed);                                                            //������̨��

	VOID Ptz_leftup(BOOL ctrl_start_stop,int hspeed,int vspeed);														//������̨����
	VOID Ptz_leftdown(BOOL ctrl_start_stop,int hspeed,int vspeed);														//������̨����
	VOID Ptz_rightup(BOOL ctrl_start_stop,int hspeed,int vspeed);														//������̨����
	VOID Ptz_rightdown(BOOL ctrl_start_stop,int hspeed,int vspeed);														//������̨����
	VOID Ptz_rotaion(int hspeed,int vspeed);																			//ˮƽ��ת
    VOID Ptz_home(int hspeed,int vspeed) ;                                                                                //������̨��ʼλ��

    VOID Ptz_set_preset(int num,const CHAR* preset_name) ;                                                                //������̨Ԥ��λ����

    VOID Ptz_clear_preset(int num) ;                                                                                    //������̨���ָ��Ԥ��λ

    VOID Ptz_clearall_preset() ;                                                                                        //������̨�������Ԥ��λ

    VOID Ptz_goto_preset(int num,int hspeed,int vspeed) ;                                                                //������̨�����ƶ���ָ��Ԥ��λ

    BOOL Property_Set_INT(DWORD cmd,const DWORD& val) ;                                                                    //������ֵ������

    BOOL Property_Get_INT(DWORD cmd,DWORD& val) ;                                                                        //��ȡ��ֵ������

    BOOL Property_Set_STR(DWORD cmd,const char* val) ;                                                                    //�����ַ�������

    BOOL Property_Get_STR(DWORD cmd,char* val) ;                                                                        //��ȡ�ַ�������

	INT StartImageSharpen(float amount=1.2f);
	INT ChangeSharpenDegree(float amount);
	INT StopImageSharpen();

    ipcHandle GetSdkHandle() ;

    playHandle GetPlayHandle() ;
	
    INT GetStreamID() ;

    VOID SetPTZMode(BOOL bIsPTZMode) ;                                                                                  //�����Ƿ�Ϊ������̨

    BOOL GetPTZMode() ;                                                                                                 //��ȡ��̨ģʽ ������/����
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
