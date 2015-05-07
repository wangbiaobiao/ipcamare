/*------------------------------------------------------*/
/* The PDU definition between camera and client         */
/*                                                      */
/* client_camera_protocol.h                             */
/*                                                      */
/* Copyright (C) Gm-Innovation                          */
/* All rights reserved                                  */
/*                                                      */
/* Author                                               */
/*    Luke (zongluwu@hotmail.com)                       */
/*                                                      */
/* History                                              */
/*    07/07/2011  Create                                */
/*                                                      */
/*------------------------------------------------------*/
#ifndef __H_GM_CAMERCLIENT_PDU__
#define __H_GM_CAMERCLIENT_PDU__

const unsigned short Gm_Camera_Server_Port = 30000;

const BYTE Gm_Pdu_App_CameraSetting = 1;
const BYTE Gm_Pdu_App_Ptz = 2;
const BYTE Gm_Pdu_App_Log = 3;
const BYTE Gm_Pdu_App_RecordSetting = 4;
const BYTE Gm_Pdu_App_MediaProvider = 5;
const BYTE Gm_Pdu_App_MediaAccess = 6;
const BYTE Gm_Pdu_App_Event = 7;

/*=========================================================================================================*
                                          Definition of Commands
 *=========================================================================================================*/

/*
    command id: 4 byte, command id.
    unique id : 4 byte, unique id of this sending command, ack should use the same unique id.
    result    : 4 byte, error code.
*/

/*-------------------------------------------------------*
                 commands for properties
 *-------------------------------------------------------*/
#define GM_COMMAND_PROPERTY_BASE             0x00000000

/*
   send: PDU << GM_COMMAND_GET_PROPERTY
             << unique id
             << property id 0
             ...
             << property id n
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_GET_PROPERTY)
             >> unique id
             >> result
             >> property id 0 >> data 0
             ...
             >> property id n >> data n
*/
#define GM_COMMAND_GET_PROPERTY              (GM_COMMAND_PROPERTY_BASE + 0)

/*
   send: PDU << GM_COMMAND_SET_PROPERTY
             << unique id
             << property id 0 << data 0
             ...
             << property id n << data n
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_SET_PROPERTY)
             >> unique id
             >> result
*/
#define GM_COMMAND_SET_PROPERTY              (GM_COMMAND_PROPERTY_BASE + 1)

/*-------------------------------------------------------*
                 commands for events
 *-------------------------------------------------------*/
/*
    event index  : 4 byte, index of event.
    event count  : 4 byte, count of events.
    event enabled: 4 byte, 0: disabled, 1: enabled.
*/
#define GM_COMMAND_EVENT_BASE                0x00001000

/*
   send: PDU << GM_COMMAND_GET_EVENT_COUNT
             << unique id
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_GET_EVENT_COUNT)
             >> unique id
             >> result
             >> event count
*/
#define GM_COMMAND_GET_EVENT_COUNT           (GM_COMMAND_EVENT_BASE + 0)

/*
   send: PDU << GM_COMMAND_GET_EVENT
             << unique id
             << event index
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_GET_EVENT)
             >> unique id
             >> result
             >> event PDU
*/
#define GM_COMMAND_GET_EVENT                 (GM_COMMAND_EVENT_BASE + 1)

/*
   send: PDU << GM_COMMAND_ADD_EVENT
             << unique id
             << event PDU
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_ADD_EVENT)
             >> unique id
             >> result
             >> event index
*/
#define GM_COMMAND_ADD_EVENT                 (GM_COMMAND_EVENT_BASE + 2)

/*
   send: PDU << GM_COMMAND_UPDATE_EVENT
             << unique id
             << event index
             << event PDU
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_UPDATE_EVENT)
             >> unique id
             >> result
*/
#define GM_COMMAND_UPDATE_EVENT              (GM_COMMAND_EVENT_BASE + 3)

/*
   send: PDU << GM_COMMAND_ENABLE_EVENT
             << unique id
             << event index
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_ENABLE_EVENT)
             >> unique id
             >> result
*/
#define GM_COMMAND_ENABLE_EVENT              (GM_COMMAND_EVENT_BASE + 4)

/*
   send: PDU << GM_COMMAND_DISABLE_EVENT
             << unique id
             << event index
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_DISABLE_EVENT)
             >> unique id
             >> result
*/
#define GM_COMMAND_DISABLE_EVENT             (GM_COMMAND_EVENT_BASE + 5)

