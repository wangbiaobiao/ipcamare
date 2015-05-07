#ifndef _H_IPC_SDKDEFINE_BACKUP_
#define _H_IPC_SDKDEFINE_BACKUP_

#include "IPCSdkDefines.h"

#define ipc_App_Config									1
#define ipc_App_Ptz										2
#define ipc_App_Event									3
#define ipc_App_SysSetting								4
#define ipc_App_Connect									5
#define ipc_App_RecordServer                            9

#define IPC_CMD_GET_PROPERTY							0x00001001
#define IPC_CMD_SET_PROPERTY							0x00001002

#define IPC_VIDEO_FPS0									(IPC_VIDEO_BASE+40)
#define IPC_VIDEO_FPS1									(IPC_VIDEO_BASE+41)
#define IPC_VIDEO_FPS2									(IPC_VIDEO_BASE+42)
#define IPC_VIDEO_FPS3									(IPC_VIDEO_BASE+43)

#define IPC_VIDEO_DEVICE_OSD							(IPC_VIDEO_BASE+44)
#define IPC_VIDEO_DATETIME_OSD							(IPC_VIDEO_BASE+45)

#define IPC_SYSTEM_UPNP_ENABLE							(IPC_NETWORK_BASE+18)
#define IPC_SYSTEM_UPNP_PORT							(IPC_NETWORK_BASE+19)
#define IPC_SYSTEM_UPNP_NAME							(IPC_NETWORK_BASE+20)

#define IPC_CMD_PTZ_SET_PRESET							(IPC_PTZ_BASE + 32) //机械云台设置预置点	预置点索引 1~255
#define IPC_CMD_PTZ_GOTO_PRESET							(IPC_PTZ_BASE + 33) //机械云台转到预置点	预置点索引 1~255
#define IPC_CMD_PTZ_CLEAR_PRESET						(IPC_PTZ_BASE + 34) //机械云台删除预置点	预置点索引 1~255
#define IPC_CMD_PTZ_DIRECT_TRANS_PROP_SET       		(IPC_PTZ_BASE + 35) //设置透明通道属性
#define IPC_CMD_PTZ_DIRECT_TRANS_PROP_GET       		(IPC_PTZ_BASE + 36) //获取透明通道属性
#define IPC_CMD_PTZ_UART_CTRL_SET               		(IPC_PTZ_BASE + 37) //设置串口通信参数
#define IPC_CMD_PTZ_UART_CTRL_GET               		(IPC_PTZ_BASE + 38) //获取串口通信参数
#define IPC_CMD_PTZ_DIRECT_TRANS_DATA           		(IPC_PTZ_BASE + 39) //数据透明传输
#define IPC_CMD_PTZ_PRESET_ALL_GET						(IPC_PTZ_BASE + 40) //获取所有预置位设置    参考结构体 IPC_PRESET
#define IPC_CMD_PTZ_CAPACITY_GET                		(IPC_PTZ_BASE + 41) //获取设备能力
#define IPC_CMD_PTZ_CRUISE_GET                  		(IPC_PTZ_BASE + 42) //获取巡航路径
#define IPC_CMD_PTZ_CRUISE_SET                  		(IPC_PTZ_BASE + 43) //设置巡航路径
#define IPC_CMD_PTZ_CRUISE_CONTROL              		(IPC_PTZ_BASE + 44) //控制巡航路径执行
#define IPC_CMD_GET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 45) //获取IRCUT定时策略
#define IPC_CMD_SET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 46) //设置IRCUT定时策略
#define IPC_CMD_GET_SHUTTER_TIME_RANGE           		(IPC_PTZ_BASE + 47) //获取快门时间范围

#define IPC_CMD_PTZ_RIGHTUP						        (IPC_PTZ_BASE + 56) //
#define IPC_CMD_PTZ_LEFTUP						        (IPC_PTZ_BASE + 57) //
#define IPC_CMD_PTZ_RIGHTDOWN						    (IPC_PTZ_BASE + 58) //
#define IPC_CMD_PTZ_LEFTDOWN						    (IPC_PTZ_BASE + 59) //
#define IPC_CMD_PTZ_CRUISE_START						(IPC_PTZ_BASE + 60) // 云台巡航控制  
#define IPC_CMD_PTZ_CRUISE_STOP						    (IPC_PTZ_BASE + 61) // 云台巡航控制 

