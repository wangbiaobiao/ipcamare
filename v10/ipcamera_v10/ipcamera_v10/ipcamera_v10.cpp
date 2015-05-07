// ipcamera_v10.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "IPCDefine.h"
#include "IPCSdkDefines.h"
#include "IPCamera.h"
#include <string>
#include <map>
#include <algorithm> 
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2\opencv.hpp>

using namespace std;
string ws2s(wstring& inputws);
string WChar2Ansi(LPCWSTR pwszSrc);
extern"C"_declspec(dllexport) int close_camera(LPWSTR ip);
extern"C"_declspec(dllexport) int stop_preview(HWND myhwnd);
static bool isinial=false;


class mydevice
{
	
public: 
	mydevice(const wstring &t_ip)
	{
		ip=t_ip;
		myipchandle=NULL;
		is_used=false;
	}
	int open_device(const string &tuser,const string &tpassword){
		if (myipchandle!=NULL)
		{
			return 1;
		}
		ipcHandle t_ipchandle = ipcCreateDevice();
		int myport =30000;
		DWORD time = 5000;
		string sip=ws2s(this->ip);
		ipcConnect(t_ipchandle,tuser.c_str(),tpassword.c_str(),sip.c_str(),myport);
		if (ipcWaitConnected(t_ipchandle,time)==0)
		{
			myipchandle=t_ipchandle;
			return 0;
		}
		else 
			return -1;

	}
	int add_pre(HWND hwnd_id,int weight)
	{
		if (myipchandle==NULL)
		{
			return -2;
		}
		playHandle myplayHandle;
		myplayHandle=ipcCreateLivePlay(myipchandle,hwnd_id,0,0);
		RECT rect;
		rect.top = 0;
		rect.bottom = weight*720/1280;
		rect.left = 0;
		rect.right = weight;
		int issetrect=ipcSetDisplayRect(myplayHandle,rect);
		int isstartPlay=ipcStartLivePlay(myplayHandle); 
		if (isstartPlay==0)
		{
			myplayhand_map[hwnd_id]=myplayHandle;
			return 0;
		}
		else
			return -1;
	}
	int close_pre(HWND hwnd_id)
	{
		if (myipchandle==NULL)
		{
			return -2;
		}
		if (myplayhand_map.find(hwnd_id)==myplayhand_map.end())
		{
			return -3;
		}
		else
		{
			return ipcDestroyLivePlay(myipchandle,myplayhand_map[hwnd_id]);
		}
	}
	int set_osd(LPWSTR myosd_num)
	{
		if (myipchandle==NULL)
		{
			return -2;
		}
		string temp=ws2s(wstring(myosd_num));
		LPIPC_DEVICEOSD myosd=new tagIPC_DEVICEOSD;
		myosd->bShow=TRUE;
		myosd->streamID=0;
		myosd->textBold=0;
		myosd->textColor=1;
		strcpy(myosd->textContent,temp.c_str());
		myosd->textSize=48;
		myosd->x=3;
		myosd->y=3;
		int res_code=ipcSetDeviceOSD(myipchandle,myosd);
		return res_code;
	}
	int get_gray(LPCWSTR filename)
	{
		if (myipchandle==NULL)
		{
			return -2;
		}
		string gray_name_w=ws2s(wstring(filename));
		string gray_name_temp="";
		string gray_name_save;
		int mask=0;
		for (int i=0;i<gray_name_w.size();++i)
		{
			if (gray_name_w[i]=='\\')
			{
				if (mask == 0)
				{
					mask=1;
				}
				else
				{
					gray_name_temp+=gray_name_w[i];
					mask=0;
				}
			}
			else
			{
				gray_name_temp+=gray_name_w[i];
			}
		}
		gray_name_save=gray_name_temp;

		int temp=-1;
		for (auto playhandle:myplayhand_map)
		{
			if (ipcCapturePicture(playhandle.second,2,filename)==0)
			{
				temp=0;				
				gray_name_save.replace(gray_name_save.find("\\\\"),2,"\\gray\\");
				IplImage * img = cvLoadImage(gray_name_temp.c_str());  
				if(!img)  
				{  
					//fprintf(stderr, "Can not load image %s\n", imagename);  
					return -3;  
				}  

				if( !img->imageData ) // 检查是否正确载入图像  
				{return -3;}  
				IplImage* img1 = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);//创建目标图像  
				cvCvtColor(img,img1,CV_BGR2GRAY);//cvCvtColor(src,des,CV_BGR2GRAY)  
				cvSaveImage(gray_name_temp.c_str(),img1);
				cvReleaseImage(&img);  
				cvReleaseImage(&img1);  
				break;
			}
		}
		return temp;
	}
	int get_pho(LPCWSTR filename)
	{
		if (myipchandle==NULL)
		{
			return -2;
		}
		int temp=-1;
		for (auto playhandle:myplayhand_map)
		{
			if (ipcCapturePicture(playhandle.second,2,filename)==0)
			{
				temp=0;

				break;
			}
		}
		return temp;
	}
	~mydevice()
	{
		for (auto temp_play:myplayhand_map)
		{
			ipcStopLivePlay(myipchandle);
			ipcDestroyLivePlay(myipchandle,temp_play.second);
		}
		ipcDisConnect(myipchandle);
		ipcDestroyDevice(myipchandle);
	}
	bool is_used;