/*
   send: PDU << GM_COMMAND_IS_EVENT_ENABLED
             << unique id
             << event index
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_IS_EVENT_ENABLED)
             >> unique id
             >> result
             >> event enabled
*/
#define GM_COMMAND_IS_EVENT_ENABLED          (GM_COMMAND_EVENT_BASE + 6)

/*-------------------------------------------------------*
                 commands for DPTZ
 *-------------------------------------------------------*/
#define GM_COMMAND_DPTZ_BASE                 0x00002000

/*
   send: PDU << GM_COMMAND_DPTZ_ZOOM
             << unique id
             << stream id
             << factor
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_DPTZ_ZOOM)
             >> unique id
             >> result

   stream id: 4 byte, 0~3
   factor   : 4 byte, 0~11
*/
#define GM_COMMAND_DPTZ_ZOOM                 (GM_COMMAND_DPTZ_BASE + 0)

/*
   send: PDU << GM_COMMAND_DPTZ_cmd
             << unique id
             << stream id
             << step
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_DPTZ_cmd)
             >> unique id
             >> result

   stream id: 4 byte, 0~3
   step     : 4 byte, 0~1000
*/
#define GM_COMMAND_DPTZ_UP                   (GM_COMMAND_DPTZ_BASE + 1)
#define GM_COMMAND_DPTZ_DOWN                 (GM_COMMAND_DPTZ_BASE + 2)
#define GM_COMMAND_DPTZ_LEFT                 (GM_COMMAND_DPTZ_BASE + 3)
#define GM_COMMAND_DPTZ_RIGHT                (GM_COMMAND_DPTZ_BASE + 4)

/*
   send: PDU << GM_COMMAND_DPTZ_cmd_PRESET
             << unique id
             << stream id
             << number
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_DPTZ_cmd_PRESET)
             >> unique id
             >> result

   stream id: 4 byte, 0~3
   number   : 4 byte, preset number, 1~9
*/
#define GM_COMMAND_DPTZ_SET_PRESET           (GM_COMMAND_DPTZ_BASE + 5)
#define GM_COMMAND_DPTZ_CLEAR_PRESET         (GM_COMMAND_DPTZ_BASE + 6)
#define GM_COMMAND_DPTZ_GOTO_PRESET          (GM_COMMAND_DPTZ_BASE + 7)

/*
   send: PDU << GM_COMMAND_DPTZ_CLEAR_ALL_PRESET
             << unique id
             << stream id
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_DPTZ_CLEAR_ALL_PRESET)
             >> unique id
             >> result

   stream id: 4 byte, 0~3
*/
#define GM_COMMAND_DPTZ_CLEAR_ALL_PRESET     (GM_COMMAND_DPTZ_BASE + 8)

/*
   send: PDU << GM_COMMAND_DPTZ_GOTO_HOME
             << unique id
             << stream id
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_DPTZ_GOTO_HOME)
             >> unique id
             >> result

   stream id: 4 byte, 0~3
*/
#define GM_COMMAND_DPTZ_GOTO_HOME            (GM_COMMAND_DPTZ_BASE + 9)

/*-------------------------------------------------------*
                 commands for PTZ
 *-------------------------------------------------------*/
#define GM_COMMAND_PTZ_BASE                  0x00003000

/*
#define GM_COMMAND_PTZ_AUTO_SCAN             (GM_COMMAND_PTZ_BASE + 0)
#define GM_COMMAND_PTZ_MANUAL_SCAN           (GM_COMMAND_PTZ_BASE + 1)
#define GM_COMMAND_PTZ_CAMERA_ON             (GM_COMMAND_PTZ_BASE + 2)
#define GM_COMMAND_PTZ_CAMERA_OFF            (GM_COMMAND_PTZ_BASE + 3)
*/

