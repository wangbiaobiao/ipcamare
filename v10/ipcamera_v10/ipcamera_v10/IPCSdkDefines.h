#ifndef _IPC_SDK_DEFINES_H_
#define _IPC_SDK_DEFINES_H_

#define ipcSUCCESS  0
#define ipcFAULT    -1

#define IPC_SDK_FAULT_BASE (0x80004000)

#define IPC_E_MODULE_NOTFOUND                   (IPC_SDK_FAULT_BASE+1)        //������δ����
#define IPC_E_RESOURCE_NOTALLOCATED             (IPC_SDK_FAULT_BASE+2)        //��Դ����ʧ��
#define IPC_E_INVALID_LOGIN_INFO                (IPC_SDK_FAULT_BASE+3)        //��½��Ϣ����
#define IPC_E_INVALID_PARAMS                    (IPC_SDK_FAULT_BASE+4)        //��Ч����
#define IPC_E_CANT_DISPLAY                      (IPC_SDK_FAULT_BASE+6)        //��ʾ����
#define IPC_E_SYSTEMBUSY                        (IPC_SDK_FAULT_BASE+7)        //ϵͳæִ��ʧ��
#define IPC_E_UNSUPPORTED                       (IPC_SDK_FAULT_BASE+8)        //�����޷�֧��
#define IPC_E_IPC_SERVICE_UNACCEPTABLE          (IPC_SDK_FAULT_BASE+9)        //�豸Ӧ��ʧ��
#define IPC_E_CANT_SEND_REQUEST                 (IPC_SDK_FAULT_BASE+10)       //�豸ͨ��ʧ��
#define IPC_E_TIMEOUT                           (IPC_SDK_FAULT_BASE+11)       //��ʱʧ��
#define IPC_E_BUFFER_OVERFLOW                   (IPC_SDK_FAULT_BASE+12)       //�����������
#define IPC_E_CANT_CONNECT                      (IPC_SDK_FAULT_BASE+13)       //��������ʧ��
#define IPC_E_INVALID_FILE_OPERATION            (IPC_SDK_FAULT_BASE+14)       //���̲���ʧ��
#define IPC_E_INVALID_NET_INIT                  (IPC_SDK_FAULT_BASE+15)       //���紴��ʧ��

#define IPC_E_AUDIO_ERROR                       (IPC_SDK_FAULT_BASE+5)        //��Ƶ����
#define IPC_E_CANT_OPEN_AUDIO_STORAGE           (IPC_SDK_FAULT_BASE+16)       //������Ƶʧ��
#define IPC_E_CANT_START_AUDIO_STORAGE          (IPC_SDK_FAULT_BASE+17)       //������Ƶʧ��
#define IPC_E_CANT_CREATE_GRAPH                 (IPC_SDK_FAULT_BASE+18)       //������Ƶʧ��
#define IPC_E_NETSYNTH_NOTFOUND                 (IPC_SDK_FAULT_BASE+19)       //������Ƶʧ��
#define IPC_E_CANT_QUARY_IID_MEDIACONTROL       (IPC_SDK_FAULT_BASE+20)       //������Ƶʧ��
#define IPC_E_CANT_QUARY_IID_BASICAUDIO         (IPC_SDK_FAULT_BASE+21)       //������Ƶʧ��
#define IPC_E_CANT_ADD_AUDIOSOURCE              (IPC_SDK_FAULT_BASE+22)       //������Ƶʧ��
#define IPC_E_CANT_QUARY_IID_NETSYNTH           (IPC_SDK_FAULT_BASE+23)       //������Ƶʧ��
#define IPC_E_INVALID_MEDIA_FMT                 (IPC_SDK_FAULT_BASE+24)       //������Ƶʧ��
#define IPC_E_CODEC_NOTFOUND                    (IPC_SDK_FAULT_BASE+25)       //������Ƶʧ��
#define IPC_E_RENDERER_NOTFOUND                 (IPC_SDK_FAULT_BASE+26)       //������Ƶʧ��
#define IPC_E_REJECT_SOURCEPIN_CONNECTION       (IPC_SDK_FAULT_BASE+27)       //������Ƶʧ��
#define IPC_E_REJECT_RENDERPIN_CONNECTION       (IPC_SDK_FAULT_BASE+28)       //������Ƶʧ��
#define IPC_E_FILTER_NOTFOUND                   (IPC_SDK_FAULT_BASE+29)       //������Ƶʧ��    
#define IPC_E_CANT_QUARY_IID                    (IPC_SDK_FAULT_BASE+30)       //������Ƶʧ��    
#define IPC_E_REJECT_PINCONNECTION              (IPC_SDK_FAULT_BASE+31)       //������Ƶʧ��    
#define IPC_E_UNKNOWN_IPCVERSION                (IPC_SDK_FAULT_BASE+32)       //�޷�ʶ���豸�汾
#define ipcHandle LPVOID
#define playHandle LPVOID
#define displayHandle HWND

//��Ƶ����
#define IPC_VIDEO_BASE								0x00002000
#define IPC_VIDEO_IMGPRO_GROUP						(IPC_VIDEO_BASE+1)		//ͼ������			�ο��ṹ��IMGPRO
#define IPC_VIDEO_EXPOSURE_MODE						(IPC_VIDEO_BASE+2)		//����˸ģʽ		0 :50Hz ; 1:60Hz; 2:�Զ�
#define IPC_VIDEO_AE_TARGET_RATION					(IPC_VIDEO_BASE+3)		//�ع�Ŀ��ϵ��		25~400
#define IPC_VIDEO_MAX_GAIN							(IPC_VIDEO_BASE+4)		//SenSor�������	30db, 36db, 42db, 48db, 54db, 60db
#define IPC_VIDEO_WBC								(IPC_VIDEO_BASE+5)		//��ƽ������:		 0: �Զ�;1:incandescent;2:d4000;3: d5000;4: sunny;5: cloudy;6: flash;7: fluorescent;8: fluorescent high;9: under water;10:custom;11: �ر�
#define IPC_VIDEO_DN_MODE							(IPC_VIDEO_BASE+6)		//ģʽ����			(0 ����,1 ҹ��,2 �Զ�,3 ����)  
#define	IPC_VIDEO_BACKLIGHT_COMP					(IPC_VIDEO_BASE+7)		//���ⲹ��			 0 �ر�  1 ����
#define IPC_VIDEO_LOCAL_EXPOSURE					(IPC_VIDEO_BASE+8)		//�ֲ��ع�ģʽ		 0 : �ر�; 1: ��; 2: ��ͣ; 3: 2x; 4:3x; 5:4x
#define IPC_VIDEO_MCTF_STRENGTH						(IPC_VIDEO_BASE+9)		//3D����			 0~255
#define IPC_VIDEO_DCIRIS_GROUP						(IPC_VIDEO_BASE+10)		//DC IRISģʽ        �ο��ṹ�� IMGIRIS
#define IPC_VIDEO_SHUTTER_GROUP						(IPC_VIDEO_BASE+11)		//���ӿ���ʱ�䷶��   �ο��ṹ�� IMGSHUTTER
#define IPC_VIDEO_MJPEG_QUALITY						(IPC_VIDEO_BASE+12)		//ͼ������			 0~100
#define IPC_VIDEO_SLOW_SHUTTER						(IPC_VIDEO_BASE+13)     //�Զ��ع�������SlowShutter  0:�ر�;1:����
#define IPC_VIDEO_AE_PREFERENCE						(IPC_VIDEO_BASE+14)		//�Զ��ع��ƫ��	  0 : ����ģʽ;1 :����ģʽ;2 : ��Ȧ����
#define IPC_VIDEO_METERING_MODE						(IPC_VIDEO_BASE+15)		//�Զ��ع������в��ģʽ   0:�۹�;1:����;2:ƽ��
#define IPC_ENCODE_ENC_MODE							(IPC_VIDEO_BASE+17)		//����ģʽ			  0 : ��ͨ��1 : �������� 2 : ����ʱ
#define IPC_ENCODE_SN_TIME_ENABLE0					(IPC_VIDEO_BASE+18)		//����1����ʱ��ʹ�ܣ� 0 ������ʱ�� 1 ����ʱ��
#define IPC_ENCODE_SN_TIME_ENABLE1					(IPC_VIDEO_BASE+19)		//����2����ʱ��ʹ�ܣ� 0 ������ʱ�� 1 ����ʱ��
#define IPC_ENCODE_SN_TIME_ENABLE2					(IPC_VIDEO_BASE+20)		//����3����ʱ��ʹ�ܣ� 0 ������ʱ�� 1 ����ʱ��
#define IPC_ENCODE_SN_TIME_ENABLE3					(IPC_VIDEO_BASE+21)		//����4����ʱ��ʹ�ܣ� 0 ������ʱ�� 1 ����ʱ��
#define IPC_ENCODE_SN_TEXT_GROUP					(IPC_VIDEO_BASE+22)		//���ֵ�����Ϣ		�ο��ṹ��SNTEXT
#define IPC_ENCODE_ENC_ENC_GROUP					(IPC_VIDEO_BASE+24)		//Ԥ��ҳ��ȡ��ǰ������Ϣ	�ο��ṹ��ENCENC  ֻ��
#define IPC_VIDEO_IRCUT_GROUP						(IPC_VIDEO_BASE+25)		//IRCUT��ҹģʽ		�ο��ṹ��IMGIRCUT
#define IPC_VIDEO_IRCUT_NIGHT2DAY_MIN   			(IPC_VIDEO_BASE+26)		//ҹ��->����ģʽ��С��ֵ   ֻ�� 
#define IPC_VIDEO_IRCUT_NIGHT2DAY_MAX   			(IPC_VIDEO_BASE+27)		//ҹ��->����ģʽ���ֵ   ֻ��
#define IPC_VIDEO_IRCUT_DAY2NIGHT_MIN   			(IPC_VIDEO_BASE+28)		//����->ҹ��ģʽ��С��ֵ   ֻ��
#define IPC_VIDEO_IRCUT_DAY2NIGHT_MAX   			(IPC_VIDEO_BASE+29)		//����->ҹ��ģʽ���ֵ   ֻ��
#define IPC_ENCODE_STR_I_INTERVAL       			(IPC_VIDEO_BASE+30)     //����I֡���  1~8 ��λs���ݽ������Ϊ1~100֡��
#define IPC_VIDEO_WBC_CUSTOM_R_GAIN     			(IPC_VIDEO_BASE+32)     //�Զ���R 0~1023
#define IPC_VIDEO_WBC_CUSTOM_B_GAIN     			(IPC_VIDEO_BASE+33)     //�Զ���B 0~1023
#define IPC_VIDEO_AF_ENABLE             			(IPC_VIDEO_BASE+34)     //�۽�ģʽ 0���ֶ�ģʽ 1��ȫ���Զ�ģʽ 2���Զ��۽�����ģʽ
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM0	(IPC_VIDEO_BASE+35) 	//��������1 MJPEGѹ����  1(high),2(middle),3(low)
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM1	(IPC_VIDEO_BASE+36) 	//��������2 MJPEGѹ����  1(high),2(middle),3(low)
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM2	(IPC_VIDEO_BASE+37) 	//��������3 MJPEGѹ����  1(high),2(middle),3(low)
#define IPC_ENCODE_PROPERTY_SN_MJPEG_LEVEL_STREAM3	(IPC_VIDEO_BASE+38) 	//��������3 MJPEGѹ����  1(high),2(middle),3(low)


