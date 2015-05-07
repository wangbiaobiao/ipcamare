#ifndef _I_EVENT_CALLBACK_REGISTER_H_
#define _I_EVENT_CALLBACK_REGISTER_H_
#include "IEventCallBack.h"
class ICallBackInterfaceSink
{

public:

	virtual void  RegisterEventCallBack(ICallBackInterface* pCallback) = 0 ;
	virtual void  RegisterSystemSettingCallBack(ICallBackInterface* pCallback)= 0;
	virtual void  RegisterCameraConfigCallBack(ICallBackInterface* pCallback) = 0;

};

#endif
