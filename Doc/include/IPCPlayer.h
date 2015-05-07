#ifndef _IPCVIDEOPLAYER_SDK_H_
#define _IPCVIDEOPLAYER_SDK_H_

#include "IPCSdkDefinesBackup.h"

#ifdef IPCPLAYERSDK_EXPORTS
#define IPCPLAYER_API extern "C" __declspec(dllexport)
#else
#define IPCPLAYER_API extern "C"  __declspec(dllimport)
#endif

#ifndef PLAYERAPI
#define PLAYERAPI __cdecl
#endif


#ifndef PLAYERHANDLE
#define PLAYERHANDLE LPVOID
#endif

//------------------------------------------------------------------------------
#define  IPC_FILEPLAY_BASE	0x00008000

#define  IPC_PLAY_STATE_NONE	            ( IPC_FILEPLAY_BASE + 1 ) //���ļ���
#define  IPC_PLAY_STATE_STOP	            ( IPC_FILEPLAY_BASE + 2 ) //ֹͣ����
#define  IPC_PLAY_STATE_PAUSE	            ( IPC_FILEPLAY_BASE + 3 ) //��ͣ����
#define  IPC_PLAY_STATE_PLAY	            ( IPC_FILEPLAY_BASE + 4 ) //���ڲ���
#define  IPC_PLAY_STATE_FAST	            ( IPC_FILEPLAY_BASE + 5 ) //���ٲ���
#define  IPC_PLAY_STATE_SLOW	            ( IPC_FILEPLAY_BASE + 6 ) //���ٲ���
#define  IPC_PLAY_STATE_BACK_NORMAL	    ( IPC_FILEPLAY_BASE + 7 ) //������
#define  IPC_PLAY_STATE_NORMAL	            ( IPC_FILEPLAY_BASE + 8 ) //������
#define  IPC_PLAY_STATE_BACK_FAST	        ( IPC_FILEPLAY_BASE + 9 ) //�������
#define  IPC_PLAY_STATE_BACK_SLOW	        ( IPC_FILEPLAY_BASE + 10 )//��������
#define  IPC_PLAY_STATE_LOAD	            ( IPC_FILEPLAY_BASE + 11 )//���ڴ��ļ�
#define  IPC_PLAY_STATE_OPEN	            ( IPC_FILEPLAY_BASE + 12 )//�ļ�����ϣ����Կ�ʼ������
#define  IPC_PLAY_STATE_CLOSE	            ( IPC_FILEPLAY_BASE + 13 )//�ر��ļ�
#define  IPC_PLAY_STATE_FILEEND	        ( IPC_FILEPLAY_BASE + 14 )//�ļ��������
#define  IPC_PLAY_STATE_ERROR	            ( IPC_FILEPLAY_BASE + 15 )//�д�����
#define  IPC_PLAY_STATE_INVALID_HANDLE     ( IPC_FILEPLAY_BASE + 16 )//��Ч���
//-------------------------------------------------------------------------------------------------
#define MAX_DISPLAY_WND					4
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
#define IPCPLAYERBASE 0x8000

#define IPC_NOERROR 0
#define IPCPLAYER_NOERROR IPC_NOERROR								//û�д���

#define IPCPLAYER_GENERAL_ERROR			(IPCPLAYERBASE + 0x0001)	//һ���Դ���
#define IPCPLAYER_CREATE_DSHOW_ERROR	(IPCPLAYERBASE + 0x0002)	//����DSHOWʧ��
#define IPCPLAYER_BUF_OVER				(IPCPLAYERBASE + 0x0003)	//����������������ʧ��
#define IPCPLAYER_PARA_OVER				(IPCPLAYERBASE + 0x0004)	//��������Ƿ�
#define IPCPLAYER_ALLOC_MEMORY_ERROR	(IPCPLAYERBASE + 0x0005)	//�����ڴ�ʧ��
#define IPCPLAYER_HEADER_FRAME_ERROR	(IPCPLAYERBASE + 0x0006)	//�����ݵ���ͷ�д���
#define IPCPLAYER_ORDER_ERROR			(IPCPLAYERBASE + 0x0007)	//����˳����ȷ
#define IPCPLAYER_FILEPATH_ERROR		(IPCPLAYERBASE + 0x0008)	//�ļ�·������ȷ

#define IPCPLAYER_VIDEO_FRAME_ERROR		(IPCPLAYERBASE + 0x0009)	//��Ƶ֡�����д�
#define IPCPLAYER_VIDEO_SOURCE_ERROR	(IPCPLAYERBASE + 0x000A)	//����ƵԴ����ʧ��
#define IPCPLAYER_VIDEO_DECODER_ERROR	(IPCPLAYERBASE + 0x000B)	//����Ƶ����������ʧ��
#define IPCPLAYER_VIDEO_RENDER_ERROR	(IPCPLAYERBASE + 0x000C)	//����Ƶ��ʾ����ʧ��
#define IPCPLAYER_VIDEO_CONNECT_ERROR	(IPCPLAYERBASE + 0x000D)	//����Ƶ����������ʧ��

#define IPCPLAYER_AUDIO_FRAME_ERROR		(IPCPLAYERBASE + 0x000E)	//��Ƶ֡�����д�
#define IPCPLAYER_AUDIO_SOURCE_ERROR	(IPCPLAYERBASE + 0x000F)	//����ƵԴ����ʧ��
#define IPCPLAYER_AUDIO_DECODER_ERROR	(IPCPLAYERBASE + 0x0010)	//����Ƶ����������ʧ��
#define IPCPLAYER_AUDIO_GRABBER_ERROR	(IPCPLAYERBASE + 0x0011)	//����Ƶ����������ʧ��
#define IPCPLAYER_AUDIO_RENDER_ERROR	(IPCPLAYERBASE + 0x0012)	//����Ƶ��ʾ����ʧ��
#define IPCPLAYER_AUDIO_CONNECT_ERROR	(IPCPLAYERBASE + 0x0013)	//����Ƶ����������ʧ��

#define IPC_PLAYER_INVALID_HANDLE       (IPCPLAYERBASE + 0x0014)	//��Ч���
//-------------------------------------------------------------------------------------------------
#pragma pack (push , 1)
#ifndef IPC_VIDEO_INFO_STRUCT
#define IPC_VIDEO_INFO_STRUCT
typedef struct
{
	long	lWidth;							//ͼ���
	long	lHeight;						//ͼ���
	long	lFouCC;							//���뷽ʽ	 0:H264 ,1:MJPEG
	long	lFrameRate;						//֡��
}IPC_VIDEO_INFO,*PIPC_VIDEO_INFO;
#endif//IPC_VIDEO_INFO_STRUCT