//��̨����
#define IPC_PTZ_BASE								0x00004000
#define IPC_CMD_DPTZ_ZOOM							(IPC_PTZ_BASE + 1)		//����������̨�ӽ�		  ���ŷ�Χ: 0~11
#define IPC_CMD_DPTZ_UP								(IPC_PTZ_BASE + 2)		//������̨����			  �������� 0~1000
#define IPC_CMD_DPTZ_DOWN							(IPC_PTZ_BASE + 3)		//������̨����			  �������� 0~1000
#define IPC_CMD_DPTZ_LEFT							(IPC_PTZ_BASE + 4)		//������̨����			  �������� 0~1000
#define IPC_CMD_DPTZ_RIGHT							(IPC_PTZ_BASE + 5)		//������̨����			  �������� 0~1000
#define IPC_CMD_DPTZ_SET_PRESET						(IPC_PTZ_BASE + 6)		//����������̨Ԥ��λ      Ԥ��λ��Χ: 1~9
#define IPC_CMD_DPTZ_CLEAR_PRESET					(IPC_PTZ_BASE + 7)		//����ָ��������̨Ԥ��λ  Ԥ��λ��Χ: 1~9
#define IPC_CMD_DPTZ_GOTO_PRESET	    			(IPC_PTZ_BASE + 8)		//ת��������̨Ԥ��λ      Ԥ��λ��Χ: 1~9
#define IPC_CMD_DPTZ_CLEAR_ALL_PRESET				(IPC_PTZ_BASE + 9)		//��������������̨Ԥ��λ
#define IPC_CMD_DPTZ_GOTO_HOME						(IPC_PTZ_BASE + 10)		//�Ƶ�������̨��ʼλ
#define IPC_CMD_DPTZ_FOCUS_FAR          			(IPC_PTZ_BASE + 11) 	//���־۽�Զ			  ���ر�־ 0:on, 1:off
#define IPC_CMD_DPTZ_FOCUS_NEAR         			(IPC_PTZ_BASE + 12) 	//���־۽���              ���ر�־ 0:on, 1:off

#define IPC_CMD_PTZ_FOCUS_NEAR						(IPC_PTZ_BASE + 21)		//��С��е��̨����
#define IPC_CMD_PTZ_FOCUS_FAR						(IPC_PTZ_BASE + 22)		//�Ŵ��е��̨����
#define IPC_CMD_PTZ_ZOOM_WIDE						(IPC_PTZ_BASE + 23)		//�Ŵ��е��̨�ӽ�   
#define IPC_CMD_PTZ_ZOOM_TELE						(IPC_PTZ_BASE + 24)		//��С��е��̨�ӽ�
#define IPC_CMD_PTZ_UP								(IPC_PTZ_BASE + 25)		//��е��̨����
#define IPC_CMD_PTZ_DOWN							(IPC_PTZ_BASE + 26)		//��е��̨����
#define IPC_CMD_PTZ_LEFT							(IPC_PTZ_BASE + 27)		//��е��̨��ת
#define IPC_CMD_PTZ_RIGHT							(IPC_PTZ_BASE + 28)		//��е��̨��ת
#define IPC_CMD_PTZ_GOTO_HOME						(IPC_PTZ_BASE + 29)		//�Ƶ���е��̨��ʼλ��
#define IPC_CMD_PTZ_SET_PAN_SPEED					(IPC_PTZ_BASE + 30) 	//��е��̨ˮƽ�ٶ�		0~100
#define IPC_CMD_PTZ_SET_TILT_SPEED					(IPC_PTZ_BASE + 31) 	//��е��̨��ֱ�ٶ�		0~100

#define IPC_CMD_PTZ_SET_LEFTBORDER					(IPC_PTZ_BASE + 44) 	//������߽�
#define IPC_CMD_PTZ_SET_RIGHTBORDER					(IPC_PTZ_BASE + 45) 	//�����ұ߽�
#define IPC_CMD_PTZ_AUTO_SCAN						(IPC_PTZ_BASE + 46) 	//�Զ�����ɨ��
#define IPC_CMD_PTZ_AUXIOPEN						(IPC_PTZ_BASE + 47) 	//������  ֧�ָ����� 1~8
#define IPC_CMD_PTZ_AUXICLOSE						(IPC_PTZ_BASE + 48) 	//������
#define IPC_CMD_PTZ_AUTOPAN							(IPC_PTZ_BASE + 49) 	//�Զ�ˮƽ��ת

#define IPC_CMD_PTZ_GOTO_REL_POSITION				(IPC_PTZ_BASE + 50) 	//����Ե�ǰ����λ���˶�ָ����ƫ����
#define IPC_CMD_PTZ_GOTO_ABS_POSITION				(IPC_PTZ_BASE + 51) 	//�˶���ָ���ľ�������λ��
#define IPC_CMD_PTZ_GET_ABS_POSITION				(IPC_PTZ_BASE + 52) 	//��ȡ��̨��ǰ�ľ�������
#define IPC_CMD_PTZ_IRIS_OPEN						(IPC_PTZ_BASE + 53)		//��Ȧ
#define IPC_CMD_PTZ_IRIS_CLOSE						(IPC_PTZ_BASE + 54)		//��Ȧ
#define IPC_CMD_PTZ_3DPOSBOX                        (IPC_PTZ_BASE + 55)		//��������

#define IPC_CMD_PTZ_IRIS_AUTO						(IPC_PTZ_BASE + 62)		//�Զ���Ȧ
#define IPC_CMD_PTZ_FOCUS_AUTO						(IPC_PTZ_BASE + 63)		//�Զ��۽�
//�¼�
#define IPC_EVENT_BASE								0x00005000

//�¼�����
#define IPC_EVENT_INPUTPORT							(IPC_EVENT_BASE+15)		//�ⲿ���뱨��
#define IPC_EVENT_CAMERATAMPERING					(IPC_EVENT_BASE+16)		//��Ƶ�쳣����
#define IPC_EVENT_MONTIONDETECTION					(IPC_EVENT_BASE+17)     //�ƶ���ⱨ��
#define IPC_EVENT_REBOOT							(IPC_EVENT_BASE+31)		//�豸��������
#define IPC_EVENT_OUTPUT							(IPC_EVENT_BASE+48)		//�������

//¼��洢��ʽ
#define IPC_RECORD_FILELOCATION_FTP					(IPC_EVENT_BASE+23)		//¼��洢��ʽΪFTP   ���� RECORDACTION �е� locationID
#define IPC_RECORD_FILELOCATION_SDCARD				(IPC_EVENT_BASE+24)		//¼��洢��ʽΪSD��  ���� RECORDACTION �е� locationID
#define IPC_RECORD_FILELOCATION_EMAIL				(IPC_EVENT_BASE+25)		//¼��洢��ʽΪ�ʼ�  ���� RECORDACTION �е� locationID

//ϵͳ����
#define IPC_SYSTEM_BASE								0x00007000	
#define IPC_SYSTEM_GET_DEVICE_NAME					(IPC_SYSTEM_BASE+5)		//�豸����		 
#define IPC_SYSTEM_GET_DEVICE_MANUFACTURER			(IPC_SYSTEM_BASE+6)		//�豸����       ֻ������
#define IPC_SYSTEM_GET_FW_VERSION					(IPC_SYSTEM_BASE+7)		//�豸����汾   ֻ������ 
#define IPC_SYSTEM_GET_HW_VERSION					(IPC_SYSTEM_BASE+8)		//�豸Ӳ���汾   ֻ������
#define IPC_SYSTEM_SETGET_DATEINFO					(IPC_SYSTEM_BASE+9)		//�豸ʱ������   �ο��ṹ�� SYSDATEINFO
#define IPC_SYSTEM_AUDIO_SETTING            		(IPC_SYSTEM_BASE+15)	//������������   �ο��ṹ�� AUDIOCONF
#define IPC_SYSTEM_GETSET_ALARMCENTER       		(IPC_SYSTEM_BASE+18)    //������������   �ο��ṹ�� IPC_ALARMCENTER_UP_CFG
#define IPC_SYSTEM_GET_DEVICE_SN                    (IPC_SYSTEM_BASE+19)    //��ȡ�豸����Ψһ����
#define IPC_SYSTEM_SETGET_DATEINFOEX				(IPC_SYSTEM_BASE+30)  	//�����豸ʱ����չ�ӿ� �ο��ṹ�� SYSDATEINFOEX
#define IPC_SYSTEM_GET_SUPPORT_GB					(IPC_SYSTEM_BASE+31)	//��ȡ�豸֧�ֹ����������
#define IPC_SYSTEM_GET_SUPPORT_RTSP					(IPC_SYSTEM_BASE+32)	//��ȡ�豸֧��RTSP�������
//EXT
#define IPC_SYSTEM_GETUSRINFO                       (IPC_SYSTEM_BASE+36)	//��ȡ�˺���Ϣ 
#define IPC_SYSTEM_SETUSRINFO                       (IPC_SYSTEM_BASE+37)	//�����˺���Ϣ 
#define IPC_SYSTEM_ALARMINCFG                       (IPC_SYSTEM_BASE+38)	//������������ 
#define IPC_SYSTEM_ALARMOUTCFG                      (IPC_SYSTEM_BASE+39)	//����������� 
#define IPC_SYSTEM_AUX_ALARMCFG						(IPC_SYSTEM_BASE+40)	//������������ 
#define IPC_SYSTEM_DAYNIGHT                         (IPC_SYSTEM_BASE+42)	//��ҹģʽ��չ  ��3.0֧�� 
#define IPC_SYSTEM_SHIELDVERSION                    (IPC_SYSTEM_BASE+43)	//��̨���հ汾  ��3.0֧�� 
#define IPC_SYSTEM_AUTOFOCUSEX                      (IPC_SYSTEM_BASE+44)	//�Զ��۽�������չ  ��3.0֧��
#define IPC_SYSTEM_NETPORT                          (IPC_SYSTEM_BASE+45)	//����˿�����  ��3.0֧��

#define  IPC_MAX_TIME_SEC							16						//���֧�ֵ�ʱ��θ���
#define  IPC_MAX_CENTER								 3						//���֧��������������
#define  IPC_MAX_IPADDR_LEN							32						//IP��ַ��󳤶�
#define  IPC_MAX_NAME_LEN							64						//���Ƶ���󳤶�
#define  IPC_MAX_PRESET_CRUISE_POINTS				32						//���֧�ֵ�Ѳ�������
#define  IPC_MAX_CRUISE_PATH						32						//���֧�ֵ�Ѳ��·������
#define	 IPC_MAX_IMGINFO_COUNT						32						//���֧�ֵķֱ��� ֡����Ϣ����
#define  IPC_LOG_MAX_USER_NAME_LEN					20						//��־��ѯ����û����Ƴ���
#define  IPC_LOG_MAX_SUMMARY_LEN					128						//��־��ѯ����������			
#define  IPC_LOG_MAX_DESCRIPTION_LEN				512						//��־��ѯ�����ϸ��������
#define  IPC_MAX_USERNUM							30                      //�����½���������
#define  IPC_MAX_SHELTER_COUNT                      4                       //��˽�ڵ�����������
#define  IPC_MAX_DAYS                               7                       //ÿ�ܵ�����
#define  IPC_MAX_MOTION_WND_COUNT                   4                       //�ƶ���ⴰ��������

#define  IPC_SET_CRUISE_ALLDATA              	    1			            //�������õ�Ѳ��·����ȫ����Ϣ
#define  IPC_CLEAR_CRUISE                    	    4			            //ɾ��ĳһ��Ѳ��·��

//��־���ҽ��
#define IPC_LOG_SUCCESS 							1000 					//��ȡ��־��Ϣ�ɹ�
#define IPC_LOG_NOFIND 								1001  					//δ���ҵ���־
#define IPC_LOG_ISFINDING 							1002 					//���ڲ�����ȴ�
#define IPC_LOG_NOMORERECORD  						1003 					//û�и������־�����ҽ���
#define IPC_LOG_EXCEPTION  							1004 					//������־ʱ�쳣

//��־����
#define IPC_LOG_ALL									0x00000000				//ȫ����־
#define IPC_LOG_ACCESS								0x00000001				//������־
#define IPC_LOG_ALARM								0x00000002				//������־
#define IPC_LOG_SYSTEM								0x00000004				//ϵͳ��־

//SD��¼�����
#define IPC_COMMAND_RECORD_BASE         0x00008000

#define IPC_COMMAND_RECORD_CTRL             (IPC_COMMAND_RECORD_BASE + 0)       //SD��¼����������ɾ���ȣ�
#define IPC_COMMAND_SET_RECORD_CONFIG       (IPC_COMMAND_RECORD_BASE + 1)		//SD��¼������ã���С�ͻ�����ʽ��
#define IPC_COMMAND_GET_RECORD_CONFIG       (IPC_COMMAND_RECORD_BASE + 2)		//SD��¼������ã���С�ͻ�����ʽ��
#define IPC_COMMAND_RECORD_SEARCH           (IPC_COMMAND_RECORD_BASE + 3)       //SD��¼��Ĳ��ң���������
#define IPC_COMMAND_GET_RECORD_NUM          (IPC_COMMAND_RECORD_BASE + 4)       //SD��¼�������ͳ�ƣ���������

//¼����ҽ��
#define IPC_FINDFILE_SUCCESS 				1000 					//��ȡ��־��Ϣ�ɹ�
#define IPC_FINDFILE_NOFIND 				1001  					//δ���ҵ���־
#define IPC_FINDFILE_ISFINDING 				1002 					//���ڲ�����ȴ�
#define IPC_FINDFILE_NOMORERECORD  			1003 					//û�и������־�����ҽ���
#define IPC_FINDFILE_EXCEPTION  			1004 					//������־ʱ�쳣

#define IPC_RECORDSTART			1				//��ʼ¼�� 
#define IPC_RECORDSTOP			2				//ֹͣ¼�� 
#define IPC_DELETEFILE			3				//ɾ��¼���ļ� 
#define IPC_LOCKFILE			4				//����¼���ļ� 
#define IPC_UNLOCKFILE			5				//����¼���ļ�
#define IPC_GET_RECORDCONFIG	6				//��ȡ¼���ļ��ָ��С��Ϣ
#define IPC_SET_RECORDCONFIG	7				//����¼���ļ��ָ��С

#define IPC_SDK_LOCAL_UTF8				    0xFF000000		//sdk �ַ�ʹ��utf8
#define IPC_SDK_LOCAL_WEB_ONLYV3			0xFF000001		//sdk ����֧��3.0���web�ؼ����Ż����� 


//��̨��
#define IPC_ZOOM_TELE           11              //��̨����
#define IPC_ZOOM_WIDE           12    

#define IPC_FOCUS_NEAR          13              //��̨�۽�
#define IPC_FOCUS_FAR           14    

#define IPC_IRIS_OPEN           15                        
#define IPC_IRIS_CLOSE          16 

#define IPC_TILT_UP             17              //��̨��
#define IPC_TILT_DOWN           18              //��̨��
#define IPC_PAN_LEFT            19              //��̨��
#define IPC_PAN_RIGHT           20              //��̨��

#define IPC_UP_LEFT             21              //��̨����
#define IPC_UP_RIGHT            22              //��̨����
#define IPC_DOWN_LEFT           23              //��̨����
#define IPC_DOWN_RIGHT          24              //��̨����

#define IPC_AUXIOPEN            25                        
#define IPC_AUXICLOSE           26

#define IPC_PAN_AUTO            27                                            

#define IPC_SET_LEFTBORDER      28              //��̨��߽�
#define IPC_SET_RIGHTBORDER     29              //��̨�ұ߽�
#define IPC_AUTOSCAN            30              //��̨�Զ�ɨ��
#define IPC_GOTO_HOME           31    

#define IPC_SET_PRESET          32              //��̨����Ԥ��λ
#define IPC_GOTO_PRESET         33              //��̨�ƶ���Ԥ��λ

#define IPC_GET_ALL_PRESET      34              //��̨��ȡ����Ԥ��λ
#define IPC_CLEAR_PRESET        35              //��̨���Ԥ��λ
#define IPC_GET_CAPACITY        36              //��̨��ȡԤ��λ����

//��̨λ�ÿ���
#define IPC_RUN_SEQ				10
#define IPC_STOP_SEQ			11

#pragma pack(push,1)	
typedef struct tagIPC_PRESET_CRUISE_POINT
{
	INT		iPresetIdx;													//Ԥ�õ����� 1~255
	INT     iStaySec;													//ͣ��ʱ�� ��λ�� 
	INT     iMoveSpeed;													//ת����Ԥ�õ���ٶ�  
} IPC_PRESET_CRUISE_POINT_t;												//Ѳ���㶨��

struct IPC_PTZCruiseParam
{
	INT		id;															//Ѳ��·��id, 1~32
	CHAR    name[IPC_MAX_NAME_LEN];										//Ѳ��·������  
	INT    iEnable;														//Ѳ��·��ʹ��
	DWORD	iCount ;													//Ѳ��·����Ѳ�������
	IPC_PRESET_CRUISE_POINT_t	point[IPC_MAX_PRESET_CRUISE_POINTS];		//Ѳ����
};

typedef struct tagIPC_PTZPositionParam 
{
	INT		xPosition ;													//ˮƽ���� ����:  ȡֵ��Χ��ipcPTZPositionControl �����������Ӱ�� �� 
																		//����ΪIPC_CMD_PTZ_GOTO_REL_POSITIONʱ��,ȡֵ��Χ-35999��35999
																		//����ΪIPC_CMD_PTZ_GOTO_ABS_POSITIONʱ��,ȡֵ��Χ  0 ��35999

	INT		yPosition ;													//��ֱ�������꣬ȡֵ��Χ��ipcPTZPostionControl �����������Ӱ�� �� 
																		//����ΪIPC_CMD_PTZ_GOTO_REL_POSITIONʱ��,ȡֵ��Χ-9000��9000
																		//����ΪIPC_CMD_PTZ_GOTO_ABS_POSITIONʱ��,ȡֵ��Χ0 ��9000 
	INT     zPosition ;													//�Ŵ���,Ӧ���ڵ���0����10��������,0��ʾԭʼ��С���Ŵ�1��,10��ʾԭʼ��С�Ŵ�2��,20��ʾ�Ŵ�ԭʼ��С3��,
																		//zPosition/10+1Ϊ�Ŵ�ı���,zPosition�����ֵ180����ֵ��Ӳ���豸������,���ݵ�ֵ�����豸֧�ֵ����ֵʱ���豸�Զ�����Ϊ���ֵ�� 

	INT		xSpeed ;													//ˮƽ�����ƶ����ٶ�
	INT		ySpeed ;													//��ֱ�����ƶ����ٶ�
}IPC_PTZ_POSITION_PARAM, *LPIPC_PTZ_POSITION_PARAM;


typedef struct tagIPC_ALARMCENTER_UP_CFG{
  BYTE		byEnable[IPC_MAX_CENTER];									//�ϴ�����ʹ�ܱ�־						                                        
  WORD		wHostPort[IPC_MAX_CENTER];									//�ϴ����Ķ˿�            
  CHAR		sHostIPAddr[IPC_MAX_CENTER][IPC_MAX_IPADDR_LEN];			//�ϴ�����IP��ַ 
  BYTE		dwReserved[1];												//������
}IPC_ALARMCENTER_UP_CFG;

//MP4�ļ��洢�ӿں궨��ͽṹ
#define		IPC_MP4FRAME_UNDEFINE				0x00
#define		IPC_MP4FRAME_I						0x01					//I frame
#define		IPC_MP4FRAME_P						0x02					//P frame
#define		IPC_MP4FRAME_B						0x03					//B frame		
#define		IPC_MP4FRAME_A						IPC_MP4FRAME_UNDEFINE	//Audio frame

//��Ƶ���� 
typedef struct IPC_MP4_VIDEOPARAM_t
{
    int			dwHeight;                       						//��
    int			dwWidth;                        						//��
    double		dwFrameInterval;                						//֡���  	֡�������λ��100���룩���㷽�����磺10000000.0 / FrameRate��
    int			dwBitRate;                      						//����
    int			dwAspectRatio;                   						//����
    int			dwParWidth;												//����Ĭ��Ϊ0             
    int			dwParHeight;											//����Ĭ��Ϊ0   
    int			cbExtraInfo;											//����Ĭ��Ϊ0   
    void		*pExtraInfo;											//����Ĭ��Ϊ0   
} IPC_MP4_VIDEOPARAM,*LPIPC_MP4_VIDEOPARAM; 

//��Ƶ����
typedef struct IPC_MP4_AUDIOPARAM_t
{
    int			dwChannel;            									//����          
    int			dwSamplePerSec;       									//����Ƶ��           
    int			dwBitsPerSample ;     									//��������                
    int			nAvgBytesPerSec;      									//ƽ������                
    int			nBlockAlign;		  									//����뷽ʽ      
    int			cbExtraInfo;		  									//��չ���ݳ���      
    void		*pExtraInfo;		  									//��չ����      
} IPC_MP4_AUDIOPARAM,*LPIPC_MP4_AUDIOPARAM; 

typedef struct IPC_CALLBACK_INFO_t
{
    UINT32                      lType ;            						//֡����,<video:'I','P','B'><audio:'A'>
    const unsigned char*        pBuf;			   						//֡���ݻ�����
    UINT32			            lBufSize;		   						//֡���ݻ�������С
    LONGLONG                    lStamp;            						//ʱ���<����>
    union {
        struct Video{
            UINT32              lVideoFormat ;     						//0:H264, 1:MJPEG
            UINT32	            lWidth;			   						//ͼ���
            UINT32	            lHeight;		   						//ͼ���
            UINT32	            lFrameRate;        						//֡��
        } video ;
        struct Audio{
            UINT32                lAudioFormat ;     					//0:AMR, 1:G711
            UINT32                lSamplesPerSec ;   					//8000
            UINT32                lChannels ;        					//1
            UINT32                lBitsPerSample ;   					//16
            UINT32                lAvgBytesPerSec ;  					//16000��lSamplesPerSec * lBitsPerSample * lChannels / 8��
        } audio ;
    } info ;
}IPC_CALLBACK_INFO,*LPIPC_CALLBACK_INFO,IPC_FrameInfoEx;

