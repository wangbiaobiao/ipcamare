#ifndef _TEMPLATE_VIEW_DLG_H_
#define _TEMPLATE_VIEW_DLG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogViewDlg dialog
#include "resource.h"

#include <vector>

class CTemplateDlg : public CDialog
{
public:

    CTemplateDlg(CWnd* pParent = NULL);

    enum { IDD = IDD_DIALOG_TEMPLATE };

    CComboBox    m_MDetect;
    DWORD        m_PortStatus ;
    DWORD        m_PortValues ;

    CString        m_strMailLists;
    CString        m_strMailSubject;
    CString        m_strMailContect;

    DWORD        m_RecTime ;
    CComboBox    m_RecLocationID ;
    CString        m_strRecPath;

    DWORD        m_PresetIndex ;
    DWORD        m_PresetHome ;
    DWORD        m_PresetTime ;

    DWORD        m_md ;
    DWORD        m_locationid ;

    std::vector<DWORD> m_VisibleList ;

    VOID GetInputPort( DWORD& status_,DWORD& values_) ;
    VOID GetMontionDetect(DWORD& md_) ;
    VOID GetMail(CString& maillist_,CString& mailsubject_,CString& mailcontent_) ;
    VOID GetRecord(DWORD& timecount_,DWORD& locationid_,CString& path_) ;
    VOID GetPreset(DWORD& index_,DWORD& home_,DWORD& time_) ;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    virtual BOOL OnInitDialog();

    virtual void OnOK();

    DECLARE_MESSAGE_MAP()

public:

    afx_msg void OnBnClickedButtonTriggerSelected();

    VOID DisableAll() ;

    VOID EnableEvent(const DWORD& et_) ;

    VOID EnableAction(const DWORD& at_) ;
    afx_msg void OnBnClickedCheckPs();
};

#endif //_TEMPLATE_VIEW_DLG_H_