private:

	wstring ip;
	map<HWND,playHandle> myplayhand_map;
	ipcHandle myipchandle;
};
class Camopt 
{
public:
	static Camopt *inst()
	{
		if (singleins==NULL)
		{
			singleins=new Camopt();
			return singleins;
		}
		else 
			return singleins;
	}
	int checkavliable(wstring ip)
	{
		
		if (isinial==false)
		{
			return -10;
		}
		if (mymap.find(ip)!=mymap.end())
		{
			if(mymap[ip]->is_used==true)
			{
				OutputDebugStringA("using");
				return 1;//using 
			}
			else
				OutputDebugStringA("not use");
				return 0;//ok
		}
			return -2; //not found
	}
	int opencamera(LPWSTR ip, LPWSTR  user ,LPWSTR  password)
	{
		if (isinial==false)
		{
			return -10;
		}
		else
		{
			string myip=ws2s((wstring )ip);
			string mypassword=ws2s((wstring )password);
			string myuser=ws2s((wstring )user);
			if (mymap.find(ip)==mymap.end())
			{
				mydevice *t_device=new mydevice(ip);
				mymap[ip]=t_device;
			}
			if (mymap[ip]->is_used==true)
			{
				return 1;
			}
			else
			{
				mymap[ip]->is_used=true;
				int  res_code=mymap[ip]->open_device(myuser,mypassword);//费时操作
				mymap[ip]->is_used=false;
				return res_code;
			}
		}
	}
	int openpreview(LPWSTR ip,HWND myhwnd,int weight) 
	{
		if (checkavliable(ip)!=0)
		{
			return checkavliable(ip);//摄像头未连接
		}
		else
		{
			if (my_hwnd_map.find(myhwnd) != my_hwnd_map.end())
			{
				stoppreview(myhwnd);
			}
			mymap[ip]->is_used=true;
			my_hwnd_map[myhwnd]=ip;
			int res_code= mymap[ip]->add_pre(myhwnd,weight);
			mymap[ip]->is_used=false;
			return res_code;
		}
	}
	int stoppreview(HWND myhwnd)
	{
		if(my_hwnd_map.find(myhwnd)==my_hwnd_map.end())
		{
			return -2;
		}
		else {
			wstring ip=my_hwnd_map[myhwnd];
			if (checkavliable(ip)!=0)
			{
				return checkavliable(ip);//摄像头未连接
			}
			else
			{
				mymap[ip]->is_used=true;
				int res_code=mymap[ip]->close_pre(myhwnd);
				mymap[ip]->is_used=false;
				return res_code;
			}
		}
	}
	int closecamera(LPWSTR ip)
	{
		if (checkavliable(ip)!=0)
		{
			return checkavliable(ip);//摄像头未连接
		}
		else
		{
			delete mymap[ip];
			mymap.erase(mymap.find(ip));
			return 1;
		}	
	}
	int photofile(LPWSTR ip,LPCWSTR filename)
	{
		if (checkavliable(ip)!=0)
		{
			return checkavliable(ip);//摄像头未连接
		}
		else
		{
			mymap[ip]->is_used=true;
			int res_code= mymap[ip]->get_pho(filename);
			mymap[ip]->is_used=false;
			return res_code;
			//mymap[ip]->get_pho(filename);
		}
	}
	int photofile_gray(LPWSTR ip,LPCWSTR filename)
	{
		if (checkavliable(ip)!=0)
		{
			return checkavliable(ip);//摄像头未连接
		}
		else
		{		
			mymap[ip]->is_used=true;
			int res_code=  mymap[ip]->get_gray(filename);
			mymap[ip]->is_used=false;
			return res_code;
		}
	}
	int setosd( LPWSTR ip ,LPWSTR myosd_num) 
	{	

		if (checkavliable(ip)!=0)
		{
			return checkavliable(ip);//摄像头未连接
		}
		else
		{
			 mymap[ip]->is_used=true;
			 int res_code= mymap[ip]->set_osd(myosd_num);
			 mymap[ip]->is_used=false;
			 return res_code;
		}
	}
	void reset()
	{
		for ( auto temp : mymap)
		{
			delete temp.second;		
		}
		mymap.clear();
		my_hwnd_map.clear();
	}
private:
	Camopt()
	{
	}
	~Camopt()
	{
		for ( auto temp : mymap)
		{
			delete temp.second;		
		}
		ipcUnInitialize();
		
		mymap.clear();
		my_hwnd_map.clear();
	}
	static Camopt *singleins;
	