/*
   send: PDU << GM_COMMAND_PTZ_cmd
             << unique id
             << on_off
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_PTZ_cmd)
             >> unique id
             >> result

   on_off: 4 byte, 0 : on, 1 : off
*/
#define GM_COMMAND_PTZ_IRIS_CLOSE            (GM_COMMAND_PTZ_BASE + 4)
#define GM_COMMAND_PTZ_IRIS_OPEN             (GM_COMMAND_PTZ_BASE + 5)
#define GM_COMMAND_PTZ_FOCUS_NEAR            (GM_COMMAND_PTZ_BASE + 6)
#define GM_COMMAND_PTZ_FOCUS_FAR             (GM_COMMAND_PTZ_BASE + 7)
#define GM_COMMAND_PTZ_ZOOM_WIDE             (GM_COMMAND_PTZ_BASE + 8)
#define GM_COMMAND_PTZ_ZOOM_TELE             (GM_COMMAND_PTZ_BASE + 9)

#define GM_COMMAND_PTZ_UP                    (GM_COMMAND_PTZ_BASE + 10)
#define GM_COMMAND_PTZ_DOWN                  (GM_COMMAND_PTZ_BASE + 11)
#define GM_COMMAND_PTZ_LEFT                  (GM_COMMAND_PTZ_BASE + 12)
#define GM_COMMAND_PTZ_RIGHT                 (GM_COMMAND_PTZ_BASE + 13)

/*
   send: PDU << GM_COMMAND_PTZ_SET_PAN_SPEED
             << unique id
             << speed
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_PTZ_SET_PAN_SPEED)
             >> unique id
             >> result

   speed: 4 byte, 0x00(stop)~0x3f(high speed), PELCO-D : 0xff(turbo), PELCO-P : 0x40(turbo)
*/
#define GM_COMMAND_PTZ_SET_PAN_SPEED         (GM_COMMAND_PTZ_BASE + 14)

/*
   send: PDU << GM_COMMAND_PTZ_SET_TILT_SPEED
             << unique id
             << speed
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_PTZ_SET_TILT_SPEED)
             >> unique id
             >> result

   speed: 4 byte, 0x00(stop)~0x3f(maximum speed)
*/
#define GM_COMMAND_PTZ_SET_TILT_SPEED        (GM_COMMAND_PTZ_BASE + 15)

/*
   send: PDU << GM_COMMAND_PTZ_cmd_PRESET
             << unique id
             << number
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_PTZ_cmd_PRESET)
             >> unique id
             >> result

   number: 4 byte, preset number, PELCO-D : 1~32, PELCO-P : 1~255
*/
#define GM_COMMAND_PTZ_SET_PRESET            (GM_COMMAND_PTZ_BASE + 16)
#define GM_COMMAND_PTZ_CLEAR_PRESET          (GM_COMMAND_PTZ_BASE + 17)
#define GM_COMMAND_PTZ_GOTO_PRESET           (GM_COMMAND_PTZ_BASE + 18)

/*
   send: PDU << GM_COMMAND_PTZ_CLEAR_ALL_PRESET
             << unique id
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_PTZ_CLEAR_ALL_PRESET)
             >> unique id
             >> result
*/
#define GM_COMMAND_PTZ_CLEAR_ALL_PRESET      (GM_COMMAND_PTZ_BASE + 19)

/*
   send: PDU << GM_COMMAND_PTZ_GOTO_HOME
             << unique id
   recv: PDU >> GM_COMMAND_ACK(GM_COMMAND_PTZ_GOTO_HOME)
             >> unique id
             >> result
*/
#define GM_COMMAND_PTZ_GOTO_HOME             (GM_COMMAND_PTZ_BASE + 20)

/*-------------------------------------------------------*
                 commands for Logs
 *-------------------------------------------------------*/
#define GM_COMMAND_LOG_BASE                  0x00004000

/*-------------------------------------------------------*
                 commands for media provider
 *-------------------------------------------------------*/
#define GM_COMMAND_MEDIA_PROVIDER_BASE       0x00005000

/*-------------------------------------------------------*
                 commands for media access
 *-------------------------------------------------------*/
#define GM_COMMAND_MEDIA_ACCESS_BASE         0x00006000

/*-------------------------------------------------------*
                 commands for ACK
 *-------------------------------------------------------*/
#define GM_COMMAND_ACK_BASE                  0x80000000
#define GM_COMMAND_ACK(cmd)                  (GM_COMMAND_ACK_BASE | (cmd))


/*=========================================================================================================*
                                          Definition of Properties
 *=========================================================================================================*/
#define STREAM_ID_BASE                       0x0000
#define STREAM_ID(id)                        (STREAM_ID_BASE + (id))

