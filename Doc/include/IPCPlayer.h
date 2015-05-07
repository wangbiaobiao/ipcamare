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

#define  IPC_PLAY_STATE_NONE	            ( IPC_FILEPLAY_BASE + 1 ) //无文件打开
#define  IPC_PLAY_STATE_STOP	            ( IPC_FILEPLAY_BASE + 2 ) //停止播放
#define  IPC_PLAY_STATE_PAUSE	            ( IPC_FILEPLAY_BASE + 3 ) //暂停播放
#define  IPC_PLAY_STATE_PLAY	            ( IPC_FILEPLAY_BASE + 4 ) //正在播放
#define  IPC_PLAY_STATE_FAST	            ( IPC_FILEPLAY_BASE + 5 ) //快速播放
#define  IPC_PLAY_STATE_SLOW	            ( IPC_FILEPLAY_BASE + 6 ) //慢速播放
#define  IPC_PLAY_STATE_BACK_NORMAL	    ( IPC_FILEPLAY_BASE + 7 ) //倒序常速
#define  IPC_PLAY_STATE_NORMAL	            ( IPC_FILEPLAY_BASE + 8 ) //正序常速
#define  IPC_PLAY_STATE_BACK_FAST	        ( IPC_FILEPLAY_BASE + 9 ) //倒序快速
#define  IPC_PLAY_STATE_BACK_SLOW	        ( IPC_FILEPLAY_BASE + 10 )//倒序慢速
#define  IPC_PLAY_STATE_LOAD	            ( IPC_FILEPLAY_BASE + 11 )//正在打开文件
#define  IPC_PLAY_STATE_OPEN	            ( IPC_FILEPLAY_BASE + 12 )//文件打开完毕，可以开始播放了
#define  IPC_PLAY_STATE_CLOSE	            ( IPC_FILEPLAY_BASE + 13 )//关闭文件
#define  IPC_PLAY_STATE_FILEEND	        ( IPC_FILEPLAY_BASE + 14 )//文件播放完毕
#define  IPC_PLAY_STATE_ERROR	            ( IPC_FILEPLAY_BASE + 15 )//有错误发生
#define  IPC_PLAY_STATE_INVALID_HANDLE     ( IPC_FILEPLAY_BASE + 16 )//无效句柄
//-------------------------------------------------------------------------------------------------
#define MAX_DISPLAY_WND					4
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
#define IPCPLAYERBASE 0x8000

#define IPC_NOERROR 0
#define IPCPLAYER_NOERROR IPC_NOERROR								//没有错误

#define IPCPLAYER_GENERAL_ERROR			(IPCPLAYERBASE + 0x0001)	//一般性错误
#define IPCPLAYER_CREATE_DSHOW_ERROR	(IPCPLAYERBASE + 0x0002)	//创建DSHOW失败
#define IPCPLAYER_BUF_OVER				(IPCPLAYERBASE + 0x0003)	//缓冲区满，输入流失败
#define IPCPLAYER_PARA_OVER				(IPCPLAYERBASE + 0x0004)	//输入参数非法
#define IPCPLAYER_ALLOC_MEMORY_ERROR	(IPCPLAYERBASE + 0x0005)	//分配内存失败
#define IPCPLAYER_HEADER_FRAME_ERROR	(IPCPLAYERBASE + 0x0006)	//流数据的流头有错误
#define IPCPLAYER_ORDER_ERROR			(IPCPLAYERBASE + 0x0007)	//调用顺序不正确
#define IPCPLAYER_FILEPATH_ERROR		(IPCPLAYERBASE + 0x0008)	//文件路径不正确

#define IPCPLAYER_VIDEO_FRAME_ERROR		(IPCPLAYERBASE + 0x0009)	//视频帧数据有错
#define IPCPLAYER_VIDEO_SOURCE_ERROR	(IPCPLAYERBASE + 0x000A)	//对视频源操作失败
#define IPCPLAYER_VIDEO_DECODER_ERROR	(IPCPLAYERBASE + 0x000B)	//对视频解码器操作失败
#define IPCPLAYER_VIDEO_RENDER_ERROR	(IPCPLAYERBASE + 0x000C)	//对视频显示操作失败
#define IPCPLAYER_VIDEO_CONNECT_ERROR	(IPCPLAYERBASE + 0x000D)	//对视频相关组件连接失败

#define IPCPLAYER_AUDIO_FRAME_ERROR		(IPCPLAYERBASE + 0x000E)	//音频帧数据有错
#define IPCPLAYER_AUDIO_SOURCE_ERROR	(IPCPLAYERBASE + 0x000F)	//对音频源操作失败
#define IPCPLAYER_AUDIO_DECODER_ERROR	(IPCPLAYERBASE + 0x0010)	//对音频解码器操作失败
#define IPCPLAYER_AUDIO_GRABBER_ERROR	(IPCPLAYERBASE + 0x0011)	//对音频过滤器操作失败
#define IPCPLAYER_AUDIO_RENDER_ERROR	(IPCPLAYERBASE + 0x0012)	//对音频显示操作失败
#define IPCPLAYER_AUDIO_CONNECT_ERROR	(IPCPLAYERBASE + 0x0013)	//对音频相关组件连接失败

#define IPC_PLAYER_INVALID_HANDLE       (IPCPLAYERBASE + 0x0014)	//无效句柄
//-------------------------------------------------------------------------------------------------
#pragma pack (push , 1)
#ifndef IPC_VIDEO_INFO_STRUCT
#define IPC_VIDEO_INFO_STRUCT
typedef struct
{
	long	lWidth;							//图像宽
	long	lHeight;						//图像高
	long	lFouCC;							//编码方式	 0:H264 ,1:MJPEG
	long	lFrameRate;						//帧率
}IPC_VIDEO_INFO,*PIPC_VIDEO_INFO;
#endif//IPC_VIDEO_INFO_STRUCT

