#ifndef _IPC_SDK_DEFINES_H_
#define _IPC_SDK_DEFINES_H_

#define ipcSUCCESS  0
#define ipcFAULT    -1

#define IPC_SDK_FAULT_BASE (0x80004000)

#define IPC_E_MODULE_NOTFOUND                   (IPC_SDK_FAULT_BASE+1)        //依赖项未发现
#define IPC_E_RESOURCE_NOTALLOCATED             (IPC_SDK_FAULT_BASE+2)        //资源分配失败
#define IPC_E_INVALID_LOGIN_INFO                (IPC_SDK_FAULT_BASE+3)        //登陆信息错误
#define IPC_E_INVALID_PARAMS                    (IPC_SDK_FAULT_BASE+4)        //无效参数
#define IPC_E_CANT_DISPLAY                      (IPC_SDK_FAULT_BASE+6)        //显示错误
#define IPC_E_SYSTEMBUSY                        (IPC_SDK_FAULT_BASE+7)        //系统忙执行失败
#define IPC_E_UNSUPPORTED                       (IPC_SDK_FAULT_BASE+8)        //功能无法支持
#define IPC_E_IPC_SERVICE_UNACCEPTABLE          (IPC_SDK_FAULT_BASE+9)        //设备应答失败
#define IPC_E_CANT_SEND_REQUEST                 (IPC_SDK_FAULT_BASE+10)       //设备通信失败
#define IPC_E_TIMEOUT                           (IPC_SDK_FAULT_BASE+11)       //超时失败
#define IPC_E_BUFFER_OVERFLOW                   (IPC_SDK_FAULT_BASE+12)       //数据溢出错误
#define IPC_E_CANT_CONNECT                      (IPC_SDK_FAULT_BASE+13)       //网络连接失败
#define IPC_E_INVALID_FILE_OPERATION            (IPC_SDK_FAULT_BASE+14)       //磁盘操作失败
#define IPC_E_INVALID_NET_INIT                  (IPC_SDK_FAULT_BASE+15)       //网络创建失败

#define IPC_E_AUDIO_ERROR                       (IPC_SDK_FAULT_BASE+5)        //音频错误
#define IPC_E_CANT_OPEN_AUDIO_STORAGE           (IPC_SDK_FAULT_BASE+16)       //创建音频失败
#define IPC_E_CANT_START_AUDIO_STORAGE          (IPC_SDK_FAULT_BASE+17)       //创建音频失败
#define IPC_E_CANT_CREATE_GRAPH                 (IPC_SDK_FAULT_BASE+18)       //创建音频失败
#define IPC_E_NETSYNTH_NOTFOUND                 (IPC_SDK_FAULT_BASE+19)       //创建音频失败
#define IPC_E_CANT_QUARY_IID_MEDIACONTROL       (IPC_SDK_FAULT_BASE+20)       //创建音频失败
#define IPC_E_CANT_QUARY_IID_BASICAUDIO         (IPC_SDK_FAULT_BASE+21)       //创建音频失败
#define IPC_E_CANT_ADD_AUDIOSOURCE              (IPC_SDK_FAULT_BASE+22)       //创建音频失败
#define IPC_E_CANT_QUARY_IID_NETSYNTH           (IPC_SDK_FAULT_BASE+23)       //创建音频失败
#define IPC_E_INVALID_MEDIA_FMT                 (IPC_SDK_FAULT_BASE+24)       //创建音频失败
#define IPC_E_CODEC_NOTFOUND                    (IPC_SDK_FAULT_BASE+25)       //创建音频失败
#define IPC_E_RENDERER_NOTFOUND                 (IPC_SDK_FAULT_BASE+26)       //创建音频失败
#define IPC_E_REJECT_SOURCEPIN_CONNECTION       (IPC_SDK_FAULT_BASE+27)       //创建音频失败
#define IPC_E_REJECT_RENDERPIN_CONNECTION       (IPC_SDK_FAULT_BASE+28)       //创建音频失败
#define IPC_E_FILTER_NOTFOUND                   (IPC_SDK_FAULT_BASE+29)       //创建音频失败    
#define IPC_E_CANT_QUARY_IID                    (IPC_SDK_FAULT_BASE+30)       //创建音频失败    
#define IPC_E_REJECT_PINCONNECTION              (IPC_SDK_FAULT_BASE+31)       //创建音频失败    
#define IPC_E_UNKNOWN_IPCVERSION                (IPC_SDK_FAULT_BASE+32)       //无法识别设备版本
#define ipcHandle LPVOID
#define playHandle LPVOID
#define displayHandle HWND

//视频属性
#define IPC_VIDEO_BASE								0x00002000
#define IPC_VIDEO_IMGPRO_GROUP						(IPC_VIDEO_BASE+1)		//图像属性			参考结构体IMGPRO
#define IPC_VIDEO_EXPOSURE_MODE						(IPC_VIDEO_BASE+2)		//抗闪烁模式		0 :50Hz ; 1:60Hz; 2:自动
#define IPC_VIDEO_AE_TARGET_RATION					(IPC_VIDEO_BASE+3)		//曝光目标系数		25~400
#define IPC_VIDEO_MAX_GAIN							(IPC_VIDEO_BASE+4)		//SenSor最大增益	30db, 36db, 42db, 48db, 54db, 60db
#define IPC_VIDEO_WBC								(IPC_VIDEO_BASE+5)		//白平衡设置:		 0: 自动;1:incandescent;2:d4000;3: d5000;4: sunny;5: cloudy;6: flash;7: fluorescent;8: fluorescent high;9: under water;10:custom;11: 关闭
#define IPC_VIDEO_DN_MODE							(IPC_VIDEO_BASE+6)		//模式设置			(0 白天,1 夜晚,2 自动,3 定制)  
#define	IPC_VIDEO_BACKLIGHT_COMP					(IPC_VIDEO_BASE+7)		//背光补偿			 0 关闭  1 开启
#define IPC_VIDEO_LOCAL_EXPOSURE					(IPC_VIDEO_BASE+8)		//局部曝光模式		 0 : 关闭; 1: 打开; 2: 暂停; 3: 2x; 4:3x; 5:4x
#define IPC_VIDEO_MCTF_STRENGTH						(IPC_VIDEO_BASE+9)		//3D降噪			 0~255
#define IPC_VIDEO_DCIRIS_GROUP						(IPC_VIDEO_BASE+10)		//DC IRIS模式        参考结构体 IMGIRIS
#define IPC_VIDEO_SHUTTER_GROUP						(IPC_VIDEO_BASE+11)		//电子快门时间范畴   参考结构体 IMGSHUTTER
#define IPC_VIDEO_MJPEG_QUALITY						(IPC_VIDEO_BASE+12)		//图像质量			 0~100
#define IPC_VIDEO_SLOW_SHUTTER						(IPC_VIDEO_BASE+13)     //自动曝光设置中SlowShutter  0:关闭;1:开启
#define IPC_VIDEO_AE_PREFERENCE						(IPC_VIDEO_BASE+14)		//自动曝光的偏好	  0 : 正常模式;1 :暗光模式;2 : 光圈优先
#define IPC_VIDEO_METERING_MODE						(IPC_VIDEO_BASE+15)		//自动曝光设置中测光模式   0:聚光;1:中心;2:平均
#define IPC_ENCODE_ENC_MODE							(IPC_VIDEO_BASE+17)		//编码模式			  0 : 普通；1 : 高质量； 2 : 低延时
#define IPC_ENCODE_SN_TIME_ENABLE0					(IPC_VIDEO_BASE+18)		//码流1叠加时间使能： 0 不叠加时间 1 叠加时间
#define IPC_ENCODE_SN_TIME_ENABLE1					(IPC_VIDEO_BASE+19)		//码流2叠加时间使能： 0 不叠加时间 1 叠加时间
#define IPC_ENCODE_SN_TIME_ENABLE2					(IPC_VIDEO_BASE+20)		//码流3叠加时间使能： 0 不叠加时间 1 叠加时间
#define IPC_ENCODE_SN_TIME_ENABLE3					(IPC_VIDEO_BASE+21)		//码流4叠加时间使能： 0 不叠加时间 1 叠加时间
#define IPC_ENCODE_SN_TEXT_GROUP					(IPC_VIDEO_BASE+22)		//文字叠加信息		参考结构体SNTEXT
#define IPC_ENCODE_ENC_ENC_GROUP					(IPC_VIDEO_BASE+24)		//预览页获取当前码流信息	参考结构体ENCENC  只读
#define IPC_VIDEO_IRCUT_GROUP						(IPC_VIDEO_BASE+25)		//IRCUT昼夜模式		参考结构体IMGIRCUT
#define IPC_VIDEO_IRCUT_NIGHT2DAY_MIN   			(IPC_VIDEO_BASE+26)		//夜晚->白天模式最小阀值   只读 
#define IPC_VIDEO_IRCUT_NIGHT2DAY_MAX   			(IPC_VIDEO_BASE+27)		//夜晚->白天模式最大阀值   只读
#define IPC_VIDEO_IRCUT_DAY2NIGHT_MIN   			(IPC_VIDEO_BASE+28)		//白天->夜晚模式最小阀值   只读
#define IPC_VIDEO_IRCUT_DAY2NIGHT_MAX   			(IPC_VIDEO_BASE+29)		//白天->夜晚模式最大阀值   只读
#define IPC_ENCODE_STR_I_INTERVAL       			(IPC_VIDEO_BASE+30)     //设置I帧间隔  1~8 单位s（演进方向变为1~100帧）
#define IPC_VIDEO_WBC_CUSTOM_R_GAIN     			(IPC_VIDEO_BASE+32)     //自定义R 0~1023
#define IPC_VIDEO_WBC_CUSTOM_B_GAIN     			(IPC_VIDEO_BASE+33)     //自定义B 0~1023
#define IPC_VIDEO_AF_ENABLE             			(IPC_VIDEO_BASE+34)     //聚焦模式 0：手动模式 1：全程自动模式 2：自动聚焦锁定模式
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM0	(IPC_VIDEO_BASE+35) 	//调整码流1 MJPEG压缩率  1(high),2(middle),3(low)
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM1	(IPC_VIDEO_BASE+36) 	//调整码流2 MJPEG压缩率  1(high),2(middle),3(low)
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM2	(IPC_VIDEO_BASE+37) 	//调整码流3 MJPEG压缩率  1(high),2(middle),3(low)
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM3	(IPC_VIDEO_BASE+38) 	//调整码流3 MJPEG压缩率  1(high),2(middle),3(low)


