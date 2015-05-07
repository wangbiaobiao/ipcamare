// IPCFilePlayDemoDlg.h : header file
//

#if !defined(AFX_IPCFILEPLAYDEMODLG_H__FC08D22F_F880_46E0_9574_5D66594EA0B2__INCLUDED_)
#define AFX_IPCFILEPLAYDEMODLG_H__FC08D22F_F880_46E0_9574_5D66594EA0B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <list>
#include "LivePlayView.h"
#include "RegionDlg2.h"
#include "IPCPlayer.h"
#include "afxcmn.h"

#define WM_SLIDERCHANGEMSG ( WM_USER + 8 )
#define	WM_CLOSECUTTHREAD  ( WM_USER + 10 )
/////////////////////////////////////////////////////////////////////////////
// CIPCFilePlayDemoDlg dialog

class CIPCFilePlayDemoDlg : public CDialog
{
// Construction
public:
	CIPCFilePlayDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIPCFilePlayDemoDlg)
	enum { IDD = IDD_IPCFILEPLAYDEMO_DIALOG };
	CSliderCtrl	m_ctrlSliderProgress;
	CComboBox	m_Speed;
	//CStatic		m_staTime ;
	//}}AFX_DATA

	CLivePlayView		m_PlayViewWnd ;					//��ʾ��Ƶ����
	
	bool				m_bOpenFile ;					//�Ƿ��Ѵ�¼���ļ�
	
	std::list<float>	m_sPeedList ;					//���������б�
	
	CString				m_strFilePathName ;				//���򿪵��ļ�ȫ·��
	
 
	int					m_nTotalTime ;					//����¼���ļ��Ĳ�����ʱ��
	
	bool				m_bPlayFile ;					//�Ƿ�ʼ�����ļ�

	CRegionDlg2			*m_pRegionDlg;					//������ʾ����

 
	void	EnableAllBtn(bool bEnable) ;				//ȫ��ť״̬
	
	void	EnablePlayBtn(bool bEnable) ;				//������ذ�ť״̬
	
	void	InitAvFilePlay() ;							//��ʼ����������Դ��ע����ػص�
	
	void	UnInitAvFilePlay() ;						//����ʼ��
		
	bool	OpenFile() ;								//��¼���ļ�
	
	void	CloseFile() ;								//�ر�¼���ļ�

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCFilePlayDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIPCFilePlayDemoDlg)
	virtual BOOL OnInitDialog();
	
	afx_msg void OnDestroy();
	
	afx_msg void OnPaint();

	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnButtonPlay();
	
	afx_msg void OnButtonStop();
	
	afx_msg void OnButtonPause();

	afx_msg void OnButtonPrev();
	
	afx_msg void OnButtonNext();
	
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	
	afx_msg void OnCbnSelchangeCombo1();
	
	//afx_msg void OnHScroll(UINT, UINT, CScrollBar*);

	afx_msg void OnFileOpen();

	afx_msg void OnFileClose();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg LRESULT OnSliderChange(WPARAM wParam, LPARAM lParam);

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	BOOL		m_bSelfSetPos;
	BOOL		m_bSliderCapture;
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_volume;
	afx_msg void OnNMReleasedcaptureSliderVolume(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTRBNThumbPosChangingSliderVolume(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderVolume(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnCapture();
	int m_iFmPos;
	afx_msg void OnBnClickedBtnSetpos();
	afx_msg void OnBnClickedBtnReplay();
	afx_msg void OnBnClickedBtnGetrect();
	afx_msg void OnBnClickedBtnSetrect();
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
	afx_msg void OnBnClickedBtnForward();
	afx_msg void OnBnClickedBtnBackward();
	int m_backward;
	int m_forward;
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedBtnCapturetobuff();
	afx_msg void OnBnClickedBtnCut();
	afx_msg void OnBnClickedCheckMute();
	afx_msg void OnBnClickedButtonRangzoom();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCFILEPLAYDEMODLG_H__FC08D22F_F880_46E0_9574_5D66594EA0B2__INCLUDED_)