#define IPC_CMD_PTZ_PROTOCOL							(IPC_NETWORK_BASE+1)  	//?? 
#define IPC_PTZPROTOCOL_PELCOD							(IPC_NETWORK_BASE+7)  	//派尔高协议  ??

#define IPC_CMD_GET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 45) //获取IRCUT定时策略
#define IPC_CMD_SET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 46) //设置IRCUT定时策略
#define IPC_CMD_GET_SHUTTER_TIME_RANGE           		(IPC_PTZ_BASE + 47) //获取快门时间范围
#define IPC_VIDEO_PTZ_MODE								(IPC_VIDEO_BASE+39) //云台模式（保留暂不使用）
#define IPC_ENCODE_STR_FORCE_I							(IPC_VIDEO_BASE+31) 			
#define IPC_VIDEO_PM_GROUP							    (IPC_VIDEO_BASE+16)	//视频遮挡	参考结构体 IMGPM
#define IPC_VIDEO_GETSET_IMGINFO1						(IPC_VIDEO_BASE+46)    //获取单码流分辨率 帧率信息
#define IPC_VIDEO_GETSET_IMGINFO2						(IPC_VIDEO_BASE+47)    //获取单码流分辨率 帧率信息
#define IPC_VIDEO_GETSET_IMGINFO3						(IPC_VIDEO_BASE+48)    //获取单码流分辨率 帧率信息
#define IPC_VIDEO_GETSET_IMGINFO4						(IPC_VIDEO_BASE+49)    //获取单码流分辨率 帧率信息
#define IPC_VIDEO_GET_SUPPORTED_STREAM					(IPC_VIDEO_BASE+50)    //获取支持的码流
#define IPC_ENCODE_ENC_SN_GROUP							(IPC_VIDEO_BASE+23)		//视频编码			参考结构体ENCSN   
#define IPC_VIDEO_PARAMCFG								(IPC_VIDEO_BASE+51)	

#define IPC_VIDEO_SHUTTER_TIME_RANGE					(IPC_VIDEO_BASE+52)		//电子快门时间最大值和最小值的范围   参考结构体 SHUTTER_RANGE		
#define IPC_VIDEO_SHUTTER_MIN_TIME_RANGE				(IPC_VIDEO_BASE+53)		//电子快门时间最大值和最小值的范围   参考结构体 SHUTTER_RANGE	

#define IPC_CONNECT_CONNECTING							(IPC_NETWORK_BASE+10) //正在网络连接
#define IPC_CONNECT_OK									(IPC_NETWORK_BASE+11) //网络连接成功
#define IPC_CONNECT_FAILCONNECT							(IPC_NETWORK_BASE+12) //网络连接失败
#define IPC_CONNECT_DISCONNECT							(IPC_NETWORK_BASE+13) //网络连接断开
#define IPC_CONNECT_RECONNECT							(IPC_NETWORK_BASE+14) //正在重连
#define IPC_CONNECT_AUTHOK								(IPC_NETWORK_BASE+15) //登录成功
#define IPC_CONNECT_FAILAUTH							(IPC_NETWORK_BASE+16) //登录失败
#define IPC_CONNECT_UNKNOW								(IPC_NETWORK_BASE+17) //未知错误

//事件相关命令
#define	IPC_CMD_GET_EVENT								(IPC_EVENT_BASE+1)
#define	IPC_CMD_SET_EVENT								(IPC_EVENT_BASE+2)

#define IPC_CMD_GET_MD_WINDOWINFO						(IPC_EVENT_BASE+3)
#define IPC_CMD_SET_MD_WINDOWINFO						(IPC_EVENT_BASE+4)
//报警输入输出端口
#define IPC_EVENT_OUTPUT_PORT_NUMBER					(IPC_EVENT_BASE+8)
#define IPC_EVENT_INPUT_PORT_NUMBER						(IPC_EVENT_BASE+9)
#define IPC_EVENT_OUTPUT_PORT_CTRL						(IPC_EVENT_BASE+10)
#define IPC_EVENT_INPUT_PORT_CTRL						(IPC_EVENT_BASE+11)
#define IPC_EVENT_OUTPUT_PORT_ACTION					(IPC_EVENT_BASE+12)
#define IPC_EVENT_INPUT_PORT_TRIGGER_CONDITION			(IPC_EVENT_BASE+13)