//云台控制
#define IPC_PTZ_BASE								0x00004000
#define IPC_CMD_DPTZ_ZOOM							(IPC_PTZ_BASE + 1)		//控制数字云台视角		  缩放范围: 0~11
#define IPC_CMD_DPTZ_UP								(IPC_PTZ_BASE + 2)		//数字云台上移			  步长限制 0~1000
#define IPC_CMD_DPTZ_DOWN							(IPC_PTZ_BASE + 3)		//数字云台下移			  步长限制 0~1000
#define IPC_CMD_DPTZ_LEFT							(IPC_PTZ_BASE + 4)		//数字云台左移			  步长限制 0~1000
#define IPC_CMD_DPTZ_RIGHT							(IPC_PTZ_BASE + 5)		//数字云台右移			  步长限制 0~1000
#define IPC_CMD_DPTZ_SET_PRESET						(IPC_PTZ_BASE + 6)		//设置数字云台预置位      预置位范围: 1~9
#define IPC_CMD_DPTZ_CLEAR_PRESET					(IPC_PTZ_BASE + 7)		//清理指定数字云台预置位  预置位范围: 1~9
#define IPC_CMD_DPTZ_GOTO_PRESET	    			(IPC_PTZ_BASE + 8)		//转到数字云台预置位      预置位范围: 1~9
#define IPC_CMD_DPTZ_CLEAR_ALL_PRESET				(IPC_PTZ_BASE + 9)		//清理所有数字云台预置位
#define IPC_CMD_DPTZ_GOTO_HOME						(IPC_PTZ_BASE + 10)		//移到数字云台起始位
#define IPC_CMD_DPTZ_FOCUS_FAR          			(IPC_PTZ_BASE + 11) 	//数字聚焦远			  开关标志 0:on, 1:off
#define IPC_CMD_DPTZ_FOCUS_NEAR         			(IPC_PTZ_BASE + 12) 	//数字聚焦近              开关标志 0:on, 1:off

#define IPC_CMD_PTZ_FOCUS_NEAR						(IPC_PTZ_BASE + 21)		//缩小机械云台焦距
#define IPC_CMD_PTZ_FOCUS_FAR						(IPC_PTZ_BASE + 22)		//放大机械云台焦距
#define IPC_CMD_PTZ_ZOOM_WIDE						(IPC_PTZ_BASE + 23)		//放大机械云台视角   
#define IPC_CMD_PTZ_ZOOM_TELE						(IPC_PTZ_BASE + 24)		//缩小机械云台视角
#define IPC_CMD_PTZ_UP								(IPC_PTZ_BASE + 25)		//机械云台上移
#define IPC_CMD_PTZ_DOWN							(IPC_PTZ_BASE + 26)		//机械云台下移
#define IPC_CMD_PTZ_LEFT							(IPC_PTZ_BASE + 27)		//机械云台左转
#define IPC_CMD_PTZ_RIGHT							(IPC_PTZ_BASE + 28)		//机械云台右转
#define IPC_CMD_PTZ_GOTO_HOME						(IPC_PTZ_BASE + 29)		//移到机械云台起始位置
#define IPC_CMD_PTZ_SET_PAN_SPEED					(IPC_PTZ_BASE + 30) 	//机械云台水平速度		0~100
#define IPC_CMD_PTZ_SET_TILT_SPEED					(IPC_PTZ_BASE + 31) 	//机械云台垂直速度		0~100

#define IPC_CMD_PTZ_SET_LEFTBORDER					(IPC_PTZ_BASE + 44) 	//设置左边界
#define IPC_CMD_PTZ_SET_RIGHTBORDER					(IPC_PTZ_BASE + 45) 	//设置右边界
#define IPC_CMD_PTZ_AUTO_SCAN						(IPC_PTZ_BASE + 46) 	//自动左右扫描
#define IPC_CMD_PTZ_AUXIOPEN						(IPC_PTZ_BASE + 47) 	//辅助开  支持辅助点 1~8
#define IPC_CMD_PTZ_AUXICLOSE						(IPC_PTZ_BASE + 48) 	//辅助关
#define IPC_CMD_PTZ_AUTOPAN							(IPC_PTZ_BASE + 49) 	//自动水平旋转

#define IPC_CMD_PTZ_GOTO_REL_POSITION				(IPC_PTZ_BASE + 50) 	//从相对当前坐标位置运动指定的偏移量
#define IPC_CMD_PTZ_GOTO_ABS_POSITION				(IPC_PTZ_BASE + 51) 	//运动到指定的绝对坐标位置
#define IPC_CMD_PTZ_GET_ABS_POSITION				(IPC_PTZ_BASE + 52) 	//获取云台当前的绝对坐标
#define IPC_CMD_PTZ_IRIS_OPEN						(IPC_PTZ_BASE + 53)		//光圈
#define IPC_CMD_PTZ_IRIS_CLOSE						(IPC_PTZ_BASE + 54)		//光圈
#define IPC_CMD_PTZ_3DPOSBOX                        (IPC_PTZ_BASE + 55)		//区域缩放

#define IPC_CMD_PTZ_IRIS_AUTO						(IPC_PTZ_BASE + 62)		//自动光圈
#define IPC_CMD_PTZ_FOCUS_AUTO						(IPC_PTZ_BASE + 63)		//自动聚焦
//事件
#define IPC_EVENT_BASE								0x00005000

//事件类型
#define IPC_EVENT_INPUTPORT							(IPC_EVENT_BASE+15)		//外部输入报警
#define IPC_EVENT_CAMERATAMPERING					(IPC_EVENT_BASE+16)		//视频异常报警
#define IPC_EVENT_MONTIONDETECTION					(IPC_EVENT_BASE+17)     //移动侦测报警
#define IPC_EVENT_REBOOT							(IPC_EVENT_BASE+31)		//设备重启报警
#define IPC_EVENT_OUTPUT							(IPC_EVENT_BASE+48)		//报警输出

//录像存储方式
#define IPC_RECORD_FILELOCATION_FTP					(IPC_EVENT_BASE+23)		//录像存储方式为FTP   用于 RECORDACTION 中的 locationID
#define IPC_RECORD_FILELOCATION_SDCARD				(IPC_EVENT_BASE+24)		//录像存储方式为SD卡  用于 RECORDACTION 中的 locationID
#define IPC_RECORD_FILELOCATION_EMAIL				(IPC_EVENT_BASE+25)		//录像存储方式为邮件  用于 RECORDACTION 中的 locationID

//系统管理
#define IPC_SYSTEM_BASE								0x00007000	
#define IPC_SYSTEM_GET_DEVICE_NAME					(IPC_SYSTEM_BASE+5)		//设备名称		 
#define IPC_SYSTEM_GET_DEVICE_MANUFACTURER			(IPC_SYSTEM_BASE+6)		//设备厂商       只读属性
#define IPC_SYSTEM_GET_FW_VERSION					(IPC_SYSTEM_BASE+7)		//设备软件版本   只读属性 
#define IPC_SYSTEM_GET_HW_VERSION					(IPC_SYSTEM_BASE+8)		//设备硬件版本   只读属性
#define IPC_SYSTEM_SETGET_DATEINFO					(IPC_SYSTEM_BASE+9)		//设备时间配置   参考结构体 SYSDATEINFO
#define IPC_SYSTEM_AUDIO_SETTING            		(IPC_SYSTEM_BASE+15)	//设置语音属性   参考结构体 AUDIOCONF
#define IPC_SYSTEM_GETSET_ALARMCENTER       		(IPC_SYSTEM_BASE+18)    //报警中心配置   参考结构体 IPC_ALARMCENTER_UP_CFG
#define IPC_SYSTEM_GET_DEVICE_SN                    (IPC_SYSTEM_BASE+19)    //获取设备出厂唯一编码
#define IPC_SYSTEM_SETGET_DATEINFOEX				(IPC_SYSTEM_BASE+30)  	//更新设备时间扩展接口 参考结构体 SYSDATEINFOEX
#define IPC_SYSTEM_GET_SUPPORT_GB					(IPC_SYSTEM_BASE+31)	//获取设备支持国标能力情况
#define IPC_SYSTEM_GET_SUPPORT_RTSP					(IPC_SYSTEM_BASE+32)	//获取设备支持RTSP能力情况
//EXT
#define IPC_SYSTEM_GETUSRINFO                       (IPC_SYSTEM_BASE+36)	//获取账号信息 
#define IPC_SYSTEM_SETUSRINFO                       (IPC_SYSTEM_BASE+37)	//设置账号信息 
#define IPC_SYSTEM_ALARMINCFG                       (IPC_SYSTEM_BASE+38)	//报警输入配置 
#define IPC_SYSTEM_ALARMOUTCFG                      (IPC_SYSTEM_BASE+39)	//报警输出配置 
#define IPC_SYSTEM_AUX_ALARMCFG						(IPC_SYSTEM_BASE+40)	//辅助报警配置 
#define IPC_SYSTEM_DAYNIGHT                         (IPC_SYSTEM_BASE+42)	//日夜模式扩展  仅3.0支持 
#define IPC_SYSTEM_SHIELDVERSION                    (IPC_SYSTEM_BASE+43)	//云台护照版本  仅3.0支持 
#define IPC_SYSTEM_AUTOFOCUSEX                      (IPC_SYSTEM_BASE+44)	//自动聚焦参数扩展  仅3.0支持
#define IPC_SYSTEM_NETPORT                          (IPC_SYSTEM_BASE+45)	//网络端口配置  仅3.0支持

#define  IPC_MAX_TIME_SEC							16						//最多支持的时间段个数
#define  IPC_MAX_CENTER								 3						//最多支持三个报警中心
#define  IPC_MAX_IPADDR_LEN							32						//IP地址最大长度
#define  IPC_MAX_NAME_LEN							64						//名称的最大长度
#define  IPC_MAX_PRESET_CRUISE_POINTS				32						//最多支持的巡航点个数
#define  IPC_MAX_CRUISE_PATH						32						//最多支持的巡航路径个数
#define	 IPC_MAX_IMGINFO_COUNT						32						//最多支持的分辨率 帧率信息个数
#define  IPC_LOG_MAX_USER_NAME_LEN					20						//日志查询最大用户名称长度
#define  IPC_LOG_MAX_SUMMARY_LEN					128						//日志查询最大概述长度			
#define  IPC_LOG_MAX_DESCRIPTION_LEN				512						//日志查询最大详细描述长度
#define  IPC_MAX_USERNUM							30                      //允许登陆的最大数量
#define  IPC_MAX_SHELTER_COUNT                      4                       //隐私遮挡窗口最大个数
#define  IPC_MAX_DAYS                               7                       //每周的天数
#define  IPC_MAX_MOTION_WND_COUNT                   4                       //移动侦测窗口最大个数

