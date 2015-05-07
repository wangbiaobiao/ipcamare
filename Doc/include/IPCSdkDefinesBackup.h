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

#define IPC_CMD_PTZ_SET_PRESET							(IPC_PTZ_BASE + 32) //��е��̨����Ԥ�õ�	Ԥ�õ����� 1~255
#define IPC_CMD_PTZ_GOTO_PRESET							(IPC_PTZ_BASE + 33) //��е��̨ת��Ԥ�õ�	Ԥ�õ����� 1~255
#define IPC_CMD_PTZ_CLEAR_PRESET						(IPC_PTZ_BASE + 34) //��е��̨ɾ��Ԥ�õ�	Ԥ�õ����� 1~255
#define IPC_CMD_PTZ_DIRECT_TRANS_PROP_SET       		(IPC_PTZ_BASE + 35) //����͸��ͨ������
#define IPC_CMD_PTZ_DIRECT_TRANS_PROP_GET       		(IPC_PTZ_BASE + 36) //��ȡ͸��ͨ������
#define IPC_CMD_PTZ_UART_CTRL_SET               		(IPC_PTZ_BASE + 37) //���ô���ͨ�Ų���
#define IPC_CMD_PTZ_UART_CTRL_GET               		(IPC_PTZ_BASE + 38) //��ȡ����ͨ�Ų���
#define IPC_CMD_PTZ_DIRECT_TRANS_DATA           		(IPC_PTZ_BASE + 39) //����͸������
#define IPC_CMD_PTZ_PRESET_ALL_GET						(IPC_PTZ_BASE + 40) //��ȡ����Ԥ��λ����    �ο��ṹ�� IPC_PRESET
#define IPC_CMD_PTZ_CAPACITY_GET                		(IPC_PTZ_BASE + 41) //��ȡ�豸����
#define IPC_CMD_PTZ_CRUISE_GET                  		(IPC_PTZ_BASE + 42) //��ȡѲ��·��
#define IPC_CMD_PTZ_CRUISE_SET                  		(IPC_PTZ_BASE + 43) //����Ѳ��·��
#define IPC_CMD_PTZ_CRUISE_CONTROL              		(IPC_PTZ_BASE + 44) //����Ѳ��·��ִ��
#define IPC_CMD_GET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 45) //��ȡIRCUT��ʱ����
#define IPC_CMD_SET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 46) //����IRCUT��ʱ����
#define IPC_CMD_GET_SHUTTER_TIME_RANGE           		(IPC_PTZ_BASE + 47) //��ȡ����ʱ�䷶Χ

#define IPC_CMD_PTZ_RIGHTUP						        (IPC_PTZ_BASE + 56) //
#define IPC_CMD_PTZ_LEFTUP						        (IPC_PTZ_BASE + 57) //
#define IPC_CMD_PTZ_RIGHTDOWN						    (IPC_PTZ_BASE + 58) //
#define IPC_CMD_PTZ_LEFTDOWN						    (IPC_PTZ_BASE + 59) //
#define IPC_CMD_PTZ_CRUISE_START						(IPC_PTZ_BASE + 60) // ��̨Ѳ������  
#define IPC_CMD_PTZ_CRUISE_STOP						    (IPC_PTZ_BASE + 61) // ��̨Ѳ������ 

#define IPC_CMD_PTZ_PROTOCOL							(IPC_NETWORK_BASE+1)  	//?? 
#define IPC_PTZPROTOCOL_PELCOD							(IPC_NETWORK_BASE+7)  	//�ɶ���Э��  ??