#ifndef IPC_AUDIO_INFO_STRUCT
#define IPC_AUDIO_INFO_STRUCT
typedef struct
{
	long	lAudioFormat;					//0:AMR; 1:G711-Alaw

	long	lSamplesPerSec;					//����Ƶ��:8000,
	long	lBitsPerSample;					//��������:8,
	long	lChannels;						//����:1,
	long	lAvgBytesPerSec;				//ƽ������:8000
}IPC_AUDIO_INFO,*PIPC_AUDIO_INFO;
#endif//IPC_AUDIO_INFO_STRUCT

#ifndef IPC_PLAYER_INFO_STRUCT
#define IPC_PLAYER_INFO_STRUCT
typedef struct tagIPC_PLAYER_INFO
{
	IPC_VIDEO_INFO			videoInfo;		//��Ƶ��Ϣ
	IPC_AUDIO_INFO			audioInfo;		//��Ƶ��Ϣ

}IPC_PLAYER_INFO,*PIPC_PLAYER_INFO;
#endif//IPC_PLAYER_INFO_STRUCT

#ifndef IPC_PLAYER_FRAME_STRUCT
#define IPC_PLAYER_FRAME_STRUCT
typedef	struct tagIPC_PLAYER_FRAME
{

	long			lType;					//֡����,��I��,��P��,��B��,��A��
	unsigned char	*pBuf;					//֡���ݻ�����
	long			lBufSize;				//֡���ݻ�������С
	ULONGLONG		ullStartTime;			//���ſ�ʼʱ��
	ULONGLONG		ullEndTime;				//���Ž���ʱ��

}IPC_PLAYER_FRAME,*PIPC_PLAYER_FRAME;
#endif//IPC_PLAYER_FRAME_STRUCT

typedef struct
{
	DWORD            nType ;                  //��������, 0:YUY2,1:YUV420,2:PCM
	DWORD	         nWidth;				  //ͼ���  or ��ƵΪͨ����
	DWORD	         nHeight;			      //ͼ���  or ��ƵΪλ�� 
	DWORD	         nFrameRate;              //��Ƶ֡��	  or ��ƵΪ������ 
	DWORD			 nStamp ;				  //����Ƶ��ʱ���

}IPC_PLAYER_AV_FRAME,*LPIPC_PLAYER_AV_FRAME ;

#pragma pack (pop)

typedef struct tagIPC_PLAYOSDParamA
{
	bool		text ;						//�Ƿ���ʾ������Ϣ
	long		text_x;						//������ʾ����
	long		text_y;
	long		text_lWidth;
	long		text_lHeight;     
	LOGFONTA	text_font ;					//����
	COLORREF	text_crColor ;				//������ɫ
	wchar_t		text_context[256] ;			//�ı�����

	bool		picture;					//�Ƿ���ʾͼƬ
	long		pic_x;						//ͼƬ��ʾ����
	long		pic_y;
	long		pic_lWidth;
	long		pic_lHeight;     

	COLORREF	pic_crMask ;				//ͼƬ��ɫ
	long		pic_data_len ;				//ͼƬ���ݳ���
	BYTE*		pic_data ;					//ͼƬ����

}IPC_PLAYOSDPARAMA,*LPIPC_PLAYOSDPARAMA;

typedef struct tagIPC_PLAYOSDParamW
{
	bool		text ;						//�Ƿ���ʾ������Ϣ
	long		text_x;						//������ʾ����
	long		text_y;
	long		text_lWidth;
	long		text_lHeight;     
	LOGFONTW	text_font ;					//����
	COLORREF	text_crColor ;				//������ɫ
	wchar_t		text_context[256] ;			//�ı�����

	bool		picture;					//�Ƿ���ʾͼƬ
	long		pic_x;						//ͼƬ��ʾ����
	long		pic_y;
	long		pic_lWidth;
	long		pic_lHeight;     

	COLORREF	pic_crMask ;				//ͼƬ��ɫ
	long		pic_data_len ;				//ͼƬ���ݳ���
	BYTE*		pic_data ;					//ͼƬ����

}IPC_PLAYOSDPARAMW,*LPIPC_PLAYOSDPARAMW;

#ifdef _UNICODE
#define tagIPC_PLAYOSDParam tagIPC_PLAYOSDParamW
#define IPC_PLAYOSDPARAM IPC_PLAYOSDPARAMW
#define LPIPC_PLAYOSDPARAM LPIPC_PLAYOSDPARAMW
#else 
#define tagIPC_PLAYOSDParam tagIPC_PLAYOSDParamA
#define IPC_PLAYOSDPARAM IPC_PLAYOSDPARAMA
#define LPIPC_PLAYOSDPARAM LPIPC_PLAYOSDPARAMA
#endif

//�����豸
typedef struct
{ 
	INT		iId;											//�����豸id 
	CHAR	sDevName[128];									//�����豸���� 
}IPC_AUDIO_DEVICE,*LPIPC_AUDIO_DEVICE ;

//#include "IPCFilePlayer.h"

typedef void (WINAPI *ipcVideoYUV_CallBack)( PLAYERHANDLE handle, IPC_PLAYER_FRAME * frame, CHAR* data,INT nLen, LPVOID pContext) ;

typedef void (WINAPI *ipcAVFrame_CallBack)( PLAYERHANDLE handle, IPC_PLAYER_AV_FRAME * frame, CHAR* data,INT nLen, LPVOID pContext) ;

typedef void (WINAPI *ipcDraw_CallBack)( PLAYERHANDLE handle, HDC hdc, LPVOID pContext) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcLocalAudio_CallBack
//
//  ��    ����	
//			 [in]	type		: ��Ƶ��������0:AMR; 1:G711Alaw;2:PCM (ԭʼ��Ƶ��ʽ ������8000,λ��16,����1)
//			 [in]	pDataBuffer	: ��Ƶ���ݻ�����
//			 [in]	DataLength	: ��Ƶ���ݳ��� 
//			 [in]	pUser		: �û�����
//
//  ˵    ����  ��Ƶ�ɼ��ص�����������
//
//  �� �� ֵ���ޣ�
//-----------------------------------------------------------------------------------------
typedef void (WINAPI *ipcLocalAudio_CallBack)(DWORD type, LPBYTE pDataBuffer, DWORD DataLength, LPVOID pUser) ; 