#ifndef IPC_AUDIO_INFO_STRUCT
#define IPC_AUDIO_INFO_STRUCT
typedef struct
{
	long	lAudioFormat;					//0:AMR; 1:G711-Alaw

	long	lSamplesPerSec;					//采样频率:8000,
	long	lBitsPerSample;					//采样精度:8,
	long	lChannels;						//声道:1,
	long	lAvgBytesPerSec;				//平均速率:8000
}IPC_AUDIO_INFO,*PIPC_AUDIO_INFO;
#endif//IPC_AUDIO_INFO_STRUCT

#ifndef IPC_PLAYER_INFO_STRUCT
#define IPC_PLAYER_INFO_STRUCT
typedef struct tagIPC_PLAYER_INFO
{
	IPC_VIDEO_INFO			videoInfo;		//视频信息
	IPC_AUDIO_INFO			audioInfo;		//音频信息

}IPC_PLAYER_INFO,*PIPC_PLAYER_INFO;
#endif//IPC_PLAYER_INFO_STRUCT

#ifndef IPC_PLAYER_FRAME_STRUCT
#define IPC_PLAYER_FRAME_STRUCT
typedef	struct tagIPC_PLAYER_FRAME
{

	long			lType;					//帧类型,‘I’,‘P’,‘B’,‘A’
	unsigned char	*pBuf;					//帧数据缓冲区
	long			lBufSize;				//帧数据缓冲区大小
	ULONGLONG		ullStartTime;			//播放开始时间
	ULONGLONG		ullEndTime;				//播放结束时间

}IPC_PLAYER_FRAME,*PIPC_PLAYER_FRAME;
#endif//IPC_PLAYER_FRAME_STRUCT

typedef struct
{
	DWORD            nType ;                  //数据类型, 0:YUY2,1:YUV420,2:PCM
	DWORD	         nWidth;				  //图像宽  or 音频为通道数
	DWORD	         nHeight;			      //图像高  or 音频为位率 
	DWORD	         nFrameRate;              //视频帧率	  or 音频为采样率 
	DWORD			 nStamp ;				  //仅视频有时间戳

}IPC_PLAYER_AV_FRAME,*LPIPC_PLAYER_AV_FRAME ;

#pragma pack (pop)

typedef struct tagIPC_PLAYOSDParamA
{
	bool		text ;						//是否显示文字信息
	long		text_x;						//文字显示区域
	long		text_y;
	long		text_lWidth;
	long		text_lHeight;     
	LOGFONTA	text_font ;					//字体
	COLORREF	text_crColor ;				//字体颜色
	wchar_t		text_context[256] ;			//文本内容

	bool		picture;					//是否显示图片
	long		pic_x;						//图片显示区域
	long		pic_y;
	long		pic_lWidth;
	long		pic_lHeight;     

	COLORREF	pic_crMask ;				//图片底色
	long		pic_data_len ;				//图片数据长度
	BYTE*		pic_data ;					//图片数据

}IPC_PLAYOSDPARAMA,*LPIPC_PLAYOSDPARAMA;