	map<wstring,mydevice *> mymap;
	map<HWND,wstring> my_hwnd_map;

};
Camopt *Camopt::singleins = NULL;

Camopt *mycamopt=Camopt::inst();
std::string WChar2Ansi(LPCWSTR pwszSrc)  
{  
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);  
	if (nLen<= 0) return std::string("");  
	char* pszDst = new char[nLen];  
	if (NULL == pszDst) return std::string("");  
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);  
	pszDst[nLen -1] = 0;  
	std::string strTemp(pszDst);  
	delete [] pszDst;  
	return strTemp;  
} 
string ws2s(wstring& inputws){ return WChar2Ansi(inputws.c_str()); }  
std::wstring Ansi2WChar(LPCSTR pszSrc, int nLen)  
{  
	int nSize = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pszSrc, nLen, 0, 0);  
	if(nSize <= 0) return NULL;  
	WCHAR *pwszDst = new WCHAR[nSize+1];  
	if( NULL == pwszDst) return NULL;  
	MultiByteToWideChar(CP_ACP, 0,(LPCSTR)pszSrc, nLen, pwszDst, nSize);  
	pwszDst[nSize] = 0;  
	if( pwszDst[0] == 0xFEFF)   
		for(int i = 0; i < nSize; i ++)   
			pwszDst[i] = pwszDst[i+1];   
	wstring wcharString(pwszDst);  
	delete pwszDst;  
	return wcharString;  
} 
//////////////////////////////////////////////////////////////////////////
//设置osd
//////////////////////////////////////////////////////////////////////////
extern"C"_declspec(dllexport) int set_osd( LPWSTR ip ,LPWSTR myosd_num) 
{	
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	return mycamopt->setosd(ip,myosd_num);

	
	/*LPIPC_OSDPARAM my_osd=new tagIPC_OSDParamW;
	my_osd->text=false;
	my_osd->text_x=50 ;
	my_osd->text_y=20;
	my_osd->text_lHeight=100;
	my_osd->text_lWidth=400;

	DWORD dw;


	dw=RGB(255,0,0);
	my_osd->text_crColor=dw;

	LOGFONT logFont;
	logFont.lfHeight = 60 ;
	logFont.lfWidth   = 0;
	logFont.lfEscapement = 0;
	logFont.lfOrientation = 0;
	logFont.lfWeight = FW_NORMAL;
	logFont.lfItalic = 0;
	logFont.lfUnderline = 0;
	logFont.lfStrikeOut = 0;
	logFont.lfCharSet = ANSI_CHARSET;
	logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logFont.lfQuality = DEFAULT_QUALITY;
	logFont.lfPitchAndFamily=FIXED_PITCH;
	wcscpy (logFont.lfFaceName, L"Arial ");




	my_osd->text_font=logFont; 
	wcscpy(my_osd->text_context,myosd_num.c_str());
	my_osd->picture = true;
	my_osd->pic_x = 320;
	my_osd->pic_y = 240;
	my_osd->pic_lWidth = 640;
	my_osd->pic_lHeight = 480;
	my_osd->pic_crMask = RGB(1, 255, 1);
	ifstream fin;
	fin.open("IPC_Logo.bmp",ios_base::in|ios_base::binary);
	BITMAPFILEHEADER	Header;
	fin.read((char *) &Header,sizeof(BITMAPFILEHEADER));



	//FILE *myfile=fopen("IPC_Logo.bmp","rb");
	//int file_len = ftell(myfile);
	
	//BITMAPFILEHEADER	Header;
	//fread(&Header, sizeof(BITMAPFILEHEADER), 1,myfile);

	long lLen = sizeof(Header);
	
	long lSize = Header.bfSize - sizeof(Header);
	char *mydata= new char [lSize];
	my_osd->pic_data=(BYTE*)mydata;
	my_osd->pic_data_len=lSize;
	int j=fin.gcount();
	
	fin.read((char *)my_osd->pic_data,lSize);
	int ji=fin.gcount();
	fin.close();
	
	

	return ipcSetDisplayOSD(hplayer, my_osd);
	*/
	

};