#define  IPC_SET_CRUISE_ALLDATA              	    1			            //包含设置的巡航路径的全部信息
#define  IPC_CLEAR_CRUISE                    	    4			            //删除某一条巡航路径

//日志查找结果
#define IPC_LOG_SUCCESS 							1000 					//获取日志信息成功
#define IPC_LOG_NOFIND 								1001  					//未查找到日志
#define IPC_LOG_ISFINDING 							1002 					//正在查找请等待
#define IPC_LOG_NOMORERECORD  						1003 					//没有更多的日志，查找结束
#define IPC_LOG_EXCEPTION  							1004 					//查找日志时异常

//日志类型
#define IPC_LOG_ALL									0x00000000				//全部日志
#define IPC_LOG_ACCESS								0x00000001				//访问日志
#define IPC_LOG_ALARM								0x00000002				//报警日志
#define IPC_LOG_SYSTEM								0x00000004				//系统日志

//SD卡录像管理
#define IPC_COMMAND_RECORD_BASE         0x00008000

#define IPC_COMMAND_RECORD_CTRL             (IPC_COMMAND_RECORD_BASE + 0)       //SD卡录像操作（添加删除等）
#define IPC_COMMAND_SET_RECORD_CONFIG       (IPC_COMMAND_RECORD_BASE + 1)		//SD卡录像的配置（大小和混流方式）
#define IPC_COMMAND_GET_RECORD_CONFIG       (IPC_COMMAND_RECORD_BASE + 2)		//SD卡录像的配置（大小和混流方式）
#define IPC_COMMAND_RECORD_SEARCH           (IPC_COMMAND_RECORD_BASE + 3)       //SD卡录像的查找（按条件）
#define IPC_COMMAND_GET_RECORD_NUM          (IPC_COMMAND_RECORD_BASE + 4)       //SD卡录像的数量统计（按条件）

//录像查找结果
#define IPC_FINDFILE_SUCCESS 				1000 					//获取日志信息成功
#define IPC_FINDFILE_NOFIND 				1001  					//未查找到日志
#define IPC_FINDFILE_ISFINDING 				1002 					//正在查找请等待
#define IPC_FINDFILE_NOMORERECORD  			1003 					//没有更多的日志，查找结束
#define IPC_FINDFILE_EXCEPTION  			1004 					//查找日志时异常

#define IPC_RECORDSTART			1				//开始录像 
#define IPC_RECORDSTOP			2				//停止录像 
#define IPC_DELETEFILE			3				//删除录像文件 
#define IPC_LOCKFILE			4				//锁定录像文件 
#define IPC_UNLOCKFILE			5				//解锁录像文件
#define IPC_GET_RECORDCONFIG	6				//获取录像文件分割大小信息
#define IPC_SET_RECORDCONFIG	7				//设置录像文件分割大小

#define IPC_SDK_LOCAL_UTF8				    0xFF000000		//sdk 字符使用utf8
#define IPC_SDK_LOCAL_WEB_ONLYV3			0xFF000001		//sdk 仅仅支持3.0相机web控件，优化性能 


//云台宏
#define IPC_ZOOM_TELE           11              //云台缩放
#define IPC_ZOOM_WIDE           12    

#define IPC_FOCUS_NEAR          13              //云台聚焦
#define IPC_FOCUS_FAR           14    

#define IPC_IRIS_OPEN           15                        
#define IPC_IRIS_CLOSE          16 

#define IPC_TILT_UP             17              //云台上
#define IPC_TILT_DOWN           18              //云台下
#define IPC_PAN_LEFT            19              //云台左
#define IPC_PAN_RIGHT           20              //云台右

#define IPC_UP_LEFT             21              //云台左上
#define IPC_UP_RIGHT            22              //云台右上
#define IPC_DOWN_LEFT           23              //云台左下
#define IPC_DOWN_RIGHT          24              //云台右下

#define IPC_AUXIOPEN            25                        
#define IPC_AUXICLOSE           26

#define IPC_PAN_AUTO            27                                            

#define IPC_SET_LEFTBORDER      28              //云台左边界
#define IPC_SET_RIGHTBORDER     29              //云台右边界
#define IPC_AUTOSCAN            30              //云台自动扫描
#define IPC_GOTO_HOME           31    

#define IPC_SET_PRESET          32              //云台设置预置位
#define IPC_GOTO_PRESET         33              //云台移动到预置位

#define IPC_GET_ALL_PRESET      34              //云台获取所有预置位
#define IPC_CLEAR_PRESET        35              //云台清除预置位
#define IPC_GET_CAPACITY        36              //云台获取预置位数量

//云台位置控制
#define IPC_RUN_SEQ				10
#define IPC_STOP_SEQ			11

#pragma pack(push,1)	
typedef struct tagIPC_PRESET_CRUISE_POINT
{
	INT		iPresetIdx;													//预置点索引 1~255
	INT     iStaySec;													//停留时间 单位秒 
	INT     iMoveSpeed;													//转到该预置点的速度  
} IPC_PRESET_CRUISE_POINT_t;												//巡航点定义

struct IPC_PTZCruiseParam
{
	INT		id;															//巡航路径id, 1~32
	CHAR    name[IPC_MAX_NAME_LEN];										//巡航路径名称  
	INT    iEnable;														//巡航路径使能
	DWORD	iCount ;													//巡航路径里巡航点个数
	IPC_PRESET_CRUISE_POINT_t	point[IPC_MAX_PRESET_CRUISE_POINTS];		//巡航点
};

typedef struct tagIPC_PTZPositionParam 
{
	INT		xPosition ;													//水平方向 坐标:  取值范围受ipcPTZPositionControl 函数的命令宏影响 ： 
																		//命令为IPC_CMD_PTZ_GOTO_REL_POSITION时候,取值范围-35999到35999
																		//命令为IPC_CMD_PTZ_GOTO_ABS_POSITION时候,取值范围  0 到35999

	INT		yPosition ;													//垂直方向坐标，取值范围受ipcPTZPostionControl 函数的命令宏影响 ： 
																		//命令为IPC_CMD_PTZ_GOTO_REL_POSITION时候,取值范围-9000到9000
																		//命令为IPC_CMD_PTZ_GOTO_ABS_POSITION时候,取值范围0 到9000 
	INT     zPosition ;													//放大倍数,应大于等于0且是10的整数倍,0表示原始大小即放大1倍,10表示原始大小放大2倍,20表示放大原始大小3倍,
																		//zPosition/10+1为放大的倍数,zPosition的最大值180（该值由硬件设备决定）,传递的值超过设备支持的最大值时，设备自动设置为最大值。 

	INT		xSpeed ;													//水平方向移动的速度
	INT		ySpeed ;													//垂直方向移动的速度
}IPC_PTZ_POSITION_PARAM, *LPIPC_PTZ_POSITION_PARAM;


typedef struct tagIPC_ALARMCENTER_UP_CFG{
  BYTE		byEnable[IPC_MAX_CENTER];									//上传中心使能标志						                                        
  WORD		wHostPort[IPC_MAX_CENTER];									//上传中心端口            
  CHAR		sHostIPAddr[IPC_MAX_CENTER][IPC_MAX_IPADDR_LEN];			//上传中心IP地址 
  BYTE		dwReserved[1];												//保留字
}IPC_ALARMCENTER_UP_CFG;

//MP4文件存储接口宏定义和结构
#define		IPC_MP4FRAME_UNDEFINE				0x00
#define		IPC_MP4FRAME_I						0x01					//I frame
#define		IPC_MP4FRAME_P						0x02					//P frame
#define		IPC_MP4FRAME_B						0x03					//B frame		
#define		IPC_MP4FRAME_A						IPC_MP4FRAME_UNDEFINE	//Audio frame

//视频参数 
typedef struct IPC_MP4_VIDEOPARAM_t
{
    int			dwHeight;                       						//高
    int			dwWidth;                        						//宽
    double		dwFrameInterval;                						//帧间隔  	帧间隔（单位：100纳秒）计算方法（如：10000000.0 / FrameRate）
    int			dwBitRate;                      						//码率
    int			dwAspectRatio;                   						//比例
    int			dwParWidth;												//保留默认为0             
    int			dwParHeight;											//保留默认为0   
    int			cbExtraInfo;											//保留默认为0   
    void		*pExtraInfo;											//保留默认为0   
} IPC_MP4_VIDEOPARAM,*LPIPC_MP4_VIDEOPARAM; 

//音频参数
typedef struct IPC_MP4_AUDIOPARAM_t
{
    int			dwChannel;            									//声道          
    int			dwSamplePerSec;       									//采样频率           
    int			dwBitsPerSample ;     									//采样精度                
    int			nAvgBytesPerSec;      									//平均码率                
    int			nBlockAlign;		  									//块对齐方式      
    int			cbExtraInfo;		  									//扩展数据长度      
    void		*pExtraInfo;		  									//扩展数据      
} IPC_MP4_AUDIOPARAM,*LPIPC_MP4_AUDIOPARAM; 

typedef struct IPC_CALLBACK_INFO_t
{
    UINT32                      lType ;            						//帧类型,<video:'I','P','B'><audio:'A'>
    const unsigned char*        pBuf;			   						//帧数据缓冲区
    UINT32			            lBufSize;		   						//帧数据缓冲区大小
    LONGLONG                    lStamp;            						//时间戳<保留>
    union {
        struct Video{
            UINT32              lVideoFormat ;     						//0:H264, 1:MJPEG
            UINT32	            lWidth;			   						//图像宽
            UINT32	            lHeight;		   						//图像高
            UINT32	            lFrameRate;        						//帧率
        } video ;
        struct Audio{
            UINT32                lAudioFormat ;     					//0:AMR, 1:G711
            UINT32                lSamplesPerSec ;   					//8000
            UINT32                lChannels ;        					//1
            UINT32                lBitsPerSample ;   					//16
            UINT32                lAvgBytesPerSec ;  					//16000（lSamplesPerSec * lBitsPerSample * lChannels / 8）
        } audio ;
    } info ;
}IPC_CALLBACK_INFO,*LPIPC_CALLBACK_INFO,IPC_FrameInfoEx;