#define INVALIDATE_PROPERTY                  0xffffffff

/*-------------------------------------------------------*
                 Properties for IMAGE
 *-------------------------------------------------------*/
#define IMAGE_PROPERTY_BASE                  0x00000000

/*
    data : 4 byte
           0 : anti-flicker 50M
           1 : anti-flicker 60M
           2 : auto
           3 : keep
*/
#define IMAGE_PROPERTY_EXPOSURE_MODE         (IMAGE_PROPERTY_BASE + 0)


#define IMAGE_PROPERTY_SHUTTER_MIN           (IMAGE_PROPERTY_BASE + 1)
#define IMAGE_PROPERTY_SHUTTER_MAX           (IMAGE_PROPERTY_BASE + 2)


/*
    data : 4 byte
           30db, 36db, 42db, 48db, 54db, 60db
*/
#define IMAGE_PROPERTY_MAX_GAIN              (IMAGE_PROPERTY_BASE + 3)


#define IMAGE_PROPERTY_SLOW_SHUTTER          (IMAGE_PROPERTY_BASE + 4)
#define IMAGE_PROPERTY_VIN_FPS               (IMAGE_PROPERTY_BASE + 5)
#define IMAGE_PROPERTY_AE_PREFERENCE         (IMAGE_PROPERTY_BASE + 6)


/*
    data : 4 byte
           0 : off
           1 : on
*/
#define IMAGE_PROPERTY_DN_MODE               (IMAGE_PROPERTY_BASE + 7)


#define IMAGE_PROPERTY_METERING_MODE         (IMAGE_PROPERTY_BASE + 8)

/*
    data : 4 byte
           0 : off
           1 : on
*/
#define IMAGE_PROPERTY_BACKLIGHT_COMP        (IMAGE_PROPERTY_BASE + 9)

/*
    data : 4 byte
           0 : off
           1 : on
*/
#define IMAGE_PROPERTY_LOCAL_EXPOSURE        (IMAGE_PROPERTY_BASE + 10)

/*
    data : 4 byte
           0 ~ 255
*/
#define IMAGE_PROPERTY_MCTF_STRENGTH         (IMAGE_PROPERTY_BASE + 11)

/*
    data : 4 byte
           0 : off
           1 : on
*/
#define IMAGE_PROPERTY_DC_IRIS               (IMAGE_PROPERTY_BASE + 12)

/*
    data : 4 byte
           1 ~ 900
*/
#define IMAGE_PROPERTY_DC_IRIS_DUTY          (IMAGE_PROPERTY_BASE + 13)

/*
    data : 4 byte
           25 ~ 400
*/
#define IMAGE_PROPERTY_AE_TARGET_RATION      (IMAGE_PROPERTY_BASE + 14)

/*
    data : 4 byte
           0 ~ 255
*/
#define IMAGE_PROPERTY_SATURATION            (IMAGE_PROPERTY_BASE + 15)

/*
    data : 4 byte
           -255 ~ 255
*/
#define IMAGE_PROPERTY_BRIGHTNESS            (IMAGE_PROPERTY_BASE + 16)

/*
    data : 4 byte
           -15 ~ 15
*/
#define IMAGE_PROPERTY_HUE                   (IMAGE_PROPERTY_BASE + 17)

/*
    data : 4 byte
           0 ~ 255
*/
#define IMAGE_PROPERTY_CONTRAST              (IMAGE_PROPERTY_BASE + 18)

/*
    data : 4 byte
           0 ~ 255
*/
#define IMAGE_PROPERTY_SHARPNESS             (IMAGE_PROPERTY_BASE + 19)


/*
    data : 4 byte
           0   : auto
           1   : incandescent
           2   : d4000
           3   : d5000
           4   : sunny
           5   : cloudy
           6   : flash
           7   : fluorescent
           8   : fluorescent high
           9   : under water
           10  : custom
           100 : hold
*/
#define IMAGE_PROPERTY_WBC                   (IMAGE_PROPERTY_BASE + 20)