//////////////////////////////////////////////////////////////////////////
//打开预览，成功打开返回0，并且写入map表中，失败返回-2，默认端口30000 
 //////////////////////////////////////////////////////////////////////////
extern"C"_declspec(dllexport) int open_camera(LPWSTR ip, LPWSTR  user ,LPWSTR  password)
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}	
	return mycamopt->opencamera(ip,user,password);

}
//////////////////////////////////////////////////////////////////////////
//显示预览界面 默认宽高比 1280/720，steamid 0；
//////////////////////////////////////////////////////////////////////////
extern"C"_declspec(dllexport) int open_preview(LPWSTR ip,HWND myhwnd,int weight)
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	return mycamopt->openpreview(ip,myhwnd,weight);
}
//////////////////////////////////////////////////////////////////////////
//关闭预览 释放资源
//////////////////////////////////////////////////////////////////////////
extern"C"_declspec(dllexport) int stop_preview(HWND myhwnd)
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	return mycamopt->stoppreview(myhwnd);
}
//////////////////////////////////////////////////////////////////////////
//关闭摄像头
//////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
extern"C"_declspec(dllexport) int close_camera(LPWSTR ip)
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	return mycamopt->closecamera(ip);
}
//////////////////////////////////////////////////////////////////////////
//拍照
//////////////////////////////////////////////////////////////////////////
extern"C"_declspec(dllexport) int photographtofile(LPWSTR ip,LPCWSTR filename)
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	return mycamopt->photofile(ip,filename);
}
extern"C"_declspec(dllexport) int photographtofile_gray(LPWSTR ip,LPCWSTR filename)
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	return mycamopt->photofile_gray(ip,filename);
}
////////////////////////////////////////////////////////////////////
//重置
/////////////////////////////////////////////////
extern"C"_declspec(dllexport) int reset()
{
	if (isinial==false)
	{
		int i=ipcInitialize();
		if (i==0)
		{ 
			isinial=true;

		}
	}
	mycamopt->reset();
	isinial=false;
	return 0;
}



