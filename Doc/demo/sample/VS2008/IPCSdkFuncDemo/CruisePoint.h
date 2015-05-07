#pragma once

#include <vector>
using namespace std;

#include "afxwin.h"


// CCruisePoint �Ի���

class CCruisePoint : public CDialog
{
	DECLARE_DYNAMIC(CCruisePoint)

public:
	CCruisePoint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCruisePoint();

// �Ի�������
	enum { IDD = IDD_DLG_CRUISE_PRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CComboBox m_presets;
	int m_staytime;
	int m_speed;
	int m_curId;

	vector<int> m_tmpPresets;
	virtual BOOL OnInitDialog();
};
