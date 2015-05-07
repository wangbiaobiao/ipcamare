#pragma once


// CLivePlayView

class CLivePlayView : public CWnd
{
	DECLARE_DYNAMIC(CLivePlayView)

public:
	CLivePlayView();
	virtual ~CLivePlayView();

	BOOL Create(CRect rc,CWnd *pParentWnd);
	void StratPlay(LPVOID playhandle_) ;
	void StopPlay() ;
private:
	LPVOID    m_Playhanle;
	CPoint	  m_ptLeftTop;
	
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
public:

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