typedef struct IPCVIDEO_CALLBACK_INFO_t
{
    long                lType ;                 						//帧类型,I,P,B
    long	            lWidth;				    						//图像宽
    long	            lHeight;			    						//图像高
    long	            lFrameRate;             						//帧率
    const unsigned char	*pBuf;			        						//帧数据缓冲区
    long			    lBufSize;		        						//帧数据缓冲区大小

}IPCVIDEO_CALLBACK_INFO,*LPIPCVIDEO_CALLBACK_INFO,IPC_FrameInfo ;

//视频录像动作
typedef struct tagIPC_RecordAction
{
	tagIPC_RecordAction()
	{
		memset(this, 0, sizeof(tagIPC_RecordAction));
	}
	INT       enable_flag;												//0为删除，1为有效			
	DWORD     delay;													//录像持续时间动作，以秒为单位
	DWORD     streamID;													//0:码流1， 1:码流2 ，2:码流3  ，3:码流4
	DWORD     locationID;       										//文件保存类型，有IPC_RECORD_FILELOCATION_FTP，IPC_RECORD_FILELOCATION_SDCARD		
}IPC_RECORDACTION, *LPIPC_RECORDACTION;

//数字云台动作
typedef struct tagIPC_DPTZAction
{
	tagIPC_DPTZAction()
	{
		memset(this, 0, sizeof(tagIPC_DPTZAction));
	}
	INT        enable_flag;												//0为删除，1为启用					
	DWORD      delay;													//转移到预置位后停留时间，以秒为单位
	DWORD      streamID;												//0:码流1， 1:码流2 ，2:码流3  ，3:码流4
	DWORD      preset;													//预置位标识号,取值范围为1到9
}IPC_DPTZACTION, *LPIPC_DPTZACTION;

//机械云台动作
typedef struct tagIPC_PTZAction
{
	tagIPC_PTZAction()
	{
		memset(this, 0, sizeof(tagIPC_PTZAction));
	}
	INT        enable_flag;												//0为删除，1为启用				
	DWORD      delay;													//转移到预置位后停留时间，以秒为单位
	DWORD      preset;													//预置位标识号,取值范围为1到255
}IPC_PTZACTION, *LPIPC_PTZACTION;

//输出端口动作
typedef struct tagIPC_OutputAction
{
	tagIPC_OutputAction()
	{
		memset(this, 0, sizeof(tagIPC_OutputAction));
	}
	INT        enable_flag;												//0为删除， 1为启用				
	DWORD      level;													//保留参数,高低电平， 0为低电平， 1为高电平
}IPC_OUTPUTACTION, *LPIPC_OUTPUTACTION;

//响应动作信息
typedef struct tagIPC_ActionOptionInfo
{
	tagIPC_ActionOptionInfo()
	{
		memset(this, 0, sizeof(tagIPC_ActionOptionInfo));
	}
	DWORD             priority;											//动作的优先级 0: Low, 1: Middle, 2: High	
	DWORD             respond_option;   								//响应方式,0：报警持续期间执行动作，1：报警发生和结束时执行动作，2：报警发生时执行动作 	3：报警结束时执行动作
	IPC_RECORDACTION	  record ;											//录像动作,			见RECORDACTION数据结构 
	IPC_DPTZACTION		  dptz;												//数字云台动作,		见DPTZACTION数据结构 
	IPC_PTZACTION         ptz;												//机械云台动作,		见PTZACTION数据结构 
	IPC_OUTPUTACTION      output;											//报警输出口动作,	见OUTPUTACTION数据结构
	DWORD               dwLinkAlarmStrategy;						           //仅支持3.0联动策略，按位表示，第0位-告警输出，第1位-上传中心，第2位-声音输出，第3位-邮件，第4位-FTP上传，第5位-录像，第6位-PTZ，第7位-抓图，第8位-白光
	DWORD               dwCheckTime;                                          //仅支持3.0 单位：毫秒，检测告警状态的时间间隔
	DWORD               dwIoNum;                                                 //仅支持3.0 按位表示：第0位-告警输出端口0，第1位-告警输出端口1，第2位-告警输出端口2，第3位-告警输出端口3。位为0表示未设置，位为1表示设置。                             
	DWORD               dwOperateCmd;                                       //仅支持3.0 联动云台命令，0-无，1-预置点，2-预置点巡航，3-花样扫描
	DWORD               dwOperateSeqNum;                                //仅支持3.0 序号：预置点序号/巡航轨迹序号/花样扫描序号
	DWORD               dwPtzDelayTime;                                     //仅支持3.0 云台动作持续时间，单位为S
	DWORD               dwDelayTime;                                          //仅支持3.0 白光输出持续时间，单位为S
} IPC_ActionOptionInfo,*LPIPC_ActionOptionInfo ;


typedef struct tagIPC_MontionDetectionWindowInfoEx
{
	tagIPC_MontionDetectionWindowInfoEx()
	{
		memset(this, 0, sizeof(tagIPC_MontionDetectionWindowInfoEx));
	}
	int          index;													//窗口id 范围1~4	
	int			 enable;												//侦测区域使能标志 0 禁用 1启用
	CHAR         name[128] ;											//窗口名称			
	RECT         rect ;													//窗口区间，为RECT结构体
																		//视频图像被分成12x8=96 个格子 。x,y 可确定左上角，right,bottom可以确定右下角。右下角的坐标一定要大于左上角的坐标
																		//x 取值范围[0, 11].     y 取值范围 [0, 7].     right 取值范围 [1, 12].     width 取值范围 [1, 8].
																		//例如： rect 为{x=1，y=1 ，right=2，bottom=2} 表示占用(1,1),(1,2),(2,1),(2,2)四个格子

	INT          agile;													//灵敏度 范围[0, 10],值越大越灵敏，建议值3~5,		
	INT          threshold;												//阈值 范围[1, 100],值越小越容易触发事件，建议值25~30  				
}IPC_MontionDetectionWindowInfoEx,*LPIPC_MontionDetectionWindowInfoEx ;

//IrCut昼夜模式
typedef struct tagIPC_IRCUT
{
	tagIPC_IRCUT()
	{
		memset(this, 0, sizeof(tagIPC_IRCUT)) ;
	}
	DWORD	ircut_DurTime ;												//等待时间，即每次作出日夜切换决策的时间间隔  3s ~ 30s  默认10s
	DWORD	ircut_DayToNightThr ;										//白天模式转夜晚模式的阈值	0~100   默认 40
	DWORD	ircut_NightToDayThr ;   									//夜晚模式转白天模式的阈值	0~100 默认 60
}IPC_IMGIRCUT, *LPIPC_IMGIRCUT;

//图像属性
typedef struct tagIPC_IMGPRO
{
	tagIPC_IMGPRO()
	{
		memset(this, 0, sizeof(tagIPC_IMGPRO));
	}
	DWORD	img_saturation; 											//取值范围：0~255
	LONG	img_brightness; 											//取值范围：-255~255
	LONG	img_hue;													//取值范围：-15~15	
	DWORD	img_contrast;												//取值范围：0~255
	DWORD	img_sharpness;  											//取值范围：0~255
}IPC_IMGPRO, *LPIPC_IMGPRO;

//DC IRIS模式
typedef struct tagIPC_IMGIRIS
{
	tagIPC_IMGIRIS()
	{
		memset(this, 0, sizeof(tagIPC_IMGIRIS));
	}
	DWORD	iris_type; 													//模式 0关闭;1开启	
	DWORD	iris_quty; 													//占空值 100 ~ 999	
}IPC_IMGIRIS, *LPIPC_IMGIRIS;

//电子快门时间范畴
typedef struct tagIPC_IMGSHUTTER
{
	tagIPC_IMGSHUTTER()
	{
		memset(this, 0, sizeof(tagIPC_IMGSHUTTER));
	}
	DWORD	shutter_min;												//最小值的取值范围为64000 到 20480000	
	DWORD	shutter_max;												//最大值的取值范围为64000 到 68266667
}IPC_IMGSHUTTER, *LPIPC_IMGSHUTTER;

//视频遮挡
typedef struct tagIPC_IMGPM
{
	tagIPC_IMGPM()
	{
		memset(this, 0, sizeof(tagIPC_IMGPM));
	}
	INT		pm_index;													//索引，取值范围为1到4
	INT		enable_flag	;												//true为启用，false为删除	
	DWORD	pm_left; 													//	0~99   具体定义参考文档详细说明
	DWORD	pm_top; 													// 	0~99
	DWORD	pm_w;														//	1~100
	DWORD	pm_h;														//	1~100
	DWORD	pm_color; 													//区域颜色 0:黑色 1:红色 2:蓝色 3:绿色 4:黄色 5:洋红 6:青绿 7:白色			
}IPC_IMGPM, *LPIPC_IMGPM;


//视频遮挡
typedef struct tagIPC_IMGPM_EX
{
	tagIPC_IMGPM_EX()
	{
		memset(this, 0, sizeof(tagIPC_IMGPM_EX));
	}
	INT		pm_index;													//索引，取值范围为1到4
	INT		enable_flag	;												//true为启用，false为删除	
	DWORD	pm_left; 													//	0~99   具体定义参考文档详细说明
	DWORD	pm_top; 													// 	0~99
	DWORD	pm_w;														//	1~100
	DWORD	pm_h;														//	1~100
	DWORD	pm_color; 													//区域颜色 0:黑色 1:红色 2:蓝色 3:绿色 4:黄色 5:洋红 6:青绿 7:白色	
	CHAR	szName[32];
}IPC_IMGPM_EX, *LPIPC_IMGPM_EX;

//显示信息叠加
typedef struct tagIPC_SNTEXT
{
	tagIPC_SNTEXT()
	{
		memset(this, 0, sizeof(tagIPC_SNTEXT)) ;
	}
	DWORD	text_streamID ;												//码流ID，0为码流1，1为码流2，2为码流3，3为码流4
	BOOL	text_enable; 												//是否显示文字信息，0为不显示， 1为显示	
	CHAR	text_content[32];											//文字信息内容，最多32个字符
}IPC_SNTEXT, *LPIPC_SNTEXT;