#define IPC_CMD_GET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 45) //��ȡIRCUT��ʱ����
#define IPC_CMD_SET_DN_SCHEDULE                  		(IPC_PTZ_BASE + 46) //����IRCUT��ʱ����
#define IPC_CMD_GET_SHUTTER_TIME_RANGE           		(IPC_PTZ_BASE + 47) //��ȡ����ʱ�䷶Χ
#define IPC_VIDEO_PTZ_MODE								(IPC_VIDEO_BASE+39) //��̨ģʽ�������ݲ�ʹ�ã�
#define IPC_ENCODE_STR_FORCE_I							(IPC_VIDEO_BASE+31) 			
#define IPC_VIDEO_PM_GROUP							    (IPC_VIDEO_BASE+16)	//��Ƶ�ڵ�	�ο��ṹ�� IMGPM
#define IPC_VIDEO_GETSET_IMGINFO1						(IPC_VIDEO_BASE+46)    //��ȡ�������ֱ��� ֡����Ϣ
#define IPC_VIDEO_GETSET_IMGINFO2						(IPC_VIDEO_BASE+47)    //��ȡ�������ֱ��� ֡����Ϣ
#define IPC_VIDEO_GETSET_IMGINFO3						(IPC_VIDEO_BASE+48)    //��ȡ�������ֱ��� ֡����Ϣ
#define IPC_VIDEO_GETSET_IMGINFO4						(IPC_VIDEO_BASE+49)    //��ȡ�������ֱ��� ֡����Ϣ
#define IPC_VIDEO_GET_SUPPORTED_STREAM					(IPC_VIDEO_BASE+50)    //��ȡ֧�ֵ�����
#define IPC_ENCODE_ENC_SN_GROUP							(IPC_VIDEO_BASE+23)		//��Ƶ����			�ο��ṹ��ENCSN   
#define IPC_VIDEO_PARAMCFG								(IPC_VIDEO_BASE+51)	

#define IPC_VIDEO_SHUTTER_TIME_RANGE					(IPC_VIDEO_BASE+52)		//���ӿ���ʱ�����ֵ����Сֵ�ķ�Χ   �ο��ṹ�� SHUTTER_RANGE		
#define IPC_VIDEO_SHUTTER_MIN_TIME_RANGE				(IPC_VIDEO_BASE+53)		//���ӿ���ʱ�����ֵ����Сֵ�ķ�Χ   �ο��ṹ�� SHUTTER_RANGE	

#define IPC_CONNECT_CONNECTING							(IPC_NETWORK_BASE+10) //������������
#define IPC_CONNECT_OK									(IPC_NETWORK_BASE+11) //�������ӳɹ�
#define IPC_CONNECT_FAILCONNECT							(IPC_NETWORK_BASE+12) //��������ʧ��
#define IPC_CONNECT_DISCONNECT							(IPC_NETWORK_BASE+13) //�������ӶϿ�
#define IPC_CONNECT_RECONNECT							(IPC_NETWORK_BASE+14) //��������
#define IPC_CONNECT_AUTHOK								(IPC_NETWORK_BASE+15) //��¼�ɹ�
#define IPC_CONNECT_FAILAUTH							(IPC_NETWORK_BASE+16) //��¼ʧ��
#define IPC_CONNECT_UNKNOW								(IPC_NETWORK_BASE+17) //δ֪����

//�¼��������
#define	IPC_CMD_GET_EVENT								(IPC_EVENT_BASE+1)
#define	IPC_CMD_SET_EVENT								(IPC_EVENT_BASE+2)

#define IPC_CMD_GET_MD_WINDOWINFO						(IPC_EVENT_BASE+3)
#define IPC_CMD_SET_MD_WINDOWINFO						(IPC_EVENT_BASE+4)
//������������˿�
#define IPC_EVENT_OUTPUT_PORT_NUMBER					(IPC_EVENT_BASE+8)
#define IPC_EVENT_INPUT_PORT_NUMBER						(IPC_EVENT_BASE+9)
#define IPC_EVENT_OUTPUT_PORT_CTRL						(IPC_EVENT_BASE+10)
#define IPC_EVENT_INPUT_PORT_CTRL						(IPC_EVENT_BASE+11)
#define IPC_EVENT_OUTPUT_PORT_ACTION					(IPC_EVENT_BASE+12)
#define IPC_EVENT_INPUT_PORT_TRIGGER_CONDITION			(IPC_EVENT_BASE+13)

//�������
#define IPC_NETWORK_BASE							0x00003000
#define IPC_SYSTEM_SETGET_UPNPINFO					(IPC_NETWORK_BASE+2)  	//UPnp���� �ο��ṹ�� SYSUPNPINFO
#define IPC_SYSTEM_SETGET_SMTPINFO					(IPC_NETWORK_BASE+3)  	//�ʼ����� �ο��ṹ�� SYSSMTP
#define IPC_SYSTEM_SETGET_FTPINFO					(IPC_NETWORK_BASE+4)  	//FTP����  �ο��ṹ�� SYSFTP 
#define IPC_SYSTEM_SETGET_IPINFO					(IPC_NETWORK_BASE+5)  	//�������� �ο��ṹ�� SYSIPINFO 