/*

extern"C"_declspec(dllexport) int OpenCamera1(LPWSTR ip,int port,LPWSTR  user ,LPWSTR  password,HWND myhwnd,int steamId,int height,int weight)
{

	//HWND hwnd =showhwnd;
	//INT isintial=ipcInitialize() ;
	if (issdkinit)
	{
		INT isintial=ipcInitialize() ;
		if (isintial<0)
		{
			return -1;
			//sdk初始化失败
		}
		
		else
		{
			issdkinit=true;
		}

	}
	
	wstring iptemp=ip;
	ipcHandle	myipchandle = ipcCreateDevice();
	//string temp=ip;
	string suser=WChar2Ansi(user);
	string spassword=WChar2Ansi(password);
	string sip=WChar2Ansi(ip);
	const char* myaccount = suser.c_str();
	const char * mypassword=WChar2Ansi(password).c_str();
	const char * myip=WChar2Ansi(ip).c_str();
	int myport =port;
	ipcConnect(myipchandle,suser.c_str(),spassword.c_str(),sip.c_str(),myport);

	DWORD time = 5000;
	if (ipcWaitConnected(myipchandle,time)==0)
	{
		HWND temp=myhwnd;
		playHandle ipcPlayHandle=ipcCreateLivePlay(myipchandle,temp,0,steamId);
		RECT rect;
		rect.top = 0;
		rect.bottom = height;
		rect.left = 0;
		rect.right = weight;
		int issetrect=ipcSetDisplayRect(ipcPlayHandle,rect);
		int isstartPlay=ipcStartLivePlay(ipcPlayHandle);
		mydevice tempdevice=  mydevice(ip,myipchandle,ipcPlayHandle);
		mymap[ip]=tempdevice;


		return 0;
	}
	else
	{
		return -2;
		//连接超时
	}



	//
	//HWND handle;

	return 0;
}

extern"C"_declspec(dllexport) LPVOID StartPlay(ipcHandle myipchandle,HWND myhwnd,int steamId,int height,int weight)
{   HWND temp=myhwnd;
playHandle ipcPlayHandle=ipcCreateLivePlay(myipchandle,temp,0,steamId);
RECT rect;
rect.top = 0;
rect.bottom = height;
rect.left = 0;
rect.right = weight;
if (height!=0||weight!=0)
{
	int issetrect=ipcSetDisplayRect(ipcPlayHandle,rect);
}

int isstartPlay=ipcStartLivePlay(ipcPlayHandle);
if (isstartPlay==0)
{
	return NULL;
}
return ipcPlayHandle;
}
//extern"C"_declspec(dllexport) int GetPic(ipcHandle myipchandle,LPCWSTR filename)
//{
//	if (myipchandle!=NULL)
//	{ //wchar_t * wc = new wchar_t[filename.size()];
//		//swprintf(wc,filename.size(),L"%S",filename.c_str());
//		int getPic=ipcCapturePicture(myipchandle,2,filename);
//		//delete []wc;
//	   if (getPic<0)
//	   {
//		   return -1;
//	   }
//
//	}
//	return -1;
//}


extern"C"_declspec(dllexport) int CloseCamera(LPCWSTR ip)
{
	playHandle myipcplayhandle=NULL;
	ipcHandle myipc=NULL;

	map<wstring ,mydevice >::iterator l_it;
	for(l_it=mymap.begin();l_it!=mymap.end();++l_it)
	{
		if (wcscmp(l_it->first.c_str(),  ip)==0)
		{ myipcplayhandle=l_it->second.myplayHandle;
		myipc=l_it->second.myipchandle;
		mymap.erase(l_it);
		break;

		}


	}
	if (myipcplayhandle!=NULL)
	{
		ipcStopLivePlay(myipcplayhandle);
		ipcDestroyLivePlay(myipc,myipcplayhandle);
	}
	if (myipc!=NULL)
	{
		ipcDisConnect(myipc);
		int destroy=ipcDestroyDevice(myipc);
		if (mymap.size()==0)
		{
			ipcUnInitialize();
			issdkinit=false;
		}

		if (destroy==0)
		{
			return 0;
		}

	}
	return -1;
	


} 
*/