// 仅预览时获取当前码流信息
typedef struct tagIPC_ENCENC
{
	tagIPC_ENCENC()
	{
		memset(this, 0, sizeof(tagIPC_ENCENC));
	}
	DWORD	enc_streamID ;											//为当前正在预览的码流ID，0为码流1，1为码流2，2为码流3，3为码流4
	DWORD 	enc_type; 												//编码格式： 1为H.264，2为MJPEG			
	DWORD 	enc_fbs;												//编码帧率 60fps为 8533333， 30fps为17066667，25fps为20480000
																	//20fps为25600000，15fps为34133333，10fps为51200000，6fps为85333333 
																	//5fps为102400000，3fps为170666667，2fps为256000000，1fps为512000000
	DWORD	enc_brcMode;											//比特率控制，0为CBR，1为VBR，2为CBR (keep quality) ，3为VBR (keep quality)		
	DWORD 	enc_cbrAVG;												//比特率平均值，介于1000000到8000000之间		
	DWORD 	enc_vbr_min;											//最小比特率，默认为1000000		
	DWORD 	enc_vbr_max;											//最大比特率，默认为8000000		
}IPC_ENCENC, *LPIPC_ENCENC;

//时间设置
typedef struct tagIPC_SYSDATEINFO
{
	tagIPC_SYSDATEINFO()
	{
		memset(this, 0, sizeof(tagIPC_SYSDATEINFO));
	}
	DWORD		sync_mode;											//设备时间同步类型（只写），0:与NTP同步，ntp_addr不能为null。1:手动设置， time_date和time_time不能为空2:与pc时间同步，time_date和time_time不能为空																 
	CHAR	time_date[32]	;										//日期
	CHAR	time_time[32];											//时间
	CHAR	ntp_addr[32];											//ntp服务器地址 （只写）
}IPC_SYSDATEINFO, *LPIPC_SYSDATEINFO;

//时间设置扩展接口
typedef struct tagIPC_SYSDATEINFOEX
{
	tagIPC_SYSDATEINFOEX()
	{
		memset(this, 0, sizeof(tagIPC_SYSDATEINFOEX));
	}
	DWORD	sync_mode;												//设备时间同步类型,0:与NTP同步(ntp_addr和timeZone有效),				1:手动设置(time_date、time_time和timeZone有效)
																	//				   2:与pc同步(time_date、time_time和timeZone有效)	3:自动同步(interval、timeZone和ntp_addr有效)
	CHAR	time_date[32]	;										//日期
	CHAR	time_time[32];											//时间
	int		interval ;												//时间间隔，单位分钟，取值范围1-100000
	char    timeZone[32] ;											//时区，格式为CST+HH:MM:SS或CST-HH:MM:SS，如东八区为CST+08:00:00，西八区为CST-08:00:00
	char	ntp_addr[32];											//ntp服务器地址
}IPC_SYSDATEINFOEX, *LPIPC_SYSDATEINFOEX;

typedef struct tagIPC_SYSUPNPINFO
{
	tagIPC_SYSUPNPINFO()
	{
		memset(this, 0, sizeof(tagIPC_SYSUPNPINFO));
	}
	DWORD	     enable;											//是否可用，true为可用，false为不可用					
	DWORD	     port;												// 端口号		
	CHAR	     name[32];											// 名称			
}IPC_SYSUPNPINFO,*LPIPC_SYSUPNPINFO;

//SMTP设置
typedef struct tagIPC_SYSSMTP
{
	tagIPC_SYSSMTP()
	{
		memset(this, 0, sizeof(tagIPC_SYSSMTP));
	}
	DWORD		smtp_enable;										//是否配置SMTP, 1:需要配置，0:不需要配置
	CHAR		smtp_addr[32];										//smtp邮件服务器地址，格式类似于192.168.1.114
	DWORD		smtp_port;											//smtp端口号 0到65535
	DWORD		smtp_auth_enable;									//是否使用权限认证登陆 1:使用， 0:不使用（不
																	//需要填写name和pw）
	CHAR		smtp_auth_name[32];									//用户名
	CHAR		smtp_auth_password[32];								//密码
	DWORD		smtp_auth_model;									//验证方式，0:LOGIN  1:PLAIN
	CHAR		smtp_sender[64];									//发件人地址，正确邮箱地址
	CHAR		smtp_receiver[64];									//收件人地址，正确邮箱地址
	CHAR		smtp_cc[64];										//抄送地址， 正确邮箱地址
	CHAR		smtp_subject[64];									//邮件主题
	CHAR		smtp_content[128];									//邮件内容，文本字符。
}IPC_SYSSMTP, *LPIPC_SYSSMTP;

//FTP设置
typedef struct tagIPC_SYSFTP
{
	tagIPC_SYSFTP()
	{
		memset(this, 0, sizeof(tagIPC_SYSFTP));
	}
	DWORD		ftp_enable;											//是否开启ftp， 1:开启，0:关闭
	CHAR		ftp_addr[32];										//ftp服务器地址
	DWORD		ftp_port;											//ftp端口
	CHAR		ftp_user[32];										//用户名
	CHAR		ftp_password[32];									//密码

}IPC_SYSFTP, *LPIPC_SYSFTP;

//ipv4地址配置
typedef struct tagIPC_SYSIPINFO
{
	tagIPC_SYSIPINFO()
	{
		memset(this, 0, sizeof(tagIPC_SYSIPINFO));
	}
	DWORD	dhcp_enable;											//配置ip地址方式，1:采用dhcp，0:手动配置ip
	CHAR	ip_addr[32];											//ip地址
	CHAR	network_mask[32];										//子网掩码
	CHAR	gateway_addr[32];										//默认网关
	CHAR	dns_addr[32];											//首选DNS服务器地址
	CHAR	dns_backup_addr[32];									//备用DNS服务器地址
	CHAR	mac_addr[32]	;										//mac地址 （只读），不可设置
}IPC_SYSIPINFO, *LPIPC_SYSIPINFO;

typedef enum tagIPC_DEVICESTATE
{
    ipc_ds_online,              										//在线
    ipc_ds_offlline,            										//离线
    ipc_ds_busy,                										//忙碌
    ipc_ds_idle,                										//休眠
    ipc_ds_unknow               										//无法探知
}IPC_DEVICESTATE,*LPIPC_DEVICESTATE;

typedef struct tagIPCSCANINFO
{
	tagIPCSCANINFO()
	{
		memset(this, 0, sizeof(tagIPCSCANINFO));
	}
    IPC_DEVICESTATE state ;         								//设备当前状态
    int  port ;                 									//端口
    char mac[32] ;              									//mac地址
    char IPAddress[32] ;        									//ip地址
    char PrimaryDns[32] ;       									//dns
    char SecondaryDns[32] ;     									//备用 dns
    char Netmask[32] ;          									//掩码
    char Gateway[32] ;          									//网关
}IPCSCANINFO,*LPIPCSCANINFO ;

//音频属性
typedef struct {
    int audio_enable;												//是否启用语音对讲功能0:disable 1:enable
    int codec_fmt;													//0:AMR, 1:G711
    int audio_out_enable;											//是否允许设备输出声音，0:disable 1:enable
    int audio_out_vol;												//设备输出音量 eg:(50)50%
    int audio_in_vol;												//设备输入音量 eg:(50)50%
    int echo_canceller_enable;										//回音消除 
}IPC_AUDIOCONF_t,* LPIPC_AUDIOCONF ;

typedef struct {
    int cmd;														//0 : stop, 1 : start, 
} IPC_AUDIOCONFERENCECTRL_t,*LPIPC_AUDIOCONFERENCECTRL ;

typedef struct {
    int status;														//0 : stop, 1 : start, 
} IPC_AUDIOCONFERENCESTATUS_t,*LPIPC_AUDIOCONFERENCESTATUS ;

//声卡设备
typedef struct IPC_AudioDevice_t { 
    INT iId;														//声卡设备id 
    CHAR sDevName[128];												//声卡设备名字 
} IPC_AudioDevice,*LPIPC_AudioDevice ;

//串口配置信息
typedef struct IPC_COMM_PROP_t{ 

    BYTE byDataBit;     											//数据位 [7,8]
    BYTE byStopBit;     											//停止位 [1,2]
    BYTE byParity;      											//校验位 [0,2]：PARITY_NONE  = 0,    PARITY_ODD   = 1,        PARITY_EVEN  = 2,
    BYTE byBaudRate;    											//波特率 [0,9]：0=300,1=1200,2=2400,3=4800,4=9600,5=19200,6=38400,7=115200,8=460800,9=921600

} IPC_COMM_PROP,*LPIPC_COMM_PROP ;

//预置位信息
typedef struct IPC_PRESET_t
{
    DWORD index ;													//索引 1~255
    DWORD enable ;													//开关
    CHAR  name[256] ;												//名称
}IPC_PRESET ,*LPIPC_PRESET ;

typedef struct tagIPC_ALARMER
{
	CHAR szIp[64];													//报警设备IP
	CHAR szDevName[64];												//报警设备名称
}IPC_ALARMER;

typedef struct _tagIPC_AlarmInfo
{
	INT     idHeight;												//报警消息id（64位整数）高32位数据，该id为报警信息数据库的行记录id，可以唯一地代表一条报警信息
	INT     idLow;                  								//报警消息id（64位整数）低位32数据，该id为报警信息数据库的行记录id，可以唯一地代表一条报警信息
	INT		iLevel;                 								//报警等级(0,1,2….) ,0等级最高,数据越大等级越低
	INT		iState; 												//1报警开始0报警结束
	CHAR	tmStamp[32];											//时间戳 格式YYYYMMDDHHMMSS;如：20120802235502
	CHAR	szDescript[64];											//报警信息描述
	CHAR	szReserved[64];		    								//保留数据,外部输入报警时候可以传递端口号，部分报警可以描述一个字符串
}IPC_ALARMINFO,*LPIPC_ALARMINFO;