//�¼���������
#define IPC_EVENT_ACTIONTYPE_RECORD					(IPC_EVENT_BASE+19)		//¼��		    �ο��ṹ��ActionOptionInfo �� RECORDACTION
#define IPC_EVENT_ACTIONTYPE_PORTOUTPUT				(IPC_EVENT_BASE+20)		//����ڿ���	�ο��ṹ��ActionOptionInfo �� OUTPUTACTION	
#define IPC_EVENT_ACTIONTYPE_DPTZ					(IPC_EVENT_BASE+21)		//������̨����  �ο��ṹ��ActionOptionInfo �� DPTZACTION
#define IPC_EVENT_ACTIONTYPE_PTZ					(IPC_EVENT_BASE+22)		//��е��̨����	�ο��ṹ��ActionOptionInfo �� PTZACTION

#define  IPC_EVENT_SETENABLE							(IPC_EVENT_BASE+35)		//�¼�ʹ��
#define  IPC_EVENT_GETENABLE							(IPC_EVENT_BASE+36)		//�¼�ʹ��

#define IPC_PLAN_CAMERATAMPERING						(IPC_EVENT_BASE+27)		//��Ƶ�쳣����	
#define IPC_PLAN_MONTIONDETECTION						(IPC_EVENT_BASE+28)		//�ƶ���Ⲽ��	
#define IPC_PLAN_INPUTPORT								(IPC_EVENT_BASE+29)		//�ⲿ���뱨������	
#define IPC_PLAN_RECORD									(IPC_EVENT_BASE+30)		//��ʱ¼�񲼷�	
#define IPC_PLAN_REBOOT									(IPC_EVENT_BASE+33)		//�豸��������	
#define IPC_PLAN_CHANGECONFIG							(IPC_EVENT_BASE+34)		//�����޸Ĳ���	

#define IPC_EVENT_CAMERATAMPERING_INTERVAL				(IPC_EVENT_BASE+26)		

#define IPC_EVENT_OUTPORT_SETENABLE						(IPC_EVENT_BASE+50)		
#define IPC_EVENT_INPORT_SETENABLE						(IPC_EVENT_BASE+51)		
#define IPC_EVENT_OUTPORT_GETENABLE						(IPC_EVENT_BASE+52)		
#define IPC_EVENT_INPORT_GETENABLE						(IPC_EVENT_BASE+53)		




#define IPC_EVENT_SCHEDULED								(IPC_EVENT_BASE+14)		//��ʱ¼�񱨸�
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
#define IPC_EVENT_ALL								    (IPC_EVENT_BASE+49)		//�����¼�
#define IPC_EVENT_CONFIGCHANGED							(IPC_EVENT_BASE+32)		//�����޸ı���

#define IPC_EVENT_ACTIONTYPE_NOTIFY_EMAIL				(IPC_EVENT_BASE+18)		//�����ʼ�	�ο��ṹ�� ActionOptionInfo �е�

//sd��
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
#define IPC_SYSTEM_SET_FILE_UPGRADE						(IPC_SYSTEM_BASE+14)	 //�����ļ�

#define IPC_SYSTEM_AUDIO_CTRL               			(IPC_SYSTEM_BASE+16)
#define IPC_SYSTEM_AUDIO_STATUS             			(IPC_SYSTEM_BASE+17)

#define IPC_SYSTEM_GET_RTP_ADDR							(IPC_SYSTEM_BASE+1)		//
#define IPC_SYSTEM_GET_RTP_ADDR2						(IPC_SYSTEM_BASE+2)
#define IPC_SYSTEM_GET_RTP_ADDR3						(IPC_SYSTEM_BASE+3)
#define IPC_SYSTEM_GET_RTP_ADDR4						(IPC_SYSTEM_BASE+4)
#define IPC_SYSTEM_GETSET_DDNSPARAM                     (IPC_SYSTEM_BASE+23)    //���û�ȡDDNS������Ϣ


#define IPC_SYSTEM_GETSET_LOGCFG                        (IPC_SYSTEM_BASE+24)    //���û�ȡ��־�������

#define IPC_SYSTEM_QUERYLOG								(IPC_SYSTEM_BASE+25)    //��־��ѯ
#define IPC_SYSTEM_DELLOGBYID							(IPC_SYSTEM_BASE+26)    //����IDɾ����־
#define IPC_SYSTEM_CLEARLOG								(IPC_SYSTEM_BASE+27)    //�����־
#define IPC_SYSTEM_DELLOG								(IPC_SYSTEM_BASE+28)    //��������ɾ����־
#define IPC_SYSTEM_GETLOGCOUNT							(IPC_SYSTEM_BASE+29)    //��ȡ��־����

#define IPC_SYSTEM_SETGET_IPINFO_EX						(IPC_SYSTEM_BASE+33)

#define IPC_SYSTEM_SETGET_DEVCFG						(IPC_SYSTEM_BASE+34)

#define IPC_SYSTEM_GET_DEVINFO							(IPC_SYSTEM_BASE+35)	//�豸����

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
#define IPC_SDKINNER_AUDIO_ENABLE                       (IPC_SDKINNER_BASE+12)   //��Ƶ��ʹ������ 
#define IPC_SDKINNER_TALK_CFG							(IPC_SDKINNER_BASE+13)   //�����Խ�����Ƶ��������
#define IPC_SDKINNER_STREAMCOMBINE_CFG					(IPC_SDKINNER_BASE+14)   //�ֱ���������õ����û�ȡ
#define IPC_SDKINNER_WHITEBANACE						(IPC_SDKINNER_BASE+15)   //��ƽ�� 
#define IPC_SDKINNER_DAYNIGHR							(IPC_SDKINNER_BASE+16)   //��ҹģʽ 
#define IPC_SDKINNER_SYS_DEVCFG							(IPC_SDKINNER_BASE+17)   //�豸������Ϣ 
#define IPC_SDKINNER_ALMCFG								(IPC_SDKINNER_BASE+18)   //����������Ϣ 
#define IPC_SDKINNER_ALMDEPLOYCFG						(IPC_SDKINNER_BASE+19)   //����������Ϣ 
#define IPC_SDKINNER_ENCODEINFO						    (IPC_SDKINNER_BASE+20)   //����������Ϣ 
#define IPC_SDKINNER_MOTION_INFO                        (IPC_SDKINNER_BASE+21)   //�ƶ������Ϣ 
#define IPC_SDKINNER_ZOOMRANGE						    (IPC_SDKINNER_BASE+22)   //�䱶��Χ  

#define IPC_IPC				1		//δ����IPC���
#define IPC_IP_CAM_N		2		//ǹ��--�޺���
#define IPC_IP_CAM_Y		3		//ǹ��--�к���

#define IPC_IR_DOME_N		4		//�������--�޺���
#define IPC_IR_DOME_Y		5		//�������--�к���

#define IPC_ZOOM_CAM_N		6		//һ���--�޺���
#define IPC_ZOOM_CAM_Y		7		//һ���--�к���

#define IPC_ECOM_DOME_N		8		//���ð���-�޺���
#define IPC_ECOM_DOME_Y		9		//���ð���-�к���

#define IPC_DOLPHIN_DOME_N	10		//�������-�޺���
#define IPC_DOLPHIN_DOME_Y	11		//�������-�к���

#define IPC_OSPREY_ZOOMCAM	12		//��ӥһ�廯ǹ��


//�ص��������ص���ָ��ͨ������
//����Ϊ:GET,SET
//������:�� ENCODE_PROPERTY_SN_TEXT_ENABLE
//����:�˴�Ϊ���ݳ���
//����:ͨ��ǰ������������ȷ�����ݵ�����
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
	long	lWidth;				   									 //ͼ���
	long	lHeight;			   									 //ͼ���
	long	lFouCC;				   									 //���뷽ʽ	 0:H264 ,1:MJPEG
	long	lFrameRate;			   									 //֡��
}IPC_VIDEO_INFO,*PIPC_VIDEO_INFO;
#endif//IPC_VIDEO_INFO_STRUCT

#ifndef IPC_AUDIO_INFO_STRUCT
#define IPC_AUDIO_INFO_STRUCT
typedef struct tagIPC_AUDIO_INFO
{
	long	lAudioFormat;		         //0:AMR_1_16_8000; 1:PCMA_1_8_8000
	long	lSamplesPerSec;				//����Ƶ��:8000,
	long	lBitsPerSample;				//��������:16,
	long	lChannels;					//����:1,
	long	lAvgBytesPerSec;			//ƽ������:16000
}IPC_AUDIO_INFO,*PIPC_AUDIO_INFO;
#endif//IPC_AUDIO_INFO_STRUCT