#define IMAGE_PROPERTY_LENS_TYPE             (IMAGE_PROPERTY_BASE + 21)
#define IMAGE_PROPERTY_AF_MODE               (IMAGE_PROPERTY_BASE + 22)
#define IMAGE_PROPERTY_AF_TITLE_MODE         (IMAGE_PROPERTY_BASE + 23)
#define IMAGE_PROPERTY_ZM_DIST               (IMAGE_PROPERTY_BASE + 24)
#define IMAGE_PROPERTY_FS_DIST               (IMAGE_PROPERTY_BASE + 25)
#define IMAGE_PROPERTY_FS_NEAR               (IMAGE_PROPERTY_BASE + 26)
#define IMAGE_PROPERTY_FS_FAR                (IMAGE_PROPERTY_BASE + 27)


#define IMAGE_PROPERTY_AGC                   (IMAGE_PROPERTY_BASE + 28)
#define IMAGE_PROPERTY_SHUTTER               (IMAGE_PROPERTY_BASE + 29)



/*-------------------------------------------------------*
                 Properties for ENCODER
 *-------------------------------------------------------*/
#define ENCODE_PROPERTY_BASE                 0x00001000

/*
    data : 4 byte
           0 : disable
           1 : enable
*/
#define ENCODE_PROPERTY_VIN_ENABLE          (ENCODE_PROPERTY_BASE + 0)

/*
    data : 4 byte
           0x0000 : AMBA_VIDEO_MODE_AUTO
           0xFFF4 : MBA_VIDEO_MODE_720P
           0xFFF8 : AMBA_VIDEO_MODE_1080P
*/
#define ENCODE_PROPERTY_VIN_MODE            (ENCODE_PROPERTY_BASE + 1)

/*
    data : 4 byte
*/
#define ENCODE_PROPERTY_VIM_FRAMERATE       (ENCODE_PROPERTY_BASE + 2)

/*
    data : 4 byte
           0, 1, 2, 3, 4
*/
#define ENCODE_PROPERTY_VIN_MIRROR          (ENCODE_PROPERTY_BASE + 3)

/*
    data : 4 byte
           0, 1, 2, 3, 4
*/
#define ENCODE_PROPERTY_VIN_BAYER           (ENCODE_PROPERTY_BASE + 4)


#define ENCODE_PROPERTY_VOUT_TYPE           (ENCODE_PROPERTY_BASE + 5)
#define ENCODE_PROPERTY_VOUT_MODE           (ENCODE_PROPERTY_BASE + 6)

/*
    data : 4 byte
           0, 1, 2
*/
#define ENCODE_PROPERTY_ENC_MODE            (ENCODE_PROPERTY_BASE + 7)


/*
    data : 1 byte
           Privacy Mask
           0 ~ 100
*/
#define ENCODE_PROPERTY_PM_LEFT             (ENCODE_PROPERTY_BASE + 8)

/*
    data : 1 byte
           Privacy Mask
           0 ~ 100
*/
#define ENCODE_PROPERTY_PM_TOP              (ENCODE_PROPERTY_BASE + 9)

/*
    data : 1 byte
           Privacy Mask
           0 ~ 100
*/
#define ENCODE_PROPERTY_PM_W                (ENCODE_PROPERTY_BASE + 10)

/*
    data : 1 byte
           Privacy Mask
           0 ~ 100
*/
#define ENCODE_PROPERTY_PM_H                (ENCODE_PROPERTY_BASE + 11)


/*
    data : 4 byte
           Privacy Mask
           0 : black
           1 : red
           2 : blue
           3 : green
           4 : yellow
           5 : magenta
           6 : cyan
           7 : white
*/
#define ENCODE_PROPERTY_PM_COLOR            (ENCODE_PROPERTY_BASE + 12)

/*
    data : 4 byte
           Privacy Mask
           1 : disable
           0 : enable
           3 : delete

*/
#define ENCODE_PROPERTY_PM_ACTION           (ENCODE_PROPERTY_BASE + 13)

#define ENCODE_PROPERTY_ENCODE_TYPE         (ENCODE_PROPERTY_BASE + 14)
#define ENCODE_PROPERTY_ENCODE_FBS          (ENCODE_PROPERTY_BASE + 15)
#define ENCODE_PROPERTY_BRC_MODE            (ENCODE_PROPERTY_BASE + 16)
#define ENCODE_PROPERTY_CBR_AVG_BPS         (ENCODE_PROPERTY_BASE + 17)
#define ENCODE_PROPERTY_VBR_MIN_BPS         (ENCODE_PROPERTY_BASE + 18)
#define ENCODE_PROPERTY_VBR_NAX_BPS         (ENCODE_PROPERTY_BASE + 19)