typedef struct _tagIPC_DDNSPARA
{
	INT    iEnableDDNS;											    //是否使能：0－否，1－是 
	INT    iDDNSType;												//0-－Dyndns DNS，1---Private，2－PeanutHull(花生壳)，3-NO-IP  目前仅仅支持1
	INT	   iInterval;												//上报时间间隔，单位秒(10~7200)
	CHAR   sUserName[64];											//DDNS账号用户名  暂时未使用
	CHAR   sPassword[64];											//DDNS账号密码  暂时未使用
	CHAR   sDomainName[64];											//设备域名
	CHAR   sServerName[64];											//DDNS对应的服务器地址，可以是IP地址或域名
	INT    iDDNSPort;												//DDNS服务器端口
}IPC_DDNSPARA,*LPIPC_DDNSPARA;



typedef enum  _tagIPC_ImgSize
{
	IPC_SIZE_1080P,														//1920X1080
	IPC_SIZE_720P,														//1280X720
	IPC_SIZE_576P,														//720X576
	IPC_SIZE_480P,														//720X480
	IPC_SIZE_288,														//352X288, 
	IPC_SIZE_240,														//320X240
}IPC_ImgSize;

//视频图像信息
typedef struct _tagIPC_ImgInfo
{
	IPC_ImgSize	 stSize;											//分辨率
	INT			 iRate;												//帧率
}IPC_ImgInfo;


//与码流个数对应的全部图像分辨率 帧率信息
typedef struct _tagIPC_AllImgInfo
{
	INT				iCount;											//分辨率 帧率信息个数
	IPC_ImgInfo		stImgInfo[IPC_MAX_IMGINFO_COUNT][4];			//列对应码流id 1~4支持的图像分辨率和帧率,
}IPC_AllImgInfo;


//设备当前各个码流编码信息
typedef struct _tagIPC_StreamInfo
{
	INT				iWidth;											//图像宽度
	INT				iHeight;										//图像高度
	INT				iRate;											//图像帧率
	INT				iEncType;										//图像分编码类型 1:H264,2:MJPEG
	long			lAudioFormat;									//音频编码格式 音频编码格式 0:AMR; 1:G711
																	//格式固定为: amr为SamplesPerSec:8000,BitsPerSample:16,Channels:1,AvgBytesPerSec:16000;711为SamplesPerSec:8000,BitsPerSample:16,Channels:1,AvgBytesPerSec:8000
 
}IPC_StreamInfo;


//设备当前各个码流信息
typedef struct _tagIPC_DeviceImgInfo
{
	INT				iStreamCount;									//码流个数 1~4
	IPC_StreamInfo		stStreamInfo[4];								//对应码流id 0~3的码流信息
}IPC_DeviceImgInfo;

//码率信息
typedef struct _tagIPC_BitRate
{
	DWORD   sn_brc; 		 										//比特率控制，0为CBR，1为VBR，2为CBR (keep quality) ，3为VBR (keep quality)	  
	DWORD   sn_cbr; 		 										//比特率平均值，介于1000000到8000000之间	  sn_brc为0或2时有效
	DWORD   sn_vbr_min;	     										//最小比特率（bps），默认为1000000	 sn_brc为1或3时有效
	DWORD   sn_vbr_max;	     										//最大比特率 （bps），默认为8000000	 sn_brc为1或3时有效 
}IPC_BitRate; 


 
//ddns 信息
typedef struct _tagIPC_DDNSRecord
{
	CHAR szDomain[IPC_MAX_NAME_LEN];								// 域名
	CHAR szSN[IPC_MAX_NAME_LEN];									// 序列号
	CHAR szIp[IPC_MAX_NAME_LEN];									// 设备IP信息
	CHAR szName[IPC_MAX_NAME_LEN];									// 设备名称
	INT  iPort;														// 登录端口
}IPC_DDNSRecord;



typedef	struct	
{
    unsigned long			ulFlag;									//帧头标识,固定值:'SIMG'
    unsigned long			ulVersion;								//版本号
    long					lType;									//帧类型,视频: 'I','P','B',音频:'A',流头:'H'
    long					lSize;									//帧长度: 帧头长度 + 帧数据长度
    long					lHeaderSize;							//帧头长度:sizeof(IPC_STREAM_HEADER)	

    long					lVideoForamt;							//视频编码方式. 0:H264 ,1:MJPEG
    long					lWidth;									//视频宽
    long					lHeight;								//视频高	
    long					lFrameRate;								//视频帧率

    long					lAudioForamt;							//音频编码格式 0:AMR; 1:G711
    long					lSamplesPerSec;							//采样频率:8000,
    long					lBitsPerSample;							//采样精度:amr为16,711为16
    long					lChannels;								//声道:1,
    long					lAvgBytesPerSec;						//平均速率:amr为16000,711为8000

    unsigned char			Reserve[32];							//保留字段
}IPC_STREAM_HEADER,*PIPC_STREAM_HEADER;								//流头

typedef	struct
{
    unsigned long			ulFlag;									//帧头标识,固定值:'FIMG'
    long					lType;									//帧类型,视频: 'I','P','B',音频:'A',流头:'H'
    long					lSize;									//帧长度: 帧头长度 + 帧数据长度 + 帧尾长度
    long					lHeaderSize;							//帧头长度:sizeof(IPC_VIDEOFRAME_HEADER)	
    long					lTailSize;								//帧尾长度:sizeof(IPC_FRAME_TAIL)
    ULONGLONG				ullTimeStamp;							//时间戳
    long					lForamt;								//视频编码方式. 0:H264 ,1:MJPEG
    long					lWidth;									//视频宽
    long					lHeight;								//视频高	
    long					lFrameRate;								//视频帧率
    unsigned char			Reserve[12];							//保留
}IPC_VIDEOFRAME_HEADER,*PIPC_VIDEOFRAME_HEADER;						// 视频帧头

typedef	struct
{
    unsigned long			ulFlag;									//帧头标识,固定值:'FPIG'
    long					lType;									//帧类型,视频: 'I','P','B',音频:'A',流头:'H'
    long					lSize;									//帧长度: 帧头长度 + 帧数据长度 + 帧尾长度
    long					lHeaderSize;							//帧头长度:sizeof(IPC_AUDIOFRAME_HEADER)	
    long					lTailSize;								//帧尾长度:sizeof(IPC_FRAME_TAIL)
    ULONGLONG				ullTimeStamp;							//时间戳
    long					lForamt;								//音频编码格式 0:AMR; 1:G711
    long					lSamplesPerSec;							//采样频率:8000,
    long					lBitsPerSample;							//采样精度:amr为16,711为16,
    long					lChannels;								//声道:1,
    long					lAvgBytesPerSec;						//平均速率:amr为16000,711为8000
    unsigned char			Reserve[8];								//保留
}IPC_AUDIOFRAME_HEADER,*PIPC_AUDIOFRAME_HEADER;						//音频帧头

typedef struct
{
    long					lSize;									//帧长度: 帧头长度 + 帧数据长度 + 帧尾长度
    unsigned long			ulFlag;									//帧尾标识,固定值:'GIPF'
}IPC_FRAME_TAIL,*PIPC_FRAME_TAIL;


#define IPC_RECORD_CTRL_STRLEN 128
typedef struct tagIPC_RecordCtrl
{
	unsigned long       uRecordCtrl;                                            //0:开始  1：停止  2.删除录像文件 3.锁定录像文件 
	unsigned long       uRecordType;                                            // bit: 0:定时 bit: 1:手动 bit: 2:报警 bit: 3.移动桢测 bit: 4.断网录像 //停止录像触发（所有都停止才停止录像），(按位处理位为1表示启用)
    unsigned long       uStreamID;                                              //0~3
    unsigned long       uBitrateScale;                                          //降低帧率等方法实现码率下降
	char                strDeviceID[IPC_RECORD_CTRL_STRLEN];                    ////触发设备标识  //不关心填写空
	char                strFilePath[IPC_RECORD_CTRL_STRLEN];                    //文件存储路径,目前只填写文件名
}IPC_RECORD_CONTROL,*LPIPC_RECORD_CONTROL ;


typedef struct tagIPC_RecordConfig
{
	unsigned long           uRcordFileMaxSize;                                      //录像文件分割大小 单位MB range:32~512
	unsigned long           uStreamType;                                            //0:仅视频 1:仅音频 2:音视频复合流
}IPC_RECORDCONFIG,*LPIPC_RECORDCONFIG ;


//IPC_INTERNAL_COMMAND_RECORD_SEARCH REQ
typedef struct tagIPC_RecordFindCond
{
	unsigned long           uRecordType;                                            // bit: 0:定时 bit: 1:手动 bit: 2:报警 bit: 3.移动桢测 bit: 4.断网录像(按位处理位为1表示启用) //不关心填写-1
	unsigned long           uStreamID;                                              //流ID  0~3   //不关心填写-1
	unsigned long           uRecordOffset;                                          //记录偏移,用于分页显示，从第一条记录开始填写0  //获取录像记录总数时不需要填写
	unsigned long           uRecordMaxNum;                                          //分页显示数目  //获取录像记录总数时不需要填写
	char                    strDeviceID[IPC_RECORD_CTRL_STRLEN];                    //触发设备标识  //不关心填写空
	char                    strStartTime[IPC_RECORD_CTRL_STRLEN];                   //录像开始时间(格式2010-11-11T19:46:17) //不关心填写空
	char                    strStopTime[IPC_RECORD_CTRL_STRLEN];                    //录像结束时间(格式2010-11-11T19:46:17)    //不关心填写空

}IPC_RECORDFINDCOND,*LPIPC_RECORDFINDCOND ;


//IPC_INTERNAL_COMMAND_RECORD_SEARCH RESP
typedef struct tagIPC_RecordEntity
{
	unsigned long           uFileOffset;                                            //记录在文件中的偏移量,如果一条记录用一个文件存储uFileOffset=0,多条记录在一个文件中存储需要该标志		 
	unsigned long           uRecordSize;                                            //记录大小KB
	unsigned long           uRecordType;                                            // bit: 0:定时 bit: 1:手动 bit: 2:报警 bit: 3.移动桢测 bit: 4.断网录像(按位处理位为1表示启用)
	unsigned long           uStreamID;                                              //流ID 0~3
	unsigned long           uReserved1;                                             //备用1 
	unsigned long           uReserved2;                                             //备用2	
	char                    strDeviceID[IPC_RECORD_CTRL_STRLEN];                    //触发设备标识
	char                    strRecordID[IPC_RECORD_CTRL_STRLEN];                    //记录标识 
	char                    strFilePath[IPC_RECORD_CTRL_STRLEN];                    //文件存储路径,目前只填写文件名
	char                    strStartTime[IPC_RECORD_CTRL_STRLEN];                   //录像开始时间(格式2010-11-11T19:46:17)
	char                    strStopTime[IPC_RECORD_CTRL_STRLEN];                    //录像结束时间(格式2010-11-11T19:46:17)

}IPC_RECORDENTITY,*LPIPC_RECORDENTITY ;