typedef struct tagIPC_PLAYOSDParamW
{
	bool		text ;						//是否显示文字信息
	long		text_x;						//文字显示区域
	long		text_y;
	long		text_lWidth;
	long		text_lHeight;     
	LOGFONTW	text_font ;					//字体
	COLORREF	text_crColor ;				//字体颜色
	wchar_t		text_context[256] ;			//文本内容

	bool		picture;					//是否显示图片
	long		pic_x;						//图片显示区域
	long		pic_y;
	long		pic_lWidth;
	long		pic_lHeight;     

	COLORREF	pic_crMask ;				//图片底色
	long		pic_data_len ;				//图片数据长度
	BYTE*		pic_data ;					//图片数据

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

//声卡设备
typedef struct
{ 
	INT		iId;											//声卡设备id 
	CHAR	sDevName[128];									//声卡设备名字 
}IPC_AUDIO_DEVICE,*LPIPC_AUDIO_DEVICE ;

//#include "IPCFilePlayer.h"

typedef void (WINAPI *ipcVideoYUV_CallBack)( PLAYERHANDLE handle, IPC_PLAYER_FRAME * frame, CHAR* data,INT nLen, LPVOID pContext) ;

typedef void (WINAPI *ipcAVFrame_CallBack)( PLAYERHANDLE handle, IPC_PLAYER_AV_FRAME * frame, CHAR* data,INT nLen, LPVOID pContext) ;

typedef void (WINAPI *ipcDraw_CallBack)( PLAYERHANDLE handle, HDC hdc, LPVOID pContext) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcLocalAudio_CallBack
//
//  参    数：	
//			 [in]	type		: 音频编码类型0:AMR; 1:G711Alaw;2:PCM (原始音频格式 采样率8000,位率16,声道1)
//			 [in]	pDataBuffer	: 音频数据缓冲区
//			 [in]	DataLength	: 音频数据长度 
//			 [in]	pUser		: 用户数据
//
//  说    明：  音频采集回调函数参数；
//
//  返 回 值：无；
//-----------------------------------------------------------------------------------------
typedef void (WINAPI *ipcLocalAudio_CallBack)(DWORD type, LPBYTE pDataBuffer, DWORD DataLength, LPVOID pUser) ; 

//-----------------------------------------------------------------------------------------
//  函 数 名: IPCPLAYER_MESSAGE_CALLBACK(DWORD dwCode, VOID *context)
//
//  参    数：	
//			 [in]	dwCode		: 参数是一个32位数，低16位为改变的状态 见播放状态宏定义；
//			 [in]	context		: 返回用户注册回调函数时所输入的自定义数据；
//
//  说    明：播放状态回调函数；
//
//  返 回 值：无；
//-----------------------------------------------------------------------------------------
typedef VOID (CALLBACK* IPCPLAYER_MESSAGE_CALLBACK)(DWORD dwCode, VOID *context) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: IPCPLAYER_AVFRAME_CALLBACKEX(LPBYTE data,DWORD size,LPIPC_PLAYER_AV_FRAME pInfo,LPVOID pContext )
//
//  参    数：	
//			 [in]	data		  : 解码后数据；
//			 [in]	size		  : 数据长度；
//			 [in]	pInfo		  : 码流信息
//			 [in]	pContext	  : 返回用户注册回调函数时所输入的自定义数据
//
//  说    明：音频视频解码回调；
//
//  返 回 值：无；
//-----------------------------------------------------------------------------------------
typedef VOID (CALLBACK* IPCPLAYER_AVFRAME_CALLBACKEX)(LPBYTE data,DWORD size,LPIPC_PLAYER_AV_FRAME pInfo,LPVOID pContext );


//-----------------------------------------------------------------------------------------
//  函 数 名: IPCPLAYER_AVFRAME_CALLBACK(LPBYTE data,DWORD size,DWORD type,DWORD width,DWORD height,LPVOID pContext )
//
//  参    数：	
//			 [in]	data		  : 解码后YUY2数据；
//			 [in]	size		  : 数据长度；
//			 [in]	type		  : 解码后的数据格式
//			 [in]	width		  : 图像宽度
//			 [in]	height		: 图像高度
//			 [in]	pContext	: 返回用户注册回调函数时所输入的自定义数据
//
//  说    明：音频视频解码回调；
//
//  返 回 值：无；
//-----------------------------------------------------------------------------------------
typedef VOID (CALLBACK* IPCPLAYER_AVFRAME_CALLBACK)(LPBYTE data,DWORD size,DWORD type,DWORD width,DWORD height,LPVOID pContext );


//鼠标回调
typedef VOID (CALLBACK* IPCPLAYER_MOUSE_CALLBACK)(INT x, INT y, INT event, VOID *context );


//API函数   

// ASF文件播放部分

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Init( HWND hWnd,DWORD dwFlags,DWORD dwDisFmt,DWORD dwAudFmt )
//
//  参    数：	
//			 [in]	hWnd		  : 播放器显示窗口句柄；
//			 [in]	dwFlags		: 解码器类型<只能为H264_DECODER_ID_BKASF>；
//			 [in]	dwDisFmt	: 显示Surface类型<该参数暂被忽略>；
//			 [in]	dAudFmt		: 播放声音方式<该参数暂被忽略>；
//
//  说    明：初始化播放器，每次调用初始化一个播放器；
//
//  返 回 值：初始化正确返回该播放通道控制句柄，错误返回NULL；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API HANDLE PLAYERAPI ipcAvFileDec_Init( HWND hWnd,DWORD dwFlags,DWORD dwDisFmt,DWORD dwAudFmt );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Done( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//
//  说    明：释放播放器资源；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Done( HANDLE hAndle );

#ifdef _UNICODE
#define ipcAvFileDec_SetFileName ipcAvFileDec_SetFileNameW
#else
#define ipcAvFileDec_SetFileName ipcAvFileDec_SetFileNameA
#endif

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetFileName( HANDLE hAndle, LPCTSTR lpFileName, LPCTSTR lpAudioFile, BOOL bPlay )
//
//  参    数：	
//			 [in]	hAndle		    : 通道控制句柄；
//			 [in]	lpFileName		: 文件名；
//			 [in]	lpAudioFile		: 附加音频文件名；
//			 [in]	bPlay			: 自动播放标志；
//
//  说    明：设置播放文件；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetFileNameA( HANDLE hAndle, LPCSTR lpFileName, LPCSTR lpAudioFile, BOOL bPlay ) ;



//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetFileNameW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpAudioFile, BOOL bPlay )
//
//  参    数：	
//			 [in]	hAndle		    : 通道控制句柄；
//			 [in]	lpFileName		: 文件名；
//			 [in]	lpAudioFile		: 附加音频文件名；
//			 [in]	bPlay			: 自动播放标志；
//
//  说    明：设置播放文件；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetFileNameW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpAudioFile, BOOL bPlay );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CloseFile( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//
//  说    明：关闭播放器中当前打开的文件；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CloseFile( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Play( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//
//  说    明：设置播放器为播放状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Play( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Stop( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//
//  说    明：设置播放器为停止状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Stop( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_RePlay( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//
//  说    明：设置播放器为重新播放状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RePlay( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Pause( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//
//  说    明：设置播放器为暂停状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Pause( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Fast( HANDLE hAndle, float fRate )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//			 [in]	fRate		  : 播放速率；
//
//  说    明：设置播放器为快放状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Fast( HANDLE hAndle, float fRate );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Slow( HANDLE hAndle, float fRate )
//
//  参    数：	
//			 [in]	hAndle		: 通道控制句柄；
//			 [in]	fRate		  : 播放速率；
//
//  说    明：设置播放器为慢放状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Slow( HANDLE hAndle, float fRate );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_StepFrame( HANDLE hAndle, BOOL bForward )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	bForward	: 相对于文件前后帧标志；
//
//  说    明：设置播放器为单帧播放状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_StepFrame( HANDLE hAndle, BOOL bForward );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Forward( HANDLE hAndle, DWORD dwOffset )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	dwOffset	: 偏移量；
//
//  说    明：文件前跳一段；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Forward( HANDLE hAndle, DWORD dwOffset );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_Backward( HANDLE hAndle, DWORD dwOffset )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	dwOffset	: 偏移量；
//
//  说    明：文件后跳一段；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_Backward( HANDLE hAndle, DWORD dwOffset );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetVolume( HANDLE hAndle, LONG* lVolume )
//
//  参    数：	
//			 [in]  hAndle	  : 通道控制句柄；
//			 [out] lVolume	  : 音量百分比值；
//
//  说    明：获取音量百分比；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetVolume( HANDLE hAndle, LONG* lVolume );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetVolume( HANDLE hAndle, LONG lVolume )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]   lVolume	  : 音量百分比值；
//
//  说    明：设置音量百分比；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetVolume( HANDLE hAndle, LONG lVolume );



//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetMute( HANDLE hAndle, BOOL* bMute )
//
//  参    数：	
//			 [in]  hAndle	  : 通道控制句柄；
//			 [out] bMute	  : 静音标志；
//
//  说    明：获取音量静音标志；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetMute( HANDLE hAndle, BOOL* bMute );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetMute( HANDLE hAndle, BOOL bMute )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]   bMute	  : 静音标志；
//
//  说    明：设置音量静音标志；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetMute( HANDLE hAndle, BOOL bMute );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetDisplayVisible( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：获取解码图像是否显示输出；
//
//  返 回 值：返回解码图像是否显示输出；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API BOOL PLAYERAPI ipcAvFileDec_GetDisplayVisible( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetDisplayVisible( HANDLE hAndle, BOOL bShow )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	bShow	    : 解码图像是否显示输出；
//
//  说    明：设置解码显示输出开关，关闭显示输出时正常解码文件；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetDisplayVisible( HANDLE hAndle, BOOL bShow );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetDisplayPos( HANDLE hAndle, RECT *lpRect )
//
//  参    数：	
//			 [in]	 hAndle	  : 通道控制句柄；
//			 [out] lpRect	  : 显示矩形框；
//
//  说    明：获取播放显示矩形框；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetDisplayPos( HANDLE hAndle, RECT *lpRect );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetDisplayPos( HANDLE hAndle, RECT *lpRect )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in] lpRect	  : 显示矩形框；
//
//  说    明：设置播放显示矩形框；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetDisplayPos( HANDLE hAndle, RECT *lpRect );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetFullScreen( HANDLE hAndle, RECT* lpRect )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [out] lpRect	  : 全屏显示矩形框；
//
//  说    明：返回用户窗口全屏显示状态；
//
//  返 回 值：放回是否处于用户全屏显示状态；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API BOOL PLAYERAPI ipcAvFileDec_GetFullScreen( HANDLE hAndle, RECT* lpRect );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetFullScreen( HANDLE hAndle, BOOL bFull, HWND hWnd, RECT* lpRect )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	bFull	    : 是否需要全屏显示；
//			 [in] lpRect	  : 显示矩形框；
//
//  说    明：当用户需要在自己的窗口上全屏显示时，必须调用此函数；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetFullScreen( HANDLE hAndle, BOOL bFull, HWND hWnd, RECT* lpRect );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetZoom( HANDLE hAndle, RECT* lpRect )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [out]	lpRect	  : 存放局部放大矩形框的指针；
//
//  说    明：获取当前局部放大状态，必须调用此函数；
//
//  返 回 值：返回当前是否处于局部放大状态；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API BOOL PLAYERAPI ipcAvFileDec_GetZoom(HANDLE hAndle, RECT* lpRect);

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetZoom(HANDLE hAndle, BOOL bZoom, RECT* lpRect)
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄;
//			 [in]   bZoom	  : 是否局部放大;
//			 [in]	lpRect	  : 局部放大矩形框;
//
//  说    明：设置局部放大，必须调用此函数;
//
//  返 回 值：正确返回0，错误返回非0;
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetZoom(HANDLE hAndle, BOOL bZoom, RECT* lpRect);

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetDisplayRegion(HANDLE hAndle,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable)
//
//  参    数：	
//			 [in]	hPlayer	    : 通道控制句柄；
//			 [in]	nRegionNum	: 显示区域序号,0~(MAX_DISPLAY_WND-1),如果为0,则将设置的区域显示在主窗口中.
//                          将忽略hDestWnd；
//			 [in]	rcSrc	      : 局部显示区域；
//			 [in]	hDestWnd	  : 显示窗口句柄；
//			 [in]	bEnable	    : 打开(设置)或关闭显示区域；
//
//  说    明：设置或增加显示区域,可以做局部放大显示；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetDisplayRegion(HANDLE hAndle,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable);


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_RefreshDisplayRegion(HANDLE hAndle,DWORD nRegionNum)
//
//  参    数：
//			 [in]	hPlayer	   : 通道控制句柄；	
//			 [in]	nRegionNum : 显示区域序号,0~(MAX_DISPLAY_WND-1),如果为0,则将设置的区域显示在主窗口中；
//
//  说    明：刷新多区域显示的窗口；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RefreshDisplayRegion(HANDLE hAndle,DWORD nRegionNum);

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetImageWidth( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：获取当前播放文件视频图像宽度；
//
//  返 回 值：正确返回当前播放文件视频图像宽度；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetImageWidth( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetImageHeight( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：获取当前播放文件视频图像高度；
//
//  返 回 值：正确返回当前播放文件视频图像高度；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetImageHeight( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetTotalFrames( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：获取当前播放文件的总帧数；
//
//  返 回 值：当返回大于0时才表示正确得到总帧数，小于0则失败；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API LONG PLAYERAPI ipcAvFileDec_GetTotalFrames( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetCurrentPosition( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：得到当前文件播放的帧位置；
//
//  返 回 值：当返回大于0时才表示正确得到帧位置，小于0则失败；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API LONG PLAYERAPI ipcAvFileDec_GetCurrentPosition( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetCurrentPosition( HANDLE hAndle, LONG lPosition )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	lPosition	: 帧位置；
//
//  说    明：设置当前视频播放的帧位置；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetCurrentPosition( HANDLE hAndle, LONG lPosition );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetTotalTime( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：得到当前播放文件的总时间；
//
//  返 回 值：返回打开的文件总时间(单位秒)；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API FLOAT PLAYERAPI ipcAvFileDec_GetTotalTime( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetCurrentTime( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：得到当前文件播放时间；
//
//  返 回 值：返回当前文件播放时间(单位秒)；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API FLOAT PLAYERAPI ipcAvFileDec_GetCurrentTime( HANDLE hAndle );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_SetCurrentTime( HANDLE hAndle, FLOAT dwTime )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//			 [in]	dwTime	  : 播放起点时间；
//
//  说    明：设置播放的起点时间；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetCurrentTime( HANDLE hAndle, FLOAT dwTime );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_GetCurrentState( HANDLE hAndle )
//
//  参    数：	
//			 [in]	hAndle	  : 通道控制句柄；
//
//  说    明：得到播放器当前状态；
//
//  返 回 值：返回播放状态；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetCurrentState( HANDLE hAndle );

#ifdef _UNICODE
#define ipcAvFileDec_CapturePicture ipcAvFileDec_CapturePictureW
#else
#define ipcAvFileDec_CapturePicture ipcAvFileDec_CapturePictureA
#endif

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CapturePictureA( HANDLE hAndle, LPCSTR lpFileName, LPCSTR lpPicFormat )
//
//  参    数：	
//			 [in]	hAndle	      : 通道控制句柄；
//			 [in]	lpFileName	  : 文件名；
//			 [in]	lpPicFormat	  : 图像格式（保留）；
//
//  说    明：捕获当前显示帧；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictureA( HANDLE hAndle, LPCSTR lpFileName, LPCSTR lpPicFormat );

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CapturePictureW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpPicFormat )
//
//  参    数：	
//			 [in]	hAndle	      : 通道控制句柄；
//			 [in]	lpFileName	  : 文件名；
//			 [in]	lpPicFormat	  : 图像格式（保留）；
//
//  说    明：捕获当前显示帧；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictureW( HANDLE hAndle, LPCWSTR lpFileName, LPCWSTR lpPicFormat );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CapturePictToBuff( HANDLE hAndle,BYTE* buff,LONG* len)
//
//  参    数 ：	
//			 [in]	    hAndle	      : 通道控制句柄；
//			 [out]	    buff		  : 返回图像数据，该参数传递NULL，只返回需要的缓存长度；数据为包含BITMAPINFOHEADER 的位图数据，无BITMAPFILEHEADER
//			 [in/out]	len			  : 返回图像数据长度；
//  说    明：捕获当前显示帧数据到内存；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictToBuff( HANDLE hAndle,BYTE* buff,LONG* len) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CapturePictToBuffEx( HANDLE hAndle,BYTE* buff,LONG* len)
//
//  参    数 ：	
//			 [in]	    hAndle	      : 通道控制句柄；
//			 [out]	    buff		  : 返回图像数据，该参数传递NULL，只返回需要的缓存长度；数据为包含BITMAPFILEHEADER，BITMAPINFOHEADER的位图数据
//			 [in/out]	len			  : 返回图像数据长度；
//  说    明：捕获当前显示帧数据到内存；
//
//  返 回 值：正确返回0，错误返回非0；
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CapturePictToBuffEx( HANDLE hAndle,BYTE* buff,LONG* len); 

//  参数：hAndle为通道控制句柄。
//  说明：该函数设置无效。
//  返回：正确返回0，错误返回非0。
//IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetVideoParam( HANDLE hAndle, INT* iBrightness, INT* iContrast, INT* iSaturation, INT* iHue );


//  参数：hAndle为通道控制句柄。
//  说明：该函数设置无效。
//  返回：正确返回0，错误返回非0。
//IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_SetVideoParam( HANDLE hAndle, INT iBrightness, INT iContrast, INT iSaturation, INT iHue );


//  参数：hAndle为通道控制句柄, p存放流描述信息，flag视频或音频 
//  返回：正确返回0，错误返回非0。
//IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_GetStreamDescription( HANDLE hAndle, IPCPLAYER_StreamDescription_t *p, INT flag );


#ifdef _UNICODE
#define ipcAvFileDec_Cut ipcAvFileDec_CutW
#else
#define ipcAvFileDec_Cut ipcAvFileDec_CutA
#endif
//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CutA( HANDLE hAndle, CHAR *pDestFileName, INT iStartTime, INT iEndTime )
//
//  参    数：	
//			 [in]	hAndle	       : 通道控制句柄；
//			 [in]	pDestFileName  : 目标文件路径；
//			 [in]	iStartTime	   : 启始时间点，单位s，不得大于文件总时间长度；
//			 [in]	iEndTime	   : 结束时间点, 单位s,不得大于文件总时间长度；
//
//  说    明：；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CutA(HANDLE hAndle, CHAR *pDestFileName, INT iStartTime, INT iEndTime );

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_CutW( HANDLE hAndle, WCHAR *pDestFileName, INT iStartTime, INT iEndTime )
//
//  参    数：	
//			 [in]	hAndle	       : 通道控制句柄；
//			 [in]	pDestFileName  : 目标文件路径；
//			 [in]	iStartTime	   : 起始时间，单位秒；
//			 [in]	iEndTime	   : 结束时间，单位秒；
//
//  说    明：；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_CutW( HANDLE hAndle, WCHAR *pDestFileName, INT iStartTime, INT iEndTime );

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_RegisterAVMsgCallBack( HANDLE hAndle, IPCPLAYER_MESSAGE_CALLBACK pCallBack,VOID* contextt )
//
//  参    数：	
//			 [in]	hAndle	      : 通道控制句柄；
//			 [in]	pCallBack	    : 回调函数指针；
//			 [in]	contextt	    : 应用程序提供的参数；
//
//  说    明：当播放器中播放状态改变时会调用注册的回调函数；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterAVMsgCallBack( HANDLE hAndle, IPCPLAYER_MESSAGE_CALLBACK pCallBack,VOID* contextt );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_RegisterAVFrameCallBack( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACK pCallBack, VOID* context );
//
//  参    数：	
//			 [in]	hAndle	      : 通道控制句柄；
//			 [in]	pCallBack	    : 回调函数指针；
//			 [in]	contextt	    : 应用程序提供的参数；
//
//  说    明：当解码播放时，通过回调输出解码后的数据，其中视频为YUV420格式
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterAVFrameCallBack( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACK pCallBack, VOID* context );



//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_RegisterAVFrameCallBackEx( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACKEX pCallBack, VOID* pContext );
//
//  参    数：	
//			 [in]	hAndle	        : 通道控制句柄；
//			 [in]	pCallBack	    : 回调函数指针；
//			 [in]	pContext	    : 应用程序提供的参数；
//
//  说    明：当解码播放时，通过回调输出解码后的数据，其中视频为YUV420格式，音频为PCM格式
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterAVFrameCallBackEx( HANDLE hAndle, IPCPLAYER_AVFRAME_CALLBACKEX pCallBack, VOID* pContext );


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcAvFileDec_RegisterMouseCallBack( HANDLE hAndle, IPCPLAYER_MOUSE_CALLBACK pCallBack, VOID* context );
//
//  参    数：	
//			 [in]	hAndle	        : 通道控制句柄；
//			 [in]	pCallBack	    : 回调函数指针；
//			 [in]	contextt	    : 应用程序提供的参数；
//
//  说    明：当播放器全屏显示时且调用Avdec_SetFullScreen函数全屏显示的，如果有鼠标事件发生将调用此回调函数；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcAvFileDec_RegisterMouseCallBack( HANDLE hAndle, IPCPLAYER_MOUSE_CALLBACK pCallBack, VOID* context );



//流式播放部分 ------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcPlayerInitialize()
//
//  参    数：	
//
//  说    明：播放库全局初始化；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcPlayerInitialize() ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcPlayerUnInitialize()
//
//  参    数：	
//
//  说    明：播放库全局析构；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcPlayerUnInitialize() ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcCreatePlayerEx(PIPC_PLAYER_INFO  pInfo)
//
//  参    数：	
//			 [in]	pInfo	  : 音视频流参数信息；
//
//  说    明：创建实时流播放句柄；
//
//  返 回 值：返回播放句柄，如果为null则创建失败；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API PLAYERHANDLE PLAYERAPI ipcCreatePlayerEx(PIPC_PLAYER_INFO  pInfo) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcCreatePlayerEx2()
//
//  参    数：	
//
//  说    明：创建实时流播放句柄的扩展接口；
//
//  返 回 值：返回播放句柄，如果为null则创建失败；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API PLAYERHANDLE PLAYERAPI ipcCreatePlayerEx2() ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcDestroyPlayerEx(PLAYERHANDLE hPlayer)
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//
//  说    明：释放实时流播放句柄；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcDestroyPlayerEx(PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcStartEx(PLAYERHANDLE hPlayer)
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//
//  说    明：开始播放；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcStartEx(PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcStopEx(PLAYERHANDLE hPlayer)
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//
//  说    明：停止播放；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcStopEx(PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcStartImageSharpen(PLAYERHANDLE hPlayer,float amount = 1.2f);
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//           [in]	amount    : 图像锐化程度，默认为1.2f，范围0.0f-5.0f
//
//  说    明：开启图像锐化，；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcStartImageSharpen(PLAYERHANDLE hPlayer,float amount = 1.2f);


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcChangeSharpenDegree(PLAYERHANDLE hPlayer,float amount);
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//           [in]	amount    : 图像锐化程度，范围0.0f-5.0f
//
//  说    明：改变图像的锐化程度；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcChangeSharpenDegree(PLAYERHANDLE hPlayer,float amount);


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcStopImageSharpen(PLAYERHANDLE hPlayer);
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//
//  说    明：关闭图像锐化；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcStopImageSharpen(PLAYERHANDLE hPlayer);

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcRegisterYUVCallBackEx( PLAYERHANDLE hPlayer, ipcVideoYUV_CallBack pCallBack, LPVOID context)
//
//  参    数：	
//			 [in]	hPlayer	    : 实时流播放句柄；
//			 [in]	pCallBack	: 回调函数指针；
//			 [in]	context	    : 用户自定义数据；
//			 [in]	dwType		: 回调返回视频数据格式，默认为YUY2，1为YUV420
//
//  说    明：注册解码后的帧回调；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcRegisterYUVCallBackEx( PLAYERHANDLE hPlayer, ipcVideoYUV_CallBack pCallBack, LPVOID context, DWORD dwType = 0) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcRegisterAVCallBackEx( PLAYERHANDLE hPlayer, ipcAVFrame_CallBack pCallBack, LPVOID context)
//
//  参    数：	
//			 [in]	hPlayer	    : 实时流播放句柄；
//			 [in]	pCallBack	: 回调函数指针；
//			 [in]	context	    : 用户自定义数据；
//			 [in]	dwType		: 回调返回视频数据格式，默认为YUY2，1为YUV420
//
//  说    明：当实时流解码播放时，通过回调输出解码后的数据，其中视频为YUY2/YUV420格式，音频为PCM格式
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcRegisterAVCallBackEx( PLAYERHANDLE hPlayer, ipcAVFrame_CallBack pCallBack, LPVOID context, DWORD dwType = 0) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcRegisterDrawCallBack( PLAYERHANDLE hPlayer, ipcDraw_CallBack pCallBack, LPVOID context)
//
//  参    数：	
//			 [in]	hPlayer	    : 实时流播放句柄；
//			 [in]	pCallBack	: 回调函数指针；
//			 [in]	context	    : 用户自定义数据；
//
//  说    明： 注册一个回调函数，获得当前表面的device context, 你可以在这个DC 上画图（或写字）
//			 就好像在窗口的客户区DC 上绘图，但这个DC 不是窗口客户区的DC.
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcRegisterDrawCallBack( PLAYERHANDLE hPlayer, ipcDraw_CallBack pCallBack, LPVOID context) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetDisplayRectEx(PLAYERHANDLE hPlayer, HWND hWnd, IN RECT rect)
//
//  参    数：	
//			 [in]	hPlayer	  : 实时流播放句柄；
//			 [in]	hWnd	  : 显示窗口句柄；
//			 [in]	rect	  : 显示区域坐标；
//
//  说    明：设置视频显示窗口句柄及区域坐标；如果hWnd为NULL，则播放器只回调解码数据不负责显示部分。
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetDisplayRectEx(PLAYERHANDLE hPlayer, HWND hWnd, IN RECT rect) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetDisplayRectEx(PLAYERHANDLE hPlayer, HWND* hWnd, OUT RECT* rect )
//
//  参    数：	
//			 [in]  hPlayer	: 实时流播放句柄；
//			 [out] hWnd	    : 显示窗口句柄；
//			 [out] rect	    : 显示区域坐标；
//
//  说    明：获取视频显示窗口句柄及区域坐标；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetDisplayRectEx(PLAYERHANDLE hPlayer, HWND* hWnd, OUT RECT* rect ) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetDisplayVisibleEx(PLAYERHANDLE hPlayer, IN BOOL bVal)
//
//  参    数：	
//			 [in] hPlayer	: 实时流播放句柄；
//			 [in] bVal	    : 显示状态；
//
//  说    明：设置视频是否显示；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetDisplayVisibleEx(PLAYERHANDLE hPlayer, IN BOOL bVal) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetDisplayVisibleEx(PLAYERHANDLE hPlayer, OUT BOOL* bVal)
//
//  参    数：	
//			 [in]  hPlayer	: 实时流播放句柄；
//			 [out] bVal	    : 显示状态；
//
//  说    明：获取视频是否显示状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetDisplayVisibleEx(PLAYERHANDLE hPlayer, OUT BOOL* bVal) ;

//IPCPLAYER_API INT PLAYERAPI  ipcStartRecordEx( PLAYERHANDLE hPlayer, WCHAR * filePath) ;
//IPCPLAYER_API INT PLAYERAPI  ipcStopRecordEx(  PLAYERHANDLE hPlayer) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcCapturePictureEx(  PLAYERHANDLE hPlayer, int picType, WCHAR* file_name)
//
//  参    数：	
//			 [in] hPlayer	  : 实时流播放句柄；
//			 [in] picType	  : 保存图片的类型,值1为BMP格式图片，值2为JPEG格式图片；
//			 [in] file_name	  : 保存图片文件的全路径；
//
//  说    明：捕获当前显示帧数据到文件；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcCapturePictureEx(  PLAYERHANDLE hPlayer, int picType, WCHAR* file_name) ; 


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcCapturePicToBuffEx(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len)
//
//  参    数：	
//			 [in]     hPlayer	 : 实时流播放句柄；
//			 [in]     picType	 : 保留，暂无作用；
//			 [out]    buff	     : 返回图像数据，该参数传递NULL，只返回需要的缓存长度,数据为包含BITMAPINFOHEADER BITMAPFILEHEADER的位图数据；
//			 [in/out] len	     : 返回图像数据长度；
//
//  说    明：捕获当前显示帧数据到内存；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcCapturePicToBuffEx(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcCapturePicToBuffEx2(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len)
//
//  参    数：	
//			 [in]     hPlayer	 : 实时流播放句柄；
//			 [in]     picType	 : 保留，暂无作用；
//			 [out]    buff	     : 返回图像数据，该参数传递NULL，只返回需要的缓存长度,数据为包含BITMAPFILEHEADER，BITMAPINFOHEADER的位图数据；
//			 [in/out] len	 : 返回图像数据长度；
//
//  说    明：捕获当前显示帧数据到内存；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcCapturePicToBuffEx2(  PLAYERHANDLE hPlayer, int picType, BYTE* buff, LONG* len) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetOSDEx( PLAYERHANDLE hPlayer, LPIPC_PLAYOSDPARAM osd_info)
//
//  参    数：	
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [in]	osd_info	: OSD数据信息；
//
//  说    明：设置OSD；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetOSDEx( PLAYERHANDLE hPlayer, LPIPC_PLAYOSDPARAM osd_info) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD time)
//
//  参    数：	
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [in]	time		: 播放缓冲区缓冲的毫秒数，取值范围为0到1000，默认值为135；
//
//  说    明：设置播放缓冲区缓冲时间；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD time) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD* time)
//
//  参    数：	
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [in]	time		: 播放缓冲区缓冲的毫秒数；
//
//  说    明：获取播放缓冲区缓冲时间；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetBufferTimeEx(PLAYERHANDLE hPlayer, DWORD* time) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetPlayInfoEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_INFO pInfo)
//
//  参    数：	
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [in]	pInfo		: 实时流参数信息；
//
//  说    明：获取实时流参数信息；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetPlayInfoEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_INFO pInfo) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcInputDataEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_FRAME pFrame) 
//
//  参    数：	
//			 [in] hPlayer	 : 实时流播放句柄；
//			 [in] pFrame	 : 帧数据；
//
//  说    明：输入帧数据；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcInputDataEx(PLAYERHANDLE hPlayer, PIPC_PLAYER_FRAME pFrame) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcInputDataEx2(PLAYERHANDLE hPlayer, BYTE* pFrameBuff, LONG len)
//
//  参    数：	
//			 [in]	hPlayer	     : 实时流播放句柄；
//			 [in] pFrameBuff	   : 帧数据；
//			 [in] len	         : 帧数据长度；
//
//  说    明：为播放私有帧数据的扩展接口；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcInputDataEx2(PLAYERHANDLE hPlayer, BYTE* pFrameBuff, LONG len) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetAudioVolume(PLAYERHANDLE hPlayer, long val) 
//
//  参    数：	
//			 [in]	hPlayer	: 实时流播放句柄；
//			 [in] val	    : 音量；
//
//  说    明：设置音量；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcSetAudioVolume(PLAYERHANDLE hPlayer, long val) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetAudioVolume(PLAYERHANDLE hPlayer, long* val) 
//
//  参    数：	
//			 [in]	 hPlayer	: 实时流播放句柄；
//			 [out] val	    : 音量；
//
//  说    明：获取音量；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI  ipcGetAudioVolume(PLAYERHANDLE hPlayer, long* val) ;


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetPlayerMode(PLAYERHANDLE hPlayer,DWORD nMode)
//
//  参    数：
//			 [in]	hPlayer	: 实时流播放句柄；	
//			 [in]	nMode	  : 工作模式类型，0为实时流播放，1为文件流播放；
//
//  说    明：设置播放库工作模式（实时流播放、文件流播放）,默认为文件流播放；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetPlayerMode(PLAYERHANDLE hPlayer,DWORD nMode);


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable)
//
//  参    数：	
//			 [in]	hPlayer	    : 实时流播放句柄；
//			 [in]	nRegionNum	: 显示区域序号,0~(MAX_DISPLAY_WND-1),如果为0,则将设置的区域显示在主窗口中.
//                          将忽略hDestWnd；
//			 [in]	rcSrc	      : 局部显示区域；
//			 [in]	hDestWnd	  : 显示窗口句柄；
//			 [in]	bEnable	    : 打开(设置)或关闭显示区域；
//
//  说    明：设置或增加显示区域,可以做局部放大显示；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum, RECT rcSrc, HWND hDestWnd, BOOL bEnable);


