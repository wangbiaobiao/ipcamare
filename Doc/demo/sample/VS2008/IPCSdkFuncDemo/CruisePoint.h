#pragma once

#include <vector>
using namespace std;

#include "afxwin.h"


// CCruisePoint 对话框

class CCruisePoint : public CDialog
{
	DECLARE_DYNAMIC(CCruisePoint)

public:
	CCruisePoint(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCruisePoint();

// 对话框数据
	enum { IDD = IDD_DLG_CRUISE_PRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