typedef struct tagIPC_RecordDownloadInfo
{
    unsigned long       uType ;                                                         //0: 按帧ID, 1: 按字节, 2:按时间
    unsigned long long  ullIndex ;                                                      //从此位置开始下载
    unsigned long       uReserved[2] ;                                                  //保留字

} IPC_RECORDDOWNLOADINFO,*LPIPC_RECORDDOWNLOADINFO ;

typedef struct tagIPC_RdEntityGroup
{
	DWORD				dwCount ;	//lpEntityArray的大小
	LPIPC_RECORDENTITY		lpEntityArray ; // RECORDENTITY entity[dwCount];
}IPC_RDENTITYGROUP,*LPIPC_RDENTITYGROUP ;


//设备OSD信息
typedef struct tagIPC_DEVICEOSD
{
	tagIPC_DEVICEOSD()
	{
		memset(this, 0, sizeof(tagIPC_DEVICEOSD)) ;
	}

	BOOL	bShow; 													//是否显示文字信息，FALSE为不显示， TRUE为显示	
	DWORD	streamID ;												//码流ID，0为码流1，1为码流2，2为码流3，3为码流4
	DWORD   x ;														//显示区域起始X坐标 [0 100]视频图像的左上角为原点、x为在X轴方向上视频宽度的百分比
	DWORD	y ;														//显示区域起始Y坐标 [0 100]视频图像的左上角为原点、y为在Y轴方向上视频高度的百分比
	DWORD	textColor ;												//字体颜色 [0 7] 0:黑色、1:红色、2:蓝色、3:绿色、4:黄色、5:洋红色、6:蓝绿色、7:白色
	DWORD   textBold ;												//字体粗细 0：正常、 1：粗体
	DWORD	textSize ;												//字体大小 只支持16,24,32,40,48,一般取48比较合适
	CHAR	textContent[32];										//信息内容，最多32个字节
}IPC_DEVICEOSD, *LPIPC_DEVICEOSD;

//时间OSD信息
typedef struct tagIPC_DATETIMEOSD
{
	tagIPC_DATETIMEOSD()
	{
		memset(this, 0, sizeof(tagIPC_DATETIMEOSD)) ;
	}

	BOOL	bShow; 													//是否显示文字信息，FALSE为不显示， TRUE为显示	
	DWORD	streamID ;												//码流ID，0为码流1，1为码流2，2为码流3，3为码流4
	DWORD   x ;														//显示区域起始X坐标 [0 100]视频图像的左上角为原点、x为在X轴方向上视频宽度的百分比
	DWORD	y ;														//显示区域起始Y坐标 [0 100]视频图像的左上角为原点、y为在Y轴方向上视频高度的百分比
	DWORD	timeColor ;												//字体颜色 [0 7] 0:黑色、1:红色、2:蓝色、3:绿色、4:黄色、5:洋红色、6:蓝绿色、7:白色
	DWORD   timeBold ;												//字体粗细 0：正常、 1：粗体
	DWORD	timeSize ;												//字体大小 只支持16,24,32,40,48,一般取48比较合适
}IPC_DATETIMEOSD, *LPIPC_DATETIMEOSD;


//日志时间
typedef struct tagIPC_TIME
{
	DWORD dwYear;													//年
	DWORD dwMonth;													//月
	DWORD dwDay;													//日
	DWORD dwHour;													//时
	DWORD dwMinute;													//分
	DWORD dwSecond;													//秒
    DWORD dwRes;													//保留
}IPC_TIME, *LPIPC_TIME;

//日志配置
typedef struct tagIPC_LOG_CONFIG
{
	DWORD dwType;													//日志保存策略类型：0 限制最多保存条数，1 限制最多保存天数	    
	DWORD dwMaxValue;												//与保存策略对应： 当dwType为0是取值范围为 1-30000，当dwType为1是取值范围为 1-365.    
}IPC_LOG_CONFIG, *LPIPC_LOG_CONFIG;

//日志信息结构体。
typedef struct _tagIPC_LOG{
  DWORD             dwId;											//日志id
  IPC_TIME		    stLogTime;										//日志时间
  DWORD             dwType;											//日志类型,见日志类型定义
  CHAR              sUser[IPC_LOG_MAX_USER_NAME_LEN];				//用户名，GBK编码
  CHAR              sSummary[IPC_LOG_MAX_SUMMARY_LEN];				//日志概述，GBK编码
  CHAR              sDesp[IPC_LOG_MAX_DESCRIPTION_LEN];				//日志详细描述，GBK编码
}IPC_LOG,*LPIPC_LOG;


typedef struct tagIPC_FIND_DATA{
	char		sFileID[128];		//文件ID标识号
	char        sFileName[128];		//文件名
	DWORD		dwFileType ;		//文件类型
	IPC_TIME    struStartTime;		//文件的开始时间 
	IPC_TIME    struStopTime;		//文件的结束时间
	DWORD       dwFileSize;			//文件大小 单位KB
}IPC_FIND_DATA,*LPIPC_FIND_DATA;

typedef struct tagIPC_RECORD_CTRL{
	DWORD		dwFileType ;		//文件类型
	DWORD		dwChannel ;			//通道号（码流id）
}IPC_RECORD_CTRL,*LPIPC_RECORD_CTRL;