//-----------------------------------------------------------------------------------------
//  函 数 名: ipcRefreshDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum)
//
//  参    数：
//			 [in]	hPlayer	   : 实时流播放句柄；	
//			 [in]	nRegionNum : 显示区域序号,0~(MAX_DISPLAY_WND-1),如果为0,则将设置的区域显示在主窗口中；
//
//  说    明：刷新多区域显示的窗口；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcRefreshDisplayRegion(PLAYERHANDLE hPlayer,DWORD nRegionNum);

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetMuteEx(PLAYERHANDLE hPlayer, BOOL* bMute)
//
//  参    数：
//			 [in]	hPlayer	   : 实时流播放句柄；	
//			 [out]	bMute	   : 静音标志位，TRUE：打开静音，FALSE：关闭静音	
//
//  说    明：获取当前播放器静音状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcGetMuteEx(PLAYERHANDLE hPlayer, BOOL* bMute) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcSetMuteEx(PLAYERHANDLE hPlayer, BOOL bMute)
//
//  参    数：
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [in]	bMute		: 静音标志位，TRUE：打开静音，FALSE：关闭静音	
//
//  说    明：设置当前播放器静音状态；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetMuteEx(PLAYERHANDLE hPlayer, BOOL bMute) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetImageWidthEx(PLAYERHANDLE hPlayer, LONG* width)
//
//  参    数：
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [out]	width		: 实时流图像的宽度	
//
//  说    明：获取当前解码播放的视频图像宽度；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcGetImageWidthEx(PLAYERHANDLE hPlayer, LONG* width) ;