typedef struct IPCVIDEO_CALLBACK_INFO_t
{
    long                lType ;                 						//֡����,I,P,B
    long	            lWidth;				    						//ͼ���
    long	            lHeight;			    						//ͼ���
    long	            lFrameRate;             						//֡��
    const unsigned char	*pBuf;			        						//֡���ݻ�����
    long			    lBufSize;		        						//֡���ݻ�������С

}IPCVIDEO_CALLBACK_INFO,*LPIPCVIDEO_CALLBACK_INFO,IPC_FrameInfo ;

//��Ƶ¼����
typedef struct tagIPC_RecordAction
{
	tagIPC_RecordAction()
	{
		memset(this, 0, sizeof(tagIPC_RecordAction));
	}
	INT       enable_flag;												//0Ϊɾ����1Ϊ��Ч			
	DWORD     delay;													//¼�����ʱ�䶯��������Ϊ��λ
	DWORD     streamID;													//0:����1�� 1:����2 ��2:����3  ��3:����4
	DWORD     locationID;       										//�ļ��������ͣ���IPC_RECORD_FILELOCATION_FTP��IPC_RECORD_FILELOCATION_SDCARD		
}IPC_RECORDACTION, *LPIPC_RECORDACTION;

//������̨����
typedef struct tagIPC_DPTZAction
{
	tagIPC_DPTZAction()
	{
		memset(this, 0, sizeof(tagIPC_DPTZAction));
	}
	INT        enable_flag;												//0Ϊɾ����1Ϊ����					
	DWORD      delay;													//ת�Ƶ�Ԥ��λ��ͣ��ʱ�䣬����Ϊ��λ
	DWORD      streamID;												//0:����1�� 1:����2 ��2:����3  ��3:����4
	DWORD      preset;													//Ԥ��λ��ʶ��,ȡֵ��ΧΪ1��9
}IPC_DPTZACTION, *LPIPC_DPTZACTION;

//��е��̨����
typedef struct tagIPC_PTZAction
{
	tagIPC_PTZAction()
	{
		memset(this, 0, sizeof(tagIPC_PTZAction));
	}
	INT        enable_flag;												//0Ϊɾ����1Ϊ����				
	DWORD      delay;													//ת�Ƶ�Ԥ��λ��ͣ��ʱ�䣬����Ϊ��λ
	DWORD      preset;													//Ԥ��λ��ʶ��,ȡֵ��ΧΪ1��255
}IPC_PTZACTION, *LPIPC_PTZACTION;

//����˿ڶ���
typedef struct tagIPC_OutputAction
{
	tagIPC_OutputAction()
	{
		memset(this, 0, sizeof(tagIPC_OutputAction));
	}
	INT        enable_flag;												//0Ϊɾ���� 1Ϊ����				
	DWORD      level;													//��������,�ߵ͵�ƽ�� 0Ϊ�͵�ƽ�� 1Ϊ�ߵ�ƽ
}IPC_OUTPUTACTION, *LPIPC_OUTPUTACTION;

//��Ӧ������Ϣ
typedef struct tagIPC_ActionOptionInfo
{
	tagIPC_ActionOptionInfo()
	{
		memset(this, 0, sizeof(tagIPC_ActionOptionInfo));
	}
	DWORD             priority;											//���������ȼ� 0: Low, 1: Middle, 2: High	
	DWORD             respond_option;   								//��Ӧ��ʽ,0�����������ڼ�ִ�ж�����1�����������ͽ���ʱִ�ж�����2����������ʱִ�ж��� 	3����������ʱִ�ж���
	IPC_RECORDACTION	  record ;											//¼����,			��RECORDACTION���ݽṹ 
	IPC_DPTZACTION		  dptz;												//������̨����,		��DPTZACTION���ݽṹ 
	IPC_PTZACTION         ptz;												//��е��̨����,		��PTZACTION���ݽṹ 
	IPC_OUTPUTACTION      output;											//��������ڶ���,	��OUTPUTACTION���ݽṹ
	DWORD               dwLinkAlarmStrategy;						           //��֧��3.0�������ԣ���λ��ʾ����0λ-�澯�������1λ-�ϴ����ģ���2λ-�����������3λ-�ʼ�����4λ-FTP�ϴ�����5λ-¼�񣬵�6λ-PTZ����7λ-ץͼ����8λ-�׹�
	DWORD               dwCheckTime;                                          //��֧��3.0 ��λ�����룬���澯״̬��ʱ����
	DWORD               dwIoNum;                                                 //��֧��3.0 ��λ��ʾ����0λ-�澯����˿�0����1λ-�澯����˿�1����2λ-�澯����˿�2����3λ-�澯����˿�3��λΪ0��ʾδ���ã�λΪ1��ʾ���á�                             
	DWORD               dwOperateCmd;                                       //��֧��3.0 ������̨���0-�ޣ�1-Ԥ�õ㣬2-Ԥ�õ�Ѳ����3-����ɨ��
	DWORD               dwOperateSeqNum;                                //��֧��3.0 ��ţ�Ԥ�õ����/Ѳ���켣���/����ɨ�����
	DWORD               dwPtzDelayTime;                                     //��֧��3.0 ��̨��������ʱ�䣬��λΪS
	DWORD               dwDelayTime;                                          //��֧��3.0 �׹��������ʱ�䣬��λΪS
} IPC_ActionOptionInfo,*LPIPC_ActionOptionInfo ;


typedef struct tagIPC_MontionDetectionWindowInfoEx
{
	tagIPC_MontionDetectionWindowInfoEx()
	{
		memset(this, 0, sizeof(tagIPC_MontionDetectionWindowInfoEx));
	}
	int          index;													//����id ��Χ1~4	
	int			 enable;												//�������ʹ�ܱ�־ 0 ���� 1����
	CHAR         name[128] ;											//��������			
	RECT         rect ;													//�������䣬ΪRECT�ṹ��
																		//��Ƶͼ�񱻷ֳ�12x8=96 ������ ��x,y ��ȷ�����Ͻǣ�right,bottom����ȷ�����½ǡ����½ǵ�����һ��Ҫ�������Ͻǵ�����
																		//x ȡֵ��Χ[0, 11].     y ȡֵ��Χ [0, 7].     right ȡֵ��Χ [1, 12].     width ȡֵ��Χ [1, 8].
																		//���磺 rect Ϊ{x=1��y=1 ��right=2��bottom=2} ��ʾռ��(1,1),(1,2),(2,1),(2,2)�ĸ�����

	INT          agile;													//������ ��Χ[0, 10],ֵԽ��Խ����������ֵ3~5,		
	INT          threshold;												//��ֵ ��Χ[1, 100],ֵԽСԽ���״����¼�������ֵ25~30  				
}IPC_MontionDetectionWindowInfoEx,*LPIPC_MontionDetectionWindowInfoEx ;

//IrCut��ҹģʽ
typedef struct tagIPC_IRCUT
{
	tagIPC_IRCUT()
	{
		memset(this, 0, sizeof(tagIPC_IRCUT)) ;
	}
	DWORD	ircut_DurTime ;												//�ȴ�ʱ�䣬��ÿ��������ҹ�л����ߵ�ʱ����  3s ~ 30s  Ĭ��10s
	DWORD	ircut_DayToNightThr ;										//����ģʽתҹ��ģʽ����ֵ	0~100   Ĭ�� 40
	DWORD	ircut_NightToDayThr ;   									//ҹ��ģʽת����ģʽ����ֵ	0~100 Ĭ�� 60
}IPC_IMGIRCUT, *LPIPC_IMGIRCUT;

//ͼ������
typedef struct tagIPC_IMGPRO
{
	tagIPC_IMGPRO()
	{
		memset(this, 0, sizeof(tagIPC_IMGPRO));
	}
	DWORD	img_saturation; 											//ȡֵ��Χ��0~255
	LONG	img_brightness; 											//ȡֵ��Χ��-255~255
	LONG	img_hue;													//ȡֵ��Χ��-15~15	
	DWORD	img_contrast;												//ȡֵ��Χ��0~255
	DWORD	img_sharpness;  											//ȡֵ��Χ��0~255
}IPC_IMGPRO, *LPIPC_IMGPRO;

//DC IRISģʽ
typedef struct tagIPC_IMGIRIS
{
	tagIPC_IMGIRIS()
	{
		memset(this, 0, sizeof(tagIPC_IMGIRIS));
	}
	DWORD	iris_type; 													//ģʽ 0�ر�;1����	
	DWORD	iris_quty; 													//ռ��ֵ 100 ~ 999	
}IPC_IMGIRIS, *LPIPC_IMGIRIS;

//���ӿ���ʱ�䷶��
typedef struct tagIPC_IMGSHUTTER
{
	tagIPC_IMGSHUTTER()
	{
		memset(this, 0, sizeof(tagIPC_IMGSHUTTER));
	}
	DWORD	shutter_min;												//��Сֵ��ȡֵ��ΧΪ64000 �� 20480000	
	DWORD	shutter_max;												//���ֵ��ȡֵ��ΧΪ64000 �� 68266667
}IPC_IMGSHUTTER, *LPIPC_IMGSHUTTER;

//��Ƶ�ڵ�
typedef struct tagIPC_IMGPM
{
	tagIPC_IMGPM()
	{
		memset(this, 0, sizeof(tagIPC_IMGPM));
	}
	INT		pm_index;													//������ȡֵ��ΧΪ1��4
	INT		enable_flag	;												//trueΪ���ã�falseΪɾ��	
	DWORD	pm_left; 													//	0~99   ���嶨��ο��ĵ���ϸ˵��
	DWORD	pm_top; 													// 	0~99
	DWORD	pm_w;														//	1~100
	DWORD	pm_h;														//	1~100
	DWORD	pm_color; 													//������ɫ 0:��ɫ 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��� 6:���� 7:��ɫ			
}IPC_IMGPM, *LPIPC_IMGPM;


//��Ƶ�ڵ�
typedef struct tagIPC_IMGPM_EX
{
	tagIPC_IMGPM_EX()
	{
		memset(this, 0, sizeof(tagIPC_IMGPM_EX));
	}
	INT		pm_index;													//������ȡֵ��ΧΪ1��4
	INT		enable_flag	;												//trueΪ���ã�falseΪɾ��	
	DWORD	pm_left; 													//	0~99   ���嶨��ο��ĵ���ϸ˵��
	DWORD	pm_top; 													// 	0~99
	DWORD	pm_w;														//	1~100
	DWORD	pm_h;														//	1~100
	DWORD	pm_color; 													//������ɫ 0:��ɫ 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��� 6:���� 7:��ɫ	
	CHAR	szName[32];
}IPC_IMGPM_EX, *LPIPC_IMGPM_EX;

