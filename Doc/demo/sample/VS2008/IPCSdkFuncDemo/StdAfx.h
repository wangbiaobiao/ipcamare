// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__5F7D1E9D_9CB6_4F1A_BEFF_D0DB2B1DD522__INCLUDED_)
#define AFX_STDAFX_H__5F7D1E9D_9CB6_4F1A_BEFF_D0DB2B1DD522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>        // MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>            // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "WinCmdDef.h"


//#include "trace_interface.h"
//#include <afxdisp.h>


//#define XSTACK TSTACK
//
//#define XTRACE(...) MOD_TRACE(MOD_1,__VA_ARGS__)
//
//#define XDEBUG(...) MOD_DEBUG(MOD_1,__VA_ARGS__)
//
//#define XINFO(...)    MOD_INFO(MOD_1,__VA_ARGS__) 
//
//#define XWARN(...)    MOD_WARN(MOD_1,__VA_ARGS__) 
//
//#define XERROR(...) MOD_ERROR(MOD_1,__VA_ARGS__)
//
//#define XFATAL(...) MOD_FATAL(MOD_1,__VA_ARGS__)


#define XTRACE(...) ((VOID*)0)

#define XDEBUG(...) ((VOID*)0)

#define XINFO(...)  ((VOID*)0)

#define XWARN(...)  ((VOID*)0)

#define XERROR(...) ((VOID*)0)

#define XFATAL(...) ((VOID*)0)

#define        IPC_VIDEOWND_MAX            9

#define        IPC_LAYOUT_OFFSET        200

typedef struct
{
    char    szHostIP[50];            //服务器IP
    long    lHostPort;                //服务器端口
    char    szUser[50];                //用户名
    char    szPsw[50];                //密码
    char    szNO[50];                //用户编号
    long    lStreamID;                //流ID，该参数保留，备以后扩展时使用
}TEST_PLAYER_LOGININFO,*LPTEST_PLAYER_LOGININFO;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5F7D1E9D_9CB6_4F1A_BEFF_D0DB2B1DD522__INCLUDED_)