#ifndef IPC_PLAYER_INFO_STRUCT
#define IPC_PLAYER_INFO_STRUCT
typedef struct  tagIPC_PLAYER_INFO
{
	IPC_VIDEO_INFO			videoInfo;									//��Ƶ��Ϣ
	IPC_AUDIO_INFO			audioInfo;									//��Ƶ��Ϣ,����	
}IPC_PLAYER_INFO,*PIPC_PLAYER_INFO;
#endif//IPC_PLAYER_INFO_STRUCT

#ifndef IPC_PLAYER_FRAME_STRUCT
#define IPC_PLAYER_FRAME_STRUCT
typedef	struct tagIPC_PLAYER_FRAME
{
	long			lType;											//֡����,0:I,1:P,2:B,3:A
	unsigned char	*pBuf;											//֡���ݻ�����
	long			lBufSize;										//֡���ݻ�������С
	ULONGLONG		ullStartTime;									//���ſ�ʼʱ��
	ULONGLONG		ullEndTime;										//���Ž���ʱ��
	IPC_PLAYER_INFO	    stHeadInfo;										//����ͷ��Ϣ���ǿ��򲥷ſ����³�ʼ��
}IPC_PLAYER_FRAME,*PIPC_PLAYER_FRAME;
#endif//IPC_PLAYER_FRAME_STRUCT

typedef struct _tagIPC_SupportStream
{
	DWORD dwValue[4];
	DWORD dwHeight[4];
	DWORD dwRate[4];
}IPC_SupportStream;

//�ƶ���ⴰ����Ϣ
typedef struct tagIPC_MontionDetectionWindowInfo
{
	tagIPC_MontionDetectionWindowInfo()
	{
		memset(this, 0, sizeof(tagIPC_MontionDetectionWindowInfo));
	}
	int          index;													//����id ��Χ1~4		
	CHAR         name[128] ;											//��������			
	RECT         rect ;													//�������䣬ΪRECT�ṹ��
																		//��Ƶͼ�񱻷ֳ�12x8=96 ������ ��x,y ��ȷ�����Ͻǣ�right,bottom����ȷ�����½ǡ����½ǵ�����һ��Ҫ�������Ͻǵ�����
																		//x ȡֵ��Χ[0, 11].     y ȡֵ��Χ [0, 7].     right ȡֵ��Χ [1, 12].     width ȡֵ��Χ [1, 8].
																		//���磺 rect Ϊ{x=1��y=1 ��right=2��bottom=2} ��ʾռ��(1,1),(1,2),(2,1),(2,2)�ĸ�����

	INT          agile;													//������ ��Χ[0, 10]		
	INT          threshold;												//��ֵ ��Χ[1, 100]  				
}IPC_MontionDetectionWindowInfo,*LPIPC_MontionDetectionWindowInfo ;

//H264
typedef struct tagIPC_H264
{ 	
	tagIPC_H264()
	{
		memset(this, 0, sizeof(tagIPC_H264));
	}
	DWORD   sn_m;			 											//Mֵ��ȡֵ��ΧΪ��1�� 2�� 3 ��		 
	DWORD   sn_n;			 											//Nֵ��ȡֵ��ΧΪ1 ��255	
	DWORD   sn_idrInterval;	 											//IDR�����ȡֵ��ΧΪ1 ��100	
	DWORD   sn_brc; 		 											//�����ʿ��ƣ�0ΪCBR��1ΪVBR��2ΪCBR (keep quality) ��3ΪVBR (keep quality)	  
	DWORD   sn_cbr; 		 											//������ƽ��ֵ������1000000��8000000֮��	  
	DWORD   sn_vbr_min;	     											//��С�����ʣ�bps����Ĭ��Ϊ1000000
	DWORD   sn_vbr_max;	     											//�������� ��bps����Ĭ��Ϊ8000000	
} IPC_H264, *LPIPC_H264;