//网络管理
#define IPC_NETWORK_BASE							0x00003000
#define IPC_SYSTEM_SETGET_UPNPINFO					(IPC_NETWORK_BASE+2)  	//UPnp配置 参考结构体 SYSUPNPINFO
#define IPC_SYSTEM_SETGET_SMTPINFO					(IPC_NETWORK_BASE+3)  	//邮件配置 参考结构体 SYSSMTP
#define IPC_SYSTEM_SETGET_FTPINFO					(IPC_NETWORK_BASE+4)  	//FTP配置  参考结构体 SYSFTP 
#define IPC_SYSTEM_SETGET_IPINFO					(IPC_NETWORK_BASE+5)  	//网络配置 参考结构体 SYSIPINFO 

//事件触发动作
#define IPC_EVENT_ACTIONTYPE_RECORD					(IPC_EVENT_BASE+19)		//录像		    参考结构体ActionOptionInfo 及 RECORDACTION
#define IPC_EVENT_ACTIONTYPE_PORTOUTPUT				(IPC_EVENT_BASE+20)		//输出口控制	参考结构体ActionOptionInfo 及 OUTPUTACTION	
#define IPC_EVENT_ACTIONTYPE_DPTZ					(IPC_EVENT_BASE+21)		//数字云台控制  参考结构体ActionOptionInfo 及 DPTZACTION
#define IPC_EVENT_ACTIONTYPE_PTZ					(IPC_EVENT_BASE+22)		//机械云台控制	参考结构体ActionOptionInfo 及 PTZACTION

#define  IPC_EVENT_SETENABLE							(IPC_EVENT_BASE+35)		//事件使能
#define  IPC_EVENT_GETENABLE							(IPC_EVENT_BASE+36)		//事件使能

#define IPC_PLAN_CAMERATAMPERING						(IPC_EVENT_BASE+27)		//视频异常布防	
#define IPC_PLAN_MONTIONDETECTION						(IPC_EVENT_BASE+28)		//移动侦测布防	
#define IPC_PLAN_INPUTPORT								(IPC_EVENT_BASE+29)		//外部输入报警布防	
#define IPC_PLAN_RECORD									(IPC_EVENT_BASE+30)		//定时录像布防	
#define IPC_PLAN_REBOOT									(IPC_EVENT_BASE+33)		//设备重启布防	
#define IPC_PLAN_CHANGECONFIG							(IPC_EVENT_BASE+34)		//配置修改布防	

#define IPC_EVENT_CAMERATAMPERING_INTERVAL				(IPC_EVENT_BASE+26)		

#define IPC_EVENT_OUTPORT_SETENABLE						(IPC_EVENT_BASE+50)		
#define IPC_EVENT_INPORT_SETENABLE						(IPC_EVENT_BASE+51)		
#define IPC_EVENT_OUTPORT_GETENABLE						(IPC_EVENT_BASE+52)		
#define IPC_EVENT_INPORT_GETENABLE						(IPC_EVENT_BASE+53)		




#define IPC_EVENT_SCHEDULED								(IPC_EVENT_BASE+14)		//定时录像报告
#define IPC_EVENT_LOST_FOCUS							(IPC_EVENT_BASE+37)  //
#define IPC_EVENT_VIDEO_LOST							(IPC_EVENT_BASE+38)
#define IPC_EVENT_VIDEO_BLIND							(IPC_EVENT_BASE+39)
#define IPC_EVENT_IP_COLLISION							(IPC_EVENT_BASE+40)
#define IPC_EVENT_PANORAMA_SWITCH						(IPC_EVENT_BASE+41)
#define IPC_EVENT_DISK_FULL								(IPC_EVENT_BASE+42)
#define IPC_EVENT_DISK_ERROR							(IPC_EVENT_BASE+43)
#define IPC_EVENT_DISK_LOST								(IPC_EVENT_BASE+44)
#define IPC_EVENT_NETBROKEN								(IPC_EVENT_BASE+45)
#define IPC_EVENT_DSP									(IPC_EVENT_BASE+46)
#define IPC_EVENT_REALPLAY								(IPC_EVENT_BASE+47)
#define IPC_EVENT_ALL								    (IPC_EVENT_BASE+49)		//所有事件
#define IPC_EVENT_CONFIGCHANGED							(IPC_EVENT_BASE+32)		//配置修改报警

#define IPC_EVENT_ACTIONTYPE_NOTIFY_EMAIL				(IPC_EVENT_BASE+18)		//发送邮件	参考结构体 ActionOptionInfo 中的

