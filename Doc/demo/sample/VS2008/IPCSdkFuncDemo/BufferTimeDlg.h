#pragma once

#include "resource.h"

// CBufferTimeDlg �Ի���

class CBufferTimeDlg : public CDialog
{
	DECLARE_DYNAMIC(CBufferTimeDlg)

public:
	CBufferTimeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBufferTimeDlg();

// �Ի�������
	enum { IDD = IDD_DLG_BUFFERTIME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nTime;
	afx_msg void OnBnClickedOk();
};