//��Ƶ����
typedef struct tagIPC_ENCSN
{
	tagIPC_ENCSN()
	{
		memset(this, 0, sizeof(tagIPC_ENCSN));
	}
	DWORD	sn_stream; 												//����id�� 0Ϊ����1��1Ϊ����2��2Ϊ����3��3Ϊ����4
	DWORD	sn_fps;													//����֡��, 60fps ֵΪ8533333��30fpsֵΪ 17066667��25fps ֵΪ20480000
	DWORD 	sn_width;												//�����ֱ��ʵĿ�
	DWORD	sn_height;												//�����ֱ��ʵĸ�
	DWORD	sn_rotate;												//����/��ת, 0������ 1��ˮƽ���� 2����ֱ����  3 : ��ת 180 4 : ��ת 90,7 : ��ת 270
	DWORD	sn_type;												//�����ʽ 1:H.264  2:MJPEG	
	IPC_H264	sn_h264;    											
	DWORD   sn_quality ;											//MJPEG��������,ȡֵ��ΧΪ1 �� 100			
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
	CHAR	sSerialNumber[64];						//�豸���к�							
	DWORD	dwAlarmInPortNum;						//�����������
	DWORD   dwAlarmOutPortNum;						//�����������
	DWORD   dwIPCType;								//�豸����		

	DWORD   dwMaxChan;								//�豸���֧�ֵ�ͨ������
	DWORD   dwStartChan;							//��ʼͨ���ţ�Ŀǰ�豸ͨ���Ŵ�0��ʼ
	DWORD   dwStreamProto;							//��������Э������:0-˽��TCP,1-rtsp(tcpЭ��)����,2-rtsp(udpЭ��)����,3-rtsp(udpЭ��)�鲥
	DWORD   dwSupport;								//������λ����Ϊ0��ʾ��֧�֣�1��ʾ֧��
														//	bySupport & 0x1,	��ʾ�Ƿ�֧��snmp v30
														//	bySupport & 0x2,	��ʾ�Ƿ�֧�ֲ������ȼ�
														//	bySupport & 0x4��	��ʾ�Ƿ�֧��ѹ������������ȡ(IPC_STREAMINFO_V3)
														//	bySupport & 0x8��	��ʾ�Ƿ�֧��GB

														//	bySupport & 0x10��	��ʾ�Ƿ�֧���������� (�����豸��¼����Ϣ�Լ��ƶ���ⴰ����Ϣ NET_DVR_SmartSearch) ��֧��
														//	bySupport & 0x20��	��ʾ�Ƿ�֧�ֱ���	��֧��
														//	bySupport & 0x40,	��ʾ֧��Զ��SADP(SADPЭ�飬�����ʵʱ����ͬһ�������ڵ���Ƶ�����������ɶ���Ƶ��������IP��ַ������˿ںš�������Ϣ�����޸�)
														//	bySupport & 0x80,	��ʾ֧��Raid������(Redundant Array of Independent Disks ��������) ��֧��
														//	bySupport & 0x100,	��ʾ֧��IPSANĿ¼����				��֧��
														//	bySupport & 0x200,	��ʾ֧��rtp over rtsp				��֧�� 
														//	bySupport & 0x400,	��ʾ�Ƿ�֧�����ֻطź�����			��֧��
														//	bySupport & 0x800,	��ʾ�����豸�Ƿ�֧�ֲ���ʱ�����չ	��֧��
														//	bySupport & 0x1000,	��ʾ�Ƿ�֧�ֶ������������33����	��֧��
														//	bySupport & 0x2000,	��ʾ�Ƿ�֧��rtsp over http			��֧��
														//	bySupport & 0x4000,	��ʾ�Ƿ�֧����ʱԤ��				��֧��
														//	bySupport & 0x8000, ��ʾ�������Ƿ�֧��ͨ��URLȡ������	��֧��	
														//	bySupport & 0x10000,��ʾ�Ƿ�֧��˫����	��֧��	
	DWORD   dwDiskNum;								//Ӳ�̸���							 (��֧��)
	DWORD   dwAudioChanNum;							//�豸����ͨ����					 (��֧�֡���)
	DWORD   dwIPChanNum;							//�豸�������ͨ������				 (��֧�֡���)
	DWORD   dwZeroChanNum;							//��ͨ���������					 (��֧�֡���)			
	CHAR    sRes2[14];								//��������Ϊ0							
}IPC_NET_DEVICE_INFO,*LPIPC_NET_DEVICE_INFO;