//-----------------------------------------------------------------------------------------
//  �� �� ��: IPCPLAYER_MESSAGE_CALLBACK(DWORD dwCode, VOID *context)
//
//  ��    ����	
//			 [in]	dwCode		: ������һ��32λ������16λΪ�ı��״̬ ������״̬�궨�壻
//			 [in]	context		: �����û�ע��ص�����ʱ��������Զ������ݣ�
//
//  ˵    ��������״̬�ص�������
//
//  �� �� ֵ���ޣ�
//-----------------------------------------------------------------------------------------
typedef VOID (CALLBACK* IPCPLAYER_MESSAGE_CALLBACK)(DWORD dwCode, VOID *context) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: IPCPLAYER_AVFRAME_CALLBACKEX(LPBYTE data,DWORD size,LPIPC_PLAYER_AV_FRAME pInfo,LPVOID pContext )
//
//  ��    ����	
//			 [in]	data		  : ��������ݣ�
//			 [in]	size		  : ���ݳ��ȣ�
//			 [in]	pInfo		  : ������Ϣ
//			 [in]	pContext	  : �����û�ע��ص�����ʱ��������Զ�������
//
//  ˵    ������Ƶ��Ƶ����ص���
//
//  �� �� ֵ���ޣ�
//-----------------------------------------------------------------------------------------
typedef VOID (CALLBACK* IPCPLAYER_AVFRAME_CALLBACKEX)(LPBYTE data,DWORD size,LPIPC_PLAYER_AV_FRAME pInfo,LPVOID pContext );


//-----------------------------------------------------------------------------------------
//  �� �� ��: IPCPLAYER_AVFRAME_CALLBACK(LPBYTE data,DWORD size,DWORD type,DWORD width,DWORD height,LPVOID pContext )
//
//  ��    ����	
//			 [in]	data		  : �����YUY2���ݣ�
//			 [in]	size		  : ���ݳ��ȣ�
//			 [in]	type		  : ���������ݸ�ʽ
//			 [in]	width		  : ͼ����
//			 [in]	height		: ͼ��߶�
//			 [in]	pContext	: �����û�ע��ص�����ʱ��������Զ�������
//
//  ˵    ������Ƶ��Ƶ����ص���
//
//  �� �� ֵ���ޣ�
//-----------------------------------------------------------------------------------------
typedef VOID (CALLBACK* IPCPLAYER_AVFRAME_CALLBACK)(LPBYTE data,DWORD size,DWORD type,DWORD width,DWORD height,LPVOID pContext );


//���ص�
typedef VOID (CALLBACK* IPCPLAYER_MOUSE_CALLBACK)(INT x, INT y, INT event, VOID *context );


//API����   

// ASF�ļ����Ų���

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Init( HWND hWnd,DWORD dwFlags,DWORD dwDisFmt,DWORD dwAudFmt )
//
//  ��    ����	
//			 [in]	hWnd		  : ��������ʾ���ھ����
//			 [in]	dwFlags		: ����������<ֻ��ΪH264_DECODER_ID_BKASF>��
//			 [in]	dwDisFmt	: ��ʾSurface����<�ò����ݱ�����>��
//			 [in]	dAudFmt		: ����������ʽ<�ò����ݱ�����>��
//
//  ˵    ������ʼ����������ÿ�ε��ó�ʼ��һ����������
//
//  �� �� ֵ����ʼ����ȷ���ظò���ͨ�����ƾ�������󷵻�NULL��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API HANDLE PLAYERAPI ipcAvFileDec_Init( HWND hWnd,DWORD dwFlags,DWORD dwDisFmt,DWORD dwAudFmt );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Done( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//
//  ˵    �����ͷŲ�������Դ��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Done( HANDLE hAndle );

#ifdef _UNICODE
#define ipcAvFileDec_SetFileName ipcAvFileDec_SetFileNameW
#else
#define ipcAvFileDec_SetFileName ipcAvFileDec_SetFileNameA
#endif

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetFileName( HANDLE hAndle, LPCTSTR lpFileName, LPCTSTR lpAudioFile, BOOL bPlay )
//
//  ��    ����	
//			 [in]	hAndle		    : ͨ�����ƾ����
//			 [in]	lpFileName		: �ļ�����
//			 [in]	lpAudioFile		: ������Ƶ�ļ�����
//			 [in]	bPlay			: �Զ����ű�־��
//
//  ˵    �������ò����ļ���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetFileNameA( HANDLE hAndle, LPCSTR lpFileName, LPCSTR lpAudioFile, BOOL bPlay ) ;



//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetFileNameW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpAudioFile, BOOL bPlay )
//
//  ��    ����	
//			 [in]	hAndle		    : ͨ�����ƾ����
//			 [in]	lpFileName		: �ļ�����
//			 [in]	lpAudioFile		: ������Ƶ�ļ�����
//			 [in]	bPlay			: �Զ����ű�־��
//
//  ˵    �������ò����ļ���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetFileNameW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpAudioFile, BOOL bPlay );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CloseFile( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//
//  ˵    �����رղ������е�ǰ�򿪵��ļ���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CloseFile( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Play( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//
//  ˵    �������ò�����Ϊ����״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Play( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Stop( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//
//  ˵    �������ò�����Ϊֹͣ״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Stop( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_RePlay( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//
//  ˵    �������ò�����Ϊ���²���״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RePlay( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Pause( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//
//  ˵    �������ò�����Ϊ��ͣ״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Pause( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Fast( HANDLE hAndle, float fRate )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//			 [in]	fRate		  : �������ʣ�
//
//  ˵    �������ò�����Ϊ���״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Fast( HANDLE hAndle, float fRate );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Slow( HANDLE hAndle, float fRate )
//
//  ��    ����	
//			 [in]	hAndle		: ͨ�����ƾ����
//			 [in]	fRate		  : �������ʣ�
//
//  ˵    �������ò�����Ϊ����״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Slow( HANDLE hAndle, float fRate );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_StepFrame( HANDLE hAndle, BOOL bForward )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	bForward	: ������ļ�ǰ��֡��־��
//
//  ˵    �������ò�����Ϊ��֡����״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_StepFrame( HANDLE hAndle, BOOL bForward );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Forward( HANDLE hAndle, DWORD dwOffset )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	dwOffset	: ƫ������
//
//  ˵    �����ļ�ǰ��һ�Σ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Forward( HANDLE hAndle, DWORD dwOffset );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_Backward( HANDLE hAndle, DWORD dwOffset )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	dwOffset	: ƫ������
//
//  ˵    �����ļ�����һ�Σ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Backward( HANDLE hAndle, DWORD dwOffset );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetVolume( HANDLE hAndle, LONG* lVolume )
//
//  ��    ����	
//			 [in]  hAndle	  : ͨ�����ƾ����
//			 [out] lVolume	  : �����ٷֱ�ֵ��
//
//  ˵    ������ȡ�����ٷֱȣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetVolume( HANDLE hAndle, LONG* lVolume );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetVolume( HANDLE hAndle, LONG lVolume )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]   lVolume	  : �����ٷֱ�ֵ��
//
//  ˵    �������������ٷֱȣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetVolume( HANDLE hAndle, LONG lVolume );



