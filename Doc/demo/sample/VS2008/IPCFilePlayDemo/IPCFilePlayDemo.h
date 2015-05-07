// IPCFilePlayDemo.h : main header file for the IPCFILEPLAYDEMO application
//

#if !defined(AFX_IPCFILEPLAYDEMO_H__58EF3FAA_4798_4630_A78B_F728D8FE35B2__INCLUDED_)
#define AFX_IPCFILEPLAYDEMO_H__58EF3FAA_4798_4630_A78B_F728D8FE35B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIPCFilePlayDemoApp:
// See IPCFilePlayDemo.cpp for the implementation of this class
//

class CIPCFilePlayDemoApp : public CWinApp
{
public:
	CIPCFilePlayDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCFilePlayDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIPCFilePlayDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCFILEPLAYDEMO_H__58EF3FAA_4798_4630_A78B_F728D8FE35B2__INCLUDED_)