/*
    properties for each stream
*/
#define ENCODE_STREAM_PROPERTY_BASE          0x00002000

/*
    data : 1 byte
           0 : disable
           1 : enable
*/
#define ENCODE_PROPERTY_SN_DPTZ(id)          ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 0))

/*
    data : 1 byte
           0 : off
           1 : h264
           2 : mpeg
*/
#define ENCODE_PROPERTY_SN_TYPE(id)          ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 1))

/*
    data : 1 byte
           0 : normal
           1 : horiznal mirror
           2 : vertical mirror
           3 : rotate by 90
           4 : rotate by 180
           5 : rotate by 270
*/
#define ENCODE_PROPERTY_SN_FLIP_ROTATE(id)   ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 2))


/*
    data : 2 byte
           1920, 1280, 800, 720, 640, 352
*/
#define ENCODE_PROPERTY_SN_WIDTH(id)         ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 3))

/*
    data : 2 byte
           1080, 1024, 960, 720, 600, 576, 480, 288, 240,
*/
#define ENCODE_PROPERTY_SN_HEIGHT(id)        ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 4))

/*
    data : 4 byte
           8533333  : 60fps
           17066667 : 30fps
           20480000 : 25fps
*/
#define ENCODE_PROPERTY_SN_ENC_FPS(id)       ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 5))

/*
    data : 4 byte
           0 : off
           1 : enable
*/
#define ENCODE_PROPERTY_SN_H264_ID(id)       ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 6))

/*
    data : 1 byte
           1 ~ 3
*/
#define ENCODE_PROPERTY_SN_M(id)             ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 7))

/*
    data : 1 byte
           1 ~ 255
*/
#define ENCODE_PROPERTY_SN_N(id)             ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 8))


/*
    data : 1 byte
           1 ~ 100
*/
#define ENCODE_PROPERTY_SN_IDR_INTERVAL(id)  ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 9))

/*
    data : 1 byte
           0 : singal model
           1 : advance model
*/
#define ENCODE_PROPERTY_SN_GOP_MODEL(id)     ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 10))

/*
    data : 1 byte
           0 : main
           1 : base line
*/
#define ENCODE_PROPERTY_SN_PROFILE(id)       ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 11))


/*
    data : 1 byte
           0 : cbr
           1 : vbr
*/
#define ENCODE_PROPERTY_SN_BRC(id)           ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 12))


#define ENCODE_PROPERTY_SN_CBR_AVG_BPS(id)   ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 13))
#define ENCODE_PROPERTY_SN_VBR_MIN_BPS(id)   ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 14))
#define ENCODE_PROPERTY_SN_VBR_MAX_BPS(id)   ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 15))


/*
    data : 1 byte
           QUALITY 0f mpeg
           0 ~ 100
*/
#define ENCODE_PROPERTY_SN_QUALITY(id)       ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 16))

/*
    data : 4 byte
           0 : disable
           1 : enable
*/
#define ENCODE_PROPERTY_SN_BMP_ENABLE(id)    ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 17))

/*
    data : 4 byte
           0 : disable
           1 : enable
*/
#define ENCODE_PROPERTY_SN_TIME_ENABLE(id)   ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 18))

/*
    data : 4 byte
           0 : disable
           1 : enable
*/
#define ENCODE_PROPERTY_SN_TEXT_ENABLE(id)   ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 19))

/*
    data : String
           max length 26
*/
#define ENCODE_PROPERTY_SN_TEXT(id)          ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 20))


#define ENCODE_PROPERTY_STREAM_START(id)     ((STREAM_ID(id) << 16) | (ENCODE_STREAM_PROPERTY_BASE + 21))

/*=========================================================================================================*
                                          Definition of Events
 *=========================================================================================================*/

/*
event PDU:
PDU << event name                 String, name of the event
    << stream id                  4 byte, stream id, the value should be in (0, 1, 2, 3)
    << start time                 4 byte, start time of this event in one day, units is second
    << end time                   4 byte, end time of this event in one day, units is second
    << weekdays                   4 byte, mark the valid days
    << trigger type               4 byte, id of trigger type
    << trigger data 0
    ...                           0 or n byte, see the table of trigger type
    << trigger data n
    << action number              4 byte, number of actions
    << action type 0              4 byte, id of action type
    << action data 0.0
    ...                           0 or n byte, see the table of action type
    << action data 0.m
    ...
    << action tyoe n
    << action data n.0
    ...
    << action data n.m
*/