//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetMute( HANDLE hAndle, BOOL* bMute )
//
//  ��    ����	
//			 [in]  hAndle	  : ͨ�����ƾ����
//			 [out] bMute	  : ������־��
//
//  ˵    ������ȡ����������־��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetMute( HANDLE hAndle, BOOL* bMute );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetMute( HANDLE hAndle, BOOL bMute )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]   bMute	  : ������־��
//
//  ˵    ������������������־��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetMute( HANDLE hAndle, BOOL bMute );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetDisplayVisible( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    ������ȡ����ͼ���Ƿ���ʾ�����
//
//  �� �� ֵ�����ؽ���ͼ���Ƿ���ʾ�����
//-----------------------------------------------------------------------------------------
IPCPLAYER_API BOOL PLAYERAPI ipcAvFileDec_GetDisplayVisible( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetDisplayVisible( HANDLE hAndle, BOOL bShow )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	bShow	    : ����ͼ���Ƿ���ʾ�����
//
//  ˵    �������ý�����ʾ������أ��ر���ʾ���ʱ���������ļ���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetDisplayVisible( HANDLE hAndle, BOOL bShow );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetDisplayPos( HANDLE hAndle, RECT *lpRect )
//
//  ��    ����	
//			 [in]	 hAndle	  : ͨ�����ƾ����
//			 [out] lpRect	  : ��ʾ���ο�
//
//  ˵    ������ȡ������ʾ���ο�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetDisplayPos( HANDLE hAndle, RECT *lpRect );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetDisplayPos( HANDLE hAndle, RECT *lpRect )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in] lpRect	  : ��ʾ���ο�
//
//  ˵    �������ò�����ʾ���ο�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetDisplayPos( HANDLE hAndle, RECT *lpRect );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetFullScreen( HANDLE hAndle, RECT* lpRect )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [out] lpRect	  : ȫ����ʾ���ο�
//
//  ˵    ���������û�����ȫ����ʾ״̬��
//
//  �� �� ֵ���Ż��Ƿ����û�ȫ����ʾ״̬��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API BOOL PLAYERAPI ipcAvFileDec_GetFullScreen( HANDLE hAndle, RECT* lpRect );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetFullScreen( HANDLE hAndle, BOOL bFull, HWND hWnd, RECT* lpRect )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	bFull	    : �Ƿ���Ҫȫ����ʾ��
//			 [in] lpRect	  : ��ʾ���ο�
//
//  ˵    �������û���Ҫ���Լ��Ĵ�����ȫ����ʾʱ��������ô˺�����
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetFullScreen( HANDLE hAndle, BOOL bFull, HWND hWnd, RECT* lpRect );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetZoom( HANDLE hAndle, RECT* lpRect )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [out]	lpRect	  : ��žֲ��Ŵ���ο��ָ�룻
//
//  ˵    ������ȡ��ǰ�ֲ��Ŵ�״̬��������ô˺�����
//
//  �� �� ֵ�����ص�ǰ�Ƿ��ھֲ��Ŵ�״̬��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API BOOL PLAYERAPI ipcAvFileDec_GetZoom(HANDLE hAndle, RECT* lpRect);

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetZoom(HANDLE hAndle, BOOL bZoom, RECT* lpRect)
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ��;
//			 [in]   bZoom	  : �Ƿ�ֲ��Ŵ�;
//			 [in]	lpRect	  : �ֲ��Ŵ���ο�;
//
//  ˵    �������þֲ��Ŵ󣬱�����ô˺���;
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0;
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetZoom(HANDLE hAndle, BOOL bZoom, RECT* lpRect);

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetDisplayRegion(HANDLE hAndle,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable)
//
//  ��    ����	
//			 [in]	hPlayer	    : ͨ�����ƾ����
//			 [in]	nRegionNum	: ��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������.
//                          ������hDestWnd��
//			 [in]	rcSrc	      : �ֲ���ʾ����
//			 [in]	hDestWnd	  : ��ʾ���ھ����
//			 [in]	bEnable	    : ��(����)��ر���ʾ����
//
//  ˵    �������û�������ʾ����,�������ֲ��Ŵ���ʾ��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetDisplayRegion(HANDLE hAndle,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable);


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_RefreshDisplayRegion(HANDLE hAndle,DWORD nRegionNum)
//
//  ��    ����
//			 [in]	hPlayer	   : ͨ�����ƾ����	
//			 [in]	nRegionNum : ��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ���������У�
//
//  ˵    ����ˢ�¶�������ʾ�Ĵ��ڣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RefreshDisplayRegion(HANDLE hAndle,DWORD nRegionNum);

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetImageWidth( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    ������ȡ��ǰ�����ļ���Ƶͼ���ȣ�
//
//  �� �� ֵ����ȷ���ص�ǰ�����ļ���Ƶͼ���ȣ�
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetImageWidth( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetImageHeight( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    ������ȡ��ǰ�����ļ���Ƶͼ��߶ȣ�
//
//  �� �� ֵ����ȷ���ص�ǰ�����ļ���Ƶͼ��߶ȣ�
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetImageHeight( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetTotalFrames( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    ������ȡ��ǰ�����ļ�����֡����
//
//  �� �� ֵ�������ش���0ʱ�ű�ʾ��ȷ�õ���֡����С��0��ʧ�ܣ�
//-----------------------------------------------------------------------------------------
IPCPLAYER_API LONG PLAYERAPI ipcAvFileDec_GetTotalFrames( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetCurrentPosition( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    �����õ���ǰ�ļ����ŵ�֡λ�ã�
//
//  �� �� ֵ�������ش���0ʱ�ű�ʾ��ȷ�õ�֡λ�ã�С��0��ʧ�ܣ�
//-----------------------------------------------------------------------------------------
IPCPLAYER_API LONG PLAYERAPI ipcAvFileDec_GetCurrentPosition( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetCurrentPosition( HANDLE hAndle, LONG lPosition )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	lPosition	: ֡λ�ã�
//
//  ˵    �������õ�ǰ��Ƶ���ŵ�֡λ�ã�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetCurrentPosition( HANDLE hAndle, LONG lPosition );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetTotalTime( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    �����õ���ǰ�����ļ�����ʱ�䣻
//
//  �� �� ֵ�����ش򿪵��ļ���ʱ��(��λ��)��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API FLOAT PLAYERAPI ipcAvFileDec_GetTotalTime( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetCurrentTime( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    �����õ���ǰ�ļ�����ʱ�䣻
//
//  �� �� ֵ�����ص�ǰ�ļ�����ʱ��(��λ��)��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API FLOAT PLAYERAPI ipcAvFileDec_GetCurrentTime( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_SetCurrentTime( HANDLE hAndle, FLOAT dwTime )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//			 [in]	dwTime	  : �������ʱ�䣻
//
//  ˵    �������ò��ŵ����ʱ�䣻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetCurrentTime( HANDLE hAndle, FLOAT dwTime );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_GetCurrentState( HANDLE hAndle )
//
//  ��    ����	
//			 [in]	hAndle	  : ͨ�����ƾ����
//
//  ˵    �����õ���������ǰ״̬��
//
//  �� �� ֵ�����ز���״̬��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetCurrentState( HANDLE hAndle );

#ifdef _UNICODE
#define ipcAvFileDec_CapturePicture ipcAvFileDec_CapturePictureW
#else
#define ipcAvFileDec_CapturePicture ipcAvFileDec_CapturePictureA
#endif

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CapturePictureA( HANDLE hAndle, LPCSTR lpFileName, LPCSTR lpPicFormat )
//
//  ��    ����	
//			 [in]	hAndle	      : ͨ�����ƾ����
//			 [in]	lpFileName	  : �ļ�����
//			 [in]	lpPicFormat	  : ͼ���ʽ����������
//
//  ˵    ��������ǰ��ʾ֡��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictureA( HANDLE hAndle, LPCSTR lpFileName, LPCSTR lpPicFormat );

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CapturePictureW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpPicFormat )
//
//  ��    ����	
//			 [in]	hAndle	      : ͨ�����ƾ����
//			 [in]	lpFileName	  : �ļ�����
//			 [in]	lpPicFormat	  : ͼ���ʽ����������
//
//  ˵    ��������ǰ��ʾ֡��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictureW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpPicFormat );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CapturePictToBuff( HANDLE hAndle,BYTE* buff,LONG* len)
//
//  ��    �� ��	
//			 [in]	    hAndle	      : ͨ�����ƾ����
//			 [out]	    buff		  : ����ͼ�����ݣ��ò�������NULL��ֻ������Ҫ�Ļ��泤�ȣ�����Ϊ����BITMAPINFOHEADER ��λͼ���ݣ���BITMAPFILEHEADER
//			 [in/out]	len			  : ����ͼ�����ݳ��ȣ�
//  ˵    ��������ǰ��ʾ֡���ݵ��ڴ棻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictToBuff( HANDLE hAndle,BYTE* buff,LONG* len) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CapturePictToBuffEx( HANDLE hAndle,BYTE* buff,LONG* len)
//
//  ��    �� ��	
//			 [in]	    hAndle	      : ͨ�����ƾ����
//			 [out]	    buff		  : ����ͼ�����ݣ��ò�������NULL��ֻ������Ҫ�Ļ��泤�ȣ�����Ϊ����BITMAPFILEHEADER��BITMAPINFOHEADER��λͼ����
//			 [in/out]	len			  : ����ͼ�����ݳ��ȣ�
//  ˵    ��������ǰ��ʾ֡���ݵ��ڴ棻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictToBuffEx( HANDLE hAndle,BYTE* buff,LONG* len); 

//  ������hAndleΪͨ�����ƾ����
//  ˵�����ú���������Ч��
//  ���أ���ȷ����0�����󷵻ط�0��
//IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetVideoParam( HANDLE hAndle, INT* iBrightness, INT* iContrast, INT* iSaturation, INT* iHue );


//  ������hAndleΪͨ�����ƾ����
//  ˵�����ú���������Ч��
//  ���أ���ȷ����0�����󷵻ط�0��
//IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetVideoParam( HANDLE hAndle, INT iBrightness, INT iContrast, INT iSaturation, INT iHue );


//  ������hAndleΪͨ�����ƾ��, p�����������Ϣ��flag��Ƶ����Ƶ 
//  ���أ���ȷ����0�����󷵻ط�0��
//IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetStreamDescription( HANDLE hAndle, IPCPLAYER_StreamDescription_t *p, INT flag );


#ifdef _UNICODE
#define ipcAvFileDec_Cut ipcAvFileDec_CutW
#else
#define ipcAvFileDec_Cut ipcAvFileDec_CutA
#endif
//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CutA( HANDLE hAndle, CHAR *pDestFileName, INT iStartTime, INT iEndTime )
//
//  ��    ����	
//			 [in]	hAndle	       : ͨ�����ƾ����
//			 [in]	pDestFileName  : Ŀ���ļ�·����
//			 [in]	iStartTime	   : ��ʼʱ��㣬��λs�����ô����ļ���ʱ�䳤�ȣ�
//			 [in]	iEndTime	   : ����ʱ���, ��λs,���ô����ļ���ʱ�䳤�ȣ�
//
//  ˵    ������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CutA(HANDLE hAndle, CHAR *pDestFileName, INT iStartTime, INT iEndTime );

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_CutW( HANDLE hAndle, WCHAR *pDestFileName, INT iStartTime, INT iEndTime )
//
//  ��    ����	
//			 [in]	hAndle	       : ͨ�����ƾ����
//			 [in]	pDestFileName  : Ŀ���ļ�·����
//			 [in]	iStartTime	   : ��ʼʱ�䣬��λ�룻
//			 [in]	iEndTime	   : ����ʱ�䣬��λ�룻
//
//  ˵    ������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CutW( HANDLE hAndle, WCHAR *pDestFileName, INT iStartTime, INT iEndTime );

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_RegisterAVMsgCallBack( HANDLE hAndle, IPCPLAYER_MESSAGE_CALLBACK pCallBack,VOID* contextt )
//
//  ��    ����	
//			 [in]	hAndle	      : ͨ�����ƾ����
//			 [in]	pCallBack	    : �ص�����ָ�룻
//			 [in]	contextt	    : Ӧ�ó����ṩ�Ĳ�����
//
//  ˵    �������������в���״̬�ı�ʱ�����ע��Ļص�������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterAVMsgCallBack( HANDLE hAndle, IPCPLAYER_MESSAGE_CALLBACK pCallBack,VOID* contextt );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_RegisterAVFrameCallBack( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACK pCallBack, VOID* context );
//
//  ��    ����	
//			 [in]	hAndle	      : ͨ�����ƾ����
//			 [in]	pCallBack	    : �ص�����ָ�룻
//			 [in]	contextt	    : Ӧ�ó����ṩ�Ĳ�����
//
//  ˵    ���������벥��ʱ��ͨ���ص�������������ݣ�������ƵΪYUV420��ʽ
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterAVFrameCallBack( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACK pCallBack, VOID* context );



//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_RegisterAVFrameCallBackEx( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACKEX pCallBack, VOID* pContext );
//
//  ��    ����	
//			 [in]	hAndle	        : ͨ�����ƾ����
//			 [in]	pCallBack	    : �ص�����ָ�룻
//			 [in]	pContext	    : Ӧ�ó����ṩ�Ĳ�����
//
//  ˵    ���������벥��ʱ��ͨ���ص�������������ݣ�������ƵΪYUV420��ʽ����ƵΪPCM��ʽ
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterAVFrameCallBackEx( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACKEX pCallBack, VOID* pContext );


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcAvFileDec_RegisterMouseCallBack( HANDLE hAndle, IPCPLAYER_MOUSE_CALLBACK pCallBack, VOID* context );
//
//  ��    ����	
//			 [in]	hAndle	        : ͨ�����ƾ����
//			 [in]	pCallBack	    : �ص�����ָ�룻
//			 [in]	contextt	    : Ӧ�ó����ṩ�Ĳ�����
//
//  ˵    ������������ȫ����ʾʱ�ҵ���Avdec_SetFullScreen����ȫ����ʾ�ģ����������¼����������ô˻ص�������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterMouseCallBack( HANDLE hAndle, IPCPLAYER_MOUSE_CALLBACK pCallBack, VOID* context );



//��ʽ���Ų��� ------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcPlayerInitialize()
//
//  ��    ����	
//
//  ˵    �������ſ�ȫ�ֳ�ʼ����
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcPlayerInitialize() ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcPlayerUnInitialize()
//
//  ��    ����	
//
//  ˵    �������ſ�ȫ��������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcPlayerUnInitialize() ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcCreatePlayerEx(PIPC_PLAYER_INFO  pInfo)
//
//  ��    ����	
//			 [in]	pInfo	  : ����Ƶ��������Ϣ��
//
//  ˵    ��������ʵʱ�����ž����
//
//  �� �� ֵ�����ز��ž�������Ϊnull�򴴽�ʧ�ܣ�
//-----------------------------------------------------------------------------------------
IPCPLAYER_API PLAYERHANDLE PLAYERAPI ipcCreatePlayerEx(PIPC_PLAYER_INFO  pInfo) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcCreatePlayerEx2()
//
//  ��    ����	
//
//  ˵    ��������ʵʱ�����ž������չ�ӿڣ�
//
//  �� �� ֵ�����ز��ž�������Ϊnull�򴴽�ʧ�ܣ�
//-----------------------------------------------------------------------------------------
IPCPLAYER_API PLAYERHANDLE PLAYERAPI ipcCreatePlayerEx2() ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcDestroyPlayerEx(PLAYERHANDLE hPlayer)
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//
//  ˵    �����ͷ�ʵʱ�����ž����
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcDestroyPlayerEx(PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcStartEx(PLAYERHANDLE hPlayer)
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//
//  ˵    ������ʼ���ţ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcStartEx(PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcStopEx(PLAYERHANDLE hPlayer)
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//
//  ˵    ����ֹͣ���ţ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcStopEx(PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcStartImageSharpen(PLAYERHANDLE hPlayer,float amount = 1.2f);
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//           [in]	amount    : ͼ���񻯳̶ȣ�Ĭ��Ϊ1.2f����Χ0.0f-5.0f
//
//  ˵    ��������ͼ���񻯣���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcStartImageSharpen(PLAYERHANDLE hPlayer,float amount = 1.2f);


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcChangeSharpenDegree(PLAYERHANDLE hPlayer,float amount);
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//           [in]	amount    : ͼ���񻯳̶ȣ���Χ0.0f-5.0f
//
//  ˵    �����ı�ͼ����񻯳̶ȣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcChangeSharpenDegree(PLAYERHANDLE hPlayer,float amount);


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcStopImageSharpen(PLAYERHANDLE hPlayer);
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//
//  ˵    �����ر�ͼ���񻯣�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcStopImageSharpen(PLAYERHANDLE hPlayer);

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcRegisterYUVCallBackEx( PLAYERHANDLE hPlayer, ipcVideoYUV_CallBack pCallBack, LPVOID context)
//
//  ��    ����	
//			 [in]	hPlayer	    : ʵʱ�����ž����
//			 [in]	pCallBack	: �ص�����ָ�룻
//			 [in]	context	    : �û��Զ������ݣ�
//			 [in]	dwType		: �ص�������Ƶ���ݸ�ʽ��Ĭ��ΪYUY2��1ΪYUV420
//
//  ˵    ����ע�������֡�ص���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcRegisterYUVCallBackEx( PLAYERHANDLE hPlayer, ipcVideoYUV_CallBack pCallBack, LPVOID context, DWORD dwType = 0) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcRegisterAVCallBackEx( PLAYERHANDLE hPlayer, ipcAVFrame_CallBack pCallBack, LPVOID context)
//
//  ��    ����	
//			 [in]	hPlayer	    : ʵʱ�����ž����
//			 [in]	pCallBack	: �ص�����ָ�룻
//			 [in]	context	    : �û��Զ������ݣ�
//			 [in]	dwType		: �ص�������Ƶ���ݸ�ʽ��Ĭ��ΪYUY2��1ΪYUV420
//
//  ˵    ������ʵʱ�����벥��ʱ��ͨ���ص�������������ݣ�������ƵΪYUY2/YUV420��ʽ����ƵΪPCM��ʽ
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcRegisterAVCallBackEx( PLAYERHANDLE hPlayer, ipcAVFrame_CallBack pCallBack, LPVOID context, DWORD dwType = 0) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcRegisterDrawCallBack( PLAYERHANDLE hPlayer, ipcDraw_CallBack pCallBack, LPVOID context)
//
//  ��    ����	
//			 [in]	hPlayer	    : ʵʱ�����ž����
//			 [in]	pCallBack	: �ص�����ָ�룻
//			 [in]	context	    : �û��Զ������ݣ�
//
//  ˵    ���� ע��һ���ص���������õ�ǰ�����device context, ����������DC �ϻ�ͼ����д�֣�
//			 �ͺ����ڴ��ڵĿͻ���DC �ϻ�ͼ�������DC ���Ǵ��ڿͻ�����DC.
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcRegisterDrawCallBack( PLAYERHANDLE hPlayer, ipcDraw_CallBack pCallBack, LPVOID context) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetDisplayRectEx(PLAYERHANDLE hPlayer, HWND hWnd, IN RECT rect)
//
//  ��    ����	
//			 [in]	hPlayer	  : ʵʱ�����ž����
//			 [in]	hWnd	  : ��ʾ���ھ����
//			 [in]	rect	  : ��ʾ�������ꣻ
//
//  ˵    ����������Ƶ��ʾ���ھ�����������ꣻ���hWndΪNULL���򲥷���ֻ�ص��������ݲ�������ʾ���֡�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetDisplayRectEx(PLAYERHANDLE hPlayer, HWND hWnd, IN RECT rect) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetDisplayRectEx(PLAYERHANDLE hPlayer, HWND* hWnd, OUT RECT* rect )
//
//  ��    ����	
//			 [in]  hPlayer	: ʵʱ�����ž����
//			 [out] hWnd	    : ��ʾ���ھ����
//			 [out] rect	    : ��ʾ�������ꣻ
//
//  ˵    ������ȡ��Ƶ��ʾ���ھ�����������ꣻ
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetDisplayRectEx(PLAYERHANDLE hPlayer, HWND* hWnd, OUT RECT* rect ) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetDisplayVisibleEx(PLAYERHANDLE hPlayer, IN BOOL bVal)
//
//  ��    ����	
//			 [in] hPlayer	: ʵʱ�����ž����
//			 [in] bVal	    : ��ʾ״̬��
//
//  ˵    ����������Ƶ�Ƿ���ʾ��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetDisplayVisibleEx(PLAYERHANDLE hPlayer, IN BOOL bVal) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetDisplayVisibleEx(PLAYERHANDLE hPlayer, OUT BOOL* bVal)
//
//  ��    ����	
//			 [in]  hPlayer	: ʵʱ�����ž����
//			 [out] bVal	    : ��ʾ״̬��
//
//  ˵    ������ȡ��Ƶ�Ƿ���ʾ״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetDisplayVisibleEx(PLAYERHANDLE hPlayer, OUT BOOL* bVal) ;

//IPCPLAYER_API INT PLAYERAPI  ipcStartRecordEx( PLAYERHANDLE hPlayer, WCHAR * filePath) ;
//IPCPLAYER_API INT PLAYERAPI  ipcStopRecordEx(  PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcCapturePictureEx(  PLAYERHANDLE hPlayer, int picType, WCHAR* file_name)
//
//  ��    ����	
//			 [in] hPlayer	  : ʵʱ�����ž����
//			 [in] picType	  : ����ͼƬ������,ֵ1ΪBMP��ʽͼƬ��ֵ2ΪJPEG��ʽͼƬ��
//			 [in] file_name	  : ����ͼƬ�ļ���ȫ·����
//
//  ˵    ��������ǰ��ʾ֡���ݵ��ļ���
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcCapturePictureEx(  PLAYERHANDLE hPlayer, int picType, WCHAR* file_name) ; 


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcCapturePicToBuffEx(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len)
//
//  ��    ����	
//			 [in]     hPlayer	 : ʵʱ�����ž����
//			 [in]     picType	 : �������������ã�
//			 [out]    buff	     : ����ͼ�����ݣ��ò�������NULL��ֻ������Ҫ�Ļ��泤��,����Ϊ����BITMAPINFOHEADER BITMAPFILEHEADER��λͼ���ݣ�
//			 [in/out] len	     : ����ͼ�����ݳ��ȣ�
//
//  ˵    ��������ǰ��ʾ֡���ݵ��ڴ棻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcCapturePicToBuffEx(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcCapturePicToBuffEx2(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len)
//
//  ��    ����	
//			 [in]     hPlayer	 : ʵʱ�����ž����
//			 [in]     picType	 : �������������ã�
//			 [out]    buff	     : ����ͼ�����ݣ��ò�������NULL��ֻ������Ҫ�Ļ��泤��,����Ϊ����BITMAPFILEHEADER��BITMAPINFOHEADER��λͼ���ݣ�
//			 [in/out] len	 : ����ͼ�����ݳ��ȣ�
//
//  ˵    ��������ǰ��ʾ֡���ݵ��ڴ棻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcCapturePicToBuffEx2(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetOSDEx( PLAYERHANDLE hPlayer, LPIPC_PLAYOSDPARAM osd_info)
//
//  ��    ����	
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [in]	osd_info	: OSD������Ϣ��
//
//  ˵    ��������OSD��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetOSDEx( PLAYERHANDLE hPlayer, LPIPC_PLAYOSDPARAM osd_info) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD time)
//
//  ��    ����	
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [in]	time		: ���Ż���������ĺ�������ȡֵ��ΧΪ0��1000��Ĭ��ֵΪ135��
//
//  ˵    �������ò��Ż���������ʱ�䣻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD time) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD* time)
//
//  ��    ����	
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [in]	time		: ���Ż���������ĺ�������
//
//  ˵    ������ȡ���Ż���������ʱ�䣻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD* time) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetPlayInfoEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_INFO pInfo)
//
//  ��    ����	
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [in]	pInfo		: ʵʱ��������Ϣ��
//
//  ˵    ������ȡʵʱ��������Ϣ��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetPlayInfoEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_INFO pInfo) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcInputDataEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_FRAME pFrame) 
//
//  ��    ����	
//			 [in] hPlayer	 : ʵʱ�����ž����
//			 [in] pFrame	 : ֡���ݣ�
//
//  ˵    ��������֡���ݣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcInputDataEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_FRAME pFrame) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcInputDataEx2(PLAYERHANDLE hPlayer, BYTE* pFrameBuff, LONG len)
//
//  ��    ����	
//			 [in]	hPlayer	     : ʵʱ�����ž����
//			 [in] pFrameBuff	   : ֡���ݣ�
//			 [in] len	         : ֡���ݳ��ȣ�
//
//  ˵    ����Ϊ����˽��֡���ݵ���չ�ӿڣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcInputDataEx2(PLAYERHANDLE hPlayer, BYTE* pFrameBuff, LONG len) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetAudioVolume(PLAYERHANDLE hPlayer, long val) 
//
//  ��    ����	
//			 [in]	hPlayer	: ʵʱ�����ž����
//			 [in] val	    : ������
//
//  ˵    ��������������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetAudioVolume(PLAYERHANDLE hPlayer, long val) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetAudioVolume(PLAYERHANDLE hPlayer, long* val) 
//
//  ��    ����	
//			 [in]	 hPlayer	: ʵʱ�����ž����
//			 [out] val	    : ������
//
//  ˵    ������ȡ������
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetAudioVolume(PLAYERHANDLE hPlayer, long* val) ;


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetPlayerMode(PLAYERHANDLE hPlayer,DWORD nMode)
//
//  ��    ����
//			 [in]	hPlayer	: ʵʱ�����ž����	
//			 [in]	nMode	  : ����ģʽ���ͣ�0Ϊʵʱ�����ţ�1Ϊ�ļ������ţ�
//
//  ˵    �������ò��ſ⹤��ģʽ��ʵʱ�����š��ļ������ţ�,Ĭ��Ϊ�ļ������ţ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetPlayerMode(PLAYERHANDLE hPlayer,DWORD nMode);


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable)
//
//  ��    ����	
//			 [in]	hPlayer	    : ʵʱ�����ž����
//			 [in]	nRegionNum	: ��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������.
//                          ������hDestWnd��
//			 [in]	rcSrc	      : �ֲ���ʾ����
//			 [in]	hDestWnd	  : ��ʾ���ھ����
//			 [in]	bEnable	    : ��(����)��ر���ʾ����
//
//  ˵    �������û�������ʾ����,�������ֲ��Ŵ���ʾ��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable);


//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcRefreshDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum)
//
//  ��    ����
//			 [in]	hPlayer	   : ʵʱ�����ž����	
//			 [in]	nRegionNum : ��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ���������У�
//
//  ˵    ����ˢ�¶�������ʾ�Ĵ��ڣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcRefreshDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum);

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetMuteEx(PLAYERHANDLE hPlayer, BOOL* bMute)
//
//  ��    ����
//			 [in]	hPlayer	   : ʵʱ�����ž����	
//			 [out]	bMute	   : ������־λ��TRUE���򿪾�����FALSE���رվ���	
//
//  ˵    ������ȡ��ǰ����������״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcGetMuteEx(PLAYERHANDLE hPlayer, BOOL* bMute) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcSetMuteEx(PLAYERHANDLE hPlayer, BOOL bMute)
//
//  ��    ����
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [in]	bMute		: ������־λ��TRUE���򿪾�����FALSE���رվ���	
//
//  ˵    �������õ�ǰ����������״̬��
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetMuteEx(PLAYERHANDLE hPlayer, BOOL bMute) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetImageWidthEx(PLAYERHANDLE hPlayer, LONG* width)
//
//  ��    ����
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [out]	width		: ʵʱ��ͼ��Ŀ��	
//
//  ˵    ������ȡ��ǰ���벥�ŵ���Ƶͼ���ȣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcGetImageWidthEx(PLAYERHANDLE hPlayer, LONG* width) ;

//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetImageHeightEx(PLAYERHANDLE hPlayer, LONG* height)
//
//  ��    ����
//			 [in]	hPlayer		: ʵʱ�����ž����
//			 [out]	height		: ʵʱ��ͼ��ĸ߶ȣ�	
//
//  ˵    ������ȡ��ǰ���벥�ŵ���Ƶͼ��߶ȣ�
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcGetImageHeightEx(PLAYERHANDLE hPlayer, LONG* height) ;



//-----------------------------------------------------------------------------------------
//  �� �� ��: ipcGetCurYuv��HANDLE hPlayer,unsigned char * pBuff,LONG *pSize,LONG *pWidht,LONG *pHeight,LONG *pType)
//
//  ��    ����
//			 [in]		hPlayer		 : ʵʱ�����ž����
//			 [out]		pBuff	     : ����YUV���ݣ��ò�������NULL��ֻ������Ҫ�Ļ��泤��,����ΪYUV��
//			 [in/out]	pSize	     : ����YUV���ݳ��ȣ�
//			 [out]		pWidht	     : ����ͼ���ȣ�
//			 [out]		pHeight	     : ����ͼ��߶ȣ�
//			 [out]		pType	     : ����YUV���ݸ�ʽ: 1 YUV420��
//
//  ˵    ��������ǰ��ʾ֡YUV���ݵ��ڴ棻
//
//  �� �� ֵ����ȷ����0�����󷵻ط�0��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI    ipcGetCurYuv(PLAYERHANDLE hPlayer,unsigned char * pBuff,LONG *pSize,LONG *pWidht,LONG *pHeight,LONG *pType);

//------------------------------------------------------------------------------------------
//�� �� ��: ipcOpenLocalAudio(LONG lFormat, LONG lChannels, LONG lBitsPerSample,LONG lSamplesPerSec, long lReserved, ipcLocalAudio_CallBack nProc, LPVOID pUser)
//
//��	��:
//			[in]	lFormat				:��Ƶ��������0:AMR; 1:G711Alaw;2:PCM (ԭʼ��Ƶ��ʽ ������8000,λ��16,����1)
//			[in]	lChannels			:������
//			[in]	lBitsPerSample		:��������:8
//			[in]	lSamplesPerSec		:����Ƶ��:8000
//			[in]	lReserved			:����
//			[in]	nProc				:��Ƶ�ɼ����ݻص�ָ��
//			[in]	pUser				:�û��Զ������� 
//
//
//˵	��:����Ƶ�ɼ�����
//
//�� �� ֵ:��ȷ����0�����󷵻ط�0
//------------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI    ipcOpenLocalAudio(LONG lFormat, LONG lChannels, LONG lBitsPerSample,LONG lSamplesPerSec, LONG lReserved, ipcLocalAudio_CallBack nProc, LPVOID pUser) ;

//------------------------------------------------------------------------------------------
//�� �� ��: ipcCloseLocalAudio()
//
//��	��:
//
//
//˵	��:�ر���Ƶ�ɼ�����
//
//�� �� ֵ:��ȷ����0�����󷵻ط�0
//------------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI    ipcCloseLocalAudio() ;

//-----------------------------------------------------------------------------------------
//�� �� ��: ipcEnumLocalAudioDevice (IPC_AUDIO_DEVICE * pstDevice, LONG* pSize ) 
//
//��  ��: 
//			[in]	pstDevice				:���������豸��Ϣ
//			[in]	pSize					:��������
//
//˵  ��: ö����Ƶ�豸
//
//���أ�������롣0 �ɹ� ��-1ʧ��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcEnumLocalAudioDevice (IPC_AUDIO_DEVICE * pstDevice, LONG* pSize ) ;


//-----------------------------------------------------------------------------------------
//�� �� ��: ipcSetLocalAudioDevice (INT nAudioDeviceID )
//
//��  ��: 
//			[in]	nAudioDeviceID				:�����豸ID��
//
//˵  ��: ���õ�ǰ��Ƶ�豸
//
//���أ�������롣0 �ɹ� ��-1ʧ��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetLocalAudioDevice (INT nAudioDeviceID );


IPCPLAYER_API INT PLAYERAPI ipcSetIEFlag( PLAYERHANDLE hPlayer,int nFlag );

//-----------------------------------------------------------------------------------------
//�� �� ��: ipcSetAudioEncodeFrequency (INT nAudioCodeFrequency )
//
//��  ��: 
//			[in]	nAudioCodeFrequency	:��������Ƶ�� ��1��50Hz֮��
//
//˵  ��: ���õ�ǰ���������Ƶ��
//
//���أ�������롣0 �ɹ� ��-1ʧ��
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetAudioEncodeFrequency (INT nAudioCodeFrequency );
#endif //_IPCVIDEOPLAYER_SDK_H_