//��ʾ��Ϣ����
typedef struct tagIPC_SNTEXT
{
	tagIPC_SNTEXT()
	{
		memset(this, 0, sizeof(tagIPC_SNTEXT)) ;
	}
	DWORD	text_streamID ;												//����ID��0Ϊ����1��1Ϊ����2��2Ϊ����3��3Ϊ����4
	BOOL	text_enable; 												//�Ƿ���ʾ������Ϣ��0Ϊ����ʾ�� 1Ϊ��ʾ	
	CHAR	text_content[32];											//������Ϣ���ݣ����32���ַ�
}IPC_SNTEXT, *LPIPC_SNTEXT;


// ��Ԥ��ʱ��ȡ��ǰ������Ϣ
typedef struct tagIPC_ENCENC
{
	tagIPC_ENCENC()
	{
		memset(this, 0, sizeof(tagIPC_ENCENC));
	}
	DWORD	enc_streamID ;											//Ϊ��ǰ����Ԥ��������ID��0Ϊ����1��1Ϊ����2��2Ϊ����3��3Ϊ����4
	DWORD 	enc_type; 												//�����ʽ�� 1ΪH.264��2ΪMJPEG			
	DWORD 	enc_fbs;												//����֡�� 60fpsΪ 8533333�� 30fpsΪ17066667��25fpsΪ20480000
																	//20fpsΪ25600000��15fpsΪ34133333��10fpsΪ51200000��6fpsΪ85333333 
																	//5fpsΪ102400000��3fpsΪ170666667��2fpsΪ256000000��1fpsΪ512000000
	DWORD	enc_brcMode;											//�����ʿ��ƣ�0ΪCBR��1ΪVBR��2ΪCBR (keep quality) ��3ΪVBR (keep quality)		
	DWORD 	enc_cbrAVG;												//������ƽ��ֵ������1000000��8000000֮��		
	DWORD 	enc_vbr_min;											//��С�����ʣ�Ĭ��Ϊ1000000		
	DWORD 	enc_vbr_max;											//�������ʣ�Ĭ��Ϊ8000000		
}IPC_ENCENC, *LPIPC_ENCENC;

//ʱ������
typedef struct tagIPC_SYSDATEINFO
{
	tagIPC_SYSDATEINFO()
	{
		memset(this, 0, sizeof(tagIPC_SYSDATEINFO));
	}
	DWORD		sync_mode;											//�豸ʱ��ͬ�����ͣ�ֻд����0:��NTPͬ����ntp_addr����Ϊnull��1:�ֶ����ã� time_date��time_time����Ϊ��2:��pcʱ��ͬ����time_date��time_time����Ϊ��																 
	CHAR	time_date[32]	;										//����
	CHAR	time_time[32];											//ʱ��
	CHAR	ntp_addr[32];											//ntp��������ַ ��ֻд��
}IPC_SYSDATEINFO, *LPIPC_SYSDATEINFO;

//ʱ��������չ�ӿ�
typedef struct tagIPC_SYSDATEINFOEX
{
	tagIPC_SYSDATEINFOEX()
	{
		memset(this, 0, sizeof(tagIPC_SYSDATEINFOEX));
	}
	DWORD	sync_mode;												//�豸ʱ��ͬ������,0:��NTPͬ��(ntp_addr��timeZone��Ч),				1:�ֶ�����(time_date��time_time��timeZone��Ч)
																	//				   2:��pcͬ��(time_date��time_time��timeZone��Ч)	3:�Զ�ͬ��(interval��timeZone��ntp_addr��Ч)
	CHAR	time_date[32]	;										//����
	CHAR	time_time[32];											//ʱ��
	int		interval ;												//ʱ��������λ���ӣ�ȡֵ��Χ1-100000
	char    timeZone[32] ;											//ʱ������ʽΪCST+HH:MM:SS��CST-HH:MM:SS���綫����ΪCST+08:00:00��������ΪCST-08:00:00
	char	ntp_addr[32];											//ntp��������ַ
}IPC_SYSDATEINFOEX, *LPIPC_SYSDATEINFOEX;

typedef struct tagIPC_SYSUPNPINFO
{
	tagIPC_SYSUPNPINFO()
	{
		memset(this, 0, sizeof(tagIPC_SYSUPNPINFO));
	}
	DWORD	     enable;											//�Ƿ���ã�trueΪ���ã�falseΪ������					
	DWORD	     port;												// �˿ں�		
	CHAR	     name[32];											// ����			
}IPC_SYSUPNPINFO,*LPIPC_SYSUPNPINFO;

//SMTP����
typedef struct tagIPC_SYSSMTP
{
	tagIPC_SYSSMTP()
	{
		memset(this, 0, sizeof(tagIPC_SYSSMTP));
	}
	DWORD		smtp_enable;										//�Ƿ�����SMTP, 1:��Ҫ���ã�0:����Ҫ����
	CHAR		smtp_addr[32];										//smtp�ʼ���������ַ����ʽ������192.168.1.114
	DWORD		smtp_port;											//smtp�˿ں� 0��65535
	DWORD		smtp_auth_enable;									//�Ƿ�ʹ��Ȩ����֤��½ 1:ʹ�ã� 0:��ʹ�ã���
																	//��Ҫ��дname��pw��
	CHAR		smtp_auth_name[32];									//�û���
	CHAR		smtp_auth_password[32];								//����
	DWORD		smtp_auth_model;									//��֤��ʽ��0:LOGIN  1:PLAIN
	CHAR		smtp_sender[64];									//�����˵�ַ����ȷ�����ַ
	CHAR		smtp_receiver[64];									//�ռ��˵�ַ����ȷ�����ַ
	CHAR		smtp_cc[64];										//���͵�ַ�� ��ȷ�����ַ
	CHAR		smtp_subject[64];									//�ʼ�����
	CHAR		smtp_content[128];									//�ʼ����ݣ��ı��ַ���
}IPC_SYSSMTP, *LPIPC_SYSSMTP;

//FTP����
typedef struct tagIPC_SYSFTP
{
	tagIPC_SYSFTP()
	{
		memset(this, 0, sizeof(tagIPC_SYSFTP));
	}
	DWORD		ftp_enable;											//�Ƿ���ftp�� 1:������0:�ر�
	CHAR		ftp_addr[32];										//ftp��������ַ
	DWORD		ftp_port;											//ftp�˿�
	CHAR		ftp_user[32];										//�û���
	CHAR		ftp_password[32];									//����

}IPC_SYSFTP, *LPIPC_SYSFTP;

//ipv4��ַ����
typedef struct tagIPC_SYSIPINFO
{
	tagIPC_SYSIPINFO()
	{
		memset(this, 0, sizeof(tagIPC_SYSIPINFO));
	}
	DWORD	dhcp_enable;											//����ip��ַ��ʽ��1:����dhcp��0:�ֶ�����ip
	CHAR	ip_addr[32];											//ip��ַ
	CHAR	network_mask[32];										//��������
	CHAR	gateway_addr[32];										//Ĭ������
	CHAR	dns_addr[32];											//��ѡDNS��������ַ
	CHAR	dns_backup_addr[32];									//����DNS��������ַ
	CHAR	mac_addr[32]	;										//mac��ַ ��ֻ��������������
}IPC_SYSIPINFO, *LPIPC_SYSIPINFO;

typedef enum tagIPC_DEVICESTATE
{
    ipc_ds_online,              										//����
    ipc_ds_offlline,            										//����
    ipc_ds_busy,                										//æµ
    ipc_ds_idle,                										//����
    ipc_ds_unknow               										//�޷�֪̽
}IPC_DEVICESTATE,*LPIPC_DEVICESTATE;

typedef struct tagIPCSCANINFO
{
	tagIPCSCANINFO()
	{
		memset(this, 0, sizeof(tagIPCSCANINFO));
	}
    IPC_DEVICESTATE state ;         								//�豸��ǰ״̬
    int  port ;                 									//�˿�
    char mac[32] ;              									//mac��ַ
    char IPAddress[32] ;        									//ip��ַ
    char PrimaryDns[32] ;       									//dns
    char SecondaryDns[32] ;     									//���� dns
    char Netmask[32] ;          									//����
    char Gateway[32] ;          									//����
}IPCSCANINFO,*LPIPCSCANINFO ;

//��Ƶ����
typedef struct {
    int audio_enable;												//�Ƿ����������Խ�����0:disable 1:enable
    int codec_fmt;													//0:AMR, 1:G711
    int audio_out_enable;											//�Ƿ������豸���������0:disable 1:enable
    int audio_out_vol;												//�豸������� eg:(50)50%
    int audio_in_vol;												//�豸�������� eg:(50)50%
    int echo_canceller_enable;										//�������� 
}IPC_AUDIOCONF_t,* LPIPC_AUDIOCONF ;

typedef struct {
    int cmd;														//0 : stop, 1 : start, 
} IPC_AUDIOCONFERENCECTRL_t,*LPIPC_AUDIOCONFERENCECTRL ;

typedef struct {
    int status;														//0 : stop, 1 : start, 
} IPC_AUDIOCONFERENCESTATUS_t,*LPIPC_AUDIOCONFERENCESTATUS ;

//�����豸
typedef struct IPC_AudioDevice_t { 
    INT iId;														//�����豸id 
    CHAR sDevName[128];												//�����豸���� 
} IPC_AudioDevice,*LPIPC_AudioDevice ;

//����������Ϣ
typedef struct IPC_COMM_PROP_t{ 

    BYTE byDataBit;     											//����λ [7,8]
    BYTE byStopBit;     											//ֹͣλ [1,2]
    BYTE byParity;      											//У��λ [0,2]��PARITY_NONE  = 0,    PARITY_ODD   = 1,        PARITY_EVEN  = 2,
    BYTE byBaudRate;    											//������ [0,9]��0=300,1=1200,2=2400,3=4800,4=9600,5=19200,6=38400,7=115200,8=460800,9=921600

} IPC_COMM_PROP,*LPIPC_COMM_PROP ;

//Ԥ��λ��Ϣ
typedef struct IPC_PRESET_t
{
    DWORD index ;													//���� 1~255
    DWORD enable ;													//����
    CHAR  name[256] ;												//����
}IPC_PRESET ,*LPIPC_PRESET ;

typedef struct tagIPC_ALARMER
{
	CHAR szIp[64];													//�����豸IP
	CHAR szDevName[64];												//�����豸����
}IPC_ALARMER;

typedef struct _tagIPC_AlarmInfo
{
	INT     idHeight;												//������Ϣid��64λ��������32λ���ݣ���idΪ������Ϣ���ݿ���м�¼id������Ψһ�ش���һ��������Ϣ
	INT     idLow;                  								//������Ϣid��64λ��������λ32���ݣ���idΪ������Ϣ���ݿ���м�¼id������Ψһ�ش���һ��������Ϣ
	INT		iLevel;                 								//�����ȼ�(0,1,2��.) ,0�ȼ����,����Խ��ȼ�Խ��
	INT		iState; 												//1������ʼ0��������
	CHAR	tmStamp[32];											//ʱ��� ��ʽYYYYMMDDHHMMSS;�磺20120802235502
	CHAR	szDescript[64];											//������Ϣ����
	CHAR	szReserved[64];		    								//��������,�ⲿ���뱨��ʱ����Դ��ݶ˿ںţ����ֱ�����������һ���ַ���
}IPC_ALARMINFO,*LPIPC_ALARMINFO;