//sd卡
#define IPC_SD_BASE										0x00006000				
#define IPC_SYSTEM_GET_SD_STATUS						(IPC_SD_BASE+1)			
#define IPC_SYSTEM_GET_SD_RW							(IPC_SD_BASE+2)
#define IPC_SYSTEM_GET_SD_SPACE							(IPC_SD_BASE+3)
#define IPC_SYSTEM_GET_SD_FREE_SAPCE					(IPC_SD_BASE+4)
#define IPC_SYSTEM_SET_SD_CMD							(IPC_SD_BASE+5)
#define IPC_SYSTEM_GET_REC_FILES						(IPC_SD_BASE+6)
#define IPC_SYSTEM_SET_REC_DEL_FILES					(IPC_SD_BASE+7)
#define IPC_SYSTEM_SET_REC_UPLOAD_FILES					(IPC_SD_BASE+8)

#define IPC_SYSTEM_SET_RESTORE_DEFAULT					(IPC_SYSTEM_BASE+10)	//
#define IPC_SYSTEM_SET_DEVICE_RESTART					(IPC_SYSTEM_BASE+11)
#define	IPC_SYSTEM_SET_DEVICE_WAITING					(IPC_SYSTEM_BASE+12)
#define	IPC_SYSTEM_SET_DEVICE_WAKEUP					(IPC_SYSTEM_BASE+13)
#define IPC_SYSTEM_SET_FILE_UPGRADE						(IPC_SYSTEM_BASE+14)	 //升级文件

#define IPC_SYSTEM_AUDIO_CTRL               			(IPC_SYSTEM_BASE+16)
#define IPC_SYSTEM_AUDIO_STATUS             			(IPC_SYSTEM_BASE+17)

#define IPC_SYSTEM_GET_RTP_ADDR							(IPC_SYSTEM_BASE+1)		//
#define IPC_SYSTEM_GET_RTP_ADDR2						(IPC_SYSTEM_BASE+2)
#define IPC_SYSTEM_GET_RTP_ADDR3						(IPC_SYSTEM_BASE+3)
#define IPC_SYSTEM_GET_RTP_ADDR4						(IPC_SYSTEM_BASE+4)
#define IPC_SYSTEM_GETSET_DDNSPARAM                     (IPC_SYSTEM_BASE+23)    //设置获取DDNS配置信息


#define IPC_SYSTEM_GETSET_LOGCFG                        (IPC_SYSTEM_BASE+24)    //设置获取日志保存策略

#define IPC_SYSTEM_QUERYLOG								(IPC_SYSTEM_BASE+25)    //日志查询
#define IPC_SYSTEM_DELLOGBYID							(IPC_SYSTEM_BASE+26)    //依据ID删除日志
#define IPC_SYSTEM_CLEARLOG								(IPC_SYSTEM_BASE+27)    //清空日志
#define IPC_SYSTEM_DELLOG								(IPC_SYSTEM_BASE+28)    //依据条件删除日志
#define IPC_SYSTEM_GETLOGCOUNT							(IPC_SYSTEM_BASE+29)    //获取日志个数

#define IPC_SYSTEM_SETGET_IPINFO_EX						(IPC_SYSTEM_BASE+33)

#define IPC_SYSTEM_SETGET_DEVCFG						(IPC_SYSTEM_BASE+34)

#define IPC_SYSTEM_GET_DEVINFO							(IPC_SYSTEM_BASE+35)	//设备能力

