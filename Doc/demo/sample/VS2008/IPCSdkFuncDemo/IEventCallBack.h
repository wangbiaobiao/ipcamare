#ifndef _I_EVENT_CALL_BACK_H_
#define _I_EVENT_CALL_BACK_H_
//#include "GIPCamera.h"
class ICallBackInterface
{

public:
	virtual BOOL  InitializeCallBack()=0;   //��ʼ���ص�

	virtual BOOL  UnInitializeCallBack() = 0;//����ʼ��

	virtual void  OnContextResult(LPVOID lpConText) = 0;// ��������
};
#endif