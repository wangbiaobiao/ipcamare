#pragma once
#include "ActiveXCtl.h"

// CActiveDlg �Ի���

class CActiveDlg : public CDialog
{
	DECLARE_DYNAMIC(CActiveDlg)

public:
	CActiveDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CActiveDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ACTIVEX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CActiveXCtl		m_ActiveXCtl;
};