#define IPC_SDKINNER_BASE   						     0x00010000	
#define IPC_SDKINNER_DEVINFO                            (IPC_SDKINNER_BASE+1)
#define IPC_SDKINNER_IMGINFO                            (IPC_SDKINNER_BASE+2)
#define IPC_SDKINNER_TIMEINFO                           (IPC_SDKINNER_BASE+3)
#define IPC_SDKINNER_SHOWCFG                            (IPC_SDKINNER_BASE+4)
#define IPC_SDKINNER_NETPORT                            (IPC_SDKINNER_BASE+5)
#define IPC_SDKINNER_CAPABILITY                         (IPC_SDKINNER_BASE+6)
#define IPC_SDKINNER_ADVIMGINFO                         (IPC_SDKINNER_BASE+7)
#define IPC_SDKINNER_WORKSTATE                          (IPC_SDKINNER_BASE+8)
#define IPC_SDKINNER_MODIFYADDUSRINFO                   (IPC_SDKINNER_BASE+9)    //
#define IPC_SDKINNER_DELUSRINFO                         (IPC_SDKINNER_BASE+10)
#define IPC_SDKINNER_WORKSTATE_XML                      (IPC_SDKINNER_BASE+11)
#define IPC_SDKINNER_AUDIO_ENABLE                       (IPC_SDKINNER_BASE+12)   //音频流使能设置 
#define IPC_SDKINNER_TALK_CFG							(IPC_SDKINNER_BASE+13)   //语音对讲及音频参数配置
#define IPC_SDKINNER_STREAMCOMBINE_CFG					(IPC_SDKINNER_BASE+14)   //分辨率组合配置的设置获取
#define IPC_SDKINNER_WHITEBANACE						(IPC_SDKINNER_BASE+15)   //白平衡 
#define IPC_SDKINNER_DAYNIGHR							(IPC_SDKINNER_BASE+16)   //日夜模式 
#define IPC_SDKINNER_SYS_DEVCFG							(IPC_SDKINNER_BASE+17)   //设备配置信息 
#define IPC_SDKINNER_ALMCFG								(IPC_SDKINNER_BASE+18)   //报警配置信息 
#define IPC_SDKINNER_ALMDEPLOYCFG						(IPC_SDKINNER_BASE+19)   //报警布防信息 
#define IPC_SDKINNER_ENCODEINFO						    (IPC_SDKINNER_BASE+20)   //报警布防信息 
#define IPC_SDKINNER_MOTION_INFO                        (IPC_SDKINNER_BASE+21)   //移动侦测信息 
#define IPC_SDKINNER_ZOOMRANGE						    (IPC_SDKINNER_BASE+22)   //变倍范围  

#define IPC_IPC				1		//未定义IPC相机
#define IPC_IP_CAM_N		2		//枪机--无红外
#define IPC_IP_CAM_Y		3		//枪机--有红外

#define IPC_IR_DOME_N		4		//红外半球--无红外
#define IPC_IR_DOME_Y		5		//红外半球--有红外

#define IPC_ZOOM_CAM_N		6		//一体机--无红外
#define IPC_ZOOM_CAM_Y		7		//一体机--有红外

#define IPC_ECOM_DOME_N		8		//经济半球-无红外
#define IPC_ECOM_DOME_Y		9		//经济半球-有红外

#define IPC_DOLPHIN_DOME_N	10		//海豚半球-无红外
#define IPC_DOLPHIN_DOME_Y	11		//海豚半球-有红外

#define IPC_OSPREY_ZOOMCAM	12		//鱼鹰一体化枪机


//回调函数返回的是指令通信类型
//命令为:GET,SET
//子类型:如 ENCODE_PROPERTY_SN_TEXT_ENABLE
//长度:此处为数据长度
//数据:通过前两个参数可以确定数据的类型
#pragma pack(push,1)

typedef struct tagIPCCommandContext
{
	DWORD cmd ;
	DWORD subtype ;
	DWORD result ;
	DWORD len ;
	LPVOID data ;
}IPC_COMMAND_CONTEXT,*LPIPC_COMMAND_CONTEXT ;

typedef struct tagIPCEventContext
{
	DWORD cmd ;
	DWORD subtype ;
	DWORD result ;
	DWORD len ;
	LPVOID data ;
}IPC_EVENT_CONTEXT,*LPIPC_EVENT_CONTEXT ;


#ifndef IPC_VIDEO_INFO_STRUCT
#define IPC_VIDEO_INFO_STRUCT
typedef struct  tagIPC_VIDEO_INFO
{
	long	lWidth;				   									 //图像宽
	long	lHeight;			   									 //图像高
	long	lFouCC;				   									 //编码方式	 0:H264 ,1:MJPEG
	long	lFrameRate;			   									 //帧率
}IPC_VIDEO_INFO,*PIPC_VIDEO_INFO;
#endif//IPC_VIDEO_INFO_STRUCT

#ifndef IPC_AUDIO_INFO_STRUCT
#define IPC_AUDIO_INFO_STRUCT
typedef struct tagIPC_AUDIO_INFO
{
	long	lAudioFormat;		         //0:AMR_1_16_8000; 1:PCMA_1_8_8000
	long	lSamplesPerSec;				//采样频率:8000,
	long	lBitsPerSample;				//采样精度:16,
	long	lChannels;					//声道:1,
	long	lAvgBytesPerSec;			//平均速率:16000
}IPC_AUDIO_INFO,*PIPC_AUDIO_INFO;
#endif//IPC_AUDIO_INFO_STRUCT