typedef struct _tagIPC_DDNSPARA
{
	INT    iEnableDDNS;											    //�Ƿ�ʹ�ܣ�0����1���� 
	INT    iDDNSType;												//0-��Dyndns DNS��1---Private��2��PeanutHull(������)��3-NO-IP  Ŀǰ����֧��1
	INT	   iInterval;												//�ϱ�ʱ��������λ��(10~7200)
	CHAR   sUserName[64];											//DDNS�˺��û���  ��ʱδʹ��
	CHAR   sPassword[64];											//DDNS�˺�����  ��ʱδʹ��
	CHAR   sDomainName[64];											//�豸����
	CHAR   sServerName[64];											//DDNS��Ӧ�ķ�������ַ��������IP��ַ������
	INT    iDDNSPort;												//DDNS�������˿�
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

//��Ƶͼ����Ϣ
typedef struct _tagIPC_ImgInfo
{
	IPC_ImgSize	 stSize;											//�ֱ���
	INT			 iRate;												//֡��
}IPC_ImgInfo;


//������������Ӧ��ȫ��ͼ��ֱ��� ֡����Ϣ
typedef struct _tagIPC_AllImgInfo
{
	INT				iCount;											//�ֱ��� ֡����Ϣ����
	IPC_ImgInfo		stImgInfo[IPC_MAX_IMGINFO_COUNT][4];			//�ж�Ӧ����id 1~4֧�ֵ�ͼ��ֱ��ʺ�֡��,
}IPC_AllImgInfo;


//�豸��ǰ��������������Ϣ
typedef struct _tagIPC_StreamInfo
{
	INT				iWidth;											//ͼ����
	INT				iHeight;										//ͼ��߶�
	INT				iRate;											//ͼ��֡��
	INT				iEncType;										//ͼ��ֱ������� 1:H264,2:MJPEG
	long			lAudioFormat;									//��Ƶ�����ʽ ��Ƶ�����ʽ 0:AMR; 1:G711
																	//��ʽ�̶�Ϊ: amrΪSamplesPerSec:8000,BitsPerSample:16,Channels:1,AvgBytesPerSec:16000;711ΪSamplesPerSec:8000,BitsPerSample:16,Channels:1,AvgBytesPerSec:8000
 
}IPC_StreamInfo;


//�豸��ǰ����������Ϣ
typedef struct _tagIPC_DeviceImgInfo
{
	INT				iStreamCount;									//�������� 1~4
	IPC_StreamInfo		stStreamInfo[4];								//��Ӧ����id 0~3��������Ϣ
}IPC_DeviceImgInfo;

//������Ϣ
typedef struct _tagIPC_BitRate
{
	DWORD   sn_brc; 		 										//�����ʿ��ƣ�0ΪCBR��1ΪVBR��2ΪCBR (keep quality) ��3ΪVBR (keep quality)	  
	DWORD   sn_cbr; 		 										//������ƽ��ֵ������1000000��8000000֮��	  sn_brcΪ0��2ʱ��Ч
	DWORD   sn_vbr_min;	     										//��С�����ʣ�bps����Ĭ��Ϊ1000000	 sn_brcΪ1��3ʱ��Ч
	DWORD   sn_vbr_max;	     										//�������� ��bps����Ĭ��Ϊ8000000	 sn_brcΪ1��3ʱ��Ч 
}IPC_BitRate; 


 
//ddns ��Ϣ
typedef struct _tagIPC_DDNSRecord
{
	CHAR szDomain[IPC_MAX_NAME_LEN];								// ����
	CHAR szSN[IPC_MAX_NAME_LEN];									// ���к�
	CHAR szIp[IPC_MAX_NAME_LEN];									// �豸IP��Ϣ
	CHAR szName[IPC_MAX_NAME_LEN];									// �豸����
	INT  iPort;														// ��¼�˿�
}IPC_DDNSRecord;



typedef	struct	
{
    unsigned long			ulFlag;									//֡ͷ��ʶ,�̶�ֵ:'SIMG'
    unsigned long			ulVersion;								//�汾��
    long					lType;									//֡����,��Ƶ: 'I','P','B',��Ƶ:'A',��ͷ:'H'
    long					lSize;									//֡����: ֡ͷ���� + ֡���ݳ���
    long					lHeaderSize;							//֡ͷ����:sizeof(IPC_STREAM_HEADER)	

    long					lVideoForamt;							//��Ƶ���뷽ʽ. 0:H264 ,1:MJPEG
    long					lWidth;									//��Ƶ��
    long					lHeight;								//��Ƶ��	
    long					lFrameRate;								//��Ƶ֡��

    long					lAudioForamt;							//��Ƶ�����ʽ 0:AMR; 1:G711
    long					lSamplesPerSec;							//����Ƶ��:8000,
    long					lBitsPerSample;							//��������:amrΪ16,711Ϊ16
    long					lChannels;								//����:1,
    long					lAvgBytesPerSec;						//ƽ������:amrΪ16000,711Ϊ8000

    unsigned char			Reserve[32];							//�����ֶ�
}IPC_STREAM_HEADER,*PIPC_STREAM_HEADER;								//��ͷ

typedef	struct
{
    unsigned long			ulFlag;									//֡ͷ��ʶ,�̶�ֵ:'FIMG'
    long					lType;									//֡����,��Ƶ: 'I','P','B',��Ƶ:'A',��ͷ:'H'
    long					lSize;									//֡����: ֡ͷ���� + ֡���ݳ��� + ֡β����
    long					lHeaderSize;							//֡ͷ����:sizeof(IPC_VIDEOFRAME_HEADER)	
    long					lTailSize;								//֡β����:sizeof(IPC_FRAME_TAIL)
    ULONGLONG				ullTimeStamp;							//ʱ���
    long					lForamt;								//��Ƶ���뷽ʽ. 0:H264 ,1:MJPEG
    long					lWidth;									//��Ƶ��
    long					lHeight;								//��Ƶ��	
    long					lFrameRate;								//��Ƶ֡��
    unsigned char			Reserve[12];							//����
}IPC_VIDEOFRAME_HEADER,*PIPC_VIDEOFRAME_HEADER;						// ��Ƶ֡ͷ

typedef	struct
{
    unsigned long			ulFlag;									//֡ͷ��ʶ,�̶�ֵ:'FPIG'
    long					lType;									//֡����,��Ƶ: 'I','P','B',��Ƶ:'A',��ͷ:'H'
    long					lSize;									//֡����: ֡ͷ���� + ֡���ݳ��� + ֡β����
    long					lHeaderSize;							//֡ͷ����:sizeof(IPC_AUDIOFRAME_HEADER)	
    long					lTailSize;								//֡β����:sizeof(IPC_FRAME_TAIL)
    ULONGLONG				ullTimeStamp;							//ʱ���
    long					lForamt;								//��Ƶ�����ʽ 0:AMR; 1:G711
    long					lSamplesPerSec;							//����Ƶ��:8000,
    long					lBitsPerSample;							//��������:amrΪ16,711Ϊ16,
    long					lChannels;								//����:1,
    long					lAvgBytesPerSec;						//ƽ������:amrΪ16000,711Ϊ8000
    unsigned char			Reserve[8];								//����
}IPC_AUDIOFRAME_HEADER,*PIPC_AUDIOFRAME_HEADER;						//��Ƶ֡ͷ

typedef struct
{
    long					lSize;									//֡����: ֡ͷ���� + ֡���ݳ��� + ֡β����
    unsigned long			ulFlag;									//֡β��ʶ,�̶�ֵ:'GIPF'
}IPC_FRAME_TAIL,*PIPC_FRAME_TAIL;


#define IPC_RECORD_CTRL_STRLEN 128
typedef struct tagIPC_RecordCtrl
{
	unsigned long       uRecordCtrl;                                            //0:��ʼ  1��ֹͣ  2.ɾ��¼���ļ� 3.����¼���ļ� 
	unsigned long       uRecordType;                                            // bit: 0:��ʱ bit: 1:�ֶ� bit: 2:���� bit: 3.�ƶ���� bit: 4.����¼�� //ֹͣ¼�񴥷������ж�ֹͣ��ֹͣ¼�񣩣�(��λ����λΪ1��ʾ����)
    unsigned long       uStreamID;                                              //0~3
    unsigned long       uBitrateScale;                                          //����֡�ʵȷ���ʵ�������½�
	char                strDeviceID[IPC_RECORD_CTRL_STRLEN];                    ////�����豸��ʶ  //��������д��
	char                strFilePath[IPC_RECORD_CTRL_STRLEN];                    //�ļ��洢·��,Ŀǰֻ��д�ļ���
}IPC_RECORD_CONTROL,*LPIPC_RECORD_CONTROL ;


typedef struct tagIPC_RecordConfig
{
	unsigned long           uRcordFileMaxSize;                                      //¼���ļ��ָ��С ��λMB range:32~512
	unsigned long           uStreamType;                                            //0:����Ƶ 1:����Ƶ 2:����Ƶ������
}IPC_RECORDCONFIG,*LPIPC_RECORDCONFIG ;


//IPC_INTERNAL_COMMAND_RECORD_SEARCH REQ
typedef struct tagIPC_RecordFindCond
{
	unsigned long           uRecordType;                                            // bit: 0:��ʱ bit: 1:�ֶ� bit: 2:���� bit: 3.�ƶ���� bit: 4.����¼��(��λ����λΪ1��ʾ����) //��������д-1
	unsigned long           uStreamID;                                              //��ID  0~3   //��������д-1
	unsigned long           uRecordOffset;                                          //��¼ƫ��,���ڷ�ҳ��ʾ���ӵ�һ����¼��ʼ��д0  //��ȡ¼���¼����ʱ����Ҫ��д
	unsigned long           uRecordMaxNum;                                          //��ҳ��ʾ��Ŀ  //��ȡ¼���¼����ʱ����Ҫ��д
	char                    strDeviceID[IPC_RECORD_CTRL_STRLEN];                    //�����豸��ʶ  //��������д��
	char                    strStartTime[IPC_RECORD_CTRL_STRLEN];                   //¼��ʼʱ��(��ʽ2010-11-11T19:46:17) //��������д��
	char                    strStopTime[IPC_RECORD_CTRL_STRLEN];                    //¼�����ʱ��(��ʽ2010-11-11T19:46:17)    //��������д��

}IPC_RECORDFINDCOND,*LPIPC_RECORDFINDCOND ;


//IPC_INTERNAL_COMMAND_RECORD_SEARCH RESP
typedef struct tagIPC_RecordEntity
{
	unsigned long           uFileOffset;                                            //��¼���ļ��е�ƫ����,���һ����¼��һ���ļ��洢uFileOffset=0,������¼��һ���ļ��д洢��Ҫ�ñ�־		 
	unsigned long           uRecordSize;                                            //��¼��СKB
	unsigned long           uRecordType;                                            // bit: 0:��ʱ bit: 1:�ֶ� bit: 2:���� bit: 3.�ƶ���� bit: 4.����¼��(��λ����λΪ1��ʾ����)
	unsigned long           uStreamID;                                              //��ID 0~3
	unsigned long           uReserved1;                                             //����1 
	unsigned long           uReserved2;                                             //����2	
	char                    strDeviceID[IPC_RECORD_CTRL_STRLEN];                    //�����豸��ʶ
	char                    strRecordID[IPC_RECORD_CTRL_STRLEN];                    //��¼��ʶ 
	char                    strFilePath[IPC_RECORD_CTRL_STRLEN];                    //�ļ��洢·��,Ŀǰֻ��д�ļ���
	char                    strStartTime[IPC_RECORD_CTRL_STRLEN];                   //¼��ʼʱ��(��ʽ2010-11-11T19:46:17)
	char                    strStopTime[IPC_RECORD_CTRL_STRLEN];                    //¼�����ʱ��(��ʽ2010-11-11T19:46:17)

}IPC_RECORDENTITY,*LPIPC_RECORDENTITY ;

typedef struct tagIPC_RecordDownloadInfo
{
    unsigned long       uType ;                                                         //0: ��֡ID, 1: ���ֽ�, 2:��ʱ��
    unsigned long long  ullIndex ;                                                      //�Ӵ�λ�ÿ�ʼ����
    unsigned long       uReserved[2] ;                                                  //������

} IPC_RECORDDOWNLOADINFO,*LPIPC_RECORDDOWNLOADINFO ;

typedef struct tagIPC_RdEntityGroup
{
	DWORD				dwCount ;	//lpEntityArray�Ĵ�С
	LPIPC_RECORDENTITY		lpEntityArray ; // RECORDENTITY entity[dwCount];
}IPC_RDENTITYGROUP,*LPIPC_RDENTITYGROUP ;


//�豸OSD��Ϣ
typedef struct tagIPC_DEVICEOSD
{
	tagIPC_DEVICEOSD()
	{
		memset(this, 0, sizeof(tagIPC_DEVICEOSD)) ;
	}

	BOOL	bShow; 													//�Ƿ���ʾ������Ϣ��FALSEΪ����ʾ�� TRUEΪ��ʾ	
	DWORD	streamID ;												//����ID��0Ϊ����1��1Ϊ����2��2Ϊ����3��3Ϊ����4
	DWORD   x ;														//��ʾ������ʼX���� [0 100]��Ƶͼ������Ͻ�Ϊԭ�㡢xΪ��X�᷽������Ƶ��ȵİٷֱ�
	DWORD	y ;														//��ʾ������ʼY���� [0 100]��Ƶͼ������Ͻ�Ϊԭ�㡢yΪ��Y�᷽������Ƶ�߶ȵİٷֱ�
	DWORD	textColor ;												//������ɫ [0 7] 0:��ɫ��1:��ɫ��2:��ɫ��3:��ɫ��4:��ɫ��5:���ɫ��6:����ɫ��7:��ɫ
	DWORD   textBold ;												//�����ϸ 0�������� 1������
	DWORD	textSize ;												//�����С ֻ֧��16,24,32,40,48,һ��ȡ48�ȽϺ���
	CHAR	textContent[32];										//��Ϣ���ݣ����32���ֽ�
}IPC_DEVICEOSD, *LPIPC_DEVICEOSD;

//ʱ��OSD��Ϣ
typedef struct tagIPC_DATETIMEOSD
{
	tagIPC_DATETIMEOSD()
	{
		memset(this, 0, sizeof(tagIPC_DATETIMEOSD)) ;
	}

	BOOL	bShow; 													//�Ƿ���ʾ������Ϣ��FALSEΪ����ʾ�� TRUEΪ��ʾ	
	DWORD	streamID ;												//����ID��0Ϊ����1��1Ϊ����2��2Ϊ����3��3Ϊ����4
	DWORD   x ;														//��ʾ������ʼX���� [0 100]��Ƶͼ������Ͻ�Ϊԭ�㡢xΪ��X�᷽������Ƶ��ȵİٷֱ�
	DWORD	y ;														//��ʾ������ʼY���� [0 100]��Ƶͼ������Ͻ�Ϊԭ�㡢yΪ��Y�᷽������Ƶ�߶ȵİٷֱ�
	DWORD	timeColor ;												//������ɫ [0 7] 0:��ɫ��1:��ɫ��2:��ɫ��3:��ɫ��4:��ɫ��5:���ɫ��6:����ɫ��7:��ɫ
	DWORD   timeBold ;												//�����ϸ 0�������� 1������
	DWORD	timeSize ;												//�����С ֻ֧��16,24,32,40,48,һ��ȡ48�ȽϺ���
}IPC_DATETIMEOSD, *LPIPC_DATETIMEOSD;


//��־ʱ��
typedef struct tagIPC_TIME
{
	DWORD dwYear;													//��
	DWORD dwMonth;													//��
	DWORD dwDay;													//��
	DWORD dwHour;													//ʱ
	DWORD dwMinute;													//��
	DWORD dwSecond;													//��
    DWORD dwRes;													//����
}IPC_TIME, *LPIPC_TIME;

//��־����
typedef struct tagIPC_LOG_CONFIG
{
	DWORD dwType;													//��־����������ͣ�0 ������ౣ��������1 ������ౣ������	    
	DWORD dwMaxValue;												//�뱣����Զ�Ӧ�� ��dwTypeΪ0��ȡֵ��ΧΪ 1-30000����dwTypeΪ1��ȡֵ��ΧΪ 1-365.    
}IPC_LOG_CONFIG, *LPIPC_LOG_CONFIG;

//��־��Ϣ�ṹ�塣
typedef struct _tagIPC_LOG{
  DWORD             dwId;											//��־id
  IPC_TIME		    stLogTime;										//��־ʱ��
  DWORD             dwType;											//��־����,����־���Ͷ���
  CHAR              sUser[IPC_LOG_MAX_USER_NAME_LEN];				//�û�����GBK����
  CHAR              sSummary[IPC_LOG_MAX_SUMMARY_LEN];				//��־������GBK����
  CHAR              sDesp[IPC_LOG_MAX_DESCRIPTION_LEN];				//��־��ϸ������GBK����
}IPC_LOG,*LPIPC_LOG;


typedef struct tagIPC_FIND_DATA{
	char		sFileID[128];		//�ļ�ID��ʶ��
	char        sFileName[128];		//�ļ���
	DWORD		dwFileType ;		//�ļ�����
	IPC_TIME    struStartTime;		//�ļ��Ŀ�ʼʱ�� 
	IPC_TIME    struStopTime;		//�ļ��Ľ���ʱ��
	DWORD       dwFileSize;			//�ļ���С ��λKB
}IPC_FIND_DATA,*LPIPC_FIND_DATA;

typedef struct tagIPC_RECORD_CTRL{
	DWORD		dwFileType ;		//�ļ�����
	DWORD		dwChannel ;			//ͨ���ţ�����id��
}IPC_RECORD_CTRL,*LPIPC_RECORD_CTRL;

typedef struct tagIPC_RECORD_CONFIG{
	DWORD       dwFileMaxSize;		//�ļ���С ��λKB
	DWORD		dwStreamType ;		//�������� 0:����Ƶ 1:����Ƶ 2:����Ƶ������
}IPC_RECORD_CONFIG,*LPIPC_RECORD_CONFIG;

    //
    typedef struct _tagIPC_PtzHomeCfg{
        INT             iEnable;                          //ʹ�ܱ�־
		INT				iType;							  //0-Ԥ�õ㣬1-Ѳ����2-����
        INT             iPreset;                          //Ԥ�Ƶ��������Ĭ�ϴ�1��ʼ 
        INT             iTime;                            //��λ�� 1-720 
    }IPC_PTZHOME_CFG,*LPIPC_PTZHOME_CFG;



	typedef struct _tagIPC_Ptz3DCtrl{
		INT             iX;                                             //x = (x0 / W) * 8192
		INT             iY;                                             //y = (y0 / H) * 8192
		INT             iW;                                             //width = (w / W) * 8192    WΪ��Ƶ����Ŀ��
		INT             iH;                                             //hight = (h / H) * 8192    HΪ��Ƶ����ĸ߶�  ������ʱ�� width��heightΪ0
		//��ѡWidth�� height����0���䱶�����󣬷�ѡ��ʱ��Width�� height��С��0���䱶�����С
	}IPC_PTZ3DCTRL,*LPIPC_PTZ3DCTRL;

	typedef struct _tagIPC_Ptz3DCtrl2{
		INT             PtzId;
		INT             iX;                                             //x = (x0 / W) * 8192
		INT             iY;                                             //y = (y0 / H) * 8192
		INT             iW;                                             //width = (w / W) * 8192    WΪ��Ƶ����Ŀ��
		INT             iH;                                             //hight = (h / H) * 8192    HΪ��Ƶ����ĸ߶�  ������ʱ�� width��heightΪ0
		//��ѡWidth�� height����0���䱶�����󣬷�ѡ��ʱ��Width�� height��С��0���䱶�����С
		unsigned char   Parameter[4]; 
	}IPC_PTZ3DCTRL2,*LPIPC_PTZ3DCTRL2;

	typedef struct tagIPC_UserInfo
	{
		CHAR     sUserName[32];
		CHAR     sUserPass[32];
		INT      nUserFlag;				//�û�flag��1������Ա, 2������Ա, 3--Viewer
		INT      nUserLevel;			//����
	}IPC_USER_INFO;

	typedef struct _tagIPC_USER
	{ 
		DWORD                     dwSize;
		INT						  nEncType ; //�������� 1���ģ�2md5��3consult��4des
		IPC_USER_INFO             stUser[IPC_MAX_USERNUM];
	}IPC_USER,*LPIPC_USER;


	typedef struct _tagIPC_STREAM_STATE
	{
		INT nStreamId;				//stream id
		INT nRecordStatic;			//0-����¼��, 1-û��¼��
		INT nVideoSignalStatic;		//0-����l, 1-��ʧ
		INT nReserved[2];
		INT nBitRate;				//ʵ������
		INT nLinkNum;				//�ͻ���������
		CHAR nClientIP[16][32];	    //�ͻ���IP
	}IPC_STREAM_STATE;

	typedef struct  tagIPC_WORKSTATE
	{  
		INT				  nDeviceStatic;			//0-normal, 1-cpu too high, >85%, 2-hardware error
		IPC_STREAM_STATE  stStreamState[4];
		INT nVolume;								//��������
		INT nFreeSpaces;							//ʣ��ռ�
		INT niDiskStatic;							//0-�, 1-˯��, 2-�쳣
		INT nAlarmInStatic[16];						//0-û�б���, 1-�б���
		INT nAlarmOutStatic[16];					//0-û�б������, 1-�������
		INT nLocalDisplay;							//0-������ʾ, 1-û����ʾ
	}IPC_WORKSTATE,*LPIPC_WORKSTATE;
    
	//�Զ��۽����ò��� 
	typedef struct 
	{
		DWORD   dwAFMode;		    //�۽�ģʽ
		DWORD   dwAFDisLimit;		//�۽���������
		DWORD   dwPtzFactoryRange;  //����ѧ����
		DWORD   dwPtzCustomRange;   //����
		DWORD   dwDptzFactoryRange; //������ֱ���
		DWORD   dwDptzCustomRange;  //�û����õ������
	}IPC_AUTOFOCUS_CFG;


	//���հ汾��Ϣ 
	typedef struct 
	{
		BYTE  byManuInfo;			//��ʾ���ҵı���
		BYTE  byModInfo;			//��ʾ��Ʒ�ı���
		BYTE  byMsbVer;				//�汾�Ÿ�8λ
		BYTE  byLsbVer;				//�汾�ŵ�8λ
		BYTE  byReserved[4];
	}IPC_SHIELD_VERSION_CFG;

	//�豸�˿���Ϣ
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


	//��֧��3.0�豸��
	typedef struct tagIPC_HANDLEEXCEPTION_EX
	{
		DWORD	dwHandleType;		//�������ԣ���λ��ʾ����0λ-�澯�������1λ-�ϴ����ģ���2λ-�����������3λ-�ʼ�����4λ-FTP�ϴ�����5λ-¼�񣬵�6λ-PTZ����7λ-ץͼ
		BYTE    byAlarmOut[8];		//�������������ͨ����0-��������1-�����������λ��ʾ���ͨ��������byRelAlarmOut[0]==1��ʾ�������ͨ��1��byRelAlarmOut[1]==1��ʾ�������ͨ��2���������� 
		BYTE	byPtzCmd;			//������̨���0-�ޣ�1-Ԥ�õ㣬2-Ԥ�õ�Ѳ����3-����ɨ��
		DWORD   dwSeqNum;			//��ţ�Ԥ�õ����/Ѳ���켣���/����ɨ�����
		DWORD   dwPTZDelayTime;	//��̨��������ʱ�䣬��λΪS
		DWORD   dwDelayTime;		//�׹��������ʱ�䣬��λΪS
		BYTE    byReserved[7];	
	}IPC_HANDLEEXCEPTION_EX;

	typedef struct tagIPCSCHEDTIME
	{
		DWORD   dwStartHour;                                                        //��ʼʱ�䣺ʱ
		DWORD   dwStartMin;                                                         //��ʼʱ�䣺��
		DWORD   dwStopHour;                                                         //����ʱ�䣺ʱ 
		DWORD   dwStopMin;                                                          //����ʱ�䣺��
	}IPC_SCHEDTIME, *LPIPC_SCHEDTIME;
	 
	//�������������չ ��֧��3.0�豸��
	typedef struct tagIPC_ALARMINCFG_EX
	{
		DWORD                   dwSize;											//�ṹ���С
		BYTE                    sAlarmInName[IPC_MAX_NAME_LEN];					//���� 
		BYTE                    byAlarmType;										//���������ͣ�0-������1-���� 
		BYTE                    byAlarmInHandle;									//�Ƿ���0-������1-����
		BYTE                    byRes1[2];										//��������Ϊ0 
		DWORD					dwCheckTime;										//��λ�����룬���澯״̬��ʱ����
		IPC_HANDLEEXCEPTION_EX	struAlarmHandleType;								//����ʽ 
		IPC_SCHEDTIME			struAlarmTime[IPC_MAX_DAYS][IPC_MAX_TIME_SEC]; //����ʱ�����
	}IPC_ALARMINCFG_EX,*LPIPC_ALARMINCFG_EX;


	//������������ṹ�� ��֧��3.0�豸��
	typedef struct tagIPC_ALARMOUTCFG
	{
		DWORD                   dwSize;													 //�ṹ���С 
		BYTE					byEnable;												 //ʹ������
		BYTE                    sAlarmOutName[IPC_MAX_NAME_LEN];						 //���� 
		BYTE					byNormaState;											 //�������� 
		DWORD                   dwAlarmOutDelay;										 //����ź�״̬ά��ʱ��(��),0xffffff-Ϊ���ޣ����ֶ��رգ� 
		IPC_SCHEDTIME			struAlarmOutTime[IPC_MAX_DAYS][IPC_MAX_TIME_SEC];		 //�����������ʱ���
		BYTE                    byRes[14];												 //��������Ϊ0 
	}IPC_ALARMOUTCFG,*LPIPC_ALARMOUTCFG;

	//�������״̬�ṹ�� ��֧��3.0�豸��
	typedef struct tagIPC_ALARMOUTSTATUS
	{
		tagIPC_ALARMOUTSTATUS()
		{
			memset(this, 0, sizeof(tagIPC_ALARMOUTSTATUS));
		}
		BYTE      Output[8];																//��������ڵ�״̬��0-��Ч��1-��Ч 
	}IPC_ALARMOUTSTATUS,*LPIPC_ALARMOUTSTATUS;

	//PIR���������ṹ��,��֧��3.0�豸��
	typedef struct tagIPC_PIR_ALARMCFG
	{
		BYTE                     byAlarmName[32];										//�������� 
		BYTE                     byAlarmHandle;											//�Ƿ���0- ������1- ���� 
		BYTE					 bySensitive;											//0-100
		BYTE                     byRes1[3];												//���� 
		IPC_HANDLEEXCEPTION_EX	 struAlarmHandleType;									//����ʽ
		IPC_SCHEDTIME			 struAlarmTime[IPC_MAX_DAYS][IPC_MAX_TIME_SEC];		    //����ʱ�����
		BYTE                     byRes[63];												//���� 
	}IPC_PIR_ALARMCFG,*LPIPC_PIR_ALARMCFG;

	//������������������,��֧��3.0�豸��
	typedef struct tagIPC_AUX_ALARMCFG_UNION
	{ 
		IPC_PIR_ALARMCFG			  struPIRAlarm;		//PIR��������
	}IPC_AUX_ALARMCFG_UNION,*LPIPC_AUX_ALARMCFG_UNION;

	//�����������������ṹ��,��֧��3.0�豸��

	//������������ 
	#define   IPC_AUXALARM_UNKNOW     0		//δ֪ 
	#define   IPC_AUXALARM_PIR        1	//PIR���� 

	typedef struct  tagIPC_SINGLE_AUX_ALARMCFG
	{
		BYTE				    byAlarmType;										//���������ͣ���������±� GIPC_AUX_ALARM_TYPE
		BYTE					byRes1[3];											//���� 
		IPC_AUX_ALARMCFG_UNION	uAlarm;												//��������
		BYTE                    byRes[16];											//���� 
	}IPC_SINGLE_AUX_ALARMCFG,*LPIPC_SINGLE_AUX_ALARMCFG;

	#define  MAX_AUX_ALARM_NUM  8
	//������PIR�����������ṹ��,��֧��3.0�豸��
	typedef struct tagIPC_AUX_ALARMCFG
	{
		DWORD                    dwCount;											//�ṹ����� 
		IPC_SINGLE_AUX_ALARMCFG  struAlarm[MAX_AUX_ALARM_NUM];					//������������ 
		BYTE                     byRes[64];										//���� 
	}IPC_AUX_ALARMCFG,*LPIPC_AUX_ALARMCFG;

	typedef struct  tagIPC_POINT_FRAME                              //x��y��width��height�ǹ�һ����ֵ�����㷽��Ϊ: x = (x0 / W) * 8192 ;width = (w / W) * 8192    WΪ��Ƶ����Ŀ�� ;y = (y0 / H) * 8192 ;hight = (h / H) * 8192    WΪ��Ƶ����Ŀ�� ;������ʱ�� width��heightΪ0 ;��ѡWidth�� height����0���䱶�����󣬷�ѡ��ʱ��Width�� height��С��0���䱶�����С��xBottom=xTop+width,yBottom=yTop+hight
	{  
        INT    xTop ;                                               //������ʼ���x����
        INT    yTop ;                                               //������ʼ���y����
        INT    xBottom ;                                            //����������x����
        INT    yBottom ;                                            //����������y����
        INT    iType ;                                              //����ʽ:0-��ѡ 1-������С 2-���ַŴ� 
	}IPC_POINT_FRAME,*LPIPC_POINT_FRAME;

#pragma pack(pop)

typedef struct tagIPC_OSDParamA
{
	bool	text ;													//�Ƿ���ʾ������Ϣ��trueΪ��ʾ, falseΪ����ʾ
	long	text_x;													//������ʾ�����x���� ����Ƶ�ֱ��ʼ���
	long	text_y;													//������ʾ�����y���� ����Ƶ�ֱ��ʼ���
	long	text_lWidth;											//������ʾ����Ŀ� ����Ƶ�ֱ��ʼ���
	long	text_lHeight;											//������ʾ����ĸ� ����Ƶ�ֱ��ʼ���   
	LOGFONTA text_font ;											//���壬��׼��LOGFONT�ṹ ,SDK�Զ������û�Ӧ�ó����UNICODE��MultiBytes����
    COLORREF text_crColor ;             							//������ɫ
	wchar_t text_context[256] ;         							//�ı����ݣ�С��256���ַ�
	bool	picture;                    							//�Ƿ���ʾͼƬ��trueΪ��ʾ��falseΪ����ʾ
	long	pic_x;                      							//ͼƬ��ʾ�����x����  ����Ƶ�ֱ��ʼ���
	long	pic_y;													//ͼƬ��ʾ�����y����  ����Ƶ�ֱ��ʼ���
	long	pic_lWidth;												//ͼƬ��ʾ����Ŀ�     ����Ƶ�ֱ��ʼ���
	long	pic_lHeight;											//ͼƬ��ʾ����ĸ�     ����Ƶ�ֱ��ʼ���
	COLORREF pic_crMask ;               							//ͼƬ��ɫ
	long	pic_data_len ;              							//ͼƬ���ݳ���
    BYTE*	pic_data ;                  							//ͼƬ����
}IPC_OSDPARAMA,*LPIPC_OSDPARAMA;

typedef struct tagIPC_OSDParamW
{
    bool	text ;                      							//�Ƿ���ʾ������Ϣ��trueΪ��ʾ, falseΪ����ʾ
    long	text_x;                     							//������ʾ�����x����  ����Ƶ�ֱ��ʼ���
    long	text_y;													//������ʾ�����y����  ����Ƶ�ֱ��ʼ���
    long	text_lWidth;											//������ʾ����Ŀ�     ����Ƶ�ֱ��ʼ���
    long	text_lHeight;											//������ʾ����ĸ�     ����Ƶ�ֱ��ʼ���
    LOGFONTW text_font ;											//���壬��׼��LOGFONT�ṹ ,SDK�Զ������û�Ӧ�ó����UNICODE��MultiBytes����
    COLORREF text_crColor ;             							//������ɫ
    wchar_t text_context[256] ;										//�ı����ݣ�С��256���ַ�
    bool	picture;                    							//�Ƿ���ʾͼƬ��trueΪ��ʾ��falseΪ����ʾ
    long	pic_x;                      							//ͼƬ��ʾ�����x����   ����Ƶ�ֱ��ʼ���
    long	pic_y;													//ͼƬ��ʾ�����y����   ����Ƶ�ֱ��ʼ���
    long	pic_lWidth;												//ͼƬ��ʾ����Ŀ�      ����Ƶ�ֱ��ʼ���
    long	pic_lHeight;											//ͼƬ��ʾ����ĸ�      ����Ƶ�ֱ��ʼ���
    COLORREF pic_crMask ;               							//ͼƬ��ɫ
    long	pic_data_len ;              							//ͼƬ���ݳ���
    BYTE*	pic_data ;                  							//ͼƬ����
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