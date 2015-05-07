#ifndef _I_EVENT_CALL_BACK_H_
#define _I_EVENT_CALL_BACK_H_
//#include "GIPCamera.h"
class ICallBackInterface
{

public:
	virtual BOOL  InitializeCallBack()=0;   //初始化回调

	virtual BOOL  UnInitializeCallBack() = 0;//反初始化

	virtual void  OnContextResult(LPVOID lpConText) = 0;// 处理数据
};
#endif