typedef struct tagIPC_RECORD_CONFIG{
	DWORD       dwFileMaxSize;		//文件大小 单位KB
	DWORD		dwStreamType ;		//码流类型 0:仅视频 1:仅音频 2:音视频复合流
}IPC_RECORD_CONFIG,*LPIPC_RECORD_CONFIG;

    //
    typedef struct _tagIPC_PtzHomeCfg{
        INT             iEnable;                          //使能标志
		INT				iType;							  //0-预置点，1-巡航，2-花样
        INT             iPreset;                          //预制点号索引号默认从1开始 
        INT             iTime;                            //单位秒 1-720 
    }IPC_PTZHOME_CFG,*LPIPC_PTZHOME_CFG;



	typedef struct _tagIPC_Ptz3DCtrl{
		INT             iX;                                             //x = (x0 / W) * 8192
		INT             iY;                                             //y = (y0 / H) * 8192
		INT             iW;                                             //width = (w / W) * 8192    W为视频画面的宽度
		INT             iH;                                             //hight = (h / H) * 8192    H为视频画面的高度  单击的时候 width和height为0
		//正选Width、 height大于0，变倍将会变大，反选的时候Width、 height都小于0，变倍将会变小
	}IPC_PTZ3DCTRL,*LPIPC_PTZ3DCTRL;

	typedef struct _tagIPC_Ptz3DCtrl2{
		INT             PtzId;
		INT             iX;                                             //x = (x0 / W) * 8192
		INT             iY;                                             //y = (y0 / H) * 8192
		INT             iW;                                             //width = (w / W) * 8192    W为视频画面的宽度
		INT             iH;                                             //hight = (h / H) * 8192    H为视频画面的高度  单击的时候 width和height为0
		//正选Width、 height大于0，变倍将会变大，反选的时候Width、 height都小于0，变倍将会变小
		unsigned char   Parameter[4]; 
	}IPC_PTZ3DCTRL2,*LPIPC_PTZ3DCTRL2;

	typedef struct tagIPC_UserInfo
	{
		CHAR     sUserName[32];
		CHAR     sUserPass[32];
		INT      nUserFlag;				//用户flag，1—管理员, 2—操作员, 3--Viewer
		INT      nUserLevel;			//保留
	}IPC_USER_INFO;

	typedef struct _tagIPC_USER
	{ 
		DWORD                     dwSize;
		INT						  nEncType ; //加密类型 1明文，2md5，3consult，4des
		IPC_USER_INFO             stUser[IPC_MAX_USERNUM];
	}IPC_USER,*LPIPC_USER;


	typedef struct _tagIPC_STREAM_STATE
	{
		INT nStreamId;				//stream id
		INT nRecordStatic;			//0-正在录像, 1-没有录像
		INT nVideoSignalStatic;		//0-正常l, 1-丢失
		INT nReserved[2];
		INT nBitRate;				//实际码率
		INT nLinkNum;				//客户端连接数
		CHAR nClientIP[16][32];	    //客户端IP
	}IPC_STREAM_STATE;

	typedef struct  tagIPC_WORKSTATE
	{  
		INT				  nDeviceStatic;			//0-normal, 1-cpu too high, >85%, 2-hardware error
		IPC_STREAM_STATE  stStreamState[4];
		INT nVolume;								//磁盘容量
		INT nFreeSpaces;							//剩余空间
		INT niDiskStatic;							//0-活动, 1-睡眠, 2-异常
		INT nAlarmInStatic[16];						//0-没有报警, 1-有报警
		INT nAlarmOutStatic[16];					//0-没有报警输出, 1-报警输出
		INT nLocalDisplay;							//0-正常显示, 1-没有显示
	}IPC_WORKSTATE,*LPIPC_WORKSTATE;
    
	//自动聚焦配置参数 
	typedef struct 
	{
		DWORD   dwAFMode;		    //聚焦模式
		DWORD   dwAFDisLimit;		//聚焦距离限制
		DWORD   dwPtzFactoryRange;  //最大光学倍数
		DWORD   dwPtzCustomRange;   //保留
		DWORD   dwDptzFactoryRange; //最大数字倍数
		DWORD   dwDptzCustomRange;  //用户设置的最大倍数
	}IPC_AUTOFOCUS_CFG;


	//护照版本信息 
	typedef struct 
	{
		BYTE  byManuInfo;			//表示厂家的编码
		BYTE  byModInfo;			//表示产品的编码
		BYTE  byMsbVer;				//版本号高8位
		BYTE  byLsbVer;				//版本号低8位
		BYTE  byReserved[4];
	}IPC_SHIELD_VERSION_CFG;

	//设备端口信息
	typedef struct 
	{
		DWORD  dwHttpPort;			 
		DWORD  dwRtspPort;		 
		DWORD  dwSdkPort;		
		DWORD  dwUpdatePort;		
		DWORD  dwOnvifPort;		
		DWORD  dwSnmpPort;	
		DWORD  byReserved[4];
	}IPC_NETPORT_CFG;


	//仅支持3.0设备。
	typedef struct tagIPC_HANDLEEXCEPTION_EX
	{
		DWORD	dwHandleType;		//联动策略，按位表示，第0位-告警输出，第1位-上传中心，第2位-声音输出，第3位-邮件，第4位-FTP上传，第5位-录像，第6位-PTZ，第7位-抓图
		BYTE    byAlarmOut[8];		//报警触发的输出通道，0-不触发，1-触发输出，按位表示输出通道，例如byRelAlarmOut[0]==1表示触发输出通道1，byRelAlarmOut[1]==1表示触发输出通道2，依此类推 
		BYTE	byPtzCmd;			//联动云台命令，0-无，1-预置点，2-预置点巡航，3-花样扫描
		DWORD   dwSeqNum;			//序号：预置点序号/巡航轨迹序号/花样扫描序号
		DWORD   dwPTZDelayTime;	//云台动作持续时间，单位为S
		DWORD   dwDelayTime;		//白光输出持续时间，单位为S
		BYTE    byReserved[7];	
	}IPC_HANDLEEXCEPTION_EX;

	typedef struct tagIPCSCHEDTIME
	{
		DWORD   dwStartHour;                                                        //开始时间：时
		DWORD   dwStartMin;                                                         //开始时间：分
		DWORD   dwStopHour;                                                         //结束时间：时 
		DWORD   dwStopMin;                                                          //结束时间：分
	}IPC_SCHEDTIME, *LPIPC_SCHEDTIME;
	 
	//报警输入参数扩展 仅支持3.0设备。
	typedef struct tagIPC_ALARMINCFG_EX
	{
		DWORD                   dwSize;											//结构体大小
		BYTE                    sAlarmInName[IPC_MAX_NAME_LEN];					//名称 
		BYTE                    byAlarmType;										//报警器类型：0-常开，1-常闭 
		BYTE                    byAlarmInHandle;									//是否处理：0-不处理，1-处理
		BYTE                    byRes1[2];										//保留，置为0 
		DWORD					dwCheckTime;										//单位：毫秒，检测告警状态的时间间隔
		IPC_HANDLEEXCEPTION_EX	struAlarmHandleType;								//处理方式 
		IPC_SCHEDTIME			struAlarmTime[IPC_MAX_DAYS][IPC_MAX_TIME_SEC]; //布防时间参数
	}IPC_ALARMINCFG_EX,*LPIPC_ALARMINCFG_EX;


	//报警输出参数结构体 仅支持3.0设备。
	typedef struct tagIPC_ALARMOUTCFG
	{
		DWORD                   dwSize;													 //结构体大小 
		BYTE					byEnable;												 //使能配置
		BYTE                    sAlarmOutName[IPC_MAX_NAME_LEN];						 //名称 
		BYTE					byNormaState;											 //常开常闭 
		DWORD                   dwAlarmOutDelay;										 //输出信号状态维持时间(秒),0xffffff-为无限（需手动关闭） 
		IPC_SCHEDTIME			struAlarmOutTime[IPC_MAX_DAYS][IPC_MAX_TIME_SEC];		 //报警输出激活时间段
		BYTE                    byRes[14];												 //保留，置为0 
	}IPC_ALARMOUTCFG,*LPIPC_ALARMOUTCFG;

	//报警输出状态结构体 仅支持3.0设备。
	typedef struct tagIPC_ALARMOUTSTATUS
	{
		tagIPC_ALARMOUTSTATUS()
		{
			memset(this, 0, sizeof(tagIPC_ALARMOUTSTATUS));
		}
		BYTE      Output[8];																//报警输出口的状态：0-无效，1-有效 
	}IPC_ALARMOUTSTATUS,*LPIPC_ALARMOUTSTATUS;

	//PIR报警参数结构体,仅支持3.0设备。
	typedef struct tagIPC_PIR_ALARMCFG
	{
		BYTE                     byAlarmName[32];										//报警名称 
		BYTE                     byAlarmHandle;											//是否处理：0- 不处理，1- 处理 
		BYTE					 bySensitive;											//0-100
		BYTE                     byRes1[3];												//保留 
		IPC_HANDLEEXCEPTION_EX	 struAlarmHandleType;									//处理方式
		IPC_SCHEDTIME			 struAlarmTime[IPC_MAX_DAYS][IPC_MAX_TIME_SEC];		    //布防时间参数
		BYTE                     byRes[63];												//保留 
	}IPC_PIR_ALARMCFG,*LPIPC_PIR_ALARMCFG;

	//辅助报警参数联合体,仅支持3.0设备。
	typedef struct tagIPC_AUX_ALARMCFG_UNION
	{ 
		IPC_PIR_ALARMCFG			  struPIRAlarm;		//PIR报警参数
	}IPC_AUX_ALARMCFG_UNION,*LPIPC_AUX_ALARMCFG_UNION;

	//单个辅助报警参数结构体,仅支持3.0设备。

	//辅助报警类型 
	#define   IPC_AUXALARM_UNKNOW     0		//未知 
	#define   IPC_AUXALARM_PIR        1	//PIR报警 

	typedef struct  tagIPC_SINGLE_AUX_ALARMCFG
	{
		BYTE				    byAlarmType;										//报警器类型，定义详见下表 GIPC_AUX_ALARM_TYPE
		BYTE					byRes1[3];											//保留 
		IPC_AUX_ALARMCFG_UNION	uAlarm;												//报警参数
		BYTE                    byRes[16];											//保留 
	}IPC_SINGLE_AUX_ALARMCFG,*LPIPC_SINGLE_AUX_ALARMCFG;

	#define  MAX_AUX_ALARM_NUM  8
	//辅助（PIR）报警参数结构体,仅支持3.0设备。
	typedef struct tagIPC_AUX_ALARMCFG
	{
		DWORD                    dwCount;											//结构体个数 
		IPC_SINGLE_AUX_ALARMCFG  struAlarm[MAX_AUX_ALARM_NUM];					//辅助报警参数 
		BYTE                     byRes[64];										//保留 
	}IPC_AUX_ALARMCFG,*LPIPC_AUX_ALARMCFG;

	typedef struct  tagIPC_POINT_FRAME                              //x、y、width和height是归一化的值，计算方法为: x = (x0 / W) * 8192 ;width = (w / W) * 8192    W为视频画面的宽度 ;y = (y0 / H) * 8192 ;hight = (h / H) * 8192    W为视频画面的宽度 ;单击的时候 width和height为0 ;正选Width、 height大于0，变倍将会变大，反选的时候Width、 height都小于0，变倍将会变小。xBottom=xTop+width,yBottom=yTop+hight
	{  
        INT    xTop ;                                               //方框起始点的x坐标
        INT    yTop ;                                               //方框起始点的y坐标
        INT    xBottom ;                                            //方框结束点的x坐标
        INT    yBottom ;                                            //方框结束点的y坐标
        INT    iType ;                                              //画框方式:0-框选 1-滚轮缩小 2-滚轮放大 
	}IPC_POINT_FRAME,*LPIPC_POINT_FRAME;

#pragma pack(pop)

typedef struct tagIPC_OSDParamA
{
	bool	text ;													//是否显示文字信息，true为显示, false为不显示
	long	text_x;													//文字显示区域的x坐标 按视频分辨率计算
	long	text_y;													//文字显示区域的y坐标 按视频分辨率计算
	long	text_lWidth;											//文字显示区域的宽 按视频分辨率计算
	long	text_lHeight;											//文字显示区域的高 按视频分辨率计算   
	LOGFONTA text_font ;											//字体，标准的LOGFONT结构 ,SDK自动适配用户应用程序的UNICODE和MultiBytes数据
    COLORREF text_crColor ;             							//字体颜色
	wchar_t text_context[256] ;         							//文本内容，小于256个字符
	bool	picture;                    							//是否显示图片，true为显示，false为不显示
	long	pic_x;                      							//图片显示区域的x坐标  按视频分辨率计算
	long	pic_y;													//图片显示区域的y坐标  按视频分辨率计算
	long	pic_lWidth;												//图片显示区域的宽     按视频分辨率计算
	long	pic_lHeight;											//图片显示区域的高     按视频分辨率计算
	COLORREF pic_crMask ;               							//图片底色
	long	pic_data_len ;              							//图片数据长度
    BYTE*	pic_data ;                  							//图片数据
}IPC_OSDPARAMA,*LPIPC_OSDPARAMA;

typedef struct tagIPC_OSDParamW
{
    bool	text ;                      							//是否显示文字信息，true为显示, false为不显示
    long	text_x;                     							//文字显示区域的x坐标  按视频分辨率计算
    long	text_y;													//文字显示区域的y坐标  按视频分辨率计算
    long	text_lWidth;											//文字显示区域的宽     按视频分辨率计算
    long	text_lHeight;											//文字显示区域的高     按视频分辨率计算
    LOGFONTW text_font ;											//字体，标准的LOGFONT结构 ,SDK自动适配用户应用程序的UNICODE和MultiBytes数据
    COLORREF text_crColor ;             							//字体颜色
    wchar_t text_context[256] ;										//文本内容，小于256个字符
    bool	picture;                    							//是否显示图片，true为显示，false为不显示
    long	pic_x;                      							//图片显示区域的x坐标   按视频分辨率计算
    long	pic_y;													//图片显示区域的y坐标   按视频分辨率计算
    long	pic_lWidth;												//图片显示区域的宽      按视频分辨率计算
    long	pic_lHeight;											//图片显示区域的高      按视频分辨率计算
    COLORREF pic_crMask ;               							//图片底色
    long	pic_data_len ;              							//图片数据长度
    BYTE*	pic_data ;                  							//图片数据
}IPC_OSDPARAMW,*LPIPC_OSDPARAMW;

#ifdef UNICODE
#define tagIPC_OSDParam tagIPC_OSDParamW
#define IPC_OSDPARAM IPC_OSDPARAMW
#define LPIPC_OSDPARAM LPIPC_OSDPARAMW
#else 
#define tagIPC_OSDParam tagIPC_OSDParamA
#define IPC_OSDPARAM IPC_OSDPARAMA
#define LPIPC_OSDPARAM LPIPC_OSDPARAMA
#endif




#include "IPCSdkDefinesBackup.h"
#endif //_IPC_SDK_DEFINES_H_