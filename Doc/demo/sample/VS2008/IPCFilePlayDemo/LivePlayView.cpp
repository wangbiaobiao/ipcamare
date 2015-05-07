// LivePlayView.cpp : 实现文件
//

#include "stdafx.h"
#include "LivePlayView.h"

IMPLEMENT_DYNAMIC(CLivePlayView, CWnd)

CLivePlayView::CLivePlayView()
{
	m_Playhanle = NULL ;
}

CLivePlayView::~CLivePlayView()
{
}


BEGIN_MESSAGE_MAP(CLivePlayView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

void CLivePlayView::OnPaint()
{

	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

	CRect    rc;

	GetClientRect(&rc);

	CPen        pen;

	pen.CreatePen(PS_SOLID,5,RGB(255,0,0));

	CPen* pOldPen = dc.SelectObject(&pen) ;

	rc.InflateRect(20,20);
	dc.Rectangle(&rc) ;

	if ( !m_Playhanle )
	{
		CBrush        brush;

		brush.CreateSolidBrush(RGB(32,32,32));
		dc.FillRect(&rc, &brush);
	}

	dc.SelectObject(pOldPen) ;
}

BOOL CLivePlayView::Create( CRect rc,CWnd *pParentWnd )
{

	//m_rc      = rc;

	//m_pParent = pParentWnd;

	DWORD    dwStyle = WS_CHILD | WS_CLIPCHILDREN | WS_VISIBLE ;//| WS_BORDER;

	return CWnd::Create(NULL,NULL,dwStyle,rc,pParentWnd,0XFFFFFFFF,NULL);
}

void CLivePlayView::StratPlay(LPVOID playhandle_)
{
	StopPlay();

	m_Playhanle = playhandle_ ;
}

void CLivePlayView::StopPlay()
{
	if ( NULL == m_Playhanle )
	{
		return;
	}

	m_Playhanle = NULL ;
}



// CLivePlayView 消息处理程序



void CLivePlayView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  当显示视频窗口大小发生变化时 必须调用ipcSetDisplayRect来重新设置显示区域
	CRect rc ;
	GetClientRect(&rc) ;

	if (m_Playhanle != NULL)
	{
		RECT rcPlay ;
		rcPlay.left		= rc.left;
		rcPlay.top		= rc.top;
		rcPlay.right	= rc.Width() ;
		rcPlay.bottom	= rc.Height() ;		
	}
}

void CLivePlayView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString sDebug;

	sDebug.Format(_T("key= %c"),nChar);

	CWnd* p = this->GetParent();
	if( p != NULL)
	  p->SetWindowText(sDebug);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLivePlayView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString sDebug;

	sDebug.Format(_T("mouse x= %d y=%d"),point.x,point.y);

	CWnd* p = this->GetParent();
	if( p != NULL)
	  p->SetWindowText(sDebug);

	CWnd::OnMouseMove(nFlags, point);
}

void CLivePlayView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CWnd::OnLButtonDown(nFlags, point);
}

void CLivePlayView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CWnd::OnLButtonUp(nFlags, point);
}