//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetImageHeightEx(PLAYERHANDLE hPlayer, LONG* height)
//
//  参    数：
//			 [in]	hPlayer		: 实时流播放句柄；
//			 [out]	height		: 实时流图像的高度；	
//
//  说    明：获取当前解码播放的视频图像高度；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcGetImageHeightEx(PLAYERHANDLE hPlayer, LONG* height) ;



//-----------------------------------------------------------------------------------------
//  函 数 名: ipcGetCurYuv（HANDLE hPlayer,unsigned char * pBuff,LONG *pSize,LONG *pWidht,LONG *pHeight,LONG *pType)
//
//  参    数：
//			 [in]		hPlayer		 : 实时流播放句柄；
//			 [out]		pBuff	     : 返回YUV数据，该参数传递NULL，只返回需要的缓存长度,数据为YUV；
//			 [in/out]	pSize	     : 返回YUV数据长度；
//			 [out]		pWidht	     : 返回图像宽度；
//			 [out]		pHeight	     : 返回图像高度；
//			 [out]		pType	     : 返回YUV数据格式: 1 YUV420；
//
//  说    明：捕获当前显示帧YUV数据到内存；
//
//  返 回 值：正确返回0，错误返回非0；
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI    ipcGetCurYuv(PLAYERHANDLE hPlayer,unsigned char * pBuff,LONG *pSize,LONG *pWidht,LONG *pHeight,LONG *pType);