#define WEEKDAYS_NONE      (0)
#define WEEKDAYS_SUNDAY    (1 << 1)
#define WEEKDAYS_MONDAY    (1 << 2)
#define WEEKDAYS_TUESDAY   (1 << 3)
#define WEEKDAYS_WENSDAY   (1 << 4)
#define WEEKDAYS_THURSDAY  (1 << 5)
#define WEEKDAYS_FRIDAY    (1 << 6)
#define WEEKDAYS_SATURDAY  (1 << 7)

/*-------------------------------------------------------*
                   trigger type
 *-------------------------------------------------------*/
/*
  Invalid trigger type.
  Trigger data:
    None.
*/
#define EVENT_TRIGGERTYPE_NONE           0

/*
  Execute the actions in the valid time.
  Trigger data:
    None.
*/
#define EVENT_TRIGGERTYPE_SCHEDULED      1

/*
  Execute the actions when the input port be low or high in the valid time.
  Trigger data:
    data 0: 4 byte, index of the input port
    data 1: 4 byte, 0 : low  1 : high, when the input port reach this status, execute the actions
*/
#define EVENT_TRIGGERTYPE_INPUTPORT      2


/*
  Execute the actions when the camera images become unusual in the valid time.
  Trigger data:
    None.
*/
#define EVENT_TRIGGERTYPE_BLACKSCREEN    3

/*
  Execute the actions when montion-detect trigged in the valid time.
  Trigger data:
    None.
*/
#define EVENT_TRIGGERTYPE_MONTIONDETECT  4

/*
  Execute the actions when camera boot up, this trigger will ignore the event time.
  Trigger data:
    None.
*/
#define EVENT_TRIGGERTYPE_DEVICEBOOT     5

/*
  Execute the actions when camera shutdown, this trigger will ignore the event time.
  Trigger data:
    None.
*/
#define EVENT_TRIGGERTYPE_DEVICESHUTDOWN 6

/*-------------------------------------------------------*
                   action type
 *-------------------------------------------------------*/
/*
  Invalid action type.
  Action data:
    None.
*/
#define EVENT_ACTIONTYPE_NONE           0


/*
  Send an E-mail when the event trigged.
  Action data:
    data 0: String, address of the E-mail, use ';' to separate each address.
    data 1: String, subject of the E-mail.
    data 2: String, content of the E-mail.
*/
#define EVENT_ACTIONTYPE_NOTIFY_EMAIL   1

/*
  Start record when the event trigged.
  Action data:
    data 0: 4 byte, record length, units is second.
    data 1: 4 byte, file location id.
    data 2: String, file path, absolute file path is "/[Device Mount Point]/[File Path]/[Default File Name]"
*/
#define EVENT_ACTIONTYPE_RECORD         2

/*
    File location id:
*/
/* invlid file location. */
#define RECORD_FILELOCATION_NONE      0
/* record the stream on FTP site, data 2 will be ignored, but client should still have this field. */
#define RECORD_FILELOCATION_FTP       1
/* record the stream on SD card. */
#define RECORD_FILELOCATION_SDCARD    2
/* record the stream on hard disk. */
#define RECORD_FILELOCATION_HARDDISK  3

/*
  Output low or high via output port when the event trigged.
  Action data:
    data 0: 4 byte, index of the output port.
    data 1: 4 byte, 0 : low  1 : high, output status.
*/
#define EVENT_ACTIONTYPE_PORTOUTPUT     3

/*
  Move to the preferences of DPTZ when the event trigged.
  Action data:
    data 0: 4 byte, index of the preference of DPTZ.
*/
#define EVENT_ACTIONTYPE_DPTZ           4

/*
  Move to the preferences of PTZ when the event trigged.
  Action data:
    data 0: 4 byte, index of the preference of PTZ.
*/
#define EVENT_ACTIONTYPE_PTZ            5

/*=========================================================================================================*
                                         Definition of Result
 *=========================================================================================================*/
#define PDU_RESULT_SUCCESS              0
#define PDU_RESULT_FAILED               1
#define PDU_RESULT_UNSUPPORTED          2

#endif