#ifndef IPC_PLAYER_INFO_STRUCT
#define IPC_PLAYER_INFO_STRUCT
typedef struct  tagIPC_PLAYER_INFO
{
	IPC_VIDEO_INFO			videoInfo;									//视频信息
	IPC_AUDIO_INFO			audioInfo;									//音频信息,保留	
}IPC_PLAYER_INFO,*PIPC_PLAYER_INFO;
#endif//IPC_PLAYER_INFO_STRUCT

#ifndef IPC_PLAYER_FRAME_STRUCT
#define IPC_PLAYER_FRAME_STRUCT
typedef	struct tagIPC_PLAYER_FRAME
{
	long			lType;											//帧类型,0:I,1:P,2:B,3:A
	unsigned char	*pBuf;											//帧数据缓冲区
	long			lBufSize;										//帧数据缓冲区大小
	ULONGLONG		ullStartTime;									//播放开始时间
	ULONGLONG		ullEndTime;										//播放结束时间
	IPC_PLAYER_INFO	    stHeadInfo;										//数据头信息，非空则播放库重新初始化
}IPC_PLAYER_FRAME,*PIPC_PLAYER_FRAME;
#endif//IPC_PLAYER_FRAME_STRUCT

typedef struct _tagIPC_SupportStream
{
	DWORD dwValue[4];
	DWORD dwHeight[4];
	DWORD dwRate[4];
}IPC_SupportStream;

//移动侦测窗口信息
typedef struct tagIPC_MontionDetectionWindowInfo
{
	tagIPC_MontionDetectionWindowInfo()
	{
		memset(this, 0, sizeof(tagIPC_MontionDetectionWindowInfo));
	}
	int          index;													//窗口id 范围1~4		
	CHAR         name[128] ;											//窗口名称			
	RECT         rect ;													//窗口区间，为RECT结构体
																		//视频图像被分成12x8=96 个格子 。x,y 可确定左上角，right,bottom可以确定右下角。右下角的坐标一定要大于左上角的坐标
																		//x 取值范围[0, 11].     y 取值范围 [0, 7].     right 取值范围 [1, 12].     width 取值范围 [1, 8].
																		//例如： rect 为{x=1，y=1 ，right=2，bottom=2} 表示占用(1,1),(1,2),(2,1),(2,2)四个格子

	INT          agile;													//灵敏度 范围[0, 10]		
	INT          threshold;												//阈值 范围[1, 100]  				
}IPC_MontionDetectionWindowInfo,*LPIPC_MontionDetectionWindowInfo ;

//H264
typedef struct tagIPC_H264
{ 	
	tagIPC_H264()
	{
		memset(this, 0, sizeof(tagIPC_H264));
	}
	DWORD   sn_m;			 											//M值，取值范围为（1、 2、 3 ）		 
	DWORD   sn_n;			 											//N值，取值范围为1 到255	
	DWORD   sn_idrInterval;	 											//IDR间隔，取值范围为1 到100	
	DWORD   sn_brc; 		 											//比特率控制，0为CBR，1为VBR，2为CBR (keep quality) ，3为VBR (keep quality)	  
	DWORD   sn_cbr; 		 											//比特率平均值，介于1000000到8000000之间	  
	DWORD   sn_vbr_min;	     											//最小比特率（bps），默认为1000000
	DWORD   sn_vbr_max;	     											//最大比特率 （bps），默认为8000000	
} IPC_H264, *LPIPC_H264;

//视频编码
typedef struct tagIPC_ENCSN
{
	tagIPC_ENCSN()
	{
		memset(this, 0, sizeof(tagIPC_ENCSN));
	}
	DWORD	sn_stream; 												//码流id， 0为码流1，1为码流2，2为码流3，3为码流4
	DWORD	sn_fps;													//编码帧率, 60fps 值为8533333，30fps值为 17066667，25fps 值为20480000
	DWORD 	sn_width;												//码流分辨率的宽
	DWORD	sn_height;												//码流分辨率的高
	DWORD	sn_rotate;												//镜像/翻转, 0：正常 1：水平镜像 2：垂直镜像  3 : 旋转 180 4 : 旋转 90,7 : 旋转 270
	DWORD	sn_type;												//编码格式 1:H.264  2:MJPEG	
	IPC_H264	sn_h264;    											
	DWORD   sn_quality ;											//MJPEG编码质量,取值范围为1 到 100			
}IPC_ENCSN, *LPIPC_ENCSN;