//------------------------------------------------------------------------------------------
//函 数 名: ipcOpenLocalAudio(LONG lFormat, LONG lChannels, LONG lBitsPerSample,LONG lSamplesPerSec, long lReserved, ipcLocalAudio_CallBack nProc, LPVOID pUser)
//
//参	数:
//			[in]	lFormat				:音频编码类型0:AMR; 1:G711Alaw;2:PCM (原始音频格式 采样率8000,位率16,声道1)
//			[in]	lChannels			:声道数
//			[in]	lBitsPerSample		:采样精度:8
//			[in]	lSamplesPerSec		:采样频率:8000
//			[in]	lReserved			:保留
//			[in]	nProc				:音频采集数据回调指针
//			[in]	pUser				:用户自定义数据 
//
//
//说	明:打开音频采集功能
//
//返 回 值:正确返回0，错误返回非0
//------------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI    ipcOpenLocalAudio(LONG lFormat, LONG lChannels, LONG lBitsPerSample,LONG lSamplesPerSec, LONG lReserved, ipcLocalAudio_CallBack nProc, LPVOID pUser) ;

//------------------------------------------------------------------------------------------
//函 数 名: ipcCloseLocalAudio()
//
//参	数:
//
//
//说	明:关闭音频采集功能
//
//返 回 值:正确返回0，错误返回非0
//------------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI    ipcCloseLocalAudio() ;