////��Ƶͼ�����
typedef struct tagIPC_VIDEO_PARAMCFG
{	tagIPC_VIDEO_PARAMCFG()
	{
		memset(this, 0, sizeof(tagIPC_VIDEO_PARAMCFG));
	}

	DWORD	dwMaxGainValue;				//MAX_GAIN �������ֵ����λdB //30db, 36db, 42db, 48db, 54db, 60db
	DWORD	dwWhiteBalanceMode;			//WBC_MODE��ƽ������:0: �Զ�;1:�׳�;2:d4000;3: d5000;4: ����;5: ����;
										//6: ����;7: ӫ��;8: ��ӫ��;9: ˮ��;10:�ֶ���ƽ��;11: �ر�
	DWORD	dwWhiteBalanceModeRGain;	//WBC_CUSTOM_R_GAIN�ֶ���ƽ��ʱ��Ч���ֶ���ƽ��R����	0~1023						
	DWORD	dwWhiteBalanceModeBGain;	//WBC_CUSTOM_B_GAIN�ֶ���ƽ��ʱ��Ч���ֶ���ƽ��B���� 0~1023
	DWORD	dwTargetRation ;			//AE_TARGET_RATION �ع�Ŀ��ϵ��	25~400
	DWORD	dwLocalExposureMode ;		//LOCAL_EXPOSURE �ֲ��ع�ģʽ0 : �ر�; 1: ��; 2: ��ͣ; 3: 2x; 4:3x; 5:4x
	DWORD	dwSlowShutterEnable ;		//SLOW_SHUTTER �Զ��ع�������SlowShutter  0:�ر�;1:����
	DWORD	dwPreference ;				//AE_PREFERENCE �Զ��ع��ƫ�� 0 : ����ģʽ;1 :����ģʽ;2 : ��Ȧ����
	DWORD	dwMeteringMode ;			//METERING_MODE �Զ��ع������в��ģʽ   0:�۹�;1:����;2:ƽ��
	
	DWORD	dwDayNightFilterTime ;		//�ȴ�ʱ�䣬��ÿ��������ҹ�л����ߵ�ʱ����  3s ~ 30s  Ĭ��10s
	DWORD	dwDayToNightFilterThr ;		//����ģʽתҹ��ģʽ����ֵ	0~100   Ĭ�� 40
	DWORD	dwNightToDayFilterThr ;   	//ҹ��ģʽת����ģʽ����ֵ	0~100 Ĭ�� 60

	DWORD   dwBackLight ;				//BACKLIGHT_COMP ���ⲹ��0-�ر�, 1-����
	DWORD   dwNoiseRemove ;				//MCTF_STRENGTH	3D���� 0~255
	DWORD   dwPowerLineFrequencyMode;	//EXPOSURE_MODE	����˸ģʽ0-50Hz ; 1-60Hz; 2-�Զ�
	DWORD	dwIrisType; 				//ģʽ 0�ر�;1����	
	DWORD	dwIrisQuty; 				//ռ��ֵ 100 ~ 999
	DWORD   dwMJPEGQuality ;			//MJPEG_QUALITY MJPEGʵʱ����ͼ������ 0~100
	DWORD   dwSceneMode;				//DN_MODE ����ģʽ (0 ����,1 ҹ��,2 �Զ�,3 ����)  
	DWORD   dwShutterMin;				//��Сֵ��ȡֵ��ΧΪ64000 �� 20480000	
	DWORD   dwShutterMax;				//���ֵ��ȡֵ��ΧΪ64000 �� 68266667
}IPC_VIDEOPARAMCFG,*LPIPC_VIDEOPARAMCFG;

struct IPC_SYSIPINFOEX : public IPC_SYSIPINFO
{
	DWORD	dwPort;										
};

//not used any all
typedef struct tagIPC_PTZPostionParam
{
	INT		xPostion ;													//ˮƽ���� ����:  ȡֵ��Χ��ipcPTZPostionControl �����������Ӱ�� �� 
																		//����ΪIPC_CMD_PTZ_GOTO_REL_POSITIONʱ��,ȡֵ��Χ-35999��35999
																		//����ΪIPC_CMD_PTZ_GOTO_ABS_POSITIONʱ��,ȡֵ��Χ  0 ��35999

	INT		yPostion ;													//��ֱ�������꣬ȡֵ��Χ��ipcPTZPostionControl �����������Ӱ�� �� 
																		//����ΪIPC_CMD_PTZ_GOTO_REL_POSITIONʱ��,ȡֵ��Χ-9000��9000
																		//����ΪIPC_CMD_PTZ_GOTO_ABS_POSITIONʱ��,ȡֵ��Χ0 ��9000 

	INT		xSpeed ;													//ˮƽ�����ƶ����ٶ�
	INT		ySpeed ;													//��ֱ�����ƶ����ٶ�
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