typedef struct tagIPC_NET_DEVICE_CFG
{
	tagIPC_NET_DEVICE_CFG()
	{
		memset(this, 0, sizeof(tagIPC_NET_DEVICE_CFG));
	}
	CHAR	szDevName[32]; 								
	CHAR	szSN[64];
	CHAR	szManufacturerName[32];			
	CHAR 	szFWVersion[32];
	CHAR	szHWVersion[32];
	DWORD	dwGB;										
	DWORD	dwRTSP;
}IPC_NET_DEVICE_CFG,*LPIPC_NET_DEVICE_CFG;

typedef struct tagIPC_NET_DEVICE_INFO
{
	tagIPC_NET_DEVICE_INFO()
	{
		memset(this, 0, sizeof(tagIPC_NET_DEVICE_INFO));
	}
	CHAR	sSerialNumber[64];						//设备序列号							
	DWORD	dwAlarmInPortNum;						//报警输入个数
	DWORD   dwAlarmOutPortNum;						//报警输出个数
	DWORD   dwIPCType;								//设备类型		

	DWORD   dwMaxChan;								//设备最多支持的通道个数
	DWORD   dwStartChan;							//起始通道号，目前设备通道号从0开始
	DWORD   dwStreamProto;							//码流传输协议类型:0-私有TCP,1-rtsp(tcp协议)单播,2-rtsp(udp协议)单播,3-rtsp(udp协议)组播
	DWORD   dwSupport;								//能力，位与结果为0表示不支持，1表示支持
														//	bySupport & 0x1,	表示是否支持snmp v30
														//	bySupport & 0x2,	表示是否支持布防优先级
														//	bySupport & 0x4，	表示是否支持压缩参数能力获取(IPC_STREAMINFO_V3)
														//	bySupport & 0x8，	表示是否支持GB

														//	bySupport & 0x10，	表示是否支持智能搜索 (搜索设备上录像信息以及移动侦测窗口信息 NET_DVR_SmartSearch) 不支持
														//	bySupport & 0x20，	表示是否支持备份	不支持
														//	bySupport & 0x40,	表示支持远程SADP(SADP协议，可软件实时搜索同一局域网内的视频服务器，并可对视频服务器的IP地址、服务端口号、掩码信息配置修改)
														//	bySupport & 0x80,	表示支持Raid卡功能(Redundant Array of Independent Disks 磁盘阵列) 不支持
														//	bySupport & 0x100,	表示支持IPSAN目录查找				不支持
														//	bySupport & 0x200,	表示支持rtp over rtsp				不支持 
														//	bySupport & 0x400,	表示是否支持区分回放和下载			不支持
														//	bySupport & 0x800,	表示智能设备是否支持布防时间段扩展	不支持
														//	bySupport & 0x1000,	表示是否支持多磁盘数（超过33个）	不支持
														//	bySupport & 0x2000,	表示是否支持rtsp over http			不支持
														//	bySupport & 0x4000,	表示是否支持延时预览				不支持
														//	bySupport & 0x8000, 表示解码器是否支持通过URL取流解码	不支持	
														//	bySupport & 0x10000,表示是否支持双网卡	不支持	
	DWORD   dwDiskNum;								//硬盘个数							 (不支持)
	DWORD   dwAudioChanNum;							//设备语音通道数					 (不支持、无)
	DWORD   dwIPChanNum;							//设备最大数字通道个数				 (不支持、无)
	DWORD   dwZeroChanNum;							//零通道编码个数					 (不支持、无)			
	CHAR    sRes2[14];								//保留，置为0							
}IPC_NET_DEVICE_INFO,*LPIPC_NET_DEVICE_INFO;


