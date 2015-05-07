#ifndef _UPDATESEVICE_VIEW_DLG_H_
#define _UPDATESEVICE_VIEW_DLG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogViewDlg dialog
#include "resource.h"

#include <vector>

class CUpdateSeviceDlg : public CDialog
{
public:

    CUpdateSeviceDlg(CWnd* pParent = NULL);

    enum { IDD = IDD_DIALOG_UPDATE };
public:
	bool IsStartUpdateService();

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    virtual BOOL OnInitDialog();

    virtual void OnOK();

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedStart();
    afx_msg void OnBnClickedStop();
private:
    int m_SevicePort ;
	bool m_bStartUpdateService;
public:
	afx_msg void OnBnClickedUpdate();
};

#endif //_UPDATESEVICE_VIEW_DLG_H_