//-----------------------------------------------------------------------------------------
//函 数 名: ipcEnumLocalAudioDevice (IPC_AUDIO_DEVICE * pstDevice, LONG* pSize ) 
//
//参  数: 
//			[in]	pstDevice				:本端声卡设备信息
//			[in]	pSize					:声卡数量
//
//说  明: 枚举音频设备
//
//返回：错误代码。0 成功 ，-1失败
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcEnumLocalAudioDevice (IPC_AUDIO_DEVICE * pstDevice, LONG* pSize ) ;


//-----------------------------------------------------------------------------------------
//函 数 名: ipcSetLocalAudioDevice (INT nAudioDeviceID )
//
//参  数: 
//			[in]	nAudioDeviceID				:声卡设备ID号
//
//说  明: 设置当前音频设备
//
//返回：错误代码。0 成功 ，-1失败
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetLocalAudioDevice (INT nAudioDeviceID );


IPCPLAYER_API INT PLAYERAPI ipcSetIEFlag( PLAYERHANDLE hPlayer,int nFlag );

//-----------------------------------------------------------------------------------------
//函 数 名: ipcSetAudioEncodeFrequency (INT nAudioCodeFrequency )
//
//参  数: 
//			[in]	nAudioCodeFrequency	:语音编码频率 在1—50Hz之间
//
//说  明: 设置当前语音编码的频率
//
//返回：错误代码。0 成功 ，-1失败
//-----------------------------------------------------------------------------------------
IPCPLAYER_API INT PLAYERAPI ipcSetAudioEncodeFrequency (INT nAudioCodeFrequency );
#endif //_IPCVIDEOPLAYER_SDK_H_