////视频图像参数
typedef struct tagIPC_VIDEO_PARAMCFG
{	tagIPC_VIDEO_PARAMCFG()
	{
		memset(this, 0, sizeof(tagIPC_VIDEO_PARAMCFG));
	}

	DWORD	dwMaxGainValue;				//MAX_GAIN 最大增益值，单位dB //30db, 36db, 42db, 48db, 54db, 60db
	DWORD	dwWhiteBalanceMode;			//WBC_MODE白平衡设置:0: 自动;1:白炽;2:d4000;3: d5000;4: 晴朗;5: 多云;
										//6: 闪光;7: 荧光;8: 高荧光;9: 水下;10:手动白平衡;11: 关闭
	DWORD	dwWhiteBalanceModeRGain;	//WBC_CUSTOM_R_GAIN手动白平衡时有效，手动白平衡R增益	0~1023						
	DWORD	dwWhiteBalanceModeBGain;	//WBC_CUSTOM_B_GAIN手动白平衡时有效，手动白平衡B增益 0~1023
	DWORD	dwTargetRation ;			//AE_TARGET_RATION 曝光目标系数	25~400
	DWORD	dwLocalExposureMode ;		//LOCAL_EXPOSURE 局部曝光模式0 : 关闭; 1: 打开; 2: 暂停; 3: 2x; 4:3x; 5:4x
	DWORD	dwSlowShutterEnable ;		//SLOW_SHUTTER 自动曝光设置中SlowShutter  0:关闭;1:开启
	DWORD	dwPreference ;				//AE_PREFERENCE 自动曝光的偏好 0 : 正常模式;1 :暗光模式;2 : 光圈优先
	DWORD	dwMeteringMode ;			//METERING_MODE 自动曝光设置中测光模式   0:聚光;1:中心;2:平均
	
	DWORD	dwDayNightFilterTime ;		//等待时间，即每次作出日夜切换决策的时间间隔  3s ~ 30s  默认10s
	DWORD	dwDayToNightFilterThr ;		//白天模式转夜晚模式的阈值	0~100   默认 40
	DWORD	dwNightToDayFilterThr ;   	//夜晚模式转白天模式的阈值	0~100 默认 60

	DWORD   dwBackLight ;				//BACKLIGHT_COMP 背光补偿0-关闭, 1-开启
	DWORD   dwNoiseRemove ;				//MCTF_STRENGTH	3D降噪 0~255
	DWORD   dwPowerLineFrequencyMode;	//EXPOSURE_MODE	抗闪烁模式0-50Hz ; 1-60Hz; 2-自动
	DWORD	dwIrisType; 				//模式 0关闭;1开启	
	DWORD	dwIrisQuty; 				//占空值 100 ~ 999
	DWORD   dwMJPEGQuality ;			//MJPEG_QUALITY MJPEG实时码流图像质量 0~100
	DWORD   dwSceneMode;				//DN_MODE 场景模式 (0 白天,1 夜晚,2 自动,3 定制)  
	DWORD   dwShutterMin;				//最小值的取值范围为64000 到 20480000	
	DWORD   dwShutterMax;				//最大值的取值范围为64000 到 68266667
}IPC_VIDEOPARAMCFG,*LPIPC_VIDEOPARAMCFG;

struct IPC_SYSIPINFOEX : public IPC_SYSIPINFO
{
	DWORD	dwPort;										
};

//not used any all
typedef struct tagIPC_PTZPostionParam
{
	INT		xPostion ;													//水平方向 坐标:  取值范围受ipcPTZPostionControl 函数的命令宏影响 ： 
																		//命令为IPC_CMD_PTZ_GOTO_REL_POSITION时候,取值范围-35999到35999
																		//命令为IPC_CMD_PTZ_GOTO_ABS_POSITION时候,取值范围  0 到35999

	INT		yPostion ;													//垂直方向坐标，取值范围受ipcPTZPostionControl 函数的命令宏影响 ： 
																		//命令为IPC_CMD_PTZ_GOTO_REL_POSITION时候,取值范围-9000到9000
																		//命令为IPC_CMD_PTZ_GOTO_ABS_POSITION时候,取值范围0 到9000 

	INT		xSpeed ;													//水平方向移动的速度
	INT		ySpeed ;													//垂直方向移动的速度
}IPC_PTZ_POSTION_PARAM, *LPIPC_PTZ_POSTION_PARAM;



typedef struct tagIPC_DAYNIGHT
{
	tagIPC_DAYNIGHT()
	{
		memset(this, 0, sizeof(tagIPC_DAYNIGHT));
	}
	DWORD  dwMode;								//0-day mode,1-night mode, 2-auto ,3- timing mode.default 0
	DWORD  dwDurationTime;						//valid range is 3~30s.default 5
	DWORD  dwNightToDayThr;						//valid range is 0~100.default 60
	DWORD  dwDayToNightThr;						//valid range is 0~100.default 40
	DWORD  dwSchedEnable[7];					//0--disable, 1--enable.default 0
	DWORD  dwchedStartTime[7];					//0~24*3600s.default 0
	DWORD  dwSchedEndTime[7];					//0~24*3600s.default 0
}IPC_DAYNIGHT,* LPIPC_DAYNIGHT;

#pragma pack(pop)

#endif